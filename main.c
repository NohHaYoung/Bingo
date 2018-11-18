#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BingoTable.h"
#include "get_number.h"

#define N 4 // N*N ������ N���� �����ϴ� ��ȣ ��� 
#define M 1 // ���и� �����ϴ� ��ȣ���, M�� ���� ���� �ϼ��� ���� �¸� 

#define ROWS N
#define COLS N


int main(int argc, char *argv[]){
	
	int Win=0; 
	int Lose=0;
	int turn = 0; // turn���� ���� ����
	int Num; // ����ڰ� �Է��� ����
	int CheckNum[N*N]; // �Է¹��� ������ �����ϴ� �迭
	/*CheckNum�迭�� ��� ���� 0���� �ʱ�ȭ*/
	int m;
	 for(m=0;m<N*N;m++){
	 	CheckNum[m] = 0;
	 }
	int cnt=0; // CheckNum�迭�� �� ���� 
	
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
	 printf("����� : %d �� ����, ��ǻ�� : %d �� ����\n", Win, Lose);
	
	/*����� ���� ����*/
	 Num = get_number_byMe(N, 0, CheckNum);
	 CheckNum[cnt] = Num; //�Է� ���� ������ CheckNum �迭�� cnt��°�� ���� 
	 cnt++; 
	 
	 process_bingo(N, Table1, Num);
	 process_bingo(N, Table2, Num);
	
	/*M�� ���� Ȯ��*/
	 Win = count_bingo(N, M, Table1);
	 Lose = count_bingo(N, M, Table2);	 
	 
	 if(Win == M || Lose == M)
	 	break; // ���� �� ���̶� M �� ���� �ϼ� �Ǹ� �ݺ����� �������� 
	
	 
	/*��ǻ�� ���� ����*/
	 Num = get_number_byCom(N, 0, CheckNum);
	 CheckNum[cnt] = Num;
	 cnt++; 
	
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
		printf("Player Win! ");
		printf("%d ��° Turn���� ���� ����\n", turn);
	}
	else if (Win != M && Lose == M){
		printf("Computer Win! ");
		printf("%d ��° Turn���� ���� ����\n", turn);
	}
	else if(Win == M && Lose == M){
		printf("Draw! ");
		printf("%d ��° Turn���� ���� ����\n", turn);
	}
	else{
		printf("Error!\n");
	}
	
	return 0;
}
