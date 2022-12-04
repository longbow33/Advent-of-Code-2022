#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 64

char getCommonItem(char line[]);
int scoreItem(char comm);

int main(){
	FILE *file;
	if ((file = fopen("input.txt","r")) == NULL){
		printf("Error opening file!\n");
		exit(1);
	}
	
	char line[MAX_LINE_LEN];
	char comm;
	int res = 0;
	while (fgets(line,MAX_LINE_LEN,file)){
		comm = getCommonItem(line);
		res += scoreItem(comm);
		
	}
	printf("RESULT: %d\n",res);
	return 0;
}

char getCommonItem(char line[]){
	int len;	
	char comm;
	for (int i=0;i<MAX_LINE_LEN;++i){
		if (line[i] == '\n'){	
			len = i;
			//printf("length of line:%d\n",len);
			break;
		}
	}
	// first half: 0-len//2-1
	// second half: len//2-len
	
	for (int i = 0;i<(len/2)-1;++i){
		//printf("%d\t%d\n",line[i],line[i+len/2]);
		//printf("%d\t%d\n",'a','A');
		for (int j = (len/2); j < len; ++j){
			if (line[i] == line[j]){
				//printf("common item:\t%c\n",line[j]);
				return line[j];
			}
		}
	}
}

int scoreItem(char comm){
	printf("%c is lower : %d\n", comm, islower(comm));
	int prio_lower_a = 1;
	int prio_upper_a = 27;
	return islower(comm) ? comm-'a'+ prio_lower_a : comm - 'A' + prio_upper_a;
}
