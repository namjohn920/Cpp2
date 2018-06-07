//John HyunKyu Nam
//namjohn920@gmail.com


#ifndef JOHN_GRAPH_H 
#define JOHN_GRAPH_H

#include <iostream>
#define MAX_NO_OF_SAMPLES 20
namespace sict {
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples);
	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);
}
#endif