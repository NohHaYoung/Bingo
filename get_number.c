#include <stdio.h>
#include <time.h>

int process_bingo(int A, int B[][A], int C[][A])

int get_number_byMe(int A, int B, int C[][A], int D[][A]){
	
	int max=A*A;
	int i, j;
	
	/*사용자가 원하는 정수를 입력 받음*/
	 printf("숫자(1~%d)를 입력하시오:\n", max);
	 scanf("%d", &B);

	
	/*사용자가 입력한 정수 처리
	1. 입력한 정수와 배열이 일치할 경우 process_bingo로 처리
	2. 입력한 정수가 빙고판에 없는 숫자일 경우 다시 입력받음*/
	do{for(i=0;i<A;i++){
		for(j=0;j<A;j++){
			if(B!=C[i][j]){
				printf("ERROR! 다른 숫자를 입력하시오.");
				scanf("%d",&B);
			}
		 }
		}
	}while(B==C[i][j]){
	 break;
	}
}

int get_number_byCom(int A, int B, int C[][A], int D[][A]){

	int max=A*A;
	
	/*컴퓨터가 입력할 정수, 범위 내의 난수 발생 후 하나 선택*/
	
	do{	srand((unsigned int)time(NULL)); 
		B = rand()%max+1
	} while(1<=B && B<=max)
} 
