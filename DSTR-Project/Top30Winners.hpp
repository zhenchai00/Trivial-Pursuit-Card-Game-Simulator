#pragma once
#include <iostream>
using namespace std;

struct TreeNode {
	//data
	int studentID;
	int totalScore;
	//tree node
	struct TreeNode* left;
	struct TreeNode* right;
};

class Tree {
public:
	//properties in tree
	TreeNode* root;

	//constructor
	Tree() {
		root = nullptr;
	}

	//function to perform an in-order traversal of the tree and print the top 30 winners
    void inOrder(int& count) {
		cout << "Top 30 Winners:" << endl;
        inOrder(root, count);
    }

	//recursive function to perform an in-order traversal of the tree and print the top 30 winners
    void inOrder(TreeNode* node, int& count) {
        if (node != nullptr && count < 30) {
            inOrder(node->right, count);
			if (count < 30) {
				cout << count+1 << ". Student ID:" << node->studentID << " " << node->totalScore << " points" << endl;
				count++;
			}
			inOrder(node->left, count);
        }
    }

	// function to insert a new node into the binary search tree
	void insert(int studentID, int totalScore) {
		TreeNode* newNode = new TreeNode(); //create a new leaf node
		newNode->studentID = studentID;
		newNode->totalScore = totalScore;
		newNode->left = nullptr;
		newNode->right = nullptr;
		if (root == nullptr) { //inserting into an empty tree
			root = newNode;
		}

		else { //search for the proper parent node
			TreeNode* parent = nullptr;
			TreeNode* node = root;
			while (node != nullptr) {
				parent = node;
				if (node->studentID == studentID) {
					cout << "Duplicates not allowed." << endl;
					return;
				}
				else if (totalScore <= node->totalScore) {
					node = node->left;
				}
				else {
					node = node->right;
				}
			}

			//insert leaf node as a left or right child for parent node
			if (totalScore <= parent->totalScore) {
				parent->left = newNode;
			}
			else {
				parent->right = newNode;
			}
		}
	}
};