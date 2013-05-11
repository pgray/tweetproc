/*
	Main file to be compiled and run.
	tweetproc takes in the username and password for a twitter account
	and sends hourly statistic updates about the computer it is being run on

	example: ./tweetproc username password
*/
#include "postFunctions.h"

int main(int argc, char **argv)
{ 	  	
	char *uptime = parseUptime();
	post(uptime);
	char *load = parseLoadtime();
	post(load);
  	char *CPU = parseTemp();
	post(CPU);

	return 0;
}
