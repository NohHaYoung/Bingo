#include <time.h>
#include <stdio.h>

int N=5;
#define COLS N

/* �ʱ� ���� ���̺��� �����ϴ� �Լ�*/
int initiate_bingo(int N, int A[][COLS]){

   int i, j, k; // �ݺ����� �ʿ��� ���� 
   int rnd; // ���� ���� �����ϴ� ���� 

   int nums[N*N]; 

   srand((unsigned int)time(NULL));
		for (i = 0; i < 25; ){ 
			rnd = rand() % 25 + 1; 
				
				for (j = 0; j < i; j++){
            		if (nums[j] == rnd){
                     break;
              		} 
				}
       if (i == j){ 
    		nums[i++] = rnd; 
		}
		} 

 	k = 0; 

 	for (i = 0; i < 5; i++){ 

       for (j = 0; j < 5; j++){ 

             A[i][j] = nums[k++];
    	} 
	} 
 return (A[i][j]);
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
