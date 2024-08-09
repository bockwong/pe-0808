/*
This file contains a script of Transact SQL (T-SQL) command to interact with a database named 'Inventory'.
Requirements:
- SQL Server 2022 is installed and running
- database 'Inventory' already exists.
Details:
- Check if the database 'Inventory' exists, if not, exit with an error message.
- Sets the default database to 'Inventory'.
- Create a 'categories' table and related 'products' table if they do not already exist.
- Remove all rows from the 'products' and 'categories' tables.
- Populate the 'categories' table with sample data.
- Populate the 'products' table with sample data.
- Create stored procedures to get all categories.
- Create a stored procedure to get all products in a specific category.
- Create a stored procudure to get all products in a specific price range sorted by price in ascending order.
*/

-- check if the database 'Inventory' exists
IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = 'Inventory')
BEGIN
    PRINT 'The database Inventory does not exist. Please create the database and run this script again.'
    RETURN
END

-- set the default database to 'Inventory'
USE Inventory
GO

-- create the 'categories' table if it does not already exist. Use the following columns:
-- id (INT, PRIMARY KEY)
-- name (NVARCHAR(50), NOT NULL)
-- description (NVARCHAR(255), NULL)
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'categories')
BEGIN
    CREATE TABLE categories (
        id INT PRIMARY KEY,
        name NVARCHAR(50) NOT NULL,
        description NVARCHAR(255) NULL
    )
END

-- create the 'products' table if it does not already exist. Use the following columns:
-- id (INT, PRIMARY KEY)
-- name (NVARCHAR(50), NOT NULL)
-- price (DECIMAL(10, 2), NOT NULL)
-- category_id (INT, FOREIGN KEY REFERENCES categories(id))
IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'products')
BEGIN
    CREATE TABLE products (
        id INT PRIMARY KEY,
        name NVARCHAR(50) NOT NULL,
        price DECIMAL(10, 2) NOT NULL,
        category_id INT FOREIGN KEY REFERENCES categories(id),
        -- Add a created_at column to track the creation date of the product
        created_at DATETIME NOT NULL DEFAULT GETDATE(),
        -- Add a updated_at column to track the last update date of the product
        updated_at DATETIME NULL
    )
END

-- remove all rows from the 'products' and 'categories' tables
TRUNCATE TABLE products
TRUNCATE TABLE categories

-- populate the 'categories' table with sample data
INSERT INTO categories (id, name, description) VALUES
(1, 'Electronics', 'Electronic devices and accessories'),
(2, 'Clothing', 'Apparel and fashion accessories'),
(3, 'Home & Kitchen', 'Household items and kitchenware')

-- populate the 'products' table with sample data
INSERT INTO products (id, name, price, category_id) VALUES
(1, 'Laptop', 999.99, 1),
(2, 'Smartphone', 599.99, 1),
(3, 'Headphones', 99.99, 1),
(4, 'T-shirt', 19.99, 2),
(5, 'Jeans', 39.99, 2),
(6, 'Dress', 49.99, 2),
(7, 'Cookware Set', 79.99, 3),
(8, 'Coffee Maker', 29.99, 3),
(9, 'Cutlery Set', 19.99, 3)

-- create a stored procedure to get all categories
IF NOT EXISTS (SELECT * FROM sys.objects WHERE type = 'P' AND name = 'GetAllCategories')
BEGIN
    EXEC('CREATE PROCEDURE GetAllCategories AS SELECT * FROM categories')
END

-- create a stored procedure to get all products in a specific category
IF NOT EXISTS (SELECT * FROM sys.objects WHERE type = 'P' AND name = 'GetProductsByCategory')
BEGIN
    EXEC('CREATE PROCEDURE GetProductsByCategory @category_id INT AS SELECT * FROM products WHERE category_id = @category_id')
END

-- create a stored procedure to get all products in a specific price range sorted by price in ascending order
IF NOT EXISTS (SELECT * FROM sys.objects WHERE type = 'P' AND name = 'GetProductsByPriceRange')
BEGIN
    EXEC('CREATE PROCEDURE GetProductsByPriceRange @min_price DECIMAL(10, 2), @max_price DECIMAL(10, 2) AS SELECT * FROM products WHERE price BETWEEN @min_price AND @max_price ORDER BY price ASC')
END


-- Path: sales.sql


