#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BingoTable.h"
#include "get_number.h"

#define N 3 // N*N 빙고의 N값을 결정하는 기호 상수 
#define M 3 // 승패를 결정하는 기호상수, M개 줄이 먼저 완성된 쪽이 승리 

#define ROWS N
#define COLS N

int main(int argc, char *argv[]){
	
	int turn = 0; // turn수를 세는 변수
	int Num; // 사용자가 입력한 정수
	int Count1, Count2; // 빙고 수를 세는 변수 
	int BingoUser=0, BingoCom=0; 
	
	/* N*N 빙고 테이블 2개를 이차원 배열로 정의(Table1 : 사용자, Table2 : 컴퓨터)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N까지 범위 내의 난수를 발생시켜 앞서 정의한 빙고테이블 table1과 table2에 중복없이 랜덤으로 배열하는 함수*/
	initiate_bingo(N, Table1, Table2);
	
	
	/*Game start*/
	
	while(1){
	
	turn++;	
	
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(N, Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(N, Table2);
	 

	 printf("%d 번째 Turn / ", turn); 
	 printf("사용자 : %d 줄 빙고, 컴퓨터 : %d 줄 빙고\n", BingoUser, BingoCom);
	
	/*사용자 숫자 선택*/
	 get_number_byMe(N, Num, Table1, Table2);
	 
	
	 count_bingo(N, M, Table1, Count1);
	 count_bingo(N, M, Table2, Count2);	 
	
	/*컴퓨터 숫자 선택*/
	 get_number_byCom(N, Num, Table1, Table2);
	
	 count_bingo(N, M, Table1, Count1);
	 count_bingo(N, M, Table2, Count2);
	 
	
	/*M개의 줄이 만들어지면 게임 종료*/
	 if(Count1 == M || Count2 == M )
		break;
	}
 
	if(Count1 == M && Count2 != M){
		printf("User Win, Turn = %d\n", turn);
	}

	else if(Count2 == M && Count1 != M){
		printf("Computer Win, Turn = %d\n", turn);
	}
	else if(Count1 == M && Count2 == M){
		printf("Draw\n");
	}

	 

	return 0;
}
