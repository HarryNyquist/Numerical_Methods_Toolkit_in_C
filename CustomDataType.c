#include<stdio.h>
#include<math.h>

int *hugeFloat(float float_number){ //initial conversion from float to hugeFloat datatype
    int *output = (int*)malloc(104 * sizeof(int));
    for(int i = 0; i < 104; i++){
        *(output + i) = 0; //Makes the array have only zeroes basically
    }
    if(float_number < 0){
        *(output + 0) = 1; //adding 0 is just for uk, our own sanity lol. Sign of number btw
    }
    float temp = float_number;
    int exponent = 0;
    while(temp > 10){
        exponent += 1;
        temp /= 10;
    }
    if(exponent = 0){
        counter = 0;
        while((int)temp = 0){
            exponent -= 1;
            temp *= 10;
            counter += 1;
            if(counter == 99){
                exponent = 0;
                temp = 0;
                break;
            }
        }
    }
    if (exponent > 99){
        fprintf(stderr, "Error: Exponent cannot be greater than 99!(No, do not make a factorial joke please)");
    }
    else if(exponent < -99){
        fprintf(stderr, "Error: Exponent cannot be less than -99!(No, do not make a factorial joke please)");
    }
    if(exponent < 0){
        *(output + 1) = 1; //Sign of exponent
    }
    

}