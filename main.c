//
//  main.c
//  csvtojson
//
//  Created by Кирилл Двуреченский on 20.10.2021.
//

#include <stdio.h>

int main(int argc, char *argv[]){

    int started = 0;
    float latitude, longitude;
    char info[80];
    
    puts("data=[");

    while(scanf("%f %f %79s", &latitude, &longitude, info) == 3){

        if(started){
            printf(", \n");
        }
        else{
            started = 1;
        }

        printf("{latitude: %.2f, longitude: %.2f, info: '%s'}", latitude, longitude, info);
    }

    puts("\n]");

    return 0;
}

