//============================================================================
// Name        : Lab1-3.cpp
// Author      : Tomasz Czubat
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Define a struct
struct BidData{
   // Declare variables
   string Title;
   double fund;
   string vehicle;
   double bidAmount;
};

/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
void displayBid(BidData data) {

	cout << "Title: " << data.Title << endl;
	cout << "Fund: " << data.fund << endl;
	cout << "Vehicle: " << data.vehicle << endl;
	cout << "Bid Amount: " << data.bidAmount << endl;

    return;
}

/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
BidData getBid() {
    BidData data;
    string String = new char[30];


    cout << "Enter title: ";
    cin.ignore();
    getline(cin, String);
    data.Title = String;

    cout << "Enter fund: ";
    cin >> data.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, String);
    data.vehicle = String;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    data.bidAmount = strToDouble(strAmount, '$');

    return data;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

	BidData data;


    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	?variable? = getBid();
                break;
            case 2:
                displayBid(data);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
