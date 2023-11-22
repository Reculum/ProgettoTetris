



#include "funzioni_di_gioco.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using namespace std;



int main(void){

    srand(time(0));

    initscr();

    cbreak();
    curs_set(0);
    keypad(stdscr, true);

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    avvia_partita();



    endwin();

}



