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
	
	int Win; 
	int Lose;
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
	
	do{

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
	 Num = get_number_byMe(N, 0);
	 
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
	
	/*M�� ���� Ȯ��*/
	 Win = count_bingo(N, M, Table1);
	 Lose = count_bingo(N, M, Table2);	 
	 
	 if(Win == M || Lose == M)
	 	break; // ���� �� ���̶� M �� ���� �ϼ� �Ǹ� �ݺ����� �������� 
	
	 
	/*��ǻ�� ���� ����*/
	 get_number_byCom(N, 0);
	 
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
	 
	 count_bingo(N, M, Table1);
	 count_bingo(N, M, Table2);

	/*M�� ���� Ȯ��*/
	 Win = count_bingo(N, M, Table1);
	 Lose = count_bingo(N, M, Table2);
	 
	}while((Win != M) && (Lose != M)); // �� ���� ���̺� ��� M�� ���� ���� ������ do �ݺ� 
	
	
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(N, Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(N, Table2);
	 
	if(Win == M && Lose != M){
		printf("Player Win!\n");
	}
	else if (Win != M && Lose == M){
		printf("Computer Win!\n");
	}
	else if(Win == M && Lose == M){
		printf("Draw!\n");
	}
	else{
		printf("Error!\n");
	}
	
	return 0;
}
