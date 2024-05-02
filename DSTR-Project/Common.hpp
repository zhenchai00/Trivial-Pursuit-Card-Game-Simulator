// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef COMMON_HPP
#define COMMON_HPP
#include <iostream>
#include "StudentResult.hpp"
#include "AutomatedStudentResponse.hpp"
#include "StudentAnswer.hpp"
#include "Enum.hpp"
#include "DiscardedCard.hpp"
#include "AnsweredDeck.hpp"


using namespace std;

void executeManual(int studentNum)
{
    // create student result list
    StudentResultLinkedList studentResult("Student Result");
    for (int studentId = 1; studentId <= studentNum; studentId++)
    {
        string question1;
        string question2;
        string question3;
        AnswerType answer1;
        AnswerType answer2;
        AnswerType answer3;
        int score;
        studentResult.insertEndStudentResult(studentId, "", "", "", AnswerType::NONE, AnswerType::NONE, AnswerType::NONE, 0);
    }
    studentResult.displayNodes();

    int totalRound = 3;
    for (int round = 1; round <= totalRound; round++) // round of the game
    {
        for (int studentId = 1; studentId <= studentNum; studentId++) {
            // display question and answer input 
            // capture the answer input and compare the question answers
            // update the student linked list
        }
    }
    // function to read csv to object linkedlist 
    // before get need to randomize / suffer the question arrangement
    // get all question linked list = hit 3 round, break 
    // loop all the question based on the student 
    // q1 round 1 student 1 
    // q1 round student 2 
}

// method to run auto by doing it own function
void executeAuto() {
    AutomatedStudentResponse autoStudentResponse("Student Responses using Auto Method");

    // Providing a seed value
    srand((unsigned)time(NULL));

    UnansweredDeckStruct unansweredDeck[300]; // to create the array of structs with a fixed size of 300 to store the questions and its corresponding answer
    readCSVToDeck(unansweredDeck, "docs/dstr-question-nocomma.csv"); // to read the 300 questions and their corresponding answers into the newly created array of structs

    // Shuffling the unanswered questions
    for (int i = 0; i < 300; i++) {
        int r = rand() % 300;  // generate a random position
        UnansweredDeckStruct temp = unansweredDeck[i];
        unansweredDeck[i] = unansweredDeck[r];
        unansweredDeck[r] = temp;
    }
    //printFirstTenQuestions(unansweredDeck); // to display the first 10 questions out of the 300 questions for testing purposes

    StudentAnswer studentAns[100];
    readCSVToArr(studentAns, "docs/100-student-answer.csv"); // to read the 100 student responses into the newly created array of structs
    //printAllResponses(studentAns); // to display the all student responses out of the 300 questions for testing purposes

    DiscardedCardLinkedList DiscardedCard("Discarded Deck of Cards");
    AnsweredDeck AnsweredDeck("Answered Deck of Cards");


    int numOfStudents = (rand() % (100 - 70 + 1)) + 70; // randomise the number of players from 70 to 100
    cout << endl << "Number of students participated: " << numOfStudents << endl;

    int studentID = 0, totalScore = 0, score1 = 0, score2 = 0, score3 = 0, scoredMarkQ1 = 0, scoredMarkQ2 = 0, scoredMarkQ3 = 0;
    AnswerType round1 = NONE, round2 = NONE, round3 = NONE;
    AnswerTypeTF round1TF = DEFAULT, round2TF = DEFAULT, round3TF = DEFAULT;
    string question1, question2, question3;

    for (int roundNum = 1; roundNum < 4; roundNum++) { // to simulate 3 rounds 
        for (int i = 0; i < numOfStudents; i++) { // to simulate the number of players responding
            studentID = studentAns[i].studentID;
            if (roundNum == 1) {

                unansweredDeck[i].myQuestion = question1;
                unansweredDeck[i].myAnswer = round1TF;
                unansweredDeck[i].myScore = score1;


                if (studentAns[i].round1 = SKIP) {
                    scoredMarkQ1 = scoredMarkQ1 + 0;
                    DiscardedCard.addNewDiscardedCard(question1, round1TF, score1);
                    
                } 
                else if (studentAns[i].round1 = TRUE_NEW) {
                    if (round1TF == TRUE) {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    else {
                        scoredMarkQ1 = 0;
                    }
                    AnsweredDeck.InsertFront(question1, round1TF, score1);
                }
                else if (studentAns[i].round1 = FALSE_NEW) {
                    if (round1TF == FALSE) {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    else {
                        scoredMarkQ1 = 0;
                    }
                    AnsweredDeck.InsertFront(question1, round1TF, score1);
                }
                else {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode* DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    DiscardedCardInfo->question = question1;
                    DiscardedCardInfo->answer = round1TF;
                    DiscardedCardInfo->marks = score1;
                    if (studentAns[i].round1 = TRUE_DISCARD) {
                        if (round1TF == TRUE) {
                            scoredMarkQ1 = scoredMarkQ1 + (score1*0.8);
                            totalScore = totalScore + scoredMarkQ1;
                        }
                        else {
                            scoredMarkQ1 = 0;
                        }
                        AnsweredDeck.InsertFront(question1, round1TF, score1);
                    }
                    else if (studentAns[i].round1 = FALSE_DISCARD) {
                        if (round1TF == FALSE) {
                            scoredMarkQ1 = scoredMarkQ1 + (score1 * 0.8);
                            totalScore = totalScore + scoredMarkQ1;
                        }
                        else {
                            scoredMarkQ1 = 0;
                        }
                        AnsweredDeck.InsertFront(question1, round1TF, score1);
                    }
                }
            }
            else if (roundNum == 2) {
                unansweredDeck[i].myQuestion = question2;
                unansweredDeck[i].myAnswer = round2TF;
                unansweredDeck[i].myScore = score2;


                if (studentAns[i].round2= SKIP) {
                    scoredMarkQ2 = scoredMarkQ2 + 0;
                    DiscardedCard.addNewDiscardedCard(question2, round2TF, score2);

                }
                else if (studentAns[i].round2 = TRUE_NEW) {
                    if (round2TF == TRUE) {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                    }
                    else {
                        scoredMarkQ2 = 0;
                    }
                    AnsweredDeck.InsertFront(question2, round2TF, score2);
                }
                else if (studentAns[i].round2 = FALSE_NEW) {
                    if (round2TF == FALSE) {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                    }
                    else {
                        scoredMarkQ2 = 0;
                    }
                    AnsweredDeck.InsertFront(question2, round2TF, score2);
                }
                else {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode* DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    DiscardedCardInfo->question = question2;
                    DiscardedCardInfo->answer = round2TF;
                    DiscardedCardInfo->marks = score2;
                    if (studentAns[i].round2 = TRUE_DISCARD) {
                        if (round2TF == TRUE) {
                            scoredMarkQ2 = scoredMarkQ2 + (score2 * 0.8);
                            totalScore = totalScore + scoredMarkQ2;
                        }
                        else {
                            scoredMarkQ2 = 0;
                        }
                        AnsweredDeck.InsertFront(question2, round2TF, score2);
                    }
                    else if (studentAns[i].round2 = FALSE_DISCARD) {
                        if (round2TF == FALSE) {
                            scoredMarkQ2 = scoredMarkQ2 + (score2 * 0.8);
                            totalScore = totalScore + scoredMarkQ2;
                        }
                        else {
                            scoredMarkQ2 = 0;
                        }
                        AnsweredDeck.InsertFront(question2, round2TF, score2);
                    }
                }
            }
            else if (roundNum == 3) {
                unansweredDeck[i].myQuestion = question3;
                unansweredDeck[i].myAnswer = round3TF;
                unansweredDeck[i].myScore = score3;


                if (studentAns[i].round3 = SKIP) {
                    scoredMarkQ3 = scoredMarkQ3 + 0;
                    DiscardedCard.addNewDiscardedCard(question3, round3TF, score3);

                }
                else if (studentAns[i].round3 = TRUE_NEW) {
                    if (round3TF == TRUE) {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                    }
                    else {
                        scoredMarkQ3 = 0;
                    }
                    AnsweredDeck.InsertFront(question3, round3TF, score3);
                }
                else if (studentAns[i].round3 = FALSE_NEW) {
                    if (round3TF == FALSE) {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                    }
                    else {
                        scoredMarkQ3 = 0;
                    }
                    AnsweredDeck.InsertFront(question3, round3TF, score3);
                }
                else {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode* DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    DiscardedCardInfo->question = question3;
                    DiscardedCardInfo->answer = round3TF;
                    DiscardedCardInfo->marks = score3;
                    if (studentAns[i].round3 = TRUE_DISCARD) {
                        if (round3TF == TRUE) {
                            scoredMarkQ3 = scoredMarkQ3 + (score3 * 0.8);
                            totalScore = totalScore + scoredMarkQ3;
                        }
                        else {
                            scoredMarkQ3 = 0;
                        }
                        AnsweredDeck.InsertFront(question3, round3TF, score3);
                    }
                    else if (studentAns[i].round3 = FALSE_DISCARD) {
                        if (round3TF == FALSE) {
                            scoredMarkQ3 = scoredMarkQ3 + (score3 * 0.8);
                            totalScore = totalScore + scoredMarkQ3;
                        }
                        else {
                            scoredMarkQ3 = 0;
                        }
                        AnsweredDeck.InsertFront(question3, round3TF, score3);
                    }
                }

                // to store student response into a new node of AutomatedStudentResponse LinkedList
                autoStudentResponse.insertToEnd(studentID, question1, question2, question3, scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);

                // to reset the variables for next student
                int studentID = 0, totalScore = 0, score1 = 0, score2 = 0, score3 = 0, scoredMarkQ1 = 0, scoredMarkQ2 = 0, scoredMarkQ3 = 0;
                AnswerType round1 = NONE, round2 = NONE, round3 = NONE;
                AnswerTypeTF round1TF = DEFAULT, round2TF = DEFAULT, round3TF = DEFAULT;
                string question1, question2, question3;
            }
        }
    }
    autoStudentResponse.DisplayStudentResponsesForAutoExecution(); // to print all student responses for testing purposes
}

#endif // COMMON_HPP

