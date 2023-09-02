#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    while(1){
    printf("Select 1 to print GRU \nSelect 2 to print MIA \nSelect 3 to print GOAT \nSelect 4 to exit \n ");
    scanf("%d",&num);
        if (num == 1)   {
            printf("\n*****   ****    *   *\n");
            printf("*       *   *   *   *\n");
            printf("*  **   *  *    *   *\n");
            printf("*   *   *   *   *   *\n");
            printf("*****   *    *  *****\n\n");
                        }
        else if (num == 2)
           {
            printf("\n*   *   *****     *  \n");
            printf("** **     *     *   *\n");
            printf("* * *     *     *****\n");
            printf("*   *     *     *   *\n");
            printf("*   *   *****   *   *\n\n");
                        }
        else if (num == 3)
            {
            printf("\n*****     *       *     *****\n");
            printf("*       *   *   *   *     *  \n");
            printf("*  **   *   *   *****     *  \n");
            printf("*   *   *   *   *   *     *  \n");
            printf("*****     *     *   *     *  \n\n");
                        }
        else if (num == 4)
            {
            printf("\nHave a nice day  X]\n");
            break;
                        }
        else
            printf("\nSELECT FROM 1 TO 4\n\n");
        }

    return 0;
}
