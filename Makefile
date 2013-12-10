all:
	gcc user.h postFunctions.h postFunctions.c systeminfoFunctions.h systeminfoFunctions.c tweetproc.c -o tweetproc -lssl -loauth -ltokyocabinet
clean:
	rm -rf *o tweetproc ip sensor uptime 
