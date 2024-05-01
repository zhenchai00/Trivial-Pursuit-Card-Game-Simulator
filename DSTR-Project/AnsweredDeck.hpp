#include "Enum.hpp"
#include <iostream>

using namespace std;

struct answeredDeckNode {

	// data attributes
	string myQuestion;
	AnswerTypeTF myAnswer;
	int myScore;

	// link
	answeredDeckNode* nextAddress;
};

class answeredDeck {

	// properties of the student response linked list
	answeredDeckNode* head;
	string linkedlistName;
	int size;

public:
	// constructor to build the linked list
	answeredDeck(string linkedlistName) {
		this->linkedlistName = linkedlistName;
		head = nullptr;
		size = 0;
	}

	// function to create a new node for the linked list;
	answeredDeckNode* createNewNode(string myQuestion, AnswerTypeTF myAnswer, int myScore) {
		// to create struct in heap location
		answeredDeckNode* newNode = new answeredDeckNode;

		// data attribute of a single node is stored in the memory location
		newNode->myQuestion = myQuestion;
		newNode->myAnswer = myAnswer;
		newNode->myScore = myScore;
		newNode->nextAddress = nullptr;

		// return the memory address to the insert function
		return newNode;
	}

	void InsertFront(string myQuestion, AnswerTypeTF myAnswer, int myScore)
	{
		// function to create an independent node by calling the createNewNode function
		answeredDeckNode* newNode = createNewNode(myQuestion, myAnswer, myScore);

		// insert the new node to the front of the linked list
		if (head == nullptr) // inserted if this is the first node in the linked list
		{
			head = newNode;
		}
		else // if there is no nodes present in the linked list
		{
			newNode->nextAddress = head;
			head = newNode;
		}
		size++;
	}



};