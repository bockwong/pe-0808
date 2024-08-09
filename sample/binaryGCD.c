/*
This program calculates the greatest common divisor of two numbers using the binary GCD algorithm.
*/

// Add the import statement for the standard i/o library
#include <stdio.h>
// Add the import statement for the assert library (for testing the function)
#include <assert.h>

/*
Define a function 'binary_gcd' that takes two unsigned integers 'numerator' and 'denominator' as arguments.
Arguments:
- numerator: an unsigned integer
- denominator: an unsigned integer
Return Value:
- an unsigned integer representing the greatest common divisor of 'numerator' and 'denominator'
Impementation Details:
- If the numerator is 0, return the denominator.
- If the denominator is 0, return the numerator.
- If both the numerator and denominator are even, return 2 times the binary_gcd of the numerator divided by 2 and the denominator divided by 2.
- If the numerator is even and the denominator is odd, return the binary_gcd of the numerator divided by 2 and the denominator.
- If the numerator is odd and the denominator is even, return the binary_gcd of the numerator and the denominator divided by 2.
- If both the numerator and denominator are odd, return the binary_gcd of the absolute difference of the numerator and denominator divided by 2 and the smaller of the two numbers.
- The function should be implemented using recursion.
Examples:
- binary_gcd(0, 0) returns 0
- binary_gcd(0, 1) returns 1
- binary_gcd(10, 5) returns 5
- binary_gcd(10, 0) returns 10
- binary_gcd(0, 10) returns 10
- binary_gcd(10, 16) returns 2
*/

unsigned int binary_gcd(unsigned int numerator, unsigned int denominator) {
  if (numerator == 0) {
    return denominator;
  }
  if (denominator == 0) {
    return numerator;
  }
  if (numerator % 2 == 0 && denominator % 2 == 0) {
    return 2 * binary_gcd(numerator / 2, denominator / 2);
  }
  if (numerator % 2 == 0 && denominator % 2 != 0) {
    return binary_gcd(numerator / 2, denominator);
  }
  if (numerator % 2 != 0 && denominator % 2 == 0) {
    return binary_gcd(numerator, denominator / 2);
  }
  if (numerator % 2 != 0 && denominator % 2 != 0) {
    if (numerator > denominator) {
      return binary_gcd((numerator - denominator) / 2, denominator);
    } else {
      return binary_gcd((denominator - numerator) / 2, numerator);
    }
  }
  return 0;
}



/*
 Create a function 'test_BinaryGCD' to test the binary_gcd function using the assert statements.
 Print a success message "All tests passed!" if the test passes.
*/

void test_BinaryGCD() {
  assert(binary_gcd(0, 0) == 0);
  assert(binary_gcd(0, 1) == 1);
  assert(binary_gcd(10, 5) == 5);
  assert(binary_gcd(10, 0) == 10);
  assert(binary_gcd(0, 10) == 10);
  printf("All tests passed!\n");
}



// The following is the main function to test the binary_gcd function
int main() {

// Call the test_BinaryGCD function
  test_BinaryGCD();

  return 0;
}




