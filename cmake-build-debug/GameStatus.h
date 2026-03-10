//
// Created by alice flamigni on 04/03/26.
//

#ifndef PROVA_PROGETTO_GAMESTATUS_H
#define PROVA_PROGETTO_GAMESTATUS_H
/* la classe GameStatus gestisce vite e punti del giocatore. si parte da
 * 5 vite e 0 punti. una vita in meno se il personaggio è colpito da una bomba
 * o da un nemico. i punti incrementano quando il personaggio uccide un nemico
 * e se alla fine del gioco rimangono secondi extra, essi si convertono in punti.
 */

class GameStatus {
protected:
    int vite;
    int punti;

public:
    GameStatus(); // costruttore: nel .cpp ci imposto vite=5 e punti=0

    void perdiVita(); // toglie una vita
    int getVite(); // siccome vite è protected serve a far vedere nel main quante vite ho
    bool isGiocoFinito(); // se vite sono a 0 restituisce true

    void uccidiNemico(int puntiOttenuti); // somma puntiOttenuti a punti quando uccidi un nemico
    void convertiTempoInPunti(int secondiRimanenti); // converte i secondiRimanenti in punti alla fine del gioco
    int getPunti(); // stessa cosa di getVite ma con i punti
};

// mancano: dire che perde una vita quando è colpito da una bomba o quando è colpito da un nemico
// (non basta dire vite = vite-1)
#endif //PROVA_PROGETTO_GAMESTATUS_H