/* SortVector is a program that sorts vectors to have them in numerical order
   @author Anthony Minunni
   @date 3/24/21 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* SortVector is the method where the sorting takes place
   @param myVec is the vector */
void SortVector(vector<int>& myVec) {
    int temp = myVec.at(0); //variable that will hold one of the values when a swap occurs
    unsigned i; //unsigned variables are needed when comparing vectors
    unsigned j;

    //nested loop so the program runs as many times as the size of the vector to ensure multiple passes
    for (j = 0; j < myVec.size(); j++) {
        for (i = 0; i < myVec.size() - 1; i++) {
            if (myVec.at(i) > myVec.at(i + 1)) {
                temp = myVec.at(i);
                myVec.at(i) = myVec.at(i + 1);
                myVec.at(i + 1) = temp;
            }
        }
    }
}

int main() {
    vector<int> testVec(20); //declaration of vector
    int size; //declaration of int that will determine size of testVec
    int count = 0; //this will be used for populating the vector
    string input; //string that holds all of the enter values to seperate
    string first; //gets the value that will be used for size
    unsigned i; //for loops

    //This section takes the first value of the enterred string, converts it for the size of the vector, and shortens the string
    cout << "Enter on line seperated by spaces:" << endl;
    cout << "First number: Number of values that will be entered. The rest: the numbers to sort" << endl;
    getline(cin, input);
    first = input.substr(0, input.find(" ")); //first is a substring of input that holds the first value
    size = stoi(first); //converts size value from string to int
    testVec.resize(size); //adjusts size of vector to the input size
    input = input.substr(input.find(" ") + 1); //removes the first value from the string

    //this while loop uses the technique above to find each value that will be added to the vector
    while (input.length() > 2) {
        first = input.substr(0, input.find(" "));
        size = stoi(first);
        testVec.at(count) = size;
        count++;
        if (input.find(" ") != string::npos) {
            input = input.substr(input.find(" ") + 1);
        }
        else {
            break;
        }
    }

    count = testVec.size() - 1; //contingency plan in case count is higher than the size of testVec
    size = stoi(input);
    testVec.at(count) = size;

    SortVector(testVec);

    //while loop to print the vector. This is while instead of for because the code would crash if it was a for loop
    i = 0;
    while (i < testVec.size()) {
        cout << testVec.at(i) << " ";
        i++;
    }

    cout << endl;

    return 0;
}
