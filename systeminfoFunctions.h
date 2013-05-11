#ifndef __GETSENSOR_H__
#define __GETSENSOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 512

void getTime(char *temp);
void getTemp(char *temp);
char *parseTemp();
char *parseUptime();
char *parseLoadTime();

#endif
