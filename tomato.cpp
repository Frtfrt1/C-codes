#include<iostream>
#include<queue>
using namespace std;

int tomato[101][101][101];
int m, n, h;
//M -> N ^ H box value
queue<int>riping_m;
queue<int>riping_n;
queue<int>riping_h;
int ripevalue;
int unriped;
int ripe(int step){
	int grown=0;
	//printf("case : %d (step)\n", step);
	//printf("unriped : %d, ripevalue : %d\n", unriped, ripevalue);
	
	for(int i =0; i<ripevalue; i++){
		//printf("%d\n", tomato[riping_m.front()][riping_n.front()][riping_h.front()]);
		if(tomato[riping_m.front()][riping_n.front()][riping_h.front()] == step){
			//printf("a");
			//above
			if(tomato[riping_m.front()][riping_n.front()][riping_h.front()+1] == 0&&h-1>=riping_h.front()+1){
				//printf("above\n");
				unriped--;
				tomato[riping_m.front()][riping_n.front()][riping_h.front()+1] = step+1;
				//pushing
				riping_m.push(riping_m.front());
				riping_n.push(riping_n.front());
				riping_h.push(riping_h.front()+1);
				grown++;
			}
			//under
			if(tomato[riping_m.front()][riping_n.front()][riping_h.front()-1] == 0&&0<=riping_h.front()-1){
				//printf("under\n");
				unriped--;
				tomato[riping_m.front()][riping_n.front()][riping_h.front()-1] = step+1;
				//pushing
				riping_m.push(riping_m.front());
				riping_n.push(riping_n.front());
				riping_h.push(riping_h.front()-1);
				grown++;
			}
			//left
			if(tomato[riping_m.front()][riping_n.front()+1][riping_h.front()] == 0 && n-1>=riping_n.front()+1){
				//printf("left\n");
				unriped--;
				tomato[riping_m.front()][riping_n.front()+1][riping_h.front()] = step+1;
				//pushing
				riping_m.push(riping_m.front());
				riping_n.push(riping_n.front()+1);
				riping_h.push(riping_h.front());
				grown++;
			}
			//right
			if(tomato[riping_m.front()][riping_n.front()-1][riping_h.front()] == 0&&0<=riping_n.front()-1){
				//printf("right\n");
				unriped--;
				tomato[riping_m.front()][riping_n.front()-1][riping_h.front()] = step+1;
				//pushing
				riping_m.push(riping_m.front());
				riping_n.push(riping_n.front()-1);
				riping_h.push(riping_h.front());
				grown++;
			}
			//front
			if(tomato[riping_m.front()+1][riping_n.front()][riping_h.front()] == 0&&m-1>=riping_m.front()+1){
				//printf("front\n");
				unriped--;
				tomato[riping_m.front()+1][riping_n.front()][riping_h.front()] = step+1;
				//pushing
				riping_m.push(riping_m.front()+1);
				riping_n.push(riping_n.front());
				riping_h.push(riping_h.front());
				grown++;
			}
			//behind
			if(tomato[riping_m.front()-1][riping_n.front()][riping_h.front()] == 0&&0<=riping_m.front()-1){
				//printf("behind\n");
				unriped--;
				tomato[riping_m.front()-1][riping_n.front()][riping_h.front()] = step+1;
				//pushing
				riping_m.push(riping_m.front()-1);
				riping_n.push(riping_n.front());
				riping_h.push(riping_h.front());
				grown++;
			}
			//popping
			riping_h.pop();
			riping_n.pop();
			riping_m.pop();
		}
	}
	//printf("grown = %d\n", grown);
	ripevalue=grown;
	if(ripevalue==0&&unriped==0){
		printf("%d",step-1);
		return 0;
	}
	if(ripevalue==0&&unriped>0){
		printf("-1");
		return 0;
	}
	ripe(step+1);
	
}
int main(void){
	scanf("%d %d %d", &m, &n, &h);
	//i==h, j==n, k==m
	for(int i = 0; i<h; i++){
		for(int j = 0; j<n; j++){
			for(int k = 0; k<m; k++){
				scanf("%d", &tomato[k][j][i]);
				if(tomato[k][j][i]==1){
					riping_m.push(k);
					riping_n.push(j);
					riping_h.push(i);
					//printf("%d %d %d", riping_m.front(), riping_n.front(), riping_h.front());
					ripevalue++;
				}
				else if(tomato[k][j][i]==0){
					unriped++;
				}
			}
		}
	}/*
	for(int i = 0; i<h; i++){
		for(int j = 0; j<n; j++){
			for(int k = 0; k<m; k++){
				printf("%d ", tomato[m]);
				}
			}
			printf("\n");
		}
		
	}*/
	//1 == ripe, 0 == unripe, -1 == blank
	ripe(1);
	return 0;
} 
