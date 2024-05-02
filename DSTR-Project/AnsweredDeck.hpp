#ifndef ANSWERED_DECK_HPP
#define ANSWERED_DECK_HPP
#include "Enum.hpp"
#include <iostream>

using namespace std;

struct AnsweredDeckNode {

	// data attributes
	string myQuestion;
	AnswerTypeTF myAnswer;
	int myScore;

	// link
	AnsweredDeckNode* nextAddress;
};

class AnsweredDeck {

	// properties of the student response linked list
	AnsweredDeckNode* head;
	string linkedlistName;
	int size;

public:
	// constructor to build the linked list
	AnsweredDeck(string linkedlistName) {
		this->linkedlistName = linkedlistName;
		head = nullptr;
		size = 0;
	}

	// function to create a new node for the linked list;
	AnsweredDeckNode* createNewNode(string myQuestion, AnswerTypeTF myAnswer, int myScore) {
		// to create struct in heap location
		AnsweredDeckNode* newNode = new AnsweredDeckNode;

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
		AnsweredDeckNode* newNode = createNewNode(myQuestion, myAnswer, myScore);

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
#endif // ANSWERED_DECK_HPP