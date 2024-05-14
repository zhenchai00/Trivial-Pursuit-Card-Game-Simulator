#pragma once
#ifndef SORT_AND_SEARCH_ARR_HPP
#define SORT_AND_SEARCH_ARR_HPP
#include <iostream>
#include <string>

using namespace std;

struct StudentResponseNodeArr
{
	// data attributes
	int studentID;
	string question1;
	string question2;
	string question3;
	int scoreQ1;
	int scoreQ2;
	int scoreQ3;
	int totalScore;
};

//Code for Quick sort in Array
//https://www.geeksforgeeks.org/cpp-program-for-quicksort/
void swap(StudentResponseNodeArr& item1, StudentResponseNodeArr& item2) {
	StudentResponseNodeArr temp = item1;
	item1 = item2;
	item2 = temp;
}
int partitionArr(StudentResponseNodeArr studentArr[], int startIndex, int endIndex)
{
	StudentResponseNodeArr pivot = studentArr[startIndex];
	int counter = 0;
	for (int i = startIndex + 1; i < endIndex; i++) {
		if (studentArr[i].totalScore >= pivot.totalScore) {
			counter++;
		}
	}

	int pivotIndex = startIndex + counter;
	swap(studentArr[pivotIndex], studentArr[startIndex]);

	int i = startIndex, j = endIndex;

	while (i < pivotIndex && j > pivotIndex) {

		while (studentArr[i].totalScore > pivot.totalScore) {
			i++;
		}

		while (studentArr[j].totalScore < pivot.totalScore) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(studentArr[i++], studentArr[j--]);
		}
	}

	return pivotIndex;

}

void QuickSortArr(StudentResponseNodeArr studentArr[], int startIndex, int endIndex, int arrSize) {
	if (startIndex > endIndex) {
		return;
	}
	int p = partitionArr(studentArr, startIndex, endIndex);
	QuickSortArr(studentArr, p + 1, endIndex, arrSize);
	QuickSortArr(studentArr, startIndex, p - 1, arrSize);

}

//Code for Binary search in Array
int BinarySearchArr(StudentResponseNodeArr sortedArray[], int arrSize, int searchStudentID) {
	int lastIndex = arrSize - 1;
	int firstIndex = 0;
	while (firstIndex <= lastIndex)
	{
		int middleIndex = (firstIndex + lastIndex) / 2;

		if (sortedArray[middleIndex].studentID == searchStudentID)
		{
			return middleIndex;
		}

		if (sortedArray[middleIndex].studentID < searchStudentID)
		{
			firstIndex = middleIndex + 1;
		}
		else
		{
			lastIndex = middleIndex - 1;
		}
	}
	return -1;
}

void DisplaySearchedStudentID(const StudentResponseNodeArr& sortedArray) {
	cout << "---------------------------------" << endl;
	cout << "Student ID: " << sortedArray.studentID << endl;
	cout << "Question 1: " << sortedArray.question1 << " - Scored: " << sortedArray.scoreQ1 << endl;
	cout << "Question 2: " << sortedArray.question2 << " - Scored: " << sortedArray.scoreQ2 << endl;
	cout << "Question 3: " << sortedArray.question3 << " - Scored: " << sortedArray.scoreQ3 << endl;
	cout << "Total Score: " << sortedArray.totalScore << endl;
	cout << "---------------------------------" << endl;
}

void searchStudentID(StudentResponseNodeArr sortedArray[], int arrSize) {

	int studentIDInput;
	cout << "Enter the student ID to check their score: ";
	cin >> studentIDInput;

	int searchResult = BinarySearchArr(sortedArray, arrSize, studentIDInput);
	if (searchResult != -1) {
		DisplaySearchedStudentID(sortedArray[searchResult]);
	}
	else {
		cout << "---------------------------------" << endl;
		cout << "Student ID not found!" << endl;
		cout << "---------------------------------" << endl;
	}
}

void DisplayArr(StudentResponseNodeArr* sortedArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << "---------------------------------" << endl;
		cout << "Student ID: " << sortedArray[i].studentID << endl;
		cout << "Question 1: " << sortedArray[i].question1 << " - Scored: " << sortedArray[i].scoreQ1 << endl;
		cout << "Question 2: " << sortedArray[i].question2 << " - Scored: " << sortedArray[i].scoreQ2 << endl;
		cout << "Question 3: " << sortedArray[i].question3 << " - Scored: " << sortedArray[i].scoreQ3 << endl;
		cout << "Total Score: " << sortedArray[i].totalScore << endl;
	}
	cout << "---------------------------------" << endl;
}

#endif // SORT_AND_SEARCH_ARR_HPP