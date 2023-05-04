#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int discuss_start[100001], discuss_end[100001], discussion[100001];
int steps = 0, discussions;
stack<int> via1;
queue<int> ender;
int nogada(int start, int elemen, int usable, int num){
	via1.push(elemen);
//	printf("%d ", elemen);
	int finder = discuss_end[elemen];
	int found=0;
	for(int i =0; i<discussions; i++){
		if(finder<=discuss_start[i]&&i!=elemen){
			nogada(start, i, usable+1, num+1);
			found=1;
		}
	}
	if(found==0){
		ender.push(usable);
		via1.pop();
		//printf("pushed : %d start : %d, element : %d\n", usable, start, elemen);
		return 0;
	}
}
int main(void){
	scanf("%d", &discussions);
	for(int i = 0; i < discussions; i++){
		scanf("%d %d", &discuss_start[i], &discuss_end[i]);
		discussion[i] = discuss_end[i]-discuss_start[i];
	}
	for(int i =0; i<discussions; i++){
		nogada(i, i, 1, 0);
	}
	while(ender.empty()==0){
		if(steps<ender.front()){
			steps = ender.front();
		}
		ender.pop();
	}
	printf("%d", steps);
	return 0;
}
