#include<cstdio>
#include<iostream>
#inclue<cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(void){
	int n;
	scanf("%d", &n);
	int ballsc[201];
	int ballss[201];
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ballsc[i], &ballss[i]);
	}
	for(int i = 0; i < n; i++){
		int score = 0;
		for(int j = 0; j < n; j++){
			if(i == j){
				// oh boy
			}
			else if(ballsc[i] != ballsc[j]){
				if(ballss[i] > ballss[j]){
					score += ballss[j];
				}
			}
		}
		printf("%d\n", score);
	}
	return 123;
}
