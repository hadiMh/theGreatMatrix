#include<iostream>
#include<string>

using namespace std;

long long int rows;
long long int cols;
long long int allCells;


template<typename T>
int doesDeadListHaveThisIndex(T* ptrDeadList, long long int daedListLength, long long int index)
{                            //(ptr, ptrDeadList, deadListLength, (i*cols) + j)
	for (int i = 0; i < daedListLength; i++)
		if (*(ptrDeadList + i) == index)
			return 1;
	return 0;
}

template<typename T>
void createDeadList(T* ptr)
{
	T* ptrDeadList = new T[rows + cols - 1];
	long long int deadListLength = 0;
	for (int i = 0; i < rows + cols - 1; i++)
	{
		*(ptrDeadList+deadListLength) = findTheSmallestIndex(ptr, ptrDeadList, deadListLength);
		deadListLength++;
	}
	cout << endl << "createDeadList have finished" << endl;
}

template<typename T>
long long int findTheSmallestIndex(T* ptr,T* ptrDeadList, long long int deadListLength)
{
	long long int smallestIndex = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (*(ptr + (i*cols) + j) < *(ptr + smallestIndex))
			{
				if (!doesDeadListHaveThisIndex(ptrDeadList, deadListLength, (i*cols) + j))
					smallestIndex = (i*cols) + j;
			}
		}
	}
	cout << "<<<smallestIndex>>>:  " << smallestIndex << endl;
	return smallestIndex;
}

/* This function creates the matrix and gets the values from the user and assign the values to matrix. */
template<typename T> 
T* createFirstMatrix(T num)
{
	T temp;
	T* ptr = new T[allCells];
	cout << endl << allCells << "---" << num << "---" << endl;

	cout << endl << "Enter all the numbers:" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> temp;
			*(ptr + (i*cols) + j) = temp;
		}
		getchar();
	}
	cout << endl << "!!!!" << endl;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cout << *(ptr + (i*cols) + j) << " ";
	cout << endl << "!!!!" << endl;

	return ptr;
}

/* This function asks the user which type is going to be entered */
void askTheVariablesType()
{
	string type;
	int xI = 1;
	float xF = 1.1;
	double xD = 1.2;
	long long int xL = 123456;

	cout << "please enter the type of numbers:" << endl;
	cout << " 'long' for LONG LONG INT" << endl;
	cout << " 'int' for INTEGER" << endl;
	cout << " 'float' for FLOUT" << endl;
	cout << " 'double' for DOUBLE" << endl;
	cin >> type;
	if (type == "int")
		createDeadList(createFirstMatrix(xI));
	else if (type == "float")
		createDeadList(createFirstMatrix(xF));
	else if (type == "double")
		createDeadList(createFirstMatrix(xD));
	else if (type == "long")
		createDeadList(createFirstMatrix(xL));
	return;
}


int main()
{
	cout << endl << "Please enter number of cols:";
	cin >> cols;
	cout << endl << "Please enter number of rows:";
	cin >> rows;
	allCells = rows * cols;

	askTheVariablesType();
}