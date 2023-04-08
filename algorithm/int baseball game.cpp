
#include<cstdio>
#include<iostream>

int questioning;
int a[100][3], b[100], c[100], arrad[100];
//a = answers, b = strikes , c = balls
//int chances[9][3];
int chance=0;
int main(void){
	scanf("%d", &questioning);
	for(int i = 0; i<questioning; i++){
		int d=0;
		scanf("%d %d %d", &d, &b[i], &c[i]);
		a[i][0] = d/100;
		a[i][1] = d/10%10;
		a[i][2] = d%10;
		//arrad[i] = b[i]+c[i];
	}
	int i = 111;
	while(i++){
		int q = i/100;
		int w = i/10%10;
		int e = i%10;
		if(i==999){
			break;
		}
		if(q!=w&&q!=e&&w!=e&&q!=0&&w!=0&&e!=0){
			int limited =0;
			for(int j = 0; j<questioning; j++){
				int balls = c[j];
				int strikes = b[j];
				int neball = 0, nestrike = 0;
				for(int k =0; k<3; k++){
					int ap = 0;
					if(k==0){ap = q;}
					if(k==1){ap = w;}
					if(k==2){ap = e;}
					for(int u =0;u<3; u++){
						if(ap==a[j][u]){
							if(u==k){
								nestrike++;
							}
							else if(u!=k){
								neball++;
							}
						}
					}
				}
				if(balls!=neball||strikes!=nestrike){
					limited=1;
				}
			}
			if(limited!=1){
				chance++;
				//printf("%d", i);
			}
		}
	}
	printf("%d", chance);
	return 9;
}
