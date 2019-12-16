#pragma once
#pragma warning (disable: 4996)
class Kont
{
private:
	char surname[64];
	char name[64];
	char nom[13] = { '+','3','8','0' };
	char city[64];
	char job[64];
	struct { unsigned int year = 0, month = 0, day = 0; } date;
	bool Is_Surname_Corr(char surname[64]);
	bool Is_Name_Corr(char name[64]);
	bool Is_Num_Corr(char surname[9]);
	bool Is_City_Corr(char surname[64]);
	bool Is_Birth_Corr(char year[4], char month[2], char day[2]);
	void ChangeSurname();
	void ChangeName();
	void ChangeMob();
	void ChangeCity();
	void ChangeJob();
	void ChangeBirth();
public:

	void SetKont(char surnam[64], char nam[64], char num[9], char town[64], char occ[64], char year1[4], char month1[2], char day1[2]);

	void Write(FILE* a);

	void Display();


	void EditKont();



};