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

/*get_number_byCom & get_number_byMe : do-while문 이용.
Error 값이 1일 경우 do 반복실행, Error 값이 0일 경우 반복문을 나오고 입력받은 num 값을 return함
(Error 값이 1일 경우 : 입력 받은 숫자가 범위 밖의 숫자일 경우& 입력받은 숫자가 이전에 이미 입력받았던 숫자일 경우*/
int get_number_byMe(int N, int CheckNum[N*N]){
	
	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			printf("숫자(1~%d)를 입력하시오 : ", max);
			scanf("%d", &num);
			/*Case1. 입력값이 범위 밖의 숫자일 경우 Error 발생. 다시 입력 받음*/
			if(num <1 || num > max){
				Error = 1; 
				printf("Error!"); 
			}
		/*Case2. 입력값이 이미 이전에 입력 받았던 숫자일 경우*/
		if(Error == 0){
			
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
					printf("Error!"); 
				}
			}	
		}
		
	}while(Error == 1);  //Error가 1이면 다시 입력받음(do반복)
	
	printf("사용자가 입력한 숫자 : %d\n", num); //조건에 부합하는 최종 num값 printf
	
 return num; // num값을 return. 
}

int get_number_byCom(int N, int CheckNum[N*N]){

	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			num = rand()%max+1; // 1~max까지의 값을 랜덤으로 받음. 
			/*Case1. 입력값이 범위 밖의 숫자일 경우*/
			if(num <1 || num > N*N){
				Error = 1; //Error = 1, do 다시 반복 
			}
		/*Case2. 입력값이 이미 이전에 입력 받았던 숫자일 경우*/	
		if(Error == 0){
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
				}
			}	
		}
	}while(Error == 1);  //Error가 1이면 다시 입력받음(do 반복) 
	
	printf("컴퓨터가 입력한 숫자 : %d\n\n", num); // 조건에 부합하는 최종 num값 printf  
	
 return num; // num값을 return. 
	
}
