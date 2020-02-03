#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],cost[20],goal,sum=0, n,count=1, r = 1;
int astar(int v,int ind) {
	int x,i,t,t1,j,k,p,cnt=0;
	x=r;
 for(i = 1; i <= n; i++){
 if(a[v][i])
 {count++;
 q[r] = i;
 cost[r]=a[v][i]+cost[ind];
 r++;
}}

 for(j=x;j<count-1;j++){
 	for(k=j+1;k<count;k++){
 	if(cost[k]<cost[j]){
 		t=q[j];
 		t1=cost[j];
 		q[j]=q[k];
 		cost[j]=cost[k];
 		cost[k]=t1;
 		q[k]=t;
	 }	
	 }
 }
  for(i=ind+1;i<x;i++){
 	if(cost[x]<cost[i])
 	{cnt+=1;
 }
}


 for(j=1;j<count-1;j++){
 	for(k=j+1;k<count;k++){
 	if(cost[k]<cost[j]){
 		t=q[j];
 		t1=cost[j];
 		q[j]=q[k];
 		cost[j]=cost[k];
 		cost[k]=t1;
 		q[k]=t;
	 }	
	 }
 }
 x-=cnt;
 for(i=ind+1;i<x;i++){
 	if(cost[x]>cost[i])
 	{printf("\n%d->%d ,Cost=%d",v,q[x],cost[x]);
 	x+=cnt;
	  	return;
 }
}
 for(i=x;i<count;i++){
 	   printf("\n %d->%d Cost=%d",v,q[i],cost[i]);
  
 
 
  	if(q[i]==goal)
   {
   printf("\nGoal node found");
   printf("\nMinimum cost to reach goal node %d\n",cost[i]);
  exit(0);}
  astar(q[i],i);
  	
 }

}


void main() {
 int v,i,j,index=0;
 printf("\n\n Heurristic Function:-\t\tSelect minimum distance node from current node \n\t\t      and if goal node is reached then return minimum cost required to reach goal node \n"); 
 printf("\t\tIf goal node is not present in followed path then we traverse back and select another next minimum node\n\n");
 printf("\n Enter the number of vertices:");
 scanf("%d", &n);
 
 for(i=1; i <= n; i++) {
 q[i] = 0;
 }
 
 printf("\n Enter graph data in matrix form:\n");
 for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
 scanf("%d", &a[i][j]);
 }
 }
 printf("We take start vertex as 1\n");
 v=1;
 printf("\n Enter the goal node\n");
 scanf("%d",&goal);
 printf("\n The node which are reachable are:\n");
 astar(v,index); }



