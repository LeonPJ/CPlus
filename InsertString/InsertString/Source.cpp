#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include<windows.h>
void SetColor(int color = 7)//����禡
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
using namespace std;
int main(void)
{
	string buffer1 = "@,0,X=";//OK�ɸ��J�r��
	string buffer2 = "@,2,X=";//NG�ɸ��J�r��
	string buffer3 = ",#";
	string CRLF = "\n";
	string Data = "";
	char X;//�O�_�����ɮ�
	int i = 0;
	ifstream infile;//���ѱq�ɮ�Ū����ƪ��ާ@
	ofstream outfile;//���ѱq�ɮ׼g�J��ƪ��ާ@
	SetColor(5);//��0�@��1�@��2�@�C3�@��4�@��5�@��6�@��7
	SetColor(7);
	cout << "����e�нT�{�ɮ׻P���ɬO�_�� datalog.csv\n";
	cout << "�T�w�����? Y/N" << endl;
	cin >> X;
	if (X == 'Y' || X == 'y')
	{
		infile.open("datalog.csv");
		if (!infile.is_open())//�ɮ׶}�ҥ���
		{
			SetColor(4);
			cout << "�ɮ׵L�k�}�� �нT�{�ɮ׻P���ɬO�_�� datalog.csv\n";
			SetColor(7);
			system("pause"); return 0;
		}
		int rowCount = 0;
		char buffer[100];
		while (!infile.eof())//Ū���ɮ׬O�_���
		{
			SetColor(2);
			rowCount++;
			infile.getline(buffer, sizeof(buffer));//Ū���@��
			//------------------csv�ɤ��S���ťզr��------------------//
			if (buffer[0] == '0' || buffer[0] == '2' || buffer[0] == '3' || buffer[0] == '4' || buffer[0] == '5' || buffer[0] == '6' || buffer[0] == '7' || buffer[0] == '8' || buffer[0] == '9')
			{
				if (buffer[0] != '0' || buffer[2] != '0' || buffer[3] != '0' || buffer[4] != '0' || buffer[5] != '0')
				{
					string myString = buffer;
					myString.insert(7, "Y=");//���JY=
					Data = Data + buffer1 + myString + buffer3 + CRLF;
					i++;
				}
				else
				{
					string myString = buffer;
					myString.insert(7, "Y=");//���JY=
					Data = Data + buffer2 + myString + buffer3 + CRLF;//�[�J@,,X=�y��,#
				}
			}
			//--------------------------------------------------------//

			//-------------------csv�ɤ����ťզr��--------------------//
			else
			{
				//----------�M���ťզr��------------//
				string strTemp = buffer;
				string::iterator it = strTemp.begin();
				while (it != strTemp.end())
				{
					if (isspace(*it))
						it = strTemp.erase(it);
					else
						it++;
				}
				//----------------------------------//
				if (buffer[0] == ' ')//�ťզr���@���P�_
				{
					if (buffer[9] == '0' || buffer[11] == '0' || buffer[12] == '0' || buffer[13] == '0' || buffer[14] == '0')
					{
						string myString = strTemp;
						myString.insert(7, "Y=");//���JY=
						Data = Data + buffer2 + myString + buffer3 + CRLF;
						i++;
					}
					else
					{
						string myString = strTemp;
						myString.insert(7, "Y=");//���JY=
						Data = Data + buffer1 + myString + buffer3 + CRLF;//�[�J@,,X=�y��,#
					}
				}
			}
			//----------------------------------------------------//
		}
		cout << Data;
		infile.close();//�����ɮ�
		outfile.open("datalog.csv", ios::trunc);//�A�}�Ҥ@��
		if (!outfile.is_open())
		{
			SetColor(7);
			cout << "�ɮ׵L�k�}��\n";
			SetColor(7);
			system("pause"); return 0;
		}
		outfile << Data;
		outfile.close();//�����ɮ�
	}
	else
	{
		return 0;
	}
	if (i == 0)
	{
		SetColor(2);
		cout << "Mission Success" << endl;
	}
	else{
		SetColor(4);
		cout << "Mission Success(plz check any coordinates error)" << endl;
	}
	SetColor(7);
	system("pause"); return 0;
}