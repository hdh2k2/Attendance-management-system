#include "manage.h"

void manage::run() {
	wstring s;
	s = L"\n\n\tChoose language: \n\t\t1. English\n\t\t2. Vietnamese\n";
	
	wcout << s;
	int choose;
	cin >> choose;
	wcin.ignore();
	if (choose == 1)
		EG.run();
	if (choose == 2)
		VN.run();

}