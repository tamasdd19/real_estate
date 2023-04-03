#ifndef IMOBILIARE_H_INCLUDED
#define IMOBILIARE_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define MAX_C 30

typedef struct imobil
{
	char* titlu;
    int pret;
	short tip; // 1=apartament,0=casa
	short suprafata; // metrii patrati
	short confort;
	short anul_constructiei;
	short numar_camere;
	short numar_bai;
	short etaj; // pentru apartamente, etajul la care e, pentru case cate etaje are
	short numar_balcoane;
    short piscina; // 1==da;0==nu
	short terasa;  // la fel ca mai sus, da sau nu
}imobil;

typedef struct Lista_imobile
{
    imobil* Imobil;
    int capacitate;
    int nr_imobile;
}Lista_imobile;

typedef struct Lista_imobile_favorite
{
    imobil* lista;
    int* pozitii;
    int nr_favorite;
}Lista_imobile_favorite;

Lista_imobile* initializare_lista(int n);

Lista_imobile_favorite* initializare_lista_favorite(Lista_imobile* lista);

imobil* copiere_imobile(imobil* de_copiat, int capacitate, int nr_imobile);

int* sortare_pozitii(int* pozitii, int nr_favorite);

int* copiere_pozitii(int* de_copiat, int nr_imobile, int nr_favorite);

void realloc_capacity(Lista_imobile* lista);

void afisare_lista(const Lista_imobile* lista);

void adaugare_imobile(Lista_imobile* lista, imobil* de_adaugat, Lista_imobile_favorite* lista_favorite);

void adaugare_favorite(Lista_imobile_favorite* lista, Lista_imobile* lista_imobile, int indice);

void initializare_imobile(Lista_imobile* lista_imobile, Lista_imobile_favorite* lista_favorite);

void rescriere_fisier(const Lista_imobile* lista);

int acelasi_titlu(const Lista_imobile* imobil1, const imobil* imobil2);

short afisare_imobil(imobil* nume_imobil, int cu_favorite); // 1=cu favorite, 0=fara favorite

void textcolor(int color);

void resetBuffer();

short meniu(char** optiuni, int inceput, int n, char c); // c este acolo pentru a nu pune de 2 ore newline cand afisam date din fisier

void cumparare_imobil(Lista_imobile* lista, short pozitie);

void eliminare_favorite(Lista_imobile_favorite* lista, int pozitie);

void verificare_favorite(Lista_imobile_favorite* lista, int optiune);

short meniu_cumparare(Lista_imobile* lista_imobile, Lista_imobile_favorite* lista_favorite);

short meniu_favorite(Lista_imobile* lista, Lista_imobile_favorite* lista_favorite);

void meniu_vanzare(Lista_imobile* lista_imobile, Lista_imobile_favorite* lista_favorite);

#endif