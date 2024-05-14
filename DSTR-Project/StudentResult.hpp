// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef STUDENT_RESULT_HPP
#define STUDENT_RESULT_HPP
#include <iostream>
#include <iomanip>
#include "Enum.hpp"
#include "Top30Winners.hpp"

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

    // insert student node to front of the list, time complexity o(1)
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

    // insert student node to end of the list, time complexity o(1)
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

    void getStudentIdAndUpdateNode(int studentId, string question, int score, int totalScore, int round = 0)
    {
        // list is empty
        if (head == nullptr)
        {
            cout << this->listName << " is empty!" << endl;
            return;
        }
        // studentid match the head value, update node from front o(1)
        else if (studentId == head->studentId)
        {
            if (round == 2)
            {
                head->question2 = question;
                head->scoreQ2 = score;
                head->totalScore += totalScore;
                return;
            }
            else if (round == 3)
            {
                head->question3 = question;
                head->scoreQ3 = score;
                head->totalScore += totalScore;
                return;
            }
        }
        // studentid match the head value, update node from end o(1)
        else if (studentId == tail->studentId)
        {
            if (round == 2)
            {
                tail->question2 = question;
                tail->scoreQ2 = score;
                tail->totalScore += totalScore;
                return;
            }
            else if (round == 3)
            {
                tail->question3 = question;
                tail->scoreQ3 = score;
                tail->totalScore += totalScore;
                return;
            }
        }
        // studentid match middle value, update node from middle o(n)
        else
        {
            StudentResultNode *current = head->next;
            while (current != nullptr)
            {
                if (studentId == current->studentId)
                {
                    if (round == 2)
                    {
                        current->question2 = question;
                        current->scoreQ2 = score;
                        current->totalScore += totalScore;
                        return;
                    }
                    else if (round == 3)
                    {
                        current->question3 = question;
                        current->scoreQ3 = score;
                        current->totalScore += totalScore;
                        return;
                    }
                }
                current = current->next;
            }
        }
        cout << "Node with student ID " << studentId << " not found." << endl;
    }

    // get student nodes by student id which traverse whole linked list from first to last
    StudentResultNode *getNodeById(int studentId)
    {
        // list is empty
        if (head == nullptr)
        {
            cout << this->listName << " is empty!" << endl;
        }
        // studentid match the head value, return node from front o(1)
        else if (studentId == head->studentId)
        {
            return head;
        }
        // studentid match the tail value, return node from end o(1)
        else if (studentId == tail->studentId)
        {
            return tail;
        }
        // studentid match middle value, return node from middle o(n)
        else
        {
            StudentResultNode *current = head->next;
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
        return nullptr;
    }
    // testing function can ignored this
    void displayStudentResults()
    {
        // begin with the head node
        StudentResultNode *current = head;

        // to check if the list is empty
        if (current == nullptr)
        {
            cout << "The linked list is empty." << endl;
            return;
        }

        // to loop through the linked list
        cout << "Student Result List:" << endl;
        while (current != nullptr)
        {
            // Print the details of the current node
            cout << "Student ID: " << current->studentID << endl;
            cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
            cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
            cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
            cout << "Total Score: " << current->totalScore << endl;
            cout << "---------------------------------" << endl;
            cout << endl; // Insert a blank line between students
            current = current->next;
        }
    }

    void AnnounceTop30Winners()
    {
        // Create a binary search tree
        BinaryTree tree;
        StudentResultNode *current = head;
        // Traverse the linked list of student responses
        int count = 0;
        while (current != nullptr && count < 30)
        {
            tree.insertNode(current->studentId);
            current = current->next;
            count++;
        }
        tree.levelOrderTraversal(count);
        int studentID;
        string input;
        cout << "Do you want to check if you are one of the Top 30 Winners? (Y/N)";
        cin >> input;
        if (input == "Y" || input == "y")
        {
            cout << "Enter Student ID: ";
            cin >> studentID;
            tree.Search(studentID);
        }
    }
};
#endif // STUDENT_RESULT_HPP