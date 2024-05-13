#include "UnansweredDeck.hpp"
//#include "ReportFunctions.hpp"
#include "Common.hpp"
#include <iostream>

using namespace std;

int main()
{
	int modeType;
	cout << "Do you want to run the program manual or automatic? 1 - auto, 2 - manual: ";
	cin >> modeType;

	// check if not insert 1 or 2 will prompt again the command
	while (modeType != 1 && modeType != 2)
	{
		if (modeType != 1 && modeType != 2)
		{
			cout << "Invalid Input!";
			system("cls");
			cout << "Do you want to run the program manual or automatic? 1 - auto, 2 - manual: ";
			cin >> modeType;
		}
	}

	if (modeType == 1) // mode = auto
	{
		// should call the auto function
		cout << endl << "selected mode auto" << endl;
		executeAuto();
	}
	else if (modeType == 2) // mode = manual
	{
		// should call the manual function
		cout << endl << "selected mode manual" << endl;

		int studentNum = 0;
		cout << "Please enter how many student in the class. (1 - 100): ";
		cin >> studentNum;

		while (studentNum < 1 || studentNum >= 101)
		{
			if (studentNum < 1 || studentNum >= 101)
			{
				cout << "Please enter student number with 1 - 100 only. ";
				system("cls");
				cout << "Please enter how many student in the class. (1 - 100): ";
				cin >> studentNum;
			}
		}

		// pass the studentNum to the function to generate the question by print out
		executeManual(studentNum);
	}

	return 0;
}