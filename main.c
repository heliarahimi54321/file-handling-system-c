#include <stdio.h>
#include <stdlib.h>

void addData() {
    FILE *file = fopen("data.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char name[50];
    int age;

    printf("Enter name: ");
    scanf(" %[^\n]", name);

    printf("Enter age: ");
    scanf("%d", &age);

    fprintf(file, "%s %d\n", name, age);

    fclose(file);

    printf("Data saved successfully!\n");
}

void showData() {
    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("No data found.\n");
        return;
    }

    char name[50];
    int age;

    printf("\nSaved Data:\n");

    while (fscanf(file, "%s %d", name, &age) != EOF) {
        printf("Name: %s | Age: %d\n", name, age);
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- File Handling System ---\n");
        printf("1. Add Data\n");
        printf("2. Show Data\n");
        printf("3. Exit\n");

        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addData();
        } else if (choice == 2) {
            showData();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}