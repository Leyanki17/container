#include "preprocess.h"
void display(){
    char dec='N';
    string structure;
    cout << "bienvenue sur test StructData"<<endl;
    do{
        cout<<"choisir la structure sur laquelle vous voulez travailler"<<endl;
        cout<<"1-tableau\n2-liste chainée\n3-liste doublement chainée\n4-liste chaine circulaire\n5-pile\n6-file"<<endl;
        structChoise();//structure est le noms de la structure a utiliser
//        declarateStruct(structure);

        cout<<"voulez vous choisir une autre structure oui(O) ou non (N)"<<endl;
        cin>>dec;
        dec=toupper(dec);//mettre le caractère en majuscule
    }
    while(dec!='N');

}

void structChoise(){
    int choise=0;
    char dec='N';
    cin>> choise;
    switch(choise){
        case 1:
            cout<<"vous avez choisi le tableau"<<endl;
            do{
                 operation();
                cout<<"voulez vous choisir une autre operation?? oui(0) ou non(N)"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');

        break;
        case 2:
            cout<<"vous avez choisi la liste simplement chaine"<<endl;
            do{
                LC liste;
                liste.operationLC();
                cout<<"voulez vous choisir une autre operation?? oui(0) ou non(N)"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');

        break;
         case 3:
            cout<<"vous avez choisi la liste doublement chaine"<<endl;
            do{
                DblLC liste;
//                liste.displayDblLC();
                liste.operationDblLC();
                cout<<"voulez vous choisir une autre operation?? oui(0) ou non(N)"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');

        break;
         case 4:
            cout<<"vous avez choisi la liste chainer circulaire"<<endl;
            do{
                CircleLC liste;
//                liste.displayDblLC();
                liste.operationCircleLC();
                cout<<"voulez vous choisir une autre operation?? oui(0) ou non(N)"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        default:
            cout<<"choix indisponible"<<endl;
        break;
    }

}



