#define TABLE_SIZE 1000

void hashfuncs(void *arg);

char newword[1000];
int i;
FILE *fptr;

struct node
{
	char word[1000];
	int count;
	struct node *next;
};

struct node hashtable[TABLE_SIZE];
