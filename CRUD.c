#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int age;
} User;

#define FILE_NAME "users.txt"


FILE* openFile(const char* mode) {
    FILE* file = fopen(FILE_NAME, mode);
    if (file == NULL) {
        printf("Error opening the file!\n");
    }
    return file;
}


int isUniqueID(int id) {
    FILE* file = openFile("r");
    if (!file) return 0;

    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            fclose(file);
            return 0; 
        }
    }
    fclose(file);
    return 1;
}

int createUser() {
    FILE* file = openFile("a");
    if (!file) return 0;

    User user;
    printf("Enter ID: ");
    scanf("%d", &user.id);

    if (!isUniqueID(user.id)) {
        printf("Error: ID already exists. Please use a unique ID.\n");
        fclose(file);
        return 0;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);

    printf("User added successfully!\n");
    return 1;
}


void readUsers() {
    FILE* file = openFile("r");
    if (!file) return;

    User user;
    printf("ID\tName\t\tAge\n");
    printf("--------------------------------\n");
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        printf("%d\t%-15s\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

int updateUser() {
    FILE* file = openFile("r");
    if (!file) return 0;

    int targetId, found = 0;
    printf("Enter the ID of the user to update: ");
    scanf("%d", &targetId);

    FILE* tempFile = openFile("w");
    if (!tempFile) {
        fclose(file);
        return 0;
    }

    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == targetId) {
            found = 1;
            printf("Enter new Name: ");
            scanf(" %[^\n]s", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found!\n", targetId);
    }
    return found;
}

int deleteUser() {
    FILE* file = openFile("r");
    if (!file) return 0;

    int targetId, found = 0;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &targetId);

    FILE* tempFile = openFile("w");
    if (!tempFile) {
        fclose(file);
        return 0;
    }

    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == targetId) {
            found = 1;
        } else {
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found!\n", targetId);
    }
    return found;
}

int main() {
    int choice;

    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
