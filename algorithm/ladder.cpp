#include<iostream>
#include<deque>
using namespace std;
int main(void){
	int floor, leng;
	char trashvalue, nopes;
	scanf("%d%c%d", &floor, &trashvalue, &leng);
	if(trashvalue!=32){
		return 0;
	}
	// 0 = NOT lined, 1 = Lined
	deque<bool> doors(floor*leng);
	/*0 =>  1 <=*/
	deque<bool> move(floor);
	deque<int> lco(floor);
	deque<int> msg(floor);
	//printf("%d", doors.size());
	#define END_L leng-1
	#define START_L 0
	//last floor = first line, first floor = last line'
	for(int i =0; i<floor; i++){
		int lines, trs;
		scanf("%d %d", &lines, &trs);
		move[i] = trs;
		if(move[i]==0){
			lco[i] = END_L;
		}
		else{
			lco[i] = lines-1;
		}
		msg[i] = lines;
		if(move[i]==1){
			for(int uwu = END_L; uwu>END_L-lines; uwu--){
				doors[i*leng+uwu] = 1;
				//printf("%d", doors[i*leng+uwu]);
			}
		}
		else{
			for(int uwu = 0; uwu < lines; uwu++){
				doors[i*leng+uwu]= 1;
			}
		}
	}
	for(int i = 0; i<floor; i++){
		for(int j = 0; j<leng; j++){
			printf("%d ", doors[i*leng+j]);
		}
		printf("\n");
	}
	int time = 0, location = 0;
	while(1){
		int n = 0;
		while(1){
			if(location==floor-1){
				printf("%d", time);
				return 0;
			}
			if(doors[leng*location+n]==1&&doors[(leng)*(location+1)+n]==1){
				location++;
				n = 0;
			}
			else if(n>END_L){
				break;
			}
			n++;
		}
		for(int i = 0; i<floor; i++){
			if(move[i]==0||(move[i]==1&&lco[i]-msg[i]<=0)){
				if(lco[i]>=END_L){
					move[i] = 1;
				}
				else{
					doors[i*leng+lco[i]+1] = 1;
					doors[i*leng+lco[i]-msg[i]+1] = 0;
					lco[i]++;
					printf("time : %d \n", time);
					for(int p = 0; p<floor; p++){
						for(int j = 0; j<leng; j++){
							printf("%d ", doors[p*leng+j]);
						}
						printf("\n");
					}
					printf("\n");
				}
			}
			if(move[i]==1){
				if(lco[i]-msg[i]<=1){
					move[i] = 0;
				}
				else{
					doors[i*leng+lco[i]] = 0;
					doors[i*leng+lco[i]-msg[i]] = 1;
					lco[i]--;
					printf("time : %d \n", time);
					for(int p = 0; p<floor; p++){
						for(int j = 0; j<leng; j++){
							printf("%d ", doors[p*leng+j]);
						}
						printf("\n");
					}
					printf("\n"); 
				}
			}
		}
		printf("time : %d \n", time);
		for(int p = 0; p<floor; p++){
			for(int j = 0; j<leng; j++){
				printf("%d ", doors[p*leng+j]);
			}
			printf("\n");
		}
		printf("\n");
		time++;
	}
	return 0;
}
