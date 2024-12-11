/*Assignment 1: Fixed-Length File Processing
Objective:
Write a C program that processes a file (file1.txt) with fixed-length lines (10 characters each). The program will read the content line by line, reverse each line, and write the reversed lines into another file (file2.txt).
________________________________________
Requirements:
1.      File Format:
        * Each line in file1.txt is exactly 10 characters.
        * If a line is shorter, it is padded with spaces to reach 10 characters.
2.      Operations to Use:
        * creat, open, close, read, write
3.      Steps:
        1. Create and write a file (file1.txt) with user input.
        2. Ensure each line is padded to 10 characters.
        3. Open file1.txt and read it line by line (10 bytes at a time).
        4. Reverse each 10-character line.
        5. Write the reversed lines to another file (file2.txt).
________________________________________
Example
Input (file1.txt):
Copy code
Hello
World
Programming
Output (file2.txt):
markdown
Copy code
     olleH
     dlroW
gnimmargorP*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


void reverse_line(char *line) {
    int length = strlen(line);
    for (int i = 0; i < length / 2; i++) {
        char temp = line[i];
        line[i] = line[length - 1 - i];
        line[length - 1 - i] = temp;
    }
}

int main() {
    int fd1, fd2;
    char line[11];
    
    // Same as creating the file
    fd1 = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 == -1) {
        perror("Error creating file1.txt");
        return 1;
    }

    printf("Enter text for file1.txt (max 10 characters per line) - Write 'end' to exit.\n");

    while (1) {
        printf("Enter a line (max 10 characters): ");
        fgets(line, sizeof(line), stdin);

        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "end") == 0) {
            break;
        }

        int length = strlen(line);
        if (length < 10) {
          memset(line + length, ' ', 10 - length);
	  line[10] = '\0'; // To avoid segmentation fault
        }
        
        write(fd1, line, length);
    }

    close(fd1);

    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1.txt");
        return 1;
    }

    fd2 = open("file2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("Error opening file2.txt");
        return 1;
    }

    while (read(fd1, line, 10) == 10) {
        reverse_line(line);
        write(fd2, line, 10);
    } 

    close(fd1);
    close(fd2);

    printf("Reversed text written to file2.txt\n");

    return 0;
}
