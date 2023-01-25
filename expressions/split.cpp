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

int main()
{
  Node *Head=NULL,*even=NULL,*odd=NULL,*a;
  int n,ch;
  
  while(1)
    {
      printf("enter 1 to insert :\n");
      scanf("%d",&ch);
      if(ch==1)
      {
        printf("enter the data");
        scanf("%d",&n);
        Head=InEnd(Head,n);
      }
      else 
        break;
    }
    a=Head;
    while(a->link!=NULL)
    {
      if(a->data%2==0)
        even=InEnd(even,a->data);
      else
        odd=InEnd(odd,a->data);
       a=a->link; 
    }
  printf("orighinal list\n");
  Display(Head);

  printf("\neven list\n");
  Display(even);

  printf("\nodd list\n");
  Display(odd);
  
  return 0;
}

