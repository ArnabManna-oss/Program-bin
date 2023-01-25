#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
  int data;
  struct n *link;
}Node;

Node *getnode()
{
  Node *New=(Node*)malloc(sizeof(Node));
  New->link=NULL;
  return New;
}

void Display(Node *Head)
{
  Node *a;
  if(Head==NULL)
    printf("empty");
  a=Head;
  while(a!=NULL)
  {
    printf("%d,",a->data);
    a=a->link;
  }
}

Node *InEnd(Node *Head,int y)
{
  Node *New=getnode();
  New->data=y;
  Node *last;
  
  if(Head==NULL)
  {
    Head=New;
  }
  else{
  last=Head;
  while(last->link!=NULL)
    {
      last=last->link;
    }
  last->link=New;
    }
  return Head;
  }
void bubbleSort(Node *head) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->link != lptr) {
            if (ptr1->data > ptr1->link->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->link->data;
                ptr1->link->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    } while (swapped);
}
int main()
{
  Node *List1=NULL,*List2=NULL,*List3=NULL,*a;
  int n,ch,i,j;
  printf("enter list 1 \n");
  while(1)
    {
      printf("enter 1 to insert :\n");
      scanf("%d",&ch);
      if(ch==1)
      {
        printf("enter the data");
        scanf("%d",&n);
        List1=InEnd(List1,n);
      }
      else 
        break;
    }
    printf("enter list 2 \n");
      while(1)
    {
      printf("enter 1 to insert :\n");
      scanf("%d",&ch);
      if(ch==1)
      {
        printf("enter the data");
        scanf("%d",&n);
        List2=InEnd(List2,n);
      }
      else 
        break;
    }
    printf("list 1 =");
    Display(List1);
    
    printf("list 2 =");
    Display(List2);
    
    List3=List1;
    a=List1;
    while(a->link!=NULL)
    {
    	a=a->link;
	}
	a->link=List2;
	
	printf("Merged list");
	bubbleSort(List3);
	Display(List3);
	
	
  
  return 0;
}

