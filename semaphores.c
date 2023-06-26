#include <stdio.h>

int m=1, f=0, e=3;

int wait(int s){
	if(s!=0)
		s--;
	return s;
}

int signal(int s){
	s++;
	return s;
}

void producer(){
	m=wait(m);
	e=wait(e);
	f=signal(f);
	printf("Producer produces item \n");
	m=signal(m);
}

void consumer(){
	m=wait(m);
	f=wait(f);
	e=signal(e);
	printf("Consumer consumes item \n");
	m=signal(m);
}

void main(){
	int opt=0; 
	do{
		printf("\n---Choose the option---\n1.Produce Item\n2.Consume Item\n3.Exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				if(m==1 && e!=0)
					producer();
				else
					printf("Producer is waiting\n");
				break;
			case 2:if(m==1&&f!=0)
					consumer();
				else
					printf("Consumer is waiting\n");
				break;
		}
	}while(opt!=3);
}
