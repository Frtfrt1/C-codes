#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
/*
bool prime(int n){
	if (n < 2) {
		return false;
	}
	for (int i = 2; i*i<=n; i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}*/
int main(void) {
	int p[100];
	int pn=0;
	bool c[101];
	int eliminated = 0;
	int n = 100;
	for(int i = 2; i<=n; i++){
		if (c[i] == false) {
			p[pn++] = i;
			eliminated++;
			for (int j = i*i; j<=n; j+=i){
				c[j] = true;
				
			}
		}
	}
	for(int i = 0; i<25; i++){
		printf("%d, ", p[i]);
	}
	return 0;
}
