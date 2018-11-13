#include <stdio.h>
#include <time.h>

/*입력받은 값과 빙고테이블의 값이 일치할 경우 해당 테이블의 값을 -1로 바꿈*/

int process_bingo(int N, int Num, int Table1[][N], int Table2[][N]){
	
	int i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(Table1[i][j]==Num){
				Table1[i][j] = -1;
				Table2[i][j] = -1;
			} 
		}
	}
	
}

int get_number_byMe(int N, int Num, int Table1[][N], int Table2[][N]){
	
	int max=N*N;
	int i, j;
	
	/*사용자가 원하는 정수를 입력 받음*/
	 printf("숫자(1~%d)를 입력하시오 : ", max);
	 scanf("%d", &Num);

	
	/*사용자가 입력한 정수 처리
	1. 입력한 정수와 배열이 일치할 경우 process_bingo로 처리
	2. 입력한 정수가 빙고판에 없는 숫자일 경우 다시 입력받음*/
	
	while(1){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(Num!=Table1[i][j]){
					printf("ERROR, 다른 숫자를 입력하시오 : ");
					scanf("%d", &Num);
				}
					
				else{
					break;
				}
			}
		} 
	
	}
	process_bingo(N, Num, Table1, Table2);
}

int get_number_byCom(int N, int Num, int Table1[][N], int Table2[][N]){

	int max=N*N;
	int i, j;
	
	/*컴퓨터가 입력할 정수, 범위 내의 난수 발생 후 하나 선택*/
	
	do{
		srand((unsigned int)time(NULL)); 
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				Num = rand()%max+1;
			}
		}
	} while(Num == Table1[i][j]);{
		process_bingo(N, Num, Table1, Table2);
	}
} 
