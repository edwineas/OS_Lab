#include <stdio.h>
int main(){
	int np,nf,i,j,pagefault=0;
	printf("Enter the number of pages : ");
	scanf("%d",&np);
	int r[np];
	printf("Enter the reference string : ");
	for(i=0;i<np;i++){
		scanf("%d",&r[i]);
	}
	printf("Enter the number of frames : ");
	scanf("%d",&nf);
	int f[nf],age[nf];
	for(i=0;i<nf;i++){
		f[i]=-1;
		age[i]=0;
	}
	for(i=0;i<np;i++){
		int pagefound = 0;
		for(j=0;j<nf;j++){
			if(f[j]==r[i]){
				pagefound = 1;
				age[j]=i+1;
				break;
			}
		}
		if(!pagefound){
			int lruindex = 0, minage = age[0];
			for(j=1;j<nf;j++){
				if(minage>age[j]){

					minage = age[j];
					lruindex = j;
				}
			}
			f[lruindex]=r[i];
			age[lruindex]=i+1;
			pagefault++;
		}
		for(j=0;j<nf;j++){
			if(f[j]==-1)
				printf("_ ");
			else
				printf("%d ",f[j]);
		}
		printf("\n");
	}
	int pagehit = np-pagefault;
	printf("Number of pagefault : %d\n",pagefault);
	printf("Number of pagehit : %d\n",pagehit);
	printf("pagefault ratio : %.2f%%\n",((float)pagefault*100)/np);
	printf("pagehit ratio : %.2f%%\n",((float)pagehit*100)/np);
}


