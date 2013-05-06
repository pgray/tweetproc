//** rememeber to install lm-sensors
//** requires openssl dev lib
//** requires oauth dev lib
//** ONLY WORKS ON MY SONY LAPTOP FOR DEMO PURPOSE

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <openssl/hmac.h>

#define BUF_SIZE 512


int main(int argc, char**argv){

  char* command = "sensors > sensor | uptime > uptime";  
  char cputemp[BUF_SIZE] = "\0";
  char uptime_load[BUF_SIZE] = "\0";
  int i;
  FILE* fp; 
  
  // exec system call to get sensor reading
  system(command);
  
  // read from sensor file
  fp = fopen("sensor", "r");
  if(fp != NULL){
    size_t clen = fread(cputemp, sizeof(char), BUF_SIZE, fp);
    if(clen == 0){
      fputs(argv[0], stderr);
    }
    else{
      cputemp[++clen] ='\0';
    }
    fclose(fp);
  }
  else{
      perror(argv[0]);
      exit(1);
    }
  
  // read from uptime_load file
    fp = fopen("uptime", "r");
    if(fp != NULL){
      size_t ulen = fread(uptime_load, sizeof(char), BUF_SIZE, fp);
      if(ulen == 0){
        fputs(argv[0], stderr);
      }
      else{
        uptime_load[++ulen] ='\0';
      }
    fclose(fp);
    }
    else{
      perror(argv[0]);
      exit(1);
    }
  
  // print out reading
  printf("-------------------System Sensors & Uptime---------------------\n\n");
  printf("%s\n", &cputemp);
  printf("%s\n", &uptime_load);

  
  // parse uptime
  char *uptime = uptime_load;
  uptime = uptime + 13;
  char *temp_end = NULL;
  
  for(i = 0; i < sizeof(uptime); i++){
    if(uptime[i] == ','){
      uptime[i] = '\0';
      temp_end = &uptime[i];
      break;
    }
  }
  
  // parse load
  char *load = strstr(temp_end+1, ":") + 2;
  load[strlen(load)] = '\0';
  
  // parse sensor
  char* coretemp = strstr(cputemp, "Core 0");
  int k = 0;
  char* core0;
  while(coretemp[k] != '\n'){
    core0[k] = coretemp[k];
    k++;    
  }
  core0[k] = '\0';
  core0 = strstr(core0, "+");
  core0[strlen(core0)] = '\0';
  
  char* core1 = strstr(coretemp, "Core 1");
  core1 = strstr(core1, "+");
  core1[strlen(core1)] = '\0';
  
  // print out parsed data
  
  printf("\n\n-------------------------Parsed Data---------------------------\n\n");
  printf("\nUptime: %s hours\n", uptime);  
  printf("Load: %s\n", load);
  printf("Core 0 temperature: %s\n", core0);  
  printf("Core 1 temperature: %s\n", core1);    
  printf("---------------------------------------------------------------\n");
  
  return 0;
}
