#include "../include/imobiliare.h"

int main()
{
    char* optiuni[]={"Cumparare","Vanzare","Exit","Imobiliare!"};
    short optiune;
    initializare_imobile();
    printf("da");
    //afisare_imobile();
    label_meniu_principal:
    optiune=meniu(optiuni,0,3,'\n');
    switch(optiune)
    {
    case 0: // meniu cumparare
        label_meniu_cumparare:
        optiuni[0]="Lista cu anunturi";
        optiuni[1]="Lista favorite";
        optiuni[2]="Inapoi";
        optiuni[3]="Iesire";
        optiuni[4]="Meniu cumparare!";
        optiune = meniu(optiuni,0,4,'\n');
        switch(optiune)
        {
        case 0:
            if(meniu_cumparare(&lista_imobile,&lista_favorite))
                goto label_meniu_cumparare;
            break;
        case 1:
            if(meniu_favorite(&lista_imobile,&lista_favorite))
                goto label_meniu_cumparare;
            break;
        case 2:
            optiuni[0]="Cumparare";
            optiuni[1]="Vanzare";
            optiuni[2]="Iesire";
            optiuni[3]="Imobiliare!";
            goto label_meniu_principal;
            break;
        case 3:
            break;
        }
        break;
    case 1: //meniu_vanzare
        meniu_vanzare();
        goto label_meniu_principal;
        break;
    case 2:
        break;
    }
    rescriere_fisier(&lista_imobile);
    resetBuffer();
    while(GetAsyncKeyState(VK_RETURN)) {}
    Sleep(100);
    system("cls");
    return 0;
}

