#include "game.h"
#include <stdio.h>


int Isfull(char board[ROW][COL], int row, int col){
	int i= 0,j= 0;
	for(i= 0; i< row; i++){
		for(j= 0; j< col; j++){
			if(board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

void InitBoard(char board[ROW][COL], int row, int col){
    int i= 0, j= 0;
    for(i= 0; i< row; i++){
        for(j= 0; j< col; j++){
            board[i][j]= ' ';
        }
    }
}

void DisplayBoard(char board[ROW][COL], int row, int col){
    int i= 0, j= 0;
    for(i= 0; i< row; i++){
        for(j= 0;j< col; j++){
            printf(" %c ", board[i][j]);
            if(j< col- 1)
                printf("|");
        }
        printf("\n");

        if(i< row- 1){
            for(j= 0;j< col; j++){
            printf("---");
            if(j< col- 1)
                printf("|");
        }
        printf("\n");
        }
    }
}


void playergame(char board[ROW][COL], int row, int col){
	int x= 0;
	int y= 0;
	printf("������룺\n");
	while(1){
		
		printf("�����룺");
		scanf("%d%d", &x, &y);
		if(x>= 1 && x<= row && y>= 1 && y<= col){
			if(board[x-1][y-1] == ' '){
				board[x-1][y-1] = '*';
				break;
			}
			else
				printf("�˵㱻ռ��");
		}
		else
			printf("�����������������\n");
	}
	
}


void computergame(char board[ROW][COL], int row, int col)
{
	int x= 0, y= 0;
	
	printf("�������룺\n");
	while(1){
		x= rand()% row;
		y= rand()% col;
		if(board[x][y] == ' '){
			board[x][y] = '#';
			break;
		}
	}
}


//�ж���Ӯ
//���ʤ��*
//����ʤ��#
//��ƽ��p
//������c

char Iswin(char board[ROW][COL], int row, int col){
	int i= 0;
	//������
	for(i= 0; i< row; i++){
		if(board[i][0] ==board[i][1] && board[i][1]== board[i][2] && board[i][2] !=' '){
			return board[i][0];
		}
	}
	//������
	for(i= 0; i< col; i++){
		if(board[0][i] ==board[1][i] && board[1][i]== board[2][i] && board[2][i] !=' '){
			return board[0][i];
		}
	}
	//б����
	if(board[0][0] == board[1][1] && board[1][1]==board[2][2] && board[2][2]!= ' '){
		return board[0][0];
	}
	if(board[0][2] == board[1][1] && board[1][1]==board[2][0] && board[2][0]!= ' '){
		return board[0][2];
	}

	//ƽ��
	
	if(1 ==Isfull(board, ROW, COL)){
		return 'p';
	}
	return 'c';
}
