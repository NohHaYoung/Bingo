#include <time.h>
#include <stdio.h>

int N=5;
#define COLS N

/* 초기 빙고 테이블을 생성하는 함수*/
int initiate_bingo(int N, int A[][COLS]){

   int i, j, k; // 반복문에 필요한 변수 
   int rnd; // 난수 값을 저장하는 변수 

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
	
		
	/*반복문에서 행과 열을 세는 변수 i, j*/ 
	int i;
	int j;
			
	for(i=0;i<N;i++){
		{for (j=0;j<N;j++)
			printf("%d ", A[i][j]);}
		printf("\n");}
		
	printf("\n");
}
