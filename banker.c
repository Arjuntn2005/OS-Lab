#include<stdio.h>
int main()
{

int p,c,i,j,count=0,terminate=0;

 printf("enter the number of process and resourses: ");
 scanf("%d %d",&p,&c);
 
 int alc[p][c],max[p][c],need[p][c],available[c],safe[p],done[p];
 
 printf("Enter the allocation matrix(%d x %d);\n",p,c);
  for(i=0;i<p;i++)
  {
     for(j=0;j<c;j++)
     {
    scanf("%d",&alc[i][j]);
     }
 }
printf("Enter the Maximum matrix(%d x %d)\n",p,c);
for(i=0;i<p;i++)
{
   for(j=0;j<c;j++)
   {
      scanf("%d",&max[i][j]);
   }
}
printf("Enter the availble resources:\n");
for(i=0;i<c;i++) 
scanf("%d",&available[i]);

printf("\nNeed Matrix:\n");
for(i=0;i<p;i++)
{
done[i]=0;

for(j=0;j<c;j++) 
{
need[i][j]=max[i][j]-alc[i][j];
printf("%d\t",need[i][j]);
}
printf("\n");
}
while(count<p)
{
for(i=0;i<p;i++)
{
  if(!done[i])
  {
   for(j=0;j<c;j++)
   {
   if(need[i][j]>available[j]) break;
   }
if(j==c)
{
safe[count++] =i;
done[i]=1;
for(j=0;j<c;j++)
 {
 available[j]+= alc[i][j];
 }
terminate=0;
}
else 
{
terminate++;
}
}
}
if(terminate==p-1){
printf("Not Safe (Dead lock arrives)\n");
return 0;
}
}
printf("\n Availuble resources after completion :\n");
for(i=0;i<c;i++)
 {
 printf("%d\t",available[i]);
 }
printf("\n Safe sequence:\n");
for(i=0;i<p;i++)
 {
 printf("P%d\t",safe[i]);
 }

return 0;
}

