//
// Created by alice flamigni on 08/03/26.
//

#ifndef PROVA_PROGETTO_BOMBA_H
#define PROVA_PROGETTO_BOMBA_H
#include <ctime>
/* viene lasciata dal personaggio in un punto (x,y); quando colpisce un muro
 * distruttibile, questo si rompe; quando colpisce il personaggio, esso perde
 * una vita; quando colpisce un nemico, questo muore
 */

class Bomba {
protected:
    int x; // coordinata orizzontale della bomba
    int y; // coordinata verticale della bomba
    int raggioScoppio; // determina su quante caselle si espande l'esplosione (di base è 1)(serve per quando
                        // il premio aumenta il raggio di 1 per 10 secondi)
    bool is_esplosa; // true se è esplosa
    time_t tempoEsplosione; //memorizza l'istante in cui viene sganciata (tipo di variabile che conta i secondi
                            // a partire dal 1 gennaio 1970)

public:
    Bomba (int startX, int startY, int raggioOra); // costruttore con coordinate
                                                   // iniziali e raggio in quel momento

    int getX(); // da al main la colonna in cui si trova la bomba (perche le coordinate protected non sono viste nel main)
    int getY(); // da al main la riga in cui si trova la bomba
    int getRaggio(); // fa sapere in quante caselle esplode la bomba
    bool isEsplosa(); // finche la bomba non esplode il tempo va avanti (partito nel momento
                    // in cui l'ho piazzata). se passano 3 secondi is_esplosa diventa true

};
// mancano: conseguenze su muri e personaggi; quando una bomba esplode deve essere tolta; devo capire come fare
// per dire che il raggio deve prendere tot quadratini in tutte le direzioni

#endif //PROVA_PROGETTO_BOMBA_H