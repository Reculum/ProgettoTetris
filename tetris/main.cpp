
#include "classe_tetramino.h"
#include "classe_griglia.h"
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


    griglia campo = griglia(12, 24, 3, 54);
    griglia preview = griglia(8, 4, 3, 43);
    griglia pausa = griglia(60, 15, 7, 30);

    preview.disegna_griglia();
    campo.disegna_griglia();
    mvprintw(10, 33, "punteggio:");
    mvprintw(10, 44, "%d%", 0);


    bool loop = true;
    int tick = 0;
    int input;
    int pos_x;
    int pos_y;
    int punteggio = 0;


    int num_sprint = 4;
    int temp_caduta = 125;
    int rand_int;
    int next_rand_int;

    rand_int = rand()%7 + 1;
    tetramino player = choose_tetramino(rand_int);


    while(loop){

        attron(COLOR_PAIR(rand_int));

        if( !player.can_print(4,59) ){loop = false; player.set_caduto(true);}
        else{player.stampa(4, 59);}

        attroff(COLOR_PAIR(rand_int));

        next_rand_int = rand()%7 + 1;
        tetramino next_player = choose_tetramino(next_rand_int);

        attron(COLOR_PAIR(next_rand_int));
        next_player.stampa(4, 45);
        attroff(COLOR_PAIR(next_rand_int));

        preview.upload_tetramino(next_player);


        while(!player.is_caduto()){

            pos_x = player.get_x();
            pos_y = player.get_y();

            timeout(temp_caduta);
            input = getch();

            player.cancella();

            if(input == -1){tick = num_sprint;}
            else{napms( ((2 * temp_caduta)/num_sprint) ); tick += 1;}

            if(input == KEY_RIGHT){pos_x += 1;}
            if(input == KEY_LEFT){pos_x -= 1;}

            if(input == KEY_UP){player.ruota_90_dx();}
            if(input == KEY_DOWN){player.ruota_90_sx();}


            if(input == KEY_F(1)){loop = false; player.set_caduto(true);}
            if(input == KEY_F(2)){

                campo.upload_tetramino(player);
                clear();

                pausa.disegna_griglia();
                refresh();

                timeout(-1);
                getch();

                clear();

                mvprintw(10, 33, "punteggio:");
                mvprintw(10, 44, "%d%", punteggio);

                campo.disegna_griglia();
                preview.disegna_griglia();
                refresh();

            }

            if( !player.can_print(pos_y, pos_x) ){

                if(input == KEY_RIGHT){pos_x -= 1;}
                if(input == KEY_LEFT){pos_x += 1;}

                if(input == KEY_UP){player.ruota_90_sx();}
                if(input == KEY_DOWN){player.ruota_90_dx();}

            }


            if( (tick >= num_sprint) && ( !player.is_caduto()) ){

                pos_y += 1;
                tick = 0;

                if( !player.can_print(pos_y, pos_x) ){
                    pos_y -= 1;
                    player.set_caduto(true);
                }
            }


            attron(COLOR_PAIR(rand_int));
            player.stampa(pos_y, pos_x);
            attroff(COLOR_PAIR(rand_int));

            }

        campo.upload_tetramino(player);

        matrice player_mat = player.get_mat();
        int y_player = player.get_y();
        int y_campo = campo.get_y();

        int num_completed = 0;

        int num_spanned_rows = player_mat.find_most_down();

        for(int k = 0; k <= num_spanned_rows; k++){

            int riga_griglia = y_player - y_campo + k;

            if (campo.is_row_completed(riga_griglia)){

                num_completed += 1;
                campo.remove_row(riga_griglia);
            }

        }

        if(num_completed >= 1){

            campo.disegna_griglia();

            punteggio += 10 * num_completed * num_completed;
            mvprintw(10, 44, "%d%", punteggio);

        }


        preview.svuota_griglia();
        preview.disegna_griglia();

        player = next_player;
        rand_int = next_rand_int;

    }

    mvprintw(0,0, "hai perso, mezza sega!");

    timeout(-1);
    getch();

    endwin();

}



