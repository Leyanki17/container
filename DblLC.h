#ifndef DBLLC_H_INCLUDED
#define DBLLC_H_INCLUDED

///liste doublement chaine
//DblLc liste doublement chainée
    class DblLC{
        public:
            // constructeur par default;
            DblLC();
            // permet de d'inserer un element en tete de la liste chaine
            void insertHeadDblLC();
            void insertQueueDblLC();
            // permet de suppremer un elt en tête
            void delHeadDblLC();//on doit faire en sorte que la liste se vide quand a fini l'operation ceci pour reduire le cout memoire
            void delQueueDblLC();//permettre de supprer un elt en queue
            //permet de faire une list chaine en connaissant la taille;
            void makeDblLC(int taille);
            //permet d'afficher une liste chaine
            void displayDblLC();
            //permet de faire un choi sur l'operation à executer sur la liste chainée
            void operationDblLC();
            //insertion d'un elt en queue
            void clearDblLC();
            //searchLC permet de chercher une valeur dans la liste chaine
            void searchDblLC();
        private:
        Cel* tete;
    };

#endif // DBLLC_H_INCLUDED
