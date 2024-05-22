// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef AUTOMATED_STUDENT_RESPONSE_HPP
#define AUTOMATED_STUDENT_RESPONSE_HPP
#include "Enum.hpp"
#include <iostream>
#include <iomanip>
#include "Top30Winners.hpp"

using namespace std;

struct StudentResponseNode
{

	// data attributes
	int studentID;
	string question1;
	string question2;
	string question3;
	int scoreQ1;
	int scoreQ2;
	int scoreQ3;
	int totalScore;

	// link of the node
	StudentResponseNode* nextAddress; // next address of the node
	StudentResponseNode* prevAddress; // previous address of the node
};

class AutomatedStudentResponseDoubly
{

	// properties of the student response linked list
	StudentResponseNode* head, * tail;
	string linkedlistName;
	int size;

public:
	// constructor to build the linked list
	AutomatedStudentResponseDoubly(string linkedlistName)
	{
		this->linkedlistName = linkedlistName;
		head = nullptr;
		size = 0;
	}

	~AutomatedStudentResponseDoubly()
	{
		cout << endl << this->linkedlistName << " is destroyed!" << endl;;
	}

	// function to create a new node for the linked list;
	StudentResponseNode* createNewNode(int studentID, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
	{
		// to create struct in heap location
		StudentResponseNode* newNode = new StudentResponseNode;

		// data attribute of a single node is stored in the memory location
		newNode->studentID = studentID;
		newNode->question1 = question1;
		newNode->question2 = question2;
		newNode->question3 = question3;
		newNode->scoreQ1 = scoreQ1;
		newNode->scoreQ2 = scoreQ2;
		newNode->scoreQ3 = scoreQ3;
		newNode->totalScore = totalScore;

		newNode->nextAddress = nullptr;
		newNode->prevAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}

	// function to get the head of the list
	StudentResponseNode* getHead() {
		return head;
	}

	// function to insert to the end of the list
	// insert student node to end of the list, time complexity o(1)
	void insertToEnd(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
	{
		// creating a new node using the createNewNode function
		StudentResponseNode* newNode = createNewNode(studentId, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, totalScore);

		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->nextAddress = newNode;
			newNode->prevAddress = tail;
			tail = newNode;
		}
		size++;
	}


	// functions to display the list
	
	// function to display all the nodes of the list
	void DisplayStudentResponsesForAutoExecution()
	{
		// begin with the head node
		StudentResponseNode* current = head;
		int rank = 1;

		// to check if the list is empty
		if (current == nullptr)
		{
			cout << "The " << this->linkedlistName << " is linked list is empty." << endl;
			return;
		}

		// to loop through the linked list
		cout << "Displaying student responses:" << endl;
		while (current != nullptr)
		{
			// displaying the rank, studentID, questions answered by the student and their respective scores along with the total score
			cout << "Rank: " << rank << endl;
			cout << "Student ID: " << current->studentID << endl;
			cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
			cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
			cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
			cout << "Total Score: " << current->totalScore << endl;
			cout << "---------------------------------" << endl;

			// move to the next node
			current = current->nextAddress;
			rank++;
		}
	}

	// function to display the node of a single student
	void DisplaySingleStudentResponsesForAutoExecution(StudentResponseNode* studentIDNode, int rank)
	{
		if (studentIDNode != nullptr) // checking whether the node is empty
		{ 
			// displaying the rank, studentID, questions answered by the student and their respective scores along with the total score
			cout << "---------------------------------" << endl;
			cout << "Rank: " << rank << endl;
			cout << "Student ID: " << studentIDNode->studentID << endl;
			cout << "Question 1: " << studentIDNode->question1 << " - Scored: " << studentIDNode->scoreQ1 << endl;
			cout << "Question 2: " << studentIDNode->question2 << " - Scored: " << studentIDNode->scoreQ2 << endl;
			cout << "Question 3: " << studentIDNode->question3 << " - Scored: " << studentIDNode->scoreQ3 << endl;
			cout << "Total Score: " << studentIDNode->totalScore << endl;
			cout << "---------------------------------" << endl;
		}
		else
		{
			// displayed when student ID is not in the list
			cout << "Student ID not found" << endl;
		}
	}

	//updating question and answer logic
	
	// function to search for a node based on studentID and update its attributes for either round 2 and 3
	void getStudentIDAndUpdateNode(int studentId, string question, int score, int totalScore, int round)
	{
		// list is empty
		if (head == nullptr)
		{
			cout << "The " << this->linkedlistName << " Linked List is empty!" << endl;
			return;
		}
		// studentid match the head value, update node from front o(1)
		else if (studentId == head->studentID)
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
		else if (studentId == tail->studentID)
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
			StudentResponseNode* current = head->nextAddress;
			while (current != nullptr)
			{
				if (studentId == current->studentID)
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
				current = current->nextAddress;
			}
		}
		cout << "Node with student ID " << studentId << " not found." << endl;
	}


	// searching logic
	
	// function to search the student and display their data using linear search
	void searchAndDisplayStudentID(int studentIDinput, int size) 
	{
		int rank = 1; // initializing rank to 1
		
		// checking whether the list is empty
		if (head == nullptr) 
		{
			cout << "The " << this->linkedlistName << " List is empty!" << endl;
			return;
		}

		// checking whether the head node contains the studentID that is being searched
		if (studentIDinput == head->studentID)
		{
			DisplaySingleStudentResponsesForAutoExecution(head, rank);
			return;
		}

		// checking whether the tail node contains the studentID that is being searched
		else if (studentIDinput == tail->studentID)
		{
			rank = size; // rank set to the last node based on the size
			DisplaySingleStudentResponsesForAutoExecution(tail, rank);
			return;
		}

		// checking whether the middle node contains the studentID that is being searched
		else
		{
			StudentResponseNode* current = head;
			while (current != nullptr) 
			{
				if (current->studentID == studentIDinput) 
				{
					DisplaySingleStudentResponsesForAutoExecution(current, rank);
					return;
				}
				rank++; // incrementing the rank based on the number of nodes searched
				current = current->nextAddress;
			}
		}
		// displayed when student ID is not in the list
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

	// Binary tree logic
	
	// Function to display the top 30 winners using a binary tree
	void AnnounceTop30Winners()
	{
		// Create a binary tree
		BinaryTree tree;
		// Set current to head
		StudentResponseNode* current = head;
		int count = 0;
		// Insert the first 30 nodes from the sorted linked list into the tree
		while (current != nullptr && count < 30)
		{
			tree.insertNode(current->studentID);
			current = current->nextAddress;
			count++;
		}
		// Display the binary tree
		tree.levelOrderTraversal(30);
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


	// Quick sort logic 

	// getting the last node of the list
	StudentResponseNode* getLastNode(StudentResponseNode* current)
	{
		while (current != nullptr && current->nextAddress != nullptr)
		{
			current = current->nextAddress;
		}
		return current;
	}

	// getting the median node for the pivot
	StudentResponseNode* getMedian(StudentResponseNode* left, StudentResponseNode* mid, StudentResponseNode* right) 
	{
		// condition when the left node is lesser than the middle node
		if (left->totalScore < mid->totalScore) 
		{
			// condition when the middle node is lesser than the right node
			if (mid->totalScore < right->totalScore) {
				return mid;
			}
			// condition when the left node is lesser than the right node
			else if (left->totalScore < right->totalScore) {
				return right;
			}
			// condition when neither middle and left node are lesser than right node
			else {
				return left;
			}
		}
		// condition when the left node is not lesser than the middle node
		else
		{
			// condition when the left node is lesser than the right node
			if (left->totalScore < right->totalScore) {
				return left;
			}
			// condition when the middle node is lesser than the right node
			else if (mid->totalScore < right->totalScore) {
				return right;
			}
			// condition when neither middle and left node are lesser than right node
			else {
				return mid;
			}
		}
	}

	// partitioning the linked list based on the median
	StudentResponseNode* partition(StudentResponseNode* head, StudentResponseNode* end, StudentResponseNode** newHead, StudentResponseNode** newEnd)
	{
		// getting the median node for the linked list
		StudentResponseNode* pivot = getMedian(head, head->nextAddress, end);

		// making the pivot as the last node in the list if it is not already
		if (pivot != end) {
			StudentResponseNode* temp = pivot;
			pivot = end;
			end = temp;
		}

		// declaring pointers to use for partitioning the list
		StudentResponseNode* prev = nullptr;
		StudentResponseNode* current = head;
		StudentResponseNode* tail = pivot;

		// code to partition the list around the pivot
		while (current != pivot)
		{
			// condition when the current node's total score is greater than the pivot's total score
			if (current->totalScore > pivot->totalScore)
			{
				if (*newHead == nullptr)
				{
					*newHead = current;
				}
				prev = current;
				current = current->nextAddress;
			}

			// condition when the current node's total score is lesser than or equal to the pivot's total score
			else
			{
				if (prev)
				{
					prev->nextAddress = current->nextAddress;
				}
				if (current->nextAddress)
				{
					current->nextAddress->prevAddress = prev;
				}

				StudentResponseNode* temp = current->nextAddress;
				current->nextAddress = nullptr;
				tail->nextAddress = current;
				current->prevAddress = tail;
				tail = current;
				current = temp;
			}
		}

		if (*newHead == nullptr)
		{
			*newHead = pivot; // if newHead is not updated, set to the pivot
		}
		*newEnd = tail; // updating newEnd to the tail

		return pivot;
	}

	// function to sort the list
	StudentResponseNode* sortingFunction(StudentResponseNode* head, StudentResponseNode* end)
	{
		// checking if the list is empty or contains one element
		if (!head || head == end)
		{
			return head;
		}

		// creating pointers to track the sublist's elements
		StudentResponseNode* newHead = nullptr, * newEnd = nullptr;

		// partitioning the list and getting the pivot node
		StudentResponseNode* pivot = partition(head, end, &newHead, &newEnd);

		// block of code to sort the sublist that contain total score lesser than the pivot
		if (newHead != pivot)
		{
			StudentResponseNode* temp = newHead;
			while (temp->nextAddress != pivot)
			{
				temp = temp->nextAddress;
			}
			temp->nextAddress = nullptr;

			// sorting the sublist with nodes lesser than the pivot using the recursive function
			newHead = sortingFunction(newHead, temp);

			// setting the pivot to be the last node
			temp = getLastNode(newHead);
			temp->nextAddress = pivot;
			pivot->prevAddress = temp;
		}

		// sorting the sublist with nodes greater than the pivot in the list using the recursive function
		pivot->nextAddress = sortingFunction(pivot->nextAddress, newEnd);
		if (pivot->nextAddress)
		{
			pivot->nextAddress->prevAddress = pivot;
		}

		return newHead;
	}

	// function to perform the sorting operation
	void quickSort(AutomatedStudentResponseDoubly& list)
	{
		// updating the head to the new head of the sorted list
		list.head = list.sortingFunction(list.head, list.getLastNode(list.head));
		// updating the tail to the new tail of the sorted list
		list.tail = list.getLastNode(list.head);
	}

};
#endif // AUTOMATED_STUDENT_RESPONSE_HPP