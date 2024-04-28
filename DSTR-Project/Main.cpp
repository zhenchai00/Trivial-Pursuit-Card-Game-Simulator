#include "FileHandler.hpp"
#include "qnaArrOfStruct.hpp"
#include "ReportFunctions.hpp"
#include <iostream>

using namespace std;

int main()
{
	unansweredDeckStruct unansweredDeck[300]; // to create the array of structs with a fixed size of 300 to store the questions and its corresponding answer

	readCSVToDeck(unansweredDeck, "docs/dstr-question-nocomma.csv"); // to read the 300 questions and their corresponding answers into the newly created array of structs
	// printFirstTenQuestions(unansweredDeck); // to display the first 10 questions out of the 300 questions for testing purposes

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

	if (modeType == 1)	// mode = auto
	{
		// should call the auto function
		cout << endl << "selected mode auto" << endl;
	} else if (modeType == 2)	// mode = manual
	{
		// should call the manual function
		cout << endl << "selected mode manual" << endl;

		int studentNum = 0;
		cout << "Please enter how many student in the class. (1 - 100): ";
		cin >> studentNum;
		
		while (studentNum < 1 || studentNum > 101)
		{
			if (studentNum < 1 || studentNum > 101)
			{
				cout << "Please enter student number with 1 - 100 only. ";
				system("cls");
				cout << "Please enter how many student in the class. (1 - 100): ";
				cin >> studentNum;
			}
		}
		cout << "student num = " << studentNum << endl;

		// pass the studentNum to the function to generate the question by print out
	}

	//displaying report
	reportStructure report[5];
	readAllfileCSV(report, "docs/allAttributes.csv");
	displayReport(report);

	return 0;
}