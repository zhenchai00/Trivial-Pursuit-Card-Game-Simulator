#include <iostream>
#include "StudentResult.hpp"
#include "Enum.hpp"

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

void executeAuto ()
{
    // method to run auto by doing it own function
}