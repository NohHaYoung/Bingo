#include <stdio.h>
#include <time.h>

int process_bingo(int A, int B[][A], int C[][A])

int get_number_byMe(int A, int B, int C[][A], int D[][A]){
	
	int max=A*A;
	int i, j;
	
	/*����ڰ� ���ϴ� ������ �Է� ����*/
	 printf("����(1~%d)�� �Է��Ͻÿ�:\n", max);
	 scanf("%d", &B);

	
	/*����ڰ� �Է��� ���� ó��
	1. �Է��� ������ �迭�� ��ġ�� ��� process_bingo�� ó��
	2. �Է��� ������ �����ǿ� ���� ������ ��� �ٽ� �Է¹���*/
	do{for(i=0;i<A;i++){
		for(j=0;j<A;j++){
			if(B!=C[i][j]){
				printf("ERROR! �ٸ� ���ڸ� �Է��Ͻÿ�.");
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
	
	/*��ǻ�Ͱ� �Է��� ����, ���� ���� ���� �߻� �� �ϳ� ����*/
	
	do{	srand((unsigned int)time(NULL)); 
		B = rand()%max+1
	} while(1<=B && B<=max)
} 
