#include"aufgabe11.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<chrono>
#include<thread>


using namespace std;

/* Regeln zu Zellen
* Nachbarn: umgebende Zellen (max. 8)
* bei jeder Generation sterben oder leben Zellen:
- Lebende Zellen:
	weniger als 2 lebende Nachbarn: Zelle stirbt
	2 oder 3 lebende Nachbarn: Zelle lebt weiter
	3 oder Mehr lebende Nachbarn: Zelle stirbt an Nahrungsmangel
- tote Zelle
	genau 3 lebende Nachbarn: wird neu geboren

a) zweidimensionales Array anlegen mit Zufallszahlen
b) Anzeige des Arrays
c) neue Generation in Endlosschleife generieren mit Zellenregeln
d) Hilfsarray mit neuer Generation befüllen mit Zellenregeln
e) Hilfsarray in erstes Array zurückkopieren
f) 2 Modi implementieren:
	Manuell: Benutzer wird gefragt, ob nächste Generation ausgegeben werden soll
	Auto: Nächste Generation wird nach Wartezeit angezeigt, Bildschrim löschen
*/

namespace Aufgabe11 //Conways Game of Life
{
#define L 10

	void feldAusgeben(int feld[][L]);
	void initialize2Array(int arr[][L]);
	void initialize2ArrayMitRand(int arr[][L]);
	void initializeNewGeneration(int hilfsArray[][L]);


	void run() {

		srand(time(0));	//Zufallszahl-Tabelle zufällig auswählen

		int feld1[L][L];
		//a) zweidimensionales Array anlegen mit Zufallszahlen
		initialize2ArrayMitRand(feld1);

		char eingabeBenutzerModus;
		bool weiter = true;

		cout << "Waehlen Sie einen Benutzermodus aus." << endl
			<< "Bei der manuellen Benutzersteuerung koennen Sie nach jeder Generation bestimmen, ob die naechste ausgegeben werden soll." << endl
			<< "Druecken Sie hierfür die Taste 'm'" << endl
			<< "Bei der automatischen Benutzersteuerung wird nach einer kurzen Wartezeit die naechste Generation angezeigt." << endl
			<< "Beachten Sie hierbei, dass der Bildschirm vor jeder neuen Generationsanzeige geloescht wird." << endl
			<< "Druecken Sie hierfür die Taste 'a'" << endl;
		cin >> eingabeBenutzerModus;

		//b) Anzeige des Arrays
		cout << "Zellenbestand nach Urknall" << endl;

		feldAusgeben(feld1);	//Startpopulation ausgeben

		getchar();
		getchar();


		int generationsNummer = 1;

		switch (eingabeBenutzerModus) {

		case 'm':

			while (weiter) {
				//Babys

				initializeNewGeneration(feld1);
				cout << "Zellenbestand nach der " << generationsNummer << ". Generation" << endl;
				feldAusgeben(feld1);


				cout << "Bitte druecken Sie eine Taste zum Ausgeben der naechsten Generation" << endl;
				getchar();
				//getchar();
				generationsNummer++;
			}
			break;

		case 'a':

			while (weiter) {
				//babys
				initializeNewGeneration(feld1);
				cout << "Zellenbestand nach der " << generationsNummer << ". Generation" << endl;
				feldAusgeben(feld1);

				this_thread::sleep_for(std::chrono::milliseconds(10000)); // Wartezeit
				system("cls"); // Ausgabe löschen   
				generationsNummer++;
			}
			break;
		default:
			cout << "FEHLSCHLAG: Urknall nicht moeglich" << endl; break;
		}

	}

	void initialize2Array(int arr[][L]) {

		for (int i = 0; i < L; i++) {		//Spalte weiterlaufen
			for (int j = 0; j < L; j++) {	//Zeilen weiterlaufen
				arr[i][j] = rand() % 2;		// Zufallszahl zwischen 0 und 1
			}
		}

		return;
	}

	void initialize2ArrayMitRand(int arr[][L]) {

		const int GRENZWERT = (L - 1);

		for (int i = 0; i < L; i++) {		//Spalte weiterlaufen
			for (int j = 0; j < L; j++) {	//Zeilen weiterlaufen
				if (i == 0 || i == GRENZWERT)
				{
					arr[i][j] = 0;
				}
				else if (j == 0 || j == GRENZWERT)
				{
					arr[i][j] = 0;
				}
				else
				{
					arr[i][j] = rand() % 2;		// Zufallszahl zwischen 0 und 1
				}
			}
		}

		//rand befuellen
		//erste Spalte mit Nullen auffuelllen
		for (int i = 0; i < L; i++) {		//Spalte weiterlaufen
			for (int j = 0; j < L; j++) {	//Zeilen weiterlaufen
						// Zufallszahl zwischen 0 und 1
			}
		}

		return;
	}

	void feldAusgeben(int feld[][L])
	{
		for (int i = 0; i < L; i++) {			//Spalten ausgeben
			for (int j = 0; j < L; j++) {		//Zeilen ausgeben
				cout << setw(3) << feld[i][j];
			}
			cout << endl;
		}
	}

	void initializeNewGeneration(int liste[][L])
	{

		//erste Zelle: arr[1][1]
		const int GRENZWERT = (L - 1); // Überlaufschutz des Rand
		int hilfsArray[L][L];

		//Hilfsarray Rand mit 0 befuellen
		for (int i = 0; i < L; i++) {		//Spalte weiterlaufen
			for (int j = 0; j < L; j++) {	//Zeilen weiterlaufen
				if (i == 0 || i == GRENZWERT)
				{
					hilfsArray[i][j] = 0;
				}
				else if (j == 0 || j == GRENZWERT)
				{
					hilfsArray[i][j] = 0;
				}
			}
		}

		for (int i = 1; i < GRENZWERT; i++) {  //jede Zelle einmal durchgehen
			for (int j = 1; j < GRENZWERT; j++) {
				int summe = 0;
				//____________________________Summe Nachbarn abfragen_____________________

				for (int k = i - 1; k <= i + 1; k++) { //obere und untere Zeile
					for (int l = j - 1; l <= j + 1; l++)
					{
						summe = summe + liste[k][l]; //Nachbarn abfragen und anzahl speichern

					} // for 4 Ende
				} //for 3 Ende

				//___________________________Summe Nachbarn berechnen beendet_________

				//1.Fall: Zelle lebt
				if (liste[i][j] == 1) {
					summe = summe - 1;			//weil aktuelles Element mitgezaehlt wurde, von summe abziehen

												//Bedigungen abklappern
					if (summe > 3) {			//3 oder Mehr lebende Nachbarn: Zelle stirbt an Nahrungsmangel
						hilfsArray[i][j] = 0;
						//cout << "Zelle an Nahrungsmangel gestorben" << endl;
					}
					else if (summe < 2) {		//weniger als 2 lebende Nachbarn: Zelle stirbt
						hilfsArray[i][j] = 0;
						//cout << "Zelle an Einsamkeit gestorben" << endl;
					}
					else {
						hilfsArray[i][j] = liste[i][j];
						//cout << "Alles okay, Zelle lebt weiter" << endl;
					}
				}

				//2.Fall: Zelle ist tot
				//Bedigungen abklappern
				else if (liste[i][j] == 0) {
					if (summe == 3) {
						hilfsArray[i][j] = 1;		//3 Nachbarn: Zelle wird wiedergeboren
						//cout << "Zelle wieder lebendig" << endl;
					}
					else {
						hilfsArray[i][j] = liste[i][j];
						//cout << "Zelle immer noch tot" << endl;
					}

				}
				//naechste Zelle ueberpruefen
				else {
					cout << "FEHLSCHALG: Urknall nicht moeglich" << endl;
					//goto ("ende");
				}
			}// for2 Ende


		} // for1 Ende
		//Ausgabe der ersten Zellen
		cout << endl << endl;

		//hilfsarray in Liste kopieren
		for (int i = 0; i < L; i++) {		//Spalte weiterlaufen
			for (int j = 0; j < L; j++) {	//Zeilen weiterlaufen
				liste[i][j] = hilfsArray[i][j];		// Zufallszahl zwischen 0 und 1
			}
		}
	}

}