/*
	Main file to be compiled and run.
	tweetproc sends hourly statistic updates about the computer it is being run on
*/
#include "postFunctions.h"

int main(int argc, char **argv)
{ 	  	
	while(1){
		char *uptime = parseUptime();
		char *load = parseLoadtime();
  		char *CPU = parseTemp();
		char postit[100];
		snprintf(postit, 100, "Up: %s, Load: %s, CPU: %s", uptime, load, CPU);
		post(postit);
		
		sleep(10);
	}
	return 0;
}
