#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

//[x][y]
char vill[26][26];
int root[26][26];
int rootco = 1;
int counts[26] = {0, };
int n;

int search(int x, int y, int co){
	counts[co]++;
	root[x][y]=co;
	if(vill[x+1][y] == 49&&root[x+1][y]==0){
		//printf("[x+1][y]");
		search(x+1, y, co);
	}
	if(vill[x-1][y] == 49&&root[x-1][y]==0){
		//printf("[x-1][y]");
		search(x-1, y, co);
	}
	if(vill[x][y+1] == 49&&root[x][y+1]==0){
		//printf("[x][y+1]");
		search(x, y+1, co);
	}
	if(vill[x][y-1] == 49&&root[x][y-1]==0){
		//printf("[x][y-1]");
		search(x, y-1, co);
	}
}
int main(void){
	scanf("%d", &n);
	char a;
	scanf("%c", &a);
	for(int i = 0; i<n; i++){
		
		for(int j = 0; j<n; j++){
			scanf("%c", &vill[i][j]);
			//printf("%c", vill[i][j]);
		}
		scanf("%c", &a);
	}
	int x_u = 0;
	int y_u = 0;
	for(int i= 0; i<n*n; i++){
		x_u++;
		if(x_u>n-1){
			y_u++;
			x_u = 0;
		}
		if(vill[x_u][y_u]==49){
			//printf("a");
			if(root[x_u][y_u]==0){
				search(x_u, y_u, rootco);
				rootco++;
			}
		}
	}
	printf("%d\n", rootco-1);
	sort(counts, counts+rootco);
	for(int i=1; i<rootco; i++){
		printf("%d\n", counts[i]);
	}
	
}
