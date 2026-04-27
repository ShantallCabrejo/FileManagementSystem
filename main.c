#include <stdio.h>

int main()
{
    int choice;
    char filename[100];

    while (1)
    {
        // Menu
        printf("\nFile Management System\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Create file
        if (choice == 1)
        {
            printf("Enter file name: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "w");

            if (file == NULL)
            {
                printf("Error creating file.\n");
            }
            else
            {
                printf("Enter content (press Enter to finish):\n");

                char content[500];

                getchar();
                fgets(content, sizeof(content), stdin);

                fprintf(file, "%s", content);

                printf("File created successfully.\n");
                fclose(file);
            }
        }

        // Open file
        else if (choice == 2)
        {
            printf("Enter file name: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "r");

            if (file == NULL)
            {
                printf("File not found.\n");
            }
            else
            {
                printf("\nFile contents:\n");

                char line[200];

                while (fgets(line, sizeof(line), file) != NULL)
                {
                    printf("%s", line);
                }
                fclose(file);
            }
        }

        // Exit
        else if (choice == 3)
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
