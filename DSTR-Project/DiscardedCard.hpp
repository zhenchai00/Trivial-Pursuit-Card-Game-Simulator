// data included : question, marks
// first in first out logic
// havent including the marks adding function (jia, 28/04)

#ifndef DISCARDED_DECK_HPP
#define DISCARDED_DECK_HPP
#include <iostream>
using namespace std;

struct DiscardedCardLinkedListNode {
	// data
	string question;
	AnswerTypeTF answer;
	double marks;

	// link
	DiscardedCardLinkedListNode* next;
	DiscardedCardLinkedListNode* prev;
};

class DiscardedCardLinkedList {
	// initial declaration
	DiscardedCardLinkedListNode* head, *tail;
	string listname;
	int size;

public:
	// constructor
	DiscardedCardLinkedList(string listname) {
		this->listname = listname;
		head = tail = nullptr;
		size = 0;
	}

	DiscardedCardLinkedListNode* createNewNode(string question, AnswerTypeTF answer,double marks) {
		DiscardedCardLinkedListNode* newnode = new DiscardedCardLinkedListNode;

		newnode->question = question;
		newnode->answer = answer;
		newnode->marks = marks;

		newnode->next = nullptr;
		newnode->prev = nullptr;

		return newnode;
	}

	// the new added discarded card should be at the bottom of the card stack 
	// adding new discarded card to the discarded area
	void addNewDiscardedCard(string question, AnswerTypeTF answer, double marks) {
		DiscardedCardLinkedListNode* newnode = createNewNode(question, answer, marks);

		// case 1: if the discarded card area have no card
		if (head == nullptr) {
			head = tail = newnode;
		}
		// case 2: cards have existed in the area
		else {
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		size++;
	}

	// card been answer, delete the card been answered (only take the top one)
	DiscardedCardLinkedListNode* takeDiscardedCard() {
		DiscardedCardLinkedListNode* current = head, nodeFound;
		
		// case 1: the list is empty
		if (head == nullptr) {
			return nullptr;
		}
		// case 2: return node and then delete node
		else {
			DiscardedCardLinkedListNode* nodeFound = head;
			head = head->next;
			delete current;
			size--;
			return nodeFound;
		}
	}

};

#endif // DISCARDED_DECK_HPP