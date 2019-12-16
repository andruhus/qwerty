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
	bool Is_Surname_Corr(char surname[64]);
	bool Is_Name_Corr(char name[64]);
	bool Is_Num_Corr(char surname[9]);
	bool Is_City_Corr(char surname[64]);
	bool Is_Job_Corr(char surname[64]);
	bool Is_Birth_Corr(char year[4], char month[2], char day[2]);
public:
	
	void SetKont(char surnam[64],char nam[64],char num[9],char town[64],char occ[64],char year1[4],char month1[2],char day1[2])
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
		if (Is_Birth_Corr(year1,month1,day1))
		{
			for (int i = 0; i < 4; i++)
				date.year[i] = year1[i];
			for (int i = 0; i < 2; i++)
				date.month[i] = month1[i];
			for (int i = 0; i < 2; i++)
				date.day[i] = day1[i];
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
		uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing mobile phone
		for (int i = 0; i < 13; i++)
		{
			fwrite(&nom[i], sizeof(char), 1, a);
		}



		// separate mobile phone and city
		uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing city
		for (char qw : city)
			fwrite(&qw, sizeof(char), 1, a);



		// separate city and occupation
		uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);


		// writing occupation
		for (char qw : job)
			fwrite(&qw, sizeof(char), 1, a);



		// separate occupation and birthdate
		uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);

		
		// writing birthdate
			// year
		for (char qw : date.year)
			fwrite(&qw, sizeof(char), 1, a);

		uy = ' ';
		fwrite(&uy, sizeof(char), 1, a);

			// month
		for (char qw : date.month)
			fwrite(&qw, sizeof(char), 1, a);

		uy = ' ';
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
			if(qw > 0)
				cout << qw;
		cout << endl;

		cout << "Name: ";
		for (char qw : name)
			if (qw > 0)
			cout << qw;
		cout << endl;

		cout << "Mobile phone: ";
		for (char qw : nom)
			if (qw > 0)
			cout << qw;
		cout << endl;

		cout << "Native city: ";
		for (char qw : city)
			if (qw > 0)
			cout << qw;
		cout << endl;

		cout << "Occupation: ";
		for (char qw : job)
			if (qw > 0)
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
		
		cout << "What do you want to edit?" << endl;
		cout << "1 - Surname" << endl << "2 - Name" << endl;
		cout << "3 - Mobile phone" << endl << "4 - Native city" << endl << "5 - Occupation" << endl;
		cout << "6 - Birthdate";
		char r;
		cin >> r;
		switch (r)
		{
		case '1': cout << "Enter new surname: "; ChangeSurname(); break;
		case '2': cout << "Enter new surname: "; ChangeSurname(); break;
		case '3': cout << "Enter new surname: "; ChangeSurname(); break;
		case '4': cout << "Enter new surname: "; ChangeSurname(); break;
		case '5': cout << "Enter new surname: "; ChangeSurname(); break;
		case '6': cout << "Enter new surname: "; ChangeSurname(); break;
		default:
			cout << "There is no such a commad break;
		}
		/*cout << "Enter a surname: ";
		cin >> s1;
		cout << "Enter a name: ";
		cin >> s2;
		cout << "Enter the number: +380";
		cin >> p;
		SetKont(s1, s2, p);*/
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