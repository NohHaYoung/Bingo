#include <time.h>
#include <stdio.h>

/* �ʱ� ���� ���̺��� �����ϴ� �Լ�*/
int initiate_bingo(int N, int Table1[][N], int Table2[][N]){

   int i=0, j=0; // �ߺ� üũ�� �ʿ��� ����
   int m, n; // �����ǿ� ������ �Ҵ��ϱ� ���� �ʿ��� ���� 
   int max = N*N;

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
		for(int m=0; m<N; m++){
			for(n=0;n<N;n++){
				Table1[m][n] = CheckNum[i];
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
		for(int m=0; m<N; m++){
			for(n=0;n<N;n++){
				Table2[m][n] = CheckNum[i];
				i++;
			}
		}
	
}

int	print_bingo(int N, int Table[][N]){
	
		
	/*�ݺ������� ��� ���� ���� ���� i, j*/ 
	int i;
	int j;
			
	for(i=0;i<N;i++){
		{for (j=0;j<N;j++)
			printf("%3d ", Table[i][j]);}
		printf("\n");}
		
	printf("\n");
 }
 
int count_bingo(int N, int M, int Table[][N], int Count[2*M+2]){
	int Sum = 0;
	int i, j;
	
	/*������ ����*/
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Sum = Sum + Table[i][j];
		}
		Count[i] = Sum;
	}
	
	Sum = 0; // �ʱ�ȭ 
	/*������ ����*/
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			Sum = Sum + Table[i][j];
		}
		Count[i+N] = Sum;
	}
	
	Sum = 0;
	/*�밢�� ����*/
	for(i=0;i<N;i++){
		for(j=N;j>0;j--){
		} Sum = Sum + Table[i][j];
		Count[i+2*N] = Sum;
	}
	
}
 
