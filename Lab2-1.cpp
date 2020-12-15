//============================================================================
// Name        : Lab2-1.cpp
// Author      : Tom Czubat
// Version     : 1.0
// Copyright   : Copyright � 2017 SNHU COCE
// Description : Lab 2-1 Up to Speed in C++, Part 2
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>


// FIXME (1): Reference the CSVParser library
#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

struct Bid {
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.title << " | " << bid.amount << " | " << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) {
    // create a vector of bids
    vector<Bid> bids;
    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // loop to read rows of a CSV file
    for (int i = 0; i < file.rowCount(); i++) {
        // Get the amount, fund, and title
        string bidAmt = file[i].operator [](4); 
        string fund = file[i].operator[]("Fund"); 
        string title = file[i].operator[]("ArticleTitle"); 
        // Store the infor in the bid struct 
        Bid bid;
        bid.amount = strToDouble(bidAmt, '$');
        bid.fund = fund;
        bid.title = title;
        bids.push_back(bid); // push the bid to the vector
    }
    return bids;
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
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
    }

    // define a vector for all of the bids
    vector<Bid> allBids;


    // declare timer variables
    clock_t start;
    clock_t end;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Not currently implemented." << endl;

            break;
        case 2:
            // initialize timer
            start = clock();

            // call the method to load the bids
            loadBids("eBid_Monthly_Sales_Dec_2016.csv");

            cout << "Time : " << end - start << " milliseconds " << endl;
            cout << "Time : " << (end - start) * 1.0 / CLOCKS_PER_SEC << " seconds " << endl;
            break;
        case 3:
            vector<Bid> bids = loadBids("eBid_Monthly_Sales_Dec_2016.csv");

            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
