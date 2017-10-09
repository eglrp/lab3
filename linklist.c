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
#include "linklist.h"
#include<string.h>

/*find a cmd in the linklist and return the datanode pointer*/
tDataNode* FindCmd(tDataNode* head,char* cmd)
{
	if(head==NULL || cmd==NULL)
	{
		return NULL;
	}
	tDataNode *p=head;
	while(p!=NULL)
	{
		if(strcmp(p->cmd,cmd) == 0)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}

/*show all cmd in linklist*/
int ShowAllCmd(tDataNode* head)
{
	printf("Menu List:\n");
	tDataNode *p=head;
	while(p!=NULL)
	{
		printf(" - %s\n",p->cmd,p->desc );
		p=p->next;
	}
	return 0;
}