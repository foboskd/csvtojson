//
//  main.c
//  csvtojson
//
//  Created by Кирилл Двуреченский on 20.10.2021.
//

#include <stdio.h>
#include <string.h>



void error_logger(char *name){ // функция создающая файл, с записью что что то не работает
    FILE *file_out = fopen(name, "a");
    fprintf(file_out, "Not work!");
    fclose(file_out);
}

void screen_out(FILE *name){ // функция для вывода на экран
    int started = 0; // пока сделан простой переключатель для переноса строки
    char latitude[80], longitude[80], text[80];
    
    
    puts("data=["); // открываем объект для формирования внутреннего содержания json
    
    while (fscanf(name, "%s %s %s", latitude, longitude, text) == 3){ // напоминаю что fscanf отдает значение равное колличеству принятых параметров, поэтому если fscanf == 3 то цикл while продолжает работать по строке в файле
        
        if(started){
            printf(", \n"); // для того что бы ставить перенос строки переменная должна быть равна 1
        }
        else{
            started = 1;
        }
        
        printf("{latitude: %s, longitude: %s, info: '%s'}", latitude, longitude, text);
        
    }
    
    puts("\n]"); // закрываем объект для json
}



void file_out(FILE *name){ // функция для вывода в файл
    int started = 0; // пока сделан простой переключатель для переноса строки
    char latitude[80], longitude[80], text[80];
    FILE *file_out = fopen("outfile.json", "w");
    
    fprintf(file_out, "data=["); // открываем объект для формирования внутреннего содержания json
    
    while (fscanf(name, "%s %s %s", latitude, longitude, text) == 3){ // напоминаю что fscanf отдает значение равное колличеству принятых параметров, поэтому если fscanf == 3 то цикл while продолжает работать по строке в файле
        
        if(started){
            fprintf(file_out, ", \n"); // для того что бы ставить перенос строки переменная должна быть равна 1
        }
        else{
            started = 1;
        }
        
        fprintf(file_out, "{latitude: %s, longitude: %s, info: '%s'}", latitude, longitude, text);
        
    }
    
    fprintf(file_out, "\n]"); // закрываем объект для json
}


int main(int argc, char *argv[]){

    FILE *in = fopen(argv[1], "r"); // создаем тип данных для потока из файла и открываем его на чтение о чем говорит 2-й параметр функции
    
    if(!(in = fopen(argv[1], "r"))){
        error_logger(argv[2]);
    }
    
   
    if(*argv[3] == 's'){ // если поставили параметр s значит выводим на экран
        screen_out(in);
    }
    else if(*argv[3] == 'f'){ // если поставили значение f то выводим в файл
        file_out(in);
    }
    
    
    
    fclose(in);
    
    return 0;
}

