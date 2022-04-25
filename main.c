#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw(int[3][3]);
void drawAll(int[3][3], int[3][3], int[3][3]);
void drawFullBoard(int[9][3][3]);
int menu(int);
void startUltimateGame(int[9][3][3]);

void main(void){
    int m9[9][3][3];
    char *c[9];

    int i, j,k,f;
    int op; 

       for(k=0;k<9;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                m9[k][i][j]=-1;
            }
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
                startUltimateGame(m9);
            }else if(f==2){
                op=0;
            }
            break;
    }
    }while(op!=0);
    

 



    //m9[0][0][0]=1;
    //m9[1][1][1]=0;


    //drawAll(m,m2,m3);
   // drawFullBoard(m9);

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

//Draw the Ultimate Full Board
void drawFullBoard(int m[9][3][3]){
    int i,j,k;
    for(k=0;k<9;k++){
        for(i=0;i<3;i++){ //square
            for(j=0;j<3;j++){ //line
                if(m[k][i][j]==-1){
                    printf("| |");
                }else if(m[k][i][j]==0){
                    printf("|O|",m[k][i][j]);
                }else if(m[k][i][j]==1){
                    printf("|X|",m[k][i][j]);
                }
                
            }
         if(i!=2)
            printf("#");
        }
         printf("\n");
         if(k==2 || k==5 || k==8 || k==9){
            printf("# # # # # # # # # # # # # # #\n");
         }
    }
}
//draw 1
void draw(int m[9][3][3],int x, int y){
    int i, j;
    int pos;
    x=x-1;
    y=y-1;
    if(x==0){
        if(y==0){
            pos=0;
        }else if(y==1){
            pos=1;
        }else if(y==2){
            pos=2;
        }
    }else if(x==1){
        
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            printf("|%d|", m[x-1][[i][j]);
  
        }
        printf("\n");
    }
    printf("\n");
}

//draw all
void drawAll(int m[3][3], int m2[3][3], int m3[3][3]){
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            
            printf("|%d|", m[i][j]);
            printf("|%d|", m2[i][j]);
            printf("|%d|", m3[i][j]);
  
        }
        printf("\n");
    }
    printf("\n");
}

void startUltimateGame(int m[9][3][3]){
    int x,x1,y,y1;
   
    drawFullBoard(m);
    
    do{
        printf("\n -> X playing, chose the main square (ex: 1,2): ");
        scanf("%d,%d", &x, &y);
        if(x < 1 || x > 3 || y < 1 || y > 3){
            printf("\n -> Invalid square, try again\n");
        }
    }while(x < 1 || x > 3 || y < 1 || y > 3);
    
    do{
      printf("\n -> X playing, chose the position to play (Curret Square (%d,%d)): ",x,y);
      scanf("%d,%d", &x1, &y1);  
      if(x1 < 1 || x1 > 3 || y1 < 1 || y1 > 3){
            printf("\n -> Invalid square, try again\n");
        }
    }while(x1 < 1 || x1 > 3 || y1 < 1 || y1 > 3);

    
}

