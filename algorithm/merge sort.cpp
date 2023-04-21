#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//ns = origin/changing, clone = fake/notchanging
int n, ns[100000], clone[100000], locations[100000];
int main(void){
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &ns[i]);
		clone[i] = ns[i];
		locations[i] = i;
	}
	int steps = 1;
	while(1){
		if(steps>=n){
			break;
		}
		int intersection = 0;
		for(int i = 0; i<n; i++){
			if(intersection>=steps*2-1){
				intersection = 0;
			}
			if(intersection<steps){
				//printf("\naccepted : %d %d %d\n", intersection, steps, i);
				int loca = locations[ns[i]];
				for(int j = steps*2-1; j>0; j--){
					if(ns[loca]>ns[loca+j]&&ns[loca+j]!=0&&ns[loca]!=0){
						//printf("\nyes / loca - %d\n", loca);
						for(int uwu = 0; uwu<steps-(steps-j)-intersection; uwu++){
							int fir = ns[loca];
							int sec = ns[loca+1];
							locations[loca+1]--;
							locations[loca]++;
							//printf("%d %d\n", fir, sec);
							ns[loca+1] = fir;
							ns[loca] = sec;
							loca++;
							//printf("case : %d / %d %d\n", i, j, uwu);
							/*for(int sdf =0; sdf<n; sdf++){
								printf("%d ", ns[sdf]);
							}
							printf("\n");
							for(int sdf =0; sdf<n; sdf++){
								printf("%d ", locations[sdf]);
							}
							printf("\n");*/
						}
						break;
					}
				}
			}
			intersection++;
		}
		steps *= 2;
	}
	for(int i =0; i<n; i++){
		printf("%d\n", ns[i]);
	}
}
