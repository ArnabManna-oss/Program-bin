#include<stdio.h>
#include<stdlib.h>

int count=0,max=0,min=0,len=0;
int pre[100],post[100],in[100],ic=0,pc=0,poc=0;
typedef struct node
{
	int info;
	struct node *lc,*rc;
}bst;

void create(bst *root)
{	
	len++;
	char ans;
	bst *ptr;
	printf("\nDo you want to create the left child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bst*)malloc(sizeof(bst));
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
		ptr=(bst*)malloc(sizeof(bst));
		printf("\nenter the information for the right child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->rc=ptr;
		create(root->rc);
	}
	else
		root->rc=NULL;
}

void preorder(bst *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lc);
	preorder(root->rc);
}

void inorder(bst *root)
{
	if(root==NULL)
		return;
	inorder(root->lc);
	printf("%d ",root->info);
	inorder(root->rc);
}

void postorder(bst *root)
{
	if(root==NULL)
		return;
	postorder(root->lc);
	postorder(root->rc);
	printf("%d ",root->info);
}

void cntleaf(bst *root)
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
void Search(bst *root,int n)
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

void min_max(bst *root)
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

void inSuc(bst *root)
{
	if(root==NULL)
		return;
	inSuc(root->lc);
	//printf("%d ",root->info);
	in[ic++]=root->info;
	inSuc(root->rc);
}

void posSuc(bst *root)
{
	if(root==NULL)
		return;
	posSuc(root->lc);
	posSuc(root->rc);
	//printf("%d ",root->info);
	post[poc++]=root->info;
}

void preSuc(bst *root)
{
	if(root==NULL)
		return;
	//printf("%d ",root->info);
	pre[pc++]=root->info;
	preSuc(root->lc);
	preSuc(root->rc);
}

int height(bst *root)
{
	if(root==NULL)
	return 0;
	
	int left_height = height(root->lc);
    int right_height = height(root->rc);
	
	return (left_height>right_height?left_height:right_height)+1;
	
}

int main()
{
	bst *root=NULL,*ptr;
	int ch,n,i,j=0,len=0;
	printf("\nenter the information for the root: ");
	ptr=(bst*)malloc(sizeof(bst));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1. Preorder\n2. Inorder\n3. Postorder\n4. no of leafs \n5. search\n6. max min\n7. inorder Successor \n8. postorder Successor \n9. preorder successor \n10. inorder predicessor \n11. postorder predicessor \n12. preorder predicessor \n13. height of tree \n14. exit");
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
				printf("enter the value :");
				scanf("%d",&n);
				 inSuc(root);
				 j=0;
				 len=ic;
				 //printf("%d",len);
				 for(i=0;i<len;i++)
				 {
				 	
				 	if(in[i]==n)
				 	{
						j=1;
						break;
					}
				 }
				 if(j==1)
				 {
				 	printf("%d",i);
				 	if(i==len-1)
					 	printf("no Successor");
				 	else
					 	printf("the successor of %d is %d",n,in[i+1]);
				 }
				 else
				 	printf("no successor");
				 break;
			case 8:
				printf("enter the value :");
				scanf("%d",&n);
				 posSuc(root);
				 j=0;
				 len=poc;
				 for(i=0;i<len;i++)
				 {
				 	if(post[i]==n)
				 	{
						j=1;
						 break;
					}
				 }
				 if(j==1){
				 	if(i==len-1)
				 	printf("no Successor");
				 	else
				 	printf("the successor of %d is %d",n,post[i+1]);
				 }
				 else
				 printf("no node");
				 break;
			case 9:
				printf("enter the value :");
				scanf("%d",&n);
				 preSuc(root);
				 j=0;
				 len=pc;
				 for(i=0;i<len;i++)
				 {
				 	if(pre[i]==n)
				 	{
						j=1;
						 break;
					}
				 }
				 if(j==1){
				 	if(i==len-1)
				 	printf("no Successor");
				 	else
				 	printf("the successor of %d is %d",n,pre[i+1]);
				 }
				 else
				 printf("no node");
				 break;
			case 10:
				 printf("enter the value :");
				 scanf("%d",&n);
				 inSuc(root);
				 j=0;
				 len=ic;
				 //printf("%d",len);
				 for(i=0;i<len;i++)
				 {	
				 	if(in[i]==n)
				 	{
						j=1;
						break;
					}
				 }
				 if(j==1)
				 {
				 	printf("%d",i);
				 	if(i==0)
					 	printf("no predicessor");
				 	else
					 	printf("the predicessor of %d is %d",n,in[i-1]);
				 }
				 else
				 	printf("no successor");
				 break;
			case 11:
				 printf("enter the value :");
				 scanf("%d",&n);
				 posSuc(root);
				 j=0;
				 len=poc;
				 for(i=0;i<len;i++)
				 {
				 	if(post[i]==n)
				 	{
						j=1;
						 break;
					}
				 }
				 if(j==1){
				 	if(i==0)
				 	printf("no predicessor");
				 	else
				 	printf("the predicessor of %d is %d",n,post[i-1]);
				 }
				 else
				 printf("no node");
				 break;
			case 12:
				 printf("enter the value :");
				 scanf("%d",&n);
				 preSuc(root);
				 j=0;
				 len=pc;
				 for(i=0;i<len;i++)
				 {
				 	if(pre[i]==n)
				 	{
						j=1;
						 break;
					}
				 }
				 if(j==1){
				 	if(i==0)
				 	printf("no predicessor");
				 	else
				 	printf("the predicessor of %d is %d",n,pre[i-1]);
				 }
				 else
				 printf("no node");
				 break;
			case 13:
				printf("height of the tree is %d",height(root));
			case 14:
			exit(0);
		}
	}
}
