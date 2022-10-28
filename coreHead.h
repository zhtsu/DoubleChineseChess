

void Show_menu();//绘制菜单
void Get_command();//得到主菜单命令
void Out_game();//退出游戏界面
void Instruction(); //显示游戏说明 
void Start_game(); //游戏部分拼装 

void Gap_hint();//该坐标没有棋子提醒
void Error_hint();//操作错误时返回提示 
void Object_hint();//擅动对方棋子警告 
void Self_hint();//吃自己的子警告 
void Rule_hint();//棋子的移动不符合棋法警告 

void Draw_map(int map[19][18]);//绘制棋盘和棋子 
void Go_on(int map[19][18]);//判断游戏是否结束
void Red_move(int map[19][18]);//实现红方玩家对棋子的移动
void Blue_move(int map[19][18]);//实现蓝方玩家对棋子的移动
void Red_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2);//判断红棋移动是否合法
void Blue_rule(int map[19][18],int y_1,int x_1,int y_2,int x_2);//判断蓝棋移动是否合法 
 
void Files_menu();//残局菜单 
void Files_command();//残局选项得到命令 
void Files_1();//七星聚会 
void Files_2();//蚯蚓降龙 
void Files_3();//野马操田 
void Files_4();//千里独行
