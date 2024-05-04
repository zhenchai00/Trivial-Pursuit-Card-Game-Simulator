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
        for (int studentId = 1; studentId <= studentNum; studentId++)
        {
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
void executeAuto()
{
    const int totalQuestion = 300;
    const int maxStudentNum = 100;
    const int minStudentNum = 70;
    AutomatedStudentResponse autoStudentResponse("Student Responses using Auto Method");

    // Providing a seed value
    srand((unsigned)time(NULL));

    UnansweredDeckStruct unansweredDeck[totalQuestion];              // to create the array of structs with a fixed size of 300 to store the questions and its corresponding answer
    readCSVToDeck(unansweredDeck, "docs/dstr-question-nocomma.csv"); // to read the 300 questions and their corresponding answers into the newly created array of structs

    // Shuffling the unanswered questions
    for (int i = 0; i < totalQuestion; i++)
    {
        int r = rand() % totalQuestion; // generate a random position
        UnansweredDeckStruct temp = unansweredDeck[i];
        unansweredDeck[i] = unansweredDeck[r];
        unansweredDeck[r] = temp;
    }
    // printFirstTenQuestions(unansweredDeck); // to display the first 10 questions out of the 300 questions for testing purposes

    StudentAnswer studentAns[maxStudentNum];
    readCSVToArr(studentAns, "docs/100-student-answer.csv"); // to read the 100 student responses into the newly created array of structs
    // printAllResponses(studentAns); // to display the all student responses out of the 300 questions for testing purposes

    DiscardedCardLinkedList DiscardedCard("Discarded Deck of Cards");
    AnsweredDeck AnsweredDeck("Answered Deck of Cards");

    int numOfStudents = (rand() % (maxStudentNum - minStudentNum + 1)) + minStudentNum; // randomise the number of players from 70 to 100
    cout << endl
         << "Number of students participated: " << numOfStudents << endl;

    int studentID = 0, totalScore = 0, score1 = 0, score2 = 0, score3 = 0, scoredMarkQ1 = 0, scoredMarkQ2 = 0, scoredMarkQ3 = 0;
    AnswerType studentAnswer1 = NONE, studentAnswer2 = NONE, studentAnswer3 = NONE;
    AnswerTypeTF questionAnswer1TF = DEFAULT, questionAnswer2TF = DEFAULT, questionAnswer3TF = DEFAULT;
    string question1, question2, question3 = "";
    int test = 1;

    for (int roundNum = 1; roundNum < 4; roundNum++)
    { // to simulate 3 rounds
        for (int i = 0; i < numOfStudents; i++)
        { // to simulate the number of players responding
            studentID = studentAns[i].studentID;
            if (roundNum == 1)
            {
                question1 = unansweredDeck[i].myQuestion;
                questionAnswer1TF = unansweredDeck[i].myAnswer;
                score1 = unansweredDeck[i].myScore;

                if (studentAns[i].round1 == SKIP)
                {
                    scoredMarkQ1 = scoredMarkQ1 + 0;
                    DiscardedCard.addNewDiscardedCard(question1, questionAnswer1TF, score1);
                }
                else if (studentAns[i].round1 == TRUE_NEW)
                {
                    if (questionAnswer1TF == TRUE)
                    {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    else
                    {
                        scoredMarkQ1 = 0;
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
                    else
                    {
                        scoredMarkQ1 = 0;
                    }
                    AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                }
                else
                {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    if (DiscardedCardInfo == nullptr)
                    {
                        // handle if DiscardedCardInfo return nullptr
                        return;
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
                            else
                            {
                                scoredMarkQ1 = 0;
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
                            else
                            {
                                scoredMarkQ1 = 0;
                            }
                            AnsweredDeck.InsertFront(question1, questionAnswer1TF, score1);
                        }
                    }
                }
                // to store student response into a new node of AutomatedStudentResponse LinkedList
                autoStudentResponse.insertToEnd(studentID, question1, question2, question3, scoredMarkQ1, scoredMarkQ2, scoredMarkQ3, totalScore);

                // to reset the variables for next student
                studentID = totalScore = score1 = score2 = score3 = scoredMarkQ1 = scoredMarkQ2 = scoredMarkQ3 = 0;
                studentAnswer1 = studentAnswer2 = studentAnswer3 = NONE;
                questionAnswer1TF = questionAnswer2TF = questionAnswer3TF = DEFAULT;
                question1 = question2 = question3 = "";
            }
            else if (roundNum == 2)
            {
                question2 = unansweredDeck[i].myQuestion;
                questionAnswer2TF = unansweredDeck[i].myAnswer;
                score2 = unansweredDeck[i].myScore;

                if (studentAns[i].round2 == SKIP)
                {
                    scoredMarkQ2 = scoredMarkQ2 + 0;
                    DiscardedCard.addNewDiscardedCard(question2, questionAnswer2TF, score2);
                }
                else if (studentAns[i].round2 == TRUE_NEW)
                {
                    if (questionAnswer2TF == TRUE)
                    {
                        scoredMarkQ2 = scoredMarkQ2 + score2;
                        totalScore = totalScore + score2;
                    }
                    else
                    {
                        scoredMarkQ2 = 0;
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
                    else
                    {
                        scoredMarkQ2 = 0;
                    }
                    AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                }
                else
                {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    if (DiscardedCardInfo == nullptr)
                    {
                        // handle if DiscardedCardInfo return nullptr
                        return;
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
                            else
                            {
                                scoredMarkQ2 = 0;
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
                            else
                            {
                                scoredMarkQ2 = 0;
                            }
                            AnsweredDeck.InsertFront(question2, questionAnswer2TF, score2);
                        }
                    }
                }

                // to update round 2 student response information into the existing node with the corresponding student ID
                autoStudentResponse.searchAndUpdateNodeRoundTwo(studentID, question2, scoredMarkQ2, totalScore);

                // to reset the variables for next student
                studentID = totalScore = score1 = score2 = score3 = scoredMarkQ1 = scoredMarkQ2 = scoredMarkQ3 = 0;
                studentAnswer1 = studentAnswer2 = studentAnswer3 = NONE;
                questionAnswer1TF = questionAnswer2TF = questionAnswer3TF = DEFAULT;
                question1 = question2 = question3 = "";
            }
            else if (roundNum == 3)
            {
                question3 = unansweredDeck[i].myQuestion;
                questionAnswer3TF = unansweredDeck[i].myAnswer;
                score3 = unansweredDeck[i].myScore;

                if (studentAns[i].round3 == SKIP)
                {
                    scoredMarkQ3 = scoredMarkQ3 + 0;
                    DiscardedCard.addNewDiscardedCard(question3, questionAnswer3TF, score3);
                }
                else if (studentAns[i].round3 == TRUE_NEW)
                {
                    if (questionAnswer3TF == TRUE)
                    {
                        scoredMarkQ3 = scoredMarkQ3 + score3;
                        totalScore = totalScore + score3;
                    }
                    else
                    {
                        scoredMarkQ3 = 0;
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
                    else
                    {
                        scoredMarkQ3 = 0;
                    }
                    AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                }
                else
                {
                    // student chooses to answer question from discarded deck of cards
                    DiscardedCardLinkedListNode *DiscardedCardInfo = DiscardedCard.takeDiscardedCard();
                    if (DiscardedCardInfo == nullptr)
                    {
                        // handle if DiscardedCardInfo return nullptr
                        return;
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
                            else
                            {
                                scoredMarkQ3 = 0;
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
                            else
                            {
                                scoredMarkQ3 = 0;
                            }
                            AnsweredDeck.InsertFront(question3, questionAnswer3TF, score3);
                        }
                    }
                }

                // to update round 3 student response information into the existing node with the corresponding student ID
                autoStudentResponse.searchAndUpdateNodeRoundThree(studentID, question3, scoredMarkQ3, totalScore);

                // to reset the variables for next student
                studentID = totalScore = score1 = score2 = score3 = scoredMarkQ1 = scoredMarkQ2 = scoredMarkQ3 = 0;
                studentAnswer1 = studentAnswer2 = studentAnswer3 = NONE;
                questionAnswer1TF = questionAnswer2TF = questionAnswer3TF = DEFAULT;
                question1 = question2 = question3 = "";
            }
        }
    }
    autoStudentResponse.DisplayStudentResponsesForAutoExecution(); // to print all student responses for testing purposes
}

#endif // COMMON_HPP