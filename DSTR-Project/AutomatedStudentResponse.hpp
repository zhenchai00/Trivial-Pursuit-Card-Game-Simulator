// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef AUTOMATED_STUDENT_RESPONSE_HPP
#define AUTOMATED_STUDENT_RESPONSE_HPP
#include "Enum.hpp"
#include <iostream>

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

	// link
	StudentResponseNode* nextAddress;
};

class AutomatedStudentResponse {

	// properties of the student response linked list
	StudentResponseNode*head;
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
		newNode->totalScore = totalScore;
		newNode->nextAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}

	// function to insert to the front of the list
	void insertToEnd(int studentID, string question1, string question2, string question3, int scoreQ1, int scoreQ2, int scoreQ3, int totalScore) {

		// function to create an independent node by calling the createNewNode function
		StudentResponseNode* newNode = createNewNode(studentID, question1, question2, question3, scoreQ1, scoreQ2, scoreQ3, totalScore);

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



};
#endif // AUTOMATED_STUDENT_RESPONSE_HPP