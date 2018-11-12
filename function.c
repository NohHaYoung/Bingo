#include <time.h>
#include <stdio.h>

int N=5;
#define COLS N

/* �ʱ� ���� ���̺��� �����ϴ� �Լ�*/
int initiate_bingo(int N, int A[][COLS], int B[][COLS]){

   int i=0, j=0; // �ߺ� üũ�� �ʿ��� ����
   int m, n; // �����ǿ� ������ �Ҵ��ϱ� ���� �ʿ��� ���� 
   int max = N*N;

   int CheckNum[max]; //�ߺ��� üũ�ϱ� ���� �迭
   
   /*�迭�� �����ϱ� ���� ����*/
   int p;
   int ran;
   int temp=0; 
   

   srand((unsigned int)time(NULL));
		
		while (i<max){
			/*CheckNum�迭�� 1~max������ �ߺ����� ���� �߻�*/ 
			CheckNum[i] = rand()%max +1;
			
				for(int j=0; j<i; j++){
					if(CheckNum[i] == CheckNum[j]){
						i--;
					}
				}
			 i++;
		
		}
	
	i = 0;
		for(int m=0; m<N; m++){
			for(n=0;n<N;n++){
				A[m][n] = CheckNum[i];
				i++;
			}
		}

	//�迭�� �ѹ� �� ����
	while(p<max){
		ran=rand()%max+1;
		
		temp = CheckNum[0];
		CheckNum[0] = CheckNum[ran];
		CheckNum[ran] = temp;
		p++;
	}
	
	//1���� �迭 CheckNum�� �迭B�� �ű�		
	i = 0;
		for(int m=0; m<N; m++){
			for(n=0;n<N;n++){
				B[m][n] = CheckNum[i];
				i++;
			}
		}
	
}

int	print_bingo(int A[][COLS]){
	
		
	/*�ݺ������� ��� ���� ���� ���� i, j*/ 
	int i;
	int j;
			
	for(i=0;i<N;i++){
		{for (j=0;j<N;j++)
			printf("%d ", A[i][j]);}
		printf("\n");}
		
	printf("\n");
 }
