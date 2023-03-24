#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;

/*Note here*/
int nods[1001] = {0, };
int pathway[1001][1001];
int pathwaynum[1001] = {0, };
int main(void){
	int n, m, v;
	// n for pathway num / m for nod num / v for searching point(begining)
	scanf("%d %d %d", &n, &m, &v);
	pathway[0][0] = 1;
	//[root][lead]. -1 or 0 means end
	for(int i= 0; i<m; i++){
		int root = 0, lead = 0;
		scanf("%d %d", &root, &lead);
		pathway[root][pathwaynum[root]] = lead;
		//printf("%d", pathway[root][pathwaynum[root]]);
		pathwaynum[root]++;
		//printf("A");
	}
	stack<int> s;//DFS
	queue<int> q;//BFS
	//DFS time
	s.push(v);
	/*printf("%d", s.empty());
	printf("%d", s.top());*/
	int k = v;
	int eliminated[1001];
	eliminated[v] = 7;
	printf("%d ", v);
	while(s.empty()==0){
		k = s.top();
		int shortest = 9999;
		for(int i=0; i<pathwaynum[k]; i++){
			if(shortest >pathway[k][i]&&eliminated[pathway[k][i]]!=7){
				shortest = pathway[k][i];
			}
		}
		if(shortest==9999){
			s.pop();
		}
		else if(shortest!=9999){
			s.push(shortest);
			eliminated[shortest] = 7;
			printf("%d ", shortest);
		}
	}
	printf("\n");
	//BFS time
	q.push(v);
	/*printf("%d", s.empty());
	printf("%d", s.top());*/
	int eliminate[1001] ={0,};
	eliminate[v] = 7;
	printf("%d ", v);
	while(q.empty()==0){
		int k = q.front();
		int waiting[1001] = {0, };
		int i = 0;
		int plus = 0;
		while(pathway[k][i]!=0){
			if(eliminate[pathway[k][i]] != 7){
				waiting[i] = pathway[k][i];
			}
			plus++;
			i++;
		}
		if(plus==0){
			q.pop();
		}
		else{
			sort(waiting, waiting+plus);
			for(int i = 0; i<plus; i++){
				q.push(waiting[i]);
				printf("%d ", waiting[i]);
			}
			break;
		}
	}
	
	
}
