
#include "classe_tetramino.h"
#include <ncurses.h>

#ifndef COSTANTI_GRIGLIA
#define COSTANTI_GRIGLIA

class griglia{

protected:

    int larg;
    int alt;

    int pos_x;
    int pos_y;

    int* mat;

public:

    griglia(const int L, const int A, int y, int x){

        larg = L;
        alt = A;
        pos_x = x;
        pos_y = y;

        mat = new int[L * A];

        svuota_griglia();

    };

    void update_griglia(int k, int j, int val){
        *(mat + k * larg + j) = val;
    };

    int get_griglia_elem(int k, int j){return *(mat + k * larg + j);};

    int get_y(){return pos_y;};
    int get_x(){return pos_x;};

    void svuota_griglia(){

        for(int k = 0; k < alt; k++){
            for(int j = 0; j < larg; j++){

                if((j == 0) || (j == larg - 1) || (k == alt - 1) || (k == 0)){
                    update_griglia(k, j, (int) '#');
                }
                else{update_griglia(k, j, 32);}
            }
        }

    };

    void disegna_griglia(){

        for(int k = 0; k < alt; k++){
            for(int j = 0; j < larg; j++){

                int carattere = get_griglia_elem(k, j);

                mvaddch(pos_y + k, pos_x + j, carattere);

            }
        }

        refresh();

    };

    void upload_tetramino(tetramino player){

        matrice mat_player = player.get_mat();

        int x_player = player.get_x();
        int y_player = player.get_y();

        int carattere;
        int riga_griglia;
        int colonna_griglia;

        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){

                if( mat_player.get(k, j) != 0 ){

                    carattere = mvinch(y_player + k, x_player + j);

                    riga_griglia = y_player - pos_y + k;
                    colonna_griglia = x_player - pos_x + j;

                    update_griglia(riga_griglia, colonna_griglia, carattere);


                }

            }
        }




    };

    bool is_row_completed(int k){

        bool completa = true;

        int col = 0;

        while( completa && (col < larg)){

            if(get_griglia_elem(k, col) == 32){completa = false;}
            else{col += 1;}

        }

        return completa;

    };

    void remove_row(int ind_riga){

        for(int k = ind_riga - 1; k >= 1; k--){
            for(int j = 1; j <= larg - 2; j++){

                int carattere = get_griglia_elem(k, j);
                update_griglia(k + 1, j, carattere);

            }
        }

        for(int j = 1; j <= larg - 2; j++){ update_griglia(1, j, 32);}

    }



};

extern griglia titolo;
extern griglia nuova_partita;
extern griglia classifica;
extern griglia graduatoria;
extern griglia esci;

#endif