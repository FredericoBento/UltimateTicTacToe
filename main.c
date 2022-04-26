#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int menu(int);
void startUltimateGame(int[9][3][3],int[3][3],int[3][3]);
void draw(int[9][3][3],int, int);
void drawAll(int[3][3], int[3][3], int[3][3]);
void drawFullBoard(int[9][3][3]);
int convertCoordinates(int, int);
int checkSquareWin(int[9][3][3], int[3][3], int[3][3],int);

  
void main(void){
    int m9[9][3][3];
    int xWonSquares[3][3],oWonSquares[3][3];

    int i, j,k,f;
    int op; 

       for(k=0;k<9;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                m9[k][i][j]=-1;
            }
        }
    }
    
    int count=1;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                xWonSquares[i][j]=0;
                oWonSquares[i][j]=0;
            }
        }

    do{
        op = menu(op);
    switch(op){
        case 1: 
            printf("\n## ULTIMATE TICTACTOE ##\n");
            printf("\n## 1. Play ##\n");
            printf("\n## 2. Return ##\n");
            printf("\n## Choose an option: ");
            scanf("%d", &f);
            if(f==1){
                startUltimateGame(m9,xWonSquares,oWonSquares);
            }else if(f==2){
                op=0;
            }
            break;
    }
    }while(op!=3);
    

}

int menu(int op){
    do{
        printf("\n## GAME START ##\n");
        printf("- 1 - Ultimate Tic Tac Toe\n");
        printf("- 2 - Tic Tac Toe\n");
        printf("- 3 - Exit -\n");
        printf("- Choose an option: ");
        scanf("%d", &op);
    }while(op < 1 || op > 3);
  
    return op;

}

void startUltimateGame(int m[9][3][3],int xWonSquares[3][3],int oWonSquares[3][3]){
    int x,x1,y,y1;
    int flag=0,square,gameEnd=0,lastPlay=0,squareWin;
    char player = 'X';
    do{
        drawFullBoard(m);
        printf("\n");
        do{
            flag=0;
            if(lastPlay==0){
                lastPlay=1;
                printf("\n -> %c playing, chose the main square (ex: 1,2): ",player);
                scanf("%d,%d", &x, &y);
                if(x < 1 || x > 3 || y < 1 || y > 3){
                    printf("\n -> Invalid square, try again\n");
                    flag=1;
                }else{
                    if(xWonSquares[x-1][y-1]==1 || oWonSquares[x-1][y-1]==1){
                        printf("\n -> Invalid square, that square is completed try again\n");
                        flag=1;
                    }
                }
            }else {
                if(xWonSquares[x-1][y-1]==1 || oWonSquares[x-1][y-1]==1){
                flag=1;
                }else{
                x=x1;
                y=y1;
            }     
                }
                
        }while(flag!=0);
        
        do{
        flag=0;
        draw(m,x,y);
        printf("\n -> %c playing, chose the position to play (Curret Square (%d,%d)): ",player,x,y);
        scanf("%d,%d", &x1, &y1);  
        if(x1 < 1 || x1 > 3 || y1 < 1 || y1 > 3){
                printf("\n -> Invalid square, try again\n");
                flag=1;
        }else {
            square = convertCoordinates(x,y);
            if(m[square][x1-1][y1-1]!=-1){
                    printf("\nThat position is occupied!");
                    flag=1;
            }else{
                if(player=='X'){
                    m[square][x1-1][y1-1]=1;
                }else {
                    if(player=='O'){
                        m[square][x1-1][y1-1]=0;
                    }
                }
                lastPlay=1;
                flag=0;
            }
        }
        }while(flag!=0);
        printf("\nTa A SAIR %c\n",player);
        squareWin = checkSquareWin(m,xWonSquares,oWonSquares,square);
        if(squareWin==1){
            printf("\n%c won a square",player);
        }
        if(player='X'){
            player='O';
        }else {
            player='X';
        }

    }while(gameEnd!=1);
  }

//Bad made function to draw the full board
void drawFullBoard(int m[9][3][3]){
    int k=0,i=0,j=0,counter=0,last=k,saved=0;
    int stop=0;
    while(stop!=1){
        for(j=0;j<3;j++){
            
            if(m[k][i][j]==-1){
                printf("| ");
            }else if(m[k][i][j]==0){
                printf("|o");
            }else if(m[k][i][j]==1){
                printf("|x");
            }
            
           //printf("m|%d|[%d][%d] ",k,i,j);
        }
        k++;
        if(k!=0 && k%3==0){
            last=k;
            k=saved;
            printf("|\n");
            counter++;
            i++;
            if(counter%3==0){
                if(counter!=9)
                    printf("# # # # # # # # # # # # # # \n");
                k=last;
                i=0;
                saved=last;
               
            }
             
        }else printf("| # ");
        if(counter==9){
            stop=1;
        }
        
   }

}
    

//draw 1
void draw(int m[9][3][3],int x, int y){
    int i, j;
    int pos = convertCoordinates(x,y); 
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
             if(m[pos][i][j]==-1){
                    printf("| |");
                }else if(m[pos][i][j]==0){
                    printf("|O|");
                }else if(m[pos][i][j]==1){
                    printf("|X|");
                }
  
        }
        printf("\n");
    }
    printf("\n");
}

int convertCoordinates(int x, int y){
    int pos;
        
    if(x==1){
        if(y==1){
            pos=0;
        }else if(y==2){
            pos=1;
        }else if(y==3){
            pos=2;
        }
     }else if(x==2){
            if(y==1){   
                pos=3;
            }else if(y==2){
                pos=4;
            }else if(y==3){
                pos=5;
            }
    }else if(x==3){
            if(y==1){
                pos=6;
            }else if(y==2){
                pos=7;
            }else if(y==3){
                pos=8;
            }
        }
       
    return pos;
}

//Check if someone won the game
int checkWin(int m[9][3][3],int xWonSquares[3][3],int oWonSquares[3][3]){

}

//Check if someone won a square
int checkSquareWin(int m[9][3][3],int xWonSquares[3][3],int oWonSquares[3][3],int square){
    int k,i,j;
    int won=0;
    int winner=-1;
    for(i=0;i<3;i++){
        //checks horizontal lines
        if(m[square][i][0]!=-1){
            if(m[square][i][0]==m[square][i][1] && m[square][i][1]==m[square][i][2]){
                won=1;
                winner=m[square][i][0];
            }else{
                //check vertical lines
                if(m[square][0][i]==m[square][1][i] && m[square][1][i]==m[square][2][i]){
                    won=1;
                    winner=m[square][0][i];
                }else{
                
                }
            }
        }
    }
    //check left diagonal line
    if(m[square][0][0]!=-1){
        if(m[square][0][0]==m[square][1][1] && m[square][1][1]==m[square][2][2]){
            won=1;
            winner=m[square][0][0];
        }
    }else if(m[square][0][2]!=-1){
        //check right diagonal line
        if(m[square][0][2]==m[square][1][1] && m[square][1][1]==m[square][2][0]){
            won=1;
            winner=m[square][0][2];
        }
    }

    if(won!=0){
        return 1;
    }else return 0;
    
}