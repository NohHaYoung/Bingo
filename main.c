#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

#define N 5 // N*N ������ N���� �����ϴ� ��ȣ ��� 
#define M 3 // ���и� �����ϴ� ��ȣ���, M�� ���� ���� �ϼ��� ���� �¸� 

#define ROWS N
#define COLS N

int main(int argc, char *argv[]) {
	
	int turn; // turn���� ���� ����
	
	/* N*N ���� ���̺� 2���� ������ �迭�� ����(Table1 : �����, Table2 : ��ǻ��)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N���� ���� ���� ������ �߻����� �ռ� ������ �������̺� table1�� �ߺ����� �������� �迭�ϴ� �Լ�
	 table 1�� ���� ��Ȳ�� ����Ʈ�ϴ� �Լ�*/
	 initiate_bingo(N, Table1);
	 print_bingo(Table1); 
	
	 
	/* Table2 */
	 initiate_bingo(N, Table2);
	 print_bingo(Table2); 
	 
	 
	 
	return 0;
}
