#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BingoTable.h"
#include "get_number.h"

#define N 5 // N*N 빙고의 N값을 결정하는 기호 상수 
#define M 3 // 승패를 결정하는 기호상수, M개 줄이 먼저 완성된 쪽이 승리 

#define ROWS N
#define COLS N


int main(int argc, char *argv[]){
	
	int Win=0; 
	int Lose=0;
	int turn = 0; // turn수를 세는 변수
	int Num; // 사용자가 입력한 정수
	int CheckNum[N*N]; // 입력받은 정수를 저장하는 배열
	int cnt=0; // CheckNum배열에 들어갈 변수 
	
	/* N*N 빙고 테이블 2개를 이차원 배열로 정의(Table1 : 사용자, Table2 : 컴퓨터)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N까지 범위 내의 난수를 발생시켜 앞서 정의한 빙고테이블 table1과 table2에 중복없이 랜덤으로 배열하는 함수*/
	initiate_bingo(N, Table1, Table2);
	
	
	/*Game start*/
	
	do{

	turn++;	
	
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(N, Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(N, Table2);
	 

	 printf("%d 번째 Turn / ", turn); 
	 printf("사용자 : %d 줄 빙고, 컴퓨터 : %d 줄 빙고\n", Win, Lose);
	
	/*사용자 숫자 선택*/
	 Num = get_number_byMe(N, 0, CheckNum);
	 CheckNum[cnt] = Num;
	 cnt++; 
	 
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
	
	/*M줄 빙고 확인*/
	 Win = count_bingo(N, M, Table1);
	 Lose = count_bingo(N, M, Table2);	 
	 
	 if(Win == M || Lose == M)
	 	break; // 만약 한 쪽이라도 M 줄 빙고가 완성 되면 반복문을 빠져나옴 
	
	 
	/*컴퓨터 숫자 선택*/
	 Num = get_number_byCom(N, 0, CheckNum);
	 CheckNum[cnt] = Num;
	 cnt++; 
	
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
	 
	 count_bingo(N, M, Table1);
	 count_bingo(N, M, Table2);

	/*M줄 빙고 확인*/
	 Win = count_bingo(N, M, Table1);
	 Lose = count_bingo(N, M, Table2);
	 
	}while((Win != M) && (Lose != M)); // 두 빙고 테이블 모두 M줄 빙고가 되지 않으면 do 반복 
	
	
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(N, Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(N, Table2);
	 
	if(Win == M && Lose != M){
		printf("Player Win!\n");
		printf("Turn : %d\n", turn);
	}
	else if (Win != M && Lose == M){
		printf("Computer Win!\n");
		printf("%d Turn\n", turn);
	}
	else if(Win == M && Lose == M){
		printf("Draw!\n");
		printf("%d Turn\n", turn);
	}
	else{
		printf("Error!\n");
	}
	
	return 0;
}
