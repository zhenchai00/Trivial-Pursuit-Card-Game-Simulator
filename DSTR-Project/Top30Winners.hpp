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

	void levelOrderTraversal(int studentsNumber)
	{
		Queue q;
		q.enqueue(root);

		int nodesInCurrentLevel = 1;
		int nodesInNextLevel = 0;
		int count = 109;
		int count2 = 116;
		int count3 = 110;
		int winnerCount = 1;
		int loopCounter = 1;
		int numOfStudents = 1;

		cout << "Top 30 Winners: " << endl;
		while (!q.isEmpty()) {
			TreeNode* node = q.dequeue();
			for (int i = 0; i < count; i++) {
				cout << " ";
			}
			if (loopCounter > 1) {
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
				numOfStudents += 1;
			}

			// Enqueue right child
			if (node->right != nullptr) {
				q.enqueue(node->right);
				nodesInNextLevel++;
				numOfStudents += 1;
			}

			// All nodes in the current level are processed
			nodesInCurrentLevel--;
			loopCounter++;

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
				int nodesInNextLevel4 = nodesInNextLevel;
				/*if (nodesInNextLevel == 15) {
					nodesInNextLevel2 = 16;
				}*/
				if (nodesInNextLevel % 2 == 1) {
					nodesInNextLevel4++;
				}
				if (numOfStudents > 3 && numOfStudents < 8) {
					nodesInNextLevel2 = 4;
				}
				else if (numOfStudents >= 8 && numOfStudents < 16) {
					nodesInNextLevel2 = 8;
				}
				else if (numOfStudents >= 16 && numOfStudents < 31) {
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
				
				/*if (winnerCount == 16) {
					for (winnerCount++; winnerCount < 31; winnerCount++) {
						cout << "   ";
						cout << winnerCount << "th " << "Winner";
					}
				}*/
				if (nodesInNextLevel != 0) {
					for (int i = 0; i < nodesInNextLevel2 / 2 - 1; i++) {
						winnerCount++;
						for (int i = 0; i < count3 * 2 + 1; i++) {
							cout << " ";
						}
						if (winnerCount == 3) {
							cout << winnerCount << "rd " << "Winner" << " ";
						}
						else if (winnerCount <= 10) {
							cout << winnerCount << "th " << "Winner" << " ";
						}
						else {
							cout << winnerCount << "th " << "Winner";
						}
					}
				}
				if (nodesInNextLevel == 0) { //Display last line of winners
					winnerCount += 1;
					for (int i = winnerCount; i < studentsNumber+1; i++) {
						//cout << i;
						for (int i = 0; i < count3 * 2 + 1; i++) {
							cout << " ";
						}
						if (i == 3) {
							cout << i << "rd " << "Winner" << " ";
						}
						else if (i <= 10) {
							cout << i << "th " << "Winner" << " ";
						}
						else {
							cout << i << "th " << "Winner";
						}
					}
				}
				cout << endl;
				count3 /= 2;
				count3 -= 3;
				winnerCount++;
				if (nodesInNextLevel >= 1) {
					for (int i = 0; i < count2; i++) {
						cout << " ";
					}
					cout << "|"; 

				}
				for (int i = 0; i < nodesInNextLevel4 / 2 - 1; i++) {
					for (int i = 0; i < count2*2-1; i++) {
						cout << " ";
					}
					cout << "|";
				}
				cout << endl;
				count2 /= 2;
				if (nodesInNextLevel >= 1) {
					int thecount;
					if (nodesInNextLevel % 2 == 0 || nodesInNextLevel > 1) {
						thecount = count2 * 2 + 1;
					}
					else {
						thecount = count2 + 1;
					}
					for (int i = 0; i < count2; i++) {
						cout << " ";
					}
					for (int i = 0; i < thecount; i++) {
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
				if (nodesInNextLevel % 2 == 1 && ceil((float)nodesInNextLevel / 2 - 1 > 0)) {
					for (int i = 0; i < count2 * 2 - 1; i++) {
						cout << " ";
					}
					for (int i = 0; i < count2 * 2/2 + 1; i++) {
						cout << "-";
					}
				}
				cout << endl;
				if (nodesInNextLevel >= 1) {
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
				loopCounter = 1;
			}
		}
	}

	void Search(int studentID, int numOfStudents) {
		if (root == nullptr)
		{
			return;
		}
		TreeNode* current = root;
		int count = 1;
		Queue q;
		q.enqueue(current);
		if (current->studentID == studentID) {
			cout << "Congratulations! You are placed " << count << "st" << endl;
			return;
		}
		else if (numOfStudents == 1) {
			cout << "Sorry, you are not in the top 30 winners." << endl;
			return;
		}
		while (!q.isEmpty()) {
			current = q.dequeue();
			if (current->left != nullptr) {
				if (current->left->studentID == studentID) {
					count++;
					string suffix;
					if (count == 2) {
						suffix = "nd";
					}
					else if (count == 3) {
						suffix = "rd";
					}
					else {
						suffix = "th";
					}
					cout << "Congratulations! You are placed " << count << suffix << endl;
					return;
				}
				else {
					count++;
					q.enqueue(current->left);
				}
			}
			if (current->right != nullptr) {
				if (current->right->studentID == studentID) {
					count++;
					string suffix;
					if (count == 2) {
						suffix = "nd";
					}
					else if (count == 3) {
						suffix = "rd";
					}
					else {
						suffix = "th";
					}
					cout << "Congratulations! You are placed " << count << suffix << endl;
					return;
				}
				else {
					count++;
					q.enqueue(current->right);
				}
			}
			if (count >= numOfStudents) {
				cout << "Sorry, you are not in the top 30 winners." << endl;
				return;
			}
		}
	}
};