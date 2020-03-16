#ifndef CIRCLELC_H_INCLUDED
#define CIRCLELC_H_INCLUDED

    class CircleLC{
        public:
        //constructeur par default de la liste chaine vide

         CircleLC();
        //permet de creer u liste chainer circulaire en fonction de la taille
        void makeCircleLC(int taille);
        //permet d'afficher une liste chainee circulaire
        void displayCircleLC();
        //pemet d'inser un element en tete dans une liste chaine
        void insertHeadCircleLC();
        //insertion en queue d'une liste chainée circulaire
        void insertQueueCircleLC();
//        //suppression en queue de l'element dans la liste chaine circulaire
        void delQueueCircleLC();
        //suppression en tete dans la liste chaine circulaire
        void delHeadCircleLC();
        //vider la liste chainée circulaire
        void  clearCircleLC();
        void searchCircleLC();
        void operationCircleLC();
        private:
        Cel* debut;
        Cel* fin;
    };

#endif // CIRCLELC_H_INCLUDED
