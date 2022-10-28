#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ruleHead.h"


void Move_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2)//录入每个棋子的运棋规则 
{
	switch(map[y_1][x_1]) 
	{
		case 'a':
			Red_pawn( map, y_1, x_1, y_2, x_2);break;//红兵
		case 'A':
			Blue_pawn( map, y_1, x_1, y_2, x_2);break;//蓝卒
		case 'c':
			Red_car( map, y_1, x_1, y_2, x_2);break;//红车
		case 'C':
			Blue_car( map, y_1, x_1, y_2, x_2);break;//黑車
		case 'd':
			Red_horse(map, y_1, x_1, y_2, x_2);break;//红马
		case 'D':
			Blue_horse(map, y_1, x_1, y_2, x_2);break;//黑馬
		case 'p':
			Red_elephant(map, y_1, x_1, y_2, x_2);break;//红象
		case 'E':
			Blue_elephant(map, y_1, x_1, y_2, x_2);break;//黑象
		case 's':
			Red_man(map, y_1, x_1, y_2, x_2);break;//红士
		case 'F':
			Blue_man(map, y_1, x_1, y_2, x_2);break;//黑仕
		case 'z':
			Red_boss(map, y_1, x_1, y_2, x_2);break;//红帅
		case 'G':
			Blue_boss(map, y_1, x_1, y_2, x_2);break;//黑将
		case 'b':
			Red_gun(map, y_1, x_1, y_2, x_2);break;//红炮
		case 'B':
			Blue_gun(map, y_1, x_1, y_2, x_2);break;//黑砲
	}
}

void Red_pawn(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 兵 的规则 
{
				if(y_1==10||y_1==12)//在己方棋盘时的情况
			{	
				if(x_1==x_2&&y_2==(y_1-2))
				{
					map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
					Draw_map(map);Go_on(map);Blue_move(map);
				}
				else
				{
					Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
				}
			} 
			else//进入对方棋盘后的情况
			{
				if((y_2==(y_1-2)&&x_1==x_2)||(y_2==y_1&&x_2==(x_1-2)))
				{
					map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
					Draw_map(map);Go_on(map);Blue_move(map);
				}
				else
				{
					Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
				}
			}
}

void Blue_pawn(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 卒 的规则
{

			if(y_1==6||y_1==8)//在己方棋盘时的情况
			{	
				if(x_1==x_2&&y_2==(y_1+2))
				{
					map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
					Draw_map(map);Go_on(map);Red_move(map);
				}
				else
				{
					Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
				}
			} 
			else//进入对方棋盘后的情况
			{
				if((y_2==(y_1+2)&&x_1==x_2)||(y_2==y_1&&x_2==(x_1+2)))
				{
					map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
					Draw_map(map);Go_on(map);Red_move(map);
				}
				else
				{
					Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
				}
			} 
}

void Red_gun(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 炮 的规则 
{
	int i,j,flag=0,n=0;

	if(y_1==y_2)//左右移动时的情况
	{
		if(x_2>x_1)//右
		{
			for(j=x_1;j<=x_2;j++)//判断炮是否正常移动或隔子打子
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else//左
		{
			for(j=x_1;j>=x_2;j--)//判断炮是否正常移动或隔子打子
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
	} 
	else if(x_1==x_2)//上下移动的情况
	{
		if(y_2>y_1)//下
		{
			for(i=y_1;i<=y_2;i++)//判断炮是否正常移动或隔子打子
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
			else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		} 
		else//上
		{
			for(i=y_1;i>=y_2;i--)//判断炮是否正常移动或隔子打子
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
			else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
	}
	else
	{
		Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
	}
}

void Blue_gun(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 砲 的规则 
{
	int i,j,flag=0,n=0;

	if(y_1==y_2)//左右移动时的情况
	{
		if(x_2>x_1)//右
		{
			for(j=x_1;j<=x_2;j++)//判断砲是否正常移动或隔子打子
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else//左
		{
			for(j=x_1;j>=x_2;j--)//判断砲是否正常移动或隔子打子
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
	} 
	else if(x_1==x_2)//上下移动的情况
	{
		if(y_2>y_1)//下
		{
			for(i=y_1;i<=y_2;i++)//判断砲是否正常移动或隔子打子
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
			else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Blue_move(map);
			}
		} 
		else//上
		{
			for(i=y_1;i>=y_2;i--)//判断砲是否正常移动或隔子打子
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
			else
				{flag=1;n++;}
			}
			if((flag==1&&n==3)||(flag==1&&n==1))
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
	}
	else
	{
		Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
	}	 
}

void Red_car(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 车 的规则 
{
	int i,j,flag=0;

	if(y_1==y_2)//左右移动时的情况
	{
		if(x_2>x_1)//右
		{
			for(j=x_1+1;j<x_2;j++)//限制车的走位（不能隔子打子）
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else//左
		{
			for(j=x_1-1;j>x_2;j--)//限制车的走位（不能隔子打子）
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
	} 
	else if(x_1==x_2)//上下移动的情况
	{
		if(y_2>y_1)//下
		{
			for(i=y_1+1;i<y_2;i++)//限制车的走位（不能隔子打子）
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
			else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Red_move(map);
			}
		} 
		else//上
		{
			for(i=y_1-1;i>y_2;i--)//限制车的走位（不能隔子打子）
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
				else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Red_move(map);
			}
		}
	}
	else
	{
		Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
	}	
}

void Blue_car(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 車 的规则 
{

	int i,j,flag=0;

	if(y_1==y_2)//左右移动的情况
	{
		if(x_2>x_1)//右
		{
			for(j=x_1+1;j<x_2;j++)//限制車的走位（不能隔子打子）
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else//左
		{
			for(j=x_1-1;j>x_2;j--)//限制車的走位（不能隔子打子）
			{
				if((map[y_1][j])==0||(map[y_1][j])==1)
				{continue;}
				else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
	} 
	else if(x_1==x_2)//上下移动的情况
	{
		if(y_2>y_1)//下
		{
			for(i=y_1+1;i<y_2;i++)//限制車的走位（不能隔子打子）
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
			else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		} 
		else//上
		{
			for(i=y_1-1;i>y_2;i--)//限制車的走位（不能隔子打子）
			{
			if((map[i][x_1])==0||(map[i][x_1])==1||(map[i][x_1])==2||(map[i][x_1])==3||(map[i][x_1])==4||(map[i][x_1])==5||(map[i][x_1])==6||(map[i][x_1])==7)
				{continue;}
				else
				{flag=1;}
			}
			if(flag==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint(); Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
	}
	else
	{
		Rule_hint(); Draw_map(map);Go_on(map);Blue_move(map);
	} 
}

void Red_horse(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 马 的规则
{
	double a=20;
	double move_long=sqrt(a); 
	double flag;

	flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//马的移动长度的平方

	if((sqrt(flag))==move_long)//计算并判断马的移动长度
	{
	if (x_2>x_1) //向右方移动的情况
	{
		if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//正右方
		{
			if(map[y_1][x_1+2]==0)//判断马脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//右上方
		{
			if(map[y_1-2][x_1]==0)//判断马脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}	
		}
		else//右下方
		{
			if(map[y_1+2][x_1]==0)//判断马脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}			
		}
	}
	else//向左方移动的情况
	{
			if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//正左方
		{
			if(map[y_1][x_1-2]==0)//判断马脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//左上方
		{
			if(map[y_1-2][x_1]==0)//判断马脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}	
		}
		else//左下方
		{
			if(map[y_1+2][x_1]==0)//判断马脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}			
		}
	}
	}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
}

void Blue_horse(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 馬 的规则
{	

	double a=20;
	double move_long=sqrt(a); 
	double flag;

	flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//馬的移动长度的平方

	if((sqrt(flag))==move_long)//计算并判断馬的移动长度
	{
	if (x_2>x_1) //向右方移动的情况
	{
		if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//正右方
		{
			if(map[y_1][x_1+2]==0)//判断馬脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//右上方
		{
			if(map[y_1-2][x_1]==0)//判断馬脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}	
		}
		else//右下方
		{
			if(map[y_1+2][x_1]==0)//判断馬脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}			
		}
	}
	else//向左方移动的情况
	{
			if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//正左方
		{
			if(map[y_1][x_1-2]==0)//判断馬脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//左上方
		{
			if(map[y_1-2][x_1]==0)//判断馬脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}	
		}
		else//左下方
		{
			if(map[y_1+2][x_1]==0)//判断馬脚
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}			
		}
	}
	}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			} 
}

void Red_elephant(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 相 的规则
{
	double a=32;
	double move_long=sqrt(a); 
	double flag;

	if(y_2>=10)//限制相不能过河
	{
	if(y_2>y_1&&x_2>x_1)//向右下方移动
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//相移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断相的移动长度
		{
			if(map[y_1+2][x_1+2]==0)//判断相心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	} 
	else if(y_2<y_1&&x_2>x_1)//向右上方移动
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_1-y_2)*(y_1-y_2));//相移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断相的移动长度
		{
			if(map[y_1-2][x_1+2]==0)//判断相心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	}
	else if(y_1>y_2&&x_1>x_2)//向左下方移动
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2));//相移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断相的移动长度
		{
			if(map[y_1-2][x_1-2]==0)
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	}
	else//向左上方移动
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_2-y_1)*(y_2-y_1));//相移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断相的移动长度
		{
			if(map[y_1+2][x_1-2]==0)//判断相心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	}
	}
else
{
	Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
}
}

void Blue_elephant(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 象 的规则
{
	double a=32;
	double move_long=sqrt(a); 
	double flag;

	if(y_2<=8)//限制象不能过河
	{
	if(y_2>y_1&&x_2>x_1)//向右下方移动
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//象移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断象的移动长度
		{
			if(map[y_1+2][x_1+2]==0)//判断象心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	} 
	else if(y_2<y_1&&x_2>x_1)
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_1-y_2)*(y_1-y_2));//象移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断象的移动长度
		{
			if(map[y_1-2][x_1+2]==0)//判断象心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	}
	else if(y_1>y_2&&x_1>x_2)
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2));//象移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断象的移动长度
		{
			if(map[y_1-2][x_1-2]==0)//判断象心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	}
	else
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_2-y_1)*(y_2-y_1));//象移动长度的平方

		if((sqrt(flag))==move_long)//计算并判断象的移动长度
		{
			if(map[y_1+2][x_1-2]==0)//判断象心
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	}
	}
	else
	{
	Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
	} 
}

void Red_man(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 士 的规则
{
	double a=8;
	double move_long=sqrt(a); 
	double flag;

	if((x_2>=7&&x_2<=11)&&(y_2>=14&&y_2<=18))//限制士不能出九宫
{
	if(y_2>y_1&&x_2>x_1)//右下方
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	} 
	else if(y_2<y_1&&x_2>x_1)//右上方
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_1-y_2)*(y_1-y_2));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	}
	else if(y_1>y_2&&x_1>x_2)//左下方
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	}
	else//左上方
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_2-y_1)*(y_2-y_1));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
		}
	}
}
else
{
	Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
}
}

void Blue_man(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 仕 的规则
{

	double a=8;
	double move_long=sqrt(a); 
	double flag;

	if((x_2>=7&&x_2<=11)&&(y_2>=0&&y_2<=4))//限制仕不能出九宫
{
	if(y_2>y_1&&x_2>x_1)//右上方
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	} 
	else if(y_2<y_1&&x_2>x_1)//右上方
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_1-y_2)*(y_1-y_2));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	}
	else if(y_1>y_2&&x_1>x_2)//左下方
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	}
	else//左上方
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_2-y_1)*(y_2-y_1));
		if((sqrt(flag))==move_long)
		{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
		}
		else
		{
			Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
		}
	}
}
else
{
	Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
} 
}

void Red_boss(int map[19][18],int y_1,int x_1,int y_2,int x_2)//红方 帅 的规则
{
	if((x_2<=11&&x_2>=7)&&(y_2<=18&&y_2>=14))//限制帅不能够出九宫
	{
				if((y_2==(y_1+2)&&x_1==x_2)||(y_2==y_1&&x_2==x_1+2)||(y_2==(y_1-2)&&x_1==x_2)||(y_2==y_1&&x_2==x_1-2))
				{
					map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
					Draw_map(map);Go_on(map);Blue_move(map);
				}
				else
				{
					Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
				}	
	}
	else
	{
		Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
	}
}

void Blue_boss(int map[19][18],int y_1,int x_1,int y_2,int x_2)//蓝方 将 的规则
{	
		if((x_2<=11&&x_2>=7)&&(y_2<=4&&y_2>=0))//限制将不能够出九宫
	{
				if((y_2==(y_1+2)&&x_1==x_2)||(y_2==y_1&&x_2==x_1+2)||(y_2==(y_1-2)&&x_1==x_2)||(y_2==y_1&&x_2==x_1-2))
				{
					map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
					Draw_map(map);Go_on(map);Red_move(map);
				}
				else
				{
					Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
				}	
	}
	else
	{
		Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
	} 
}
