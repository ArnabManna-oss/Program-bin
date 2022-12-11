//bisection method self done
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.00001
 
float f(float x,float a0,float a1,float a2,float a3)
{
    float f1=a0*x*x*x+a1*x*x+a2*x+a3;
    return f1;
}
int main()
{
    float f0,f1,a,b,c;
    int count=0;
    float a0,a1,a2,a3;
    float xg,xl,x0,x;
    printf("enter the value of\na0(x)^3+a1(x)^2+a2x+a3\na0  a1  a2  a3\n");
    scanf("%f   %f  %f  %f",&a0,&a1,&a2,&a3);
    fflush(stdin);
    //x=sqrt(pow((a1/a0),2)-(2*(a3/a0)));
    //x=sqrt(pow((a2/a1),2)-(2*(a3/a1)));
    if(a0==0.0)//x^2+x+i
    x=sqrt(pow((a2/a1),2)-(2*(a3/a1)));
    else if(a1==0.0)//x^3+x+i
    x=sqrt(pow((a1/a0),2)-(2*(a3/a0)));
    else //x^3+x^2+x+i
    x=sqrt(pow((a1/a0),2)-(2*(a2/a0)));
    
        
    a=x;
    b=x*(-1);
    if(a>b) // assuming the lower and upper limit within which the root lies
    {xg=a;xl=b;}
    else
    {xg=b;xl=a;}
    
    do
    { 
          c=(xl+xg)/2.0;//finding the median of the two values
          f0=f(c,a0,a1,a2,a3);//finding the function with the median values
          if(f0<0)
          {
            xl=c; 
          }
          else
          {
            xg=c;
          }
          count++;
    }while(fabs(xg-xl)>e);
    
    printf("the value x for which equation is 0  is \t %f",c);
    printf("\nthe number of iterations required is ==%d",count);
    return 0;
}
