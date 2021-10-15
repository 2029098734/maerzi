#include<stdio.h>
#include<string.h>

#include"soduku.h"

int main(void)
{
	memset(cl,0,(sizeof(have) * 9));
	int count = 0;
	while(!check_zero()){
		row_col_have();
		for(int number = 1;number <= 9;number++){
			do_with_number(number);
		}
		if(count ++ > 2000000)
		{
			break;
		}
	}
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			printf(" %d ",soduku[i][j]);
		}
		printf("\n");
	}
	return 0;
} 





