#include <iostream>
#include "Enum.hpp"

using namespace std;

struct StudentResultNode
{
    // data
    int studentId;
    string question1;
    string question2;
    string question3;
    AnswerType answer1;
    AnswerType answer2;
    AnswerType answer3;
    int score;

    // linked list node
    StudentResultNode *nextAdd, *prevAdd;
};

class StudentResultLinkedList
{
    // properties in linked list
    StudentResultNode *head, *tail;
    string listName;
    int size;

public:
    // constructor to build the list
    StudentResultLinkedList(string listName)
    {
        this->listName = listName;
        head = tail = nullptr;
        size = 0;
    }

    // create a new node for a student linked list
    StudentResultNode *createNewNode(int studentId, string question1, string question2, string question3, AnswerType answer1, AnswerType answer2, AnswerType answer3, int score)
    {
        StudentResultNode *newNode = new StudentResultNode;
        newNode->studentId = studentId;
        newNode->question1 = question1;
        newNode->question2 = question2;
        newNode->question3 = question3;
        newNode->answer1 = answer1;
        newNode->answer2 = answer2;
        newNode->answer3 = answer3;
        newNode->score = score;

        newNode->nextAdd = nullptr;
        newNode->prevAdd = nullptr;

        return newNode;
    }

    // insert student node to front of the list
    void insertFrontStudentResult (int studentId, string question1, string question2, string question3, AnswerType answer1, AnswerType answer2, AnswerType answer3, int score)
    {
        StudentResultNode *newNode = createNewNode(studentId, question1, question2, question3, answer1, answer2, answer3, score);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->nextAdd = head;
            head->prevAdd = newNode;
            head = newNode;
        }
        size++;
    }

    // insert student node to end of the list
    void insertEndStudentResult (int studentId, string question1, string question2, string question3, AnswerType answer1, AnswerType answer2, AnswerType answer3, int score)
    {
        StudentResultNode *newNode = createNewNode(studentId, question1, question2, question3, answer1, answer2, answer3, score);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->nextAdd = newNode;
            newNode->prevAdd = tail;
            tail = newNode;
        }
        size++;
    }

    // insert to sorted list based on the score, more to less
    void insertToSortedStudentResultByScore (int studentId, string question1, string question2, string question3, AnswerType answer1, AnswerType answer2, AnswerType answer3, int score)
    {
        StudentResultNode *newNode = createNewNode(studentId, question1, question2, question3, answer1, answer2, answer3, score);

        if (head == nullptr)
        {
            head = newNode;
        }
        else if (newNode->score >= head->score)
        {
            newNode->nextAdd = head;
            head = newNode;
        }
        else
        {
            StudentResultNode *current = head->nextAdd;
            StudentResultNode *prev = head;

            while (current != nullptr)
            {
                if (newNode->score < current->score)
                {
                    break;
                }
                prev = current;
                current = current->nextAdd;
            }

            prev->nextAdd = newNode;
            newNode->nextAdd = current;
        }
        size++;
    }

    // get student nodes by student id which traverse whole linked list from first to last
    StudentResultNode *getNodeById (int studentId)
    {
        StudentResultNode *current = head;
        while (current != nullptr) // O(n)
        {
            if (current->studentId == studentId)
            {
                return current;
            }
            current = current->nextAdd;
        }
        return nullptr;
    }
};