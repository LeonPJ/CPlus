//絕對路徑內讀取記事本內資料輸出在commed line上
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string Loc;//宣告讀檔路徑
	string LineData = "";//宣告檔內資料
	cout << "請輸入檔案路徑：";
	getline(cin, Loc);
	ifstream infile(Loc.c_str(), ios::in);
	if (infile)
	{
		cout << "Succeeded..." << endl;
		while (!infile.eof())
		{
			getline(infile, LineData);
			cout << LineData << endl;
			LineData = "";
		}
	}
	else
	{
		cout << "Failed..." << endl;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}

//假設輸入檔叫做input.txt
//在Windows下，輸入檔放在D:\
//輸入檔路徑給　D : \input.txt

//在Ubuntu下，輸入檔放在使用者家目錄 / home / kevin
//輸入檔路徑給　 / home / kevin / input.txt