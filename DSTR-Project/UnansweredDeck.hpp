#include "Enum.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct unansweredDeckStruct {  // declaration of a struct to be used to create an array of structs
	string myQuestion;
	AnswerTypeTF myAnswer;
    int myScore;
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
    string line, question, answer, score;
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
            // Convert the answer string to AnswerType enum
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

        // start added by caizhen on 23/4/2024 
        if (getline(ss, score, ','))
        {
            if (score == "4")
            {
                unansweredDeck[i].myScore = 4;
            }
            else if (score == "8")
            {
                unansweredDeck[i].myScore = 8;
            }
            else if (score == "10")
            {
                unansweredDeck[i].myScore = 10;
            }
            else
            {
                cerr << "Unknown score value: " << score << " in line " << (i + 1) << endl;
                continue;
            }
        }
        // end added by caizhen on 23/4/2024 

        // increment the index by 1
        i++;
    }

    // close the file
    file.close();
}

void printFirstTenQuestions(const unansweredDeckStruct unansweredDeck[]) {
    cout << endl << "First 10 Questions and Answers:" << endl;
    // to loop through the first 10 elements of the array
    for (int i = 0; i < 10; i++) {
        // display the question
        cout << "Question " << (i + 1) << ": " << unansweredDeck[i].myQuestion << endl;

        // to convert the AnswerType enum to "string" data type
        string answerString;
        if (unansweredDeck[i].myAnswer == TRUE) {
            answerString = "TRUE";
        }
        else {
            answerString = "FALSE";
        }

        // to display the question's corresponding answer
        cout << "Answer: " << answerString << endl;

        // start added by caizhen on 23/4/2024 
        // to convert the score type to string
        string scoreString;
        if (unansweredDeck[i].myScore == 4) {
            scoreString = "4";
        } else if (unansweredDeck[i].myScore == 8) {
            scoreString = "8";
        } else if (unansweredDeck[i].myScore == 10) {
            scoreString = "10";
        } else {
            scoreString = "Unknown";
        }
        cout << "Score: " << scoreString << endl;
        // end added by caizhen on 23/4/2024 

        cout << "-----------------------------------" << endl;
    }
}