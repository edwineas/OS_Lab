#include <stdio.h>
int main()
{
 	int n;
	printf("Enter the number of process to be inserted : ");
	scanf("%d",&n);
	int a[n][5], i, j, temp, cmpt, s, k;
	float  atat, awt, ttat=0, twt=0;
	for(i=0;i<n;i++) //collecting process details
	{
		printf("Enter the arrival time and burst time of P%d : ",i);
		scanf("%d%d",&a[i][1],&a[i][2]);
	}
	for(i=0;i<n-1;i++) //sorting process
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j][1]>a[j+1][1])
			{
				for(k=1;k<=2;k++)
				{
					temp=a[j][k];
					a[j][k]=a[j+1][k];
					a[j+1][k]=temp;
				}
				
			}		
		}
	}
	a[0][3]=a[0][1]+a[0][2];
	a[0][4]=a[0][3]-a[0][1];
	a[0][5]=a[0][4]-a[0][2];
 	for(i=1;i<n-1;i++) //sorting in burst time process
	{
		for(j=1;j<n-1-i;j++)
		{
			if(a[j][2]>a[j+1][2])
			{
				for(k=1;k<=2;k++)
				{
					temp=a[j][k];
					a[j][k]=a[j+1][k];
					a[j+1][k]=temp;
				}
				
			}		
		}
	}
	for(i=1;i<n;i++)
	{
		a[i][3]=a[i-1][3]+a[i][2];
		a[i][4]=a[i][3]-a[i][1];
		a[i][5]=a[i][4]-a[i][2];
	}
	for(i=0;i<n;i++)
	{
		ttat=ttat+a[i][4];
		twt=twt+a[i][5];
	}
	atat=ttat/n;
	awt=twt/n;
	for(i=0;i<n-1;i++) //sorting process
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j][1]>a[j+1][1])
			{
				for(k=1;k<=5;k++)
				{
					temp=a[j][k];
					a[j][k]=a[j+1][k];
					a[j+1][k]=temp;
				}
			}		
		}
	}
	printf("P\tat\tbt\tcmpt\ttat\twt\n");
	for(i=0;i<n;i++) //printing
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
	}
	printf("awt:%f | atat:%f\n",awt,atat);
} 
