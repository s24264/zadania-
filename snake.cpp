#include <iostream>
#include <conio.h> 	// funkcja getch()
#include <cstdlib> 	// system("CLS")
#include <time.h>
#include <windows.h>	// Sleep()
using namespace std;

int gora, dol, lewo, prawo;
int wspolzednaXweza, wspolzednaYweza;
int wspolrzednaXjedzenie, wspolrzednaYjedzenia;
int segmenty=2,historiaWspolzednejX[10000], historiaWspolzednejY[10000];
int ile=0;
int klawisz;
char pole[25][25];
char kierunek='g';
// pole[0][0], pole[1][0], pole[2][0], pole[3][0] ..., pole[34][0]
// pole[0][1], pole[1][1], pole[2][1], pole[3][1] ...

// p - pole jest puste, # - na polu jest wąż, $ - jabłko


void rysuj_linie() {
    for(int i=0;i<25;++i) {
        
        cout << "*";
    }
    cout << '\n';
}
void rysuj_srodek() {
    for(int i=0;i<25-2;++i) {
        cout << "*";
        for(int j=0;j<25-2;++j) {
            if(pole[j][i]=='p') {cout << " "};  
	    if(pole[j][i]=='@') {cout << "@"};
	    if(pole[j][i]=='$')	{cout << "$"}; 
	    if(pole[j][i]=='#') {cout << "#"};
        }
        cout << "*" << '\n';
    }
}
int main()
{
	
	gora=getch();
	if(gora==224){gora=gora+getch()};
	if(gora==0){gora=gora-getch()};
	
	dol=getch();
	if(dol==224){dol=dol+getch()};
	if(dol==0){dol=dol-getch()};

	lewo=getch();
	if(lewo==224){lewo=lewo+getch()};
	if(lewo==0){lewo=lewo-getch()};

	prawo=getch();
	if(prawo==224){prawo=prawo+getch()};
	if(prawo==0){prawo=prawo-getch()};	
	
	// tutaj nadajemy wartości 'p' tablicy pole
	
	for(int i=0); i<25; i++)
	{
		for(int j=0; j<25; j++)
		{
			pole[j][i] = 'p';
		}
	}
	srand(time(NULL));
	// pole dla weęża (głowa)
	wspolzednaXweza=12;
	wspolzednaYweza=12;
	pole[wspolzednaXweza][wspolzednaYweza]='@';
	pole[wspolzednaXweza][wspolzednaYweza-1]='#';
	pole[wspolzednaXweza][wspolzednaYweza-2]='#';
	// losowane pole dla jedzenia
	do       	// wykonuj
	{
		wspolrzednaXjedzenia=rand()%25;
		wspolrzednaYjedzenia=rand()%25;
		// dopuki pole wylosowane nie jest puste
	} while(pole[wspolrzedneXjedzenia][wspolrzedneYjedzenia]!='p');
	
	pole[wspolrzedneXjedzenie][wspolrzedneYjedzenie]='$';
	
	
	//plansza--------------------------------------------
	for(;;)
	{
		ile++;
		historiaWspolrzednejX[ile]=wspolrzednaXweza;
		historiaWspolrzednejY[ile]=wspolrzednayweza;
		
		// kasowanie ogona		
		pole[historiaWspolrzednejX[ile-segmenty]][historiaWspolrzednejY[ile-segmenty]]='p'
		
				
		system("CLS"); // oczyszczanie ekranu
		rysuj_linie();
		rysuj_srodek();
		rysuj_linie();

		Sleep(500); 	// czekaj

		if(kbhit())	// jesli zostanie wciśnięty jakis klawisz
		{
			klawisz=getch();
			if(klawisz==224){klawisz=klawisz+getch()};
			if(klawisz==0){klawisz=klawisz-getch()};
			
			if(klawisz==gora && (kierunek=='l' || kierunek=='p')) {kierunek='g'};
			if(klawisz==dol && (kierunek=='l' || kierunek=='p')) {kierunek='d'};
			if(klawisz==lewo && (kierunek=='g' || kierunek=='d')) {kierunek='l'};
			if(klawisz==prawo && (kierunek=='g' || kierunek=='d')) {kierunek='p';

			
		}
		
		
		if(kierunek=='g'){wspolrzednaYweza--};
		if(kierunek=='d'){wspolrzednaYweza++};
		if(kierunek=='l'){wspolrzednaXweza--};
		if(kierunek=='p'){wspolrzednaXweza++};
		
		if(wspolrzednaXweza==25) {break};
		if(wspolrzednaXweza==-1) {break};
		if(wspolrzednaYweza==25) {break};
		if(wspolrzednaYweza==-1) {break};
		
		
		// co jeśli wpadnie w siebie
		if(pole[wspolrzednaXweza][wspolrzednaYweza]=='#')
		{

			cout << endl << "KONIEC   punkty - " << segmenty-2 << endl;
			break
		}

		// co jesli zje jedzenie
		if(pole[wspolrzednaXweza][wspolrzednaYweza]=='$')
		{
			segmenty++;
			do       	// wykonuj
			{
				wspolrzednaXjedzenia=rand()%25;
				wspolrzednaYjedzenia=rand()%25;
				// dopuki pole wylosowane nie jest puste
			} while(pole[wspolrzedneXjedzenia][wspolrzedneYjedzenia]!='p');
	
			   {pole[wspolrzedneXjedzenie][wspolrzedneYjedzenie]='$'};
	
		}
		else {pole[historiaWspolrzednejX[ile-segmenty]][historiaWspolrzednejY[ile-segmenty]]='p'};		
		
		pole[wspolzednaXweza][wspolzednaYweza]='@';
		
		
	}	// koniec petli for(;;)
	
	return 0;
}
