/*
	requires lm_sensors. After installing lm_sensors please run sensors-detect to configure lm_sensors
	parsetemp is tested to work on Fujitsu Liftbook T731 and Sony Vaio TZ28-GNX FOR DEMO PURPOSE
	If "sensors" command does not show "Core 0", please change Line 61 Core 0 to a desired name that's shown
*/

#include "systeminfoFunctions.h"

void getTime(char *temp){

	FILE *fp;
	char* command = "uptime > uptime";
	system(command);
	char uptime_load[BUF_SIZE] = "\0";
	fp = fopen("uptime", "r");
    	if(fp != NULL){
      		size_t ulen = fread(uptime_load, sizeof(char), BUF_SIZE, fp);
      		if(ulen == 0){
        		fputs("getTime()", stderr);
      		}
      		else{
        		uptime_load[++ulen] ='\0';
      		}
    		fclose(fp);
    	}
    	else{
      		perror("getTime()");
      		exit(1);
    	}
	strncpy(temp,uptime_load, strlen(uptime_load));
}

void getTemp(char *temp){
	
	FILE *fp;
	char* command = "sensors > sensor";
	system(command);
	char cpu[BUF_SIZE] = "\0";
	fp = fopen("sensor", "r");
  	if(fp != NULL){
    		size_t clen = fread(cpu, sizeof(char), BUF_SIZE, fp);
fprintf(stderr, "clen = %i", clen);
    		if(clen == 0){
      			fputs("getTemp()", stderr);
    		}
    		else{
      			cpu[++clen] ='\0';
    		}
    		fclose(fp);
	}
  	else{
      		perror("getTemp()");
      		exit(1);
    	}
fprintf(stderr, "THIS WORKED");
	strncpy(temp, cpu, strlen(cpu));
}

void getIP(char *ip){
	FILE *fp;
	char *command = "curl -s icanhazip.com > ip";
	system(command);
	char ip_now[BUF_SIZE] = "\0";
	fp = fopen("ip", "r");
	if(fp != NULL) {
		size_t iplen = fread(ip_now, sizeof(char), BUF_SIZE, fp);
		if (iplen == 0) {
			fputs("getTime()", stderr);
		}
		else {
			ip_now[++iplen] = '\0';
		}
		fclose(fp);
	}
	else {
		perror("getIP()");
		exit(1);
	}
	strncpy(ip, ip_now, strlen(ip_now));
}

char* parseTemp(){
	char temp[BUF_SIZE];
	getTemp(temp);
	int i;
	char* cputemp = temp;
	cputemp = strstr(cputemp, "Core0 Temp:") + strlen("Core0 Temp:");
	cputemp = strstr(cputemp, "+");
	for(i = 0; i < sizeof(cputemp); i++){
    		if(cputemp[i] == 'C'){
      			cputemp[i+1] = '\0';
      			break;
    		}
  	}
	char*result = malloc(BUF_SIZE);
	strncpy(result, cputemp, strlen(cputemp));
	result[strlen(cputemp)] = 0;
	printf("CPU: %s\n", result);
	return result;
	//free(result);
}

char* parseUptime(){
	int i;
	char temp[BUF_SIZE];
	getTime(temp);
	char* uptime = temp;
	uptime = strstr(uptime, "up") + 2;
	for(i = 0; i < sizeof(uptime); i++){
    		if(uptime[i] == ','){
      			uptime[i] = '\0';
      			break;
    		}
  	}

	char*result = malloc(BUF_SIZE);
	strncpy(result, uptime, strlen(uptime));
	printf("Up: %s\n", result);
	return result;
	//free(result);
}

char *parseLoadtime(){
	char temp[BUF_SIZE];
	getTime(temp);
	char *loadtime = temp;
	char *load = strstr(temp, "load average: ")+strlen("load average: ");
	int i;
	for(i = 0; i < sizeof(load); i++){
    		if(load[i] == ','){
      			load[i] = '\0';
      			break;
    		}
  	}
	char *result = malloc(BUF_SIZE);
	strncpy(result,load, strlen(load));
	printf("Load: %s\n", result);
	return result;
	//free(result);
}

char *parseIP() {
	char ip[BUF_SIZE];
	getIP(ip);
	char *result = malloc(BUF_SIZE);
	strncpy(result, ip, strlen(ip));
	printf("IP: %s\n", result);
	return result;
}
