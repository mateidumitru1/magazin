#pragma once

#ifndef produse_h
#define produse_h

#include <iostream>
#include <string>
#include <mysql.h>
#include <iomanip>

using namespace std;

MYSQL* connection2;
MYSQL_ROW row2;
MYSQL_RES* res2;

void afiseazaProduse()
{
	connection2 = mysql_init(0);
	connection2 = mysql_real_connect(connection2, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection2)
	{
		if (mysql_query(connection2, "SELECT COUNT(ID) FROM Produse;") == 0)
		{
			res2 = mysql_store_result(connection2);
			if (strcmp(mysql_fetch_row(res2)[0], "0") == 0) cout << "Nu exista niciun produs.\n\n";
			else
			{
				mysql_free_result(res2);
				string query = "SELECT * from Produse";
				const char* q = query.c_str();
				int state = mysql_query(connection2, q);
				res2 = mysql_store_result(connection2);
				if (state == 0)
				{
					while (row2 = mysql_fetch_row(res2))
					{
						for (int i = 0; i < mysql_num_fields(res2); i++)
						{
							if (row2[i] == NULL) cout << "NULL ";
							else cout << row2[i] << "  ";
						}
						cout << "\n";
					}
					mysql_free_result(res2);
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


void adaugaProdus()
{
	connection2 = mysql_init(0);
	connection2 = mysql_real_connect(connection2, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection2)
	{
		string query = "INSERT INTO Produse VALUES(";
		string c;
		cout << "ID: "; cin >> c;
		query = query + c + ",";
		cout << "Denumire: "; cin >> c;
		query = query + "'" + c + "'" + ",";
		cout << "Pret: "; cin >> c;
		query = query + c + ",";
		cout << "Raion: "; cin >> c;
		query = query + c + ");";

		const char* q = query.c_str();
		int state = mysql_query(connection2, q);
		system("cls");
		if (state) cout << "Eroare q!";
		else cout << "Produsul a fost adaugat cu succes!";
	}
	else cout << "Eroare!";
}

void stergeProdus()
{
	connection2 = mysql_init(0);
	connection2 = mysql_real_connect(connection2, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection2)
	{
		if (mysql_query(connection2, "SELECT COUNT(ID) FROM Produse;") == 0)
		{
			res2 = mysql_store_result(connection2);
			if (strcmp(mysql_fetch_row(res2)[0], "0") == 0) cout << "Nu exista niciun produs.\n\n";
			else
			{
				mysql_free_result(res2);
				cout << "Introdu ID-ul produsului pe care dores2ti sa il stergi: ";
				string c;
				cin >> c;
				string query = "DELETE FROM Produse WHERE ID=" + c + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection2, q);
				if (!state) cout << "Produsul a fost sters cu succes!";
				else cout << "Eroare!";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void modificaProdus()
{
	connection2 = mysql_init(0);
	connection2 = mysql_real_connect(connection2, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection2)
	{
		if (mysql_query(connection2, "SELECT COUNT(ID) FROM Produse;") == 0)
		{
			res2 = mysql_store_result(connection2);
			if (strcmp(mysql_fetch_row(res2)[0], "0") == 0) cout << "Nu exista niciun produs.\n\n";
			else
			{
				cout << "Introdu ID-ul produsului pe care dores2ti sa il modifici: ";
				string id;
				cin >> id;
				system("cls");
				cout << "\n";
				string query = "SELECT * FROM Produse Where ID=" + id + ";";
				const char* q = query.c_str();
				int state = mysql_query(connection2, q);
				if (state) cout << "Eroare!";
				else
				{
					res2 = mysql_store_result(connection2);
					row2 = mysql_fetch_row(res2);
					cout << "\n ";
					for (int i = 0; i < mysql_num_fields(res2); i++)
					{
						if (row2[i] == NULL) cout << "NULL ";
						else cout << row2[i] << "  ";
					}

					string c;

					mysql_free_result(res2);

					query = "UPDATE Produse SET Pret = ";

					cout << "\n\n Noul Pret: "; cin >> c;

					query = query + c + " WHERE ID = " + id + ";";

					system("cls");
					q = query.c_str();
					int state = mysql_query(connection2, q);
					if (state) cout << "Eroare q!";
					else cout << "Produsul a fost modificat cu succes!";
				}
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
}

void cautaProdus()
{
	connection2 = mysql_init(0);
	connection2 = mysql_real_connect(connection2, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection2)
	{
		if (mysql_query(connection2, "SELECT COUNT(ID) FROM Produse;") == 0)
		{
			res2 = mysql_store_result(connection2);
			if (strcmp(mysql_fetch_row(res2)[0], "0") == 0) cout << "Nu exista niciun produs.\n\n";
			else
			{
				mysql_free_result(res2);
				cout << "\n Cauti dupa: \n 1. ID\n 2. Denumire\n\n Alege una dintre optiuni.\n Tasteaza orice altceva pentru a reveni la meniu.\n\n";
				char c;
				cin >> c;
				system("cls");
				switch (c)
				{
				case '1':
				{
					cout << "Introdu ID-ul produsului pe care doresti sa il cauti: ";
					string id;
					cin >> id;
					cout << "\n";
					string query = "SELECT * FROM Produse Where ID=" + id + ";";
					const char* q = query.c_str();
					int state = mysql_query(connection2, q);
					if (state) cout << "Eroare!";
					else
					{
						res2 = mysql_store_result(connection2);
						while (row2 = mysql_fetch_row(res2))
						{
							for (int i = 0; i < mysql_num_fields(res2); i++)
							{
								if (row2[i] == NULL) cout << "NULL ";
								else cout << row2[i] << "  ";
							}
							cout << "\n";
						}
						mysql_free_result(res2);
					}
					break;
				}

				case '2':
				{
					cout << "Introdu denumirea produsului pe care doresti sa il cauti: \n";
					string n, p;
					cout << "Denumire: ";
					cin >> n;
					string query = "SELECT * FROM Produse WHERE Denumire='" + n + "';";
					const char* q = query.c_str();
					int state = mysql_query(connection2, q);
					if (state) cout << "Eroare!";
					else
					{
						cout << "\n";
						res2 = mysql_store_result(connection2);
						while (row2 = mysql_fetch_row(res2))
						{
							for (int i = 0; i < mysql_num_fields(res2); i++)
							{
								if (row2[i] == NULL) cout << "NULL ";
								else cout << row2[i] << "  ";
							}
							cout << "\n";
						}
						mysql_free_result(res2);
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

void stergeToateProdusele()
{
	connection2 = mysql_init(0);
	connection2 = mysql_real_connect(connection2, "localhost", "root", "password", "Magazin", 3306, NULL, 0);
	if (connection2)
	{
		if (mysql_query(connection2, "SELECT COUNT(ID) FROM Produse;") == 0)
		{
			res2 = mysql_store_result(connection2);
			if (strcmp(mysql_fetch_row(res2)[0], "0") == 0) cout << "Nu exista niciun produs.\n\n";
			else
			{
				mysql_free_result(res2);
				int state = mysql_query(connection2, "DELETE FROM Produse;");
				if (state) cout << "Eroare q!";
				else cout << "Toate produsele au fost sterse cu succes!\n";
			}
		}
		else cout << "Eroare q!";
	}
	else cout << "Eroare!";
	cout << "\n";
}

#endif
