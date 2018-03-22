#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(x) (rand()%x)	//产生随机数的宏定义
using namespace std;
int main(void)
{
	int magic[4];				//需要猜测数据的数组
	int score[3] = { 0 };		//储存成绩的数组
	int input, a, b, c, d, h, k, cnt = 0;
	int flag = 1;				//控制继续游戏的标签
	do                          //游戏循环的标签
	{
		while (1)               //生成随机数的循环
		{
			srand((int)time(NULL));
			for (int i = 0; i < 4; i++)
			{
				magic[i] = random(10);
			}
			if (magic[0] != magic[1] && magic[0] != magic[2] && magic[0] != magic[3] && magic[1] != magic[2] && magic[1] != magic[3] && magic[2] != magic[3])
				break;
		}
		//用于测试用，输出magic数组的值
	   /* for (int j = 0; j < 4; j++)
		{
			cout << magic[j] << " ";
		}
		cout << endl;*/
		//单次游戏能猜测20次
		for (k = 0; k < 20; k++)
		{
			int allright = 0, mistake = 0;
			cout << "请输入你猜测的四位数字:";
			cin >> input;
			a = input / 1000;		//取千位数
			b = input / 100 % 10;	//取百位数
			c = input / 10 % 10;	//取十位数
			d = input % 10;			//取个位数
			//判断游戏的得分
			if (a == magic[0])
			{
				allright++;
			}
			else
			{
				for (h = 0; h < 4; h++)
				{
					if (a == magic[h])
						mistake++;
					break;
				}
			}
			if (b == magic[1])
			{
				allright++;
			}
			else
			{
				for (h = 0; h < 4; h++)
				{
					if (b == magic[h])
						mistake++;
					break;
				}
			}
			if (c == magic[2])
			{
				allright++;
			}
			else
			{
				for (h = 0; h < 4; h++)
				{
					if (c == magic[h])
						mistake++;
					break;
				}
			}
			if (d == magic[3])
			{
				allright++;
			}
			else
			{
				for (h = 0; h < 4; h++)
				{
					if (d == magic[h])
						mistake++;
					break;
				}
			}
			cnt++;				//统计单次猜测的次数
			cout << allright << "A" << mistake << "B" << endl;	//输出成绩
			if (allright == 4)	//胜利的条件
			{
				cout << "你真聪明" << endl;
				break;
			}
		}
		if (k == 20)			//单次达到20次的提示
		{
			cout << "超过规定次数啦，重新来过吧!" << endl;
		}
		for (int p = 0; p < 3; p++)		//成绩排名
		{
			if (score[p] == 0 || cnt < score[p])
			{
				score[p] = cnt;
				break;
			}
		}
			cnt = 0;			//重置每次的统计的次数
			//输出排名
		cout << "NO.1" << "  " << score[0] << "  " << "NO.2" << "  " << score[1] << " " << "NO.3" << "  " << score[2] << endl;
		cout << "是否继续游戏？(Y/N)" << endl;
		//判断是否继续游戏
		char select;
		cin >> select;
		if (select == 'N')
			flag = 0;
	} while (flag == 1);
	system("pause");
	return 0;
}