//
// Created by alice flamigni on 04/03/26.
//

#ifndef PROVA_PROGETTO_MENU_H
#define PROVA_PROGETTO_MENU_H


struct NodoOpzione {
    char testo[20];
    int idOpzione;
    NodoOpzione* su;
    NodoOpzione* giu;
};

typedef NodoOpzione* pMenu;
class Menu {
protected:
    pMenu testa;
    pMenu selezionato;
public:
    Menu();
    ~Menu();

    int gestisciMenu();
};

#endif //PROVA_PROGETTO_MENU_H