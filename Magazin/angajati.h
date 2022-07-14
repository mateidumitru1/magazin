#pragma once

#ifndef angajati_h
#define angajati_h

#include <iostream>
#include <string>
#include <mysql.h>
#include <iomanip>

using namespace std;

MYSQL * connection;
MYSQL_ROW row;
MYSQL_RES* res;

void afiseazaAngajati()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		if (mysql_query(connection, "SELECT COUNT(ID) FROM Angajati;") == 0)
		{
			res = mysql_store_result(connection);
			if (strcmp(mysql_fetch_row(res)[0], "0") == 0) cout << "Nu exista niciun angajat.\n\n";
			else
			{
				mysql_free_result(res);
				string query = "SELECT * from Angajati";
				const char* q = query.c_str();
				int state = mysql_query(connection, q);
				res = mysql_store_result(connection);
				if (state == 0)
				{
					cout << "\n";
					cout << setw(10) << "ID" << setw(10) << "Nume" << setw(15) << "Prenume" << setw(12) << "Raion" << setw(15) << "ID_Serviciu" << setw(10) << "Salariu" << "\n\n";
					while (row = mysql_fetch_row(res))
					{
						for (int i = 0; i < mysql_num_fields(res); i++)
						{
							cout << setw(10);
							if (row[i] == NULL) cout << "NULL";
							else cout << row[i] << "  ";
						}
						cout << "\n";
					}
					mysql_free_result(res);
				}
				else cout << "Eroare q!";
			}
		}
		else
		{
			cout << "Eroare q!";
		}
		
	}
	else cout << "Eroare!";
	cout << "\n";
}

void afisareSefi()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		if (mysql_query(connection, "SELECT COUNT(ID) FROM Angajati;") == 0)
		{
			res = mysql_store_result(connection);
			if (strcmp(mysql_fetch_row(res)[0], "0") == 0) cout << "Nu exista niciun angajat.\n\n";
			else
			{
				mysql_free_result(res);
				int state = mysql_query(connection, "SELECT * FROM Angajati WHERE ID IN(SELECT Sef_Raion FROM Raioane) ORDER BY Raion;");
				if (state) cout << "Eroare q!";
				else
				{
					cout << "\n";
					res = mysql_store_result(connection);
					cout << setw(10) << "ID" << setw(10) << "Nume" << setw(15) << "Prenume" << setw(12) << "Raion" << setw(15) << "ID_Serviciu" << setw(10) << "Salariu" << "\n\n";
					while (row = mysql_fetch_row(res))
					{
						for (int i = 0; i < mysql_num_fields(res); i++)
						{
							cout << setw(10);
							if (row[i] == NULL) cout << "NULL";
							else cout << row[i] << "  ";
						}
						cout << "\n";
					}
					mysql_free_result(res);
				}

				
			}
		}
		else
		{
			cout << "Eroare q!";
		}

	}
	else cout << "Eroare!";
	cout << "\n";
}

void adaugaAngajat()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		string query = "INSERT INTO Angajati VALUES(";
		string c;
		cout << "ID: "; cin >> c;
		query = query + c + ",";
		cout << "Nume: "; cin >> c;
		query = query + "'" +  c + "'" + ",";
		cout << "Prenume: "; cin >> c;
		query = query + "'" + c + "'" + ",";
		cout << "Raion: "; cin >> c;
		query = query + c + ",";
		cout << "ID_Serviciu: "; cin >> c;
		query = query + c + ",";
		cout << "Salariu: "; cin >> c;
		query = query + c + ");";
		const char* q = query.c_str();
		int state = mysql_query(connection, q);
		system("cls");
		if (state) cout << "Eroare q!";
		else cout << "Angajatul a fost adaugat cu succes!";
	}
	else cout << "Eroare!";
}

void stergeAngajat()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		if (mysql_query(connection, "SELECT COUNT(ID) FROM Angajati;") == 0)
		{
			res = mysql_store_result(connection);
			if (strcmp(mysql_fetch_row(res)[0], "0") == 0) cout << "Nu exista niciun angajat.\n\n";
			else
			{
				mysql_free_result(res);
				cout << "Introdu ID-ul angajatului pe care doresti sa il stergi: ";
				string c;
				cin >> c;
				string query = "DELETE FROM Angajati WHERE ID=" + c + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection, q);
				if (!state) cout << "Angajatul a fost sters cu succes!";
				else cout << "Eroare!";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void modificaAngajat()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		if (mysql_query(connection, "SELECT COUNT(ID) FROM Angajati;") == 0)
		{
			res = mysql_store_result(connection);
			if (strcmp(mysql_fetch_row(res)[0], "0") == 0) cout << "Nu exista niciun angajat.\n\n";
			else
			{
				cout << "Introdu ID-ul angajatului pe care doresti sa il modifici: ";
				string id;
				cin >> id;
				system("cls");
				cout << "\n";
				string query = "SELECT * FROM Angajati Where ID=" + id + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection, q);
				if (state) cout << "Eroare!";
				else
				{
					res = mysql_store_result(connection);
					row = mysql_fetch_row(res);
					cout << "\n ";
					for (int i = 0; i < mysql_num_fields(res); i++)
					{
						if (row[i] == NULL) cout << "NULL ";
						else cout << row[i] << "  ";
					}
					
					string c;

					mysql_free_result(res);

					query = "UPDATE Angajati SET Raion = ";

					cout << "\n\n Noul Raion: "; cin >> c;
					query = query + c + ", ID_Serviciu = ";

					cout << "\n Noul Serviciu: "; cin >> c;
					query = query + c + ", Salariu = ";

					cout << "\n Noul Salariu: "; cin >> c;
					query = query + c + " WHERE ID = " + id + ";";
					system("cls");
					q = query.c_str();
					int state = mysql_query(connection, q);
					if (state) cout << "Eroare q!";
					else cout << "Angajatul a fost modificat cu succes!";
				}
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
};

void cautaAngajat()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		if (mysql_query(connection, "SELECT COUNT(ID) FROM Angajati;") == 0)
		{
			res = mysql_store_result(connection);
			if (strcmp(mysql_fetch_row(res)[0], "0") == 0) cout << "Nu exista niciun angajat.\n\n";
			else
			{
				mysql_free_result(res);
				cout << "\n Cauti dupa: \n 1. ID\n 2. Nume si Prenume\n\n Alege una dintre optiuni.\n Tasteaza orice altceva pentru a reveni la meniu.\n\n";
				char c;
				cin >> c;
				system("cls");
				switch (c)
				{
					case '1':
					{
						cout << "Introdu ID-ul angajatului pe care doresti sa il cauti: ";
						string id;
						cin >> id;
						cout << "\n";
						string query = "SELECT * FROM Angajati Where ID=" + id + ";";
						const char* q = query.c_str();
						int state = mysql_query(connection, q);
						if (state) cout << "Eroare!";
						else
						{
							res = mysql_store_result(connection);
							while (row = mysql_fetch_row(res))
							{
								for (int i = 0; i < mysql_num_fields(res); i++)
								{
									if (row[i] == NULL) cout << "NULL ";
									else cout << row[i] << "  ";
								}
								cout << "\n";
							}
							mysql_free_result(res);
						}
						break;
					}

					case '2':
					{
						cout << "Introdu numele si prenumele angajatului pe care doresti sa il cauti: \n";
						string n, p;
						cout << "Nume: ";
						cin >> n;
						cout << "\nPrenume: ";
						cin >> p;
						cout << "\n";
						string query = "SELECT * FROM Angajati WHERE Nume='" + n + "'AND Prenume='" + p + "';";
						const char* q = query.c_str();
						int state = mysql_query(connection, q);
						if (state) cout << "Eroare!";
						else
						{
							res = mysql_store_result(connection);
							while (row = mysql_fetch_row(res))
							{
								for (int i = 0; i < mysql_num_fields(res); i++)
								{
									if (row[i] == NULL) cout << "NULL ";
									else cout << row[i] << "  ";
								}
								cout << "\n";
							}
							mysql_free_result(res);
						}
						break;
					}
					default:
					{

						break;
					}
				}
				

			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
	cout << "\n";
}

void stergeTotiAngajatii()
{
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection)
	{
		if (mysql_query(connection, "SELECT COUNT(ID) FROM Angajati;") == 0)
		{
			res = mysql_store_result(connection);
			if (strcmp(mysql_fetch_row(res)[0], "0") == 0) cout << "Nu exista niciun angajat.\n\n";
			else
			{
				mysql_free_result(res);
				int state = mysql_query(connection, "DELETE FROM Angajati;");
				if (state) cout << "Eroare q!";
				else cout << "Toti angajatii au fost stersi cu succes!\n";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
	cout << "\n";
}

#endif
