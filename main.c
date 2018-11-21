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
	
	int Win=0; //사용자가 이겼는 지 확인하는 변수 
	int Lose=0; // 컴퓨터가 이겼는 지 확인하는 변수 
	int turn = 0; // turn수를 세는 변수
	int Num; // 사용자가 입력한 정수
	int CheckNum[N*N]; // 입력받은 정수를 저장하는 배열
	/*CheckNum배열의 모든 값을 0으로 초기화*/
	int m;
	 for(m=0;m<N*N;m++){
	 	CheckNum[m] = 0;
	 }
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
	
	/*사용자 숫자 선택(get_number.c)*/
	 Num = get_number_byMe(N, CheckNum);
	 CheckNum[cnt] = Num; //입력 받은 정수를 CheckNum 배열의 cnt번째에 저장 
	 cnt++; 
	 
	/*process_bingo함수를 통해 입력받은 정수를 -1값으로 변경(get_number.c)*/
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
	
	/*count_bingo 함수를 통해 현재 빙고된 줄의 갯수를 return 받고 그 값을 Win과 Lose 변수에 대입(BingoTable.c)*/
	 Win = count_bingo(N, Table1);
	 Lose = count_bingo(N, Table2);	 
	 
	 if(Win == M || Lose == M)
	 	break; // 만약 한 쪽이라도 M 줄 빙고가 완성 되면 반복문(do)을 빠져나감 
	
	 
	/*컴퓨터 숫자 선택(get_number.c)*/
	 Num = get_number_byCom(N, CheckNum);
	 CheckNum[cnt] = Num;
	 cnt++; 
	/*process_bingo함수를 통해 입력받은 정수를 -1값으로 변경(get_number.c)*/
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
 
	/*count_bingo 함수를 통해 현재 빙고된 줄의 갯수를 return 받고 그 값을 Win과 Lose 변수에 대입(BingoTable.c)*/
	 Win = count_bingo(N, Table1);
	 Lose = count_bingo(N, Table2);
	 
	}while((Win != M) && (Lose != M)); // 두 빙고 테이블 모두 M줄 빙고가 되지 않으면 do 반복 
	
	
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(N, Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(N, Table2);

	/*사용자(player)가 이겼을 경우*/	 
	if(Win == M && Lose != M){
		printf("Player Win! ");
		printf("%d 번째 Turn에서 게임 종료\n", turn);
	}
	/*컴퓨터가 이겼을 경우*/
	else if (Win != M && Lose == M){
		printf("Computer Win! ");
		printf("%d 번째 Turn에서 게임 종료\n", turn);
	}
	/*사용자(player)와 컴퓨터가 비겼을 경우*/
	else if(Win == M && Lose == M){
		printf("Draw! ");
		printf("%d 번째 Turn에서 게임 종료\n", turn);
	}
	/*그 이외의 경우 : 에러 - 이 경우에는 do-while문을 빠져나오지 못해서 발생하지 않음.*/
	else{
		printf("Error!\n");
	}
	
	return 0;
}
