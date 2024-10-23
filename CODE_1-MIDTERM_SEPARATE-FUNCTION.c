#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
CODE_1-MIDTERM_SEPARATE-FUNCTION
by shiloh, chatgpt, and google

Write a C program to sort the digits of a number in descending order and leave the remaining digits unchanged.

Test Data:
Number of inputs: 4
Number of digits: 3
Inputs: 4120 230 485 98423
Outputs: 4120 320 854 98423

explanation:
- only the elements that fit the number of digits will 
be arranged descendingly
- use one dimensional array


*/

// Function prototypes
int extract_digits(char number[20], int digits[10]);
void sort_digits(int digits[10], int digit_count);
void rebuild_number(char number[20], int digits[10], int digit_count);

int main() {
    int n, digit_count, i;

    // Prompt the user for the number of inputs and the digit count
    printf("Number of inputs: ");
    scanf("%d", &n);

    printf("Number of digits: ");
    scanf("%d", &digit_count);

    // Declare a 1D array to hold each number one by one (assuming each number can be up to 20 characters)
    char number[20];
    char inputs[n][20];  // Array to store all input numbers
    char outputs[n][20]; // Array to store all output numbers after sorting

    // Input the numbers
    printf("Inputs: ");
    for (i = 0; i < n; i++) {
        scanf("%s", number);  // Read one number at a time
        strcpy(inputs[i], number); // Store the original input in the inputs array
//printf("%s ", inputs[i]);
        // Check length of the number and sort digits if it matches the required count
        if (strlen(number) == digit_count) {
            int digits[10]; // Array to hold extracted digits
            int digit_index = extract_digits(number, digits); // Extract digits and get count
            sort_digits(digits, digit_index); // Sort the digits in descending order
            rebuild_number(number, digits, digit_index); // Rebuild the number with sorted digits
        }

        // Store the processed number in the outputs array
        strcpy(outputs[i], number);
    }

    // Display the sorted results
    printf("Outputs: ");
    for (i = 0; i < n; i++) {
        printf("%s ", outputs[i]);
    }

    return 0;
}

// Function to extract digits from the number
int extract_digits(char number[20], int digits[10]) {
    int digit_count = 0; // Initialize digit_count locally
    for (int i = 0; number[i] != '\0'; i++) {
        if (isdigit(number[i])) {
            digits[digit_count] = (number[i] - '0'); // Convert char to int
            digit_count++;
        }
    }
    return digit_count; // Return the count of extracted digits
}

// Function to sort digits in descending order
void sort_digits(int digits[10], int digit_count) {
    for (int i = 0; i < digit_count - 1; i++) {
        for (int j = i + 1; j < digit_count; j++) {
            if (digits[i] < digits[j]) { 
                // Swap for descending order
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }
}

// Function to rebuild the number with sorted digits
void rebuild_number(char number[20], int digits[10], int digit_count) {
    int digit_index = 0; // Initialize index for accessing sorted digits
    for (int i = 0; number[i] != '\0'; i++) {
        if (isdigit(number[i])) {
            number[i] = digits[digit_index++] + '0'; // Replace with sorted digit
        }
    }
}
