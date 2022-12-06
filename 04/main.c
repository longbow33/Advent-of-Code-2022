#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MLL 13 // max line length
#define sleeptime 0
int main(){
	FILE* file;
	if ((file = fopen("input.txt","r")) == NULL){
		printf("Error opening File!");
		exit(1);
	}
	
	char line [MLL];
	int interval[] ={0,0,0,0};
	char *token;
	int sum = 0;
	int part2 = 0;
	while (fgets(line,MLL,file)){
		printf("--------------\n%s",line);
		token = strtok(line,"-,");
		if (token == NULL){
			puts("empty string");
			return 1;
		}
		for(int i= 0;token;++i){
			//puts(token);
			interval[i] = atoi(token);
			token = strtok(NULL,"-,");
		}
		printf("%d, %d, %d, %d\n",interval[0],interval[1],interval[2], interval[3]);	
		// part1
		if ((interval[0]<=interval[2])*(interval[1]>=interval[3])){
			sum+=1;
			//printf("second is fully in first!\n");

		} else if((interval[0]>=interval[2])*(interval[1]<=interval[3])){
			sum+=1;
			//printf("first is fully in second!\n");

		}
		//part2
		
		if ((interval[1]>=interval[2])*(interval[3]>=interval[0])){
			part2+=1;
			printf("overlap\n");
			sleep(sleeptime);
		}

	}
	printf("PART1: %d\n",sum);
	printf("PART2: %d\n",part2);
	return 0;
}
