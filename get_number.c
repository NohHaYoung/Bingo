#include <stdio.h>

int get_number_byMe(int A, int B){
	
	int max=A*A
	
	/*����ڰ� ���ϴ� ������ �Է� ����*/
	 printf("����(1~%d)�� �Է��Ͻÿ�:\n", max);
	 scanf("%d", &B);

	
	/*����ڰ� �Է��� ������ �̹� ���� ���ڰų� ���� ���� ���ڰ� �ƴ� ��� �ٽ� �Է� ����*/
	 if(B<1 || B>max){
	 	printf("ERROR, �ٸ� ���ڸ� �Է��Ͻÿ�(1~%d) : \n", max);
		scanf("%d", &B); 	
		}
}

int get_number_byCom(void){
	
	
} 
