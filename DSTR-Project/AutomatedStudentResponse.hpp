// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef AUTOMATED_STUDENT_RESPONSE_HPP
#define AUTOMATED_STUDENT_RESPONSE_HPP
#include "Enum.hpp"
#include "AnsweredDeck.hpp"
#include "UnansweredDeck.hpp"
#include "DiscardedCard.hpp"

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
		}
		else { // this is not the first node in the linkedlist
			StudentResponseNode* current = head;
			while (current->nextAddress != nullptr) { // if node not yet the last node, move again
				current = current->nextAddress;
			}
			// if the last node is found
			current->nextAddress = newNode;
		}
		size++;
	}

	// Function to display the contents of the linked list nodes
	void DisplayStudentResponsesForAutoExecution() {
		// Start with the head node
		StudentResponseNode* current = head;

		// Check if the list is empty
		if (current == nullptr) {
			cout << "The linked list is empty." << endl;
			return;
		}

		// Iterate through the linked list
		cout << "Displaying student responses:" << endl;
		while (current != nullptr) {
			// Print the details of the current node
			cout << "Student ID: " << current->studentID << endl;
			cout << "Question 1: " << current->question1 << " - Scored: " << current->scoreQ1 << endl;
			cout << "Question 2: " << current->question2 << " - Scored: " << current->scoreQ2 << endl;
			cout << "Question 3: " << current->question3 << " - Scored: " << current->scoreQ3 << endl;
			cout << "Total Score: " << current->totalScore << endl;
			cout << "---------------------------------" << endl;

			// Move to the next node
			current = current->nextAddress;
		}
	}


};
#endif // AUTOMATED_STUDENT_RESPONSE_HPP