#include<stdio.h>
#include<stdlib.h>

int count=0,max=0,min=0,k=0;
typedef struct node
{
	int info;
	struct node *lc,*rc;
}bin_tere;

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

void preorder(bin_tere *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lc);
	preorder(root->rc);
}

void inorder(bin_tere *root)
{
	if(root==NULL)
		return;
	inorder(root->lc);
	printf("%d ",root->info);
	inorder(root->rc);
}

void postorder(bin_tere *root)
{
	if(root==NULL)
		return;
	postorder(root->lc);
	postorder(root->rc);
	printf("%d ",root->info);
}

void cntleaf(bin_tere *root)
{
	
	if(root==NULL)
		return;
	if(root->lc==NULL && root->rc==NULL)
	{
		count++;
		printf("leaf=%d\n",root->info);
	}
			
	cntleaf(root->lc);
	cntleaf(root->rc);
	 
}
void Search(bin_tere *root,int n)
{
	
	if(root==NULL)
		return;
	if(root->info==n)
	{
		count=1;
		return;
	}
	Search(root->lc,n);
	Search(root->rc,n);
}

void min_max(bin_tere *root)
{
	
	if(root==NULL)
		return;
	if(root->info>=max)
	{
		max=root->info;
	}
	if(root->info<=min)
	{
		min=root->info;
	}	
	min_max(root->lc);
	min_max(root->rc);
}
int maxDepth(bin_tere *root)
{
    if (root == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(root->lc);
        int rDepth = maxDepth(root->rc);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
//
//void height(bin_tere *root)
//{
//	if(root==NULL)
//		return;
//	//printf("%d ",root->info);
//	 k++;
//	 height(root->lc);
//	 height(root->rc);
//}

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
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1. Preorder\n2. Inorder\n3. Postorder\n4. no of leafs \n5. search\n6. max min\n7. height \n8.exit");
		printf("\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: preorder(root);
					break;
			case 2: inorder(root);
					break;
			case 3: postorder(root);
					break;
			case 4:
					cntleaf(root);
					printf("no of leafs =%d",count);
					break;
			case 5:
				printf("\nenter element to be searched: ");
				scanf("%d",&n);
				Search(root,n);
				if(count==1){
					printf("found");
				}
				else
				{
					printf("not found");
				}
				count=0;
				break;
			case 6:
				max=root->info;
				min=root->info;
				min_max(root);
				printf("max =%d  min =%d",max,min);
				break;
			case 7: 
				 
				printf("the height is =%d",maxDepth(root));
			case 8: exit(0);
		}
	}
}
