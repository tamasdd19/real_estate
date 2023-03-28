#ifndef IMOBILIARE_H_INCLUDED
#define IMOBILIARE_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

typedef struct imobil
{
	char* titlu;
	short tip; // 1=apartament,0=casa
	short suprafata; // metrii patrati
	short numar_camere;
	short numar_bai;
	short etaj; // pentru apartamente, etajul la care e, pentru case cate etaje are
	short anul_constructiei;
	short numar_balcoane;
	short confort;
    short piscina; // 1==da;0==nu
	short terasa;  // la fel ca mai sus, da sau nu
}imobil;

imobil* lista_imobile;
int nr_imobile;

void initializare_imobile()
{
    FILE* f=fopen("src/input/imobiliare.txt","r");
    char aux;
    fscanf(f,"%d\n",&nr_imobile);
    lista_imobile=(imobil*)malloc(sizeof(imobil)*nr_imobile);
    for(int i=0; i<nr_imobile; i++)
    {
        //fgets(aux,1,f);
       // p=(imobil*)malloc(sizeof(imobil));
        lista_imobile[i].titlu=(char*)malloc(sizeof(char)*30);
        fgets(lista_imobile[i].titlu,30,f);
        fscanf(f,"%d",&lista_imobile[i].tip);
        fscanf(f,"%d",&lista_imobile[i].suprafata);
        fscanf(f,"%d",&lista_imobile[i].numar_camere);
        fscanf(f,"%d",&lista_imobile[i].numar_bai);
        fscanf(f,"%d",&lista_imobile[i].etaj);
        fscanf(f,"%d",&lista_imobile[i].anul_constructiei);
        fscanf(f,"%d",&lista_imobile[i].numar_balcoane);
        fscanf(f,"%d",&lista_imobile[i].confort);
        fscanf(f,"%d",&lista_imobile[i].piscina);
        fscanf(f,"%d",&lista_imobile[i].terasa);
        printf("Tipul este:%d",lista_imobile[i].tip);
        //imobile_append(&lista_imobile,p);
    }

}

short afisare_imobil(imobil* nume_imobil)
{
    textcolor(112);
    printf("%s",nume_imobil->titlu);
    textcolor(7);
    printf("\n\n");
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
    system("pause");
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

short meniu_cumparare()
{
    char** optiuni=(char**)malloc(sizeof(char*)*(nr_imobile+3));
    short optiune;
    for(int i=0; i<nr_imobile; i++)
    {
        optiuni[i]=lista_imobile[i].titlu;
    }
    optiuni[nr_imobile+2]="Lista cu imobiliare";
    optiuni[nr_imobile]="Inapoi\n";
    optiuni[nr_imobile+1]="Iesire";
    optiune=meniu(optiuni,0,nr_imobile+2,'\0');
    while(optiune!=nr_imobile && optiune!=nr_imobile+1)
    {
        afisare_imobil(&lista_imobile[optiune]);
    }
    if(optiune==nr_imobile)
        return 1;
    return 0;
}

void meniu_vanzare()
{
    system("cls");
    resetBuffer();
    printf("\e[?25h"); // afiseaza inapoi cursorul
    FILE* f=fopen("lista_imobiliare1.txt","a");
    char* imobil_vanzare=(char*)malloc(50*sizeof(char));
    printf("Meniul de vanzare\n\n\n");
    printf("Introduceti date despre imobil:");
    fgets(imobil_vanzare,50*sizeof(char),stdin);
    char *p=strchr(imobil_vanzare,'\n');
    *p='\0';
    printf("%s\n",p);
    fprintf(f,"%s","\n");
    fprintf(f,"%s",imobil_vanzare);
    fclose(f);
}

#endif