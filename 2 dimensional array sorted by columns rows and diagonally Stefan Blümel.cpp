#include <iostream>
using namespace std;

void sorting(int arr[4][4], int rows, int columns);

void sorting2(int arr[4][4], int rows, int columns);

void sorting3(int arr[4][4], int rows, int columns);

void display(int arr[4][4], int rows, int columns);

void main(void)
{
	//*****************************************************//
	//Aufgabe 1 Spaltenweise Sortieren
	cout << "Task 1 sorting into columns:" << endl << endl;

	int arr[4][4] = { 3,3,3,3,
					  4,5,2,1,
					  1,9,2,7,
					  3,7,6,5 };

	cout << "before sorting:" << endl;
	display(arr, 4, 4);
	sorting(arr, 4, 4);

	cout << endl << endl << "after sorting:" << endl;
	display(arr, 4, 4);
	cout << endl << endl <<"*****************************************************" << endl << endl;
	//*****************************************************//
	//Aufgabe 2 Zeilenweise Sortieren
	cout << "Task 2 sorting into rows:" << endl << endl;

	int arr2[4][4] = { 3,3,3,3,
				  	   4,5,2,1,
				 	   1,9,2,7,
					   3,7,6,5 };

	cout << "before sorting:" << endl;
	display(arr2, 4, 4);
	sorting2(arr2, 4, 4);

	cout << endl << endl << "after sorting:" << endl;;
	display(arr2, 4, 4);
	cout << endl << endl << "*****************************************************" << endl << endl;

	//*****************************************************//
	//Aufgabe 3 Diagonal Sortieren von Oben Links nach unten Rechts
	cout << "Task 3 sorting the smaller numbers diagonally into the upper left and the bigger numbers to the bottom right" << endl << endl;

	int arr3[4][4] = { 3,3,3,3,
					   4,5,2,1,
					   1,9,2,7,
					   3,7,6,5 };

	cout << "before sorting:" << endl;
	display(arr3, 4, 4);
	sorting3(arr3, 4, 4);

	cout << endl << endl << "after sorting:" << endl;
	display(arr3, 4, 4);
	cout << endl << endl << "*****************************************************" << endl << endl;

	//*****************************************************//
}

void display(int arr[4][4], int rows, int columns)
{
	
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t x = 0; x < columns; x++)
		{
			cout << arr[i][x] << "  ";
		}
		cout << endl;
	}
}


void sorting(int arr[4][4], int rows, int columns) //Spaltenweise Sortieren
{
	int temp;
	for (size_t i = 0; i < columns; i++) //Durch Zeilen Navigieren
	{
		for (size_t x = 0; x < columns; x++) //Durch Spalten Navigieren
		{
			for (size_t y = 0; y < (rows * columns) - 1 - i * rows - x; y++)//Durch alle unsortierten Navigieren
			{
				temp = arr[y % columns][y / columns];
				if (temp > arr[(y + 1) % rows][(y + 1) / columns])
				{
					arr[y % rows][y / columns] = arr[(y + 1) % rows][(y + 1) / columns];
					arr[(y + 1) % rows][(y + 1) / columns] = temp;
				}
			}
		}
	}
}

void sorting2(int arr[4][4], int rows, int columns) //Zeilenweise Sortieren
{
	int temp;
	for (size_t i = 0; i < columns; i++) //Durch Zeilen Navigieren
	{
		for (size_t x = 0; x < columns; x++) //Durch Spalten Navigieren
		{
			for (size_t y = 0; y < (rows * columns) - 1 - i * rows - x; y++)//Durch alle unsortierten Navigieren
			{
				temp = arr[y / columns][y % columns];
				if (temp > arr[(y + 1) / rows][(y + 1) % columns])
				{
					arr[y / rows][y % columns] = arr[(y + 1) / rows][(y + 1) % columns];
					arr[(y + 1) / rows][(y + 1) % columns] = temp;
				}
			}
		}
	}
}



void sorting3(int arr[4][4], int rows, int columns) //Diagonal Sortieren
{
	int temp;
	for (size_t i = 0; i < rows; i++) //Durch Zeilen Navigieren
	{
		for (size_t x = 0; x < columns; x++) //Durch Spalten Navigieren
		{
			for (size_t y = 0; y < (rows * columns) - 1 - i * rows - x; y++)//Durch alle unsortierten Navigieren
			{
				temp = arr[y / rows][y % columns];
				if ((y / rows) < rows - 1 && (y % columns) < columns - 1)
				{
					if (temp > arr[(y + columns + 1) / rows][(y + columns + 1) % columns])
					{
						arr[y / rows][y % columns] = arr[(y + columns + 1) / rows][(y + columns + 1) % columns];
						arr[(y + columns + 1) / rows][(y + columns + 1) % columns] = temp;
					}

				}
			}
		}
	}
}