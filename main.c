#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BingoTable.h"
#include "get_number.h"

#define N 3 // N*N ������ N���� �����ϴ� ��ȣ ��� 
#define M 3 // ���и� �����ϴ� ��ȣ���, M�� ���� ���� �ϼ��� ���� �¸� 

#define ROWS N
#define COLS N

int main(int argc, char *argv[]){
	
	int turn = 0; // turn���� ���� ����
	int Num; // ����ڰ� �Է��� ����
	int Count1, Count2; // ���� ���� ���� ���� 
	int BingoUser=0, BingoCom=0; 
	
	/* N*N ���� ���̺� 2���� ������ �迭�� ����(Table1 : �����, Table2 : ��ǻ��)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N���� ���� ���� ������ �߻����� �ռ� ������ �������̺� table1�� table2�� �ߺ����� �������� �迭�ϴ� �Լ�*/
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
	 

	 printf("%d ��° Turn / ", turn); 
	 printf("����� : %d �� ����, ��ǻ�� : %d �� ����\n", BingoUser, BingoCom);
	
	/*����� ���� ����*/
	 get_number_byMe(N, Num, Table1, Table2);
	 
	
	 count_bingo(N, M, Table1, Count1);
	 count_bingo(N, M, Table2, Count2);	 
	
	/*��ǻ�� ���� ����*/
	 get_number_byCom(N, Num, Table1, Table2);
	
	 count_bingo(N, M, Table1, Count1);
	 count_bingo(N, M, Table2, Count2);
	 
	
	/*M���� ���� ��������� ���� ����*/
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
