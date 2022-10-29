#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coreHead.h"

void Show_menu()//绘制菜单 
{ 
	printf("\n\n\n\n\n\n\n                                            ☆ 双人象棋 ☆\n\n\n");
	printf("                                        1 ---  重新开始  --- 1\n\n");
	printf("                                        2 ---  残局挑战  --- 2\n\n");
	printf("                                        3 ---  游戏帮助  --- 3\n\n");
	printf("                                        4 ---  退出游戏  --- 4\n\n\n");
	printf("                          （⊙ω⊙）请大人输入您想要完成的操作对应的序号："); 
}

void Get_command()//得到主菜单命令
{
	int command; 
	
	scanf("%d",&command);
	system("cls");

	if(command==1) {Start_game();}
	else if(command==2) {Files_menu();Files_command();}
	else if(command==3) {Instruction();}
	else if(command==4) {Out_game();}
	else {Error_hint();Show_menu();Get_command();}
}
 
void Out_game()//退出游戏界面 
{
	int command_1;

	system("cls");
	
	printf("\n\n                                       (⊙ ⊙)大人确定要离开了吗？\n\n\n");//提醒玩家是否确认退出
	printf("                                          886 --- 返回 --- 886\n\n");
	printf("                                 其它任意序号 --- 退出 --- 其它任意序号\n\n");
	printf("                                             请输入序号：");

	scanf("%d",&command_1);
	system("cls");

	if(command_1==886) {Show_menu();Get_command();}
	else {printf("\n\n                               ~ ( T _ T ) 大人再见！常回来看看啊！\n");exit(0);}
}

void Instruction() //显示游戏说明
{ 
		int command_2; 

		printf("\n                                              象棋口诀\n");
		printf("                                    将军不离九宫内，士止相随不出官。\n");
		printf("                                    象飞四方营四角，马行一步一尖冲。\n");
		printf("                                    炮须隔子打一子，车行直路任西东。\n");
		printf("                                    唯卒只能行一步，过河横进退无踪。\n"); 
		printf("\n\nChinese Chess 是一款双人休闲小游戏。选择重新开始，大人可以与好友开启一局有趣的中国象棋对弈;");
		printf(" 选择读取存档，大人可以读取对战记录，与好友进行未完成的对局;选择残局挑战，大人面前将会重现象");
		printf("棋界众多魔王留下的棋局，与好友一绝高下！\n\n");
		printf("详细操作：\n首先，红方先行运棋：根据屏幕上出现的指示完成运棋操作(注意：输入坐标时两个数值中间需用空格分开)，");
		printf("当完成红方运棋后，轮到蓝方运棋回合，同理，蓝") ;
		printf("方运棋结束后重复上述操作，直至一方的主帅被吃掉，游戏结束。快邀请您的好友一齐来下象棋吧！\n\n");
		printf("                                   (请输入 886 返回主菜单) 操作编号：");

		scanf("%d",&command_2);
		system("cls");

		if(command_2==886) {Show_menu();Get_command();}
		else {Error_hint();Instruction();}
}

void Draw_map(int map[19][18])//绘制棋盘和棋子 
{ 
	int i,j;
	
	printf("\n");//绘制棋盘上方提示
	printf("\n提示：            ");
	printf("(-ω-)直到把对方的\033[41m帅\033[0m/\033[46m将\033[0m吃掉才算胜利哦（若需返回主菜单请输入 886 886 ）\n\n");
	printf("                                                  蓝方\n"); 
	for(i = 0;i < 19;i++)
	{
		printf ("                               ");	
		for (j = 0;j < 18;j ++)
		{
			if(map[i][j]>=0&&map[i][j]<=9)//用特殊符号绘制棋盘框架
			{
			switch(map[i][j]){
			case 0:
				if(i == 0 && j == 1) {printf ("╔ "); break;}
				else if (i == 0 && j == 17) {printf ("╗"); break;}
				else if (i == 18 && j == 1) {printf ("╚ "); break;}
				else if (i == 18 && j == 17) {printf ("╝"); break;}
	    		else if (i != 0 && j == 1 || i != 18 && j == 1 ) {printf ("╟ "); break;}
	    		else if (i != 0 && j == 17 || i != 18 && j == 17 ) {printf ("╢"); break;}
	    		else if (i == 2 && j ==9 || i == 16 && j == 9) {printf ("╳ "); break;}
	    		else if (i == 0 && j != 1 || i == 10 && j != 1) {printf ("╤ "); break;}
	    		else if (i == 18 && j != 1 || i == 8 && j != 17) {printf("╧ "); break;}
				else{printf ("┼ "); break; }
			case 1:
				if(i==0||i==18) {printf("═ ");break;}
				else if (j==1) {printf("║");break;}
				else if (j==17) {printf(" ║");break;}
				else if(j==1||j==3||j==5||j==7||j==9||j==11||j==13||j==15)
				{
					if(i!=0&&i!=18)
					{printf(" │");break;}
			
				}
				else if(i==2||i==4||i==6||i==12||i==14||i==16)
				{
					if (j!=1&&j!=17) {printf("──");break;}	 
				}
				else if(i==8||i==10) {printf("══");break;}
				else {printf("  ");break;}
			case 2:
				printf("楚"); break; 
			case 3:
				printf("河"); break; 
			case 4:
				printf("汉"); break; 
			case 5:
				printf("界"); break;
			case 6:
				printf ("  "); break;
			case 7:
				printf("★"); break;} 
			}
			else
			{
				switch(map[i][j])//棋盘左侧y轴坐标提示
				{
					case 101:
						printf("9   ");break;
					case 102:
						printf("    ");break;
					case 103:
						printf("8   ");break;
					case 104:
						printf("7   ");break;
					case 105:
						printf("6   ");break;
					case 106:
						printf("5   ");break;
					case 107:
						printf("4   ");break;
					case 108:
						printf("3   ");break;
					case 109:
						printf("2   ");break;
					case 110:
						printf("1   ");break;
					case 'a':
						printf("\033[41m兵\033[0m");break;//根据二维数组数据输出棋子
					case 'A':
						printf("\033[46m卒\033[0m");break;
					case 'b':
						printf("\033[41m炮\033[0m");break;
					case 'B':
						printf("\033[46m砲\033[0m");break;
					case 'c':
						printf("\033[41m车\033[0m");break;
					case 'C':
						printf("\033[46m車\033[0m");break;
					case 'd':
						printf("\033[41m马\033[0m");break;
					case 'D':
						printf("\033[46m馬\033[0m");break;
					case 'p':
						printf("\033[41m相\033[0m");break;
					case 'E':
						printf("\033[46m象\033[0m");break;
					case 's':
						printf("\033[41m士\033[0m");break;
					case 'F':
						printf("\033[46m仕\033[0m");break;
						case 'z':
						printf("\033[41m帅\033[0m");break;
					case 'G':
						printf("\033[46m将\033[0m");break;	
				}
			}
		}
		printf("\n");
	}
		printf("                                                  红方\n");
		printf("                               0       1   2   3   4   5   6   7   8\n\n");	//棋盘下方x轴坐标提示
}
	
void Error_hint()//输出操作错误时的提示
{
	printf("\n                          （⊙—⊙）属下没有找到该序号对应的操作,请大人再试一次\n");
} 

void Self_hint()//吃自己的子警告
{
	printf("\n！警告！：                         (←_←)大人！您不能吃掉自己的棋子\n"); 
} 

void Rule_hint()//棋子的移动不符合棋法警告
{
	printf("\n！警告！：                         (←_←)大人！您这样运棋是不合法的\n");
} 

void Object_hint()////擅动对方棋子警告 
{
	printf("\n！警告！：                         (←_←)大人！您不能移动对方的棋子\n") ;
} 

void Gap_hint()//该坐标没有棋子提醒 
{
	printf("\n！警告！：                  (→_→)大人您输入的坐标没有棋子，还请您认真一点\n"); 
}

void Go_on(int map[19][18])//判断游戏是否结束
{
	int i,j;

	int flag_1=0,flag_2=0; //作为输赢条件的标记
		
	for(i = 0;i < 19;i++)
	{	
		for (j = 0;j < 18;j ++)	
		{
			if(map[i][j]=='z') {flag_1=1;}
			else if(map[i][j]=='G') {flag_2=1;}
			else {continue;}	
		}
	} 
		if(flag_1==0&&flag_2==1)
		{
			system("cls");

			printf("\n                                （﹩O﹩）本局游戏结束！恭喜蓝方获胜！\n");
			printf("\n                                           已为您返回主菜单");
			
			Show_menu();Get_command();
		}
		else if(flag_1==1&&flag_2==0)
		{
			system("cls");

			printf("\n                                （@ O @）本局游戏结束！恭喜红方获胜！\n");
			printf("\n                                           已为您返回主菜单");

			Show_menu();Get_command();
		}
		else 	{flag_1=0;flag_2=0;}	
} 

void Blue_move(int map[19][18])//实现蓝方玩家对棋子的移动 
{
		int first_1;int first_2;int end_1;int end_2;int y_1,x_1,y_2,x_2;//接收玩家输入的坐标信息
		
		printf("现在请\033[46m蓝\033[0m方运棋               (⊙+⊙)请大人输入您想要移动的棋子坐标：");  
		scanf("%d %d",&first_1,&first_2 );
		
		if(first_1==886||first_2==886)//判断玩家是否退出 
			{system("cls");Show_menu();Get_command();}
			
		printf("                             (> O <)现在输入您想要让棋子到达的坐标：");
		scanf("%d %d",&end_1 ,&end_2 );
		
		if(end_1==886||end_2==886)//判断玩家是否退出 
			{system("cls");Show_menu();Get_command();}
			
		system("cls");
		
		if(first_1==0) {x_1=1;}  //转化玩家输入的数据为对应二维数组的坐标 
		else if(first_1==1) {x_1=3;}      else if(first_1==2) {x_1=5;}
		else if(first_1==3) {x_1=7;}      else if(first_1==4) {x_1=9;}
		else if(first_1==5) {x_1=11;}     else if(first_1==6) {x_1=13;}
		else if(first_1==7) {x_1=15;}     else if(first_1==8) {x_1=17;}
		else {Gap_hint();}
		
		if(first_2==0) {y_1=18;}
		else if(first_2==1) {y_1=16;}     else if(first_2==2) {y_1=14;}	
		else if(first_2==3) {y_1=12;}     else if(first_2==4) {y_1=10;} 
		else if(first_2==5) {y_1=8;}      else if(first_2==6) {y_1=6;}
		else if(first_2==7) {y_1=4;}      else if(first_2==8) {y_1=2;}     else if(first_2==9) {y_1=0;}
		else {Gap_hint();}
		
		if(end_1==0) {x_2=1;}
		else if(end_1==1) {x_2=3;}        else if(end_1==2) {x_2=5;}
		else if(end_1==3) {x_2=7;}        else if(end_1==4) {x_2=9;}
		else if(end_1==5) {x_2=11;}       else if(end_1==6) {x_2=13;}
		else if(end_1==7) {x_2=15;}       else if(end_1==8) {x_2=17;}
		else {Gap_hint();}
		
		if(end_2==0) {y_2=18;}
		else if(end_2==1) {y_2=16;}		  else if(end_2==2) {y_2=14;}
     	else if(end_2==3) {y_2=12;}       else if(end_2==4) {y_2=10;}
		else if(end_2==5) {y_2=8;}        else if(end_2==6) {y_2=6;} 
		else if(end_2==7) {y_2=4;}        else if(end_2==8) {y_2=2;}        else if(end_2==9) {y_2=0;}
		else {Gap_hint();}
		
		Blue_rule(map,y_1,x_1,y_2,x_2);
}

void Red_move(int map[19][18])//实现红方玩家对棋子的移动
{
		int first_1;int first_2;int end_1;int end_2;int y_1,x_1,y_2,x_2;//接收玩家输入的坐标信息
		
		printf("现在请\033[41m红\033[0m方运棋               (⊙+⊙)请大人输入您想要移动的棋子坐标：");  
		scanf("%d %d",&first_1,&first_2 );
		
		if(first_1==886||first_2==886)//判断玩家是否退出 
			{system("cls");Show_menu();Get_command();}
			
		printf("                             (> O <)现在输入您想要让棋子到达的坐标：");
		scanf("%d %d",&end_1 ,&end_2 );
		
		if(end_1==886||end_2==886)//判断玩家是否退出 
			{system("cls");Show_menu();Get_command();}
			
		system("cls");
		
		if(first_1==0) {x_1=1;}  //转化玩家输入的数据为对应二维数组的坐标  
		else if(first_1==1) {x_1=3;}      else if(first_1==2) {x_1=5;}
		else if(first_1==3) {x_1=7;}      else if(first_1==4) {x_1=9;}
		else if(first_1==5) {x_1=11;}     else if(first_1==6) {x_1=13;}
		else if(first_1==7) {x_1=15;}     else if(first_1==8) {x_1=17;}
		else {Gap_hint();}
		
		if(first_2==0) {y_1=18;}
		else if(first_2==1) {y_1=16;}     else if(first_2==2) {y_1=14;}	
		else if(first_2==3) {y_1=12;}     else if(first_2==4) {y_1=10;} 
		else if(first_2==5) {y_1=8;}      else if(first_2==6) {y_1=6;}
		else if(first_2==7) {y_1=4;}      else if(first_2==8) {y_1=2;}     else if(first_2==9) {y_1=0;}
		else {Gap_hint();}
		
		if(end_1==0) {x_2=1;}
		else if(end_1==1) {x_2=3;}        else if(end_1==2) {x_2=5;}
		else if(end_1==3) {x_2=7;}        else if(end_1==4) {x_2=9;}
		else if(end_1==5) {x_2=11;}       else if(end_1==6) {x_2=13;}
		else if(end_1==7) {x_2=15;}       else if(end_1==8) {x_2=17;}
		else {Gap_hint();}
		
		if(end_2==0) {y_2=18;}
		else if(end_2==1) {y_2=16;}		  else if(end_2==2) {y_2=14;}
     	else if(end_2==3) {y_2=12;}       else if(end_2==4) {y_2=10;}
		else if(end_2==5) {y_2=8;}        else if(end_2==6) {y_2=6;} 
		else if(end_2==7) {y_2=4;}        else if(end_2==8) {y_2=2;}        else if(end_2==9) {y_2=0;}
		else {Gap_hint();} 
		
		Red_rule(map,y_1,x_1,y_2,x_2);
}

void Red_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2)//判断红棋移动是否合法
{	
		if(map[y_1][x_1]==0||map[y_1][x_1]==1||map[y_1][x_1]==2||map[y_1][x_1]==3) //判断玩家移动的目标是否为空白 
			{Gap_hint();Draw_map(map);Go_on(map);Red_move(map);}
			
		else if(map[y_1][x_1]==4||map[y_1][x_1]==5||map[y_1][x_1]==6||map[y_1][x_1]==7)
			{Gap_hint();Draw_map(map);Go_on(map);Red_move(map);}
			
		else if(map[y_1][x_1]==map[y_2][x_2]) //判断玩家是否不动
			{Gap_hint();Draw_map(map);Go_on(map);Red_move(map);}
			
		else 
		{
			if  (map[y_1][x_1]>='a'&&map[y_1][x_1]<='z')
			{
				if((map[y_2][x_2]>='a'&&map[y_2][x_2]<='z')&&(map[y_1][x_1]>='a'&&map[y_1][x_1]<='z'))//判断玩家是否想吃掉自己 
					{Self_hint();Draw_map(map);Go_on(map);Red_move(map);}
				else 
				{
					Move_rule(map,y_1, x_1, y_2, x_2);
					Draw_map(map);Go_on(map);Blue_move(map);
				}	
			}
			else if(map[y_1][x_1]>='A'&&map[y_1][x_1]<='Z')
			{
				Object_hint();
				Draw_map(map);Go_on(map);Red_move(map);
			}
		}

}

void Blue_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2)//判断蓝棋移动是否合法
{		
		if(map[y_1][x_1]==0||map[y_1][x_1]==1||map[y_1][x_1]==2||map[y_1][x_1]==3) //判断玩家移动的目标是否为空白 
			{Gap_hint();Draw_map(map);Go_on(map);Blue_move(map);}
			
		else if(map[y_1][x_1]==4||map[y_1][x_1]==5||map[y_1][x_1]==6||map[y_1][x_1]==7)
			{Gap_hint();Draw_map(map);Go_on(map);Blue_move(map);}
			
		else if(map[y_1][x_1]==map[y_2][x_2]) //判断玩家是否不动
			{Gap_hint();Draw_map(map);Go_on(map);Blue_move(map);}
			
		else
		{
			if(map[y_1][x_1]>='A'&&map[y_1][x_1]<='Z')
			{ 
				if((map[y_2][x_2]>='A'&&map[y_2][x_2]<='Z')&&(map[y_1][x_1]>='A'&&map[y_1][x_1]<='Z'))//判断玩家是否想吃掉自己 
					{Self_hint();Draw_map(map);Go_on(map);Blue_move(map);}
				else
				{
					Move_rule(map,y_1, x_1, y_2, x_2);
					Draw_map(map);Go_on(map);Red_move(map);
				}
			}
			else if(map[y_1][x_1]>='a'&&map[y_1][x_1]<='z')
			{
				Object_hint();
				Draw_map(map);Go_on(map);Blue_move(map); 
			}
		}
}

void Start_game()//游戏部分拼装+地图初始化 
{ 
	int map[19][18]=
	/*0*/{{101,'C',1,'D',1,'E',1,'F',1,'G',1,'F',1,'E',1,'D',1,'C'},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*2*/{103,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*4*/{104,0,1,'B',1,0,1,0,1,0,1,0,1,0,1,'B',1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*6*/{105,'A',1,0,1,'A',1,0,1,'A',1,0,1,'A',1,0,1,'A'},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*8*/{106,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{ 102,7,6,6,2,6,3,6,6,6,6,6,4,6,5,6,6,7 },
	/*10*/{107,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*12*/{108,'a',1,0,1,'a',1,0,1,'a',1,0,1,'a',1,0,1,'a'},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*14*/{109,0,1,'b',1,0,1,0,1,0,1,0,1,0,1,'b',1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*16*/{110,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*18*/{102,'c',1,'d',1,'p',1,'s',1,'z',1,'s',1,'p',1,'d',1,'c'}};
	while(1)
	{ 
		Draw_map(map);Red_move(map);
	}
}

void Files_command()//得到残局菜单命令 
{
	int command;
	 
	scanf("%d",&command);
	system("cls");

	if(command==1) {Files_1();}
	else if(command==2) {Files_2();}
	else if(command==3) {Files_3();}
	else if(command==4) {Files_4();}
	else if(command==886) {Show_menu();Get_command();}
	else {Error_hint();Files_menu();Files_command();}	 
} 

void Files_menu()//残局菜单
{
	printf("\n\n\n\n\n\n\n                                            ☆ 残局目录 ☆\n\n\n");
	printf("                                        1 ---  七星聚会  --- 1\n\n");
	printf("                                        2 ---  蚯蚓降龙  --- 2\n\n");
	printf("                                        3 ---  野马操田  --- 3\n\n");
	printf("                                        4 ---  千里独行  --- 4\n\n");
	printf("                                     886 ---  返回主菜单  --- 886\n\n\n");
	printf("                           （⊙ω⊙）请大人输入您想要读取的残局对应的序号：");
} 

void Files_1()//七星聚会 
{
	int map[19][18]=
	/*0*/{{101,0,1,0,1,0,1,0,1,'C',1,'G',1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*2*/{103,0,1,0,1,0,1,'a',1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*4*/{104,0,1,0,1,0,1,0,1,'E',1,'a',1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*6*/{105,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*8*/{106,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{ 102,7,6,6,2,6,3,6,6,6,6,6,4,6,5,6,6,7 },
	/*10*/{107,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*12*/{108,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,'a'},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*14*/{109,0,1,'A',1,0,1,0,1,'A',1,0,1,0,1,'b',1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*16*/{110,0,1,0,1,0,1,'A',1,0,1,'A',1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*18*/{102,0,1,0,1,0,1,0,1,'z',1,0,1,'c',1,'c',1,0}};
	
	while(1)
	{ 
		Draw_map(map);Go_on(map);Red_move(map);
	}
} 

void Files_2()//蚯蚓降龙 
{
	int map[19][18]=
	/*0*/{{101,0,1,0,1,0,1,'F',1,'G',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*2*/{103,0,1,0,1,0,1,0,1,'F',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*4*/{104,0,1,0,1,0,1,0,1,'E',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*6*/{105,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*8*/{106,0,1,0,1,'A',1,0,1,0,1,0,1,0,1,0,1,0},
	{ 102,7,6,6,2,6,3,6,6,6,6,6,4,6,5,6,6,7 },
	/*10*/{107,0,1,0,1,0,1,0,1,0,1,'c',1,0,1,0,1,'a'},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*12*/{108,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*14*/{109,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*16*/{110,0,1,0,1,0,1,0,1,'A',1,0,1,'A',1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*18*/{102,0,1,0,1,0,1,0,1,0,1,'z',1,0,1,0,1,'c'}};
	
	while(1)
	{ 
		Draw_map(map);Go_on(map);Red_move(map);
	}
}

void Files_3()//野马操田
{
	int map[19][18]=
	/*0*/{{101,0,1,0,1,'E',1,'F',1,'G',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*2*/{103,0,1,0,1,0,1,0,1,'F',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*4*/{104,0,1,0,1,0,1,0,1,'E',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*6*/{105,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*8*/{106,0,1,0,1,0,1,0,1,0,1,0,1,'d',1,'c',1,'c'},
	{ 102,7,6,6,2,6,3,6,6,6,6,6,4,6,5,6,6,7 },
	/*10*/{107,0,1,0,1,'p',1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*12*/{108,0,1,'C',1,'a',1,0,1,'a',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*14*/{109,0,1,0,1,0,1,'A',1,'p',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*16*/{110,0,1,0,1,0,1,0,1,'A',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*18*/{102,0,1,0,1,0,1,'z',1,0,1,0,1,0,1,0,1,0}};
	
	while(1)
	{ 
		Draw_map(map);Go_on(map);Red_move(map);
	}	
} 

void Files_4()//千里独行
{
	int map[19][18]=
	/*0*/{{101,0,1,0,1,0,1,0,1,'G',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*2*/{103,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*4*/{104,0,1,0,1,0,1,'F',1,'a',1,0,1,0,1,0,1,'E'},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*6*/{105,'A',1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*8*/{106,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
	{ 102,7,6,6,2,6,3,6,6,6,6,6,4,6,5,6,6,7 },
	/*10*/{107,0,1,0,1,0,1,0,1,0,1,0,1,'D',1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*12*/{108,0,1,0,1,'a',1,0,1,0,1,0,1,'A',1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*14*/{109,0,1,0,1,0,1,0,1,'c',1,0,1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*16*/{110,0,1,0,1,0,1,'A',1,0,1,'A',1,0,1,0,1,0},
	{102,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	/*18*/{102,0,1,0,1,0,1,0,1,'z',1,0,1,0,1,0,1,0}};
	
	while(1)
	{ 
		Draw_map(map);Go_on(map);Red_move(map);
	}
}
