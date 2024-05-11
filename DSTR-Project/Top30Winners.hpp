#pragma once
#include <iostream>
using namespace std;

struct TreeNode
{
	// data
	int studentID;
	// tree node
	struct TreeNode *left;
	struct TreeNode *right;
};

class Queue
{
private:
	struct Node
	{
		TreeNode* data;
		Node* next;
	};

	Node* front;
	Node* rear;

public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(TreeNode* data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	TreeNode* dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return nullptr;
		}
		else
		{
			Node* temp = front;
			TreeNode* data = temp->data;
			front = front->next;
			delete temp;
			return data;
		}
	}

	bool isEmpty()
	{
		return front == nullptr;
	}
};

class BinaryTree
{
public:
	// properties in tree
	TreeNode* root;

	// constructor
	BinaryTree()
	{
		root = nullptr;
	}

	TreeNode* createNewNode(int studentID) {
		TreeNode* newnode = new TreeNode;
		newnode->studentID = studentID;
		newnode->left = nullptr;
		newnode->right = nullptr;

		return newnode;
	}

	void insertNode(int studentID)
	{
		TreeNode* newnode = createNewNode(studentID);
		if (root == nullptr)
		{
			root = newnode;
		}
		else {
			Queue q;
			TreeNode* current = root;
			q.enqueue(current);
			while (!q.isEmpty()) {
				current = q.dequeue();
				if (current->left == nullptr) {
					current->left = newnode;
					break;
				}
				else {
					q.enqueue(current->left);
				}
				if (current->right == nullptr) {
					current->right = newnode;
					break;
				}
				else {
					q.enqueue(current->right);
				}
			}
		}
	}

	void levelOrderTraversal()
	{
		Queue q;
		q.enqueue(root);

		int nodesInCurrentLevel = 1;
		int nodesInNextLevel = 0;
		int count = 109;
		int count2 = 116;
		int count3 = 110;
		int winnerCount = 1;

		cout << "Top 30 Winners: " << endl;
		while (!q.isEmpty()) {
			TreeNode* node = q.dequeue();

			for (int i = 0; i < count; i++) {
				cout << " ";
			}
			if (nodesInNextLevel > 0) {
				for (int i = 0; i < count; i++) {
					cout << " ";
				}
			}
			if (node->studentID < 10) {
				cout << "Student ID:" << node->studentID << "  ";
			}
			else {
				cout << "Student ID:" << node->studentID << " ";
			}

			// Enqueue left child
			if (node->left != nullptr) {
				q.enqueue(node->left);
				nodesInNextLevel++;
			}

			// Enqueue right child
			if (node->right != nullptr) {
				q.enqueue(node->right);
				nodesInNextLevel++;
			}

			// All nodes in the current level are processed
			nodesInCurrentLevel--;

			// Move to the next line if all nodes in the current level are processed
			if (nodesInCurrentLevel == 0) {
				if (count <= 20) {
					count = 0;
				}
				else {
					if (count % 2 == 0) {
						count /= 2;
						count -= 4;
					}
					else {
						count /= 2;
						count -= 3;
					}
				}
				cout << endl;
				int nodesInNextLevel2 = nodesInNextLevel;
				int nodesInNextLevel3 = 0;
				if (nodesInNextLevel == 15) {
					nodesInNextLevel2 = 16;
				}
				for (int i = 0; i < count3; i++) {
					cout << " ";
				}
				if (winnerCount == 1) {
					cout << winnerCount << "st " << "Winner" << " ";
				}
				else if (winnerCount == 2) {
					cout << winnerCount << "nd " << "Winner" << " ";
				}
				else if (winnerCount == 3) {
					cout << winnerCount << "rd " << "Winner" << " ";
				}
				else if (winnerCount <= 10) {
					cout << winnerCount << "th " << "Winner" << " ";
				}
				else {
					cout << winnerCount << "th " << "Winner";
				}
				if (winnerCount == 16) {
					for (winnerCount++; winnerCount < 31; winnerCount++) {
						cout << "   ";
						cout << winnerCount << "th " << "Winner";
					}
				}
				for (int i = 0; i < nodesInNextLevel2 / 2 - 1; i++) {
					winnerCount++;
					for (int i = 0; i < count3 * 2 + 1; i++) {
						cout << " ";
					}
					if (winnerCount == 1) {
						cout << winnerCount << "st " << "Winner" << " ";
					}
					else if (winnerCount == 2) {
						cout << winnerCount << "nd " << "Winner" << " ";
					}
					else if (winnerCount == 3) {
						cout << winnerCount << "rd " << "Winner" << " ";
					}
					else if (winnerCount <= 10) {
						cout << winnerCount << "th " << "Winner" << " ";
					}
					else {
						cout << winnerCount << "th " << "Winner";
					}
				}
				cout << endl;
				count3 /= 2;
				count3 -= 3;
				winnerCount++;
				if (nodesInNextLevel > 1) {
					for (int i = 0; i < count2; i++) {
						cout << " ";
					}
					cout << "|"; 

				}
				for (int i = 0; i < nodesInNextLevel2 / 2 - 1; i++) {
					for (int i = 0; i < count2*2-1; i++) {
						cout << " ";
					}
					cout << "|";
				}
				cout << endl;
				count2 /= 2;
				if (nodesInNextLevel > 1) {
					for (int i = 0; i < count2; i++) {
						cout << " ";
					}
					for (int i = 0; i < count2 * 2 + 1; i++) {
						cout << "-";
					}
				}
				for (int i = 0; i < nodesInNextLevel / 2 - 1; i++) {
					for (int i = 0; i < count2 * 2 - 1; i++) {
						cout << " ";
					}
					for (int i = 0; i < count2 * 2 + 1; i++) {
						cout << "-";
					}
				}
				if (nodesInNextLevel == 15) {
					for (int i = 0; i < count2 * 2 - 1; i++) {
						cout << " ";
					}
					for (int i = 0; i < count2 * 2/2 + 1; i++) {
						cout << "-";
					}
				}
				cout << endl;
				if (nodesInNextLevel > 1) {
					for (int i = 0; i < count2; i++) {
						cout << " ";
					}
					cout << "|";
				}
				for (int i = 0; i < nodesInNextLevel-1; i++) {
					for (int i = 0; i < count2 * 2 - 1; i++) {
						cout << " ";
					}
					cout << "|";
				}
				cout << endl;
				nodesInCurrentLevel = nodesInNextLevel;
				nodesInNextLevel = 0;
			}
		}
	}
};