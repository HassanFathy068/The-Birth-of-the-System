#include <stdio.h>
#include <stdlib.h>

int main(){

    float mpuAccur = 79.0/100, bnoAccur = 92.0/100;
    float mpu6050[10] = {0.0,11.68,18.95,23.56,25.72,25.38,22.65,18.01,10.14,-0.26};
    float bno55[10] = {0.0,9.49,16.36,21.2,23.16,22.8,19.5,14.85,6.79,-2.69};

    float NewArr[10] = {0};
        printf("Average without accuracy: ( ");

    for (int i=0;i<10;i++){
        NewArr[i] = (mpu6050[i] + bno55[i]) / 2;
        printf("%.2f, ", NewArr[i]);
    }
        printf(")\n\n");
        printf("Average with accuracy: ( ");

    for (int i=0;i<10;i++){
        NewArr[i] = (mpu6050[i] + bno55[i]) / 2 * mpuAccur * bnoAccur;
        printf("%.2f, ", NewArr[i]);
    }
         printf(")\n");

  return 0;
}
