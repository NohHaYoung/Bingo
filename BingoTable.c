#include <time.h>
#include <stdio.h>

/* �ʱ� ���� ���̺��� �����ϴ� �Լ�*/
int initiate_bingo(int C, int A[][C], int B[][C]){

   int i=0, j=0; // �ߺ� üũ�� �ʿ��� ����
   int m, n; // �����ǿ� ������ �Ҵ��ϱ� ���� �ʿ��� ���� 
   int max = C*C;

   int CheckNum[max]; //�ߺ��� üũ�ϱ� ���� �迭
   
   /*�迭�� �����ϱ� ���� ����*/
   int p;
   int rnd;
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
	/*i�� �ʱ�ȭ �� 1���� �迭 CheckNum�� 2�����迭 A�� �ű�*/ 
	i = 0;
		for(int m=0; m<C; m++){
			for(n=0;n<C;n++){
				A[m][n] = CheckNum[i];
				i++;
			}
		}

	//�迭 A�� B�� ���� �ٸ��� �����ǵ��� ����(Computer Bingo Table != Player Bingo Table) 
	while(p<max){
		rnd=rand()%max+1;
		
		temp = CheckNum[0];
		CheckNum[0] = CheckNum[rnd];
		CheckNum[rnd] = temp;
		p++;
	}
	
	/*i�� �ʱ�ȭ �� 1���� �迭 CheckNum�� 2�����迭 B�� �ű�*/
	i = 0;
		for(int m=0; m<C; m++){
			for(n=0;n<C;n++){
				B[m][n] = CheckNum[i];
				i++;
			}
		}
	
}

int	print_bingo(int A, int B[][A]){
	
		
	/*�ݺ������� ��� ���� ���� ���� i, j*/ 
	int i;
	int j;
			
	for(i=0;i<A;i++){
		{for (j=0;j<A;j++)
			printf("%3d ", B[i][j]);}
		printf("\n");}
		
	printf("\n");
 }
 