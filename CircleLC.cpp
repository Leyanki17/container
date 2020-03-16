#include "preprocess.h"

        CircleLC::CircleLC(){
            debut=0;
            fin=0;
        }
        void CircleLC::makeCircleLC(int taille){
            for(int i=0;i<taille;i++){
                insertHeadCircleLC();
            }
        }
        //permet d'afficher une liste chainee circulaire
        void CircleLC::displayCircleLC(){
            Cel* current=debut;
            if(debut==0 && fin==0){
                cout<< "votre liste est vide"<<endl;
            }else{
                 do{
                    cout<< current->val<<" ";
                    current=current->suivant;
                }while(current!=debut);
            }

        }
        //pemet d'inser un element en tete dans une liste chaine
        void CircleLC::insertHeadCircleLC(){
            Cel* p=new Cel;
            int value;
            cout<<"entrer  la valeur a inserer"<<endl;
            cin>>value;
            if(debut==0){
                p->val=value;
                fin=p;
                p->suivant=p;
                p->previous=p;
                debut=p;
            }else{
                p->val=value;
                p->suivant=debut;//le suivant de mon nouvel element pointe vers l'ancienne tete
                debut->previous=p;//le precedent de l'ancienne tete pointe vers le nouvelle element
                p->previous=fin;//le precedent du nouvel element pointe vers le dernier element de la liste
                fin->suivant=p;//le dernier element de la liste pointe sur le nouvelle element
                debut=p;//la tete pointe sur le nouvel element
            }
        }

        //insertion en queue d'une liste chainée circulaire
        void CircleLC::insertQueueCircleLC(){
            Cel* p=new Cel;
            int value;
            cout<<"entrer la valeur a inserer en queue"<<endl;
            cin>> value;
            if(debut==0){
                p->val=value;
                fin=p;
                p->suivant=p;
                p->previous=p;
                debut=p;
            }else{
                p->val=value;
                p->previous=fin;
                fin->suivant=p;
                p->suivant=debut;
                debut->previous=p;
                fin=p;
            }
        }
        //suppression en queue de l'element dans la liste chaine circulaire
        void  CircleLC::delQueueCircleLC(){
            Cel* current=fin; //on recupere le dernier element de la liste
            current->previous->suivant=debut; //le suivant du precedent du dernier elt pointe vers la tete
            debut->previous=current->previous;//le precedent de la tete pointe sur l'avant dernier elt
            fin=current->previous;//le queue pointe mtn dur le dernier element
            delete current;//je supprime mon ernier element
            current=0;
        }
        //suppression en tete dans la liste chaine circulaire
        void  CircleLC::delHeadCircleLC(){
            Cel* current=debut;
            current->suivant->previous=fin;//le precednt de mon deuxieme element pointe vers la fin de la liste
            fin->suivant=current->suivant;//le suivant de mon dernier elt pointe vers le deuxieme element
            debut=current->suivant;//la tete pointe a present sur le deuxieme element
            delete current;
            current=0;
        }
        //vider la liste chainée circulaire
        void CircleLC::clearCircleLC(){
            Cel* current=debut;
            do{
                delHeadCircleLC();
            }while(debut!=fin);
             debut=0;
            fin=0;
        }
        //permet de chercher un elt dans la liste;
        void CircleLC::searchCircleLC(){
            int val,i=0;
            bool trouve=false;
            Cel* current=debut;
            cout<<"entrer la valeur a chercher"<<endl;
            cin>>val;
            do{
                    i++;
                if(current->val==val){//si la valeur de l'element courant correspond a celle que l'on  cherche
                    trouve=true;
                }else{
                    current=current->suivant;//l'element courant devient son  le suivant d
                }
            }while(current->suivant!=debut && trouve!=true);//on recommence si trouver==vrai ou que le suivant du courant pointe sur le debut
            if(trouve){
                cout<<"\nle nombre "<<val<<" se trouve dans la liste a la position "<<i-1<<endl;
            }else{
                cout<<"le nombre "<<val<<" ne se trouve pas dans le tableau"<<endl;
            }
        }

        void CircleLC:: operationCircleLC(){
        int Taille;
        cout<<"veuiller entrer la taille du liste"<<endl;
        cin>>Taille;
        makeCircleLC(Taille);//on creer une liste avec une taille min
        cout <<"operation sur les listes chaines"<<endl;
        cout<<"1-inserer un element en tete\n2-inserer un element en queue\n3-supprimer un element en tete\n"<<
        "4-supprimer un element en queue\n5-vider la liste\n6-rechercher un element dans la liste chaine"<<endl;
        int choix=0;
        cout<<"choisir une des operation ci-dessus"<<endl;
        cin >> choix;
        switch(choix){
            case 1:
                char decision;
                cout<<"vous avez choisi l'insertion en tete"<<endl<<endl;
                cout<<"avant l'insertion en tete"<<endl;
                displayCircleLC();
    //            do{
                   insertHeadCircleLC();
    //               cout <<"voulez vous encore inserer un nombre?? oui(O) ou non(N)"<<endl;
    //               cin>>decision;
    //            }while(decision!='N');

                cout<<"\napres l'insertion en tete"<<endl;
                displayCircleLC();
            break;
            case 2:
                cout<<"vous avez choisi l'insertion en queue"<<endl<<endl;
                cout<<"avant l'insertion en queue"<<endl;
                displayCircleLC();
                insertQueueCircleLC();
                cout<<"\napres l'insertion en queue"<<endl;
                displayCircleLC();
            break;
            case 3:
                cout<<"vous avez choisi la suppression en tete"<<endl<<endl;
                cout<<"avant la suppression en tete"<<endl;
                displayCircleLC();
                delHeadCircleLC();
                cout<<"\napres l'insertion en tete"<<endl;
                displayCircleLC();
            break;
            case 4:
                cout<<"vous avez choisi la suppression en queue"<<endl<<endl;
                cout<<"avant la suppression en queue"<<endl;
                displayCircleLC();
                delQueueCircleLC();
                cout<<"apres l'insertion en queue"<<endl;
                displayCircleLC();
            break;
            case 5:
                cout<<"vous avez choisi de vider la liste"<<endl<<endl;
                cout<<"avant que la liste ne soit vide"<<endl;
                displayCircleLC();
                clearCircleLC();
                cout<<"apres que la liste soit vider"<<endl;
                displayCircleLC();
            break;
            case 6:
                cout<<"vous avez choisi de chercher une val dans la liste"<<endl<<endl;
                displayCircleLC();
                cout<<endl;
                searchCircleLC();
            break;
            default:
                cout <<"choix indisponible"<<endl;
            break;
    }
}


