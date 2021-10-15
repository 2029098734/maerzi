#ifndef SODUKU_H_
#define SODUKU_H_

void row_col_have(void);

void do_with_number(int number);

int check_one_block(int *block);

int check_block(void);

int check_one_row(int *row);

int check_row(void);

int check_one_col(int *col);

int check_col(void);

typedef struct have_number{
	int row[9];
	int col[9];
	int blocks[9];
} have;

extern have cl[9];
extern int soduku[9][9];
extern int check[10];

#endif

