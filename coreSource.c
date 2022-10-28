#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coreHead.h"

void Show_menu()//���Ʋ˵� 
{ 
	printf("\n\n\n\n\n\n\n                                            �� ˫������ ��\n\n\n");
	printf("                                        1 ---  ���¿�ʼ  --- 1\n\n");
	printf("                                        2 ---  �о���ս  --- 2\n\n");
	printf("                                        3 ---  ��Ϸ����  --- 3\n\n");
	printf("                                        4 ---  �˳���Ϸ  --- 4\n\n\n");
	printf("                          ���Ѧءѣ��������������Ҫ��ɵĲ�����Ӧ����ţ�"); 
}

void Get_command()//�õ����˵�����
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
 
void Out_game()//�˳���Ϸ���� 
{
	int command_1;

	system("cls");
	
	printf("\n\n                                       (�� ��)����ȷ��Ҫ�뿪����\n\n\n");//��������Ƿ�ȷ���˳�
	printf("                                          886 --- ���� --- 886\n\n");
	printf("                                 ����������� --- �˳� --- �����������\n\n");
	printf("                                             ��������ţ�");

	scanf("%d",&command_1);
	system("cls");

	if(command_1==886) {Show_menu();Get_command();}
	else {printf("\n\n                               ~ ( T _ T ) �����ټ�����������������\n");exit(0);}
}

void Instruction() //��ʾ��Ϸ˵��
{ 
		int command_2; 

		printf("\n                                              ����ھ�\n");
		printf("                                    ��������Ź��ڣ�ʿֹ���治���١�\n");
		printf("                                    ����ķ�Ӫ�Ľǣ�����һ��һ��塣\n");
		printf("                                    ������Ӵ�һ�ӣ�����ֱ·��������\n");
		printf("                                    Ψ��ֻ����һ�������Ӻ�������١�\n"); 
		printf("\n\nChinese Chess ��һ��˫������С��Ϸ��ѡ�����¿�ʼ�����˿�������ѿ���һ����Ȥ���й��������;");
		printf(" ѡ���ȡ�浵�����˿��Զ�ȡ��ս��¼������ѽ���δ��ɵĶԾ�;ѡ��о���ս��������ǰ����������");
		printf("����ڶ�ħ�����µ���֣������һ�����£�\n\n");
		printf("��ϸ������\n���ȣ��췽�������壺������Ļ�ϳ��ֵ�ָʾ����������(ע�⣺��������ʱ������ֵ�м����ÿո�ֿ�)��");
		printf("����ɺ췽������ֵ���������غϣ�ͬ������") ;
		printf("������������ظ�����������ֱ��һ������˧���Ե�����Ϸ���������������ĺ���һ����������ɣ�\n\n");
		printf("                                   (������ 886 �������˵�) ������ţ�");

		scanf("%d",&command_2);
		system("cls");

		if(command_2==886) {Show_menu();Get_command();}
		else {Error_hint();Instruction();}
}

void Draw_map(int map[19][18])//�������̺����� 
{ 
	int i,j;
	
	printf("\n");//���������Ϸ���ʾ
	printf("\n��ʾ��            ");
	printf("(-��-)ֱ���ѶԷ���\033[41m˧\033[0m/\033[46m��\033[0m�Ե�����ʤ��Ŷ�����践�����˵������� 886 886 ��\n\n");
	printf("                                                  ����\n"); 
	for(i = 0;i < 19;i++)
	{
		printf ("                               ");	
		for (j = 0;j < 18;j ++)
		{
			if(map[i][j]>=0&&map[i][j]<=9)//��������Ż������̿��
			{
			switch(map[i][j]){
			case 0:
				if(i == 0 && j == 1) {printf ("�X "); break;}
				else if (i == 0 && j == 17) {printf ("�["); break;}
				else if (i == 18 && j == 1) {printf ("�^ "); break;}
				else if (i == 18 && j == 17) {printf ("�a"); break;}
	    		else if (i != 0 && j == 1 || i != 18 && j == 1 ) {printf ("�c "); break;}
	    		else if (i != 0 && j == 17 || i != 18 && j == 17 ) {printf ("�f"); break;}
	    		else if (i == 2 && j ==9 || i == 16 && j == 9) {printf ("�w "); break;}
	    		else if (i == 0 && j != 1 || i == 10 && j != 1) {printf ("�h "); break;}
	    		else if (i == 18 && j != 1 || i == 8 && j != 17) {printf("�k "); break;}
				else{printf ("�� "); break; }
			case 1:
				if(i==0||i==18) {printf("�T ");break;}
				else if (j==1) {printf("�U");break;}
				else if (j==17) {printf(" �U");break;}
				else if(j==1||j==3||j==5||j==7||j==9||j==11||j==13||j==15)
				{
					if(i!=0&&i!=18)
					{printf(" ��");break;}
			
				}
				else if(i==2||i==4||i==6||i==12||i==14||i==16)
				{
					if (j!=1&&j!=17) {printf("����");break;}	 
				}
				else if(i==8||i==10) {printf("�T�T");break;}
				else {printf("  ");break;}
			case 2:
				printf("��"); break; 
			case 3:
				printf("��"); break; 
			case 4:
				printf("��"); break; 
			case 5:
				printf("��"); break;
			case 6:
				printf ("  "); break;
			case 7:
				printf("��"); break;} 
			}
			else
			{
				switch(map[i][j])//�������y��������ʾ
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
						printf("\033[41m��\033[0m");break;//���ݶ�ά���������������
					case 'A':
						printf("\033[46m��\033[0m");break;
					case 'b':
						printf("\033[41m��\033[0m");break;
					case 'B':
						printf("\033[46m�h\033[0m");break;
					case 'c':
						printf("\033[41m��\033[0m");break;
					case 'C':
						printf("\033[46m܇\033[0m");break;
					case 'd':
						printf("\033[41m��\033[0m");break;
					case 'D':
						printf("\033[46m�R\033[0m");break;
					case 'p':
						printf("\033[41m��\033[0m");break;
					case 'E':
						printf("\033[46m��\033[0m");break;
					case 's':
						printf("\033[41mʿ\033[0m");break;
					case 'F':
						printf("\033[46m��\033[0m");break;
						case 'z':
						printf("\033[41m˧\033[0m");break;
					case 'G':
						printf("\033[46m��\033[0m");break;	
				}
			}
		}
		printf("\n");
	}
		printf("                                                  �췽\n");
		printf("                               0       1   2   3   4   5   6   7   8\n\n");	//�����·�x��������ʾ
}
	
void Error_hint()//�����������ʱ����ʾ
{
	printf("\n                          ���ѡ��ѣ�����û���ҵ�����Ŷ�Ӧ�Ĳ���,���������һ��\n");
} 

void Self_hint()//���Լ����Ӿ���
{
	printf("\n�����棡��                         (��_��)���ˣ������ܳԵ��Լ�������\n"); 
} 

void Rule_hint()//���ӵ��ƶ��������巨����
{
	printf("\n�����棡��                         (��_��)���ˣ������������ǲ��Ϸ���\n");
} 

void Object_hint()////�ö��Է����Ӿ��� 
{
	printf("\n�����棡��                         (��_��)���ˣ��������ƶ��Է�������\n") ;
} 

void Gap_hint()//������û���������� 
{
	printf("\n�����棡��                  (��_��)���������������û�����ӣ�����������һ��\n"); 
}

void Go_on(int map[19][18])//�ж���Ϸ�Ƿ����
{
	int i,j;

	int flag_1=0,flag_2=0; //��Ϊ��Ӯ�����ı��
		
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

			printf("\n                                ����O����������Ϸ��������ϲ������ʤ��\n");
			printf("\n                                           ��Ϊ���������˵�");
			
			Show_menu();Get_command();
		}
		else if(flag_1==1&&flag_2==0)
		{
			system("cls");

			printf("\n                                ��@ O @��������Ϸ��������ϲ�췽��ʤ��\n");
			printf("\n                                           ��Ϊ���������˵�");

			Show_menu();Get_command();
		}
		else 	{flag_1=0;flag_2=0;}	
} 

void Blue_move(int map[19][18])//ʵ��������Ҷ����ӵ��ƶ� 
{
		int first_1;int first_2;int end_1;int end_2;int y_1,x_1,y_2,x_2;//������������������Ϣ
		
		printf("������\033[46m��\033[0m������               (��+��)�������������Ҫ�ƶ����������꣺");  
		scanf("%d %d",&first_1,&first_2 );
		
		if(first_1==886||first_2==886)//�ж�����Ƿ��˳� 
			{system("cls");Show_menu();Get_command();}
			
		printf("                             (> O <)������������Ҫ�����ӵ�������꣺");
		scanf("%d %d",&end_1 ,&end_2 );
		
		if(end_1==886||end_2==886)//�ж�����Ƿ��˳� 
			{system("cls");Show_menu();Get_command();}
			
		system("cls");
		
		if(first_1==0) {x_1=1;}  //ת��������������Ϊ��Ӧ��ά��������� 
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

void Red_move(int map[19][18])//ʵ�ֺ췽��Ҷ����ӵ��ƶ�
{
		int first_1;int first_2;int end_1;int end_2;int y_1,x_1,y_2,x_2;//������������������Ϣ
		
		printf("������\033[41m��\033[0m������               (��+��)�������������Ҫ�ƶ����������꣺");  
		scanf("%d %d",&first_1,&first_2 );
		
		if(first_1==886||first_2==886)//�ж�����Ƿ��˳� 
			{system("cls");Show_menu();Get_command();}
			
		printf("                             (> O <)������������Ҫ�����ӵ�������꣺");
		scanf("%d %d",&end_1 ,&end_2 );
		
		if(end_1==886||end_2==886)//�ж�����Ƿ��˳� 
			{system("cls");Show_menu();Get_command();}
			
		system("cls");
		
		if(first_1==0) {x_1=1;}  //ת��������������Ϊ��Ӧ��ά���������  
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

void Red_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�жϺ����ƶ��Ƿ�Ϸ�
{	
		if(map[y_1][x_1]==0||map[y_1][x_1]==1||map[y_1][x_1]==2||map[y_1][x_1]==3) //�ж�����ƶ���Ŀ���Ƿ�Ϊ�հ� 
			{Gap_hint();Draw_map(map);Go_on(map);Red_move(map);}
			
		else if(map[y_1][x_1]==4||map[y_1][x_1]==5||map[y_1][x_1]==6||map[y_1][x_1]==7)
			{Gap_hint();Draw_map(map);Go_on(map);Red_move(map);}
			
		else if(map[y_1][x_1]==map[y_2][x_2]) //�ж�����Ƿ񲻶�
			{Gap_hint();Draw_map(map);Go_on(map);Red_move(map);}
			
		else 
		{
			if  (map[y_1][x_1]>='a'&&map[y_1][x_1]<='z')
			{
				if((map[y_2][x_2]>='a'&&map[y_2][x_2]<='z')&&(map[y_1][x_1]>='a'&&map[y_1][x_1]<='z'))//�ж�����Ƿ���Ե��Լ� 
					{Self_hint();Draw_map(map);Go_on(map);Red_move(map);}
				else 
				{
	//				Move_rule(map,y_1, x_1, y_2, x_2);
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

void Blue_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�ж������ƶ��Ƿ�Ϸ�
{		
		if(map[y_1][x_1]==0||map[y_1][x_1]==1||map[y_1][x_1]==2||map[y_1][x_1]==3) //�ж�����ƶ���Ŀ���Ƿ�Ϊ�հ� 
			{Gap_hint();Draw_map(map);Go_on(map);Blue_move(map);}
			
		else if(map[y_1][x_1]==4||map[y_1][x_1]==5||map[y_1][x_1]==6||map[y_1][x_1]==7)
			{Gap_hint();Draw_map(map);Go_on(map);Blue_move(map);}
			
		else if(map[y_1][x_1]==map[y_2][x_2]) //�ж�����Ƿ񲻶�
			{Gap_hint();Draw_map(map);Go_on(map);Blue_move(map);}
			
		else
		{
			if(map[y_1][x_1]>='A'&&map[y_1][x_1]<='Z')
			{ 
				if((map[y_2][x_2]>='A'&&map[y_2][x_2]<='Z')&&(map[y_1][x_1]>='A'&&map[y_1][x_1]<='Z'))//�ж�����Ƿ���Ե��Լ� 
					{Self_hint();Draw_map(map);Go_on(map);Blue_move(map);}
				else
				{
	//				Move_rule(map,y_1, x_1, y_2, x_2);
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

void Start_game()//��Ϸ����ƴװ+��ͼ��ʼ�� 
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

void Files_command()//�õ��оֲ˵����� 
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

void Files_menu()//�оֲ˵�
{
	printf("\n\n\n\n\n\n\n                                            �� �о�Ŀ¼ ��\n\n\n");
	printf("                                        1 ---  ���Ǿۻ�  --- 1\n\n");
	printf("                                        2 ---  ��򾽵��  --- 2\n\n");
	printf("                                        3 ---  Ұ������  --- 3\n\n");
	printf("                                        4 ---  ǧ�����  --- 4\n\n");
	printf("                                     886 ---  �������˵�  --- 886\n\n\n");
	printf("                           ���Ѧءѣ��������������Ҫ��ȡ�Ĳоֶ�Ӧ����ţ�");
} 

void Files_1()//���Ǿۻ� 
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

void Files_2()//��򾽵�� 
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

void Files_3()//Ұ������
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

void Files_4()//ǧ�����
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
