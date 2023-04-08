#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int t,cycle;
int test[1001][1001];
int inputs[1001], eliminated[1001];
bool returned=false;
int psi(int num, int limit, int one){
	if(returned==true&&num==one){
		//printf("returned : %d %d %d\n", num, limit, one);
		return 0;
	}
	else if(eliminated[num]==1){
		return 0;
	}
	else{
		if(num==one&&returned==false){
			//printf("%d %d %d\n", num, limit, one);
			cycle++;
			returned=true;
		}
		
		eliminated[num]=1;
		psi(test[limit][num]-1, limit, one);
	}
}
int main(void){
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &inputs[i]);
		for(int j=0; j<inputs[i]; j++){
			scanf("%d", &test[i][j]);
		}
	}
	//printf("hey");
	for(int i = 0; i<t; i++){
		for(int j=0; j<inputs[i]; j++){
			returned=false;
			psi(j, i, j);
		}
		printf("%d\n", cycle);
		cycle=0;
		for(int j=0; j<inputs[i]; j++){
			eliminated[j]=0;
		}
		//printf("yo");
	}
	return 0;
}
