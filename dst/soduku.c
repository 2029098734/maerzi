#include<stdio.h>
#include<string.h>

#include"soduku.h"


have cl[9];

int soduku[9][9] = {
	{0,0,0,0,0,0,8,1,3},
	{0,1,0,6,7,0,2,0,9},
	{2,0,9,0,0,3,6,0,5},
	{0,6,7,9,0,4,3,0,0},
	{3,8,1,5,6,0,0,0,0},
	{9,2,0,3,8,0,5,6,7},
	{0,0,6,0,9,2,1,0,0},
	{1,3,0,7,5,6,4,0,0},
	{0,9,2,0,0,0,0,0,6},
	};
int check[10] = {0};


void row_col_have(void)
{
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			if(soduku[i][j] != 0){
				cl[soduku[i][j] - 1].row[i - 1] = 1;
				cl[soduku[i][j] - 1].col[j - 1] = 1;
				cl[soduku[i][j] - 1].blocks[(i/3)*3 + (j/3)] = 1;
			}
		}
	}
}

int do_with_number(int number)
{
	int block[9] = {0};
	int row_pos[9] = {0};
	int col_pos[9] = {0};
	int ret = 0;
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			if(soduku[i][j] == 0 && cl[number - 1].blocks[(i/3)*3 + (j/3)] == 0 &&\
			   cl[number - 1].row[i] == 0 && cl[number - 1].col[i] == 0){
				   block[(i/3)*3 + (j/3)] ++;
				   row_pos[(i/3)*3 + (j/3)] = i;
				   col_pos[(i/3)*3 + (j/3)] = j;
			}
		}
	}
	for(int i = 0;i < 9;i++){
		if(block[i] == 1){
			soduku[row_pos[i]][col_pos[i]] = number;
			ret = 1; 
		}
	}
	return ret;
}

int check_one_block(int *block)
{
	for(int i = -1;i <= 1;i++){
		for(int j = -1;j <= 1;j++){
			if(check[*(block + i + j * 9)] == 0){
				check[*(block + i + j * 9)] = *(block + i + j * 9);
			}else{
				for(int s = 0;s < 10;s++){
					check[s] = 0;
				}
				return 0;
			}
		}
	}
	
	for(int s = 0;s < 10;s++){
		check[s] = 0;
	}
	return 1;
}

int check_block(void)
{
	return check_one_block(&soduku[1][1]) && check_one_block(&soduku[1][4]) && check_one_block(&soduku[1][7])  \
			&& check_one_block(&soduku[4][1]) && check_one_block(&soduku[4][4]) && check_one_block(&soduku[4][7])\
			 && check_one_block(&soduku[7][1]) && check_one_block(&soduku[7][4]) && check_one_block(&soduku[7][7]);
}

int check_one_row(int *row)
{
	for(int i = 0;i < 9;i++){
		if(check[*(row + i)] == 0)
		{
			check[*(row + i)] = *(row + i);
		}else{
			for(int s = 0;s < 10;s++){
				check[s] = 0;
			}
			return 0;
		}
	}
	for(int s = 0;s < 10;s++){
		check[s] = 0;
	}
	return 1;
}


int check_row(void)
{
	return check_one_block(&soduku[0][0]) && check_one_block(&soduku[1][0]) && check_one_block(&soduku[2][0])  \
			&& check_one_block(&soduku[3][0]) && check_one_block(&soduku[4][0]) && check_one_block(&soduku[5][0])\
			 && check_one_block(&soduku[6][0]) && check_one_block(&soduku[7][0]) && check_one_block(&soduku[8][0]);
}

int check_one_col(int *col)
{
	for(int i = 0;i < 9;i++){
		if(check[*(col + i * 9)] == 0)
		{
			check[*(col + i)] = *(col + i);
		}else{
			for(int s = 0;s < 10;s++){
				check[s] = 0;
			}
			return 0;
		}
	}
	for(int s = 0;s < 10;s++){
		check[s] = 0;
	}
	return 1;
}


int check_col(void)
{
	return check_one_block(&soduku[0][0]) && check_one_block(&soduku[0][1]) && check_one_block(&soduku[0][2])  \
			&& check_one_block(&soduku[0][3]) && check_one_block(&soduku[0][4]) && check_one_block(&soduku[0][5])\
			 && check_one_block(&soduku[0][6]) && check_one_block(&soduku[0][7]) && check_one_block(&soduku[0][8]);
}

int check_zero(void)
{
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			if(soduku[i][j] == 0 ){
				   return 0;
			}
		}
	}
	return 1;
}