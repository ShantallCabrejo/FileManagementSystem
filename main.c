#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME 100
#define MAX_CONTENT 500

struct SimulateFile
{
    char name[MAX_NAME];
    char content[MAX_CONTENT];
    int isOpen;
    int exists;
};

// RAM that simulates hard disk space
struct SimulateFile files[MAX_FILES];

// Find file by name
int findFile(char filename[])
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        if (files[i].exists && strcmp(files[i].name, filename) == 0)
        {
            return i;
        }
        
    }
    return -1;
}

// Find empty space in RAM for a new file
int findEmptySlot()
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        if (!files[i].exists)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int choice;
    char filename[MAX_NAME];

    while (1)
    {
        // Menu
        printf("\nFile Management System\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Write File\n");
        printf("4. Read File\n");
	    printf("5. Close File\n");
	    printf("6. Search File\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Try again.\n");
            while (getchar() != '\n');
            continue;
        }
       
        // Create file
        if (choice == 1)
        {
            printf("Enter file name: ");
            scanf("%s", filename);

            if (findFile(filename) != -1)
            {
                printf("File already exists.\n");
            }
            else
            {
                int index = findEmptySlot();

                if (index == -1)
                {
                    printf("No space left in RAM.\n");
                }
                else{
                    strcpy(files[index].name, filename);
                    files[index].content[0] = '\0';
                    files[index].isOpen = 0;
                    files[index].exists = 1;

                    printf("File created successfully.\n");
                }
            }
        }

        // Open file
        else if (choice == 2)
        {
            printf("Enter file name: ");
            scanf("%s", filename);

            int index = findFile(filename);

            if (index == -1)
            {
                printf("File not found.\n");
            }
            else if (files[index].isOpen)
            {
                printf("File is already open.\n");
            }
            else
            {
                files[index].isOpen = 1;
                printf("File opened successfully.\n");
            }
        }

        // Write to file
	    else if (choice == 3) 
        {
            printf("Enter file name: ");
            scanf("%s", filename);

            int index = findFile(filename);

            if (index == -1)
            {
                printf("File not found.\n");
            }
            else if (!files[index].isOpen)
            {
                printf("File must be open before writing.\n");
            }
            else
            {
                char content[MAX_CONTENT];

                printf("Enter content: ");
                getchar(); // Clear leftover newline
                fgets(content, sizeof(content), stdin);

                content[strcspn(content, "\n")] = '\0';
                strcpy(files[index].content, content);

                printf("Content written successfully.\n");
            }
        }

        // Read file
        else if (choice == 4)
        {
            printf("Enter file name: ");
            scanf("%s", filename);

            int index = findFile(filename);

            if (index == -1)
            {
                printf("File not found.\n");
            }
            else if (!files[index].isOpen)
            {
                printf("File must be open before reading.\n");
            }
            else
            {
                printf("File contents:\n%s\n", files[index].content);
            }
        }

        // Close file
        else if (choice == 5)
        {
            printf("Enter file name to close: ");
            scanf("%s", filename);

            int index = findFile(filename);

            if (index == -1)
            {
                printf("File not found.\n");
            }
            else if (!files[index].isOpen)
            {
                printf("File is already closed.\n");
            }
            else
            {
                files[index].isOpen = 0;
                printf("File closed successfully.\n");
            }
        }

        // Search file
        else if (choice == 6)
        {
            printf("Enter file name to search: ");
                scanf("%s", filename);

            int index = findFile(filename);
            
            if (index == -1)
            {
                printf("File not found.\n");
            }
            else
            {
                printf("File found.\n");
            }
        }

        // Exit
        else if (choice == 7)
        {
            printf("Exiting program\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}