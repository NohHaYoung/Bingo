#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

#define N 3 // N*N ������ N���� �����ϴ� ��ȣ ��� 
#define M 3 // ���и� �����ϴ� ��ȣ���, M�� ���� ���� �ϼ��� ���� �¸� 

#define ROWS N
#define COLS N

int main(int argc, char *argv[]) {
	
	int turn; // turn���� ���� ����
	int Num; // ����ڰ� �Է��� ����
	int BingoUser=0, BingoCom=0; 
	
	/* N*N ���� ���̺� 2���� ������ �迭�� ����(Table1 : �����, Table2 : ��ǻ��)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N���� ���� ���� ������ �߻����� �ռ� ������ �������̺� table1�� table2�� �ߺ����� �������� �迭�ϴ� �Լ�*/
	initiate_bingo(N, Table1, Table2);
	
	
	/*Game start*/
	do{
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(Table2);
	
	 printf("%d ��° Turn", turn); 
	 printf("����� : %d �� ����, ��ǻ�� : %d �� ����", BingoUser, BingoCom);
	 printf("���ϴ� ���ڸ� �Է��Ͻÿ�(1~%d) : ", N*N);
	 scanf("%d", &Num);
	 
	} while()
	
	 
	 
	 
	return 0;
}
