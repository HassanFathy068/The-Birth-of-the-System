#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option, remove, i=0, j, grow[100];
    char str[100][100];
    printf("Minions Task Manager \n1. Add Task \n2. View Tasks \n3. Remove Task \n4. Exit \n\n");

    while(1)        {

        printf("Select an option: ");
        scanf("%d",&option);
        getchar();

            if (option == 1){

                printf("Enter task description: ");
                fgets(str[i],sizeof(str[i]),stdin);
                printf("Task added successfully!\n\n");
                ++i;
                grow[i - 1] = i;
            }

            else if(option == 2){

                for(j = 0;j < grow[i - 1];j++){
                int id = 0;
                printf("Current Tasks: \n");
                printf("Task ID: %d\n",grow[id]);
                id++;
                printf("Description: %s\n\n",str);
                }
            }

            else if(option == 3){

                printf("Enter task ID to remove: ");
                scanf("%d",&remove);
                for (j = remove;j < i - 1;j++){
                        strcpy(str[remove], str[remove + 1]);
                        }
                printf("Task removed successfully!\n\n");
            }

            else if(option == 4){

                printf("Exiting Minions Task Manager. Have a great day!\n");
                break;
            }

            else                {

                printf("Select from 1 to 4\n");
            }

                    }

return 0;

}
