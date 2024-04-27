// data included : question, marks
// first in first out logic
// havent including the marks adding function (jia, 28/04)
#pragma once
#include <iostream>
using namespace std;

struct LinkedListNode {
	// data
	string question;
	double marks;

	// link
	LinkedListNode* next;
	LinkedListNode* prev;
};

class LinkedList {
	// initial declaration
	LinkedListNode* head, *tail;
	string listname;
	int size;

public:
	// constructor
	LinkedList(string listname) {
		this->listname = listname;
		head = tail = nullptr;
		size = 0;
	}

	LinkedListNode* createNewNode(string question, double marks) {
		LinkedListNode* newnode = new LinkedListNode;

		newnode->question = question;
		newnode->marks = marks;

		newnode->next = nullptr;
		newnode->prev = nullptr;

		return newnode;
	}

	// the new added discarded card should be at the bottom of the card stack 
	// adding new discarded card to the discarded area
	void addNewDiscardedCard(string question, double marks) {
		LinkedListNode* newnode = createNewNode(question, marks * 80);

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
	void takeDiscardedCard() {
		LinkedListNode* current = head;
		
		// case 1: the list is empty
		if (head == nullptr) {
			return;
		}
		// case 2: cards existing in the area
		else {
			head = head->next;
			delete current;
			size--;
		}
	}
};