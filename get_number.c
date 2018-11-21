#include <stdio.h>
#include <time.h>
#include "BingoTable.h"

/*�Է¹��� ���� �������̺��� ���� ��ġ�� ��� �ش� ���̺��� ���� -1�� �ٲ�*/

void process_bingo(int N, int Table[][N], int num){
	
	int i, j;
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(Table[i][j] == num)
					Table[i][j] = -1;
			}
		}

}

/*get_number_byCom & get_number_byMe : do-while�� �̿�.
Error ���� 1�� ��� do �ݺ�����, Error ���� 0�� ��� �ݺ����� ������ �Է¹��� num ���� return��
(Error ���� 1�� ��� : �Է� ���� ���ڰ� ���� ���� ������ ���& �Է¹��� ���ڰ� ������ �̹� �Է¹޾Ҵ� ������ ���*/
int get_number_byMe(int N, int CheckNum[N*N]){
	
	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			printf("����(1~%d)�� �Է��Ͻÿ� : ", max);
			scanf("%d", &num);
			/*Case1. �Է°��� ���� ���� ������ ��� Error �߻�. �ٽ� �Է� ����*/
			if(num <1 || num > max){
				Error = 1; 
				printf("Error!"); 
			}
		/*Case2. �Է°��� �̹� ������ �Է� �޾Ҵ� ������ ���*/
		if(Error == 0){
			
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
					printf("Error!"); 
				}
			}	
		}
		
	}while(Error == 1);  //Error�� 1�̸� �ٽ� �Է¹���(do�ݺ�)
	
	printf("����ڰ� �Է��� ���� : %d\n", num); //���ǿ� �����ϴ� ���� num�� printf
	
 return num; // num���� return. 
}

int get_number_byCom(int N, int CheckNum[N*N]){

	int num;
	int Error;
	int max = N*N;
	int i;
	
	do{
		Error = 0;

			num = rand()%max+1; // 1~max������ ���� �������� ����. 
			/*Case1. �Է°��� ���� ���� ������ ���*/
			if(num <1 || num > N*N){
				Error = 1; //Error = 1, do �ٽ� �ݺ� 
			}
		/*Case2. �Է°��� �̹� ������ �Է� �޾Ҵ� ������ ���*/	
		if(Error == 0){
			for(i=0;i<max;i++){
				if(CheckNum[i] == num){
					Error = 1;
				}
			}	
		}
	}while(Error == 1);  //Error�� 1�̸� �ٽ� �Է¹���(do �ݺ�) 
	
	printf("��ǻ�Ͱ� �Է��� ���� : %d\n\n", num); // ���ǿ� �����ϴ� ���� num�� printf  
	
 return num; // num���� return. 
	
}
