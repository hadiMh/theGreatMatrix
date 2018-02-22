#include<iostream>
#include<string>

using namespace std;

long long int rows;
long long int cols;
long long int allCells;
long long int deadListLengthGlobal;

template<typename T>
T* compressTheMatrix(T* ptr,long long int* ptrDeadList)
{
	long long int newAllCells = (rows - 1)*(cols - 1);
	T* newPtr = new T[(rows - 1)*(cols - 1)];
	for (int i = 0,j = 0; i < allCells && j<newAllCells; i++, j++)
	{
		if (!doesDeadListHaveThisIndex(ptrDeadList, deadListLengthGlobal, i))
			*(newPtr + j) = *(ptr + i);
		else
			j--;
	}
	delete[] ptr;
	rows--;
	cols--;
	allCells = newAllCells;
	return newPtr;
}

template<typename T>
int doesDeadListHaveThisIndex(T* ptrDeadList, long long int daedListLength, long long int index)
{                            //(ptr, ptrDeadList, deadListLength, (i*cols) + j)
	for (int i = 0; i < daedListLength; i++)
		if (*(ptrDeadList + i) == index)
			return 1;
	return 0;
}

template<typename T>
long long int* createDeadList(T* ptr)
{
	cout << endl << "The removed numbers:"  << endl;
	long long int* ptrDeadList = new long long int[rows + cols - 1];
	long long int deadListLength = 0;
	for (int i = 0; i < rows + cols - 1; i++)
	{
		*(ptrDeadList+deadListLength) = findTheSmallestIndex(ptr, ptrDeadList, deadListLength);
		deadListLength++;
	}
	/*
	cout << endl << "createDeadList have finished" << endl;
	*/
	cout << endl;
	deadListLengthGlobal = deadListLength;
	return ptrDeadList;
}

template<typename T>
long long int findTheSmallestIndex(T* ptr,long long int* ptrDeadList, long long int deadListLength)
{
	long long int smallestIndex = 0;
	long long int biggestIndex = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (*(ptr + (i*cols) + j) > *(ptr + biggestIndex))
					biggestIndex = (i*cols) + j;
			
	smallestIndex = biggestIndex;
	/*
	cout << endl << "|||||" << biggestIndex << "|||||" << endl;
	*/
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
	cout << *(ptr + smallestIndex) << " ";
	return smallestIndex;
}

/* This function creates the matrix and gets the values from the user and assign the values to matrix. */
template<typename T> 
T* createFirstMatrix(T num)
{
	T temp;
	T* ptr = new T[allCells];
	/*
	cout << endl << allCells << "---" << num << "---" << endl;
	*/
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
	/*
	cout << endl << "!!!!" << endl;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cout << *(ptr + (i*cols) + j) << " ";
	cout << endl << "!!!!" << endl;
	*/
	return ptr;
}

template<typename T>
void printTheMatrix(T* ptr)
{
	cout << endl;
	for (int i = 0; i < allCells; i++)
	{
		cout << *(ptr + i) << " ";
		if ((i + 1) % cols == 0)
			cout << endl;
	}
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
	{
		int* ptr = createFirstMatrix(xI);
		while (1)
		{
			if (rows == 1 || cols == 1)
			{
				cout << endl << "THE END" << endl;
				break;
			}
			ptr = compressTheMatrix(ptr, createDeadList(ptr));
			cout << endl << "the left matrix:";
			printTheMatrix(ptr);
		}
	}
	else if (type == "float")
	{
		float* ptr = createFirstMatrix(xF);
		while (1)
		{
			if (rows == 1 || cols == 1)
			{
				cout << endl << "THE END" << endl;
				break;
			}
			ptr = compressTheMatrix(ptr, createDeadList(ptr));
			cout << endl << "the left matrix:";
			printTheMatrix(ptr);
		}
	}
	else if (type == "double")
	{
		double* ptr = createFirstMatrix(xD);
		while (1)
		{
			if (rows == 1 || cols == 1)
			{
				cout << endl << "THE END" << endl;
				break;
			}
			ptr = compressTheMatrix(ptr, createDeadList(ptr));
			cout << endl << "the left matrix:";
			printTheMatrix(ptr);
		}
	}
	else if (type == "long")
	{
		long long int* ptr = createFirstMatrix(xL);
		while (1)
		{
			if (rows == 1 || cols == 1)
			{
				cout << endl << "THE END" << endl;
				break;
			}
			ptr = compressTheMatrix(ptr, createDeadList(ptr));
			cout << endl << "the left matrix:";
			printTheMatrix(ptr);
		}
	}
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