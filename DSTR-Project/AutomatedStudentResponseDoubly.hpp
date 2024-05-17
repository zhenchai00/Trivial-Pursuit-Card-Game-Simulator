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
	StudentResponseNode* nextAddress;
	StudentResponseNode* prevAddress; // useful for doubly linked list
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
		// newNode->totalScore = scoreQ1+scoreQ2+scoreQ3;
		newNode->totalScore = totalScore;

		newNode->nextAddress = nullptr;
		newNode->prevAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}

	//function to get the head of the list
	StudentResponseNode* getHead() {
		return head;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// function to insert to the end of the list
	// insert student node to end of the list, time complexity o(1)
	void insertToEnd(int studentId, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore)
	{
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

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// function to display the contents of the linked list nodes
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
			// Print the details of the current node
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

	void DisplaySingleStudentResponsesForAutoExecution(StudentResponseNode* studentIDNode, int rank)
	{
		if (studentIDNode != nullptr) {
			cout << "---------------------------------" << endl;
			cout << "Rank: " << rank << endl;
			cout << "Student ID: " << studentIDNode->studentID << endl;
			cout << "Question 1: " << studentIDNode->question1 << " - Scored: " << studentIDNode->scoreQ1 << endl;
			cout << "Question 2: " << studentIDNode->question2 << " - Scored: " << studentIDNode->scoreQ2 << endl;
			cout << "Question 3: " << studentIDNode->question3 << " - Scored: " << studentIDNode->scoreQ3 << endl;
			cout << "Total Score: " << studentIDNode->totalScore << endl;
			cout << "---------------------------------" << endl;
		}
		else {
			cout << "Student ID not found" << endl;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//search the student and display their data
	void searchStudentID( int studentIDinput, int size) {
		int rank = 1;
		
		if (head == nullptr)
		{
			cout << "The " << this->linkedlistName << " Linked List is empty!" << endl;
			return;
		}
		if (studentIDinput == head->studentID) {
			DisplaySingleStudentResponsesForAutoExecution(head, rank);
			return;
		}
		else if (studentIDinput == tail->studentID) {
			rank = size;
			DisplaySingleStudentResponsesForAutoExecution(tail, rank);
			return;
		}
		else {
			StudentResponseNode* current = head;
			while (current != nullptr) {
				if (current->studentID == studentIDinput) {
					DisplaySingleStudentResponsesForAutoExecution(current, rank);
					return;
				}
				rank++;
				current = current->nextAddress;
			}
		}
		cout << "Student ID not found!" << endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//search function
	void searchStudentIDInSortedList() {
		int studentIDinput;
		cout << "Enter the student ID to display their data: ";
		cin >> studentIDinput;
		searchStudentID(studentIDinput,size);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// function to insert student's ID and total score from the linked list into the tree data structure and then display the top 30 students with the highest scores
	void AnnounceTop30Winners()
	{
		// Create a binary search tree
		BinaryTree tree;
		StudentResponseNode* current = head;
		// Traverse the linked list of student responses
		int count = 0;
		while (current != nullptr && count < 30)
		{
			tree.insertNode(current->studentID);
			current = current->nextAddress;
			count++;
		}
		tree.levelOrderTraversal(30);
		int studentID;
		string input;
		cout << "Do you want to check if you are one of the Top 30 Winners? (Y/N)";
		cin >> input;
		if (input == "Y" || input == "y") {
			cout << "Enter Student ID: ";
			cin >> studentID;
			tree.Search(studentID, 30);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Quick sort logic 
	//https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/

	//getting the last node of the list
	StudentResponseNode* getLastNode(StudentResponseNode* current) {
		while (current != nullptr && current->nextAddress != nullptr)
			current = current->nextAddress;
		return current;
	}

	StudentResponseNode* partition(StudentResponseNode* head, StudentResponseNode* end, StudentResponseNode** newHead, StudentResponseNode** newEnd) {

		StudentResponseNode* pivot = end; //setting the pivot as the last node of the list

		StudentResponseNode* prev = nullptr;
		StudentResponseNode* current = head;
		StudentResponseNode* tail = pivot;

		while (current != pivot) {
			if (current->totalScore > pivot->totalScore) {
				if ((*newHead) == NULL)
					(*newHead) = current;

				prev = current;
				current = current->nextAddress;
			}
			//condition when the node's total score is greater than the pivot's total score
			else
			{
				if (prev)
					prev->nextAddress = current->nextAddress;
				StudentResponseNode* temp = current->nextAddress;
				current->nextAddress = nullptr;
				tail->nextAddress = current;
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
	StudentResponseNode* sortingFunction(StudentResponseNode* head, StudentResponseNode* end)
	{
		//checking if the list is empty
		if (!head || head == end)
			return head;

		//creating pointers to track the sublist's elements
		StudentResponseNode* newHead = nullptr, * newEnd = nullptr;

		//creating the pivot node to compare the nodes for sorting the list
		StudentResponseNode* pivot = partition(head, end, &newHead, &newEnd);

		//block of code to sort the sublist that contain total score lesser than or equal to the pivot
		if (newHead != pivot) {
			StudentResponseNode* temp = newHead;
			while (temp->nextAddress != pivot) {
				temp = temp->nextAddress;
			}
			temp->nextAddress = nullptr;

			//sorting the sublist using the recursive function
			newHead = sortingFunction(newHead, temp);

			//setting back the pivot to be the last node
			temp = getLastNode(newHead);
			temp->nextAddress = pivot;
		}

		//sorting the node that is greater than the pivot in the list
		pivot->nextAddress = sortingFunction(pivot->nextAddress, newEnd);

		return newHead;
	}

	//function to perform the sorting operation
	void quickSort(AutomatedStudentResponseDoubly& list)
	{
		//updating the head to the new head of the sorted list
		list.head = list.sortingFunction(list.head, list.getLastNode(list.head));
		//updating the tail to the new tail of the sorted list
		list.tail = list.getLastNode(list.head);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Binary search algorithm
	StudentResponseNode* middleNode(StudentResponseNode* head, StudentResponseNode* tail) {

		StudentResponseNode* pointer1 = head;
		StudentResponseNode* pointer2 = head->nextAddress;

		if (head == nullptr) {
			return nullptr;
		}

		while (pointer1 != tail) {
			pointer1 = pointer1->nextAddress;
			if (pointer1 != tail) {
				pointer2 = pointer2->nextAddress;
				pointer1 = pointer1->nextAddress;
			}
		}

		return pointer2;
	}

	StudentResponseNode* binarySearch(StudentResponseNode* head, int studentID) {
		StudentResponseNode* firstNode = head;
		StudentResponseNode* lastNode = nullptr;

		while (lastNode != firstNode)
		{
			StudentResponseNode* midNode = middleNode(firstNode, lastNode);

			if (midNode == nullptr) {
				return nullptr;
			}

			if (midNode->studentID == studentID)
			{
				return midNode;
			}

			else if (midNode->studentID > studentID)
			{
				lastNode = midNode;
			}
			else
			{
				firstNode = midNode->nextAddress;
			}
		}
		//student ID is not in the list
		cout << "Student ID " << studentID << " does not exist!" << endl;
		return nullptr;
	}

	void displaySingleStudent(StudentResponseNode* studentIDNode) {

		if (studentIDNode != nullptr) {
			cout << "---------------------------------" << endl;
			cout << "Student ID: " << studentIDNode->studentID << endl;
			cout << "Question 1: " << studentIDNode->question1 << " - Scored: " << studentIDNode->scoreQ1 << endl;
			cout << "Question 2: " << studentIDNode->question2 << " - Scored: " << studentIDNode->scoreQ2 << endl;
			cout << "Question 3: " << studentIDNode->question3 << " - Scored: " << studentIDNode->scoreQ3 << endl;
			cout << "Total Score: " << studentIDNode->totalScore << endl;
			cout << "---------------------------------" << endl;
		}
		else {
			cout << "Student ID not found" << endl;
		}
	}

	void searchStudentID(AutomatedStudentResponseDoubly& studentList, int studentID) {
		StudentResponseNode* studentNode = studentList.binarySearch(studentList.head, studentID);

		if (studentNode != nullptr) {
			studentList.displaySingleStudent(studentNode);
		}
	}
};
#endif // AUTOMATED_STUDENT_RESPONSE_HPP