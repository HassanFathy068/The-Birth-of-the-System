#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int i,j,count;
    printf("Put the number to start the countdown: ");
    scanf("%d",&j);
    for(i = 0;i < j;i++){
        count = j - i;
        printf("%d\n",count);
        _beep(1000,200);
        sleep(1);
    }
    printf("Blast off to the moon!");
    return 0;
}

