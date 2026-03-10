//
// Created by alice flamigni on 04/03/26.
//

#include "GameStatus.h"

GameStatus::GameStatus() {
    vite = 5;
    punti = 0;
}

void GameStatus::perdiVita() {
    if (vite > 0) {
        vite = vite -1;
    }
}

int GameStatus::getVite() {
    return vite;
}

bool GameStatus::isGiocoFinito() {
    if (vite <= 0) {
        return true;
    }
    else {
        return false;
    }
}

void GameStatus::uccidiNemico(int puntiOttenuti) {
    punti = punti + puntiOttenuti;
}

void GameStatus::convertiTempoInPunti (int secondiRimanenti) {
    if (secondiRimanenti > 0) {
        punti = punti + secondiRimanenti;
    }
}

int GameStatus::getPunti() {
    return punti;
}




