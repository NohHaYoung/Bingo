#include <stdio.h>
#include <time.h>

/*�Է¹��� ���� �������̺��� ���� ��ġ�� ��� �ش� ���̺��� ���� -1�� �ٲ�*/

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
	
	/*����ڰ� ���ϴ� ������ �Է� ����*/
	 printf("����(1~%d)�� �Է��Ͻÿ� : ", max);
	 scanf("%d", &Num);

	
	/*����ڰ� �Է��� ���� ó��
	1. �Է��� ������ �迭�� ��ġ�� ��� process_bingo�� ó��
	2. �Է��� ������ �����ǿ� ���� ������ ��� �ٽ� �Է¹���*/
	
	while(1){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(Num!=Table1[i][j]){
					printf("ERROR, �ٸ� ���ڸ� �Է��Ͻÿ� : ");
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
	
	/*��ǻ�Ͱ� �Է��� ����, ���� ���� ���� �߻� �� �ϳ� ����*/
	
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
