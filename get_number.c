#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*입력받은 값과 빙고테이블의 값이 일치할 경우 해당 테이블의 값을 -1로 바꿈*/

void process_bingo(int N, int Table[][N], int num){
	
	int i, j;
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(Table[i][j] == num)
					Table[i][j] = -1;
			}
		}

}

int get_number_byMe(int N, int a, int CheckNum[N*N]){
	
	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			printf("숫자(1~%d)를 입력하시오 : ", max);
			scanf("%d", &num);
			if(num <1 || num > max){
				Error = 1; //Error가 1이면 다시 입력
				printf("Error!"); 
			}
		/*Error가 1이 나왔을 때 그 값이 이미 입력된 정수이면 다시 Error값을 1로 바꿈*/
		if(Error == 0){
			
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
					printf("Error!"); 
				}
			}	
		}
		
	}while(Error == 1);  //Error가 1이면 다시 입력받음(do 재실행)
	
	printf("사용자가 입력한 숫자 : %d\n", num);
	
 return num; // num값을 return. 
}

int get_number_byCom(int N, int a, int CheckNum[N*N]){

	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			num = rand()%max+1; // 1~max까지의 값을 랜덤으로 받음. 
			if(num <1 || num > N*N){
				Error = 1; //Error가 1이면 다시 입력
			}
			
		if(Error == 0){
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
				}
			}	
		}
	}while(Error == 1);  //Error가 1이면 다시 입력받음(do 재실행) 
	
	printf("컴퓨터가 입력한 숫자 : %d\n\n", num);
	
 return num; // num값을 return. 
	
}
