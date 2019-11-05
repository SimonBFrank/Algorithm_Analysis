#include "algorithms.h"


void bubbleSort (vector<int> &input)
{
	for (unsigned int i = 0; i < input.size(); i++)
	{
		bool swapped = false;
		for (unsigned int j = 0; j < input.size() - i - 1; j++)
		{
			if (input[j] > input[j + 1])
			{
				swapped = true;
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}

void selectionSort(vector<int> &input)
{
	for (unsigned int i = 0; i < input.size(); i++)
	{
		int minIndex = i;
		for (unsigned int j = i + 1; j < input.size(); j++)
		{
			if (input[j] < input[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = input[i];
		input[i] = input[minIndex];
		input[minIndex] = temp;
	}
}

void mergeSort(vector<int> &input, int l, int r)
{
	if (l < r)
	{
		int middle = l + (r - l) / 2;
		mergeSort(input, l, middle);
		mergeSort(input, middle+1, r);

		unsigned int i = 0;
		unsigned int j = 0;
		unsigned int k = 0;
		unsigned int n1 = middle - l + 1;
		unsigned int n2 = r - middle;
		vector<int> L, R;
		for (i = 0; i < n1; i++)
			L.push_back(input[l + i]);
		for (j = 0; j < n2; j++)
			R.push_back(input[middle + 1 + j]);
		i = 0; 
		j = 0; 
		k = l;
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				input[k] = L[i];
				i++;
			}
			else
			{
				input[k] = R[j];
				j++;
			}
			k++;
		}
		while (i < n1)
		{
			input[k] = L[i];
			i++;
			k++;
		}
		while (j < n2)
		{
			input[k] = R[j];
			j++;
			k++;
		}
	}
}