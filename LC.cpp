#include "preprocess.h"
/*****************************liste chainée simple*******************************/
 LC::LC(){

    tete=0;
 };
 void LC::insertHead(){

     int value;
     value= rand()%200;
//        cout<<"entret la valeur a inserer"<<endl;
//        cin>>value;
     //on cree un espace e memoire pouvant contenir une cellule
    Cellule* p=new Cellule;
    //si la tete est vide
    if(tete==0){
        p->val=value;
        tete=p; //tete egale p
        p->suivant=0; // le suivant de p est null;
    }else{
        p->val=value;
        p->suivant=tete;// le suivant de l'acienne tête pointe mtn sur mon nouvel element
        tete=p;//la tete poite mtn sur mon nouvelle element
    }
 }
void LC::insertSw(){
    int value,pos,i(0);
    Cellule *current,*p=new Cellule;
    cout<<"a quel position voulez vous inserer cet element"<<endl;
    cin>>pos;
    cout<<"enter l'element à inserer"<<endl;
    cin>>value;
    current=tete;
    p->val=value;
    if(tete==0){
        cout<<"la liste est vide seul une insertion en tete sera valide"<<endl;
            tete=p; //tete egale p
            p->suivant=0;
            i++; // le suivant de p est null;
    }else{
        current=tete;
        while(current->suivant!=0 && i!=pos){
            current=current->suivant;
            cout<<i<<endl;
            i++;
        }
        cout<<i;
        if(pos!=i){
            cout<<"la liste est trop courte pour inserer a cette poisition"<<endl;
        }else{
            p->suivant=current;
            current->suivant=p;
        }
    }

}

 void LC::insertQueue(){

    int value ;
    Cellule *current=tete,*p;
    p=new Cellule;
    cout<<"\n entrer la valeur a inserer en queue"<<endl;
    cin >> value;
    do{
        current=current->suivant;
    }while(current->suivant!=0);
    p->val=value;
    current->suivant=p;
    p->suivant=0;
 }
 void LC::delHead(){

    Cellule* p=new Cellule;//on cree une nouvelle cellule
    p=tete; //on le fait pointer vers le meme elt que la tete
    tete=p->suivant; //la tete pointe mtn sur le second elt de la liste
    delete p;// on libere la case memoire contenant le premier elt;
    p=0;
 }
 void LC::delQueue(){

    Cellule *p=new Cellule,*current=tete;
    do{
        p=current;
        current=current->suivant;
    }while(current->suivant!=0);
    p->suivant=0;
    delete current;
    current=0;
 }
  void LC::makeLC(int taille){

    for(int i=0;i<taille;i++){
        insertHead();
    }
  }

void LC ::displayLC(){
    Cellule* current=tete;
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

void LC::clearLC(){

    do{
        delHead();
    }while(tete!=0);
}
void LC::searchLC(){

    int val=0,i=0;
    bool found=false;
    Cellule *current=tete;
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
void LC:: operationLC(){
    int Taille;
    cout<<"veuiller entrer la taille du liste"<<endl;
    cin>>Taille;
    makeLC(Taille);//on creer une liste avec une taille min
    cout <<"operation sur les listes chaines"<<endl;
    cout<<"1-inserer un element en tete\n2-inserer un element en queue\n3-supprimer un element en tete\n"<<
    "4-supprimer un element en queue\n5-vider la liste\n6-rechercher un element dans la liste chaine\n7-insertion a une position quelconque"<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    switch(choix){
        case 1:
            char decision;
            cout<<"vous avez choisi l'insertion en tete"<<endl<<endl;
            cout<<"avant l'insertion en tete"<<endl;
            displayLC();
//            do{
               insertHead();
//               cout <<"voulez vous encore inserer un nombre?? oui(O) ou non(N)"<<endl;
//               cin>>decision;
//            }while(decision!='N');

            cout<<"\napres l'insertion en tete"<<endl;
            displayLC();
        break;
        case 2:
            cout<<"vous avez choisi l'insertion en queue"<<endl<<endl;
            cout<<"avant l'insertion en queue"<<endl;
            displayLC();
            insertQueue();
            cout<<"\napres l'insertion en queue"<<endl;
            displayLC();
        break;
        case 3:
            cout<<"vous avez choisi la suppression en tete"<<endl<<endl;
            cout<<"avant la suppression en tete"<<endl;
            displayLC();
            delHead();
            cout<<"\napres l'insertion en tete"<<endl;
            displayLC();
        break;
        case 4:
            cout<<"vous avez choisi la suppression en queue"<<endl<<endl;
            cout<<"avant la suppression en queue"<<endl;
            displayLC();
            delQueue();
            cout<<"apres l'insertion en queue"<<endl;
            displayLC();
        break;
        case 5:
            cout<<"vous avez choisi de vider la liste"<<endl<<endl;
            cout<<"avant que la liste ne soit vide"<<endl;
            displayLC();
            clearLC();
            cout<<"apres que la liste soit vider"<<endl;
            displayLC();
        break;
        case 6:
            cout<<"vous avez choisi de chercher une val dans la liste"<<endl<<endl;
            displayLC();
            cout<<endl;
            searchLC();
        break;
        case 7:
            cout<<"vous avez choisi d'inserer un element a une position quelconque"<<endl<<endl;
            cout<<"avant insertion"<<endl;
            displayLC();
            insertSw();
            cout<<"apres insertion"<<endl;
            displayLC();
        break;

        default:
            cout <<"choix indisponible"<<endl;
        break;
    }
}
