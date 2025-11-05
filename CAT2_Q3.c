/*
Name:Mutunga Alex
Reg no:CT100/G/26278/25
Description:c program to  write a program into different files
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeIntegersToFile();
void processIntegers();
void displayFiles();

int main() {
    writeIntegersToFile();
    processIntegers();
    displayFiles();
    return 0;
}

// 1. Function to get 10 integers from the user and store them in "input.txt"
void writeIntegersToFile() {
    FILE *fptr;
    int num;
    int i;
    
    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing");
        exit(EXIT_FAILURE);
    }

    printf("Enter 10 integers:\n");
    for ( i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            fclose(fptr);
            exit(EXIT_FAILURE);
        }
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("\nData successfully written to input.txt\n\n");
}

// 2. Function to read integers from "input.txt", compute sum and average, and write to "output.txt"
void processIntegers() {
    FILE *fin, *fout;
    int num, count = 0;
    int sum = 0;
    double avg = 0.0;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        perror("Error opening input.txt for reading");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fin);

    if (count == 0) {
        printf("No integers found in input.txt.\n");
        exit(EXIT_FAILURE);
    }

    avg = (double)sum / count;

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        perror("Error opening output.txt for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(fout, "Sum = %d\nAverage = %.2f\n", sum, avg);
    fclose(fout);

    printf("Sum and average successfully written to output.txt\n\n");
}

// 3. Function to display contents of both files
void displayFiles() {
    FILE *fin, *fout;
    char ch;

    printf("Contents of input.txt:\n");
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        perror("Error opening input.txt for reading");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fin)) != EOF)
        putchar(ch);
    fclose(fin);

    printf("\nContents of output.txt:\n");
    fout = fopen("output.txt", "r");
    if (fout == NULL) {
        perror("Error opening output.txt for reading");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fout)) != EOF)
        putchar(ch);
    fclose(fout);

    printf("\n");
}