#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 4096

int countBombs(char** field, int N, int M, int x, int y){
    int bombs = 0;
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            int nx = dx + x;
            int ny = dy + y;
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == '*')
            bombs++;
        }
    }
    
    return bombs;
}


int parse_int(char *string, int *integer){
    int i = 0;
    while(isspace(string[i])) i++; // while(isspace([string[i]])) i++;
    int length = strlen(string);
    if(length == i) return 0; 

    char int_buffer[BUFFER_SIZE];
    int int_chars = 0;

    if(string[i] == '-'){
        int_buffer[int_chars] = '-';
        int_chars++; i++;

        if(!isdigit(string[i])) return 0;
    }
    
    while(i < length && !isspace(string[i])){ // isspace can't be modifed, fck
        if(!isdigit(string[i])) return 0;
        
        int_buffer[int_chars] = string[i];
        int_chars++;
        i++;
    }
    int_buffer[int_chars] = '\0';

    while(isspace(string[i])) i++; // isspace cmon

    if(string[i] != '\0') return 0;

    *integer = atoi(int_buffer);

    return 1;
}

int StringToInteger(){
        int type;
        int parsed_correct = 1;
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_int(buffer, &type);
        if(parsed_correct == 0)
            return 0;
        else
            return type;
}

#ifdef __cplusplus
}
#endif
