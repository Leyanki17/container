#ifndef LC_H_INCLUDED
#define LC_H_INCLUDED
    class LC{
    public:
        // LC est le constructeur par default de la liste chaine
        LC();
        // permet de d'inserer un element en tete de la liste chaine
        void insertHead();
         void insertQueue();
         void insertSw();
        // permet de suppremer un elt en tête
        void delHead();//on doit faire en sorte que la liste se vide quand a fini l'operation ceci pour reduire le cout memoire
        void delQueue();//permettre de supprer un elt en queue
        //permet de faire une list chaine en connaissant la taille;
        void makeLC(int taille);
        //permet d'afficher une liste chaine
        void displayLC();
        //permet de faire un choi sur l'operation à executer sur la liste chainée
        void operationLC();
        //insertion d'un elt en queue
        void clearLC();
        //searchLC permet de chercher une valeur dans la liste chaine
        void searchLC();
    private:
        Cellule* tete;
    };
// case 1:
//            cout<<"vous avez choisi l'insertion en tete"<<endl<<endl;
//            cout<<"avant l'insertion en tete"<<endl;
//            displayLC();
//            insertHead();
//            cout<<"\napres l'insertion en tete"<<endl;
//            displayLC();
//        break;

#endif // LC_H_INCLUDED
