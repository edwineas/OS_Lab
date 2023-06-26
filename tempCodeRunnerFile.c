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
