#pragma once
#include <iostream>
using namespace std;

struct TreeNode
{
	// data
	int studentID;
	int totalScore;
	// tree node
	struct TreeNode *left;
	struct TreeNode *right;
};

class Tree
{
public:
	// properties in tree
	TreeNode *root;

	// constructor
	Tree()
	{
		root = nullptr;
	}

	// function to perform an in-order traversal of the tree and print the top 30 winners
	void inOrder(int &count)
	{
		cout << "Top 30 Winners:" << endl;
		inOrder(root, count);
	}

	// recursive function to perform an in-order traversal of the tree and print the top 30 winners
	void inOrder(TreeNode *node, int &count)
	{
		if (node != nullptr && count < 30)
		{
			inOrder(node->right, count);
			if (count < 30)
			{
				cout << count + 1 << ". Student ID:" << node->studentID << " Overall Score: " << node->totalScore << endl;
				count++;
			}
			inOrder(node->left, count);
		}
	}

	// function to insert a new node into the binary search tree
	void insert(int studentID, int totalScore)
	{
		TreeNode *newNode = new TreeNode(); // create a new leaf node
		newNode->studentID = studentID;
		newNode->totalScore = totalScore;
		newNode->left = nullptr;
		newNode->right = nullptr;
		if (root == nullptr)
		{ // inserting into an empty tree
			root = newNode;
		}

		else
		{ // search for the proper parent node
			TreeNode *parent = nullptr;
			TreeNode *node = root;
			while (node != nullptr)
			{
				parent = node;
				if (node->studentID == studentID)
				{
					cout << "Duplicates not allowed." << endl;
					return;
				}
				else if (totalScore <= node->totalScore)
				{
					node = node->left;
				}
				else
				{
					node = node->right;
				}
			}

			// insert leaf node as a left or right child for parent node
			if (totalScore <= parent->totalScore)
			{
				parent->left = newNode;
			}
			else
			{
				parent->right = newNode;
			}
		}
	}

	// function to search for a student ID in the top 30 winners and retrieve their position and score
	void searchTop30(int studentID, int &position, int &score)
	{
		int count = 0;
		position = -1;
		score = -1;
		searchTop30(root, studentID, count, position, score);
	}

	// recursive function to search for a student ID in the top 30 winners and update position and score if found
	void searchTop30(TreeNode *node, int studentID, int &count, int &position, int &score)
	{
		if (node != nullptr && count < 30 && position == -1)
		{
			searchTop30(node->right, studentID, count, position, score);
			if (count < 30 && position == -1)
			{
				count++;
				if (node->studentID == studentID)
				{
					position = count;
					score = node->totalScore;
				}
			}
			if (position == -1)
			{
				searchTop30(node->left, studentID, count, position, score);
			}
		}
	}
};