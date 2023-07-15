#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	cout << "Загрузка произойдёт через 5 секунд" << endl << "Загрузка";
	for(int count = 0; count < 5; ++ count)
	{
		cout << ". ";
		fflush(stdout);
		sleep(1);
	}
	cout << endl << "Загрузка завершена" << endl;
	return 0;
}