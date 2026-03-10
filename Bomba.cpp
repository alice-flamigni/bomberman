//
// Created by alice flamigni on 08/03/26.
//

#include "Bomba.h"
#include <cstdlib>
#include <ctime>

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




