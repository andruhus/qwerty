#include <iostream>
#include "Kont.h"
#pragma warning (disable: 4996)
using namespace std;

void Kont::SetKont(char surnam[64], char nam[64], char num[9], char town[64], char occ[64], char year1[4], char month1[2], char day1[2])
{
	// surname
	if (Is_Surname_Corr(surnam))
	{
		for (int i = 0; i < 64; i++)
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





	// Birthdate
	if (Is_Birth_Corr(year1, month1, day1))
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

void Kont::Write(FILE* a)
{
	a = fopen("Abonent.txt", "ab");
	// writing a surname
	for (char qw : surname)
	{
		fwrite(&qw, sizeof(char), 1, a);
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

void Kont::Display()
{
	cout << "Surname: ";
	for (char qw : surname)
		if (qw > 0)
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

void Kont::EditKont()
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
	case '2': cout << "Enter new name: "; ChangeName(); break;
	case '3': cout << "Enter new mobile phone: "; ChangeMob(); break;
	case '4': cout << "Enter new city: "; ChangeCity(); break;
	case '5': cout << "Enter new occupation: "; ChangeJob(); break;
	case '6': cout << "Enter new birthdate: "; ChangeBirth(); break;
	default:
		cout << "There is no such a commad";
	}
	/*cout << "Enter a surname: ";
	cin >> s1;
	cout << "Enter a name: ";
	cin >> s2;
	cout << "Enter the number: +380";
	cin >> p;
	SetKont(s1, s2, p);*/
}



void Kont::ChangeSurname()
{
	while (true)
	{
		char surnam[64] = { " " };
		while (surnam == " ")
			cin.getline(surnam, 64);
		if (Is_Surname_Corr(surnam))
			for (int i = 0; i < 64;i++)
			{
				if (surnam[i] != ' ')
					surname[i] = surnam[i];
				else
					return;
			}


	}
}

void Kont::ChangeName()
{
	while (true)
	{
		char nam[64] = { " " };
		while (nam == " ")
			cin.getline(nam, 64);
		if (Is_Name_Corr(nam))
			for (int i = 0; i < 64;i++)
			{
				if (nam[i] != ' ')
					name[i] = nam[i];
				else
					return;
			}


	}
}

void Kont::ChangeMob()
{
	
	while (true)
	{
		char mob[13] = { "e" };
		while (mob == "e")
			cin.getline(mob, 64);
		if (Is_Name_Corr(mob))
			for (int i = 0; i < 13; i++)
			{
					nom[i] = mob[i];
			}
	}
	
}

void Kont::ChangeCity()
{
	while (true)
	{
		char tow[64] = { " " };
		while (tow == " ")
			cin.getline(tow, 64);
		if (Is_City_Corr(tow))
			for (int i = 0; i < 64; i++)
			{
				if (tow[i] != ' ')
					city[i] = tow[i];
				else
					return;
			}


	}
}

void Kont::ChangeJob()
{
	while (true)
	{
		char work[64] = { " " };
		while (work == " ")
			cin.getline(work, 64);
		for (int i = 0; i < 64; i++)
		{
			if (work[i] != ' ')
				city[i] = work[i];
			else
				return;
		}


	}
}

void Kont::ChangeBirth()
{

}