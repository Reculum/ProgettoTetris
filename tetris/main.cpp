

#include "funzioni_di_gioco.h"
#include "classe_griglia.h"

#include <cstdlib>
#include <ctime>
#include <ncurses.h>

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
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    //disegna la configurazione iniziale della menu

    carica_scritta_tetris();
    titolo.disegna_griglia();

    attron(COLOR_PAIR(2));
    nuova_partita.disegna_griglia();
    mvprintw(12, 54, "nuova partita");
    attroff(COLOR_PAIR(2));

    classifica.disegna_griglia();
    mvprintw(17, 55, "graduatoria");
    mvprintw(19, 58, "punti");

    esci.disegna_griglia();
    mvprintw(24, 58, "esci");


    bool menu_loop = true;
    int posizione = 0;
    int input;
    int nuovo_punteggio;

    while(menu_loop){

        input = getch();

        if(input == KEY_DOWN){
            posizione += 1;
            disegna_menu();
        }

        if(input == KEY_UP){
            posizione -= 1;
            disegna_menu();
        }

        if(input == 10){

            if (posizione == 0){

                clear();

                nuovo_punteggio = avvia_partita();
                memorizza_punteggio(nuovo_punteggio);

                disegna_menu();

            }
            if (posizione == 1){

                clear();

                graduatoria.disegna_griglia();
                stampa_classifica();

                disegna_menu();


            }
            if (posizione == 2){menu_loop = false;}

        }



        if(posizione > 2){posizione = 2;}
        if(posizione < 0){posizione = 0;}

        if(posizione == 0){

            attron(COLOR_PAIR(2));
            nuova_partita.disegna_griglia();
            mvprintw(12, 54, "nuova partita");
            attroff(COLOR_PAIR(2));

        }

        if(posizione == 1){

            attron(COLOR_PAIR(2));
            classifica.disegna_griglia();
            mvprintw(17, 55, "graduatoria");
            mvprintw(19, 58, "punti");
            attroff(COLOR_PAIR(2));

        }

        if (posizione == 2){

            attron(COLOR_PAIR(2));
            esci.disegna_griglia();
            mvprintw(24, 58, "esci");
            attroff(COLOR_PAIR(2));

        }


    }



    endwin();

}



