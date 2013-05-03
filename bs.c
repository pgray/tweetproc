#include <stdio.h>
#include <string.h>
#include <time.h>

#define NONCE_LENGTH 32
void createnonce(char[NONCE_LENGTH]);

int main(int argc, char **argv)
{
	char *post = "POST /1/statuses/update.json?include_entities=true HTTP/1.1\nAccept: */*\nConnection:close\n";
	char *useragent = "User-Agent: ";
	char *contentType = "Content-Type: ";
	char *auth = "Authorization: ";
	char *contentLength = "Content-Length: ":
	char *host = "Host: api.twitter.com";
	char *status = "status=";

	char nonce[NONCE_LENGTH];
	createnonce(nonce);



	return 0;
}

void createnonce(char nonce[NONCE_LENGTH])
{
	int i,j;
	for(i=0;i<NONCE_LENGTH;i++)
	{
		j=random();
	}
}
