//������|��Ū���O�ƥ�����ƿ�X�bcommed line�W
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string Loc;//�ŧiŪ�ɸ��|
	string LineData = "";//�ŧi�ɤ����
	cout << "�п�J�ɮ׸��|�G";
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

//���]��J�ɥs��input.txt
//�bWindows�U�A��J�ɩ�bD:\
//��J�ɸ��|���@D : \input.txt

//�bUbuntu�U�A��J�ɩ�b�ϥΪ̮a�ؿ� / home / kevin
//��J�ɸ��|���@ / home / kevin / input.txt