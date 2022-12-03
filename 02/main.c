#include <stdio.h>
#include <stdlib.h>

int getPoints(char opp, char me);
int getFixedOutcome(char opp, char outpcome);

int main(){
	FILE *file;
	if ((file = fopen("input.txt","r")) == NULL){
		printf("Error opening file!");
		exit(1);
	}

	char line[5];
	int points = 0;
	int pointsThisRound;
	int pointsFixedOutcome = 0;
	int fixThisRound;
	while (fgets(line,5,file)){
		//printf("%s\n",line);
		
		pointsThisRound = getPoints(line[0],line[2]);
		fixThisRound = getFixedOutcome(line[0], line[2]);
		pointsFixedOutcome+= fixThisRound; 
		printf("HE %c, %c -> %d/%d\n",line[0],line[2],pointsThisRound,fixThisRound);
		points += pointsThisRound;
		printf("New Point Standings: %d\n",points);
		printf("Points with Fixed outcome: %d\n",pointsFixedOutcome);
	}
	fclose(file);
	return 0;
}


int getPoints(char opp, char me){
	// A = rock
	// B = paper
	// C = scissors
	//
	// X = rock
	// Y = paper
	// Z = scissors
	
	switch (opp) {
		case 'A'://rock
			switch (me){
				case 'X': return 4;
				case 'Y': return 8;
				case 'Z': return 3;
			}
		case 'B'://paper
			switch (me){	
				case 'X': return 1;
				case 'Y': return 5;
				case 'Z': return 9;
			}
		case 'C'://scissors
			switch (me){	
				case 'X': return 7;
				case 'Y': return 2;
				case 'Z': return 6;

			}
	}
}

int getFixedOutcome(char opp, char outcome){
	switch (opp){
		case 'A': //rock
			  switch (outcome){
			  	case 'X': return getPoints(opp, 'Z');
				case 'Y': return getPoints(opp, 'X');
				case 'Z': return getPoints(opp, 'Y');
			  }
		case 'B': //paper
			  switch (outcome){
			  	case 'X': return getPoints(opp, 'X');
				case 'Y': return getPoints(opp, 'Y');
				case 'Z': return getPoints(opp, 'Z');
			  }
		case 'C': //scissors
			  switch (outcome){
			  	case 'X': return getPoints(opp, 'Y');
				case 'Y': return getPoints(opp, 'Z');
				case 'Z': return getPoints(opp, 'X');
			  }
	}	
}
