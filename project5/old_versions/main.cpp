#include <iostream>
#include <vector>

/******************************************************************************
 *  Rules:
 *      1.  Any live cell with < 2 live neighbors dies
 *      2.  Any live cell with 2 or 3 live neighbors lives on
 *      3.  Any live cell with > 3 live neighbors dies
 *      4.  Any dead cell with exactly 3 live neighbors becomes a live cell
******************************************************************************/


class GameOfLife
{
public:
    GameOfLife(int iColumns, int iRows){ columns = iColumns, rows = iRows; };


    void setLiveDeadChars(char cLive, char cDead){ live = cLive, dead = cDead; };
    void initVectors();
    void setInitParams();
    void setInitParams1();



    void print(std::vector<std::vector<char>> v);
    void printV(){ print(v); };
    void printNV(){ print(nv); };

    void createNextIteration(); //builds next iteration, based on this iteration
    int getNeighbors(int c, int r); //returns the number of living neighbors
    void copyVector(){ v = nv; };

private:
    int rows, columns;
    char live, dead;
    std::vector<std::vector<char>> v, nv;   //current, next generation
};


void GameOfLife::initVectors(){
    for (int i = 0 ; i < columns ; i++ ){
        v.push_back( std::vector<char>(rows,dead));
        nv.push_back( std::vector<char>(rows,dead));
    }
}

void GameOfLife::setInitParams(){
    v.at(5).at(5) = live;   //glider
    v.at(6).at(6) = live;
    v.at(6).at(7) = live;
    v.at(7).at(5) = live;
    v.at(7).at(6) = live;
    //setInitParams1();
}

void GameOfLife::print(std::vector<std::vector<char>> v){
    for (int row = 0 ; row < rows ; row++){
        for (int column = 0 ; column < columns ; column++){
            std::cout << v.at(column).at(row); }
        std::cout << std::endl; }
}


void GameOfLife::createNextIteration(){
    for (int row = 0 ; row < rows ; row++){
        for (int column = 0 ; column < columns ; column++){
            int neighbors = getNeighbors(column,row);   //get number of neighbors
            char position = v.at(column).at(row);

            if (position == live){                      //rules 1-3
                if (neighbors < 2){                         //rule 1
                    nv.at(column).at(row) = dead; }
                else if (neighbors > 1 && neighbors < 4){   //rule 2
                    nv.at(column).at(row) = live; }
                else if (neighbors > 3){                    //rule 3
                    nv.at(column).at(row) = dead; }
            }   //end if
            else if (position == dead && neighbors == 3){   //rule 4
                nv.at(column).at(row) = live;
            }   //end else if | conditional
        }   //end for loop column
    }   //end for loop row

}

int GameOfLife::getNeighbors(int c, int r){ //returns the number of living neighbors
    int negC = (c+(columns-1))%columns, posC = (c+1)%columns;
    int negR = (r+(rows-1))%rows, posR = (r+1)%rows, sum = 0;

    sum += (v.at(negC).at(negR) == live) ? 1 : 0;
    sum += (v.at(negC).at(r) == live) ? 1 : 0;
    sum += (v.at(negC).at(posR) == live) ? 1 : 0;
    sum += (v.at(c).at(negR) == live) ? 1 : 0;
    sum += (v.at(c).at(posR) == live) ? 1 : 0;
    sum += (v.at(posC).at(negR) == live) ? 1 : 0;
    sum += (v.at(posC).at(r) == live) ? 1 : 0;
    sum += (v.at(posC).at(posR) == live) ? 1 : 0;

    return sum;
}

void GameOfLife::setInitParams1(){
/*
    v.at(0).at(0) = live;   //block
    v.at(0).at(1) = live;
    v.at(1).at(0) = live;
    v.at(1).at(1) = live;

    v.at(7).at(3) = live;   //blinker
    v.at(7).at(4) = live;
    v.at(7).at(5) = live;

    v.at(13).at(3) = live;   //beacon
    v.at(13).at(4) = live;
    v.at(14).at(3) = live;
    v.at(14).at(4) = live;
    v.at(15).at(5) = live;
    v.at(15).at(6) = live;
    v.at(16).at(5) = live;
    v.at(16).at(6) = live;

    v.at(0).at(4) = live;   //block
    v.at(0).at(5) = live;
    v.at(19).at(4) = live;
    v.at(19).at(5) = live;

    v.at(19).at(9) = live;  //
    v.at(19).at(8) = live;
    v.at(18).at(9) = live;
    v.at(18).at(8) = live;
*/

    v.at(5).at(5) = live;   //glider
    v.at(6).at(6) = live;
    v.at(6).at(7) = live;
    v.at(7).at(5) = live;
    v.at(7).at(6) = live;



}

int main(){
    GameOfLife game(40,20);

    game.setLiveDeadChars('X',' '); //set symbols
    game.initVectors();
    game.setInitParams();


    for (int i = 0 ; i < 20 ; i++){
        game.printV();
        game.createNextIteration();
        game.copyVector();
        std::cout << "\n\n--------------------\n\n";
    }

}
