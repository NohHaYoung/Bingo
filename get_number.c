#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*�Է¹��� ���� �������̺��� ���� ��ġ�� ��� �ش� ���̺��� ���� -1�� �ٲ�*/

void process_bingo(int N, int Table[][N], int num){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(Table[i][j] == num)
				Table[i][j] == -1;
		}
	}	

}

int get_number_byMe(int N, int a){
	
	int num;
	int Error;
	int max = N*N;
	
	do{
		Error = 0;

			printf("����(1~%d)�� �Է��Ͻÿ� : ", max);
			scanf("%d", &num);
			if(num <1 || num > max){
				Error = 1; //Error�� 1�̸� �ٽ� �Է� 
			}
		
	}while(Error == 1);  //Error�� 1�̸� �ٽ� �Է¹���(do �����) 
	
 return num; // num���� return. 
}

int get_number_byCom(int N, int a){

	int num;
	int Error;
	int max = N*N;
	
	do{
		Error = 0;

			num = rand()%max+1; // 1~max������ ���� �������� ����. 
			if(num <1 || num > N*N){
				Error = 1; //Error�� 1�̸� �ٽ� �Է� 
			}
		
	}while(Error == 1);  //Error�� 1�̸� �ٽ� �Է¹���(do �����) 
	
 return num; // num���� return. 
	
}
