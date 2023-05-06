#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	int change_f[11], change_s[11];
	int cards[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	for(register int i = 0; i < 10; i++){
		scanf("%d %d", &change_f[i], &change_s[i]);
	}
	for(register int i =0; i<10; i++){
		reverse(cards+change_f[i]-1, cards+change_s[i]);
	}
	//printf("\n");
	for(register int i =0; i<20; i++){
		printf("%d ", cards[i]);
	}
	return 0;
}
