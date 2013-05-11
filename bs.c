#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *fp;
	fp = popen("uptime", "r");

	int i, ch1, ch2;
	while (ch1 != 'u')
		ch1 = fgetc(fp);

	char time[32];
	time[0] = ch1;
	for(i = 1; i < 31; i++)
	{
		time[i] = ch1 = fgetc(fp);
	}
	time[11] = 0;
	printf("Time: %s\n", time);

	pclose(fp);
	return 0;
}
