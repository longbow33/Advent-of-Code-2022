#include <stdio.h>
#include <stdlib.h>

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
		printf("%s",line);
		printf("common item: %c\n",comm);
		res+= scoreItem(comm);
		printf("\n");
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
	
	printf("LINE LENGTH COMPARISON\n");
	for (int i = 0;i<(len/2);++i){
		printf("%c, ",line[i]);
	}
	printf("\n");
	for (int i = len/2;i<len;++i){
		printf("%c, ",line[i]);
	}
	printf("\n");
	
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
	char alphabet[52];
	for (int i = 0; i<26;++i){
		alphabet[i] = 'a'+i;
		alphabet[i+26] = 'A'+i;
	}
	//printf("lowercase: %d-%d\tuppercase: %d-%d\n",'a','z','A','Z');
	if ((comm>=97)*(comm<=122)){
		//is lowercase
		comm-= 96;
		printf("lowercase: %d\n",comm);
	} else if ((comm>=65)*(comm<=90)){
		//is uppercase
		comm-=(65-27);
		printf("uppercase: %d\n",comm);
	}
	
	return comm;
	for (int i = 0; i<52;++i){
		printf("(%c/%d), ",alphabet[i],i+1);
	}

}
