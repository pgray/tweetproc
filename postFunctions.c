#include "postFunctions.h"
#include "user.h"
/*
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
*/
int post(const char *text)
{
	const char *test_call_uri = "http://api.twitter.com/1/statuses/update.json";
	char *req_url = NULL;
	char *postarg = NULL;
	int argc = 2;
	char argv_wark[512];
	char **argv = (char**)malloc(sizeof(char*) * 2);
	argv[0] = strdup(test_call_uri);
	snprintf(argv_wark, sizeof(argv_wark), "status= %s", text);
	tcstrcututf(argv_wark, 140);
	argv[1] = strdup(argv_wark);
	req_url = oauth_sign_array2(&argc, &argv, &postarg, OA_HMAC, NULL, consumer_key, consumer_secret, access_token, access_token_secret);
	free(argv[0]);
	free(argv[1]);
	free(argv);
	oauth_http_post2(req_url, postarg, "Expect: \r\n");
	return 0;
}
