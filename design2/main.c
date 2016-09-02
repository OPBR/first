#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//const int MAX = 50000;
#define MAX 50000
int fathers[MAX];
int relation[MAX];

void SetInit(int x)
{
	fathers[x] = x;
	relation[x] = 0;
}

int FindSet(int x)
{
	int t;
	if (x != fathers[x]){
		t = fathers[x];
		fathers[x] = FindSet(fathers[x]);
		relation[x] = (relation[x] + relation[t]) % 3;
	}

	return fathers[x];
}

void Union(int x,int y,int d)
{
	int xf = FindSet(x);
	int yf = FindSet(y);

	fathers[xf] = yf;
	relation[xf] = (relation[y] - relation[x] +3 +d) % 3;
}

void Cycle(int *total,int d,int x,int y,int n)
{
	int xf,yf;
#if 0
	if (d < 1 || d > 2){
		(*totla)++;
	}
#endif

	if (x > n || y > n || d < 1 || d > 2 ||(
				d == 2 && x == y)){
		(*total)++;
	}
	else{
		xf = FindSet(x);
		yf = FindSet(y);

		if (xf == yf){
			if (1 == d && relation[x] != relation[y]){
				(*total)++;
			}
			if (2 == d){
				if (relation[x] == relation[y] || relation[x] == (relation[y] + 1) % 3){
					(*total)++;
				}
			}
		}
		else{
			Union(x,y,d-1);
		}
	}
}

void mainCP()
{
	int total = 0;
	int i,n,k,x,y,d;
	char a = 'y';
	printf("Please enter the number of total biological and conclusion(n k)\n");
	scanf("%d %d",&n,&k);
	for (i = 1; i <= n; i++){
		SetInit(i);
	}
	printf("Pleace enter the conclusion(1 2 3)\n");
	srand((unsigned)time(NULL));
	while(k--){
		d = rand()%2 + 1;
		x = rand()%n + 1;
		y = rand()%n + 1;
		printf("%d %d %d\n",d,x,y);
		Cycle(&total,d,x,y,n);

	}
	printf("At least %d lies\n",total);
	printf("If you want to add a few conclusions,Please enter \"y\"\n");
	setbuf(stdin,NULL);
	scanf("%c",&a);
	if ('y' == a){
		printf("Please enter the conclusion of quanity(n):");
		scanf("%d",&k);
		while(k--){
			scanf("%d %d %d",&d,&x,&y);
			Cycle(&total,d,x,y,n);
		}
	}

	printf("At least %d lies\n",total);

}

int main()
{
	mainCP();
	return 0;
}
