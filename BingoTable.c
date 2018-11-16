#include <time.h>
#include <stdio.h>

/* 초기 빙고 테이블을 생성하는 함수*/
int initiate_bingo(int N, int Table1[][N], int Table2[][N]){

   int i=0, j=0; // 중복 체크에 필요한 변수
   int m, n; // 빙고판에 난수를 할당하기 위해 필요한 변수 
   int max = N*N;

   int CheckNum[max]; //중복을 체크하기 위한 배열
   
   /*배열을 셔플하기 위한 변수*/
   int p;
   int rnd;
   int temp=0; 
   

   srand((unsigned int)time(NULL));
		
		while (i<max){
			/*CheckNum배열에 1~max까지의 중복없는 난수 발생*/ 
			CheckNum[i] = rand()%max +1;
			
				for(int j=0; j<i; j++){
					if(CheckNum[i] == CheckNum[j]){
						i--;
					}
				}
			 i++;
		
		}
	/*i값 초기화 후 1차원 배열 CheckNum을 2차원배열 A로 옮김*/ 
	i = 0;
		for(int m=0; m<N; m++){
			for(n=0;n<N;n++){
				Table1[m][n] = CheckNum[i];
				i++;
			}
		}

	//배열 A와 B의 값이 다르게 설정되도록 셔플(Computer Bingo Table != Player Bingo Table) 
	while(p<max){
		rnd=rand()%max+1;
		
		temp = CheckNum[0];
		CheckNum[0] = CheckNum[rnd];
		CheckNum[rnd] = temp;
		p++;
	}
	
	/*i값 초기화 후 1차원 배열 CheckNum을 2차원배열 B로 옮김*/
	i = 0;
		for(int m=0; m<N; m++){
			for(n=0;n<N;n++){
				Table2[m][n] = CheckNum[i];
				i++;
			}
		}
	
}

/*빙고테이블을 프린트하는 함수*/
int	print_bingo(int N, int Table[][N]){
	
		
	/*반복문에서 행과 열을 세는 변수 i, j*/ 
	int i;
	int j;
			
	for(i=0;i<N;i++){
		{for (j=0;j<N;j++)
			printf("%3d ", Table[i][j]);}
		printf("\n");}
		
	printf("\n");
 }

/*빙고 수를 세는 함수*/
int count_bingo(int N, int M, int Table[][N], int Count){
	
	int i, j;
	int Sum[2*N+2];
	
	/*가로줄 빙고*/
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Sum[i] = Sum[i] + Table[i][j];
		}
	}
	 
	/*세로줄 빙고*/
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			Sum[i+N] = Sum[i+N] + Table[i][j];
		}
	}
	/*대각선 빙고*/
	for(i=0;i<N;i++){
		for(j=N;j>0;j--){
		} Sum[i+2*N] = Sum[i+2*N] + Table[i][j];
	}

	for(i=0;i<2*N+2;i++){
		if(Sum[i]==0){
			Count++;
		}
	}
	
	return Count;	
}
 
