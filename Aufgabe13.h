#pragma once
/************************************************************************\
| Autor: Dorothea Weber, Laura Ehleiter, David Stephan und Beyzanur Türkan
| Aufgabenblatt: 2
| Aufgabe: 13
|************************************************************************|
| Bearbeitungsdauer:
| 1. 60 Minuten
|
| Bemerkungen:
|
\************************************************************************/

using namespace std;

namespace Aufgabe13 {
	void run();
	int* randomIntArray(int laenge);

	void bubblesort(int* array, int arrayLength);
	void mergeSort(int* arr, int n);
	int vergleicheZwei(const void* lem1, const void* elem2);

}