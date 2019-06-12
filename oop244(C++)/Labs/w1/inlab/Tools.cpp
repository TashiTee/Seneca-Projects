/********************************
Tashi Tsering
Student Id: 114763170
Seneca Email: ttsering11@myseneca.ca
Date Completion: September 09 2018

*/
// displays the user interface menu
#include<iostream>
#include"graph.h"
#include"tools.h"
using namespace std;


int menu() {
	cout << "1- Number of Samples" << endl;
	cout << "2- Sample Entry" << endl;
	cout << "3- Draw Graph" << endl;
	cout << "0- Exit" << endl;
	cout << "> ";
	return getInt(0, 3);
}
// Performs a fool-proof integer entry
int getInt(int min, int max) {
	int val;
	bool done = false;
	while (!done) {
		cin >> val;
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid Integer, try again: ";
		}
		else {
			if (val < min || val > max) {
				cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
			}
			else {
				done = true;
			}
		}
		cin.ignore(1000, '\n');
	}
	return val;
}