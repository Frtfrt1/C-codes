#include<cstdio>
int main(void){
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	int c = (v-b)/(a-b);
	if((v-b)%(a-b)>0){c++;}
	printf("%d", c);
}
