#include <iostream>

using namespace std;

enum ResponseType { TRUE_NEW, FALSE_NEW, SKIP, TRUE_DISCARD, FALSE_DISCARD };

struct StudentResponseNode {

	// data attributes
	int studentID;
	string question1;
	string question2;
	string question3;
	ResponseType round1;
	ResponseType round2;
	ResponseType round3;
	int score;

	// link
	StudentResponseNode* nextAddress;
};

class automatedStudentResponse {

	// properties of the student response linked list
	StudentResponseNode*head;
	string linkedlistName;
	int size;

public:
	// constructor to build the linked list
	automatedStudentResponse(string linkedlistName) {
		this->linkedlistName = linkedlistName;
		head = nullptr;
		size = 0;
	}

	// function to create a new node for the linked list;
	StudentResponseNode* createNewNode(int studentID, string question1, string question2, string question3, ResponseType round1, ResponseType round2, ResponseType round3, int score) {
		// to create struct in heap location
		StudentResponseNode* newNode = new StudentResponseNode;

		// data attribute of a single node is stored in the memory location
		newNode->studentID = studentID;
		newNode->question1 = question1;
		newNode->question2 = question2;
		newNode->question3 = question3;
		newNode->round1 = round1;
		newNode->round2 = round2;
		newNode->round3 = round3;
		newNode->score = score;
		newNode->nextAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}

	// function to insert to the front of the list
	void insertToEnd(int studentID, string question1, string question2, string question3, ResponseType round1, ResponseType round2, ResponseType round3, int score) {

		// function to create an independent node by calling the createNewNode function
		StudentResponseNode* newNode = createNewNode(studentID, question1, question2, question3, round1, round2, round3, score);

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


};