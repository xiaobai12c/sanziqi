#include <stdio.h>
#include "game.h"

void menu(){
    printf("***************************\n");
    printf("****  1.play   0.exit  ****\n");
    printf("***************************\n");
}


void game(){

	char ret= 0;
    //���������̵���Ϣ
    char board[ROW][COL]= {0};
    //��ʼ������
    InitBoard(board, ROW, COL);
    //��ӡ����
    DisplayBoard(board, ROW, COL);
	
	while(1){
		//�������
		playergame(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�
		ret= Iswin(board, ROW, COL);
		if(ret != 'c'){
			break;
		}
			

		//��������
		computergame(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�
		ret= Iswin(board, ROW, COL);
		if(ret != 'c'){
			break;
		}
	}
		if(ret == '*'){
			printf("���Ӯ\n");
		}
		else if(ret == '#'){
			printf("����Ӯ\n");
		}
		else{
			printf("ƽ��\n");
		}
		

}


void test(){
    int input= 0;

	srand((unsigned int) time(NULL));

    do{
        menu();
        printf("������ >:\n");
        scanf("%d", &input);
        switch(input){
            case 1: game(); 
                break;
            case 0: printf("�˳��ɹ�\n");
                break;
            default: printf("�����������������\n");
                break;
        }
    }while(input);
}



int main(){

    test();
    return 0;
}
