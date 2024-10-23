#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
CODE_2-MIDTERM_ONE-FUNCTION
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

// Function prototype
void sort_digits(char number[20], int digit_count);

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

        // Check length of the number and sort digits if it matches the required count
        if (strlen(number) == digit_count) {
            sort_digits(number, digit_count);
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

// Function definition
void sort_digits(char number[20], int digit_count) {
    int digits[10], digit_index = 0;
	int i = 0, j = 0;

    // Extract digits from the number
    /* BASICALLY this loop converts the character number 
    	into an integer number using ASCII
	*/
    for (i = 0; number[i] != '\0'; i++) {
        if (isdigit(number[i])) {
            digits[digit_index++] = (number[i] - '0');
            /*
            
			if number[0] is 5
			ASCII 5 is 53
			ASCII 0 is 48
			
			number[0] - '0'
			ASCII of '5' minus '0'
				53 - 48
				5
			*/
        }
    }

    // Only sort if the number has exactly 
	// 'digit_count' digits
    for (i = 0; i < digit_index - 1; i++) {
        for (j = i + 1; j < digit_index; j++) {
            if (digits[i] < digits[j]) { 
			// Sort in descending order
                // Swap
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    // Rebuild the number with sorted digits
    // Initialize the index for accessing 
	// the sorted digits
	digit_index = 0; 
	 // Loop through each character 
	 //in the number string
    for (i = 0; number[i] != '\0'; i++) {
	 // Check if the current character is a digit
	    if (isdigit(number[i])) {
		 // Replace the digit in the number with the sorted digit
    	number[i] = digits[digit_index++] + '0';
		}
	}
}

