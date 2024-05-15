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
	int rank;
};

//Code for Quick sort in Array
//sorting based on total score
//https://www.programiz.com/dsa/quick-sort
void swap(StudentResponseNodeArr& item1, StudentResponseNodeArr& item2) {
	StudentResponseNodeArr temp = item1;
	item1 = item2;
	item2 = temp;
}

int partitionTotalScoreArr(StudentResponseNodeArr studentArr[], int startIndex, int endIndex)
{
	StudentResponseNodeArr pivot = studentArr[endIndex];
	int i = startIndex;

	//sorting in descending order
	for (int j = startIndex; j < endIndex; j++) {
		if (studentArr[j].totalScore > pivot.totalScore) {
			swap(studentArr[i], studentArr[j]);
			i++;
		}
	}
	swap(studentArr[i], studentArr[endIndex]);
	return i;

}

void QuickSortTotalScoreArr(StudentResponseNodeArr studentArr[], int startIndex, int endIndex) {
	if (startIndex > endIndex) {
		return;
	}
	int p = partitionTotalScoreArr(studentArr, startIndex, endIndex);
	QuickSortTotalScoreArr(studentArr, startIndex, p - 1);
	QuickSortTotalScoreArr(studentArr, p + 1, endIndex);
}

//sorting based on student ID
int partitionStudentID(StudentResponseNodeArr studentArr[], int start, int end) {
	StudentResponseNodeArr pivot = studentArr[end];
	int i = start - 1;

	//sorting in ascending order
	for (int j = start; j < end; j++) {
		if (studentArr[j].studentID <= pivot.studentID) {
			i++;
			swap(studentArr[i], studentArr[j]);
		}
	}
	swap(studentArr[i + 1], studentArr[end]);
	return i + 1;
}

void QuickSortStudentIDArr(StudentResponseNodeArr studentArr[], int start, int end) {
	if (start < end) {
		int p = partitionStudentID(studentArr, start, end);
		QuickSortStudentIDArr(studentArr, start, p - 1);
		QuickSortStudentIDArr(studentArr, p + 1, end);
	}
}

//adding rank to the sorted array
void appendRank(StudentResponseNodeArr sorttedArray[], int arrSize) {
	for (int i = 1; i < arrSize; i++) {
		sorttedArray[i].rank = i + 1;
	}
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
	cout << "Rank: " << sortedArray.rank << endl;
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
	if (searchResult > 0) {
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
		cout << "Rank: " << sortedArray[i].rank << endl;
		cout << "Student ID: " << sortedArray[i].studentID << endl;
		cout << "Question 1: " << sortedArray[i].question1 << " - Scored: " << sortedArray[i].scoreQ1 << endl;
		cout << "Question 2: " << sortedArray[i].question2 << " - Scored: " << sortedArray[i].scoreQ2 << endl;
		cout << "Question 3: " << sortedArray[i].question3 << " - Scored: " << sortedArray[i].scoreQ3 << endl;
		cout << "Total Score: " << sortedArray[i].totalScore << endl;
	}
	cout << "---------------------------------" << endl;
}

#endif // SORT_AND_SEARCH_ARR_HPP