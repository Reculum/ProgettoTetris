
#include "funzioni_di_gioco.h"

#include "classe_tetramino.h"
#include "classe_griglia.h"

#include <ncurses.h>


int avvia_partita(){

    griglia campo = griglia(14, 26, 3, 54);
    griglia preview = griglia(8, 4, 3, 43);
    griglia pausa = griglia(61, 15, 7, 30);

    // scritta PAUSE

    {   //P
        pausa.update_griglia(3,8, 35);
        pausa.update_griglia(3,9, 35);
        pausa.update_griglia(3,10, 35);
        pausa.update_griglia(3,11, 35);

        pausa.update_griglia(4, 8, 35);
        pausa.update_griglia(4, 12, 35);

        pausa.update_griglia(5, 8, 35);
        pausa.update_griglia(5, 12, 35);

        pausa.update_griglia(6, 8, 35);
        pausa.update_griglia(6, 12, 35);

        pausa.update_griglia(7, 8, 35);
        pausa.update_griglia(7, 12, 35);

        pausa.update_griglia(8, 8, 35);
        pausa.update_griglia(8, 9, 35);
        pausa.update_griglia(8, 10, 35);
        pausa.update_griglia(8, 11, 35);

        pausa.update_griglia(9, 8, 35);
        pausa.update_griglia(10, 8, 35);
        pausa.update_griglia(11, 8, 35);


        //A

        pausa.update_griglia(3,19, 35);
        pausa.update_griglia(3,20, 35);
        pausa.update_griglia(3,21, 35);

        pausa.update_griglia(4, 18, 35);
        pausa.update_griglia(4, 22, 35);

        pausa.update_griglia(5, 17, 35);
        pausa.update_griglia(5, 23, 35);

        pausa.update_griglia(6, 17, 35);
        pausa.update_griglia(6, 23, 35);

        pausa.update_griglia(7, 17, 35);
        pausa.update_griglia(7, 18, 35);
        pausa.update_griglia(7, 22, 35);
        pausa.update_griglia(7, 23, 35);

        pausa.update_griglia(8, 17, 35);
        pausa.update_griglia(8, 19, 35);
        pausa.update_griglia(8, 20, 35);
        pausa.update_griglia(8, 21, 35);
        pausa.update_griglia(8, 23, 35);

        pausa.update_griglia(9, 17, 35);
        pausa.update_griglia(9, 23, 35);

        pausa.update_griglia(10, 17, 35);
        pausa.update_griglia(10, 23, 35);

        pausa.update_griglia(11, 17, 35);
        pausa.update_griglia(11, 23, 35);

        //U

        pausa.update_griglia(3, 28, 35);
        pausa.update_griglia(3, 34, 35);

        pausa.update_griglia(4, 28, 35);
        pausa.update_griglia(4, 34, 35);

        pausa.update_griglia(5, 28, 35);
        pausa.update_griglia(5, 34, 35);

        pausa.update_griglia(6, 28, 35);
        pausa.update_griglia(6, 34, 35);

        pausa.update_griglia(7, 28, 35);
        pausa.update_griglia(7, 34, 35);

        pausa.update_griglia(8, 28, 35);
        pausa.update_griglia(8, 34, 35);

        pausa.update_griglia(9, 28, 35);
        pausa.update_griglia(9, 34, 35);

        pausa.update_griglia(10, 29, 35);
        pausa.update_griglia(10, 33, 35);

        pausa.update_griglia(11, 30, 35);
        pausa.update_griglia(11, 31, 35);
        pausa.update_griglia(11, 32, 35);

        //S

        pausa.update_griglia(3, 40, 35);
        pausa.update_griglia(3, 41, 35);
        pausa.update_griglia(3, 42, 35);
        pausa.update_griglia(3, 43, 35);

        pausa.update_griglia(4, 39, 35);

        pausa.update_griglia(5, 39, 35);

        pausa.update_griglia(6, 39, 35);

        pausa.update_griglia(7, 40, 35);
        pausa.update_griglia(7, 41, 35);
        pausa.update_griglia(7, 42, 35);

        pausa.update_griglia(8, 43, 35);

        pausa.update_griglia(9, 43, 35);

        pausa.update_griglia(10, 43, 35);

        pausa.update_griglia(11, 39, 35);
        pausa.update_griglia(11, 40, 35);
        pausa.update_griglia(11, 41, 35);
        pausa.update_griglia(11, 42, 35);

        //E

        pausa.update_griglia(3, 48, 35);
        pausa.update_griglia(3, 49, 35);
        pausa.update_griglia(3, 50, 35);
        pausa.update_griglia(3, 51, 35);
        pausa.update_griglia(3, 52, 35);

        pausa.update_griglia(4, 48, 35);

        pausa.update_griglia(5, 48, 35);

        pausa.update_griglia(6, 48, 35);

        pausa.update_griglia(7, 48, 35);
        pausa.update_griglia(7, 49, 35);
        pausa.update_griglia(7, 50, 35);
        pausa.update_griglia(7, 51, 35);
        pausa.update_griglia(7, 52, 35);

        pausa.update_griglia(8, 48, 35);

        pausa.update_griglia(9, 48, 35);

        pausa.update_griglia(10, 48, 35);

        pausa.update_griglia(11, 48, 35);
        pausa.update_griglia(11, 49, 35);
        pausa.update_griglia(11, 50, 35);
        pausa.update_griglia(11, 51, 35);
        pausa.update_griglia(11, 52, 35);



    }

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


    int num_sprint = 3;
    int temp_caduta = 120;
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
            if(input == KEY_DOWN){pos_y += 1;}


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
                if(input == KEY_DOWN){pos_y -= 1;}

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

    mvprintw(12, 26, "la partita si e' conclusa!");

    timeout(-1);
    getch();

    return punteggio;

}