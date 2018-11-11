#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

#define N 5 // N*N 빙고의 N값을 결정하는 기호 상수 
#define M 3 // 승패를 결정하는 기호상수, M개 줄이 먼저 완성된 쪽이 승리 

#define ROWS N
#define COLS N

int main(int argc, char *argv[]) {
	
	int turn; // turn수를 세는 변수
	
	/* N*N 빙고 테이블 2개를 이차원 배열로 정의(Table1 : 사용자, Table2 : 컴퓨터)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N까지 범위 내의 난수를 발생시켜 앞서 정의한 빙고테이블 table1에 중복없이 랜덤으로 배열하는 함수
	 table 1의 현재 상황을 프린트하는 함수*/
	 initiate_bingo(N, Table1);
	 print_bingo(Table1); 
	
	 
	/* Table2 */
	 initiate_bingo(N, Table2);
	 print_bingo(Table2); 
	 
	 
	 
	return 0;
}
