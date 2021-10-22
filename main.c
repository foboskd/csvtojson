//
//  main.c
//  csvtojson
//
//  Created by Кирилл Двуреченский on 20.10.2021.
//

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    int started = 0; // пока сделан простой переключатель для переноса строки
    
    char latitude[80], longitude[80], text[80];
    
    
    FILE *in = fopen(argv[1], "r"); // создаем тип данных для потока из файла и открываем его на чтение о чем говорит 2-й параметр функции
    
    FILE *file_out = fopen(argv[2], "a");
    
    if(!(in = fopen(argv[1], "r"))){
        fprintf(file_out, "Not work!");
    }
    
    puts("data=["); // открываем объект для формирования внутреннего содержания json
    
    while (fscanf(in, "%s %s %s", latitude, longitude, text) == 3){ // напоминаю что fscanf отдает значение равное колличеству принятых параметров, поэтому если fscanf == 3 то цикл while продолжает работать по строке в файле
        
        if(started){
            printf(", \n"); // для того что бы ставить перенос строки переменная должна быть равна 1
        }
        else{
            started = 1;
        }
        
        printf("{latitude: %s, longitude: %s, info: '%s'}", latitude, longitude, text);
        
    }
    
    puts("\n]"); // закрываем объект для json
    
    fclose(in);
    fclose(file_out);

    return 0;
}

