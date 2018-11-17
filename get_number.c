#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*입력받은 값과 빙고테이블의 값이 일치할 경우 해당 테이블의 값을 -1로 바꿈*/

void process_bingo(int N, int Table[][N], int num){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(Table[i][j] == num)
				Table[i][j] == -1;
		}
	}	

}

int get_number_byMe(int N, int a){
	
	int num;
	int Error;
	int max = N*N;
	
	do{
		Error = 0;

			printf("숫자(1~%d)를 입력하시오 : ", max);
			scanf("%d", &num);
			if(num <1 || num > max){
				Error = 1; //Error가 1이면 다시 입력 
			}
		
	}while(Error == 1);  //Error가 1이면 다시 입력받음(do 재실행) 
	
 return num; // num값을 return. 
}

int get_number_byCom(int N, int a){

	int num;
	int Error;
	int max = N*N;
	
	do{
		Error = 0;

			num = rand()%max+1; // 1~max까지의 값을 랜덤으로 받음. 
			if(num <1 || num > N*N){
				Error = 1; //Error가 1이면 다시 입력 
			}
		
	}while(Error == 1);  //Error가 1이면 다시 입력받음(do 재실행) 
	
 return num; // num값을 return. 
	
}
