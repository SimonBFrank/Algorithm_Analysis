using namespace std;
#include "algorithms.h"
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>


int main()
{
	//Make sure to commnet out the lines for the algorithms your'e not using.  Look at lines 44-46.
	string sortingMethod = "Bubble_Sort";
	int numberTrials = 32;
	vector<string> names = { "Ascending_10000","Ascending_20000","Ascending_50000","Ascending_100000",
							"Descending_10000","Descending_20000","Descending_50000","Descending_100000",
							"Random_10000","Random_20000","Random_50000","Random_100000" };
	
	
	ofstream myfile;
	string outFileName = sortingMethod + "_Times.txt";
	myfile.open(outFileName);
	for (int i = 0; i < names.size(); i++)
	{
		unsigned long long sum = 0;
		for (int j = 0; j < numberTrials; j++)
		{
			string fileName = "C:/Users/frank/PycharmProjects/Data Structures Algorithms/" + names[i];
			ifstream inFile;
			inFile.open(fileName);
			if (!inFile)
			{
				cout << "Unable to open file";
				exit(1);
			}
			string line;
			vector<int> testVec;
			while (getline(inFile, line))
			{
				testVec.push_back(stoi(line));
			}
			inFile.close();
			auto start = std::chrono::high_resolution_clock::now();
			bubbleSort(testVec);
			//selectionSort(testVec);
			//mergeSort(testVec, 0, testVec.size() - 1);
			auto finish = std::chrono::high_resolution_clock::now();
			auto duration = finish - start;
			sum += duration.count();
			//cout << names[i] << " Elapsed time: " << duration.count()<< " ns\n";
		}
		double average = sum / numberTrials;
		cout << names[i] <<" Average Elapsed time: " << average << " ns\n";
		myfile << names[i] << " " << setprecision(9) << average << "\n";
	}
	myfile.close();	
}
	