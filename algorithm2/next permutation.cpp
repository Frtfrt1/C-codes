#include<iostream>
#include<algorithm>
int main(void){
	int n, num[10001];
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &num[i]);
	}
	bool absent = false;
	if(num[n-2]<num[n-1]){
		int a = num[n-1];
		num[n-1] = num[n-2];
		num[n-2] = a;
	}
	else{
		absent = true;
		// 1 2 4 3
		// 1 3 4 2
		// 1 3 2 4
		// 4 3 2 1
		for(int i = n-2; i>0; i--){
			if(num[i]>num[i-1]){
				for(int j = n-1; j>i-1; j--){
					if(num[j]>num[i-1]){
						int a = num[i-1];
						num[i-1] = num[j];
						num[j] = a;
						break;
					}
				}
//				for(int a = 0; a<n; a++){
//					printf("%d ", num[a]);
//				}
//				printf("\n//\n");
				std::sort(num+i, num+n);
				absent=false;
				break;
			}
		}
	}
	if(absent==1){
		printf("-1");
		return 0;
	}
	for(int i = 0; i<n; i++){
		printf("%d ", num[i]);
	}
	return 0;
}
