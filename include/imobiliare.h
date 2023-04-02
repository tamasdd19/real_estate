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

Lista_imobile lista_imobile;
Lista_imobile_favorite lista_favorite;

Lista_imobile initializare_lista(int n)
{
    Lista_imobile nou;
    nou.Imobil=(imobil*)malloc(sizeof(imobil)*(n+n/2));
    nou.capacitate=n+n/2;
    nou.nr_imobile=n;
    return nou;
}

Lista_imobile_favorite initializare_lista_favorite(Lista_imobile* lista)
{
    Lista_imobile_favorite nou;
    nou.lista=lista->Imobil;
    nou.pozitii=(int*)malloc(sizeof(int)*lista->nr_imobile);
    nou.nr_favorite=0;
    return nou;
}

imobil* copiere_imobile(imobil* de_copiat, int capacitate, int nr_imobile)
{
    imobil* nou=(imobil*)malloc(sizeof(imobil)*capacitate);
    for(int i=0; i<nr_imobile; i++)
    {
        nou[i].titlu=(char*)malloc(sizeof(char)*MAX_C);
        nou[i]=de_copiat[i];
    }
    free(de_copiat);
    return nou;
}

int* sortare_pozitii(int* pozitii, int nr_favorite)
{
    int aux;
    for(int i=0; i<nr_favorite-1; i++)
    {
        for(int j=i+1; j<nr_favorite; j++)
        {
            if(pozitii[i]>pozitii[j])
            {
                aux=pozitii[i];
                pozitii[i]=pozitii[j];
                pozitii[j]=aux;
            }
        }
    }
    return pozitii;
}

int* copiere_pozitii(int* de_copiat, int nr_imobile, int nr_favorite)
{
    int* nou=(int*)malloc(sizeof(imobil)*nr_imobile);
    for(int i=0; i<nr_favorite; i++)
    {
        nou[i]=de_copiat[i];
    }
    free(de_copiat);
    return nou;
}

void realloc_capacity(Lista_imobile* lista)
{
    lista->capacitate+=10;
    lista->Imobil=copiere_imobile(lista->Imobil, lista->capacitate,lista->nr_imobile);
}

void afisare_lista(const Lista_imobile* lista)
{
    imobil* nume_imobil;
    for(int i=0; i<lista->nr_imobile; i++)
    {
        nume_imobil=&lista->Imobil[i];
        system("cls");
        textcolor(112);
        printf("%s",nume_imobil->titlu);
        textcolor(7);
        printf("\n\n");
        textcolor(112);
        printf("Pret:");
        textcolor(7);
        printf(" %d$\n",nume_imobil->pret);
        textcolor(112);
        printf("Tip:");
        textcolor(7);
        printf(" %s\n",nume_imobil->tip==1 ? "apartament":"casa");
        textcolor(112);
        printf("Suprafata:");
        textcolor(7);
        printf(" %d mp\n",nume_imobil->suprafata);
        textcolor(112);
        printf("Confort:");
        textcolor(7);
        printf(" %d\n",nume_imobil->confort);
        textcolor(112);
        printf("Numar anul constructiei:");
        textcolor(7);
        printf(" %d\n",nume_imobil->anul_constructiei);
        textcolor(112);
        printf("Numar camere:");
        textcolor(7);
        printf(" %d\n",nume_imobil->numar_camere);
        textcolor(112);
        printf("Numar bai:");
        textcolor(7);
        printf(" %d\n",nume_imobil->numar_bai);
        textcolor(112);
        printf("Etaj:");
        textcolor(7);
        if(nume_imobil->etaj==0)
            printf(" parter\n");
        else
            printf("%d\n",nume_imobil->etaj);
        textcolor(112);
        printf("Numar balcoane:");
        textcolor(7);
        printf(" %d\n",nume_imobil->numar_balcoane);
        textcolor(112);
        printf("Piscina:");
        textcolor(7);
        printf(" %s\n",nume_imobil->piscina==1?"da":"nu");
        textcolor(112);
        printf("Terasa:");
        textcolor(7);
        printf(" %s\n",nume_imobil->terasa==1?"da":"nu");
        printf("\n");
        system("pause");
    }
}

void adaugare_imobile(Lista_imobile* lista, imobil* de_adaugat, Lista_imobile_favorite* lista_favorite)
{
    if(lista->nr_imobile+1>=lista->capacitate)
    {
        realloc_capacity(lista);
        lista_favorite->pozitii=copiere_pozitii(lista_favorite->pozitii,lista->capacitate,lista_favorite->nr_favorite);
        lista_favorite->lista=lista->Imobil;
    }
    lista->Imobil[lista->nr_imobile]=*de_adaugat;
    lista->nr_imobile++;
}

void adaugare_favorite(Lista_imobile_favorite* lista, int indice)
{
    for(int i=0; i<lista->nr_favorite; i++)
    {
       if(lista->pozitii[i]==indice)
            return ;
    }
    lista->pozitii[lista->nr_favorite]=indice;
    lista->nr_favorite++;
    lista->pozitii=sortare_pozitii(lista->pozitii,lista->nr_favorite);
}

void initializare_imobile()
{
    FILE* f=fopen("src/input/imobiliare.txt","r");
    char aux;
    int n;
    fscanf(f,"%d\n",&n);
    lista_imobile=initializare_lista(n);
    imobil* nou;
    for(int i=0; i<n; i++)
    {
        nou=(imobil*)malloc(sizeof(imobil));
        nou->titlu=(char*)malloc(sizeof(char)*MAX_C);
        fgets(nou->titlu,MAX_C,f);
        fscanf(f,"%d",&nou->pret);
        fscanf(f,"%d",&nou->tip);
        fscanf(f,"%d",&nou->suprafata);
        fscanf(f,"%d",&nou->confort);
        fscanf(f,"%d",&nou->anul_constructiei);
        fscanf(f,"%d",&nou->numar_camere);
        fscanf(f,"%d",&nou->numar_bai);
        fscanf(f,"%d",&nou->etaj);
        fscanf(f,"%d",&nou->numar_balcoane);
        fscanf(f,"%d",&nou->piscina);
        fscanf(f,"%d\n",&nou->terasa);
        lista_imobile.Imobil[i]=*nou;
    }
    lista_favorite=initializare_lista_favorite(&lista_imobile);
}

void rescriere_fisier(const Lista_imobile* lista)
{
    FILE* f=fopen("src/input/imobiliare.txt","w");
    fprintf(f,"%d\n",lista->nr_imobile);
    for(int i=0; i<lista->nr_imobile; i++)
    {
        fprintf(f,"%s",lista->Imobil[i].titlu);
        fprintf(f,"%d ",lista->Imobil[i].pret);
        fprintf(f,"%d ",lista->Imobil[i].tip);
        fprintf(f,"%d ",lista->Imobil[i].suprafata);
        fprintf(f,"%d ",lista->Imobil[i].confort);
        fprintf(f,"%d ",lista->Imobil[i].anul_constructiei);
        fprintf(f,"%d ",lista->Imobil[i].numar_camere);
        fprintf(f,"%d ",lista->Imobil[i].numar_bai);
        fprintf(f,"%d ",lista->Imobil[i].etaj);
        fprintf(f,"%d ",lista->Imobil[i].numar_balcoane);
        fprintf(f,"%d ",lista->Imobil[i].piscina);
        fprintf(f,"%d\n",lista->Imobil[i].terasa);
    }
    fclose(f);
    initializare_imobile();
}

int acelasi_titlu(const Lista_imobile* imobil1, const imobil* imobil2)
{
    for(int i=0; i<imobil1->nr_imobile; i++)
    {
        if(!strcmp(imobil1->Imobil[i].titlu,imobil2->titlu))
            return 1;
    }
    return 0;
}

short afisare_imobil(imobil* nume_imobil, int cu_favorite) // 1=cu favorite, 0=fara favorite
{
    int optiune=0;
    char** optiuni=(char**)malloc(sizeof(char*)*4);
    for(int i=0; i<4; i++)
    {
        optiuni[i]=(char*)malloc(sizeof(char)*MAX_C);
    }
    optiuni[0]="Cumpara";
    if(cu_favorite)
    {
        optiuni[1]="Adauga la favorite";
        optiuni[2]="Inapoi";
        optiuni[3]="Iesire";
    }
    else
    {
        optiuni[1]="Inapoi";
        optiuni[2]="Iesire";
    }

    while(1)
    {
        system("cls");
        textcolor(112);
        printf("%s",nume_imobil->titlu);
        textcolor(7);
        printf("\n\n");
        textcolor(112);
        printf("Pret:");
        textcolor(7);
        printf(" %d$\n",nume_imobil->pret);
        textcolor(112);
        printf("Tip:");
        textcolor(7);
        printf(" %s\n",nume_imobil->tip==1 ? "apartament":"casa");
        textcolor(112);
        printf("Suprafata:");
        textcolor(7);
        printf(" %d mp\n",nume_imobil->suprafata);
        textcolor(112);
        printf("Confort:");
        textcolor(7);
        printf(" %d\n",nume_imobil->confort);
        textcolor(112);
        printf("Numar anul constructiei:");
        textcolor(7);
        printf(" %d\n",nume_imobil->anul_constructiei);
        textcolor(112);
        printf("Numar camere:");
        textcolor(7);
        printf(" %d\n",nume_imobil->numar_camere);
        textcolor(112);
        printf("Numar bai:");
        textcolor(7);
        printf(" %d\n",nume_imobil->numar_bai);
        textcolor(112);
        printf("Etaj:");
        textcolor(7);
        if(nume_imobil->etaj==0)
            printf(" parter\n");
        else
            printf("%d\n",nume_imobil->etaj);
        textcolor(112);
        printf("Numar balcoane:");
        textcolor(7);
        printf(" %d\n",nume_imobil->numar_balcoane);
        textcolor(112);
        printf("Piscina:");
        textcolor(7);
        printf(" %s\n",nume_imobil->piscina==1?"da":"nu");
        textcolor(112);
        printf("Terasa:");
        textcolor(7);
        printf(" %s\n",nume_imobil->terasa==1?"da":"nu");
        printf("\n");
        for(int i=0; i<3+cu_favorite; i++)
        {
            if(optiune==i)
            {
                printf(">>%s\n",optiuni[i]);
            }
            else
            {
                printf("%s\n",optiuni[i]);
            }
        }
        while(1)
        {
            if(GetAsyncKeyState(VK_UP))
            {
                while(GetAsyncKeyState(VK_UP)) {}
                if(optiune>0)
                    optiune--;
                break;
            }
            if(GetAsyncKeyState(VK_DOWN))
            {
                while(GetAsyncKeyState(VK_DOWN)) {}
                if(optiune<2+cu_favorite)
                    optiune++;
                break;
            }
            if(GetAsyncKeyState(VK_RETURN))
            {
                while(GetAsyncKeyState(VK_RETURN)) {}
                return optiune;
            }
        }
    }
}

void textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        color + (__BACKGROUND << 4));
}

void resetBuffer()
{
    while (_kbhit())
        _getch();
}

short meniu(char** optiuni, int inceput, int n, char c) // c este acolo pentru a nu pune de 2 ore newline cand afisam date din fisier
{
    short MAX=n-1, MIN=inceput, pozitie=MIN, gasit=1;
    while (GetAsyncKeyState(VK_RETURN)) {}
    while (gasit)
    {
        system("cls");
        printf("%s\n\n",optiuni[n]);
        for (short i = inceput;i < n; i++)
        {
            if(optiuni[i]==NULL)
            {
                if(pozitie==i)
                    pozitie++;
                continue;
            }
            else if (pozitie == i)
            {
                textcolor(112);
                if(c=='\0')
                    printf(">>");
                printf("%s%c",optiuni[i],c);
                textcolor(7);
            }
            else
                printf("%s%c",optiuni[i],c);
        }
        printf("\e[?25l"); // ascunde cursorul
        while (1==1)
        {
            if (GetAsyncKeyState(VK_UP))
            {
                pozitie--;
                if (pozitie < MIN)
                {
                    pozitie = MIN;
                }
                while(GetAsyncKeyState(VK_UP)) {}
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN))
            {
                pozitie++;
                if (pozitie > MAX)
                {
                    pozitie=n-1;
                }
                while(GetAsyncKeyState(VK_DOWN)) {}
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                gasit=0;
                break;
            }
            else if (GetAsyncKeyState('F') && c=='\0' && pozitie<n-2)
            {
                FILE* f=fopen("lista_favorite.txt","a");
                fprintf(f,"%s",optiuni[pozitie]);
                fclose(f);
            }
            else if (GetAsyncKeyState(VK_ESCAPE))
            {
                gasit=0;
                pozitie=n/2;
                break;
            }
            Sleep(250);
        }
    }
    system("cls");
    return(pozitie);
}

void cumparare_imobil(Lista_imobile* lista, short pozitie)
{
    if(lista->nr_imobile>0)
    {
        for(int i=pozitie; i<lista->nr_imobile-1; i++)
        {
            lista->Imobil[i]=lista->Imobil[i+1];
        }
        lista->nr_imobile--;
    }
    //rescriere_fisier1();
    //initializare_imobile();
}

void eliminare_favorite(Lista_imobile_favorite* lista, int pozitie)
{
    system("cls");
    for(int i=pozitie; i<lista->nr_favorite-1; i++)
    {
        lista->pozitii[i]=lista->pozitii[i+1];
        lista->pozitii[i]--; // este aici pentru ca atunci cand stergi un element, toti indicii
        //de la favorite trebuie mutati cu unul la stanga
    }
    lista->nr_favorite--;
}

void verificare_favorite(Lista_imobile_favorite* lista, int optiune)
{
    for(int i=0; i<lista->nr_favorite; i++)
    {
        if(lista->pozitii[i]==optiune)
        {
            eliminare_favorite(lista,i);
            break;
        }
    }
}

short meniu_cumparare(Lista_imobile* lista_imobile, Lista_imobile_favorite* lista_favorite)
{
    char** optiuni=(char**)malloc(sizeof(char*)*(lista_imobile->nr_imobile+3));
    int nr_imobile=lista_imobile->nr_imobile;
    short optiune,optiune_imobil;
    back:
    for(int i=0; i<lista_imobile->nr_imobile; i++)
    {
        optiuni[i]=lista_imobile->Imobil[i].titlu;
    }
    optiuni[lista_imobile->nr_imobile+2]="Lista cu imobiliare";
    optiuni[lista_imobile->nr_imobile]="Inapoi\n";
    optiuni[lista_imobile->nr_imobile+1]="Iesire";
    optiune=meniu(optiuni,0,lista_imobile->nr_imobile+2,'\0');
    while(optiune!=lista_imobile->nr_imobile && optiune!=lista_imobile->nr_imobile+1)
    {
        optiune_imobil=afisare_imobil(&lista_imobile->Imobil[optiune], 1);
        if(optiune_imobil==2)
            optiune=meniu(optiuni,0,lista_imobile->nr_imobile+2,'\0');
        else if(optiune_imobil==0)
        {
            system("cls");
            verificare_favorite(lista_favorite, optiune);
            cumparare_imobil(lista_imobile, optiune);
            goto back;
        }
        else if(optiune_imobil==1)
        {
            adaugare_favorite(lista_favorite,optiune);
            goto back;
        }
        else if(optiune_imobil==3)
            optiune=lista_imobile->nr_imobile+1;  
    }
    free(optiuni);
    if(optiune==lista_imobile->nr_imobile)
        return 1;
    return 0;
}

short meniu_favorite(Lista_imobile* lista, Lista_imobile_favorite* lista_favorite)
{
    char** optiuni=(char**)malloc(sizeof(char*)*(lista_favorite->nr_favorite+3));
    short optiune,optiune_imobil;
    back:
    for(int i=0; i<lista_favorite->nr_favorite; i++)
    {
        optiuni[i]=lista_favorite->lista[lista_favorite->pozitii[i]].titlu;
    }
    optiuni[lista_favorite->nr_favorite+2]="Lista cu favorite";
    optiuni[lista_favorite->nr_favorite]="Inapoi\n";
    optiuni[lista_favorite->nr_favorite+1]="Iesire";
    optiune=meniu(optiuni,0,lista_favorite->nr_favorite+2,'\0');
    while(optiune!=lista_favorite->nr_favorite && optiune!=lista_favorite->nr_favorite+1)
    {
        optiune_imobil=afisare_imobil(&lista_favorite->lista[lista_favorite->pozitii[optiune]], 0);
        if(optiune_imobil==1)
            optiune=meniu(optiuni,0,lista_favorite->nr_favorite+2,'\0');
        else if(optiune_imobil==0)
        {
            system("cls");
            cumparare_imobil(lista,lista_favorite->pozitii[optiune]);
            eliminare_favorite(lista_favorite, optiune);
            goto back;
        }
        else if(optiune_imobil==2)
            optiune=lista_favorite->nr_favorite+1;  
    }
    free(optiuni);
    if(optiune==lista_favorite->nr_favorite)
        return 1;
    return 0;
}

void meniu_vanzare()
{
    while(GetAsyncKeyState(VK_RETURN)) {}
    static int i=0;
    if(i>=1)
        getchar();
    resetBuffer();
    fflush(stdin);
    imobil* nou_imobil=(imobil*)malloc(sizeof(imobil));
    nou_imobil->titlu=(char*)malloc(sizeof(char)*MAX_C);
    system("cls");
    resetBuffer();
    printf("\e[?25h"); // afiseaza inapoi cursorul
    textcolor(112);
    printf("Meniu vanzare");
    textcolor(7);
    printf("\n\nTitlu: ");
    fgets(nou_imobil->titlu,MAX_C,stdin);
    if(acelasi_titlu(&lista_imobile,nou_imobil))
    {
        printf("Titlurile anunturilor trebuie sa fie diferite!\n");
        Sleep(2000);
        free(nou_imobil->titlu);
        free(nou_imobil);
        i++;
        return ;
    }
    printf("Pret: ");
    scanf("%d",&nou_imobil->pret);
    printf("Tip(1:apartament,0:casa): ");
    scanf("%d",&nou_imobil->tip);
    printf("Suprafata: ");
    scanf("%d",&nou_imobil->suprafata);
    printf("Confort: ");
    scanf("%d",&nou_imobil->confort);
    printf("Anul constructiei: ");
    scanf("%d",&nou_imobil->anul_constructiei);
    printf("Numar camere: ");
    scanf("%d",&nou_imobil->numar_camere);
    printf("Numar bai: ");
    scanf("%d",&nou_imobil->numar_bai);
    printf("Etaj/e: ");
    scanf("%d",&nou_imobil->etaj);
    printf("Numar balcoane: ");
    scanf("%d",&nou_imobil->numar_balcoane);
    printf("Piscina(1:da,0:nu): ");
    scanf("%d",&nou_imobil->piscina);
    printf("Terasa(1:da,0:nu): ");
    scanf("%d",&nou_imobil->terasa);
    system("cls");
    adaugare_imobile(&lista_imobile,nou_imobil,&lista_favorite);
    //rescriere_fisier(nou_imobil);
    i++;
}

#endif