#include<iostream>
#include<algorithm>
using namespace std;

int typenum, required,types[11];
int steps = 0;
int minu(void){
	for(int i=0; i<typenum; i++){
		if((required-types[typenum-i-1])>=0){
			required = required - types[typenum-1-i];
			break;
		}
	}
	steps++;
	if(required==0){
		printf("%d", steps);
		return 0;
	}
	else{
		minu();
	}
}
int main(void){
	scanf("%d %d", &typenum, &required);
	for(int i =0; i<typenum; i++){
		scanf("%d", &types[i]);
	}
	sort(types, types+typenum);
	//printf("%d", types[typenum-1]);
	minu();
	return 0;
}
