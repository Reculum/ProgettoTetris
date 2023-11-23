#include "funzioni_di_gioco.h"

#include "liste.h"
#include <fstream>

#include "classe_tetramino.h"
#include "classe_griglia.h"





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

    clear();

    return punteggio;

}

void memorizza_punteggio(int nuovo_punteggio){

    ifstream file_punti_in;
    ofstream file_punti_out;

    file_punti_in.open("punteggi.txt");


    char car;
    char next_car;

    file_punti_in.get(car);

    if(file_punti_in.eof()){

        file_punti_in.close();

        file_punti_out.open("punteggi.txt", ios::app);
        file_punti_out << nuovo_punteggio << "!";
        file_punti_out.close();
    }
    else{

        p_lista_int head_int = leggi_punteggio();
        p_lista_int head_int_backup = head_int;


        //inserisce il nuovo punteggio in ordine

        head_int = head_int_backup;
        p_lista_int new_nodo;
        p_lista_int temp_next;

        bool place_found = false;

        if( nuovo_punteggio >= (head_int -> val) ){

            p_lista_int new_head_int = new lista_int;

            new_head_int -> val = nuovo_punteggio;
            new_head_int -> next = head_int;

            head_int_backup = new_head_int;
        }
        else{

            while( (head_int -> next != NULL) && (!place_found) ){

                if( nuovo_punteggio >= (head_int -> next -> val) ){

                     new_nodo = new lista_int;
                     temp_next = head_int -> next;

                     new_nodo -> val = nuovo_punteggio;
                     head_int -> next = new_nodo;
                     new_nodo -> next = temp_next;

                     place_found = true;

                }
                else{head_int = head_int -> next;}

            }

            if(!place_found){

                new_nodo = new lista_int;
                head_int -> next = new_nodo;

                new_nodo -> val = nuovo_punteggio;
                new_nodo -> next = NULL;

            }

        }

        head_int = head_int_backup;

        //riscrive il file con la lista aggiornata

        file_punti_out.open("punteggi.txt");

        while(head_int != NULL){
            file_punti_out << (head_int -> val) << "!";
            head_int = head_int -> next;
        }

        file_punti_out.close();

    }
};

p_lista_int leggi_punteggio(){

    ifstream file_punti_in;
    file_punti_in.open("punteggi.txt");

    char car;
    char next_car;

    file_punti_in.get(car);

    p_lista_int head_int = new lista_int;
    p_lista_int head_int_backup = head_int;
    p_lista_int temp_int;

    p_lista_char head_char = new lista_char;
    p_lista_char temp_char;
    head_char -> previous = NULL;

    p_lista_char temp;

    while(!file_punti_in.eof()){

        if(car != '!'){

            temp_char = new lista_char;

            head_char -> ch = car;
            head_char -> next = temp_char;

            temp_char -> previous = head_char;
            head_char = temp_char;

            file_punti_in.get(next_car);
            car = next_car;
        }
        else{

            int valore = 0;
            int ten_pow = 1;

            head_char = head_char -> previous;

            file_punti_in.get(next_car);

            if(file_punti_in.eof()){
                temp_int = NULL;
            }
            else{
                temp_int = new lista_int;
                car = next_car;
            }



            while(head_char != NULL){

                temp = head_char;

                valore += ( (int) head_char -> ch - 48) * ten_pow;
                ten_pow *= 10;

                head_char = head_char -> previous;
                delete temp;
            }


            head_int -> val = valore;
            head_int -> next = temp_int;

            //head_int sarà sempre NULL alla fine del ciclo
            head_int = temp_int;

            head_char = new lista_char;
            head_char -> previous = NULL;

        }
    }

    file_punti_in.close();
    head_int = head_int_backup;

    return head_int;

}

void stampa_classifica(){

    p_lista_int head = leggi_punteggio();

    int num_punt_disegnati = 0;
    int coord_y = 5;

    while( (num_punt_disegnati != 18) && (head != NULL)){

        mvprintw(coord_y, 56, "%d%", (head -> val));

        coord_y += 1;
        head = head -> next;
        num_punt_disegnati += 1;

    }

    getch();

    clear();

}

void disegna_menu(){

    titolo.disegna_griglia();

    nuova_partita.disegna_griglia();
    mvprintw(12, 54, "nuova partita");

    classifica.disegna_griglia();
    mvprintw(17, 55, "graduatoria");
    mvprintw(19, 58, "punti");

    esci.disegna_griglia();
    mvprintw(24, 58, "esci");


}

void carica_scritta_tetris(){

    //T

    titolo.update_griglia(2, 11, 547);
    titolo.update_griglia(2, 12, 547);
    titolo.update_griglia(2, 13, 547);
    titolo.update_griglia(2, 14, 547);
    titolo.update_griglia(2, 15, 547);

    titolo.update_griglia(3, 13, 547);
    titolo.update_griglia(4, 13, 547);
    titolo.update_griglia(5, 13, 547);
    titolo.update_griglia(6, 13, 547);

    //E

    titolo.update_griglia(2, 19, 291);
    titolo.update_griglia(2, 20, 291);
    titolo.update_griglia(2, 21, 291);
    titolo.update_griglia(2, 22, 291);

    titolo.update_griglia(3, 19, 291);

    titolo.update_griglia(4, 19, 291);
    titolo.update_griglia(4, 20, 291);
    titolo.update_griglia(4, 21, 291);
    titolo.update_griglia(4, 22, 291);

    titolo.update_griglia(5, 19, 291);

    titolo.update_griglia(6, 19, 291);
    titolo.update_griglia(6, 20, 291);
    titolo.update_griglia(6, 21, 291);
    titolo.update_griglia(6, 22, 291);

    //T

    titolo.update_griglia(2, 26, 1059);
    titolo.update_griglia(2, 27, 1059);
    titolo.update_griglia(2, 28, 1059);
    titolo.update_griglia(2, 29, 1059);
    titolo.update_griglia(2, 30, 1059);

    titolo.update_griglia(3, 28, 1059);
    titolo.update_griglia(4, 28, 1059);
    titolo.update_griglia(5, 28, 1059);
    titolo.update_griglia(6, 28, 1059);

    //R

    titolo.update_griglia(2, 34, 1059);
    titolo.update_griglia(2, 35, 1059);
    titolo.update_griglia(2, 36, 1059);
    titolo.update_griglia(2, 37, 1059);

    titolo.update_griglia(3, 34, 1059);
    titolo.update_griglia(3, 37, 1059);

    titolo.update_griglia(4, 34, 1059);
    titolo.update_griglia(4, 35, 1059);
    titolo.update_griglia(4, 36, 1059);
    titolo.update_griglia(4, 37, 1059);

    titolo.update_griglia(5, 34, 1059);
    titolo.update_griglia(5, 36, 1059);

    titolo.update_griglia(6, 34, 1059);
    titolo.update_griglia(6, 37, 1059);

    //I

    titolo.update_griglia(2, 41, 803);
    titolo.update_griglia(2, 42, 803);
    titolo.update_griglia(2, 43, 803);

    titolo.update_griglia(3, 42, 803);
    titolo.update_griglia(4, 42, 803);
    titolo.update_griglia(5, 42, 803);

    titolo.update_griglia(6, 41, 803);
    titolo.update_griglia(6, 42, 803);
    titolo.update_griglia(6, 43, 803);

    //S

    titolo.update_griglia(2, 47, 1571);
    titolo.update_griglia(2, 48, 1571);
    titolo.update_griglia(2, 49, 1571);
    titolo.update_griglia(2, 50, 1571);

    titolo.update_griglia(3, 47, 1571);

    titolo.update_griglia(4, 47, 1571);
    titolo.update_griglia(4, 48, 1571);
    titolo.update_griglia(4, 49, 1571);
    titolo.update_griglia(4, 50, 1571);

    titolo.update_griglia(5, 50, 1571);

    titolo.update_griglia(6, 47, 1571);
    titolo.update_griglia(6, 48, 1571);
    titolo.update_griglia(6, 49, 1571);
    titolo.update_griglia(6, 50, 1571);









}