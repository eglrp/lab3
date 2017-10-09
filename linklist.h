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

/*data structs  and its operations*/
typedef struct DataNode
{
	char* cmd;
	char* desc;
	int (*handler)();
	struct DataNode *next;		
}tDataNode;

/*find a cmd in the linklist and return the datanode pointer*/
tDataNode* FindCmd(tDataNode *head,char* cmd);

/*show all cmd in linklist*/
int ShowAllCmd(tDataNode* head);