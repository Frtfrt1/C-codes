#include<iostream>
#include<string>
using namespace std;
int main(void){
	long long t;
	bool x[21] = {0, };
	scanf("%lld", &t);
	for(int i = 0; i<t; i++){
		string command;
		int rigx;
		cin >> command;
		if(command!="all"&&command!="empty"){
			scanf("%d", &rigx);
		}
		if(command=="add"){
			x[rigx] = 1;
		}
		else if(command=="remove"){
			x[rigx] = 0;
		}
		else if(command=="check"){
			printf("%d\n", x[rigx]);
		}
		else if(command=="toggle"){
			if(x[rigx]==1){
				x[rigx]=0;
			}
			else{
				x[rigx]=1;
			}
		}
		else if(command=="all"){
			for(int i =0; i<21; i++){
				x[i] = 1;
			}
		}
		else if(command=="empty"){
			for(int i =0; i<21; i++){
				x[i] = 0;
			}
		}
		else{
			printf("error\n");
		}
	}
	return 0;
}

//---------------------------------------------------------------------------------------
//password
/*#include<iostream>
#include<cmath>
int main(void){
	long long a;
	scanf("%d", &a);
	if(a<1||a>std::pow(10, 18)){
		return 0;
	}
	long long x = 0;
	long long clone_a = a;
	while(1){
		if(clone_a==0){
			break;
		}
		x+=clone_a%2;
		clone_a=clone_a/2;
	}
	int lowerx = a, higherx = a;	
	while(1){
		lowerx--;
		if(lowerx<0){
			lowerx = 0;
			break;
		}
		long long clone_lowerx = lowerx;
		long long cc = 0;
		while(1){
			if(clone_lowerx==0){
				break;
			}
			cc+=clone_lowerx%2;
			clone_lowerx=clone_lowerx/2;
		}
		if(cc==x){
			break;
		}
	}
	while(1){
		higherx++;
		long long clone_higherx = higherx;
		long long cc = 0;
		while(1){
			if(clone_higherx==0){
				break;
			}
			cc+=clone_higherx%2;
			clone_higherx=clone_higherx/2;
		}
		if(cc==x){
			break;
		}
	}
	printf("%lld %lld", lowerx, higherx);
	return 0;
}*/

//----------------------------------------------------------------------------
//gem
/*#include<iostream>
#include<queue>
int main(void){
	int n, m, t, k;
	scanf("%d %d %d %d", &n, &m, &t, &k);
	std::queue<int> gold_x;
	std::queue<int> gold_y;
	int topx=0, topy=0, lowx=10000000, lowy=10000000;
	for(int i = 0; i<t; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x>topx){
			topx = x;
		}
		if(x<lowx){
			lowx = x;
		}
		if(y>topy){
			topy = y;
		}
		if(y<lowy){
			lowy = y;
		}
		gold_x.push(x);
		gold_y.push(y);
	}
	int bestgrind = 0, locationx = lowx, locationy = lowy;
	int bestx = 0, besty = 0;
	while(1){
		int grind = 0;
		for(int i = 0; i<t; i++){
			if(gold_x.front()<=locationx+k&&gold_y.front()<=locationy+k&&gold_x.front()>=locationx&&gold_y.front()>=locationy){
				grind++;
			}
			int x3 = gold_x.front();
			int y3 = gold_x.front();
			gold_x.pop();
			gold_y.pop();
			gold_x.push(x3);
			gold_y.push(y3);
		}
		if(grind>bestgrind){
			bestgrind = grind;
			bestx = locationx;
			besty = locationy+k;
		}       
		locationx++;
		if(locationx+k>topx){
			if(locationy+k>=topy){
				break;
			}
			locationx = lowx;
			locationy++;
		}
		                                              
	}
	printf("%d %d\n", bestx, besty);
	printf("%d", bestgrind);
	return 0;
}*/

//----------------------------------------------------------------------
//zodiac
/*#include<iostream>

int main(void){
	int n;
	scanf("%d", &n);
	if(n<1||n>1000001){
		return 0;
	}
	n+=56;
	int num= n % 10;
	char alp = n % 12 + 65;
	printf("%c%d", alp, num);
	return 0;
}*/
