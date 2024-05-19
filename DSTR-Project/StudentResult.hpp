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
    
    // destructor to destroy the list
    ~StudentResultLinkedList()
    {
        cout << endl << this->listName << " is destroyed!" << endl;;
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

    StudentResultNode *getHead()
    {
        return head;
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
            cout << "Student ID: " << current->studentId << endl;
            cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
            cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
            cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
            cout << "Total Score: " << current->totalScore << endl;
            cout << "---------------------------------" << endl;
            cout << endl; // Insert a blank line between students
            current = current->next;
        }
    }

    // Merge two sorted doubly linked lists
    StudentResultNode* merge(StudentResultNode* left, StudentResultNode* right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        // Create a new head pointer for the merged list
        StudentResultNode* merged = nullptr;

        // Choose the smaller value between left and right
        if (left->totalScore <= right->totalScore)
        {
            merged = left;
            merged->next = merge(left->next, right);
            if (merged->next)
                merged->next->prev = merged;
        }
        else
        {
            merged = right;
            merged->next = merge(left, right->next);
            if (merged->next)
                merged->next->prev = merged;
        }

        return merged;
    }

    // Merge sort for doubly linked list
    void mergeSort(StudentResultNode** headRef)
    {
        StudentResultNode* head = *headRef;
        StudentResultNode* left;
        StudentResultNode* right;

        // Base case: If the list is empty or has only one node
        if (head == nullptr || head->next == nullptr)
            return;

        // Split the list into two halves
        split(head, &left, &right);

        // Recursively sort the two halves
        mergeSort(&left);
        mergeSort(&right);

        // Merge the sorted halves
        *headRef = merge(left, right);
    }

    // Function to split a doubly linked list into two halves
    void split(StudentResultNode* head, StudentResultNode** leftRef, StudentResultNode** rightRef)
    {
        StudentResultNode* slow = head;
        StudentResultNode* fast = head->next;

        // Move 'fast' two nodes and 'slow' one node
        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // 'slow' is before the midpoint of the list
        *leftRef = head;
        *rightRef = slow->next;

        // Splitting the list
        slow->next = nullptr;
        if (*rightRef)
            (*rightRef)->prev = nullptr;
    }

    void insertionSort()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        // Initialize sorted linked list
        StudentResultNode* sorted = nullptr;

        // Traverse the original list
        StudentResultNode* current = head;
        while (current != nullptr)
        {
            // Store the next node
            StudentResultNode* nextNode = current->next;

            // Insert current node into sorted linked list
            if (sorted == nullptr || sorted->totalScore < current->totalScore)
            {
                // Insert at the beginning of sorted list
                current->prev = nullptr;
                current->next = sorted;
                if (sorted)
                    sorted->prev = current;
                sorted = current;
            }
            else
            {
                // Traverse the sorted list to find the correct position
                StudentResultNode* temp = sorted;
                while (temp->next != nullptr && temp->next->totalScore >= current->totalScore)
                {
                    temp = temp->next;
                }

                // Insert current node after temp
                current->prev = temp;
                current->next = temp->next;
                if (temp->next)
                    temp->next->prev = current;
                temp->next = current;
            }

            // Move to the next node in the original list
            current = nextNode;
        }

        // Update head and tail pointers
        head = sorted;
        tail = sorted;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
    }

    // Function to display the top winners/ top 30 winners using a binary tree
    void AnnounceTop30Winners()
    {
        // Create a binary search tree
        BinaryTree tree;
        // Set current to head
        StudentResultNode *current = head;
        int count = 0;
        // Insert the all the nodes/ first 30 nodes from the sorted linked list into the tree
        while (current != nullptr && count < 30)
        {
            tree.insertNode(current->studentId);
            current = current->next;
            count++;
        }
        // Display the binary tree
        tree.levelOrderTraversal(count);
        int studentID;
        string input;
        cout << "Do you want to check if you are one of the Top 30 Winners? (Y/N)";
        cin >> input;

        while (input != "n" && input != "N")
        {
            if (input == "Y" || input == "y")
            {
                cout << "Enter Student ID: ";
                cin >> studentID;
                // Search for the studentID in the binary tree
                tree.Search(studentID, count);
            }
            cout << "Do you want to check if you are one of the Top 30 Winners? (Y/N)";
            cin >> input;
        }

        cout << endl << endl;
    }


    //Quick sort logic 
    //https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/

    //getting the last node of the list
    StudentResultNode* getLastNode(StudentResultNode* current) {
        while (current != nullptr && current->next != nullptr)
            current = current->next;
        return current;
    }

    StudentResultNode* partition(StudentResultNode* head, StudentResultNode* end, StudentResultNode** newHead, StudentResultNode** newEnd) {

        StudentResultNode* pivot = end; //setting the pivot as the last node of the list

        StudentResultNode* prev = nullptr;
        StudentResultNode* current = head;
        StudentResultNode* tail = pivot;

        while (current != pivot) {
            if (current->totalScore > pivot->totalScore) {
                if ((*newHead) == NULL)
                    (*newHead) = current;

                prev = current;
                current = current->next;
            }
            //condition when the node's total score is greater than the pivot's total score
            else
            {
                if (prev)
                    prev->next = current->next;
                StudentResultNode* temp = current->next;
                current->next = nullptr;
                tail->next = current;
                tail = current;
                current = temp;
            }
        }

        if ((*newHead) == nullptr)
            (*newHead) = pivot;

        (*newEnd) = tail;

        return pivot;
    }

    //function to sort the list
    StudentResultNode* sortingFunction(StudentResultNode* head, StudentResultNode* end)
    {
        //checking if the list is empty
        if (!head || head == end)
            return head;

        //creating pointers to track the sublist's elements
        StudentResultNode* newHead = nullptr, * newEnd = nullptr;

        //creating the pivot node to compare the nodes for sorting the list
        StudentResultNode* pivot = partition(head, end, &newHead, &newEnd);

        //block of code to sort the sublist that contain total score lesser than or equal to the pivot
        if (newHead != pivot) {
            StudentResultNode* temp = newHead;
            while (temp->next != pivot) {
                temp = temp->next;
            }
            temp->next = nullptr;

            //sorting the sublist using the recursive function
            newHead = sortingFunction(newHead, temp);

            //setting back the pivot to be the last node
            temp = getLastNode(newHead);
            temp->next = pivot;
        }

        //sorting the node that is greater than the pivot in the list
        pivot->next = sortingFunction(pivot->next, newEnd);

        return newHead;
    }

    //function to perform the sorting operation
    void quickSort(StudentResultLinkedList& list)
    {
        //updating the head to the new head of the sorted list
        list.head = list.sortingFunction(list.head, list.getLastNode(list.head));
        //updating the tail to the new tail of the sorted list
        list.tail = list.getLastNode(list.head);
    }

 
    // searching and displaying logic
    // function to display all the nodes of the list
    void DisplayStudentResponsesForManualExecution()
    {
        // begin with the head node
        StudentResultNode* current = head;
        int rank = 1;

        // to check if the list is empty
        if (current == nullptr)
        {
            cout << "The " << this->listName << " is linked list is empty." << endl;
            return;
        }

        // to loop through the linked list
        cout << "Displaying student responses:" << endl;
        while (current != nullptr)
        {
            // Print the details of the current node
            cout << "Rank: " << rank << endl;
            cout << "Student ID: " << current->studentId << endl;
            cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
            cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
            cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
            cout << "Total Score: " << current->totalScore << endl;
            cout << "---------------------------------" << endl;

            // move to the next node
            current = current->next;
            rank++;
        }
    }

    // function to display the node of a single student
    void DisplaySingleStudentResponsesForManualExecution(StudentResultNode* studentIDNode, int rank)
    {
        if (studentIDNode != nullptr) 
        {
            cout << "---------------------------------" << endl;
            cout << "Rank: " << rank << endl;
            cout << "Student ID: " << studentIDNode->studentId << endl;
            cout << "Question 1: " << studentIDNode->question1 << " - Scored: " << studentIDNode->scoreQ1 << endl;
            cout << "Question 2: " << studentIDNode->question2 << " - Scored: " << studentIDNode->scoreQ2 << endl;
            cout << "Question 3: " << studentIDNode->question3 << " - Scored: " << studentIDNode->scoreQ3 << endl;
            cout << "Total Score: " << studentIDNode->totalScore << endl;
            cout << "---------------------------------" << endl;
        }
        else
        {
            cout << "Student ID not found" << endl;
        }
    }

    // searching logic
    // function to search the student and display their data using linear search
    // Big O notation: 
    // Best case: O(1)
    // Worst case: O(n)
    void searchAndDisplayStudentID(int studentIDinput, int size)
    {
        int rank = 1; // initializing rank to 1

        // checking whether the list is empty
        if (head == nullptr)
        {
            cout << "The " << this->listName << " Linked List is empty!" << endl;
            return;
        }

        // checking whether the head node contains the studentID that is being searched
        if (studentIDinput == head->studentId)
        {
            DisplaySingleStudentResponsesForManualExecution(head, rank);
            return;
        }
        
        // checking whether the tail node contains the studentID that is being searched
        else if (studentIDinput == tail->studentId)
        {
            rank = size;// rank set to the last node based on the size
            DisplaySingleStudentResponsesForManualExecution(tail, rank);
            return;
        }
        
        // checking whether the middle node contains the studentID that is being searched
        else
        {
            StudentResultNode* current = head;
            while (current != nullptr)
            {
                if (current->studentId == studentIDinput)
                {
                    DisplaySingleStudentResponsesForManualExecution(current, rank);
                    return;
                }
                rank++; // incrementing the rank based on the number of nodes searched
                current = current->next;
            }
        }
        cout << "Student ID not found!" << endl;
    }

    // search function to be used in the common file
    void searchStudentIDInSortedList() 
    {
        string choice; // declaring a variable to input whether or not to display the student's game details
        cout << "Do you want to check a student's attempted questions and scores obtained? (Y/N)";
        cin >> choice;

        int studentIDinput;

        // condition when the input is 'Y' or 'y'
        while (choice != "N" && choice != "n")
        {
            if (choice == "Y" || choice == "y")
            {
                cout << "Enter the student ID to display their data: ";
                cin >> studentIDinput;
                searchAndDisplayStudentID(studentIDinput, size); // calling searchStudentID function 
            }
            cout << "Do you want to check a student's attempted questions and scores obtained? (Y/N)";
            cin >> choice;
        }
    }
};
#endif // STUDENT_RESULT_HPP