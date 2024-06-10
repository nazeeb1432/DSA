#include <stdio.h>
#include <string.h>

// Function to find the maximum string length
int maxStrLength(char arr[][100], int n) {
    int maxLen = strlen(arr[0]);
    for (int i = 1; i < n; i++) {
        if (strlen(arr[i]) > maxLen) {
            maxLen = strlen(arr[i]);
        }
    }
    return maxLen;
}

// Function to do counting sort of 2D string array
void countingSort(char arr[][100], int n, int exp) {
    char output[n][100];
    int count[256] = {0};

    // Count occurrences of each character in current digit position
    for (int i = 0; i < n; i++) {
        count[arr[i][exp]]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[] array
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = count[arr[i][exp]] - 1;
        strcpy(output[index], arr[i]);
        count[arr[i][exp]]--;
    }

    // Copy the output array to arr[], so that arr[] now contains
    // sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        strcpy(arr[i], output[i]);
    }
}

// Function to do radix sort of 2D string array
void radixSort(char arr[][100], int n) {
    int maxLen = maxStrLength(arr, n);

    // Do counting sort for every digit position
    for (int exp = maxLen - 1; exp >= 0; exp--) {
        countingSort(arr, n, exp);
    }
}

// Main function to test the code
int main() {
    char arr[5][100] = {"apple", "banana", "cherry", "date", "fig"};

    printf("Original array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    radixSort(arr, 5);

    printf("\nSorted array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
