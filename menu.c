/************************************************************************/
/* 				Copyright(C) mclab.com SSE@USTC , 2017.10.01		    */
/* 				FILENAME				:menu.c						    */
/* 				PRINCIPAL AUTHOR		:heyulin					    */
/* 				SUBSYSTEM NAME			:mene						    */
/* 				MODULE NAME				:menu						    */
/* 				LANGUAGE				:C						        */
/* 				TARGET ENVIRONMENT		:ANY						    */
/* 				DATE OF FIRST RELEASE	:2017/10/01					    */
/* 				DESCRIPTION				:This is a program 			    */ 	
/************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linklist.h"

int Help();
int Quit();
int Cat(char cmd[]);
int Clear(char cmd[]);
int Ping(char cmd[]);
int Grep(char cmd[]);
int Ls(char cmd[]);
int Man(char cmd[]);

/*Filter the input command*/
void  FilterCmd(char cmd[],char FilterCmd[]);

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10


/*Menu Program*/
static tDataNode head[]=
{
	{"help","this is help command!",Help,&head[1]},
	{"version","menu program v1.0",NULL,&head[2]},
	{"quit","quit from the menu",Quit,&head[3]},
	{"cat","cat file content in read mode",Cat,&head[4]},
	{"clear","clear the screen ",Clear,&head[5]},
	{"ping","ping host or network device",Ping,&head[6]},
	{"grep","Find the specified content in the file",Grep,&head[7]},
	{"ls","List  information  about  the FILEs",Ls,&head[8]},
	{"man","Describe the usage of the command",Man,NULL}
};

/*show help information */
int Help()
{
	ShowAllCmd(head);
	return 0;
}

/*exit the menu program*/
int Quit()
{
	exit(0);
	return 0;
}

/*cat file content in read mode*/
int Cat(char cmd[])
{
	system(cmd);
	printf("\n");
	return 0;
}

/*clear the screen*/
int Clear(char cmd[])
{
	system(cmd);
	printf("\n");
	return 0;
}

/*ping host or network device*/
int Ping(char cmd[])
{
	system(cmd);
	printf("\n");
	return 0;
}

/*Find the specified content in the file*/
int Grep(char cmd[])
{
	system(cmd);
	printf("\n");
	return 0;
}

/*List  information  about  the FILEs*/
int Ls(char cmd[])
{
	system(cmd);
	printf("\n");
	return 0;
}

/*Describe the usage of the command*/
int Man(char cmd[])
{
	system(cmd);
	printf("\n");
	return 0;
}

/*Filter the input command*/
void FilterCmd(char cmd[],char CmdFiltered[])
{
	for(int i=0;i<strlen(cmd);i++)
	{
		if(cmd[i]!='\n' && cmd[i]!=' ')
		{
			CmdFiltered[i]=cmd[i];
		}
	}
}

/*main function */
int main(int argc, char const *argv[])
{

	char cmd[CMD_MAX_LEN];
	char CmdFiltered[CMD_MAX_LEN];
	/* cmd line begin */
	while(1)
	{
		/*Initialize memory*/
		memset(cmd,0,sizeof(cmd));
		memset(CmdFiltered,0,sizeof(CmdFiltered));

		printf("Input your command >");
		fgets(cmd,CMD_MAX_LEN,stdin);

		/*Filter command*/
		FilterCmd(cmd,CmdFiltered);

		tDataNode *p =FindCmd(head,CmdFiltered);
		if(p==NULL)
		{
			printf("This is wrong cmd\n");
			continue;
		}
		printf("%s - %s\n",p->cmd,p->desc);
		if(p->handler!=NULL)
		{
			puts(cmd);
			p->handler(cmd);
		}
	}
	return 0;
}