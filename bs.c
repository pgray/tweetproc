#include <stdio.h>
#include <string.h>
#include <time.h>

#define NONCE_LENGTH 32
#define NONCE_CHARS 62
void createnonce(char[NONCE_LENGTH]);

int main(int argc, char **argv)
{
	char *post = "POST /1/statuses/update.json?include_entities=true HTTP/1.1\nAccept: */*\nConnection:close\n";
	char *useragent = "User-Agent: ";
	char *contentType = "Content-Type: ";
	char *auth = "Authorization: ";
	char *contentLength = "Content-Length: ";
	char *host = "Host: api.twitter.com";
	char *status = "status=";

	char nonce[NONCE_LENGTH];
	createnonce(nonce);
	int i;
	for(i=0;i<NONCE_LENGTH;i++)
		printf("%c", nonce[i]);
	printf("\n");
	return 0;
}

/* 48 - 57 numbers 65 - 90 uppercase 97 - 122 lowercase 62 numbers total */

void createnonce(char nonce[NONCE_LENGTH])
{
	int i,j;
	srand(time(NULL));
	for(i=0;i<NONCE_LENGTH;i++)
	{
		j=random() % NONCE_CHARS;
		if(j < 10)
			nonce[i] = j + 48;
		else if(j < 36)
			nonce[i] = j + 55;
		else
			nonce[i] = j + 61;
	}
}
