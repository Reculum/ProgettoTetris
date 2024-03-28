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
            if(input == KEY_DOWN){tick = num_sprint;}


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

        //verifica se il punteggio sia maggiore della testa

        if( nuovo_punteggio >= (head_int -> val) ){

            p_lista_int new_head_int = new lista_int;

            new_head_int -> val = nuovo_punteggio;
            new_head_int -> next = head_int;

            head_int_backup = new_head_int;
        }
        else{

            //verifica se il punteggio sia maggiore dei valori nella lista

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

            //se il punteggio non è maggiore di alcun punteggio nella lista
            //crea un nuovo nodo e fa puntare head_int, che a questo punto
            // è l'ultimo elemento non NULL della lista, a quel nodo ed
            // inserisce un ultimo NULL finale

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

    if(file_punti_in.eof()){return NULL;}

    p_lista_int head_int = new lista_int;
    p_lista_int head_int_backup = head_int;
    p_lista_int temp_int;

    p_lista_char head_char = new lista_char;
    p_lista_char temp_char;
    head_char -> previous = NULL;

    p_lista_char temp;

    while(!file_punti_in.eof()){

        if(car != '!'){

            // legge i caratteri dal testo; i valori di car e next_car saranno sempre allineati

            temp_char = new lista_char;

            head_char -> ch = car;
            head_char -> next = temp_char;

            temp_char -> previous = head_char;
            head_char = temp_char;

            file_punti_in.get(next_car);
            car = next_car;
        }
        else{

            // quando car (= next_car) è uguale a !, allora va avanti di un carattere nella lettura
            // se raggiunge la fine del file, concluderà la lista di interi (temp_int = NULL)
            // altrimenti riallinea car e next_car e temp_int sarà un nuovo indirizzo di memoria

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

            //cancella l'intera lista di caratteri e ne estrae il valore intero

            while(head_char != NULL){

                temp = head_char;

                valore += ( (int) head_char -> ch - 48) * ten_pow;
                ten_pow *= 10;

                head_char = head_char -> previous;
                delete temp;
            }            


            head_int -> val = valore;
            head_int -> next = temp_int;

            //head_int sarà sempre NULL alla fine del ciclo, dunque
            //la lista di interi, verrà sempre chiusa propriamente

            head_int = temp_int;

            //ricreiamo quella di caratteri che a questo punto
            // è stata cancellata del tutto

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

void menu_iniziale(){



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
    int input_choose_gamemode;
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

                attron(COLOR_PAIR(5));
                nuova_partita.disegna_griglia();
                mvprintw(11, 54, "F1: std mode");
                mvprintw(13, 54, "F2: grav mode");
                attroff(COLOR_PAIR(5));

                input_choose_gamemode = getch();

                if(input_choose_gamemode == KEY_F(1)){

                    clear();

                    nuovo_punteggio = avvia_partita();
                    memorizza_punteggio(nuovo_punteggio);

                    disegna_menu();
                }
                else{

                    clear();

                    gravity_mode();

                    disegna_menu();
                }



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


}

void gravity_mode(){

    griglia campo = griglia(28, 30, 2, 46);
    griglia base = griglia(12, 2, 27, 54);
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

    //traccia la bilancia

    { for(int k = 46; k <= 73; k++){

        if((k == 59) || (k == 60)){mvprintw(0, k, "X");}
        else{mvprintw(0, k, "*");}

        }

        mvprintw(1, 59, "^");

    }

    campo.upload_griglia(base);
    campo.remove_row(0);
    campo.remove_row(29);

    campo.disegna_griglia();

    bool loop = true;
    int tick = 0;
    int input;
    int pos_x;
    int pos_y;
    int pos_curs = 59;


    int num_sprint = 3;
    int temp_caduta = 120;
    int rand_int;
    int next_rand_int;

    while(loop){

        rand_int = rand()%7 + 1;
        tetramino player = choose_tetramino(rand_int);



        if( !player.can_print(3, 59) ){

            for(int k = 1; k <= 24; k++){
                campo.remove_row(29);
            }

            campo.disegna_griglia();

        }

        attron(COLOR_PAIR(rand_int));
        player.stampa(3, 59);
        attroff(COLOR_PAIR(rand_int));

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
            if(input == KEY_DOWN){tick = num_sprint;}


            if(input == KEY_F(1)){loop = false; player.set_caduto(true);}
            if(input == KEY_F(2)){

                campo.upload_tetramino(player);
                clear();

                pausa.disegna_griglia();
                refresh();

                timeout(-1);
                getch();

                clear();

                campo.disegna_griglia();

                //ridisegna la bilancia

                for(int k = 46; k <= 73; k++){

                        if((k == 59) || (k == 60)){mvprintw(0, k, "X");}
                        else{mvprintw(0, k, "*");}

                    }

                mvprintw(1, pos_curs, "^");


                refresh();

            }

            if( !player.can_print(pos_y, pos_x) ){

                if(input == KEY_RIGHT){pos_x -= 1;}
                if(input == KEY_LEFT){pos_x += 1;}

                if(input == KEY_UP){player.ruota_90_sx();}


            }



            if( (player.get_y() + player.get_mat().find_most_down()) >= 29){

                pos_y = 2;
                pos_x = 59;

            }
            else{

                if( (tick >= num_sprint) && ( !player.is_caduto()) ){

                    pos_y += 1;
                    tick = 0;


                    if (!player.can_print(pos_y, pos_x)) {
                        pos_y -= 1;
                        player.set_caduto(true);
                    }

                }

            }


            attron(COLOR_PAIR(rand_int));
            player.stampa(pos_y, pos_x);
            attroff(COLOR_PAIR(rand_int));

        }

        campo.upload_tetramino(player);

        int player_width = player.get_mat().find_most_right();

        int unbalance = 0;

        //calcola di quanto è stata sbilanciata la torre

        for(int j = 0; j <= player_width; j++){

            if((player.get_x() + j) > 65){

                for(int k = 0; k < 4; k++){
                    if(player.get_mat().get(k, j) != 0){unbalance += 1;}
                }
            }
            else if((player.get_x() + j) < 54){

                for(int k = 0; k < 4; k++){
                    if(player.get_mat().get(k, j) != 0){unbalance -= 1;}
                }
            }
            else{

                for(int k = 0; k < 4; k++){
                    if(player.get_mat().get(k, j) != 0){
                        if(rand()%2 == 0){unbalance -= 1;}
                        else{unbalance += 1;}
                    }
                }

            }


        }


        mvprintw(1, pos_curs, " ");
        pos_curs += unbalance;
        mvprintw(1, pos_curs, "^");

        if((pos_curs < 46) || (pos_curs > 73)){loop = false;}

    }

    mvprintw(0,0, "la torre e' crollata!");

    timeout(-1);
    getch();

    clear();

}