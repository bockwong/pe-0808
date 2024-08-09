
#include <stdio.h>
#include <assert.h>

// TODO: Implement the conditionalBitSwap function


// Implement a test for the 'conditionalBitSwap' function named 'test_conditionalBitSwap'

void test_conditionalBitSwap() {
    char arr1[] = {0b1010, 0b1100};
    char arr2[] = {0b0110, 0b0011};
    char m = 0b1010;

    // calculate the length of the arr1
    int arrLen1 = sizeof(arr1) / sizeof(arr1[0]);

    // calculate the length of the arr2
    int arrLen2 = sizeof(arr2) / sizeof(arr2[0]);

    // assert that the length of the arr1 is equal to the length of the arr2
    assert(arrLen1 == arrLen2);

    // call the conditionalBitSwap function
    conditionalBitSwap(arr1, arr2, m, arrLen1);

    assert(arr1[0] == 0b0010);
    assert(arr2[0] == 0b1110);

    assert(arr1[1] == 0b0110);
    assert(arr2[1] == 0b1001);
}


int main() {
    // call the test function
    test_conditionalBitSwap();

    printf("All tests pass\n");

    return 0;
}









