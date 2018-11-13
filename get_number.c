#include <stdio.h>

int get_number_byMe(int A, int B){
	
	int max=A*A
	
	/*사용자가 원하는 정수를 입력 받음*/
	 printf("숫자(1~%d)를 입력하시오:\n", max);
	 scanf("%d", &B);

	
	/*사용자가 입력한 정수가 이미 나온 숫자거나 범위 내의 숫자가 아닐 경우 다시 입력 받음*/
	 if(B<1 || B>max){
	 	printf("ERROR, 다른 숫자를 입력하시오(1~%d) : \n", max);
		scanf("%d", &B); 	
		}
}

int get_number_byCom(void){
	
	
} 
