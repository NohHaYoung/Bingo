#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*�Է¹��� ���� �������̺��� ���� ��ġ�� ��� �ش� ���̺��� ���� -1�� �ٲ�*/

void process_bingo(int N, int Table[][N], int num){
	
	int i, j;

			if(Table[i][j] == num)
				Table[i][j] == -1;

}

int get_number_byMe(int N, int a, int CheckNum[N*N]){
	
	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			printf("����(1~%d)�� �Է��Ͻÿ� : ", max);
			scanf("%d", &num);
			if(num <1 || num > max){
				Error = 1; //Error�� 1�̸� �ٽ� �Է� 
			}
		/*Error�� 1�� ������ �� �� ���� �̹� �Էµ� �����̸� �ٽ� Error���� 1�� �ٲ�*/
		if(Error == 0){
			
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
				}
			}	
		}
		
	}while(Error == 1);  //Error�� 1�̸� �ٽ� �Է¹���(do �����)
	
 return num; // num���� return. 
}

int get_number_byCom(int N, int a, int CheckNum[N*N]){

	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			num = rand()%max+1; // 1~max������ ���� �������� ����. 
			if(num <1 || num > N*N){
				Error = 1; //Error�� 1�̸� �ٽ� �Է� 
			}
			
		if(Error == 0){
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
				}
			}	
		}
	}while(Error == 1);  //Error�� 1�̸� �ٽ� �Է¹���(do �����) 
	
 return num; // num���� return. 
	
}
