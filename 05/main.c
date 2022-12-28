#include <regex.h>
#include <stdio.h>
#include <string.h>

int runRegex(char *source, char *regexString, size_t maxGroups);

int main(){
	char * source = "move 44 from 9 to 1";
	char * regexString = "move ([0-9]*) from ([0-9]*) to ([0-9]*)";
	size_t maxGroups = 4;

	runRegex(source, regexString, maxGroups);

	//secondpart
	
	source = "[P] [F] [H] [R] [Z] [J] [J] [D] [D]";
	regexString = "\\[([A-Z]| )\\]]";
	maxGroups = 9;

	runRegex(source, regexString, maxGroups);

	return 0;
}

int runRegex(char * source, char * regexString, size_t maxGroups){
	regex_t regexCompiled;
	regmatch_t groupArray[maxGroups];

	if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
	{
		printf("Could not compile regular expression.\n");
		return 1;
	}
	if (regexec (&regexCompiled, source, maxGroups, groupArray, 0) == 0)
	{
		unsigned int g = 0;
		for (g = 0;g<maxGroups; g++)
		{
			if (groupArray[g].rm_so == (size_t)-1)
			{
				printf("This is the exit Funtion being called\n");
				break;
			}
			char sourceCopy[strlen(source) +1];
			strcpy (sourceCopy, source);
			sourceCopy[groupArray[g].rm_eo] = 0;
			printf("Group %u: [%2u-%2u]: %s\n",
				g, groupArray[g].rm_so, groupArray[g].rm_eo,
				sourceCopy+ groupArray[g].rm_so);
		}
	}
	regfree(&regexCompiled);

	return 0;
}
