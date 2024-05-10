// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef STUDENT_RESULT_HPP
#define STUDENT_RESULT_HPP
#include <iostream>
#include <iomanip>
#include "Enum.hpp"

using namespace std;

struct StudentResultNode
{
    // data
    int studentId;
    string question1;
    string question2;
    string question3;
    int scoreQ1;
    int scoreQ2;
    int scoreQ3;
    int totalScore;

    // linked list node
    StudentResultNode *next, *prev;
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
    StudentResultNode *createNewNode(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
    {
        StudentResultNode *newNode = new StudentResultNode;
        newNode->studentId = studentId;
        newNode->question1 = question1;
        newNode->question2 = question2;
        newNode->question3 = question3;
        newNode->scoreQ1 = scoreQ1;
        newNode->scoreQ2 = scoreQ2;
        newNode->scoreQ3 = scoreQ3;
        newNode->totalScore = totalScore;

        newNode->next = nullptr;
        newNode->prev = nullptr;

        return newNode;
    }

    // insert student node to front of the list
    void insertToFront(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
    {
        StudentResultNode *newNode = createNewNode(studentId, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, totalScore);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // insert student node to end of the list
    void insertToEnd(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
    {
        StudentResultNode *newNode = createNewNode(studentId, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, totalScore);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // insert to sorted list based on the score, more to less
    void insertToSortedStudentResultByScore(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
    {
        StudentResultNode *newNode = createNewNode(studentId, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, totalScore);

        if (head == nullptr)
        {
            head = newNode;
        }
        // insert to front list
        else if (newNode->totalScore <= head->totalScore)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (newNode->totalScore >= tail->totalScore)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            StudentResultNode *current = head->next;

            while (current->totalScore < newNode->totalScore)
            {
                current = current->next;
            }
            current->prev->next = newNode;
            newNode->prev = current->prev;
            current->prev = newNode;
            newNode->next = current;
        }
        size++;
    }

    // get student nodes by student id which traverse whole linked list from first to last
    StudentResultNode *getNodeById(int studentId)
    {
        StudentResultNode *current = head;
        while (current != nullptr) // O(n)
        {
            if (current->studentId == studentId)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void displayNodes()
    {
        StudentResultNode *current = head;

        while (current != nullptr)
        {
            cout << endl;
            cout << "Student ID: " << current->studentId << endl;
            current = current->next;
        }

        cout << listName << " is empty now" << endl;
    }

    // insert the manual mode data by sorting the total score
    void ManualInsertToSortedStudentResultByScore(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
    {
        StudentResultNode* newNode = createNewNode(studentId, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, totalScore);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        // Insert at the front of the list if the list is empty or if the new node's score is greater than or equal to the head's score
        else if (newNode->totalScore >= head->totalScore)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        // Insert at the end of the list if the new node's score is less than or equal to the tail's score
        else if (newNode->totalScore <= tail->totalScore)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        // Insert in the middle of the list
        else
        {
            StudentResultNode* current = tail;

            while (current->prev != nullptr && current->prev->totalScore < newNode->totalScore)
            {
                current = current->prev;
            }

            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
        size++;
    }

    // testing function can ignored this
    void displayStudentResults() {
        if (head == nullptr) {
            cout << "Student Result List is empty." << endl;
            return;
        }

        cout << "Student Result List:" << endl;

        StudentResultNode* current = head;
        while (current != nullptr) {
            cout << "Student ID: " << current->studentId << endl;
            cout << "Question 1: " << current->question1 << endl;
            cout << "Score Q1: " << current->scoreQ1 << endl;
            cout << "Question 2: " << current->question2 << endl;
            cout << "Score Q2: " << current->scoreQ2 << endl;
            cout << "Question 3: " << current->question3 << endl;
            cout << "Score Q3: " << current->scoreQ3 << endl;
            cout << "Total Score: " << current->totalScore << endl;
            cout << endl; // Insert a blank line between students
            current = current->next;
        }
    }


    
};
#endif // STUDENT_RESULT_HPP