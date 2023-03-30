#include<cstdio>
using namespace std;

int rootyes = 1;
int rootco = 0;
int roots[1001];
int turn(int yes, int k){
	rootco--;
	for(int i = 0; i<1001; i++){
		if(roots[i] == yes){
			roots[i] = k;
		}
	}
}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<m; i++){
		int u,v;
		scanf("%d %d", &u, &v);
		if(rootco==0){
			roots[u] = 1;
			roots[v] = 1;
			rootco++;
		}
		else if(rootco!=0){
			int inp = 0;
			if(roots[u]==0&&roots[v]==0){
				
				//printf("\nyes\n");
				roots[u] = rootyes+1;
				roots[v] = rootyes+1;
				rootco++;
				rootyes++;
			}
			else if(roots[u]!=0 || roots[v]!=0){
				//printf("\nno\n");
				int no = 0;
				if(roots[u]!=0){
					inp=roots[u];
				}
				if(roots[v]!=0){
					if(roots[v] < inp){
						inp=roots[v];
						no = roots[u];
					}
					else{
						no = roots[v];
					}
				}
				if(no==0&&inp>0){
					if(roots[u] == 0){
						roots[u] = inp;
					}
					else if(roots[v] == 0){
						roots[v] = inp;
					}
				}
				if(no==inp){
					int thisisaveryamazingvaluewhichnooneuse = 0;
				}
				else if(roots[u]!=0&&roots[v]!=0&&no>0){
					turn(no, inp);
				}
			}
		}
		
		//printf("\n\n%d %d %d %d\n", roots[u], roots[v], rootco, rootyes);
	}
	printf("%d", rootco);
	return 0;
}
