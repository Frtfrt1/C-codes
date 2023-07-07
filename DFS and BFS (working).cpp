#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool e[1001] = {false, }, e2[1001] = {false, };
int node[1001][10001];
int cc[1001] = {0,};
int dfs(int v, int location){
	cout<<location<<" ";
	int kc[10001];
	for(int i = 0; i<cc[location]; i++){
		kc[i] = node[location][i];
	}
	sort(kc, kc+cc[location]);
	e[location] = true;
	for(int i = 0; i<cc[location]; i++){
		if(e[kc[i]]!=true){
			dfs(v, kc[i]);
		}
	}
	return 0;
}
int main(void){
	int n, m, v, a, b;
	queue<int> q;
	cin>>n>>m>>v;
	for(int i = 0; i<m; i++){
		cin>>a>>b;
		node[a][cc[a]] = b;
		cc[a]++;
		node[b][cc[b]] = a;
		cc[b]++;
	}
	e[v] = true;
	dfs(v, v);
	cout<<"\n";
	q.push(v);
	while(1){
		int uwu[1001];
		int x = 0;
		while(1){
			if(q.empty()!=0){
				break;
			}
			cout<<q.front()<<" ";
			int kc[10001];
			for(int i = 0; i<cc[q.front()]; i++){
				kc[i] = node[q.front()][i];
			}
			sort(kc, kc+cc[q.front()]);
			e2[q.front()] = true;
			for(int i = 0; i<cc[q.front()]; i++){
				if(e2[kc[i]]!=true){
					e2[kc[i]] = true;
					uwu[x] = kc[i];
					x++;
				}
			}
			q.pop();
		}
		for(int i = 0; i<x; i++){
			q.push(uwu[i]);
		}
		if(q.empty()!=0){
			break;
		}
	}
}
