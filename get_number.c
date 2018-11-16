#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*입력받은 값과 빙고테이블의 값이 일치할 경우 해당 테이블의 값을 -1로 바꿈*/

int process_bingo(int N, int Num, int Table1[][N], int Table2[][N]){
	
	int i, j;
	int m, n;
	
	/*사용자가 입력한 정수 처리
	1. 입력한 정수와 배열이 일치할 경우 배열의 값을 -1로 표시
	2. 입력한 정수가 빙고판에 없는 숫자일 경우 다시 입력받음*/
	while(Num != Table1[i][j]){
		printf("ERROR 재입력하시오 : ");
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
	
	/*사용자가 원하는 정수를 입력 받음*/
	 printf("숫자(1~%d)를 입력하시오 : ", max);
	 scanf("%d", &Num);

	/*사용자가 입력한 정수를 처리하는 함수*/
	 process_bingo(N, Num, Table1, Table2);
	 
	return Table1, Table2;
}

int get_number_byCom(int N, int Num, int Table1[][N], int Table2[][N]){

	int max=N*N;
	int i, j;
	int m, n;
	
	/*컴퓨터가 입력할 정수, 범위 내의 난수 발생 후 하나 선택*/
	do{
		srand((unsigned int)time(NULL));
			Num = rand()%max+1;
			
	}while(Table1[i][j]!=Num);{
		Table1[i][j] = -1;
		Table2[m][n] = -1;
	}
	
}
