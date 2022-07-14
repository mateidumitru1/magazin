#pragma once

#ifndef raioane_h
#define raioane_h


#include <iostream>
#include <string>
#include <mysql.h>
#include <iomanip>

using namespace std;

MYSQL* connection3;
MYSQL_ROW row3;
MYSQL_RES* res3;

void afiseazaRaioane()
{
	connection3 = mysql_init(0);
	connection3 = mysql_real_connect(connection3, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection3)
	{
		if (mysql_query(connection3, "SELECT COUNT(ID) FROM Raioane;") == 0)
		{
			res3 = mysql_store_result(connection3);
			if (strcmp(mysql_fetch_row(res3)[0], "0") == 0) cout << "Nu exista niciun raion.\n\n";
			else
			{
				mysql_free_result(res3);
				string query = "SELECT * from Raioane";
				const char* q = query.c_str();
				int state = mysql_query(connection3, q);
				res3 = mysql_store_result(connection3);
				if (state == 0)
				{
					while (row3 = mysql_fetch_row(res3))
					{
						for (int i = 0; i < mysql_num_fields(res3); i++)
						{
							if (row3[i] == NULL) cout << "NULL ";
							else cout << row3[i] << "  ";
						}
						cout << "\n";
					}
					mysql_free_result(res3);
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

void adaugaRaion()
{
	connection3 = mysql_init(0);
	connection3 = mysql_real_connect(connection3, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection3)
	{
		string query = "INSERT INTO Raioane VALUES(";
		string c;
		cout << "ID: "; cin >> c;
		query = query + c + ",";
		cout << "Denumire: "; cin >> c;
		query = query + "'" + c + "'" + ",";
		cout << "Sef_Raion: "; cin >> c;
		query = query + c + ");";
		const char* q = query.c_str();
		int state = mysql_query(connection3, q);
		system("cls");
		if (state) cout << "Eroare q!";
		else cout << "Raionul a fost adaugat cu succes!";
	}
	else cout << "Eroare!";
}

void stergeRaion()
{
	connection3 = mysql_init(0);
	connection3 = mysql_real_connect(connection3, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection3)
	{
		if (mysql_query(connection3, "SELECT COUNT(ID) FROM Raioane;") == 0)
		{
			res3 = mysql_store_result(connection3);
			if (strcmp(mysql_fetch_row(res3)[0], "0") == 0) cout << "Nu exista niciun raion.\n\n";
			else
			{
				mysql_free_result(res3);
				cout << "Introdu ID-ul raionului pe care dores3ti sa il stergi: ";
				string c;
				cin >> c;
				string query = "DELETE FROM Raioane WHERE ID=" + c + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection3, q);
				if (!state) cout << "Raionul a fost sters cu succes!";
				else cout << "Eroare!";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void modificaRaion()
{
	connection3 = mysql_init(0);
	connection3 = mysql_real_connect(connection3, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection3)
	{
		if (mysql_query(connection3, "SELECT COUNT(ID) FROM Raioane;") == 0)
		{
			res3 = mysql_store_result(connection3);
			if (strcmp(mysql_fetch_row(res3)[0], "0") == 0) cout << "Nu exista niciun raion.\n\n";
			else
			{
				cout << "Introdu ID-ul raionului pe care dores3ti sa il modifici: ";
				string id;
				cin >> id;
				system("cls");
				cout << "\n";
				string query = "SELECT * FROM Raioane Where ID=" + id + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection3, q);
				if (state) cout << "Eroare!";
				else
				{
					res3 = mysql_store_result(connection3);
					row3 = mysql_fetch_row(res3);
					cout << "\n ";
					for (int i = 0; i < mysql_num_fields(res3); i++)
					{
						if (row3[i] == NULL) cout << "NULL ";
						else cout << row3[i] << "  ";
					}

					string c;

					mysql_free_result(res3);

					query = "UPDATE Raioane SET Sef_Raion = ";

					cout << "\n\n Noul sef de raion: "; cin >> c;
					query = query + c + " WHERE ID = " + id + ";";

					system("cls");
					q = query.c_str();
					
					int state = mysql_query(connection3, q);
					if (state) cout << "Eroare q!";
					else cout << "Raionul a fost modificat cu succes!";
				}
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void stergeToateRaioanele()
{
	connection3 = mysql_init(0);
	connection3 = mysql_real_connect(connection3, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection3)
	{
		if (mysql_query(connection3, "SELECT COUNT(ID) FROM Raioane;") == 0)
		{
			res3 = mysql_store_result(connection3);
			if (strcmp(mysql_fetch_row(res3)[0], "0") == 0) cout << "Nu exista niciun raion.\n\n";
			else
			{
				mysql_free_result(res3);
				int state = mysql_query(connection3, "DELETE FROM Raioane;");
				if (state) cout << "Eroare q!";
				else cout << "Toate raioanele au fost sterse cu succes!\n";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
	cout << "\n";
}

#endif
