#include"aufgabe12.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

namespace Aufgabe12 {
	int* merge(int* array1, int* array2, int arrayLength1, int arrayLength2);
	void bubblesort(int* array, int arrayLength);


	void run() {

		//2 Arrays anlegen mit Werten
		int array1[] = { 13,4 };
		int array2[] = { 10, 2,6, 5,8, 9, 12 };

		//get legnth of Array
		int arrayLength2 = sizeof(array2) / sizeof(int);
		int arrayLength1 = sizeof(array1) / sizeof(int);

		//merge Arrays 
		int* mergedArray = merge(array1, array2, arrayLength1, arrayLength2);
		system("pause");
	}



	int* merge(int* array1, int* array2, int arrayLength1, int arrayLength2) {


		int lengthFusedArr = arrayLength1 + arrayLength2;	//get length fused Array
		int* fusedArr = new int[lengthFusedArr];			//Hilfspointer neues Array anlegen + Speicher allokieren
		int j = 0, k = 0;

		//bubblesort(array1, arrayLength1); // für Aufgabe 12 
		//bubblesort(array2, arrayLength2);

		for (int i = 0; i < lengthFusedArr; i++) { //fusedarray durchlaufen

			if (j >= arrayLength1) {			// wenn 1.Array (j) schon komplett abgefuellt, dann k in Array speichern
				fusedArr[i] = array2[k];
				k++;
			}
			else if (k >= arrayLength2) {		// wenn 2.Array (k) schon komplett abgefuellt, dann j in Array speichern
				fusedArr[i] = array1[j];
				j++;
			}
			else if (array1[j] <= array2[k]) {	//wenn j kleiner, gleich k: Element von j in Array speichern
				fusedArr[i] = array1[j];
				j++;
			}
			else if (array1[j] > array2[k]) {		//wenn j groesser k: Element von k in Array speichern
				fusedArr[i] = array2[k];
				k++;
			}


			//cout << fusedArr[i] << endl; //Für die 13 auskommentiert

		}

		return fusedArr;

	}

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

	}

}