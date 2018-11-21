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
   int temp; 
   

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
	for(i=0;i<N*N;i++){
		rnd = rand()%max;
		
		temp = CheckNum[i];
		CheckNum[i] = CheckNum[rnd];
		CheckNum[rnd] = temp;
		
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
int count_bingo(int N, int Table[][N]){
	int i, j;
	int Sum; // 빙고된 줄의 합은 -N
	int Count=0; // 현재 빙고된 줄의 수를 저장하는 변수, Sum=-N이면 Count값을 증가시키고 최종 Count 값을 메인함수로 return, return 값이 M이 되면 게임 종료 
	
	/*가로줄 빙고 확인*/
	for(i=0;i<N;i++){
		Sum = 0; //Sum 값 초기화 
		for(j=0; j<N; j++){
			Sum += Table[i][j];
		}
		/*만약 Sum = -N 이면 Count값 1 증가*/
		if(Sum == -1*N){
			Count = Count+1; 
		}
	}
	/*세로줄 빙고 확인*/
	for(j=0;j<N;j++){
		Sum = 0; // Sum 값 초기화
		for(i=0;i<N;i++){
			Sum += Table[i][j];
		}
		if(Sum == -1*N){
			Count = Count+1;
		}
	}
	
	/*대각선(i,i) 빙고 확인(왼쪽위에서 오른쪽 아래 방향)*/
	Sum = 0;
	for(i=0;i<N;i++){
		Sum += Table[i][i];
	}
	/*만약 Sum = -N 이면 Count값 1 증가*/
	if(Sum == -1*N){
		Count = Count+1;
	}
	
	/*대각선(i,N-i-1) 빙고 확인(오른쪽위에서 왼쪽 아래 방향)*/
	Sum = 0;
	for(i=0;i<N;i++){
		Sum += Table[i][N-i-1];
	}
	/*만약 Sum = -N 이면 Count값 1 증가*/
	if(Sum == -1*N){
		Count = Count+1;
	}

	return Count;
}
 
