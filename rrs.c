#include <stdio.h>
/*
1:Arival time 
2:Burst time
3:remaining time
4:Completion time
5:Turn Around time
6:Waiting time
*/
void main()
{
	int n,q;
	printf("Enter the value of QUANTUM : ");
	scanf("%d",&q);
	printf("Enter the number of process to be inserted : ");
	scanf("%d",&n);
	int a[n][6], i, j, temp, k,cp=0,time=0;
	float  atat, awt, ttat=0, twt=0;
	for(i=0;i<n;i++) //collecting process details
	{
		printf("Enter the arrival time and burst time of P%d : ",i);
		scanf("%d%d",&a[i][1],&a[i][2]);
		a[i][3]=a[i][2];	
		
	}
	for(i=0;i<n-1;i++) //sorting process
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j][1]>a[j+1][1])
			{
			printf("remaining time of %d : 	%d\n",i,a[i][3]);
				for(k=1;k<=3;k++)
				{
					temp=a[j][k];
					a[j][k]=a[j+1][k];
					a[j+1][k]=temp;
				}
				
			}		
		}
	} 	
	while(cp<n)//if process available
	{
		for(i=0;i<n;i++)
		{
		
			if(a[i][3]>0)
			{
				printf("Time %d: Runnig Process:%d\n",time,i);
				a[i][3] -= q;
				time += q;
				if(a[i][3]<=0)
				{
					printf("Process %d finished\n", i);
					cp++;
					time+=a[i][3];
					a[i][4]=time;
				}
			}
		}
	} 
	for(i=0;i<n;i++)
	{
		a[i][5]=a[i][4]-a[i][1];
		ttat+=a[i][5];
		a[i][6]=a[i][5]-a[i][2]; 	 		 	
		twt+=a[i][6];
	}
	awt = twt/n;
	atat = ttat/n;	
	printf("P\tat\tbt\tcmpt\ttat\twt\n");
	for(i=0;i<n;i++) //printing
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,a[i][1],a[i][2],a[i][4],a[i][5],a[i][6]);
	}
	printf("awt:%f | atat:%f\n",awt,atat);
}
