#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book b;

    // Input book details
    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);

    printf("Enter author name: ");
    fgets(b.author, sizeof(b.author), stdin);

    printf("Enter book price: ");
    scanf("%f", &b.price);

    // Write to file
    FILE *fptr = fopen("book.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fptr, "%s%s%.2f\n", b.title, b.author, b.price);
    fclose(fptr);

    // Read from file
    struct Book readBook;
    fptr = fopen("book.txt", "r");
    if (fptr == NULL) {
        printf("Error reading file!\n");
        return 1;
    }
    fgets(readBook.title, sizeof(readBook.title), fptr);
    fgets(readBook.author, sizeof(readBook.author), fptr);
    fscanf(fptr, "%f", &readBook.price);
    fclose(fptr);

    // Display book details
    printf("\nSaved Book Details:\n");
    printf("Title: %s", readBook.title);
    printf("Author: %s", readBook.author);
    printf("Price: %.2f\n", readBook.price);

    return 0;
}
