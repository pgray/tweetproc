all:
	gcc -lssl -loauth -ltokyocabinet user.h postFunctions.h postFunctions.c systeminfoFunctions.h systeminfoFunctions.c tweetproc.c -o tweetproc
clean:
	rm -rf *o tweetproc
