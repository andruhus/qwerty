#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#pragma warning(disable:4996)
using namespace std;

class Kont
{
private:
	char surname[64];
	char name[64];
	char nom[13] = { '+','3','8','0' };
	char city[64];
	char job[64];
	struct birthdate { char year[4]; char month[2]; char day[2]; } date;
public:
	bool Is_Surname_Corr(char surname[64]);
	bool Is_Name_Corr(char name[64]);
	bool Is_Num_Corr(char surname[9]);
	bool Is_City_Corr(char surname[64]);
	bool Is_Job_Corr(char surname[64]);
	bool Is_Birth_Corr(birthdate date);
	void SetKont(char surnam[64],char nam[64],char num[9],char town[64],char occ[64],birthdate dat)
	{
		// surname
		if (Is_Surname_Corr(surnam))
		{
			for(int i = 0;i<64;i++)
				surname[i] = surnam[i];
		}
		else
			cout << "The surname is incorrect" << endl;


		// name
		if (Is_Name_Corr(nam))
		{
			for (int i = 0; i < 64; i++)
				name[i] = nam[i];
		}
		else
			cout << "The name is incorrect" << endl;


		// phone number
		if (Is_Num_Corr(num))
			for (int i = 0; i < 9; i++)
				nom[i + 4] = num[i];
		else
			cout << "The number is incorrect" << endl;


		// city
		if (Is_City_Corr(town))
		{
			for (int i = 0; i < 64; i++)
				city[i] = town[i];
		}
		else
			cout << "The city is incorrect" << endl;


		// occupation
		if (Is_Job_Corr(occ))
		{
			for (int i = 0; i < 64; i++)
				job[i] = occ[i];
		}
		else
			cout << "The occupation is incorrect" << endl;


		// Birthdate
		if (Is_Birth_Corr(dat))
		{
			for (int i = 0; i < 4; i++)
				date.year[i] = dat.year[i];
			for (int i = 0; i < 2; i++)
				date.month[i] = dat.month[i];
			for (int i = 0; i < 2; i++)
				date.day[i] = dat.day[i];
		}
		else
			cout << "The birthdate is incorrect" << endl;
	}

	void Write(FILE* a)
	{
		a = fopen("Abonent.txt", "ab");
		// writing a surname
		for (char qw : surname)
		{
			fwrite(&qw,sizeof(char), 1, a);
		}



		// separate surname and name
		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing a name
		for (char qw : name)
		{
			fwrite(&qw, sizeof(char), 1, a);
		}
		fwrite(&uy, sizeof(char), 1, a);



		// separate name and mobile phone
		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing mobile phone
		for (int i = 0; i < 13; i++)
		{
			fwrite(&nom[i], sizeof(char), 1, a);
		}



		// separate mobile phone and city
		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing city
		for (char qw : city)
			fwrite(&qw, sizeof(char), 1, a);



		// separate city and occupation
		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing occupation
		for (char qw : job)
			fwrite(&qw, sizeof(char), 1, a);



		// separate occupation and birthdate
		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);

		
		// writing birthdate
			// year
		for (char qw : date.year)
			fwrite(&qw, sizeof(char), 1, a);

		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);

			// month
		for (char qw : date.month)
			fwrite(&qw, sizeof(char), 1, a);

		char uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);

			// day
		for (char qw : date.day)
			fwrite(&qw, sizeof(char), 1, a);

		// finish writing a contact
		uy = '\n';
		fwrite(&uy, sizeof(char), 1, a);
		
		
		fclose(a);
	}

	void Display()
	{
		cout << "Surname: ";
		for (char qw : surname)
			cout << qw;
		cout << endl;

		cout << "Name: ";
		for (char qw : name)
			cout << qw;
		cout << endl;

		cout << "Mobile phone: ";
		for (char qw : nom)
			cout << qw;
		cout << endl;

		cout << "Native city: ";
		for (char qw : city)
			cout << qw;
		cout << endl;

		cout << "Occupation: ";
		for (char qw : job)
			cout << qw;
		cout << endl;

		cout << "Birthday: ";
		for (char qw : date.day)
			cout << qw;
		cout << ".";
		for (char qw : date.month)
			cout << qw;
		cout << ".";
		for (char qw : date.year)
			cout << qw;
		cout << endl;


	}


	void EditKont()
	{
		string s1, s2, p;
		cout << "Enter a surname: ";
		cin >> s1;
		cout << "Enter a name: ";
		cin >> s2;
		cout << "Enter the number: +380";
		cin >> p;
		SetKont(s1, s2, p);
	}

	

};

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
			
			if ((int)v == 10 && ch > 64 && ch < 123)
			{
				noi++;
				cout << noi << ')' << ' ';

			}
			std::cout << (char)ch;
			v = ch;
		}
	}
}

void AddCont(FILE* a)
{
	
	
	string s1, s2,p;
	cout << "Enter a surname: ";
	cin >> s1;
	cout << "Enter a name: ";
	cin >> s2;
	cout << "Enter the number: +380";
	cin >> p;
	
	Kont ret;
	ret.SetKont(s1, s2, p);
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
	while ((ch= getc(a)) != EOF)
	{
		if(ch == 10)
		nKont++;
	}
	Kont* mas = new Kont[nKont];

	int o = 0;
	string s1, s2, p;
	fseek(a, 0, SEEK_SET);
	while ((ch = getc(a)) != EOF)
	{
		
		if (ch == 10)
		{
			o++;
			o = o % 3;
			p.erase(0, 4);
			mas[i].SetKont(s1, s2, p);
			i++;
			s1 = ""; s2 = ""; p = "";
			continue;
		}
		if (ch == 32)
		{
			o++;
			o = o % 3;
			continue;
		}

		if (o == 0)
			s1 += (char)ch;
		else if (o == 1)
			s2 += (char)ch;
		else
			p += (char)ch;
	}
	
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
	fclose(a);

	for (int j = 0; j < nKont; j++)
	{
		mas[j].Write(a);
	}
	


}

void DelCont(FILE* a)
{
	a = fopen("Abonent.txt", "rb");
	int i = 0;
	int nKont = 0;
	int ch;
	while ((ch = getc(a)) != EOF)
	{
		if (ch == 10)
			nKont++;
	}
	Kont* mas = new Kont[nKont];

	int o = 0;
	string s1, s2, p;
	fseek(a, 0, SEEK_SET);
	while ((ch = getc(a)) != EOF)
	{

		if (ch == 10)
		{
			o++;
			o = o % 3;
			p.erase(0, 4);
			mas[i].SetKont(s1, s2, p);
			i++;
			s1 = ""; s2 = ""; p = "";
			continue;
		}
		if (ch == 32)
		{
			o++;
			o = o % 3;
			continue;
		}

		if (o == 0)
			s1 += (char)ch;
		else if (o == 1)
			s2 += (char)ch;
		else
			p += (char)ch;
	}

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
	fclose(a);

	for (int j = 0; j < nKont; j++)
	{
		if(j != i)
		mas[j].Write(a);
	}

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