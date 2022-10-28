#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ruleHead.h"


void Move_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2)//¼��ÿ�����ӵ�������� 
{
	switch(map[y_1][x_1]) 
	{
		case 'a':
			Red_pawn( map, y_1, x_1, y_2, x_2);break;//���
		case 'A':
			Blue_pawn( map, y_1, x_1, y_2, x_2);break;//����
		case 'c':
			Red_car( map, y_1, x_1, y_2, x_2);break;//�쳵
		case 'C':
			Blue_car( map, y_1, x_1, y_2, x_2);break;//��܇
		case 'd':
			Red_horse(map, y_1, x_1, y_2, x_2);break;//����
		case 'D':
			Blue_horse(map, y_1, x_1, y_2, x_2);break;//���R
		case 'p':
			Red_elephant(map, y_1, x_1, y_2, x_2);break;//����
		case 'E':
			Blue_elephant(map, y_1, x_1, y_2, x_2);break;//����
		case 's':
			Red_man(map, y_1, x_1, y_2, x_2);break;//��ʿ
		case 'F':
			Blue_man(map, y_1, x_1, y_2, x_2);break;//����
		case 'z':
			Red_boss(map, y_1, x_1, y_2, x_2);break;//��˧
		case 'G':
			Blue_boss(map, y_1, x_1, y_2, x_2);break;//�ڽ�
		case 'b':
			Red_gun(map, y_1, x_1, y_2, x_2);break;//����
		case 'B':
			Blue_gun(map, y_1, x_1, y_2, x_2);break;//�ڳh
	}
}

void Red_pawn(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 �� �Ĺ��� 
{
				if(y_1==10||y_1==12)//�ڼ�������ʱ�����
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
			else//����Է����̺�����
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

void Blue_pawn(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� �� �Ĺ���
{

			if(y_1==6||y_1==8)//�ڼ�������ʱ�����
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
			else//����Է����̺�����
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

void Red_gun(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 �� �Ĺ��� 
{
	int i,j,flag=0,n=0;

	if(y_1==y_2)//�����ƶ�ʱ�����
	{
		if(x_2>x_1)//��
		{
			for(j=x_1;j<=x_2;j++)//�ж����Ƿ������ƶ�����Ӵ���
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
		else//��
		{
			for(j=x_1;j>=x_2;j--)//�ж����Ƿ������ƶ�����Ӵ���
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
	else if(x_1==x_2)//�����ƶ������
	{
		if(y_2>y_1)//��
		{
			for(i=y_1;i<=y_2;i++)//�ж����Ƿ������ƶ�����Ӵ���
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
		else//��
		{
			for(i=y_1;i>=y_2;i--)//�ж����Ƿ������ƶ�����Ӵ���
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

void Blue_gun(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� �h �Ĺ��� 
{
	int i,j,flag=0,n=0;

	if(y_1==y_2)//�����ƶ�ʱ�����
	{
		if(x_2>x_1)//��
		{
			for(j=x_1;j<=x_2;j++)//�жϳh�Ƿ������ƶ�����Ӵ���
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
		else//��
		{
			for(j=x_1;j>=x_2;j--)//�жϳh�Ƿ������ƶ�����Ӵ���
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
	else if(x_1==x_2)//�����ƶ������
	{
		if(y_2>y_1)//��
		{
			for(i=y_1;i<=y_2;i++)//�жϳh�Ƿ������ƶ�����Ӵ���
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
		else//��
		{
			for(i=y_1;i>=y_2;i--)//�жϳh�Ƿ������ƶ�����Ӵ���
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

void Red_car(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 �� �Ĺ��� 
{
	int i,j,flag=0;

	if(y_1==y_2)//�����ƶ�ʱ�����
	{
		if(x_2>x_1)//��
		{
			for(j=x_1+1;j<x_2;j++)//���Ƴ�����λ�����ܸ��Ӵ��ӣ�
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
		else//��
		{
			for(j=x_1-1;j>x_2;j--)//���Ƴ�����λ�����ܸ��Ӵ��ӣ�
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
	else if(x_1==x_2)//�����ƶ������
	{
		if(y_2>y_1)//��
		{
			for(i=y_1+1;i<y_2;i++)//���Ƴ�����λ�����ܸ��Ӵ��ӣ�
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
		else//��
		{
			for(i=y_1-1;i>y_2;i--)//���Ƴ�����λ�����ܸ��Ӵ��ӣ�
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

void Blue_car(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� ܇ �Ĺ��� 
{

	int i,j,flag=0;

	if(y_1==y_2)//�����ƶ������
	{
		if(x_2>x_1)//��
		{
			for(j=x_1+1;j<x_2;j++)//����܇����λ�����ܸ��Ӵ��ӣ�
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
		else//��
		{
			for(j=x_1-1;j>x_2;j--)//����܇����λ�����ܸ��Ӵ��ӣ�
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
	else if(x_1==x_2)//�����ƶ������
	{
		if(y_2>y_1)//��
		{
			for(i=y_1+1;i<y_2;i++)//����܇����λ�����ܸ��Ӵ��ӣ�
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
		else//��
		{
			for(i=y_1-1;i>y_2;i--)//����܇����λ�����ܸ��Ӵ��ӣ�
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

void Red_horse(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 �� �Ĺ���
{
	double a=20;
	double move_long=sqrt(a); 
	double flag;

	flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//����ƶ����ȵ�ƽ��

	if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
	{
	if (x_2>x_1) //���ҷ��ƶ������
	{
		if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//���ҷ�
		{
			if(map[y_1][x_1+2]==0)//�ж����
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//���Ϸ�
		{
			if(map[y_1-2][x_1]==0)//�ж����
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}	
		}
		else//���·�
		{
			if(map[y_1+2][x_1]==0)//�ж����
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
	else//�����ƶ������
	{
			if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//����
		{
			if(map[y_1][x_1-2]==0)//�ж����
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//���Ϸ�
		{
			if(map[y_1-2][x_1]==0)//�ж����
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Blue_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Red_move(map);
			}	
		}
		else//���·�
		{
			if(map[y_1+2][x_1]==0)//�ж����
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

void Blue_horse(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� �R �Ĺ���
{	

	double a=20;
	double move_long=sqrt(a); 
	double flag;

	flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//�R���ƶ����ȵ�ƽ��

	if((sqrt(flag))==move_long)//���㲢�ж��R���ƶ�����
	{
	if (x_2>x_1) //���ҷ��ƶ������
	{
		if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//���ҷ�
		{
			if(map[y_1][x_1+2]==0)//�ж��R��
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//���Ϸ�
		{
			if(map[y_1-2][x_1]==0)//�ж��R��
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}	
		}
		else//���·�
		{
			if(map[y_1+2][x_1]==0)//�ж��R��
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
	else//�����ƶ������
	{
			if((((x_2-x_1)*(x_2-x_1))>(y_2-y_1)*(y_2-y_1)))//����
		{
			if(map[y_1][x_1-2]==0)//�ж��R��
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}
		}
		else if((y_2<y_1)&&(((x_2-x_1)*(x_2-x_1))<(y_2-y_1)*(y_2-y_1)))//���Ϸ�
		{
			if(map[y_1-2][x_1]==0)//�ж��R��
			{
				map[y_2][x_2]=map[y_1][x_1];  map[y_1][x_1]=0;
				Draw_map(map);Go_on(map);Red_move(map);
			}
			else
			{
				Rule_hint();Draw_map(map);Go_on(map);Blue_move(map);
			}	
		}
		else//���·�
		{
			if(map[y_1+2][x_1]==0)//�ж��R��
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

void Red_elephant(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 �� �Ĺ���
{
	double a=32;
	double move_long=sqrt(a); 
	double flag;

	if(y_2>=10)//�����಻�ܹ���
	{
	if(y_2>y_1&&x_2>x_1)//�����·��ƶ�
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1+2][x_1+2]==0)//�ж�����
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
	else if(y_2<y_1&&x_2>x_1)//�����Ϸ��ƶ�
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_1-y_2)*(y_1-y_2));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1-2][x_1+2]==0)//�ж�����
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
	else if(y_1>y_2&&x_1>x_2)//�����·��ƶ�
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
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
	else//�����Ϸ��ƶ�
	{
		flag=((x_1-x_2)*(x_1-x_2))+((y_2-y_1)*(y_2-y_1));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1+2][x_1-2]==0)//�ж�����
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

void Blue_elephant(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� �� �Ĺ���
{
	double a=32;
	double move_long=sqrt(a); 
	double flag;

	if(y_2<=8)//�������ܹ���
	{
	if(y_2>y_1&&x_2>x_1)//�����·��ƶ�
	{
		flag=((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1+2][x_1+2]==0)//�ж�����
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
		flag=((x_2-x_1)*(x_2-x_1))+((y_1-y_2)*(y_1-y_2));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1-2][x_1+2]==0)//�ж�����
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
		flag=((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1-2][x_1-2]==0)//�ж�����
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
		flag=((x_1-x_2)*(x_1-x_2))+((y_2-y_1)*(y_2-y_1));//���ƶ����ȵ�ƽ��

		if((sqrt(flag))==move_long)//���㲢�ж�����ƶ�����
		{
			if(map[y_1+2][x_1-2]==0)//�ж�����
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

void Red_man(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 ʿ �Ĺ���
{
	double a=8;
	double move_long=sqrt(a); 
	double flag;

	if((x_2>=7&&x_2<=11)&&(y_2>=14&&y_2<=18))//����ʿ���ܳ��Ź�
{
	if(y_2>y_1&&x_2>x_1)//���·�
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
	else if(y_2<y_1&&x_2>x_1)//���Ϸ�
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
	else if(y_1>y_2&&x_1>x_2)//���·�
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
	else//���Ϸ�
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

void Blue_man(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� �� �Ĺ���
{

	double a=8;
	double move_long=sqrt(a); 
	double flag;

	if((x_2>=7&&x_2<=11)&&(y_2>=0&&y_2<=4))//�����˲��ܳ��Ź�
{
	if(y_2>y_1&&x_2>x_1)//���Ϸ�
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
	else if(y_2<y_1&&x_2>x_1)//���Ϸ�
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
	else if(y_1>y_2&&x_1>x_2)//���·�
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
	else//���Ϸ�
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

void Red_boss(int map[19][18],int y_1,int x_1,int y_2,int x_2)//�췽 ˧ �Ĺ���
{
	if((x_2<=11&&x_2>=7)&&(y_2<=18&&y_2>=14))//����˧���ܹ����Ź�
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

void Blue_boss(int map[19][18],int y_1,int x_1,int y_2,int x_2)//���� �� �Ĺ���
{	
		if((x_2<=11&&x_2>=7)&&(y_2<=4&&y_2>=0))//���ƽ����ܹ����Ź�
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
