#include "../include/imobiliare.h"

int main()
{
    char* optiuni[]={"Cumparare","Vanzare","Exit","Imobiliare!"};
    short optiune;
    initializare_imobile();
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
            if(meniu_cumparare())
                goto label_meniu_cumparare;
            break;
        case 1:
            optiuni[0]="Nu ai favorite";
            optiuni[1]="Inapoi";
            optiuni[2]="Iesire";
            optiuni[3]="Meniu favorite";
            optiune = meniu(optiuni,0,3,'\n');
            if(optiune!=2)
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
    resetBuffer();
    while(GetAsyncKeyState(VK_RETURN)) {}
    Sleep(100);
    system("cls");
    return 0;
}

