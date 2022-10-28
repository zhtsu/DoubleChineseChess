#include <stdio.h>
#include <stdlib.h>

#include "ruleHead.h"
#include "coreHead.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("mode con cols=105 lines=35");//调整控制台窗口大小
	
	Show_menu();//展示菜单
	Get_command();//得到主菜单命令
	
	system("pause");
	return 0;
}
