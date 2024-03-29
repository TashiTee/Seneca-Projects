/********************************
Tashi Tsering
Student Id: 114763170
Seneca Email: ttsering11@myseneca.ca
Date Completion: September 17 2018

*/
#ifndef GRAPH_H
#define GRAPH_H

namespace sict {
	// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);

	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);

	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);

	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples);

}
#endif // !GRAPH_H
#pragma once
