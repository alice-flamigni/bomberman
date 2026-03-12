//
// Created by alice flamigni on 08/03/26.
//

#include "Bomba.h"
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

Bomba::Bomba(int startX, int startY, int raggioOra) {
    x = startX;
    y = startY;
    raggioScoppio = raggioOra;
    is_esplosa = false;

    tempoEsplosione = time(NULL);
}

int Bomba::getX() {
    return x;
}

int Bomba::getY() {
    return y;
}

int Bomba::getRaggio() {
    return raggioScoppio;
}

bool Bomba::isEsplosa() {
    if (!is_esplosa) {
        time_t orarioAttuale = time(NULL);
        if (orarioAttuale-tempoEsplosione >= 3) {
            is_esplosa = true;
        }
    }
    return is_esplosa;
}

void Bomba::disegnaBomba() {
    if (!is_esplosa) {      //se la bomba deve ancora esplodere la "vediamo"
        mvprintw(y,x,"*");  // stampo l'asterisco alle coordinate della bomba
    }
}

void Bomba::disegnaEsplosione() {
    if (is_esplosa) {
        // se is_esplosa = true allora disegno la bomba e il raggio
        mvprintw(y,x,"*"); //disegno sempre la bomba

        for (int i = 1; i<= raggioScoppio; i++) {
            mvprintw(y-i,x,"*"); // scoppio in alto
            mvprintw(y+i,x,"*"); // scoppio in basso
            mvprintw(y,x-i,"*"); // scoppio a sinistra
            mvprintw(y,x+i,"*"); // scoppio a destra
        }
    }
}

void Bomba::cancella() {
    mvprintw(y,x," "); // stampo spazio vuoto al centro per cancellare la bomba

    if (is_esplosa) {   // se la bomba era esplosa cancello anche l'esplosione nelle varie direzioni
        for (int i = 1; i<= raggioScoppio; i++) {
            mvprintw(y-i,x," "); // cancello in alto
            mvprintw(y+i,x," "); // cancello in basso
            mvprintw(y,x-i," "); // cancello a sinistra
            mvprintw(y,x+i," "); // cancello a destra
        }
    }

}







