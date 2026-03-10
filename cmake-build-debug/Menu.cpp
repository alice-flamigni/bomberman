//
// Created by alice flamigni on 04/03/26.
//

#include "Menu.h"
#include <ncurses.h>
#include <cstdlib>
#include <cstring>

Menu::Menu() {
    pMenu nodoGioca = new NodoOpzione;
    strcpy (nodoGioca->testo, "Gioca");
    nodoGioca->idOpzione = 0;

    pMenu nodoClassifica = new NodoOpzione;
    strcpy(nodoClassifica->testo, "Classifica");
    nodoClassifica->idOpzione = 1;

    pMenu nodoEsci = new NodoOpzione;
    strcpy(nodoEsci->testo, "Esci");
    nodoEsci->idOpzione = 2;

    nodoGioca->giu = nodoClassifica;
    nodoGioca->su = nodoEsci;

    nodoClassifica->giu = nodoEsci;
    nodoClassifica->su = nodoGioca;

    nodoEsci->giu = nodoGioca;
    nodoEsci->su = nodoClassifica;

    testa = nodoGioca;
    selezionato = nodoGioca;
}

Menu::~Menu() {
    if (testa != NULL) {
        pMenu n1 = testa;
        pMenu n2 = n1->giu;
        pMenu n3 = n2->giu;

        delete n1;
        delete n2;
        delete n3;

        testa = NULL;
        selezionato = NULL;
    }
}

int Menu::gestisciMenu() {
    keypad(stdscr, TRUE); //
    bool sceltaFatta = false;
    int idScelto = -1;

    while (!sceltaFatta) {
        clear();

        mvprintw(2, 20, "BOMBERMAN");

        pMenu temp = testa;
        int riga = 6;

        do {
            if (temp == selezionato) {
                mvprintw(riga, 18, "-> %s", temp->testo);
            }
            else {
                mvprintw(riga, 18, "   %s", temp->testo);
            }
            riga = riga+2;
            temp = temp->giu;
        } while (temp != testa);
        refresh();

        int tasto = getch();
        switch (tasto) {
            case KEY_UP:
                selezionato = selezionato->su; // Il puntatore sale
                break;
            case KEY_DOWN:
                selezionato = selezionato->giu; // Il puntatore scende
                break;
            case 10: // Codice ASCII del tasto Invio
                sceltaFatta = true;
                idScelto = selezionato->idOpzione;
                break;
        }
    }

    return idScelto;
}

