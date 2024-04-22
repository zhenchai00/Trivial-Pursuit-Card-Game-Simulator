#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum answerType {TRUE, FALSE}; // declaration of enum to standardize the question's answer type

struct unansweredDeckStruct {  // declaration of a struct to be used to create an array of structs
	string myQuestion;
	answerType myAnswer;
};

void readCSVToDeck(unansweredDeckStruct unansweredDeck[], const string& filename) {
    // to open the CSV file
    ifstream file(filename);

    // to check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // declaring variables used to store the current line, question, and its corresponding answer
    string line, question, answer;
    int i = 0;

    // to read the file line by line
    while (getline(file, line) && i < 300) {
        // Create a string stream from the line
        stringstream ss(line);

        // to read the question (the first element in the CSV line)
        if (getline(ss, question, ',')) {
            unansweredDeck[i].myQuestion = question;
        }

        // to read the question's corresponding answer (the second element in the CSV line)
        if (getline(ss, answer, ',')) {
            // Convert the answer string to answerType enum
            if (answer == "TRUE") {
                unansweredDeck[i].myAnswer = TRUE;
            }
            else if (answer == "FALSE") {
                unansweredDeck[i].myAnswer = FALSE;
            }
            else {
                cerr << "Unknown answer type: " << answer << " in line " << i + 1 << endl;
                continue;
            }
        }

        // increment the index by 1
        i++;
    }

    // close the file
    file.close();
}

void printFirstTenQuestions(const unansweredDeckStruct unansweredDeck[]) {
    cout << endl << "First 10 Questions and Answers:" << endl;
    // to loop through the first 10 elements of the array
    for (int i = 0; i < 300; i++) {
        // display the question
        cout << "Question " << i + 1 << ": " << unansweredDeck[i].myQuestion << endl;

        // to convert the answerType enum to "string" data type
        string answerString;
        if (unansweredDeck[i].myAnswer == TRUE) {
            answerString = "TRUE";
        }
        else {
            answerString = "FALSE";
        }

        // to display the question's corresponding answer
        cout << "Answer: " << answerString << endl;

        cout << "-----------------------------------" << endl;
    }
}