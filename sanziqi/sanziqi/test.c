#include <stdio.h>
#include "game.h"

void menu(){
    printf("***************************\n");
    printf("****  1.play   0.exit  ****\n");
    printf("***************************\n");
}


void game(){

	char ret= 0;
    //数组存放棋盘的信息
    char board[ROW][COL]= {0};
    //初始化棋盘
    InitBoard(board, ROW, COL);
    //打印棋盘
    DisplayBoard(board, ROW, COL);
	
	while(1){
		//玩家下棋
		playergame(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断
		ret= Iswin(board, ROW, COL);
		if(ret != 'c'){
			break;
		}
			

		//电脑下棋
		computergame(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断
		ret= Iswin(board, ROW, COL);
		if(ret != 'c'){
			break;
		}
	}
		if(ret == '*'){
			printf("玩家赢\n");
		}
		else if(ret == '#'){
			printf("电脑赢\n");
		}
		else{
			printf("平局\n");
		}
		

}


void test(){
    int input= 0;

	srand((unsigned int) time(NULL));

    do{
        menu();
        printf("请输入 >:\n");
        scanf("%d", &input);
        switch(input){
            case 1: game(); 
                break;
            case 0: printf("退出成功\n");
                break;
            default: printf("输入错误，请重新输入\n");
                break;
        }
    }while(input);
}



int main(){

    test();
    return 0;
}
