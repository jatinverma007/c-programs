#include<stdio.h>
main()
{
int ar[7]={10,20,20,5,30,5},ar2[10];
int i,j,k=0;
for(i=0;i<7;i++)
{
for(j=i+1;j<7;j++)
{
if(ar[i]==ar[j])
{
ar2[k++]=ar[i];
}
}
}

printf("\nthe second repition is %d ",ar2[1]);
}
