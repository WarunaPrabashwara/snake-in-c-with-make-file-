#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include <conio.h>
#include "random.h"



int i, j,k, m  ,var,   height , width  , Game = 1 , sizeofsnake  ,  moved =0 , trytogoout =0;
int UNBEATABLE = 1;
int lost = 0 ;
char direction = 'd';
char directionarr[100] ;

#define wi 100
#define he 100
int Field[wi][he]  ;
int trytogoreverse = 0 ;
int invalkey = 0 ;

void directioninit(){
    for (int i = 0 ; i < sizeofsnake - 2  ; i++){
        directionarr[i] = '-';
    }
}

void snakeInitialization(){
   for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            Field[i][j]=0;
        }
    }

    for(i=1 ; i<sizeofsnake+1 ; i++){
        if( i == sizeofsnake){
                Field[2][i] = sizeofsnake;
        }
        else if (  i == 1  ){
                Field[2][i] = 1;
        }
        else {
                Field[2][i] = i;
        }
    }
}

void dkey(){
    for(i=0;i<height;i++){
    for(j=0;j<width;j++){
            if (Field[i][j] == sizeofsnake ){
                if( Field[i][j+1] == sizeofsnake-1  ){
                    trytogoreverse = 1 ;

                }
                else if ( UNBEATABLE == 0 && Field[i][j+1] >0 ){
                            lost = 1;
                        }
                else{
                    if( moved == 0 && j+1 < width-1 ){
                        moved =1 ;
                        Field[i][j+1] = sizeofsnake ;
                        for( int dm = 0 ;dm <sizeofsnake -3 ; dm++){
                            directionarr[dm] = directionarr[dm +1];
                        }
                        directionarr[sizeofsnake -3 ] = '-';
                        direction = 'd';
                        for( int k = 0 ; k <height ; k++){
                            for( int m = 0 ; m <width ; m++ ){
                                if( 0 < Field[k][m]  &&  Field[k][m] < sizeofsnake ){
                                    Field[k][m] = Field[k][m] -1;
                                }
                            }
                        }
                        Field[i][j] = sizeofsnake-1 ;
                        if ( i == k  && j+1 == m ){

                            Game = 0 ;

                        }
                        else{
                            continue;
                        }

                    }
                    else if( moved == 0 && j+1 == width -1  ){
                        trytogoout = 1;
                    }
                }

            }
            else {
                continue ;
            }
    }

    }
}

void akey(){
    for(i=0;i<height;i++){
    for(j=0;j<width;j++){
            if (Field[i][j] == sizeofsnake ){
                if( Field[i][j-1] == sizeofsnake-1  ){
                    trytogoreverse = 1 ;
                }
                else if ( UNBEATABLE == 0 && Field[i][j-1] >0 ){
                            lost = 1;
                        }
                else{
                    if( moved == 0 && j-1 > 1 ){
                        moved =1 ;
                        Field[i][j-1] = sizeofsnake ;
                        for( int dm = 0 ;dm <sizeofsnake -3 ; dm++){
                            directionarr[dm] = directionarr[dm +1];
                        }
                        directionarr[sizeofsnake -3 ] = '-';
                        direction ='a';
                        for( int k = 0 ; k <height ; k++){
                            for( int m = 0 ; m <width ; m++ ){
                                if( 0 < Field[k][m]  &&  Field[k][m] < sizeofsnake ){
                                    Field[k][m] = Field[k][m] -1;
                                }
                            }
                        }
                        Field[i][j] = sizeofsnake-1 ;
                        if ( i == k  && j-1 == m ){

                            Game = 0 ;

                        }
                        else{
                            continue;
                        }

                    }
                    else if( moved == 0 && j-1 == 1  ){
                        trytogoout = 1;
                    }
                }

            }
            else {
                continue ;
            }
    }

    }
}

void wkey(){
    for(i=0;i<height;i++){
    for(j=0;j<width;j++){
            if (Field[i][j] == sizeofsnake ){
                if( Field[i-1][j] == sizeofsnake-1  ){
                    trytogoreverse = 1 ;
                }
                else if ( UNBEATABLE == 0 && Field[i-1][j] >0 ){
                            lost = 1;
                        }
                else{
                    if( moved == 0 && i-1 > 0){
                        moved =1 ;
                        Field[i-1][j] = sizeofsnake ;
                        for( int dm = 0 ;dm <sizeofsnake -3 ; dm++){
                            directionarr[dm] = directionarr[dm +1];
                        }
                        directionarr[sizeofsnake -3 ] = '|';
                        direction ='w';
                        for( int k = 0 ; k <height ; k++){
                            for( int m = 0 ; m <width ; m++ ){
                                if( 0 < Field[k][m]  &&  Field[k][m] < sizeofsnake ){
                                    Field[k][m] = Field[k][m] -1;
                                }
                            }
                        }
                        Field[i][j] = sizeofsnake-1 ;
                        if ( i-1 == k  && j == m ){

                            Game = 0 ;
                        }
                        else{
                            continue;
                        }

                    }
                    else if( moved == 0 && i-1 == 0  ){
                        trytogoout = 1;
                    }
                }

            }
            else {
                continue ;
            }
    }

    }
}

void skey(){
    for(i=0;i<height;i++){
    for(j=0;j<width;j++){
            if (Field[i][j] == sizeofsnake ){
                if( Field[i+1][j] == sizeofsnake-1  ){
                    trytogoreverse = 1 ;
                }
                else if ( UNBEATABLE == 0 && Field[i+1][j] >0 ){
                            lost = 1;
                        }
                else{
                    if( moved == 0 && i+1 < height -1 ){
                        moved =1 ;
                        Field[i+1][j] = sizeofsnake ;
                        for( int dm = 0 ;dm <sizeofsnake -3 ; dm++){
                            directionarr[dm] = directionarr[dm +1];
                        }
                        directionarr[sizeofsnake -3 ] = '|';
                        direction ='s';
                        for( int k = 0 ; k <height ; k++){
                            for( int m = 0 ; m <width ; m++ ){
                                if( 0 < Field[k][m]  &&  Field[k][m] < sizeofsnake ){
                                    Field[k][m] = Field[k][m] -1;
                                }
                            }
                        }
                        Field[i][j] = sizeofsnake-1 ;
                        if ( i+1 == k  && j == m ){

                            Game = 0 ;
                        }
                        else{
                            continue;
                        }

                    }
                    else if( moved == 0 && i+1 == height -1  ){
                        trytogoout = 1;
                    }
                }

            }
            else {
                continue ;
            }
    }

    }
}

int getch_noblock(){
    while (!kbhit()){
        return _getch();
    }
}

void movement(){
    var = getch_noblock();
    var = tolower(var);

    if(var != 'd' && var != 'a' && var != 'w' && var != 's'  ){
            invalkey = 1 ;

    }
    if(var == 'd'){
        dkey();
    }

    if(var == 'a'){
        akey();
    }
    if(var == 'w'){
        wkey();
    }
    if(var == 's'){
        skey();
    }


}



/* this will map the food into the grid */
void toRange(){
    if(height > width ){
        k = random( width , height )/2;
        m = random( width , height )/2;
    }
    else {
        k = random( height , width )/2;
        m = random( height , width )/2;
    }
    if ( k == height   ){
        k = k -1 ;
    }
    if( k + 1 == height ){
        k= k - 2 ;
    }
    if(k == 0 ){
        k = 1 ;
    }
    if ( m == width   ){
        m = m -1 ;
    }

    if( m +1 ==  width  ){
        m = m -2 ;
    }
    if (m == 0){
        m = 1 ;
    }
}


void draw()
{

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            }


            else if ( Field[i][j] >0 ){
                if (Field[i][j] ==1){
                    printf("%c", 35);
                }
                else if (1 <Field[i][j] && Field[i][j] < sizeofsnake){
                    for (int in = 0 ; in < sizeofsnake -2 ; in++) {
                        if( Field[i][j] == in+2   ){
                            if( directionarr[in] == '-' ){
                                printf("%c",45);
                            }
                            else if (directionarr[in] == '|'){
                                printf("%c",124);
                            }
                        }
                    }

                }
                else if(Field[i][j] == sizeofsnake  ) {
                    if(direction == 'a'){
                        printf("%c",60);
                    }
                    else if (direction == 'w'){
                        printf("%c",94);
                    }
                    else if (direction == 's'){
                        printf("%c",118);
                    }
                    else if (direction == 'd'){
                        printf("%c",62);
                    }

                }
            }
            else if ( i == k && j == m ){
                printf("@");
            }

            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


void main( int argc, int* argv[] )
{   if(argc == 4 ){

    sizeofsnake  = atoi(argv[3]) ;
    width = atoi(argv[2]) ;
    height = atoi(argv[1]) ;
    initRandom();
    toRange();
    snakeInitialization();
    directioninit();
    do {
        system("clear");
        draw();
        if(invalkey == 1 ){
            printf("\n invalid key \n");
            invalkey =0 ;
        }
        if(trytogoout ==1){
            printf("\n can't go outside the map \n ");
            trytogoout =0;
        }
        if(trytogoreverse == 1){
            printf("\n can't go backward \n");
            trytogoreverse= 0 ;
        }

        movement();
        moved = 0 ;

    }while(Game == 1 && lost == 0);
    system("clear");
    draw();
    if( lost == 1 ){
        printf("\n you lose :( ");
    }
    else {
        printf("\n you won ! :) ");
    }
    free(argv);


}

else {
    system("clear");
    printf("Incorrect amount of arguments . Program usage : \n ./snake <row_map> <col_map> <snake_length> ");

}


}
