#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char data[100];
    char extra;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Create File and Insert\n");
        printf("2. Read File\n");
        printf("3. Update Record\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d%c", &choice, &extra) != 2 || extra != '\n')
        {
            printf("Invalid input! Please enter digits only.\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice < 1 || choice > 5)
        {
            printf("Invalid choice! Please enter 1 to 5.\n");
            continue;
        }
        switch (choice)
        {
            case 1:
            {
                FILE *fp;
                fp = fopen("data.txt", "a");

                if (fp == NULL)
                {
                    printf("File cannot be created!\n");
                    break;
                }
              printf("Enter your data: ");
              scanf("%s", data);
              getchar();

                fprintf(fp, "%s\n", data);
                fclose(fp);

                printf("Data inserted successfully.\n");
                break;
            }

            case 2:
            {
                FILE *fp;
                fp = fopen("data.txt", "r");
                if (fp == NULL)
                {
                    printf("File does not exist!\n");
                    break;
                }

                printf("\nData in file:\n");
                while (fscanf(fp, "%s", data) == 1)                {
                    printf("%s\n", data);
                }
                fclose(fp);
                break;
            }
            case 3:
            {
                FILE *fp;
                FILE *temp;
                fp = fopen("data.txt", "r");
                if (fp == NULL)
                {
                    printf("File does not exist!\n");
                    break;
                }

                temp = fopen("temp.txt", "w");

                printf("Enter new data: ");
                scanf("%s", data);
                getchar();

                fprintf(temp, "%s\n", data);

                fclose(fp);
                fclose(temp);

                remove("data.txt");
                rename("temp.txt", "data.txt");

                printf("Record updated successfully.\n");
                break;
            }
            case 4:
            {
                if (remove("data.txt") == 0)
                {
                    printf("File deleted successfully.\n");
                }
                else
                {
                    printf("File does not exist!\n");
                }
                break;
            }
            case 5:
                printf("Exiting program.\n");
                return 0;
        }
    }
}