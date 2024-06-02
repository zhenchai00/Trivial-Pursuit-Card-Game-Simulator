// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef STUDENT_ANSWER_HPP
#define STUDENT_ANSWER_HPP
#include "Enum.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// to create an Array of Struct to store the 100 student decisions from the 100-student-answer.csv file (ANSWER new/discarded question or SKIP the round)

// declaration of a struct to be used to create an array of structs
struct StudentAnswer
{
    int studentID;
    AnswerType round1;
    AnswerType round2;
    AnswerType round3;
};

void readCSVToArr(StudentAnswer studentAnswers[], const string &filename)
{
    // to open the CSV file
    ifstream file(filename);

    // to check if the file was opened successfully
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // declaring variables used to store the current line and the student information
    string line, studentIDStr, round1Str, round2Str, round3Str;
    int i = 0;

    // to read the file line by line
    while (getline(file, line) && i < 100)
    {
        // Create a string stream from the line
        stringstream ss(line);

        // to read the student ID (first column in the CSV file)
        if (getline(ss, studentIDStr, ','))
        {
            studentAnswers[i].studentID = stoi(studentIDStr);
        }
        else
        {
            cerr << "Error reading student ID in line " << i + 1 << endl;
            continue;
        }

        // function to convert a string to AnswerType enum
        auto convertAnswerType = [](const string &answerStr) -> AnswerType
        {
            if (answerStr == "NONE")
            {
                return NONE;
            }
            else if (answerStr == "TRUE_NEW")
            {
                return TRUE_NEW;
            }
            else if (answerStr == "FALSE_NEW")
            {
                return FALSE_NEW;
            }
            else if (answerStr == "SKIP")
            {
                return SKIP;
            }
            else if (answerStr == "TRUE_DISCARD")
            {
                return TRUE_DISCARD;
            }
            else if (answerStr == "FALSE_DISCARD")
            {
                return FALSE_DISCARD;
            }
            else
            {
                cerr << "Unknown answer type: " << answerStr << endl;
                return NONE; // default answer type as NONE
            }
        };

        // to read round 1 answer (second column in the csv file)
        if (getline(ss, round1Str, ','))
        {
            studentAnswers[i].round1 = convertAnswerType(round1Str);
        }
        else
        {
            cerr << "Error reading round1 answer in line " << i + 1 << endl;
            continue;
        }

        // to read round 2 answer (third column in the csv file)
        if (getline(ss, round2Str, ','))
        {
            studentAnswers[i].round2 = convertAnswerType(round2Str);
        }
        else
        {
            cerr << "Error reading round2 answer in line " << i + 1 << endl;
            continue;
        }

        // to read round 3 answer (fourth column in the csv file)
        if (getline(ss, round3Str))
        {
            studentAnswers[i].round3 = convertAnswerType(round3Str);
        }
        else
        {
            cerr << "Error reading round3 answer in line " << i + 1 << endl;
            continue;
        }

        // increment the index for the next student answer
        i++;
    }

    // close the file
    file.close();
}

void printAllResponses(const StudentAnswer studentAnswers[])
{ // for testing purposes - Kae Lam (1/5/2024 - 10AM)
    // to loop through all 100 responses in the array of struct
    for (int i = 0; i < 100; i++)
    {
        // to display the student ID
        cout << "Student ID: " << studentAnswers[i].studentID << endl;

        // to display round 1 answer
        cout << "Round 1: ";
        switch (studentAnswers[i].round1)
        {
        case NONE:
            cout << "NONE";
            break;
        case TRUE_NEW:
            cout << "TRUE_NEW";
            break;
        case FALSE_NEW:
            cout << "FALSE_NEW";
            break;
        case SKIP:
            cout << "SKIP";
            break;
        case TRUE_DISCARD:
            cout << "TRUE_DISCARD";
            break;
        case FALSE_DISCARD:
            cout << "FALSE_DISCARD";
            break;
        default:
            cout << "Unknown";
            break;
        }
        cout << endl;

        // to display round 2 answer
        cout << "Round 2: ";
        switch (studentAnswers[i].round2)
        {
        case NONE:
            cout << "NONE";
            break;
        case TRUE_NEW:
            cout << "TRUE_NEW";
            break;
        case FALSE_NEW:
            cout << "FALSE_NEW";
            break;
        case SKIP:
            cout << "SKIP";
            break;
        case TRUE_DISCARD:
            cout << "TRUE_DISCARD";
            break;
        case FALSE_DISCARD:
            cout << "FALSE_DISCARD";
            break;
        default:
            cout << "Unknown";
            break;
        }
        cout << endl;

        // to display round 3 answer
        cout << "Round 3: ";
        switch (studentAnswers[i].round3)
        {
        case NONE:
            cout << "NONE";
            break;
        case TRUE_NEW:
            cout << "TRUE_NEW";
            break;
        case FALSE_NEW:
            cout << "FALSE_NEW";
            break;
        case SKIP:
            cout << "SKIP";
            break;
        case TRUE_DISCARD:
            cout << "TRUE_DISCARD";
            break;
        case FALSE_DISCARD:
            cout << "FALSE_DISCARD";
            break;
        default:
            cout << "Unknown";
            break;
        }
        cout << endl;

        cout << "-----------------------------------" << endl;
    }
}

#endif // STUDENT_ANSWER_HPP