all:
	gcc -lssl -loauth -ltokyocabinet -o oauth oauth.c
clean:
	rm -rf *o oauth
