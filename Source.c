#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 10000

int oktalni_konverzija(int broj) {

	int oktalni_broj = 0;
	int i = 1;

	while (broj != 0)
	{
		oktalni_broj = oktalni_broj + (broj % 8) * i;
		broj = broj / 8;
		i = i * 10;
	}

	return oktalni_broj;

}

int dekadni_konverzija(int broj) {

	int dekadni_broj = 0;
	int ostatak = 0;
	int eksponent = 0;

	while (broj > 0)
	{
		ostatak = broj % 10;
		dekadni_broj += ostatak * pow(8, eksponent);
		eksponent++;
		broj /= 10;
	}
	return dekadni_broj;
}

void stampanje_niza(int niz[], int n) {

	for (int i = 0; i < n; i++)
	{
		printf("%d ", niz[i]);
	}
	printf("\n");
}

void stampanje_niza_karaktera(char niz[]) {

	for (int i = 0; i < niz[i] != '\0'; i++)
	{
		printf("%c", niz[i]);
	}
	printf("\n");
}

void sifrovanje() {

	char tekst[MAX_SIZE]; // Niz za cuvanje unetog teksta
	int i, broj;
	int niz[MAX_SIZE];
	int n = 0;
	int poslednji_niz[MAX_SIZE];
	int m = 0;
	/*char sifra[MAX_SIZE];*/

	printf("Unesite tekst: ");
	fgets(tekst, 1000, stdin); // Ucitavanje teksta sa standardnog ulaza (tastatura)

	// Prolazak kroz svaki karakter unetog teksta
	for (i = 0; tekst[i] != '\0'; i++) {
		char karakter = tekst[i];
		
		// Provera da li je karakter slovo
		if (isalpha(karakter)) {
			broj = tolower(karakter) - 'a' + 1; // Konverzija u broj (mala slova)
		}
		else if (isspace(karakter)) {
			broj = 0; // Razmak postaje 00
		}
		else {
			broj = -1; // Za sve ostale karaktere stavljamo -1 (opcionalno)
		}

		niz[n++] = broj;
	}

	//stampanje_niza(niz, n);

	//Konvertovanje o oktalni
	for (int i = 0; i < n; i++)
	{
		int oktalni = oktalni_konverzija(niz[i]);
		niz[i] = oktalni;
	}

	//stampanje_niza(niz, n);

	//Dodavanje koeficijenta 
	int koeficijent = 1;
	for (int i = 0; i < n; i++)
	{
		niz[i] = niz[i] + koeficijent;
		koeficijent = koeficijent_formiranje_sifrovanje(koeficijent);
	}

	//stampanje_niza(niz, n);

	//Ponovno pretvaranje u oktalni
	for (int i = 0; i < n; i++)
	{
		int oktalni = oktalni_konverzija(niz[i]);
		niz[i] = oktalni;
	}

	//stampanje_niza(niz, n);

	//Formiranje niza u kom je svaki element jedna cifra
	for (int i = 0; i < n; i++)
	{
		int prva = niz[i] / 10;
		int druga = niz[i] % 10;
		poslednji_niz[m++] = prva;
		poslednji_niz[m++] = druga;
	}

	//stampanje_niza(poslednji_niz, m);

	//Konacno sifrovanje
	for (int i = 0; i < m; i++)
	{
		if (poslednji_niz[i] == 0)
		{
			//sifra[i] = '#';
			printf("#");
		}
		else if (poslednji_niz[i] == 1)
		{
			//sifra[i] = '@';
			printf("@");
		}
		else if (poslednji_niz[i] == 2)
		{
			//sifra[i] = '/';
			printf("/");
		}
		else if (poslednji_niz[i] == 3)
		{
			//sifra[i] = '?';
			printf("?");
		}
		else if (poslednji_niz[i] == 4)
		{
			//sifra[i] = '*';
			printf("*");
		}
		else if (poslednji_niz[i] == 5)
		{
			//sifra[i] = '$';
			printf("$");
		}
		else if (poslednji_niz[i] == 6)
		{
			//sifra[i] = '!';
			printf("!");
		}
		else if (poslednji_niz[i] == 7)
		{
			//sifra[i] = '+';
			printf("+");
		}
	}
	//stampanje_niza_karaktera(sifra);
	printf("\n");
}

int koeficijent_formiranje_sifrovanje(int k) {

	if (k == 1)
	{
		return 2;
	}
	else if (k == 2)
	{
		return 3;
	}
	else if (k == 3)
	{
		return 4;
	}
	else if (k == 4)
	{
		return 5;
	}
	else if (k = 5)
	{
		return 1;
	}

}

int koeficijnet_formiranje_desifrovanje(int k) {

	if (k == 5)
	{
		return 4;
	}
	else if (k == 4)
	{
		return 3;
	}
	else if (k == 3)
	{
		return 2;
	}
	else if (k == 2)
	{
		return 1;
	}
	else if (k == 1)
	{
		return 5;
	}

}

void desifrovanje() {

	char tekst[MAX_SIZE];
	int niz[MAX_SIZE];
	int n = 0;
	int niz_dve_cifre[MAX_SIZE];
	int m = 0;
	int k = 0;

	printf("Unetite tekst: ");

	fgets(tekst, 1000, stdin);

	//stampanje_niza_karaktera(tekst);

	//Pretvaranje karakteristicnih karaktera u cifre
	for (int i = 0; tekst[i] != '\0'; i++)
	{
		if (tekst[i] == '#')
		{
			niz[n++] = 0;
		}
		else if (tekst[i] == '@')
		{
			niz[n++] = 1;
		}
		else if (tekst[i] == '/')
		{
			niz[n++] = 2;
		}
		else if (tekst[i] == '?')
		{
			niz[n++] = 3;
		}
		else if (tekst[i] == '*')
		{
			niz[n++] = 4;
		}
		else if (tekst[i] == '$')
		{
			niz[n++] = 5;
		}
		else if (tekst[i] == '!')
		{
			niz[n++] = 6;
		}
		else if (tekst[i] == '+')
		{
			niz[n++] = 7;
		}
	}

	//stampanje_niza(niz, n);

	//Formiranje novog niza spajanjem svake dve cifre
	for (int i = 0; i < n - 1; i += 2)
	{
		int cifra = niz[i] * 10 + niz[i + 1];
		niz_dve_cifre[m++] = cifra;
	}

	//stampanje_niza(niz_dve_cifre, m);

	//Pretvaranje iz oktalnog u dekadni
	for (int i = 0; i < m; i++)
	{
		int novi = dekadni_konverzija(niz_dve_cifre[i]);
		niz_dve_cifre[i] = novi;
	}

	//stampanje_niza(niz_dve_cifre, m);

	//Oduzimanje koeficijenta 2
	int koeficijent = m % 5;
	for (int i = m-1; i >= 0; i--)
	{
		niz_dve_cifre[i] = niz_dve_cifre[i] - koeficijent;
		koeficijent = koeficijnet_formiranje_desifrovanje(koeficijent);
	}

	//stampanje_niza(niz_dve_cifre, m);

	//Pretvaranje iz oktalnog u dekadni
	for (int i = 0; i < m; i++)
	{
		int novi = dekadni_konverzija(niz_dve_cifre[i]);
		niz_dve_cifre[i] = novi;
	}

	//stampanje_niza(niz_dve_cifre, m);

	//Konacno desifrovanje
	for (int i = 0; i < m; i++)
	{
		if (niz_dve_cifre[i] == 0)
		{
			printf(" ");
			continue;
		}
		char r = 96 + niz_dve_cifre[i];
		printf("%c", r);
	}

	//stampanje_niza_karaktera(tekst);
	printf("\n");
}

int main(void) {

	int a;
	
	printf("Dobrodosli u program za sifrovanje.\n\n");
	printf("Sifrovanje: 1\n");
	printf("Desifrovanje: 2\n");
	printf("Izadji iz programa: 3\n\n");
	printf("Unesite broj: ");

	scanf("%d", &a);
	getchar();

	if (a == 1)
	{
		sifrovanje();
		system("pause");
	}
	else if (a == 2)
	{
		desifrovanje();
		system("pause");
	}
	else if (a == 3)
	{
		return;
	}
	else
	{
		printf("GRESKA\n\n");
	}

	main();
	
	return;
}