#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

    FILE *file;

    if ((file = fopen("input.txt","r")) == NULL){
        printf("Error! openinng File");
        exit(1);
    }
    
    char line[10];
    int values[3000];
    int value = atoi(line);
    int value_idx = 0;

    while(fgets(line,10,file)){
        value_idx++;
        values[value_idx] = atoi(line);
        printf("Current line: %d\n",values[value_idx]);
    }
        
    fclose(file);
    return 0;
}