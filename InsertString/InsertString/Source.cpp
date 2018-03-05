#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include<windows.h>
void SetColor(int color = 7)//換色函式
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
using namespace std;
int main(void)
{
	string buffer1 = "@,0,X=";//OK時載入字串
	string buffer2 = "@,2,X=";//NG時載入字串
	string buffer3 = ",#";
	string CRLF = "\n";
	string Data = "";
	char X;//是否執行檔案
	int i = 0;
	ifstream infile;//提供從檔案讀取資料的操作
	ofstream outfile;//提供從檔案寫入資料的操作
	SetColor(5);//黑0　藍1　綠2　青3　紅4　紫5　黃6　白7
	SetColor(7);
	cout << "執行前請確認檔案與副檔是否為 datalog.csv\n";
	cout << "確定執行嗎? Y/N" << endl;
	cin >> X;
	if (X == 'Y' || X == 'y')
	{
		infile.open("datalog.csv");
		if (!infile.is_open())//檔案開啟失敗
		{
			SetColor(4);
			cout << "檔案無法開啟 請確認檔案與副檔是否為 datalog.csv\n";
			SetColor(7);
			system("pause"); return 0;
		}
		int rowCount = 0;
		char buffer[100];
		while (!infile.eof())//讀取檔案是否到尾
		{
			SetColor(2);
			rowCount++;
			infile.getline(buffer, sizeof(buffer));//讀取一行
			//------------------csv檔內沒有空白字串------------------//
			if (buffer[0] == '0' || buffer[0] == '2' || buffer[0] == '3' || buffer[0] == '4' || buffer[0] == '5' || buffer[0] == '6' || buffer[0] == '7' || buffer[0] == '8' || buffer[0] == '9')
			{
				if (buffer[0] != '0' || buffer[2] != '0' || buffer[3] != '0' || buffer[4] != '0' || buffer[5] != '0')
				{
					string myString = buffer;
					myString.insert(7, "Y=");//插入Y=
					Data = Data + buffer1 + myString + buffer3 + CRLF;
					i++;
				}
				else
				{
					string myString = buffer;
					myString.insert(7, "Y=");//插入Y=
					Data = Data + buffer2 + myString + buffer3 + CRLF;//加入@,,X=座標,#
				}
			}
			//--------------------------------------------------------//

			//-------------------csv檔內有空白字串--------------------//
			else
			{
				//----------清除空白字串------------//
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
				if (buffer[0] == ' ')//空白字元作為判斷
				{
					if (buffer[9] == '0' || buffer[11] == '0' || buffer[12] == '0' || buffer[13] == '0' || buffer[14] == '0')
					{
						string myString = strTemp;
						myString.insert(7, "Y=");//插入Y=
						Data = Data + buffer2 + myString + buffer3 + CRLF;
						i++;
					}
					else
					{
						string myString = strTemp;
						myString.insert(7, "Y=");//插入Y=
						Data = Data + buffer1 + myString + buffer3 + CRLF;//加入@,,X=座標,#
					}
				}
			}
			//----------------------------------------------------//
		}
		cout << Data;
		infile.close();//關閉檔案
		outfile.open("datalog.csv", ios::trunc);//再開啟一次
		if (!outfile.is_open())
		{
			SetColor(7);
			cout << "檔案無法開啟\n";
			SetColor(7);
			system("pause"); return 0;
		}
		outfile << Data;
		outfile.close();//關閉檔案
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