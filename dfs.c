#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[20][20],reach[20],n,goal;
int dfs(int v)
{
 int i;
 reach[v]=1;
 for(i=1;i<=n;i++)
  if(a[v][i] && !reach[i])
  {
   printf("\n %d->%d",v,i);
   if(i==goal)
   {
   printf("\nGoal node found");
  exit(0);}
   dfs(i);
  }
}
void main()
{
 int i,j;
 printf("\n Enter number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  reach[i]=0;
 }
 printf("\n Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
   
   printf("enter goal node\n");
   scanf("%d",&goal);
 
 dfs(1);
}



