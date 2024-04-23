#include "FileHandler.hpp"
#include "qnaArrOfStruct.hpp"
#include <iostream>

using namespace std;

int main()
{
	unansweredDeckStruct unansweredDeck[300]; // to create the array of structs with a fixed size of 300 to store the questions and its corresponding answer
	//cout << "bye bye";
	//fileHandler();

	readCSVToDeck(unansweredDeck, "docs/dstr-question-nocomma.csv"); // to read the 300 questions and their corresponding answers into the newly created array of structs
	printFirstTenQuestions(unansweredDeck); // to display the first 10 questions out of the 300 questions for testing purposes (22/4 10:53pm - Kae Lam)
	
	return 0;
}