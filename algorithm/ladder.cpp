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
		/* definations */
		int lines, trs;
		scanf("%d %d", &lines, &trs);
		move[i] = trs;
		if(move[i]==1){
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
	}/*
	for(int i = 0; i<floor; i++){
		for(int j = 0; j<leng; j++){
			printf("%d ", doors[i*leng+j]);
		}
		printf("\n");
	}*/
	int time = 0, location = 0;
	int n = 0;
	// human going up
	while(1){
		if(n>END_L){
			break;
		}
		if(location==floor-1){
			//printf("%d", time);
			return 0;
		}
		if(doors[leng*location+n]==true&&doors[(leng)*(location+1)+n]==true){
			location++;
			n = (-1);
		}
		else if(n!=0){
			if(doors[leng*location+n-1]==true&&doors[(leng)*(location+1)+n]==true&&n!=0){
				location++;
				n = (-1);
			}
			else if(doors[leng*location+n]==true&&doors[(leng)*(location+1)+n-1]==true&&n!=0){
				location++;
				n = (-1);
			}
		} 
		
		n++;
	}
	while(1){
		
		//printf("loc %d\n", location);
		//ladder movement
		for(int i = 0; i<floor; i++){
			if(move[i]==1&&lco[i]-msg[i]<0){
				move[i]=0;
			}
			else if(move[i]==0&&lco[i]>=END_L){
				move[i]=1;
			}
			if(move[i]==0){
				if(lco[i]>=END_L){
					move[i] = 1;
				}
				else{
					doors[i*leng+lco[i]+1] = 1;
					doors[i*leng+lco[i]-msg[i]+1] = 0;
					lco[i]++;/*
					printf("upp %d\n", lco[i]);
					printf("time : %d \n", time);
					for(int p = 0; p<floor; p++){
						for(int j = 0; j<leng; j++){
							printf("%d ", doors[p*leng+j]);
						}
						printf("\n");
					}
					printf("\n");*/
				}
			}
			if(move[i]==1){
				doors[i*leng+lco[i]-msg[i]] = true;
				doors[i*leng+lco[i]] = false;
				lco[i]--;
				//printf("d %d\n", lco[i]);
				//printf("time : %d \n", time);
				/*for(int p = 0; p<floor; p++){
					for(int j = 0; j<leng; j++){
						printf("%d ", doors[p*leng+j]);
						}
					printf("\n");
					}
				printf("\n"); */
			}
		}
		
		//printf("hehe end time : %d \n", time);
		/* <testing prints> *//*
		for(int p = 0; p<floor; p++){
			for(int j = 0; j<leng; j++){
				printf("%d ", doors[p*leng+j]);
			}
			printf("\n");
		}
		printf("\n");*//* </testing prints> */
		time++;
		int n = 0;
		// human going up
		while(1){
			if(n>END_L){
				break;
			}
			if(location==floor-1){
				printf("%d", time);
				return 0;
			}
			if(doors[leng*location+n]==true&&doors[(leng)*(location+1)+n]==true){
				location++;
				n = (-1);
			}
			else if(n!=0){
				if(doors[leng*location+n-1]==true&&doors[(leng)*(location+1)+n]==true&&n!=0){
					location++;
					n = (-1);
				}
				else if(doors[leng*location+n]==true&&doors[(leng)*(location+1)+n-1]==true&&n!=0){
					location++;
					n = (-1);
				}
			} 
			n++;
		}
	}
	return 1;
}
