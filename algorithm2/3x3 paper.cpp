#include<cstdio>
#include<deque>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	if(((n/3)%3!=0&&n!=3)||n>2187){
		return 404;
	}
	deque<int> paper(n*n);
	//00 01 02 03 04 05 06 07 08
	//09 10 11 12 13 14 15 16 17...
	for(int i = 0; i<n*n; i++){
		int uwu;
		scanf("%d", &uwu);
		paper[i] = uwu;
	}
	int ultimateminu = 0, ultimatezero = 0, ultimateplus = 0; //-1 0 1
	int uwu = 4;
	bool safe = true;
	for(int i =0; i<n*n; i++){
		if(i==0){
			uwu = paper[i];
		}
		if(paper[i]!=uwu){
			safe=false;
			break;
		}
	}
	if(safe==true){
		if(uwu==-1){
			ultimateminu++;
		}
		else if(uwu==0){
			ultimatezero++;
		}
		else if(uwu==1){
			ultimateplus++;
		}
		else{
			return 0;
		}
	}
	else{
		int pos_x = 0, pos_y = 0;
		for(int i = 0; i<n*n/9; i++){
			int possibles = 4;
			bool yessir = true;
			for(int j = 0; j<9; j++){
				if(j==0){
					possibles = paper[j%3+pos_x+pos_y*n+(j/3)*n];
				}
				if(paper[j%3+pos_x+pos_y*n+(j/3)*n]!=possibles){
					yessir =false;
					break;
				}
			}
			if(yessir==true){
				//printf("true");
				if(possibles==-1){
					ultimateminu++;
				}
				else if(possibles==0){
					ultimatezero++;
				}
				else if(possibles==1){
					ultimateplus++;
				}
				else{
					return 0;
				}
			}
			else{
				// 1 1 1 0 0 0 1 1 1
				//printf("false");
				for(int j = 0; j<9; j++){
					possibles = paper[j%3+pos_x+pos_y*n+(j/3)*n];
					if(possibles==-1){
						ultimateminu++;
					}
					else if(possibles==0){
						ultimatezero++;
					}
					else if(possibles==1){
						ultimateplus++;
					}
					else{
						return 0;
					}
				}
			}
			if(pos_x+3>=n){
				if(pos_y+3>=n){
					break;
				}
				pos_x=0;
				pos_y+=3;
			}
			else{
				pos_x+=3;
			}
			
		}
	}
	printf("%d\n%d\n%d", ultimateminu, ultimatezero, ultimateplus);
	// 81 9
	// 81->9->1
	return 0;
}
