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
   int temp; 
   

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
	for(i=0;i<N*N;i++){
		rnd = rand()%max;
		
		temp = CheckNum[i];
		CheckNum[i] = CheckNum[rnd];
		CheckNum[rnd] = temp;
		
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

/*�������̺��� ����Ʈ�ϴ� �Լ�*/
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

/*���� ���� ���� �Լ�*/
int count_bingo(int N, int Table[][N]){
	int i, j;
	int Sum; // ����� ���� ���� -N
	int Count=0; // ���� ����� ���� ���� �����ϴ� ����, Sum=-N�̸� Count���� ������Ű�� ���� Count ���� �����Լ��� return, return ���� M�� �Ǹ� ���� ���� 
	
	/*������ ���� Ȯ��*/
	for(i=0;i<N;i++){
		Sum = 0; //Sum �� �ʱ�ȭ 
		for(j=0; j<N; j++){
			Sum += Table[i][j];
		}
		/*���� Sum = -N �̸� Count�� 1 ����*/
		if(Sum == -1*N){
			Count = Count+1; 
		}
	}
	/*������ ���� Ȯ��*/
	for(j=0;j<N;j++){
		Sum = 0; // Sum �� �ʱ�ȭ
		for(i=0;i<N;i++){
			Sum += Table[i][j];
		}
		if(Sum == -1*N){
			Count = Count+1;
		}
	}
	
	/*�밢��(i,i) ���� Ȯ��(���������� ������ �Ʒ� ����)*/
	Sum = 0;
	for(i=0;i<N;i++){
		Sum += Table[i][i];
	}
	/*���� Sum = -N �̸� Count�� 1 ����*/
	if(Sum == -1*N){
		Count = Count+1;
	}
	
	/*�밢��(i,N-i-1) ���� Ȯ��(������������ ���� �Ʒ� ����)*/
	Sum = 0;
	for(i=0;i<N;i++){
		Sum += Table[i][N-i-1];
	}
	/*���� Sum = -N �̸� Count�� 1 ����*/
	if(Sum == -1*N){
		Count = Count+1;
	}

	return Count;
}
 
