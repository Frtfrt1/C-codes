#include<cstdio>

int main(void){
	int num[3][8];
	for(int j = 0; j<3; j++){
		
		char sdf;
		for(int i =0; i<8; i++){
			
			scanf("%c", &sdf);
			num[j][i] = int(sdf)-48;
			if(num[j][i]<0){
				return 0;
			}
			//printf("%c ", sdf);
			//printf("%d ", num[j][i]);
		}
		
		scanf("%c", &sdf);
		if(int(sdf)>47){
			return 0;
		}
	}
	for(int i = 0; i<3; i++){
		int continuous = 0, nums = 0, bestcon = 0;
		for(int j = 0; j<8; j++){
			if(j==0){
				nums = num[i][j];
			}
			if(nums==num[i][j]){
				continuous++;
			}
			else{
				if(bestcon < continuous){
					bestcon = continuous;
				}
				continuous = 1;
				nums = num[i][j];
			}
			//printf("%d best : %d con : %d\n", i, bestcon, continuous);
		}
		printf("%d\n", bestcon);
	}
	return 0;
}
