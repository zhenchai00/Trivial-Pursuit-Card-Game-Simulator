#include <iostream>

using namespace std;

enum responseType { TRUE_NEW, FALSE_NEW, SKIP, TRUE_DISCARD, FALSE_DISCARD };

struct studentResponseNode {

	// data attributes
	int studentID;
	responseType round1;
	responseType round2;
	responseType round3;
	int score;

	// link
	studentResponseNode* nextAddress;
};

class automatedStudentResponse {

	// properties of the student response linked list
	studentResponseNode*head;
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
	studentResponseNode* createNewNode(int studentID, responseType round1, responseType round2, responseType round3, int score) {
		// to create struct in heap location
		studentResponseNode* newNode = new studentResponseNode;

		// data attribute of a single node is stored in the memory location
		newNode->studentID = studentID;
		newNode->round1 = round1;
		newNode->round2 = round2;
		newNode->round3 = round3;
		newNode->nextAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}
};