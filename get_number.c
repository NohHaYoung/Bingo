#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*�Է¹��� ���� �������̺��� ���� ��ġ�� ��� �ش� ���̺��� ���� -1�� �ٲ�*/

int process_bingo(int N, int Num, int Table1[][N], int Table2[][N]){
	
	int i, j;
	int m, n;
	
	/*����ڰ� �Է��� ���� ó��
	1. �Է��� ������ �迭�� ��ġ�� ��� �迭�� ���� -1�� ǥ��
	2. �Է��� ������ �����ǿ� ���� ������ ��� �ٽ� �Է¹���*/
	while(Num != Table1[i][j]){
		printf("ERROR ���Է��Ͻÿ� : ");
		scanf("%d", &Num);
	}
	
	if(Table1[i][j]==Num){
		Table1[i][j] = -1;
	}
	
	if(Table2[m][n]==Num){
		Table2[m][n] = -1;
	}
	
	return Table1, Table2;
	
}

int get_number_byMe(int N, int Num, int Table1[][N], int Table2[][N]){
	
	int max=N*N;
	int i, j;
	
	/*����ڰ� ���ϴ� ������ �Է� ����*/
	 printf("����(1~%d)�� �Է��Ͻÿ� : ", max);
	 scanf("%d", &Num);

	/*����ڰ� �Է��� ������ ó���ϴ� �Լ�*/
	 process_bingo(N, Num, Table1, Table2);
	 
	return Table1, Table2;
}

int get_number_byCom(int N, int Num, int Table1[][N], int Table2[][N]){

	int max=N*N;
	int i, j;
	int m, n;
	
	/*��ǻ�Ͱ� �Է��� ����, ���� ���� ���� �߻� �� �ϳ� ����*/
	do{
		srand((unsigned int)time(NULL));
			Num = rand()%max+1;
			
	}while(Table1[i][j]!=Num);{
		Table1[i][j] = -1;
		Table2[m][n] = -1;
	}
	
}
