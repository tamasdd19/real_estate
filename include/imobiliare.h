#ifndef IMOBILIARE_H_INCLUDED
#define IMOBILIARE_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

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
        lista_imobile[i].titlu=(char*)malloc(sizeof(char)*30);
        fgets(lista_imobile[i].titlu,30,f);
        fscanf(f,"%d",&lista_imobile[i].pret);
        fscanf(f,"%d",&lista_imobile[i].tip);
        fscanf(f,"%d",&lista_imobile[i].suprafata);
        fscanf(f,"%d",&lista_imobile[i].confort);
        fscanf(f,"%d",&lista_imobile[i].anul_constructiei);
        fscanf(f,"%d",&lista_imobile[i].numar_camere);
        fscanf(f,"%d",&lista_imobile[i].numar_bai);
        fscanf(f,"%d",&lista_imobile[i].etaj);
        fscanf(f,"%d",&lista_imobile[i].numar_balcoane);
        fscanf(f,"%d",&lista_imobile[i].piscina);
        fscanf(f,"%d\n",&lista_imobile[i].terasa);
    }

}

void rescriere_fisier(imobil* nou_imobil)
{
    FILE* f=fopen("src/input/imobiliare.txt","w");
    fprintf(f,"%d\n",nr_imobile);
    for(int i=0; i<nr_imobile-1; i++)
    {
        fprintf(f,"%s",lista_imobile[i].titlu);
        fprintf(f,"%d ",lista_imobile[i].pret);
        fprintf(f,"%d ",lista_imobile[i].tip);
        fprintf(f,"%d ",lista_imobile[i].suprafata);
        fprintf(f,"%d ",lista_imobile[i].confort);
        fprintf(f,"%d ",lista_imobile[i].anul_constructiei);
        fprintf(f,"%d ",lista_imobile[i].numar_camere);
        fprintf(f,"%d ",lista_imobile[i].numar_bai);
        fprintf(f,"%d ",lista_imobile[i].etaj);
        fprintf(f,"%d ",lista_imobile[i].numar_balcoane);
        fprintf(f,"%d ",lista_imobile[i].piscina);
        fprintf(f,"%d\n",lista_imobile[i].terasa);
    }
        fprintf(f,"%s",nou_imobil->titlu);
        fprintf(f,"%d ",nou_imobil->pret);
        fprintf(f,"%d ",nou_imobil->tip);
        fprintf(f,"%d ",nou_imobil->suprafata);
        fprintf(f,"%d ",nou_imobil->confort);
        fprintf(f,"%d ",nou_imobil->anul_constructiei);
        fprintf(f,"%d ",nou_imobil->numar_camere);
        fprintf(f,"%d ",nou_imobil->numar_bai);
        fprintf(f,"%d ",nou_imobil->etaj);
        fprintf(f,"%d ",nou_imobil->numar_balcoane);
        fprintf(f,"%d ",nou_imobil->piscina);
        fprintf(f,"%d",nou_imobil->terasa);
    fclose(f);
    initializare_imobile();
}

void rescriere_fisier1()
{
    FILE* f=fopen("src/input/imobiliare.txt","w");
    fprintf(f,"%d\n",nr_imobile);
    for(int i=0; i<nr_imobile; i++)
    {
        fprintf(f,"%s",lista_imobile[i].titlu);
        fprintf(f,"%d ",lista_imobile[i].pret);
        fprintf(f,"%d ",lista_imobile[i].tip);
        fprintf(f,"%d ",lista_imobile[i].suprafata);
        fprintf(f,"%d ",lista_imobile[i].confort);
        fprintf(f,"%d ",lista_imobile[i].anul_constructiei);
        fprintf(f,"%d ",lista_imobile[i].numar_camere);
        fprintf(f,"%d ",lista_imobile[i].numar_bai);
        fprintf(f,"%d ",lista_imobile[i].etaj);
        fprintf(f,"%d ",lista_imobile[i].numar_balcoane);
        fprintf(f,"%d ",lista_imobile[i].piscina);
        fprintf(f,"%d\n",lista_imobile[i].terasa);
    }
    fclose(f);
    initializare_imobile();
}

short afisare_imobil(imobil* nume_imobil)
{
    int optiune=0;
    char** optiuni=(char**)malloc(sizeof(char*)*4);
    for(int i=0; i<4; i++)
    {
        optiuni[i]=(char*)malloc(sizeof(char)*30);
    }
    optiuni[0]="Cumpara";
    optiuni[1]="Adauga la favorite";
    optiuni[2]="Inapoi";
    optiuni[3]="Iesire";

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
        for(int i=0; i<4; i++)
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
                if(optiune<3)
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

void copiere_imobil(imobil* imobil1, imobil* imobil2)
{
        imobil1->titlu=imobil2->titlu;
        imobil1->pret=imobil2->pret;
        imobil1->tip=imobil2->tip;
        imobil1->suprafata=imobil2->suprafata;
        imobil1->confort=imobil2->confort;
        imobil1->anul_constructiei=imobil2->anul_constructiei;
        imobil1->numar_camere=imobil2->numar_camere;
        imobil1->numar_bai=imobil2->numar_bai;
        imobil1->etaj=imobil2->etaj;
        imobil1->numar_balcoane=imobil2->numar_balcoane;
        imobil1->piscina=imobil2->piscina;
        imobil1->terasa=imobil2->terasa;
}

void cumparare_imobil(imobil* imobil_cumparat, short pozitie)
{
   // system("cls");
    if(nr_imobile>0)
    {
        for(int i=pozitie; i<nr_imobile-1; i++)
        {
            //printf("%s\t%s\n",imobil_cumparat[i].titlu,imobil_cumparat[i+1].titlu);
            copiere_imobil(&imobil_cumparat[i],&imobil_cumparat[i+1]);
        }
        nr_imobile--;
    }
    rescriere_fisier1();
    initializare_imobile();
}

short meniu_cumparare()
{
    char** optiuni=(char**)malloc(sizeof(char*)*(nr_imobile+3));
    short optiune,optiune_imobil;
    back:
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
        optiune_imobil=afisare_imobil(&lista_imobile[optiune]);
        if(optiune_imobil==2)
            optiune=meniu(optiuni,0,nr_imobile+2,'\0');
        else if(optiune_imobil==0)
        {
            cumparare_imobil(&lista_imobile[optiune],optiune);
            goto back;
        }
        else if(optiune_imobil==3)
            optiune=nr_imobile+1;  
    }
    if(optiune==nr_imobile)
        return 1;
    return 0;
}

void meniu_vanzare()
{
    while(GetAsyncKeyState(VK_RETURN)) {}
    resetBuffer();
    fflush(stdin);
    nr_imobile++;
    imobil* nou_imobil=(imobil*)malloc(sizeof(imobil));
    nou_imobil->titlu=(char*)malloc(sizeof(char)*30);
    system("cls");
    resetBuffer();
    printf("\e[?25h"); // afiseaza inapoi cursorul
    textcolor(112);
    printf("Meniu vanzare");
    textcolor(7);
    printf("\n\nTitlu: ");
    fgets(nou_imobil->titlu,30,stdin);
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
    rescriere_fisier(nou_imobil);
}



#endif