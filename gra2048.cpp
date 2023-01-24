#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;
int punkty=0;
int tab[4][4];
int dirLine[]={1,0,-1,0};                                            //dol, prawo, gora, lewo
int dirColumn[]={0,1,0,-1};
pair<int,int>genWolnaPozycja();
void dodajKawalek();
bool czyMoznaRuszyc(int line,int column,int nextLine,int nextColumn);
void newGame();
void printInter();
void zastosujRuch(int kierunek);
bool isGameOver();
bool gameWon();
int main(){                                                                         //MAIN
    srand(time(NULL));
    int commandToDir[128];
    commandToDir['s']=0;
    commandToDir['d']=1;
    commandToDir['w']=2;
    commandToDir['a']=3;
    newGame();
    while(1){
        printInter();
        char znak;
        cin>>znak;
        if(znak=='n'){newGame();}
        else if(znak=='q'){break;}
        else{
            int currentDirection = commandToDir[znak];
            zastosujRuch(currentDirection);
        }
        if(isGameOver()){cout<<"Game Over\t"<<"punkty:"<<punkty; return 0;}
        else if(gameWon()){cout<<"YOU WIN!!!\t"<<"punkty:"<<punkty; return 0;}
    }
return 0;
}                                                                                   //END_MAIN
void newGame(){                                                                     //new_Game
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            tab[i][j]=0;
        }
    }
    dodajKawalek();
}
void printInter(){                                                                     //printInterface
    system("cls");
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
           if(tab[i][j]==0){cout<<setw(4)<<".";}
           else{cout<<setw(4)<<tab[i][j];}
        }
        cout<<endl;
    }
    cout<<"n-nowa gra, w-gora, s-dol, a-lewo, d-prawo, q-wyjscie"<<endl;
    cout<<"punkty:"<<punkty<<endl;
}
bool czyMoznaRuszyc(int line,int column,int nextLine,int nextColumn){                        //czyMoznaRuszyc
    if(nextLine<0 || nextColumn<0 || nextLine>=4 || nextColumn>=4 || (tab[line][column]!=tab[nextLine][nextColumn] && tab[nextLine][nextColumn]!=0)){
        return false;
    }
    return true;
}
void zastosujRuch(int kierunek){                                                          //zastosujRuch
    int startLine=0, startColumn=0,lineStep=1,columnStep=1;
    if(kierunek==0){
        startLine=3;
        lineStep=-1;
    }
    if(kierunek==1){
        startColumn =3;
        columnStep=-1;
    }
    int mozliwyRuch, czyDodacKawalek=0;
    do{
        mozliwyRuch = 0;
        for (int i = startLine; i >= 0 && i < 4; i += lineStep) {
            for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
                int nextI = i + dirLine[kierunek], nextJ = j + dirColumn[kierunek];
                if (tab[i][j] && czyMoznaRuszyc(i, j, nextI, nextJ)) {
                    if(tab[nextI][nextJ]==tab[i][j]){punkty+=tab[i][j]*2;}
                    tab[nextI][nextJ] += tab[i][j];
                    tab[i][j]=0;
                    mozliwyRuch = czyDodacKawalek=1;
                }
            }
        }

    }while(mozliwyRuch);
    if(czyDodacKawalek){dodajKawalek();}
}
pair<int,int>genWolnaPozycja(){                                              //pair_genWolnaPozycja
    int wolna=1,line,column;
    while(wolna){
        line = rand() % 4;
        column = rand() % 4;
        if(tab[line][column]==0){wolna=0;}
    }
    return make_pair(line,column);
}
void dodajKawalek(){                                                                        //dodajKawalek
    pair<int, int>pos = genWolnaPozycja();
    tab[pos.first][pos.second]=2;
}
bool isGameOver(){                                                                          //GameOver
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(tab[i][j]==0){return false;}
            if(i != 3 && tab[i][j]==tab[i+1][j]){return false;}
            if(j != 3 && tab[i][j]==tab[i][j+1]){return false;}

        }

    }
    return true;

}
bool gameWon(){                                                                         //gameWin
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tab[i][j]==2048){return true;}
        }
    }
    return false;
}
