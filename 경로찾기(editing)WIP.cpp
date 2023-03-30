#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

char element[1001][31];
queue<int>re;
queue<int>onlycoolpeoplecanusethisqueue;
int ways[10000][1001];
int results[1001], n, k, s, e;

bool comp(int v1, int v2){
	int count = 0;
	for(int i = 0; i<k; i++){
		if(element[v1][i]!=element[v2][i]){
			count++;
		}
	}
	if(count==1){
		return true;
	}
	else{
		return false;
	}
}
int eliminated[10000][1001];
int haming(int steps, int loca, int waynum){
	if(results[waynum]>0){
		return 0;
	}
	if(comp(loca,e)==true){
		re.push(steps);
		return 0;
	}
	for(int i =0; i<k-1; i++){
		if(eliminated[waynum][i]!=1){
			if(comp(loca, i)==true){
				eliminated[waynum][loca]=1;
				onlycoolpeoplecanusethisqueue.push(loca);
				haming(steps+1, i, waynum);
			}
		}
	}
	
}
int main(void){
	scanf("%d %d", &n, &k);
	for(int i =0; i<n; i++){
		char a;
		scanf("%c", &a);
		for(int j =0; j<k; j++){
			scanf("%c", &element[i][j]);
		}
	}
	scanf("%d %d", &s, &e);
	haming(0, s-1, 0);
	//printf("%d ", onlycoolpeoplecanusethisqueue.front());
	while(onlycoolpeoplecanusethisqueue.empty()!=0){
		printf("%d ", onlycoolpeoplecanusethisqueue.front());
		onlycoolpeoplecanusethisqueue.pop();
	}
	return 23;
}
