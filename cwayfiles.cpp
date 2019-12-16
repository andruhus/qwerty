#include <iostream>
#include "Kont.h"
#include <conio.h>
#pragma warning (disable: 4996)
using namespace std;





void ContDisplay(FILE* a)
{
	if ((a = fopen("Abonent.txt", "rb")) != NULL)
	{
		int ch;
		int noi = 1;
		char v = ' ';
		cout << noi << ')' << ' ';
		while ((ch = getc(a)) != EOF)
		{
			
			if ((int)v == 10)
			{
				noi++;
				cout << noi << ')' << ' ';

			}
			cout << ch;
			v = ch;
		}
	}
}

void AddCont(FILE* a)
{
	
	
	char surname[64];
	char name[64];
	char nom[9];
	char city[64];
	char job[64];
	char year[4];
	char month[2];
	char day[2];
	cout << "Enter a surname: ";
	cin.getline(surname, 64);
	cout << "Enter a name: ";
	cin.getline(name, 64);
	cout << "Enter the number: +380";
	cin.getline(nom, 9);
	cout << "Enter a native city: ";
	cin.getline(city, 64);
	cout << "Enter an occupation: ";
	cin.getline(job, 64);
	cout << "Enter your birthdate:" << endl;
	cout << "Year: ";
	cin.getline(year, 4);
	cout << "Month: ";
	cin.getline(month, 2);
	cout << "Day: ";
	cin.getline(day, 2);
	
	Kont ret;
	ret.SetKont(surname, name, nom, city, job, year, month, day);
	ret.Write(a);
	
	system("cls");
	cout << "The contact was successfully added" << endl;
	ret.Display();
	system("pause");
	system("cls");
	
}



void EditCont(FILE* a)
{
	
	a = fopen("Abonent.txt", "rb");
	int i = 0;
	int nKont = 0;
	int ch;
	// here we count how many contacts the file has
	while ((ch= getc(a)) != EOF)
	{
		if(ch == 10)
		nKont++;
	}
	Kont* mas = new Kont[nKont];

	// here we form the 'Kont* mas'
	int o = 0;
	char surname[64];
	char name[64];
	char nom[13];
	char city[64];
	char job[64];
	char year[4]; 
	char month[2]; 
	char day[2];
	fseek(a, 0, SEEK_SET);
	int j = 0;
	while ((ch = getc(a)) != EOF)
	{
		
		if (ch == 10)
		{
			o++;
			o = o % 8;
			mas[i].SetKont(surname, name, nom, city, job, year, month, day);
			i++;
			j = 0;
			continue;
		}
		if (ch == 32)
		{
			o++;
			j = 0;
			continue;
		}

		if (o == 0)
		{
			surname[j] = (char)ch;
			j++;
		}
		else if (o == 1)
		{
			name[j] = (char)ch;
			j++;
		}
		else if (o == 2)
		{
			nom[j] = (char)ch;
			j++;
		}
		else if (o == 3)
		{
			city[j] = (char)ch;
			j++;
		}
		else if (o == 4)
		{
			job[j] = (char)ch;
			j++;
		}
		else if (o == 5)
		{
			year[j] = (char)ch;
			j++;
		}
		else if (o == 6)
		{
			month[j] = (char)ch;
			j++;
		}
		else
		{
			day[j] = (char)ch;
			j++;
		}
	}
	
	// now the user chooses a contact which he wants to change
	for (int g = 0; g < nKont; g++)
	{
		cout << "Do you want to change this account?" << endl;
		mas[g].Display();
		cout << "Press 's' if yes" << endl;

		char s;
		cin >> s;
		if (s == 's')
		{
			i = g;
			break;
		}
		else
		{
			system("cls");
			if (g == nKont - 1)
				return;
			continue;
		}
		return;
	}


	mas[i].EditKont();
	system("cls");
	cout << "The contact was successfully edited" << endl;
	system("pause");
	system("cls");
	fclose(a);

	a = fopen("Abonent.txt", "w");
	

	for (int j = 0; j < nKont; j++)
	{
		mas[j].Write(a);
	}
	fclose(a);


}

void DelCont(FILE* a)
{
	a = fopen("Abonent.txt", "rb");
	int i = 0;
	int nKont = 0;
	int ch;
	// here we count how many contacts the file has
	while ((ch = getc(a)) != EOF)
	{
		if (ch == 10)
			nKont++;
	}
	Kont* mas = new Kont[nKont];

	// here we form the 'Kont* mas'
	int o = 0;
	char surname[64];
	char name[64];
	char nom[13];
	char city[64];
	char job[64];
	char year[4];
	char month[2];
	char day[2];
	fseek(a, 0, SEEK_SET);
	int j = 0;
	while ((ch = getc(a)) != EOF)
	{

		if (ch == 10)
		{
			o++;
			o = o % 8;
			mas[i].SetKont(surname, name, nom, city, job, year, month, day);
			i++;
			j = 0;
			continue;
		}
		if (ch == 32)
		{
			o++;
			j = 0;
			continue;
		}

		if (o == 0)
		{
			surname[j] = (char)ch;
			j++;
		}
		else if (o == 1)
		{
			name[j] = (char)ch;
			j++;
		}
		else if (o == 2)
		{
			nom[j] = (char)ch;
			j++;
		}
		else if (o == 3)
		{
			city[j] = (char)ch;
			j++;
		}
		else if (o == 4)
		{
			job[j] = (char)ch;
			j++;
		}
		else if (o == 5)
		{
			year[j] = (char)ch;
			j++;
		}
		else if (o == 6)
		{
			month[j] = (char)ch;
			j++;
		}
		else
		{
			day[j] = (char)ch;
			j++;
		}
	}

	// now the user chooses a contact which he wants to delete
	for (int g = 0; g < nKont; g++)
	{
		cout << "Do you want to delete this account?" << endl;
		mas[g].Display();
		cout << "Press 's' if yes" << endl;

		char s;
		cin >> s;
		if (s == 's')
		{
			i = g;
			break;
		}
		else
		{
			system("cls");
			if (g == nKont - 1)
				return;
			continue;
		}
		return;
	}

	system("cls");
	cout << "The contact was successfully deleted" << endl;
	system("pause");
	system("cls");

	a = fopen("Abonent.txt", "w");
	

	for (int j = 0; j < nKont; j++)
	{
		if(j != i)
		mas[j].Write(a);
	}
	fclose(a);
	return;
}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> Show all the contacts" << endl;
		else  cout << "   Show all the contacts" << endl;
		if (key == 1) cout << "-> Add a contact" << endl;
		else  cout << "   Add a contact" << endl;
		if (key == 2) cout << "-> Edit a contact" << endl;
		else  cout << "   Edit a contact" << endl;
		if (key == 3) cout << "-> Delete a contact" << endl;
		else  cout << "   Delete a contact" << endl;
		if (key == 4) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

void MENU(FILE* a)
{
	bool NonExit = 0;
	int answer = menu();
	switch (answer)
	{
	case 0: ContDisplay(a); break;
	case 1: AddCont(a); break;
	case 2: EditCont(a); break;
	case 3: DelCont(a); break;
	case 4: NonExit = 1; break;
	}
	system("pause");
	if (NonExit)
		return;
	else
		MENU(a);
}



void Kontacts()
{
	FILE* f;
	f = nullptr;
	// f = fopen("newProga.cpp");
	//fwrite()
	//f = fopen("Abonent.txt");
	MENU(f);
}