#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 4096

long long max_diagonal(int*** arr, int N){
    int sum1 = 0; int sum2 = 0; int sum3 = 0; int sum4 = 0;
    for(int i = 0; i < N; i++){
        sum1 += arr[i][i][i];
        sum2 += arr[i][N - 1 - i][i];
        sum3 += arr[i][i][N - 1 - i];
        sum4 += arr[i][N - 1 - i][N -1 - i];
    }
    if(sum1 >= sum1 && sum1 >= sum3 && sum1 >= sum4){
        return sum1;
    }else if(sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4){
        return sum2;
    }else if(sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4){
        return sum3;
    }else{
        return sum4;
    }
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
