// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef COMMON_HPP
#define COMMON_HPP
#include <iostream>
#include <cmath>
#include "StudentResult.hpp"
#include "AutomatedStudentResponse.hpp"
#include "StudentAnswer.hpp"
#include "Enum.hpp"
#include "DiscardedCard.hpp"
#include "AnsweredDeck.hpp"
#include "Top30Winners.hpp"

using namespace std;

void executeManual(int numOfStudents)
{
    const int totalQuestion = 300;
    // to create the array of structs with a fixed size of 300 to store the questions and its corresponding answer
    UnansweredDeckStruct unansweredDeck[totalQuestion];
    readCSVToDeck(unansweredDeck, "docs/dstr-question-nocomma.csv");

    // Providing a seed value for the shuffling the unanswered questions
    srand((unsigned)time(NULL));

    // Shuffling the unanswered questions
    for (int i = 0; i < totalQuestion; i++)
    {
        int r = rand() % totalQuestion; // generate a random position
        UnansweredDeckStruct temp = unansweredDeck[i];
        unansweredDeck[i] = unansweredDeck[r];
        unansweredDeck[r] = temp;
    }

    DiscardedCardLinkedList DiscardedCard("Discarded Deck of Cards");
    AnsweredDeck AnsweredDeck("Answered Deck of Cards");
    StudentResultLinkedList studentResult("Student Result");

    int studentID = 0, totalScore = 0, score1 = 0, score2 = 0, score3 = 0, scoredMarkQ1 = 0, scoredMarkQ2 = 0, scoredMarkQ3 = 0;
    AnswerType studentAnswer1 = NONE, studentAnswer2 = NONE, studentAnswer3 = NONE;
    AnswerTypeTF questionAnswer1TF = DEFAULT, questionAnswer2TF = DEFAULT, questionAnswer3TF = DEFAULT;
    string question1 = "", question2 = "", question3 = "";

    int input;

    for (int roundNum = 1; roundNum < 4; roundNum++) // swap the loop position so it can display nicely
    {
        //int studentID = i + 1;
        //// reset the score each loop (student id) so it didnt leave the score previos student has done
        //totalScore = 0;
        //scoredMarkQ1 = 0;
        //scoredMarkQ2 = 0;
        //scoredMarkQ3 = 0;

        for (int i = 0; i < numOfStudents; i++ )
        {
            int studentID = i + 1;
            int index = (roundNum - 1) * numOfStudents + i; // Calculate index based on round number

            cout << endl << "Student ID: " << studentID << endl;

            if (roundNum == 1)
            {
                question1 = unansweredDeck[index].myQuestion;
                questionAnswer1TF = unansweredDeck[index].myAnswer;
                score1 = unansweredDeck[index].myScore;

                cout << "Round: " << roundNum << endl;
                cout << "Question: " << endl << question1 << " (" << score1 << " score)" << endl;
                cout << "Choose option below by entering the respective number (1-3):" << endl;
                cout << "1. Skip" << endl;
                cout << "2. True" << endl;
                cout << "3. False" << endl;
                // check whether discarded area is empty or not
                if (!DiscardedCard.isEmpty())
                {
                    cout << endl;
                    cout << "***You may enter 4 to answer the discarded card below which only get 80% of mark after correct answering***" << endl;
                    cout << "4. " << DiscardedCard.top() << endl;
                }
                cin >> input;

                if (input == 1)
                { // if student choose to skip the round, the card will be added to discarded card area
                    DiscardedCard.addNewDiscardedCard(question1, questionAnswer1TF, score1);
                    cout << "****** Score + 0 ******" << endl;
                }
                else if (input == 2)
                { // student choosing answer in 'T'
                    if (questionAnswer1TF == TRUE)
                    {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                        cout << "****** Score + " << score1 << " ******" << endl;
                    }
                    else {
                        cout << "****** Score + 0 ******" << endl;
                    }
                    AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                    
                }
                else if (input == 3)
                { // student choosing answer in 'F'
                    if (questionAnswer1TF == FALSE)
                    {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                        cout << "****** Score +" << score1 << " ******" << endl;
                    }
                    else {
                        cout << "****** Score + 0 ******" << endl;
                    }
                    AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                }
                else if (input == 4)
                { // student choose to answer deck from discarded card
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    int disInput;
                    cout << endl;
                    cout << "Please enter the respective number state below to answer the question (1-2):" << endl;
                    cout << "1. True" << endl;
                    cout << "2. False" << endl;
                    cin >> disInput;
                    question1 = DiscardedCardInfo->question;
                    questionAnswer1TF = DiscardedCardInfo->answer;
                    score1 = DiscardedCardInfo->marks;
                    int disScore = (int)round(score1 * 0.8);

                    if (disInput == 1)
                    {
                        if (questionAnswer1TF == TRUE)
                        {
                            scoredMarkQ1 = scoredMarkQ1 + disScore;
                            totalScore = totalScore + disScore;
                            cout << "****** Score +" << disScore << " ******" << endl;
                        }
                        else {
                            cout << "****** Score + 0 ******" << endl;
                        }
                        AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                    }
                    else if (disInput == 2)
                    {
                        if (questionAnswer1TF == FALSE)
                        {
                            scoredMarkQ1 = scoredMarkQ1 + disScore;
                            totalScore = totalScore + disScore;
                            cout << "****** Score +" << disScore << " ******" << endl; 
                        }
                        else {
                            cout << "****** Score + 0 ******" << endl;
                        }
                        AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                    }
                }
                cin.clear();

                studentResult.ManualInsertToStudent(studentID, question1, question2, question3, scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);
                studentID = totalScore = score1 = scoredMarkQ1 = 0;
                studentAnswer1 = NONE;
                questionAnswer1TF = DEFAULT;
                question1 = "";

                
            }
            else if (roundNum == 2)
            {
                question2 = unansweredDeck[index].myQuestion;
                questionAnswer2TF = unansweredDeck[index].myAnswer;
                score2 = unansweredDeck[index].myScore;

                cout << "Round: " << roundNum << endl;
                cout << "Question: " << endl << question2 << " (" << score2 << " score)" << endl;
                cout << "Choose option below by entering the respective number (1-3):" << endl;
                cout << "1. Skip" << endl;
                cout << "2. True" << endl;
                cout << "3. False" << endl;
                if (!DiscardedCard.isEmpty())
                {
                    cout << endl;
                    cout << "***You may enter 4 to answer the discarded card below which only get 80% of mark after correct answering***" << endl;
                    cout << "4. " << DiscardedCard.top() << endl;
                }
                cin >> input;

                if (input == 1)
                { // if student choose to skip the round, the card will be added to discarded card area
                    DiscardedCard.addNewDiscardedCard(question2, questionAnswer2TF, score2);
                    cout << "****** Score + 0 ******" << endl;
                }
                else if (input == 2)
                { // student choosing answer in 'T'
                    if (questionAnswer2TF == TRUE)
                    {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                        cout << "****** Score +" << score2 << " ******" << endl;
                    }
                    else {
                        cout << "****** Score + 0 ******" << endl;
                    }
                    AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                }
                else if (input == 3)
                { // student choosing answer in 'F'
                    if (questionAnswer2TF == FALSE)
                    {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                        cout << "****** Score +" << score2 << " ******" << endl;
                    }
                    else {
                        cout << "****** Score + 0 ******" << endl;
                    }
                    AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                }
                else if (input == 4)
                { // student choose to answer deck from discarded card
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    int disInput;
                    cout << endl;
                    cout << "Please enter the respective number state below to answer the question (1-2):" << endl;
                    cout << "1. True" << endl;
                    cout << "2. False" << endl;
                    cin >> disInput;
                    question2 = DiscardedCardInfo->question;
                    questionAnswer2TF = DiscardedCardInfo->answer;
                    score2 = DiscardedCardInfo->marks;
                    int disScore = (int)round(score2 * 0.8);

                    if (disInput == 1)
                    {
                        if (questionAnswer2TF == TRUE)
                        {
                            scoredMarkQ2 = scoredMarkQ2 + disScore;
                            totalScore = totalScore + disScore;
                            cout << "****** Score +" << disScore << " ******" << endl;
                        }
                        else {
                            cout << "****** Score + 0 ******" << endl;
                        }
                        AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                    }
                    else if (disInput == 2)
                    {
                        if (questionAnswer2TF == FALSE)
                        {
                            scoredMarkQ2 = scoredMarkQ2 + disScore;
                            totalScore = totalScore + disScore;
                            cout << "****** Score +" << disScore << " ******" << endl;
                        }
                        else {
                            cout << "****** Score + 0 ******" << endl;
                        }
                        AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                    }
                }
                cin.clear();
                studentResult.getStudentIdAndUpdateNode(studentID, question2, scoredMarkQ2, totalScore, 2);
                studentID = totalScore = score2 = scoredMarkQ2 = 0;
                studentAnswer2 = NONE;
                questionAnswer2TF = DEFAULT;
                question2 = "";
                
            }
            else if (roundNum == 3)
            {
                question3 = unansweredDeck[index].myQuestion;
                questionAnswer3TF = unansweredDeck[index].myAnswer;
                score3 = unansweredDeck[index].myScore;

                cout << "Round: " << roundNum << endl;
                cout << "Question: " << endl << question3 << " (" << score3 << " score)" << endl;
                cout << "Choose option below by entering the respective number (1-3):" << endl;
                cout << "1. Skip" << endl;
                cout << "2. True" << endl;
                cout << "3. False" << endl;
                if (!DiscardedCard.isEmpty())
                {
                    cout << endl;
                    cout << "***You may enter 4 to answer the discarded card below which only get 80% of mark after correct answering***" << endl;
                    cout << "4. " << DiscardedCard.top() << endl;
                }
                cin >> input;

                if (input == 1)
                { // if student choose to skip the round, the card will be added to discarded card area
                    DiscardedCard.addNewDiscardedCard(question3, questionAnswer3TF, score3);
                    cout << "****** Score + 0 ******" << endl;
                }
                else if (input == 2)
                { // student choosing answer in 'T'
                    if (questionAnswer3TF == TRUE)
                    {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                        cout << "****** Score +" << score3 << " ******" << endl;
                    }
                    else {
                        cout << "****** Score + 0 ******" << endl;
                    }
                    AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                }
                else if (input == 3)
                { // student choosing answer in 'F'
                    if (questionAnswer3TF == FALSE)
                    {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                        cout << "****** Score +" << score3 << " ******" << endl;
                    }
                    else {
                        cout << "****** Score + 0 ******" << endl;
                    }
                    AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                }
                else if (input == 4)
                { // student choose to answer deck from discarded card
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    int disInput;
                    cout << endl;
                    cout << "Please enter the respective number state below to answer the question (1-2):" << endl;
                    cout << "1. True" << endl;
                    cout << "2. False" << endl;
                    cin >> disInput;
                    question3 = DiscardedCardInfo->question;
                    questionAnswer3TF = DiscardedCardInfo->answer;
                    score3 = DiscardedCardInfo->marks;
                    int disScore = (int)round(score3 * 0.8);

                    if (disInput == 1)
                    {
                        if (questionAnswer3TF == TRUE)
                        {
                            scoredMarkQ3 = scoredMarkQ3 + disScore;
                            totalScore = totalScore + disScore;
                            cout << "****** Score +" << disScore << " ******" << endl;
                        }
                        else {
                            cout << "****** Score + 0 ******" << endl;
                        }
                        AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                    }
                    else if (disInput == 2)
                    {
                        if (questionAnswer3TF == FALSE)
                        {
                            scoredMarkQ3 = scoredMarkQ3 + disScore;
                            totalScore = totalScore + disScore;
                            cout << "****** Score +" << disScore << " ******" << endl;
                        }
                        else {
                            cout << "****** Score + 0 ******" << endl;
                        }
                        AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                    }
                    
                }
                cin.clear();

                studentResult.getStudentIdAndUpdateNode(studentID, question3, scoredMarkQ3, totalScore, 3);
                studentID = totalScore = score3 = scoredMarkQ3 = 0;
                studentAnswer3 = NONE;
                questionAnswer3TF = DEFAULT;
                question3 = "";
                
            }

            
        }
        // test
        /*cout << endl << endl;
        studentResult.ManualInsertToSortedStudentResultByScore(studentID, question1, question2, question3,
            scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);*/
        // test display the linked list c whether it exist in linked list or not
        cout << endl << endl;
        /*studentResult.ManualInsertToSortedStudentResultByScore(studentID, question1, question2, question3,
            scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);*/
        
    }
   
    /*studentResult.displayStudentResults(); */
    
   
    
    // call the ranking tree report
    //studentResult.AnnounceTop30Winners();
    // call the table report
}

// method to run auto by doing it own function
void executeAuto()
{
    const int totalQuestion = 300;
    const int maxStudentNum = 100;
    const int minStudentNum = 70;
    AutomatedStudentResponse autoStudentResponse("Student Responses using Auto Method");
    AutomatedStudentResponse autoStudentResponse2("Student Responses using Auto Method 2");

    // to create the array of structs with a fixed size of 300 to store the questions and its corresponding answer
    UnansweredDeckStruct unansweredDeck[totalQuestion];
    // to read the 300 questions and their corresponding answers into the newly created array of structs
    readCSVToDeck(unansweredDeck, "docs/dstr-question-nocomma.csv");

    // Providing a seed value for the shuffling the unanswered questions
    srand((unsigned)time(NULL));

    // Shuffling the unanswered questions
    for (int i = 0; i < totalQuestion; i++)
    {
        int r = rand() % totalQuestion; // generate a random position
        UnansweredDeckStruct temp = unansweredDeck[i];
        unansweredDeck[i] = unansweredDeck[r];
        unansweredDeck[r] = temp;
    }
    // to display the first 10 questions out of the 300 questions for testing purposes
    printFirstTenQuestions(unansweredDeck);

    StudentAnswer studentAns[maxStudentNum];
    // to read the 100 student responses into the newly created array of structs
    readCSVToArr(studentAns, "docs/100-student-answer-old.csv");
    // printAllResponses(studentAns); // to display the all student responses out of the 300 questions for testing purposes

    DiscardedCardLinkedList DiscardedCard("Discarded Deck of Cards");
    AnsweredDeck AnsweredDeck("Answered Deck of Cards");

    // randomise the number of players from 70 to 100
    int numOfStudents = (rand() % (maxStudentNum - minStudentNum + 1)) + minStudentNum;
    cout << endl
         << "Number of students participated: " << numOfStudents << endl;

    int studentID = 0, totalScore = 0, score1 = 0, score2 = 0, score3 = 0, scoredMarkQ1 = 0, scoredMarkQ2 = 0, scoredMarkQ3 = 0;
    AnswerType studentAnswer1 = NONE, studentAnswer2 = NONE, studentAnswer3 = NONE;
    AnswerTypeTF questionAnswer1TF = DEFAULT, questionAnswer2TF = DEFAULT, questionAnswer3TF = DEFAULT;
    string question1 = "", question2 = "", question3 = "";

    // to simulate 3 rounds
    for (int roundNum = 1; roundNum < 4; roundNum++)
    {
        // to simulate the number of players responding
        for (int i = 0; i < numOfStudents; i++)
        {
            studentID = studentAns[i].studentID;
            int index = (roundNum - 1) * numOfStudents + i; // Calculate index based on round number

            if (roundNum == 1)
            {
                question1 = unansweredDeck[index].myQuestion;
                questionAnswer1TF = unansweredDeck[index].myAnswer;
                score1 = unansweredDeck[index].myScore;

                if (studentAns[i].round1 == SKIP)
                {
                    DiscardedCard.addNewDiscardedCard(question1, questionAnswer1TF, score1);
                }
                else if (studentAns[i].round1 == TRUE_NEW)
                {
                    if (questionAnswer1TF == TRUE)
                    {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                }
                else if (studentAns[i].round1 == FALSE_NEW)
                {
                    if (questionAnswer1TF == FALSE)
                    {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                }
                else
                {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    if (DiscardedCardInfo == nullptr)
                    {
                        // handle different approach if discarded is empty force the student answer the new deck
                        // answer will based on student answer true false as from discard covert to new
                        bool correct = false;
                        if (studentAns[i].round1 == TRUE_DISCARD && questionAnswer1TF == TRUE)
                        {
                            correct = true;
                        }
                        else if (studentAns[i].round1 == FALSE_DISCARD && questionAnswer1TF == FALSE)
                        {
                            correct = true;
                        }

                        if (correct)
                        {
                            scoredMarkQ1 = scoredMarkQ1 + score1;
                            totalScore = totalScore + score1;
                        }
                        AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                    }
                    else
                    {
                        question1 = DiscardedCardInfo->question;
                        questionAnswer1TF = DiscardedCardInfo->answer;
                        score1 = DiscardedCardInfo->marks;
                        int roundedScore1 = (int)round(score1 * 0.8);

                        if (studentAns[i].round1 == TRUE_DISCARD)
                        {
                            if (questionAnswer1TF == TRUE)
                            {
                                scoredMarkQ1 = scoredMarkQ1 + roundedScore1;
                                totalScore = totalScore + scoredMarkQ1;
                            }
                            AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                        }
                        else if (studentAns[i].round1 == FALSE_DISCARD)
                        {
                            if (questionAnswer1TF == FALSE)
                            {
                                scoredMarkQ1 = scoredMarkQ1 + roundedScore1;
                                totalScore = totalScore + scoredMarkQ1;
                            }
                            AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                        }
                    }
                }
                // to store student response into a new node of AutomatedStudentResponse LinkedList
                autoStudentResponse.insertToEnd(studentID, question1, question2, question3, scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);
                autoStudentResponse2.insertToEnd(studentID, question1, question2, question3, scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);

                // to reset the variables for next student
                studentID = totalScore = score1 = scoredMarkQ1 = 0;
                studentAnswer1 = NONE;
                questionAnswer1TF = DEFAULT;
                question1 = "";
            }
            else if (roundNum == 2)
            {
                question2 = unansweredDeck[index].myQuestion;
                questionAnswer2TF = unansweredDeck[index].myAnswer;
                score2 = unansweredDeck[index].myScore;

                if (studentAns[i].round2 == SKIP)
                {
                    DiscardedCard.addNewDiscardedCard(question2, questionAnswer2TF, score2);
                }
                else if (studentAns[i].round2 == TRUE_NEW)
                {
                    if (questionAnswer2TF == TRUE)
                    {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                    }
                    AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                }
                else if (studentAns[i].round2 == FALSE_NEW)
                {
                    if (questionAnswer2TF == FALSE)
                    {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                    }
                    AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                }
                else
                {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    if (DiscardedCardInfo == nullptr)
                    {
                        // handle different approach if discarded is empty force the student answer the new deck
                        // answer will based on student answer true false as from discard covert to new
                        bool correct = false;
                        if (studentAns[i].round2 == TRUE_DISCARD && questionAnswer2TF == TRUE)
                        {
                            correct = true;
                        }
                        else if (studentAns[i].round2 == FALSE_DISCARD && questionAnswer2TF == FALSE)
                        {
                            correct = true;
                        }

                        if (correct)
                        {
                            scoredMarkQ2 = scoredMarkQ2 + score2;
                            totalScore = totalScore + score2;
                        }
                        AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                    }
                    else
                    {
                        question2 = DiscardedCardInfo->question;
                        questionAnswer2TF = DiscardedCardInfo->answer;
                        score2 = DiscardedCardInfo->marks;
                        int roundedScore2 = (int)round(score2 * 0.8);

                        if (studentAns[i].round2 == TRUE_DISCARD)
                        {
                            if (questionAnswer2TF == TRUE)
                            {
                                scoredMarkQ2 = scoredMarkQ2 + roundedScore2;
                                totalScore = totalScore + scoredMarkQ2;
                            }
                            AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                        }
                        else if (studentAns[i].round2 == FALSE_DISCARD)
                        {
                            if (questionAnswer2TF == FALSE)
                            {
                                scoredMarkQ2 = scoredMarkQ2 + roundedScore2;
                                totalScore = totalScore + scoredMarkQ2;
                            }
                            AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                        }
                    }
                }

                // to update round 2 student response information into the existing node with the corresponding student ID
                autoStudentResponse.searchAndUpdateNodeRoundTwo(studentID, question2, scoredMarkQ2, totalScore);
                autoStudentResponse2.searchAndUpdateNodeRoundTwo(studentID, question2, scoredMarkQ2, totalScore);

                // to reset the variables for next student
                studentID = totalScore = score2 = scoredMarkQ2 = 0;
                studentAnswer2 = NONE;
                questionAnswer2TF = DEFAULT;
                question2 = "";
            }
            else if (roundNum == 3)
            {
                question3 = unansweredDeck[index].myQuestion;
                questionAnswer3TF = unansweredDeck[index].myAnswer;
                score3 = unansweredDeck[index].myScore;

                if (studentAns[i].round3 == SKIP)
                {
                    DiscardedCard.addNewDiscardedCard(question3, questionAnswer3TF, score3);
                }
                else if (studentAns[i].round3 == TRUE_NEW)
                {
                    if (questionAnswer3TF == TRUE)
                    {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                    }
                    AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                }
                else if (studentAns[i].round3 == FALSE_NEW)
                {
                    if (questionAnswer3TF == FALSE)
                    {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                    }
                    AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                }
                else
                {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    if (DiscardedCardInfo == nullptr)
                    {
                        // handle different approach if discarded is empty force the student answer the new deck
                        // answer will based on student answer true false as from discard covert to new
                        bool correct = false;
                        if (studentAns[i].round3 == TRUE_DISCARD && questionAnswer3TF == TRUE)
                        {
                            correct = true;
                        }
                        else if (studentAns[i].round3 == FALSE_DISCARD && questionAnswer3TF == FALSE)
                        {
                            correct = true;
                        }

                        if (correct)
                        {
                            scoredMarkQ3 = scoredMarkQ3 + score3;
                            totalScore = totalScore + score3;
                        }
                        AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                    }
                    else
                    {
                        question3 = DiscardedCardInfo->question;
                        questionAnswer3TF = DiscardedCardInfo->answer;
                        score3 = DiscardedCardInfo->marks;
                        int roundedScore3 = (int)round(score3 * 0.8);

                        if (studentAns[i].round3 == TRUE_DISCARD)
                        {
                            if (questionAnswer3TF == TRUE)
                            {
                                scoredMarkQ3 = scoredMarkQ3 + roundedScore3;
                                totalScore = totalScore + scoredMarkQ3;
                            }
                            AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                        }
                        else if (studentAns[i].round3 == FALSE_DISCARD)
                        {
                            if (questionAnswer3TF == FALSE)
                            {
                                scoredMarkQ3 = scoredMarkQ3 + roundedScore3;
                                totalScore = totalScore + scoredMarkQ3;
                            }
                            AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                        }
                    }
                }

                // to update round 3 student response information into the existing node with the corresponding student ID
                autoStudentResponse.searchAndUpdateNodeRoundThree(studentID, question3, scoredMarkQ3, totalScore);
                autoStudentResponse2.searchAndUpdateNodeRoundThree(studentID, question3, scoredMarkQ3, totalScore);
                
                // here sort
                autoStudentResponse.quickSort(autoStudentResponse);

                // to reset the variables for next student
                studentID = totalScore = score3 = scoredMarkQ3 = 0;
                studentAnswer3 = NONE;
                questionAnswer3TF = DEFAULT;
                question3 = "";
            }
        }
    }
    autoStudentResponse.DisplayStudentResponsesForAutoExecution(); // to print all student responses for testing purposes

    //code to search a student's ID and display the questions attempted, their score and the total score
    int studentIDInput;
    cout << "Enter the student ID to check their score: ";
    cin >> studentIDInput;
    autoStudentResponse2.searchStudentID(autoStudentResponse2, studentIDInput);

    autoStudentResponse.AnnounceTop30Winners();                    // Announce top 30 winners

    
}

#endif // COMMON_HPP