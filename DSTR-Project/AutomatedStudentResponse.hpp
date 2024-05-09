// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef AUTOMATED_STUDENT_RESPONSE_HPP
#define AUTOMATED_STUDENT_RESPONSE_HPP
#include "Enum.hpp"
#include <iostream>
#include <iomanip>
#include "Top30Winners.hpp"

using namespace std;

struct StudentResponseNode {

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
	StudentResponseNode* prevAddress; //useful for doubly linked list
};

class AutomatedStudentResponse {

	// properties of the student response linked list
	StudentResponseNode*head, *tail;
	string linkedlistName;
	int size;

public:
	// constructor to build the linked list
	AutomatedStudentResponse(string linkedlistName) {
		this->linkedlistName = linkedlistName;
		head = nullptr;
		size = 0;
	}

	// function to create a new node for the linked list;
	StudentResponseNode* createNewNode(int studentID, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore) {
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
		//newNode->totalScore = scoreQ1+scoreQ2+scoreQ3;
		newNode->totalScore = totalScore;
		
		newNode->nextAddress = nullptr;
		newNode->prevAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}


	// function to insert to the front of the list
	void insertToEnd(int studentID, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore) {

		// function to create an independent node by calling the createNewNode function
		StudentResponseNode* newNode = createNewNode(studentID, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3,totalScore);

		// insert the new node to the end of the linked list
		if (head == nullptr) { // this is the first node in the linked list
			head = newNode;
			//cout << head->question1 << " " << head->scoreQ1 << " " << head->totalScore << " " << head->studentID << endl;
		}
		else { // this is not the first node in the linkedlist
			StudentResponseNode* current = head;
			//cout << head->question1 << " " << head->scoreQ1 << " " << head->totalScore << " " << head->studentID << endl;
			while (current->nextAddress != nullptr) { // if node not yet the last node, move again
				current = current->nextAddress;
			}
			// if the last node is found
			current->nextAddress = newNode;
		}
		size++;
	}
	
	//has bugs atm (prolly would have to switch to doubly linked list later to use this function)
	//inserting nodes while sorting the doubly linked list
	void insertToSortedList(int studentID, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int toalScore)
	{
		StudentResponseNode* newnode = createNewNode(studentID, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, toalScore);

		//empty node case: insert node to the empty list
		if (head == nullptr)
		{
			head = tail = newnode;
		}
		//insert from front of list case: when newnode's total score is smaller than head's total score
		else if (newnode->totalScore <= head->totalScore)
		{
			newnode->nextAddress = head;
			head->prevAddress = newnode;
			head = newnode;
		}
		//insert from end of list case: when newnode's total score is larger than tail's total score
		else if (newnode->totalScore >= tail->totalScore)
		{
			newnode->prevAddress = tail;
			tail->nextAddress = newnode;
			tail = newnode;
		}
		//insert in middle case: when newnode's total score is larger than head and smaller than tail's total score
		else 
		{
			StudentResponseNode* current = head->nextAddress;
			while (current != nullptr && current->totalScore < newnode->totalScore) {
				current = current->nextAddress;
			}
			if (current != nullptr)
			{
				current->prevAddress->nextAddress = newnode;
				newnode->prevAddress = current->prevAddress;
				current->prevAddress = newnode;
				newnode->prevAddress = current;
			}
			else
			{
				tail->nextAddress = newnode;
				newnode->prevAddress = tail;
				tail = newnode;
			}
		}
		size++;
	}

	//should only be executed if the list is sorted in the order lowest to higheset grade
	//function to display the leaderboard in reverse order so that it displays from student with highest grade to lowest
	void displayReversedLeaderboardList() {
		//pointer to refer to the last node
		StudentResponseNode* current = tail;

		//code to display the content of the list

		cout << string(145, '=') << "GAME REPORT" << string(145, '=') << endl;

		//code for displaying the header of the table
		cout << setw(10) << "Rank" << setw(20) << " " << "StudentID" << setw(20) << " " << "Round1" << setw(20) << " " << "Round2" << setw(20) << " " << "Round3" << setw(20) << " " << "OverallScore" << endl;
		cout << string(300, '-') << endl;

		int rankOfStudent = 1; //declaring the rank
		while (current != nullptr) { //loop until current node reaches null pointer
			cout << setw(10) << rankOfStudent;
			cout << setw(20) << " " << current->studentID << " ";
			cout << setw(20) << "  " << current->question1 << setw(20) << " " << current->question2 << setw(20) << " " << current->question3;
			cout << setw(20) << current->totalScore << endl;
			// Display scores below the questions
			cout << setw(46) << current->scoreQ1 << setw(20) << " " << current->scoreQ2 << setw(20) << " " << current->scoreQ3 << endl;
			cout << string(300, '-') << endl;

			// Move to the previous node
			current = current->prevAddress;
			rankOfStudent++; //iterating the rank after every loop
		}
		//display list already finish display
		cout << "Content of list " << linkedlistName << " is done displaying in the screen!" << endl << endl;
	}


	//insert and display for SLL 
	
	//insert
	void insertToSorted(int studentID, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int toalScore) {
		StudentResponseNode* newnode = createNewNode(studentID, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, toalScore);
		if (head == nullptr)
		{
			head = newnode;
		}
		else if (newnode->totalScore <= head->totalScore)
		{
			newnode->nextAddress = head;
			head = newnode;
		}
		else
		{
			StudentResponseNode* current = head->nextAddress;
			StudentResponseNode* prev = head;

			while (current != nullptr)
			{
				if (current->totalScore > newnode->totalScore)
				{
					break;
				}
				//otherwise
				prev = current;
				current = current->nextAddress;
			}
			//if found the correct location, add the item to the location (middle / end list) using below lines
			prev->nextAddress = newnode;
			newnode->nextAddress = current;
		}
		size++;
	}

	//display
	void DisplayInOrder() {
		for (int limit = size - 1; limit >= 0; limit--) {
			StudentResponseNode* current = head;
			for (int i = 0; i < limit; i++) {
				current = current->nextAddress;
			}
			cout << "Student ID: " << current->studentID << endl;
			cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
			cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
			cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
			cout << "Total Score: " << current->totalScore << endl;
			cout << "---------------------------------" << endl;
		}
		cout << endl;
	}

	//sorting the function


	// function to display the contents of the linked list nodes
	void DisplayStudentResponsesForAutoExecution() {
		// begin with the head node
		StudentResponseNode* current = head;

		// to check if the list is empty
		if (current == nullptr) {
			cout << "The linked list is empty." << endl;
			return;
		}

		// to loop through the linked list
		cout << "Displaying student responses:" << endl;
		while (current != nullptr) {
			// Print the details of the current node
			cout << "Student ID: " << current->studentID << endl;
			cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
			cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
			cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
			cout << "Total Score: " << current->totalScore << endl;
			cout << "---------------------------------" << endl;

			// move to the next node
			current = current->nextAddress;
		}
	}

	// function to search for a node based on studentID and update its attributes
	void searchAndUpdateNodeRoundTwo(int studentID, string question2, int scoreQ2, int totalScore) {
		// begin with the head node
		StudentResponseNode* current = head;

		// to loop through the linked list
		while (current != nullptr) { // 0(n)
			// to check if the current node's studentID matches the provided studentID
			if (current->studentID == studentID) {
				// to update the attributes of the current node
				current->question2 = question2;
				current->scoreQ2 = scoreQ2;
				current->totalScore = current->totalScore + totalScore;

				return;
			}

			// move to the next node
			current = current->nextAddress;
		}

		// if no node with the specified studentID is found 
		cout << "Node with student ID " << studentID << " not found." << endl;
	}

	// function to search for a node based on studentID and update its attributes
	void searchAndUpdateNodeRoundThree(int studentID, string question3, int scoreQ3, int totalScore) {
		// begin with the head node
		StudentResponseNode* current = head;

		// to loop through the linked list
		while (current != nullptr) { // 0(n)
			// to check if the current node's studentID matches the provided studentID
			if (current->studentID == studentID) {
				// to update the attributes of the current node
				current->question3 = question3;
				current->scoreQ3 = scoreQ3;
				current->totalScore = current->totalScore + totalScore;

				return;
			}

			// move to the next node
			current = current->nextAddress;
		}

		// if no node with the specified studentID is found 
		cout << "Node with student ID " << studentID << " not found." << endl;
	}
	
	//function to insert student's ID and total score from the linked list into the tree data structure and then display the top 30 students with the highest scores
	void AnnounceTop30Winners() {
		// Create a binary search tree
		Tree t;
		StudentResponseNode* current = head;
		// Traverse the linked list of student responses
		while (current != nullptr) {
			t.insert(current->studentID, current->totalScore);
			current = current->nextAddress;
		}
		int count = 0;
		// Print the top 30 winners in descending order of total scores
		t.inOrder(count);

		int studentID;
		cout << "Enter your student ID to search for: ";
		cin >> studentID;

		int position = -1; // Initialize position to -1 (not found)
		int score = -1; // Initialize score to -1

		// Search for the student ID in the top 30 winners
		t.searchTop30(studentID, position, score);

		// Display the search result
		if (position != -1) {
			cout << "Congratulations! You are placed " << position << " with an overall score of " << score << endl;
		}
		else {
			cout << "Sorry, you are not in the top 30 winners." << endl;
		}
	}

};
#endif // AUTOMATED_STUDENT_RESPONSE_HPP