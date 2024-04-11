#include"aufgabe12.h"
#include"aufgabe13.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono> 
#include <thread>
#include <cstdlib>   

using namespace std;
using namespace chrono;
//#define MAXLENGTH 16384

/*a)
	* i)randomIntArray
	* ii) Funktion für Bubblesort
	* iii) Ausführungszeit Bubblesort messen und dokumentieren
* b) Mergesort aus Skript kopieren
* c) Quicksort aus Bibliothek
* d) mit Arraylaengen experimentieren -> Tabelle dazu
*/

namespace Aufgabe13 {


	void run() {
		srand(time(0)); //Zufallszahl-Tabelle zufällig auswählen
		int problem[] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 }; //problem = Problem Größe
		int lengthProblem = sizeof(problem) / sizeof(int); //get legnth of Array

		//cout << "geben sie die länge für das array ein:" << endl; // aufgabe 1
		//int laengeArr;
		//cin >> laengeArr;

		//int* array1 = randomIntArray(laengeArr); // Aufgabe a1)


		for (int i = 0; i < lengthProblem; i++) {

			int* array1 = randomIntArray(problem[i]);

			system_clock::time_point start = system_clock::now(); // Startzeit 
			milliseconds elapsedTimeMs;


			bubblesort(array1, problem[i]); // Aufgabe a2)

			//mergeSort(array1, problem[i]); // Aufgabe b)

			//qsort(array1, problem[i], sizeof(array1[i]), vergleicheZwei); // Aufgabe c)


			system_clock::time_point end = system_clock::now();			//Zeit nach Durchfuehrung des Sorts

			duration<double> elapsedTime = end - start;					//Zeit, die sort gebraucht hat
			elapsedTimeMs = duration_cast<milliseconds>(elapsedTime);	//Zeit in ms
			double msPerRun = double(elapsedTimeMs.count());
			cout << "Problemgroesse: " << setw(10) << problem[i] << "Laufzeit: " << setw(10) << msPerRun << " ms" << endl;

			/*	for (int j = 0; j < problem[i]; j++) { // Kontrolle der Sortierung
					cout << array1[j];
				}
				delete(array1);
				cout << endl;*/
		}
		system("pause");

	}

	int vergleicheZwei(const void* elem1, const  void* elem2) // für quicksort, 4. Parameter  
	{
		int i1, i2;
		i1 = *(int*)elem1; // Elemente aus dem Array
		i2 = *(int*)elem2;
		if (i1 < i2)
		{
			return -1;
		}
		else if (i1 > i2)
		{
			return 1;
		}
		else if (i1 == i2)
		{
			return 0;
		}
	}

	//bubblesort
	void bubblesort(int* array, int arrayLength) {
		int tmp;
		int j = 0;
		for (int i = 1; i < arrayLength; i++) {

			for (j = 0; j < arrayLength - 1; j++) { // wenn erstes Element groesser als 2: speichere 2. Element nach vorne
				if (array[j] > array[j + 1]) {
					tmp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = tmp;
				}
			}
		}

		//ausgabe des Arrays
		//for (int i = 0; i < arrayLength; i++) {
		//	cout << array[i] << endl;
		//	this_thread::sleep_for(std::chrono::milliseconds(10));
		//}
	}

	// Random Int Array erstellen
	int* randomIntArray(int laenge) {

		int* arr = new int[laenge];

		for (int i = 0; i < laenge; i++) {
			arr[i] = rand() % 101;
		}

		return arr;
	}

	void mergeSort(int* arr, int n) {
		int l1 = n / 2;
		if (l1 > 1)
			mergeSort(arr, l1);

		int l2 = n - l1;
		if (l2 > 1)
			mergeSort(arr + l1, l2);


		int* merged = Aufgabe12::merge(arr, arr + l1, l1, l2);
		for (int i = 0; i < n; i++) {
			arr[i] = merged[i];
		}
		delete[] merged;
	}



}