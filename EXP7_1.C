#include<stdio.h>
int main(){
	int nb, np,i,j;
	printf("Enter the number of blocks : ");
	scanf("%d",&nb);
	int b[nb],flag[nb];
	printf("Enter the size of each blocks : ");
	for(i=0;i<nb;i++){
		scanf("%d",&b[i]);
		flag[i]=0;
	}
	printf("Enter the number of process : ");
	scanf("%d",&np);
	int p[np],allocation[np];
	printf("Enter the size of each process : ");
	for(i=0;i<np;i++){
		scanf("%d",&p[i]);
		allocation[i]=-1;
	}
	for(i=0;i<np;i++){
		for(j=0;j<nb;j++){
			if((flag[j]!=1)&&(p[i]<=b[j])){
				allocation[i]=j;
				flag[j]=1;
				break;
			}
		}
	}
	printf("Process No\tProcess Size\tBlock Allocated\n");
	for(i=0;i<np;i++){
		printf("%d\t\t%d\t\t",i+1,p[i]);
		if(allocation[i]==-1)
			printf("Not Allocated");
		else
			printf("%d\n",allocation[i]+1);
	}
}
