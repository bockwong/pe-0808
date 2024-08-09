/*
This file contains a script of Transact SQL (T-SQL) command to interact with a database named 'Inventory'.
Requirements:
- SQL Server 2022 is installed and running
- database 'Inventory' already exists.
Details:
- Check if the database 'Inventory' exists, if not, exit with an error message.
- Sets the default database to 'Inventory'.
- Create a 'categories' table and related 'products' table if they do not already exist.
- Remove all rows from the tables.
- Populate the 'categories' table with sample data.
- Populate the 'products' table with sample data.
- Create stored procedures to get all categories.
- Create a stored procedure to get all products in a specific category.
- Create a stored procudure to get all products in a specific price range sorted by price in ascending order.
*/