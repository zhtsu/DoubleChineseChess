#include <stdio.h>
#include <stdlib.h>

#include "ruleHead.h"
#include "coreHead.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("mode con cols=105 lines=35");//��������̨���ڴ�С
	
	Show_menu();//չʾ�˵�
	Get_command();//�õ����˵�����
	
	system("pause");
	return 0;
}
