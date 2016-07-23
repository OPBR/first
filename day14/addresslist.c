#include"addresslist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DATA_FILE "/tmp/data"

void PrintHelp()
{
	printf("------------------------------------------------\n");
	printf("\t\t\tAddressList System\t\t\t\n\n");
	printf("\t\t\t1.search contact\n");
	printf("\t\t\t2.new contact\n");
	printf("\t\t\t3.update contact\n");
	printf("\t\t\t4.delete contact\n");
	printf("\t\t\t5.exit\n");
	printf("------------------------------------------------\n");

}

int Menu(char *cmd, LinkList head)
{

	while(1){
		PrintHelp();
		*cmd = getchar();
		printf("cmd = %c\n",*cmd);
		setbuf(stdin,NULL);
		system("clear");
		List(head);

		switch(*cmd){

			case '1':
				Search(head);
				break;
			case '2':
				New(head);
				Save(head);
				break;
			case '3':
				Update(head);
				Save(head);
				break;
			case '4':
				Remove(head);
				Save(head);
				break;
			case '5':
				exit(EXIT_SUCCESS);
				break;
			default:
				printf("Input Error! Try Again\n");
				break;
		}
		getchar();

	}
	return 0;
}

int Init(LinkList *head)
{
	*head = (LinkList)malloc(sizeof(Node));

	strcpy((*head)->number,"\0");
	strcpy((*head)->name,"\0");

	(*head)->next = NULL;

	return 0;

}

int New(LinkList head)
{
	Node *newnode = NULL;
	newnode = (Node *)malloc(sizeof(Node));

	if (newnode == NULL){
		perror("malloc");
	}

	printf("Input Contact Name:\n");
	scanf("%s",newnode->name);
	
	printf("Input Contact Number:\n");
	scanf("%s",newnode->number);

	newnode->next = head->next;
	head->next = newnode;

	return 0;

}

int Remove(LinkList head)
{
	Node *pre = NULL;
	Node *cur = NULL;

	pre = head;
	cur = head->next;

	char d_name[MAX_NAME_LEN];
	printf("Input Name\n");
	sscanf("%s",d_name);

	while(cur != NULL){

		if (strcmp(d_name,cur->name) == 0){
			printf("Remove name is %s,Number is %s\n",cur->name,cur->number);
			pre->next = cur->next;

			free(cur);
			return 0;
		}
		cur = cur->next;
		pre = pre->next;

	}

	return 0;
	
}

int Update(LinkList head)
{
	Node *cur = NULL;
	char m_name[MAX_NAME_LEN];

	printf("Input Contact Name:\n");

	scanf("%s",m_name);

	cur = head->next;

	while(cur != NULL){
		if (strcmp(m_name,cur->name) == 0){
			printf("Input New Name\n");
			scanf("%s",cur->name);

			printf("Input New Number\n");
			scanf("%s",cur->number);

			return 0;

		}

		cur = cur->next;
	
	}

	printf("NOT FOUND %s\n",m_name);

}

int Search(LinkList head)
{
	Node *cur = NULL;
	cur = head;
	char q_name[MAX_NAME_LEN];
	printf("Input Name Or Number\n");
	scanf("%s",q_name);

	while(cur != NULL){
		if (strcmp(q_name,cur->name) == 0 || strcmp(q_name,cur->number)){
			printf("Found Contact:\n");
			printf("\tName\t\tNumber\n");
			printf("\t%s\t\t%s\n",cur->name,cur->number);

			return 0;

		}

		cur = cur->next;
	
	}

	printf("NOT FOUND %s",q_name);
	return 0;

}

int List(LinkList head)
{
	Node *cur = NULL;
	cur = head->next;

	printf("\tName\t\tNumber\n");

	while(cur != NULL){
		printf("\t%s\t\t%s\n",cur->name,cur->number);
		cur = cur->next;

	}

	return 0;

}

int Load(LinkList head)
{
	Node *newnode = NULL;
	FILE *r_file = NULL;
	r_file = fopen(DATA_FILE,"rt");
	
	if (!r_file){
		perror("fopen");
		r_file = fopen(DATA_FILE,"wt");
		
		fclose(r_file);
		return 0;
	}

	while(!feof(r_file)){				//Not the ending return 0
		newnode = (Node *)malloc(sizeof(Node));

		if (newnode == NULL){
			perror("malloc");
			exit(EXIT_FAILURE);
		
		}

		fscanf(r_file,"\t%s\t%s\n",newnode->name,newnode->number);
		printf("\t%s\t%s\n",newnode->name,newnode->number);
		

		newnode->next = head->next;
		head->next = newnode;
	
	}

	printf("Load Successfully!\n");

	fclose(r_file);

	return 0;

}

int Save(LinkList head)
{
	Node *cur = NULL;
	FILE *w_file = NULL;

	cur = head->next;

	w_file = fopen(DATA_FILE,"wt");
	if (!w_file){
		perror("fopen");
		exit(EXIT_FAILURE);
	
	}

	while(cur){
		fprintf(w_file,"\t%s\t%s\n",cur->name,cur->number);
		printf("\t%s\t%s\n",cur->name,cur->number);

		cur = cur->next;
	
	}

	printf("Save Successfully!\n");

	return 0;
}

int main(void)
{
	LinkList head = NULL;
	char cmd = '\0';

	Init(&head);

	Load(head);

	Menu(&cmd, head);

	return 0;
}
