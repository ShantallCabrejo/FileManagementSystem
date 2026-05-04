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
	printf("3. Close File\n");
	printf("4. Search File\n");
        printf("5. Exit\n");
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
	
	// Close file
	else if (choice == 3)
	{
	    printf("Enter file name to close: ");
	    scanf("%s", filename);

	    FILE *file = fopen(filename, "r");

	    if (file == NULL)
	    {
		printf("File not found.\n");
	    }
	    else
	    {
		fclose(file);
		printf("File closed successfully.\n");
	    }
	}

	// Search file
	else if (choice == 4)
	{
	    printf("Enter file name to search: ");
    	    scanf("%s", filename);

	    FILE *file = fopen(filename, "r");
   	    
	    if (file == NULL)
   	    {
       		printf("File not found.\n");
    	    }
    	    else
    	    {
        	fclose(file);
        	printf("File found.\n");
   	    }
	}
       
	// Exit
        else if (choice == 5)
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
