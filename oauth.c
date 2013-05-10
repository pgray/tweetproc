//
// twitpost.c
//   require liboauth and libtokyocabinet
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <oauth.h>
#include <tcutil.h>
 
int twitter_post(const char *owner, const char *text) {
 
  const char *consumer_key        = "A8Zr8aArEDH0cE8I7Yu2aQ";
  const char *consumer_secret     = "7ukHxwX8WhYM5c4EUzTZGmKdEwmERxiblmSqSbKGc";
  const char *access_token        = "1400457920-DX2FhVVIpVCVCLij9qlm1xpoVKxqd9zubqzrUsy";
  const char *access_token_secret = "7OM6b4Wy5Ynqv8GdwxKPYZukDJTwNRRYN7w1QRfU";
 
  const char *test_call_uri = "http://api.twitter.com/1/statuses/update.json";
 
  char *req_url = NULL;
  char *postarg = NULL;
  
  int argc = 2;
  char argv_wark[512];
  char **argv = (char**) malloc(sizeof(char*) * 2);
  argv[0] = strdup(test_call_uri);
  snprintf(argv_wark, sizeof(argv_wark), "status= %s:%s", owner, text);
  tcstrcututf(argv_wark, 140);
  argv[1] = strdup(argv_wark);
  req_url = oauth_sign_array2(&argc, &argv, &postarg, OA_HMAC, NULL,
      consumer_key, consumer_secret, access_token, access_token_secret);
  free(argv[1]);
  free(argv[0]);
  free(argv);
  oauth_http_post2(req_url, postarg, "Expect: \r\n");
  return 0;
}
 
int main() {
  twitter_post("CPU", "Not Available.");
  return 0;
}
