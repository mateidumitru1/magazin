#pragma once

#ifndef interface_h
#define interface_h

#include "angajati.h"
#include "servicii.h"
#include "produse.h"
#include "raioane.h"
#include <limits>

using namespace std;

void MeniuAngajati();
void MeniuProduse();
void MeniuServicii();
void MeniuRaioane();



void MeniuPrincipal()
{
	cout << "\n~~~~~~~~~~~~~~~~~~Meniu~~~~~~~~~~~~~~~~~~\n\n";
	cout << "   1. Angajati\n";
	cout << "   2. Produse\n";
	cout << "   3. Servicii\n";
	cout << "   4. Raioane\n\n";
	cout << "   Selecteaza o optiune: ";


	char o = 'a';
	while (o != 'q')
	{
		cin >> o;
		fflush(stdin);
		system("cls");
		switch (o)
		{
		case '1':
		{
			MeniuAngajati();
			break;
		}
		case '2':
		{
			MeniuProduse();
			break;
		}
		case '3':
		{
			MeniuServicii();
			break;
		}
		case '4':
		{
			MeniuRaioane();
			break;
		}
		default:
		{
			cout << "\nSelecteaza o optiune valida!\n";
			MeniuPrincipal();
			break;
		}
		}
	}
	

}

void MeniuAngajati()
{
	cout << "\n~~~~~~~~~~~~~~~~~~Angajati~~~~~~~~~~~~~~~~~~\n\n";
	cout << "   1. Afisare angajati.\n";
	cout << "   2. Afisare sefi de raion.\n";
	cout << "   3. Adaugare angajat.\n";
	cout << "   4. Stergere angajat.\n";
	cout << "   5. Modificare angajat.\n";
	cout << "   6. Cautare angajat.\n";
	cout << "   7. Stergerea tuturor angajatilor.\n\n";
	cout << "   Pentru a reveni la meniu principal apasa 'b'.\n\n";
	cout << "   Selecteaza o optiune: ";

	char o = 'a';
	while (o != 'q')
	{
		cin >> o;
		fflush(stdin);
		system("cls");
		switch (o)
		{
		case '1':
		{
			afiseazaAngajati();
			break;
		}
		case '2':
		{
			afisareSefi();
			break;
		}
		case '3':
		{
			adaugaAngajat();
			break;
		}
		case '4':
		{
			stergeAngajat();
			break;
		}
		case '5':
		{
			modificaAngajat();
			break;
		}
		case '6':
		{
			cautaAngajat();
			break;
		}
		case '7':
		{
			stergeTotiAngajatii();
			break;
		}
		case 'b':
		{
			MeniuPrincipal();
			break;
		}
		default:
		{
			cout << "\nSelecteaza o optiune valida!\n";
			MeniuAngajati();
			break;
		}
		}
		cout << "\nApasati ENTER pentru a continua ...";
		cin.ignore();
		cin.get();
		system("cls");
		MeniuAngajati();
	}
	
}

void MeniuProduse()
{
	cout << "\n~~~~~~~~~~~~~~~~~~Produse~~~~~~~~~~~~~~~~~~\n\n";
	cout << "   1. Afisare produse.\n";
	cout << "   2. Adaugare produs.\n";
	cout << "   3. Stergere produs.\n";
	cout << "   4. Modificare produs.\n";
	cout << "   5. Cautare produs.\n";
	cout << "   6. Stergerea tuturor produselor.\n\n";
	cout << "   Pentru a reveni la meniu principal apasa 'b'.\n\n";
	cout << "   Selecteaza o optiune: ";

	char o = 'a';
	while (o != 'q')
	{
		cin >> o;
		fflush(stdin);
		system("cls");
		switch (o)
		{
		case '1':
		{
			afiseazaProduse();
			break;
		}
		case '2':
		{
			adaugaProdus();
			break;
		}
		case '3':
		{
			stergeProdus();
			break;
		}
		case '4':
		{
			modificaProdus();
			break;
		}
		case '5':
		{
			cautaProdus();
			break;
		}
		case '6':
		{
			stergeToateProdusele();
			break;
		}
		case 'b':
		{
			MeniuPrincipal();
			break;
		}
		default:
		{
			cout << "\nSelecteaza o optiune valida!\n";
			MeniuProduse();
			break;
		}
		}
		cout << "\nApasati ENTER pentru a continua ...";
		cin.ignore();
		cin.get();
		system("cls");
		MeniuProduse();
	}
}

void MeniuServicii()
{
	cout << "\n~~~~~~~~~~~~~~~~~~Servicii~~~~~~~~~~~~~~~~~~\n\n";
	cout << "   1. Afisare servicii.\n";
	cout << "   2. Adaugare serviciu.\n";
	cout << "   3. Stergere serviciu.\n";
	cout << "   4. Modificare serviciu.\n";
	cout << "   5. Stergerea tuturor serviciilor.\n\n";
	cout << "   Pentru a reveni la meniu principal apasa 'b'.\n\n";
	cout << "   Selecteaza o optiune: ";

	char o = 'a';
	while (o != 'q')
	{
		cin >> o;
		fflush(stdin);
		system("cls");
		switch (o)
		{
		case '1':
		{
			afiseazaServicii();
			break;
		}
		case '2':
		{
			adaugaServiciu();
			break;
		}
		case '3':
		{
			stergeServiciu();
			break;
		}
		case '4':
		{
			modificaServiciu();
			break;
		}
		case '5':
		{
			stergeToateServiciile();
			break;
		}
		case 'b':
		{
			MeniuPrincipal();
			break;
		}
		default:
		{
			cout << "\nSelecteaza o optiune valida!\n";
			MeniuServicii();
			break;
		}
		}
		cout << "\nApasati ENTER pentru a continua ...";
		cin.ignore();
		cin.get();
		system("cls");
		MeniuServicii();
	}
}

void MeniuRaioane()
{
	cout << "\n~~~~~~~~~~~~~~~~~~Raioane~~~~~~~~~~~~~~~~~~\n\n";
	cout << "   1. Afisare raioane.\n";
	cout << "   2. Adaugare raion.\n";
	cout << "   3. Stergere raion.\n";
	cout << "   4. Modificare raion.\n";
	cout << "   5. Stergerea tuturor raioanelor.\n\n";
	cout << "   Pentru a reveni la meniu principal apasa 'b'.\n\n";
	cout << "   Selecteaza o optiune: ";

	char o = 'a';
	while (o != 'q')
	{
		cin >> o;
		fflush(stdin);
		system("cls");
		switch (o)
		{
		case '1':
		{
			afiseazaRaioane();
			break;
		}
		case '2':
		{
			adaugaRaion();
			break;
		}
		case '3':
		{
			stergeRaion();
			break;
		}
		case '4':
		{
			modificaRaion();
			break;
		}
		case '5':
		{
			stergeToateRaioanele();
			break;
		}
		case 'b':
		{
			MeniuPrincipal();
			break;
		}
		default:
		{
			cout << "\nSelecteaza o optiune valida!\n";
			MeniuRaioane();
			break;
		}
		}
		cout << "\nApasati ENTER pentru a continua ...";
		cin.ignore();
		cin.get();
		system("cls");
		MeniuRaioane();
	}
}

#endif
