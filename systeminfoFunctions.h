/*
	contains all library and functions necessary for systeminfoFunctions.c
*/
#ifndef __SYSTEMINFOFUNCTIONS_H__
#define __SYSTEMINFOFUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 1024

void getTime(char *temp);
void getTemp(char *temp);
void getIP(char *temp);
char *parseTemp();
char *parseUptime();
char *parseLoadTime();

#endif
