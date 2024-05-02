#include <iostream>
#include "StudentResult.hpp"
#include "AutomatedStudentResponse.hpp"
#include "StudentAnswer.hpp"
#include "Enum.hpp"
#include "DiscardedCard.hpp"


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

    LinkedList DiscardedCard("Discarded Deck of Cards");
    answeredDeck AnsweredDeck("Answered Deck of Cards");


    int numOfStudents = (rand() % (100 - 70 + 1)) + 70; // randomise the number of players from 70 to 100
    cout << endl << "Number of students participated: " << numOfStudents << endl;

    int studentID = 0, totalScore = 0, score1 = 0, score2 = 0, score3 = 0, scoredMarkQ1 = 0, scoredMarkQ2 = 0, scoredMarkQ3 = 0;
    AnswerType round1, round2, round3;
    AnswerTypeTF round1TF, round2TF, round3TF;
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
                    totalScore = 0;
                    DiscardedCard.addNewDiscardedCard(question1, round1TF, score1);
                    
                } 
                else if (studentAns[i].round1 = TRUE_NEW) {
                    if (round1TF == TRUE) {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    else {
                        scoredMarkQ1 = 0;
                        totalScore = 0;
                    }
                }
                else if (studentAns[i].round1 = FALSE_NEW) {
                    if (round1TF == FALSE) {
                        scoredMarkQ1 = scoredMarkQ1 + score1;
                        totalScore = totalScore + score1;
                    }
                    else {
                        scoredMarkQ1 = 0;
                        totalScore = 0;
                    }
                }
                else if (studentAns[i].round1 = TRUE_DISCARD) {
                    DiscardedCard.takeDiscardedCard();
                    
                }
                else if (studentAns[i].round1 = FALSE_DISCARD) {

                }
            }
            else if (roundNum == 2) {
            
            }
            else if (roundNum == 3) {
                
            }
        }
    }
}
