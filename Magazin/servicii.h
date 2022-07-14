#pragma once

#ifndef servicii_h
#define servicii_h


#include <iostream>
#include <string>
#include <mysql.h>
#include <iomanip>

using namespace std;

MYSQL* connection1;
MYSQL_ROW row1;
MYSQL_RES* res1;

void afiseazaServicii()
{
	connection1 = mysql_init(0);
	connection1 = mysql_real_connect(connection1, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection1)
	{
		if (mysql_query(connection1, "SELECT COUNT(ID) FROM Servicii;") == 0)
		{
			res1 = mysql_store_result(connection1);
			if (strcmp(mysql_fetch_row(res1)[0], "0") == 0) cout << "Nu exista niciun serviciu.\n\n";
			else
			{
				mysql_free_result(res1);
				string query = "SELECT * from Servicii";
				const char* q = query.c_str();
				int state = mysql_query(connection1, q);
				res1 = mysql_store_result(connection1);
				if (state == 0)
				{
					while (row1 = mysql_fetch_row(res1))
					{
						for (int i = 0; i < mysql_num_fields(res1); i++)
						{
							if (row1[i] == NULL) cout << "NULL ";
							else cout << row1[i] << "  ";
						}
						cout << "\n";
					}
					mysql_free_result(res1);
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


void adaugaServiciu()
{
	connection1 = mysql_init(0);
	connection1 = mysql_real_connect(connection1, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection1)
	{
		string query = "INSERT INTO Servicii VALUES(";
		string c;
		cout << "ID: "; cin >> c;
		query = query + c + ",";
		cout << "Denumire: "; cin >> c;
		query = query + "'" + c + "'" + ",";
		cout << "Pret: "; cin >> c;
		query = query + c + ");";
		const char* q = query.c_str();
		int state = mysql_query(connection1, q);
		system("cls");
		if (state) cout << "Eroare q!";
		else cout << "Serviciul a fost adaugat cu succes!";
	}
	else cout << "Eroare!";
}

void stergeServiciu()
{
	connection1 = mysql_init(0);
	connection1 = mysql_real_connect(connection1, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection1)
	{
		if (mysql_query(connection1, "SELECT COUNT(ID) FROM Servicii;") == 0)
		{
			res1 = mysql_store_result(connection1);
			if (strcmp(mysql_fetch_row(res1)[0], "0") == 0) cout << "Nu exista niciun serviciu.\n\n";
			else
			{
				mysql_free_result(res1);
				cout << "Introdu ID-ul serviciului pe care dores1ti sa il stergi: ";
				string c;
				cin >> c;
				string query = "DELETE FROM Servicii WHERE ID=" + c + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection1, q);
				if (!state) cout << "Serviciul a fost sters cu succes!";
				else cout << "Eroare!";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void modificaServiciu()
{
	connection1 = mysql_init(0);
	connection1 = mysql_real_connect(connection1, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection1)
	{
		if (mysql_query(connection1, "SELECT COUNT(ID) FROM Servicii;") == 0)
		{
			res1 = mysql_store_result(connection1);
			if (strcmp(mysql_fetch_row(res1)[0], "0") == 0) cout << "Nu exista niciun serviciu.\n\n";
			else
			{
				cout << "Introdu ID-ul serviciului pe care dores1ti sa il modifici: ";
				string id;
				cin >> id;
				system("cls");
				cout << "\n";
				string query = "SELECT * FROM Servicii Where ID=" + id + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection1, q);
				if (state) cout << "Eroare!";
				else
				{
					res1 = mysql_store_result(connection1);
					row1 = mysql_fetch_row(res1);
					cout << "\n ";
					for (int i = 0; i < mysql_num_fields(res1); i++)
					{
						if (row1[i] == NULL) cout << "NULL ";
						else cout << row1[i] << "  ";
					}

					string c;

					mysql_free_result(res1);

					query = "UPDATE Servicii SET Pret = ";

					cout << "\n\n Noul Pret: "; cin >> c;
					query = query + c + " WHERE ID = " + id + ";";

					system("cls");
					q = query.c_str();
					int state = mysql_query(connection1, q);
					if (state) cout << "Eroare q!";
					else cout << "Angajatul a fost modificat cu succes!";
				}
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void stergeToateServiciile()
{
	connection1 = mysql_init(0);
	connection1 = mysql_real_connect(connection1, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection1)
	{
		if (mysql_query(connection1, "SELECT COUNT(ID) FROM Servicii;") == 0)
		{
			res1 = mysql_store_result(connection1);
			if (strcmp(mysql_fetch_row(res1)[0], "0") == 0) cout << "Nu exista niciun serviciu.\n\n";
			else
			{
				mysql_free_result(res1);
				int state = mysql_query(connection1, "DELETE FROM Servicii;");
				if (state) cout << "Eroare q!";
				else cout << "Toate serviciile au fost sterse cu succes!\n";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
	cout << "\n";
}

#endif
