
#include "preprocess.h"
DblLC::DblLC(){
     tete=0;
}

void DblLC::insertHeadDblLC(){
    Cel* p=new Cel;
    int value=rand()%200;
//    cout<<"entrer la valeur a inserer"<<endl;
//    cin >> value;
    if(tete==0){
        p->val=value;
        p->previous=0;
        p->suivant=0;
        tete=p;
    }else{
        p->val=value;//on insere la valeur dan son champs
        p->previous=tete; // vue que l'elt est inserer en tête son precedent pointer vers rien
        tete->previous=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=tete;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        tete=p;//la tete pointe mtn sur mon element inserer;
    }
}

 void DblLC::insertQueueDblLC(){
    int value=0;
    Cel* p=new Cel,*current=tete;
    cout<<"entrer la valeur a inserer en queue";
    cin>>value;
    if(tete==0){
        p->val=value;
        p->previous=0;
        p->suivant=0;
        tete=p;
    }else{
        do{
            current=current->suivant;
        }while(current->suivant!=0);
        p->val=value;
        p->suivant=0;// le nouvelle elt pointe vers rien
        current->suivant=p;// le suivant de mon dernier element poite vers le nouvel mon element
        p->previous=current;// le precedent de mon nouvelle element pointe vers le dernier element de la list
    }
 }
 void DblLC::delHeadDblLC(){
    Cel* p=tete;
    if(tete==0){
        cout <<"la liste est vide"<<endl;
    }else{
        tete=p->suivant;
        delete p;
        p=0;
    }
 }

 void DblLC::delQueueDblLC(){
    Cel *current=tete;
    if(tete==0){
        cout<<"la liste est vide"<<endl;
    }else{
        do{
            current=current->suivant;
        }while(current->suivant!=0);
        current->previous->suivant=0;
        delete current;
        current=0;
     }
 }
void DblLC::makeDblLC(int taille){
    for(int i=0;i<taille;i++){
        insertHeadDblLC();
    }
}

void DblLC::clearDblLC(){
    do{
        delHeadDblLC();
    }while(tete!=0);
}

void DblLC::searchDblLC(){
      int val=0,i=0;
    bool found=false;
    Cel *current=tete;
    cout<<"entrer la valeur a chercher dans la liste"<<endl;
    cin>>val;

    do{
        if(current->val==val){
            found=true;
        }else{
            current=current->suivant;
        }
        i++;
    }while(found!=true && current!=0);
    if(found){
        cout <<"l'element est dans la liste a la position "<<i-1<<endl;
    }else{
        cout <<"l'element n'est pas dans la liste"<<endl;
    }
}
void DblLC::displayDblLC(){
     Cel* current=tete;
    if(tete==0){
        cout<<"votre liste est vide en cet instant"<<endl;
    }else{
        do{
            cout<<current->val<<" ";
            current=current->suivant;//l'element courent  devient son suivant
        }while(current!=0);//si le courrent pointe vers 0 alors on sort de la boucle
       cout<<endl;
    }
}
void DblLC:: operationDblLC(){
    int Taille;
    cout<<"veuiller entrer la taille du liste"<<endl;
    cin>>Taille;
    makeDblLC(Taille);//on creer une liste avec une taille min
    cout <<"operation sur les listes doublement chaines"<<endl;
    cout<<"1-inserer un element en tete\n2-inserer un element en queue\n3-supprimer un element en tete\n"<<
    "4-supprimer un element en queue\n5-vider la liste\n6-rechercher un element dans la liste chaine"<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    switch(choix){
        case 1:
            cout<<"vous avez choisi l'insertion en tete"<<endl<<endl;
            cout<<"avant l'insertion en tete"<<endl;
            displayDblLC();
            insertHeadDblLC();
            cout<<"\napres l'insertion en tete"<<endl;
            displayDblLC();
        break;
        case 2:
            cout<<"vous avez choisi l'insertion en queue"<<endl<<endl;
            cout<<"avant l'insertion en queue"<<endl;
            displayDblLC();
            insertQueueDblLC();
            cout<<"\napres l'insertion en queue"<<endl;
            displayDblLC();
        break;
        case 3:
            cout<<"vous avez choisi la suppression en tete"<<endl<<endl;
            cout<<"avant la suppression en tete"<<endl;
            displayDblLC();
            delHeadDblLC();
            cout<<"\napres l'insertion en tete"<<endl;
            displayDblLC();
        break;
        case 4:
            cout<<"vous avez choisi la suppression en queue"<<endl<<endl;
            cout<<"avant la suppression en queue"<<endl;
            displayDblLC();
            delQueueDblLC();
            cout<<"apres l'insertion en queue"<<endl;
            displayDblLC();
        break;
        case 5:
            cout<<"vous avez choisi de vider la liste"<<endl<<endl;
            cout<<"avant que la liste ne soit vide"<<endl;
            displayDblLC();
            clearDblLC();
            cout<<"apres que la liste soit vider"<<endl;
            displayDblLC();
        break;
        case 6:
            cout<<"vous avez choisi de chercher une val dans la liste"<<endl<<endl;
            displayDblLC();
            cout<<endl;
            searchDblLC();
        break;
        default:
            cout <<"choix indisponible"<<endl;
        break;
    }
}
