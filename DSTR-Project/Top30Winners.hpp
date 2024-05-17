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
		// data
		TreeNode* data;
		// node property
		Node* next;
	};
	// pointers for front and rear
	Node* front;
	Node* rear;

public:
	// Constructor
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	// Destructor
	~Queue()
	{
		cout << endl << "Queue for Tree Structure is reset!" << endl;;
	}

	// Function to add a new node to the rear of the queue
	void enqueue(TreeNode* data)
	{
		// Create a new node and initialize its data and next pointer
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		// If the queue is empty, set both front and rear to the new node
		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		// If the queue is not empty, add the new node to the end and update the rear pointer
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	TreeNode* dequeue()
	{
		// If the queue is empty, print error message and return null pointer
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return nullptr;
		}
		else
		{
			// Store front into temp
			Node* temp = front;
			// Store the front's data into data
			TreeNode* data = temp->data;
			// Move the front pointer to the next node
			front = front->next;
			delete temp;
			return data;
		}
	}

	// Function to check if the queue is empty
	bool isEmpty()
	{
		return front == nullptr;
	}
};

class BinaryTree
{
public:
	// properties in binary tree
	TreeNode* root;

	// constructor
	BinaryTree()
	{
		root = nullptr;
	}
	// destructor
	~BinaryTree()
	{
		cout << endl << "Binary Tree is reset!" << endl;;
	}

	// Function to create a new TreeNode and initialize its data
	TreeNode* createNewNode(int studentID) {
		TreeNode* newnode = new TreeNode;
		newnode->studentID = studentID;
		newnode->left = nullptr;
		newnode->right = nullptr;

		return newnode;
	}

	// Function to insert a node into the tree in a level order basis
	void insertNode(int studentID)
	{
		// Create a tree node
		TreeNode* newnode = createNewNode(studentID);
		// If root is empty, the node becomes the root
		if (root == nullptr)
		{
			root = newnode;
		}
		else {
			// Create a queue
			Queue q;
			// Set current to root
			TreeNode* current = root;
			// Add current into the queue
			q.enqueue(current);
			while (!q.isEmpty()) {
				// Set current to the first node in the queue
				current = q.dequeue();
				// If the left child of current is empty, insert the new node into the left child
				if (current->left == nullptr) {
					current->left = newnode;
					break;
				}
				// If the left child of current is not empty, add the left child of the current into the queue
				else {
					q.enqueue(current->left);
				}
				// If the right child of current is empty, insert the new node into the right child
				if (current->right == nullptr) {
					current->right = newnode;
					break;
				}
				// If the right child of current is not empty, add the right child of the current into the queue
				else {
					q.enqueue(current->right);
				}
			}
		}
	}

	// Function to print out the binary tree in level order (Top 30 winners)
	void levelOrderTraversal(int studentsNumber)
	{
		// Create a queue
		Queue q;
		//Add root into the queue
		q.enqueue(root);

		// Initialize variables
		int nodesInCurrentLevel = 1;
		int nodesInNextLevel = 0;
		int spaceForStudentID = 109; 
		int spaceForArrow = 116;
		int spaceForWinner = 110; 
		int winnerCount = 1;
		int loopCounter = 1;
		int numOfStudents = 1;

		cout << "Top 30 Winners: " << endl;
		while (!q.isEmpty()) {
			// Set node to the first node in the queue
			TreeNode* node = q.dequeue();
			// Print spaces first time for StudentID
			for (int i = 0; i < spaceForStudentID; i++) {
				cout << " ";
			}
			// Print spaces after the first time for StudentID
			if (loopCounter > 1) {
				for (int i = 0; i < spaceForStudentID; i++) {
					cout << " ";
				}
			}
			// Make sure that the size of the Student ID is always 14
			if (node->studentID < 10) {
				cout << "Student ID:" << node->studentID << "  ";
			}
			else {
				cout << "Student ID:" << node->studentID << " ";
			}

			// If the left child of the node exist, add the left child into the queue and increment variables
			if (node->left != nullptr) {
				q.enqueue(node->left);
				nodesInNextLevel++;
				numOfStudents += 1;
			}

			// If the right child of the node exist, add the right child into the queue and increment variables
			if (node->right != nullptr) {
				q.enqueue(node->right);
				nodesInNextLevel++;
				numOfStudents += 1;
			}

			nodesInCurrentLevel--;
			loopCounter++;

			// Move to the next level if all nodes in the current level are processed
			if (nodesInCurrentLevel == 0) {
				// Adjusting the space for StudentID after every level
				if (spaceForStudentID <= 20) {
					spaceForStudentID = 0;
				}
				else {
					if (spaceForStudentID % 2 == 0) {
						spaceForStudentID /= 2;
						spaceForStudentID -= 4;
					}
					else {
						spaceForStudentID /= 2;
						spaceForStudentID -= 3;
					}
				}
				cout << endl;
				int maxNodesInNextLevel = nodesInNextLevel;
				int balanceNodesInNextLevel = nodesInNextLevel;
				if (nodesInNextLevel % 2 == 1) {
					balanceNodesInNextLevel++;
				}
				if (numOfStudents > 3 && numOfStudents < 8) {
					maxNodesInNextLevel = 4;
				}
				else if (numOfStudents >= 8 && numOfStudents < 16) {
					maxNodesInNextLevel = 8;
				}
				else if (numOfStudents >= 16 && numOfStudents < 31) {
					maxNodesInNextLevel = 16;
				}
				// Print spaces first time for Winner
				for (int i = 0; i < spaceForWinner; i++) {
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
				// Print spaces after the first time for Winner
				if (nodesInNextLevel != 0) {
					for (int i = 0; i < maxNodesInNextLevel / 2 - 1; i++) {
						winnerCount++;
						for (int i = 0; i < spaceForWinner * 2 + 1; i++) {
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
				//Display last line of winners
				if (nodesInNextLevel == 0) { 
					winnerCount += 1;
					for (int i = winnerCount; i < studentsNumber+1; i++) {
						for (int i = 0; i < spaceForWinner * 2 + 1; i++) {
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
				// Adjusting the space for Winner after every level
				spaceForWinner /= 2;
				spaceForWinner -= 3;
				winnerCount++;
				// Print spaces first time for |
				if (nodesInNextLevel >= 1) {
					for (int i = 0; i < spaceForArrow; i++) {
						cout << " ";
					}
					cout << "|"; 

				}
				// Print spaces after the first time for |
				for (int i = 0; i < balanceNodesInNextLevel / 2 - 1; i++) {
					for (int i = 0; i < spaceForArrow*2-1; i++) {
						cout << " ";
					}
					cout << "|";
				}
				cout << endl;
				// Adjusting the space for Arrow after every level
				spaceForArrow /= 2;
				int arrowCount;
				// Level 4 scenario is a special scenario to print the correct amount of arrows for inbalance tree at the level 4
				int level4Scenario = 3;
				// Print spaces first time for - and amount of -
				if (nodesInNextLevel >= 1) {
					// Balance tree
					if (nodesInNextLevel % 2 == 0 || nodesInNextLevel > 1) {
						arrowCount = spaceForArrow * 2 + 1;
					}
					// Inbalance tree
					else {
						// Level 4 scenario for first time
						if (spaceForArrow == 14) {
							arrowCount = spaceForArrow + 2;
						}
						else {
							arrowCount = spaceForArrow + 1;
						}
					}
					for (int i = 0; i < spaceForArrow; i++) {
						cout << " ";
					}
					for (int i = 0; i < arrowCount; i++) {
						cout << "-";
					}
				}
				// Print spaces after the first time for - and amount of - (balance tree)
				for (int i = 0; i < nodesInNextLevel / 2 - 1; i++) {
					for (int i = 0; i < spaceForArrow * 2 - 1; i++) {
						cout << " ";
					}
					for (int i = 0; i < spaceForArrow * 2 + 1; i++) {
						cout << "-";
					}
					level4Scenario += 2;
				}
				// Print spaces after the first time for - and amount of - (inbalance tree)
				if (nodesInNextLevel % 2 == 1 && ceil((float)nodesInNextLevel / 2 - 1 > 0)) {
					for (int i = 0; i < spaceForArrow * 2 - 1; i++) {
						cout << " ";
					}
					if (spaceForArrow == 14) {
						arrowCount = spaceForArrow + 1 + level4Scenario;
					}
					else {
						arrowCount = spaceForArrow + 1;
					}
					for (int i = 0; i < arrowCount; i++) {
						cout << "-";
					}
				}
				cout << endl;
				// Print spaces first time for |
				if (nodesInNextLevel >= 1) {
					for (int i = 0; i < spaceForArrow; i++) {
						cout << " ";
					}
					cout << "|";
				}
				// Print spaces after the first time for |
				for (int i = 0; i < nodesInNextLevel-1; i++) {
					for (int i = 0; i < spaceForArrow * 2 - 1; i++) {
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

	// Function to search for studentID in the tree
	void Search(int studentID, int numOfStudents) {
		//If root is empty, return
		if (root == nullptr)
		{
			return;
		}
		// Set current to root
		TreeNode* current = root;
		int count = 1;
		// Create a queue
		Queue q;
		// Add current into the queue
		q.enqueue(current);
		// If the root's studentID is the studentID that is being searched
		if (current->studentID == studentID) {
			cout << "Congratulations! You are placed " << count << "st" << endl;
			return;
		}
		// If only the root exist and the root's studentID is not the studentID that is being searched
		else if (numOfStudents == 1) {
			cout << "Sorry, you are not in the top 30 winners." << endl;
			return;
		}
		while (!q.isEmpty()) {
			// Set current to the first node in the queue
			current = q.dequeue();
			// If current left child exist
			if (current->left != nullptr) {
				// If current left child's studentID is the studentID that is being searched
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
				// If current left child's studentID is not the studentID that is being searched
				else {
					count++;
					// Add current's left child into the queue
					q.enqueue(current->left);
				}
			}
			// If current right child exist
			if (current->right != nullptr) {
				// If current right child's studentID is the studentID that is being searched
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
				// If current right child's studentID is not the studentID that is being searched
				else {
					count++;
					// Add current's right child into the queue
					q.enqueue(current->right);
				}
			}
			// If studentID not found after checking over the number of students that is less than 30 or the top 30 winners
			if (count >= numOfStudents) {
				cout << "Sorry, you are not in the top 30 winners." << endl;
				return;
			}
		}
	}
};