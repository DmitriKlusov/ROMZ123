#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	cout << "�������� ��������� ����� 5 ������" << endl << "��������";
	for(int count = 0; count < 5; ++ count)
	{
		cout << ". ";
		fflush(stdout);
		sleep(1);
	}
	cout << endl << "�������� ���������" << endl;
	return 0;
}