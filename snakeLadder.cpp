#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void printludo()
{
	printf("\n| 30 | 29 |$28 | 27 | 26#|");
	printf("\n| 21*|*22$| 23 | #24| 25#|");
	printf("\n| 20#|*19$| 18 |#17 | 16#|");
	printf("\n| 11#|*12 | 13#| 14 |$15 |");
	printf("\n| 10#|* 9 | 8# | 7 $| 6  |");
	printf("\n| 1  |* 2 | 3 $| 4 $| 5  |");
	printf("\n$ and * represent snake and # represent ladder");
	printf("ladder 1= form 10 to 20\nladder 2= form 8 to 24\nladder 3= form 16 to 26\nsnake 1= form 15 to 3\nsnake 2= form 21 to 2\nsnake 3= form 28 to 12\n");
}
typedef struct play
{
	int pos;
	int dice;
}player;

int dice(player p)
{
	p.dice=(rand() % 6) + 1;
	return p.dice;
}
int ladder(player p)
{
	int i;
	int arr[6][2]={{8,24},{10,20},{15,3}};
	for(i=0;i<6;i++)
	{
		if(arr[i][0]==p.pos)
		{
			p.pos=arr[i][1];
			printf("\n|--|");
    		printf("\n|--|");
    		printf("\n|--|");
    		printf("\n|--|");
        	printf("\n|--|");
		}
	}
	
	return p.pos;
}

int snake(player p)
{
	int i;
	int arr[6][2]={{16,26},{21,2},{28,12}};
	for(i=0;i<6;i++)
	{
		if(arr[i][0]==p.pos)
		{
			p.pos=arr[i][1];
			
	printf("\n <<<<<<<<<<<<>>>))))))))3>>>>");
		}
	}
	return p.pos;
}

int main()
{
	printludo();
	char ch;
	player p1;
	p1.pos=0;
	while(1)
	{
		printf("enter y to role a dice : ");
		fflush(stdin);
		ch=getche();
		if(p1.pos<30 && (ch=='y' || ch=='Y'))
		{
			if(p1.pos<=25)
			{
	    	l:
	    	p1.dice=dice(p1);
		    printf("the dice rolled –------> %d",p1.dice);
		    p1.pos=(p1.pos)+(p1.dice);
		    p1.pos=ladder(p1);
		    p1.pos=snake(p1);
	    	printf("\nvalue is %d \n",p1.pos);
	    	continue;
			}
			else if (p1.pos>=25 && p1.pos<30)
			{
				if(p1.pos==25 && (p1.dice>0 && p1.dice<6))
				goto l;
				else if(p1.pos==26 && (p1.dice>0 && p1.dice<5))
				goto l;
				else if(p1.pos==27 && (p1.dice>0 && p1.dice<4))
				goto l;
				else if(p1.pos==28 && (p1.dice>0 && p1.dice<3))
				goto l;
				else if(p1.pos==29 && (p1.dice>0 && p1.dice<2))
				goto l;
				else
				{
					continue;
				}
			}
		}
		else
		printf("you win");
		exit(0);
	}
	return 0;
}
