#include "preprocess.h"
using namespace std;
void operation(){
    int choise,Taille;
     cout<<"veuiller entrer la taille du tableau"<<endl;
    cin>>Taille;
    int tab[Taille];
    cout << "choisir une opération a éffectuer"<<endl;
    cout<<"1-Selection Sort\n2-Bulbe Sort\n3-Insertion Sort\n4-Search Value\n5-dichotomic Search Value"<<endl;
    cin>>choise;
    switch(choise){
        case 1:
            cout <<"vous avez choisi le trie par selection"<<endl;
            insertTab(tab,Taille);
            cout<<"avant le trie par selection"<<endl;
            displayTab(tab,Taille);
            selectionSort(tab,Taille);
            cout<<"\napres le trie par selection"<<endl;
            displayTab(tab,Taille);
            cout<<endl<<endl;
            //on effectue les opérationsur le tableau

        break;
        case 2:
            cout <<"vous avez choisi le trie par insertion"<<endl;
            insertTab(tab,Taille);
            cout<<"avant le trie par bulle"<<endl;
            displayTab(tab,Taille);
            bulbeSort(tab,Taille);
            cout<<"\napres le trie par bulle"<<endl;
            displayTab(tab,Taille);
            cout<<endl<<endl;
            //on effectue les opérationsur le tableau

        break;
         case 3:
            cout <<"vous avez choisi le trie par insertion"<<endl;
            insertTab(tab,Taille);
            cout<<"avant le trie par insertion"<<endl;
            displayTab(tab,Taille);
            insertionSort(tab,Taille);
            cout<<"\napres le trie par insertion"<<endl;
            displayTab(tab,Taille);
            cout<<endl<<endl;
            //on effectue les opérationsur le tableau

        break;
         case 4:
            cout <<"vous avez choisi la recherche d'un element"<<endl;
            insertTab(tab,Taille);
            displayTab(tab,Taille);
            searchVal(tab,Taille);
            cout<<endl<<endl;
            //on effectue les opérationsur le tableau

        break;
        default:
            cout<<"Choix indisponible"<<endl;
        break;
    }
}

int searchMin(int tab[],int taille,int ind){
    int posmin=ind;
    for(int i=posmin+1;i<taille;i++){
        if(tab[posmin]>tab[i]){
            posmin=i;
        }
    }
    return posmin;
}

int searchMax(int tab[],int taille,int ind){
    int posmax=ind;
    for(int i=posmax+1;i<taille;i++){
        if(tab[posmax]<tab[i]){
            posmax=i;
        }
    }
    return posmax;
}

void swapElt(int tab[] ,int i,int j){
    int tmp;
    tmp=tab[i];
    tab[i]=tab[j];
    tab[j]=tmp;
}
void insertTab(int tab[],int taille){
    for(int i=0;i<taille;i++){
        tab[i]=rand()%100;
    }
}
void displayTab(int tab[],int taille){
    for(int i=0;i<taille;i++){
       cout<< tab[i]<<" ";
    }
}

void selectionSort(int tab[],int taille){
    int mini;
    for(int i=0;i<taille;i++){
        mini=searchMin(tab,taille,i);//on recherche le min entre la pos i et taille
        swapElt(tab,mini,i);//on place le plus petit elt à sa position exacte
    }
}

void bulbeSort(int tab[],int taille){
    int N=taille;
    bool permut;
    do{
        permut=false;
        for(int i=0;i<taille-1;i++){
            if(tab[i]>tab[i+1]){
                swapElt(tab,i,i+1);
                permut=true;
            }
        }
        N--;
    }
    while(permut!=false || N!=1);
}


void insertionSort(int tab[],int taille){
    for(int j=1;j<taille;j++){
        int k=j,val=tab[j];//on recupere la valeur à inserer
        for(int i=j-1;i>=0;i--){
            if(val<tab[i]){//compare les val inferieur avec la valeur a inserer
                tab[i+1]=tab[i];//on declale a droite si la val est inférieur à l'elt courant
                 k--;//position provisoire de la valeur à inserer
            }

        }
        tab[k]=val;//on place la valeur a inserer a sa position exacte
    }
}

void searchVal(int tab[],int taille){
    int val,i=0;
    bool trouver=false;
    cout<<"\nentrer la valeur à chercher dans le tableau"<<endl;
    cin>>val;
    if( taille==0){
        cout<<val<<" ne peut pas se trouver dans le tableau vue qu'il est vide "<<endl;
    }
    else{
        while(i<taille && trouver!=true){
            if(tab[i]==val){
                trouver=true;
            }else{
                i++;
            }

        }
        if(trouver){
            cout<<val<< " est bien dans le tableau à la position"<<i<<endl;
        }else{
            cout<<val<< " n'est pas dans le tableau"<<endl;
        }
    }
}


bool isSorted(int tab[],int taille){
    int i=0;
    bool statut=false;
    while(statut!=true && i<taille)
        if(tab[i]>tab[i+1]){
            statut=true;
        }else{
            i++;
        }
     return statut;
    }
void dichotomicSearchVal(int tab[],int taille){
    int val,imin,imax;
    bool statut;
    statut=isSorted(tab,taille);
    if(!statut){
        cout<<"votre tableau n'est pas trier nous allons le trie d'abord"<<endl;
        insertionSort(tab,taille);
    }
    cout<<"\nentrer la valeur à chercher dans le tableau"<<endl;
    cin>>val;
    imax=searchMax(tab,0,taille);
    imin=searchMin(tab,0,taille);
//    dichotomicSearchVal(int tab[],int imin,int imax);
}

