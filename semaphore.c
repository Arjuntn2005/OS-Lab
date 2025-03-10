#include <stdio.h>
#include <stdlib.h>

int mutex=1;
int full=0;
int empty,x=0;

void producer()
{
   --mutex;
   ++full;
   --empty;
   x++;

printf("\nProducer produce item %d",x);
++mutex;

}

void consumer()
{
  --mutex;
  --full;
  ++empty;
printf("\nConsumer consumes item %d",x);
x--;
++mutex;
}
int main()
{
 int n,i,s;
 printf("Enter the buffer size:");
 scanf("%d",&s);
 empty=s;
 printf("\n1.Producer\n2.Consumer\n3.Exit");
 for(i=1;i>0;i++)
 {
 printf("\nEnter your choice:");
 scanf("%d",&n);
 switch(n)
 {
 case 1:
 if((mutex==1)&&(empty!=0))
 {
 producer();}
 else{
 printf("Buffer full");
 }
 break;
 case 2:
 if((mutex==1)&&(full!=0))
 {
 consumer();
 }
 else
 {
 printf("Buffer empty");
 }
 break;
 case 3:
 printf("Exiting....");
 exit(0);
 break;
   }
  }
 }
	

