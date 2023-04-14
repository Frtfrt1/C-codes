#include<cstdio>
#include<queue>
using namespace std;
int main(void){
	int costs[100001], dis[100001], befores[100001], cityco;
	scanf("%d", &cityco);
	int before = 0, snowball = 0;
	queue<int> money;
	for(int i = 0; i<cityco-1; i++){
		scanf("%d", &dis[i]);
	}
	for(int i = 0; i<cityco; i++){
		scanf("%d", &costs[i]);
		if(i==0||costs[befores[before-1]]>costs[i]){
			//printf("\n%d\n", costs[i]);
			befores[before] = i;
			before++;
			if(i!=0){
				money.push(snowball);
				//printf("\ns : %d\n", snowball);
				snowball = 0;
			}
		}
		snowball+=dis[i];
	}
	money.push(snowball);
	int cc=0;/*
	for(int i = 0; i<before; i++){
		printf("\n%d ", befores[i]);
	}*/
	
	for(int i = 0; i<before; i++){
		cc+=costs[befores[i]]*money.front();
		money.pop();
	}
	printf("%d", cc);
	return 0;
	
}
