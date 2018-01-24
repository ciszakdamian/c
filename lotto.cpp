#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
using namespace std;
int typowane[6], losowane[6], konto=100, trafien = 0;
void typowanie()
{
	system("cls");
	cout << "| Podaj 6 liczb kt�re typujesz w losowaniu LOTTO (od 1 do 49) |" << endl;
	for(int i = 0;i<=5;i++)
	{	
		int typ, repeatTest;
		do
		{
			repeatTest = 0;
			cout << "Typ " << i+1 << ":";
			while(!(cin>>typ))
			{
  			cout << "Podaj tylko liczby ca�kowite!" <<endl; 
  	  		cout << "Wprowadz poprawn� liczbe: "; 		
  			cin.clear(); 
 			cin.sync(); 
			}
			
			if(typ<1 || typ>49){
				cout << "Podany typ "<< i+1 <<" jest po za zakresem losowania. Podaj poprawny!" << endl;
			}
			for (int n = 0;n<=5;n++)
			{
				if(typowane[n] == typ)
				{
					cout << "Podany typ: "<< typ <<" zosta� ju� wprowadzany. Podaj nowy niepowtarzalny (od 1 do 49)" << endl;
					repeatTest = 1;
				}				
			}
		}while(typ<1 || typ>49 || repeatTest !=0);
		typowane[i] = typ;
	}		
}
void losowanie()
{
	srand(time(0));
	for(int i = 0; i<=5;i++)
	{
		losowane[i] = (1 + rand()%49);	
	}	
}

void checkSystem()
{
	for(int i = 0; i<=5;i++)
	{
		char symbol = ',';
		char nawiasA = 00;
		char nawiasZ = 00;		
		if(typowane[i]==losowane[i])
		{
			nawiasA = '(';
			nawiasZ = ')';
			trafien++;
		}			
		if(i>4)symbol = 00;
		cout << nawiasA << typowane[i] << nawiasZ << symbol; 	
	}
}

void adwardSystem()
{
	if(trafien<3)cout << "Tw�j stan konta wynosi: " << konto << " z�otych";	
	if(trafien == 3)
	{
		cout << "Trafi�e� tr�jk�!" << endl;
		cout << "Na twoje konto trafia +2 z�" << endl;	
		konto = konto + 2;	
		cout << "Tw�j stan konta wynosi: " << konto << " z�otych";		
	}
	if(trafien == 4)
	{
		cout << "Trafi�e� czw�rk�!" << endl;
		cout << "Na twoje konto trafia +10 z�" << endl;	
		konto = konto + 10;			
		cout << "Tw�j stan konta wynosi: " << konto << " z�otych";		
	}	
	if(trafien == 5)
	{
		cout << "Trafi�e� pi�tke!" << endl;
		cout << "Na twoje konto trafia +100 z�" << endl;	
		konto = konto + 100;			
		cout << "Tw�j stan konta wynosi: " << konto << " z�otych";		
	}
	if(trafien == 6)
	{
		cout << "Trafi�e� sz�stke!" << endl;
		cout << "Na twoje konto trafia +100000 z�" << endl;	
		konto = konto + 100000;			
		cout << "Tw�j stan konta wynosi: " << konto << " z�otych";		
	}			
	trafien = 0;
}

void printTab(int *n)
{
	char symbol = ',';
	for(int i = 0;i<=5;i++)
	{		
		if(i>4)symbol = ' ';
		cout << n[i] << symbol <<" "; 				
	}	
}

void load()
{
cout <<"Load:"; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| "; Sleep(200);
cout << "| " << endl; Sleep(200);
cout << endl;	
}

void loadLos()
{
cout <<"Losowanie:"; Sleep(100);
cout << "* "; Sleep(170);
cout << "* "; Sleep(170);
cout << "* "; Sleep(170);
cout << "* "; Sleep(170);
cout << "* "; Sleep(170);
cout << "* "; Sleep(170);
cout << endl;	
}

void clearTab(int *n)
{
	for(int i = 0; i<=5; i++)
	{
		n[i] = 0;
	}
	
}
int main(int argc, char** argv) {
char znak, znak2, znak3;
setlocale(LC_ALL,"");

cout <<" ===============================================================\n"
	<<"|                         LOTTO                                 |\n"
    <<"|---------------------------------------------------------------|\n"
    <<"|         CDV(C)2018 Damian Ciszak nr albumu 22990              |\n"
    <<" ===============================================================\n\n";
load();
do
{	 
	do
	{
		system("cls");
		int opcja;
		cout << "----MENU----" << endl;
		cout << "1. Opis gry " << endl;
		cout << "2. Graj " << endl;
		cout << "3. Wyj�cie" << endl;
		cout << "------------" << endl;		
		cin >> opcja;		
		switch(opcja)
		{
			case 1:
				system("cls");
				cout << "-----------------------------------------------Opis Gry--------------------------------------------------"<< endl;			
				cout << "Gra polega na typowaniu 6 niepowtarzalnych liczb od 1 do 49."<< endl;
				cout << "Nastepnie komputer przeprowadza losowanie 6 liczb z tego samego zakresu"<< endl;		
				cout << "Je�eli gracz trafi� to liczba zostaje oznaczona (nawiasami)"<< endl;	
				cout << "Na start u�ytkownik dostaje 100z�, za tr�jk� 2z�, za czw�rk� 10z�, za pi�tke 100z�, za sz�stk� 100000z�."<< endl;
				cout << "-----------------------------------------------Powodzenia!-----------------------------------------------"<< endl;
				cout << "Czy powr�cic do menu gry? T/N"<< endl;
				cin >> znak2;										
			break;
			case 2:
				do
				{
					system("cls");
					cout << "Losowanie: "; printTab(typowane);
					typowanie();
					loadLos();
					system("cls");
					losowanie();
					cout << "Losowanie: "; printTab(losowane);
					cout << endl;
					cout << "Typowanie: "; checkSystem();	
					cout << endl;	
					adwardSystem();	
					cout << endl;
					clearTab(typowane);
					cout << endl << "Czy chcesz kontynuowac gre? T/N" << endl;
					cin >> znak3;
				}
				while(znak3=='t' || znak3=='T');
			break;
			case 3:
		
			break;
			default:
				cout << "Wybierz poprawn� opcje" << endl;
			break;	
		}	
	}
	while(znak2=='t' || znak2=='T');
konto = 100;	
cout << endl << "Czy chcesz wyj�� z gry? T/N" << endl;
cin >> znak;
}
while(znak=='n' || znak=='N');
}
