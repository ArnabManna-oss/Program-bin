#include<stdio.h>
#include<stdlib.h>

int count=0,max=0,min=0;
typedef struct node
{
	int info;
	struct node *lc,*rc;
}bin_tere;

typedef struct q
{
	bin_tere *arr[200];
	int front;
	int rear;
}Q;

void create(bin_tere *root)
{
	char ans;
	bin_tere *ptr;
	printf("\nDo you want to create the left child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tere*)malloc(sizeof(bin_tere));
		printf("\nenter the information for the left child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->lc=ptr;
		create(root->lc);
	}
	else
		root->lc=NULL;
	printf("\nDo you want to create the right child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tere*)malloc(sizeof(bin_tere));
		printf("\nenter the information for the right child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->rc=ptr;
		create(root->rc);
	}
	else
		root->rc=NULL;
}

void enqueue(Q *q, bin_tere *node) {
    q->arr[q->rear] = node;
    q->rear++;
}

bin_tere *dequeue(Q *q) {
   bin_tere *temp = q->arr[q->front];
    q->front++;
    return temp;
}

void levelOrder(bin_tere *root) {
    Q *q = (Q*)malloc(sizeof(Q));
    q->front = 0;
    q->rear = 0;
    enqueue(q, root);
    while (q->front != q->rear) {
        bin_tere *temp = dequeue(q);
        printf("%d ", temp->info);
        if (temp->lc)
            enqueue(q, temp->lc);
        if (temp->rc)
            enqueue(q, temp->rc);
    }
}

void mirror(bin_tere *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		bin_tere *temp=root->lc;
		root->lc=root->rc;
		root->rc=temp;
		mirror(	root->lc);
		mirror(	root->rc);
		
	}
}

int main()
{
	bin_tere *root=NULL,*ptr;
	int ch,n;
	printf("\nenter the information for the root: ");
	ptr=(bin_tere*)malloc(sizeof(bin_tere));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
	
	printf("the level wise traversal :");
	levelOrder(root);
	mirror(root);
	printf("the level wise traversal after mirror image :");
	levelOrder(root);
	return 0;
}
