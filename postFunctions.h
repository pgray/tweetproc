/*
	This file contains all the helper functions for creating a twitter request.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <oauth.h>
#include <tcutil.h>

#define NONCE_LENGTH 32
#define NONCE_CHARS 62
#define BUF_SIZE 512
#define MSG_SIZE 140
#define POST_SIZE 100
/*
void createnonce(char[NONCE_LENGTH]);
*/
int post(const char *);
