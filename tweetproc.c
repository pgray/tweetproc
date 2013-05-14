/*
	Main file to be compiled and run.
	tweetproc sends hourly statistic updates about the computer it is being run on
	also checks if the cpu temp is over a threshold
*/
#include "postFunctions.h"

void checkThreshold(char *temp){
	char *cpustr = strstr(temp, "+") + 1;
	char warning[POST_SIZE];
	int i=0;
	while(cpustr[i]!= '.'){
		i++;
	}
	cpustr[i] = NULL;
	int thres = (int)strtol(cpustr, (char**)NULL, 10);
	if(thres > 30){	
		printf("In warning\n\n");		
		snprintf(warning, POST_SIZE, "Warning: CPU temp over threshold (Current: %dC)", thres);
		post(warning);			
	}
}

int main(void)
{ 	  	
	while(1){
		char *uptime = parseUptime();
		char *load = parseLoadtime();
  		char *CPU = parseTemp();
		checkThreshold(CPU);
		
		char postit[POST_SIZE];
		snprintf(postit, POST_SIZE, "Up: %s, Load: %s, CPU: %s", uptime, load, CPU);
		post(postit);
		
		sleep(10);
	}
	return 0;
}
