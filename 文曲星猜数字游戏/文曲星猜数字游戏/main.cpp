#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(x) (rand()%x)	//����������ĺ궨��
using namespace std;
int main(void)
{
	int magic[4];				//��Ҫ�²����ݵ�����
	int score[3] = { 0 };		//����ɼ�������
	int input, a, b, c, d, h, k, cnt = 0;
	int flag = 1;				//���Ƽ�����Ϸ�ı�ǩ
	do                          //��Ϸѭ���ı�ǩ
	{
		while (1)               //�����������ѭ��
		{
			srand((int)time(NULL));
			for (int i = 0; i < 4; i++)
			{
				magic[i] = random(10);
			}
			if (magic[0] != magic[1] && magic[0] != magic[2] && magic[0] != magic[3] && magic[1] != magic[2] && magic[1] != magic[3] && magic[2] != magic[3])
				break;
		}
		//���ڲ����ã����magic�����ֵ
	   /* for (int j = 0; j < 4; j++)
		{
			cout << magic[j] << " ";
		}
		cout << endl;*/
		//������Ϸ�ܲ²�20��
		for (k = 0; k < 20; k++)
		{
			int allright = 0, mistake = 0;
			cout << "��������²����λ����:";
			cin >> input;
			a = input / 1000;		//ȡǧλ��
			b = input / 100 % 10;	//ȡ��λ��
			c = input / 10 % 10;	//ȡʮλ��
			d = input % 10;			//ȡ��λ��
			//�ж���Ϸ�ĵ÷�
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
			cnt++;				//ͳ�Ƶ��β²�Ĵ���
			cout << allright << "A" << mistake << "B" << endl;	//����ɼ�
			if (allright == 4)	//ʤ��������
			{
				cout << "�������" << endl;
				break;
			}
		}
		if (k == 20)			//���δﵽ20�ε���ʾ
		{
			cout << "�����涨������������������!" << endl;
		}
		for (int p = 0; p < 3; p++)		//�ɼ�����
		{
			if (score[p] == 0 || cnt < score[p])
			{
				score[p] = cnt;
				break;
			}
		}
			cnt = 0;			//����ÿ�ε�ͳ�ƵĴ���
			//�������
		cout << "NO.1" << "  " << score[0] << "  " << "NO.2" << "  " << score[1] << " " << "NO.3" << "  " << score[2] << endl;
		cout << "�Ƿ������Ϸ��(Y/N)" << endl;
		//�ж��Ƿ������Ϸ
		char select;
		cin >> select;
		if (select == 'N')
			flag = 0;
	} while (flag == 1);
	system("pause");
	return 0;
}