#include<stdio.h>

void main(){
	int nb, np, i, j;
	printf("Enter the number of blocks : ");
	scanf("%d",&nb);
	printf("Enter the number of process : ");
	scanf("%d",&np);
	int b[nb],p[np];
	printf("Enter the size of each blocks\n");
	for(i=0;i<nb;i++){
		printf("Size of block%d : ",i+1);
		scanf("%d",&b[i]);
	}
	printf("Enter the size of each process\n");
	for(i=0;i<np;i++){
		printf("Size of process%d : ",i+1);
		scanf("%d",&p[i]);
	} 
	printf("Process No | size | Block NO | Rem size\n");
	for(i=0;i<np;i++)
		for(j=0;j<nb;j++){
			if(b[j]>=p[i]){
				printf("     %d\t\t%d\t  %d\t%d\n",i+1, p[i], j+1, b[j]-p[i]);
				b[j]-=p[i];
				p[i]=-1;
				break;
			}
		}
	for(i=0;i<np;i++){
		if(p[i]!=-1)
			printf("process %d not allocated\n",i);
	}
}
