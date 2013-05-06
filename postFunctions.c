#include "postFunctions.h"

void createnonce(char nonce[NONCE_LENGTH])
{
	int i,j;
	srand(time(NULL));
	for(i=0; i < NONCE_LENGTH; i++)
	{
		j = random() % NONCE_CHARS;
		if(j < 10)
			nonce[i] = j + 48;
		else if(j < 36)
			nonce[i] = j + 55;
		else
			nonce[i] = j + 61;
	}
}
