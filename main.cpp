
#include "Menu.h"
#include <ncurses.h>
#include "cmake-build-debug/Menu.h"

int main () {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    Menu mioMenu;
    bool inEsecuzione = true;

    while (inEsecuzione) {
        int scelta = mioMenu.gestisciMenu();

        clear();

        switch (scelta) {
            case 0:
                refresh();
                getch();
                break;

            case 1:
                refresh();
                getch();
                break;

            case 2:
                inEsecuzione = false; // Rompe il ciclo e avvia la chiusura
                break;
        }
    }
    clear();
    refresh();
    endwin();
    return 0;
}
