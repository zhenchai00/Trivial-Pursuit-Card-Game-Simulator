// data included : question, marks
// first in first out logic
// havent including the marks adding function (jia, 28/04)

#ifndef DISCARDED_DECK_HPP
#define DISCARDED_DECK_HPP
#include <iostream>
using namespace std;

struct DiscardedCardLinkedListNode
{
	// data
	string question;
	AnswerTypeTF answer;
	double marks;

	// link
	DiscardedCardLinkedListNode *next;
	DiscardedCardLinkedListNode *prev;
};

class DiscardedCardLinkedList
{
	// initial declaration
	DiscardedCardLinkedListNode *head, *tail;
	string listname;
	int size;

public:
	// constructor
	DiscardedCardLinkedList(string listname)
	{
		this->listname = listname;
		head = tail = nullptr;
		size = 0;
	}

	DiscardedCardLinkedListNode *createNewNode(string question, AnswerTypeTF answer, double marks)
	{
		DiscardedCardLinkedListNode *newnode = new DiscardedCardLinkedListNode;

		newnode->question = question;
		newnode->answer = answer;
		newnode->marks = marks;

		newnode->next = nullptr;
		newnode->prev = nullptr;

		return newnode;
	}

	// the new added discarded card should be at the bottom of the card stack
	// adding new discarded card to the discarded area
	void addNewDiscardedCard(string question, AnswerTypeTF answer, double marks)
	{
		DiscardedCardLinkedListNode *newnode = createNewNode(question, answer, marks);

		// case 1: if the discarded card area have no card
		if (head == nullptr)
		{
			head = tail = newnode;
		}
		// case 2: cards have existed in the area
		else
		{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		size++;
	}

	DiscardedCardLinkedListNode *takeDiscardedCard()
	{
		// case 1: the list is empty
		if (head == nullptr)
		{
			return nullptr;
		}
		// case 2: return node and then delete node

		DiscardedCardLinkedListNode *current = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}

		// create copy of the node's data before delete it
		DiscardedCardLinkedListNode *nodeData = new DiscardedCardLinkedListNode;
		nodeData->question = current->question;
		nodeData->answer = current->answer;
		nodeData->marks = current->marks;

		delete current;
		size--;

		return nodeData;
	}

	void display()
	{
		DiscardedCardLinkedListNode *current = head;

		cout << "********************************" << endl;
		while (current != nullptr)
		{
			cout << " " << current->question << endl;
			cout << " " << current->answer << endl;
			cout << " " << current->marks << endl;
			current = current->next;
		}
		cout << "empty" << endl;
		cout << "********************************" << endl;
	}

	// check whether empty
	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}

	// display the header card -------- used in manual mode
	string top()
	{
		if (head != nullptr)
		{
			string question = head->question;
			return question;
		}
	}
};

#endif // DISCARDED_DECK_HPP