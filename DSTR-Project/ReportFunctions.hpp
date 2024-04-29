#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

//assuming the csv data is in an array
//pls do not consider this hpp as the official one to display the report, it is still under progress 
//the csv file is just dummy data of both question and students answer

struct reportStructure {  // declaration of a struct to be used to create an array of structs
    string studentid;
    string round1;
    string round2;
    string round3;
    unsigned point1;
    unsigned point2;
    unsigned point3;
    unsigned score;
};

void readAllFileCSV(reportStructure report[], const string& filename) {
    
    try {
        ifstream allfile(filename);
        if (!allfile.is_open()) {
            cout << "File cannot be opened" << endl;
        }
        else {
            //cout << "File opened successfully" << endl;
            string line, studentID, question1, question2, question3, tempstring;
            unsigned points_1 = 0, points_2 = 0, points_3 = 0, total_score = 0;
            int i = 0;
            // to read the file line by line
            while (getline(allfile, line) && i < 5) {
                // Create a string stream from the line
                stringstream ss(line);

                if (getline(ss, studentID, ',')) {
                    report[i].studentid = studentID;
                }

                if (getline(ss, question1, ',')) {
                    report[i].round1 = question1;
                }

                if (getline(ss, question2, ',')) {
                    report[i].round2 = question2;
                }

                if (getline(ss, question3, ',')) {
                    report[i].round3 = question3;
                }

                if (getline(ss, tempstring, ',')) {
                    points_1 = stoi(tempstring);
                    report[i].point1 = points_1;
                }

                if (getline(ss, tempstring, ',')) {
                    points_2 = stoi(tempstring);
                    report[i].point2 = points_2;
                }

                if (getline(ss, tempstring, ',')) {
                    points_3 = stoi(tempstring);
                    report[i].point3 = points_3;
                }

                total_score = report[i].point1 + report[i].point2 + report[i].point3;
                report[i].score = total_score;

                // increment the index by 1
                i++;
            }
        }
        allfile.close();
    }
    catch (ifstream::failure& e) {
        cerr << "Error in opening the file!" << endl;
    }
    
}

void displayReport(const reportStructure report[]) {
    cout << string(40, '=') << "GAME REPORT" << string(40, '=') << endl;
   
    for (int i = 0; i < 5; i++) { 
        cout << "Rank : " << i+1 << endl;
        cout << "StudentID : " << report[i].studentid << endl;
        cout << "Question 1 : " << report[i].round1 << endl;
        cout << setw(70) << "\t";
        cout << "Points 1 : " << report[i].point1 << endl;
        cout << "Question 2 : " << report[i].round2 << endl;
        cout << setw(70) << "\t";
        cout << "Points 2 : " << report[i].point2 << endl;
        cout << "Question 3 : " << report[i].round3 << endl;
        cout << setw(70) << "\t";
        cout << "Points 3 : " << report[i].point3 << endl;
         cout << setw(11) << "\t";
        cout << "Total Score : " << report[i].score << endl;
        cout << string(92, '-') << endl;
        cout << " " << endl;
    }
}
