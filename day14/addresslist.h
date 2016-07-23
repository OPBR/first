#define MAX_NAME_LEN	32
#define MAX_NUMBER_LEN	20

typedef struct contact{
	char name[MAX_NAME_LEN];
	char number[MAX_NUMBER_LEN];
	struct contact *next;
}Node,*LinkList;

int Menu(char *cmd, LinkList head);

int Init(LinkList *head);

int New(LinkList head);

int Remove(LinkList head);

int Update(LinkList head);

int Search(LinkList head);

int Load(LinkList head);

int Save(LinkList head);

int List(LinkList head);
