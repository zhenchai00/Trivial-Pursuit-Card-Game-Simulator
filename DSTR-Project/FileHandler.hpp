#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fileHandler() 
{
    // ifstream = read from file
    // ofstream = write on file
    // fstream = both read and write file
    fstream questionFile;
    string output;
    int counter = 1;

    cout << "File handler" << endl;

    questionFile.open("docs/dstr-question-M.csv");

    while (getline(questionFile, output))
    {
        // test the csv display
        cout << counter << ". " << output << endl;
        counter++;
    }
}