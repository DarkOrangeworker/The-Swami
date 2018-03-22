#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(x) (rand()%x)
using namespace std;
int main(void)
{
	int magic[4];
	int score[3] = { 0 };
	int input, a, b, c, d, h, k, cnt = 0;
	int flag = 1;
	do
	{
		while (1)
		{
			srand((int)time(NULL));
			for (int i = 0; i < 4; i++)
			{
				magic[i] = random(10);
			}
			if (magic[0] != magic[1] && magic[0] != magic[2] && magic[0] != magic[3] && magic[1] != magic[2] && magic[1] != magic[3] && magic[2] != magic[3])
				break;
		}
	   /* for (int j = 0; j < 4; j++)
		{
			cout << magic[j] << " ";
		}
		cout << endl;*/
		for (k = 0; k < 20; k++)
		{
			int allright = 0, mistake = 0;
			cout << "请输入你猜测的四位数字:";
			cin >> input;
			a = input / 1000;
			b = input / 100 % 10;
			c = input / 10 % 10;
			d = input % 10;
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
			cnt++;
			cout << allright << "A" << mistake << "B" << endl;
			if (allright == 4)
			{
				cout << "你真聪明" << endl;
				break;
			}
		}
		if (k == 20)
		{
			cout << "超过规定次数啦，重新来过吧!" << endl;
		}
		for (int p = 0; p < 3; p++)
		{
			if (score[p] == 0 || cnt < score[p])
			{
				score[p] = cnt;
				break;
			}
		}
			cnt = 0;
		cout << "NO.1" << "  " << score[0] << "  " << "NO.2" << "  " << score[1] << " " << "NO.3" << "  " << score[2] << endl;
		cout << "是否继续游戏？(Y/N)" << endl;
		char select;
		cin >> select;
		if (select == 'N')
			flag = 0;
	} while (flag == 1);
	system("pause");
	return 0;
}