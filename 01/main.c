#include <stdio.h>
#include <stdlib.h>

int get_min(int a[]);


int main(){

	FILE *file;

	if ((file = fopen("input.txt","r")) == NULL){
		printf("Error! openinng File");
		exit(1);
	}
    
	char line[10];
	int curr_max = 0;
	int curr_count = 0;
	int value;
	int top_three[3]= {0,0,0};
	int sm_top;
	while(fgets(line,10,file)){

		value = atoi(line);

		if (value != 0){
			curr_count += value;
		} else {
			if (curr_count > curr_max){
				curr_max = curr_count;
			}
			//printf("%d is the new max\n",curr_max);
			sm_top = get_min(top_three);
			if (curr_count>top_three[sm_top]){
				top_three[sm_top] = curr_count;
				printf("new member in top three: \t%d\n",curr_count);
			}
			curr_count = 0;
		}
	}
        
	fclose(file);
	int sum = 0;
	for (int i = 0;i<3;++i){
		printf("%d\n",top_three[i]);
		sum += top_three[i];
	}
	printf("\n sum: %d\n",sum);
	return 0;
}

int get_min(int a[]){
	int smallest;
	smallest = (a[0]<=a[1]) ? 0 : 1;
	smallest = (a[smallest]<=a[2])? smallest:2;
	return smallest;
}
