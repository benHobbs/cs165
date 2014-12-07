#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
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

    std::vector< std::vector<char> > run(){
        createNextIteration();
        copyVector();
        return v;
    }

    void print(std::vector< std::vector<char> > v);
    std::vector< std::vector< char> > print(){ return v; };
    //void printV(){ print(v); };
    //void printNV(){ print(nv); };

    void createNextIteration(); //builds next iteration, based on this iteration
    int getNeighbors(int c, int r); //returns the number of living neighbors
    void copyVector(){ v = nv; };

private:
    int rows, columns;
    char live, dead;
    std::vector<std::vector<char> > v, nv;   //current, next generation
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

void GameOfLife::print(std::vector<std::vector<char> > v){
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

int main(){
	int cycles =  200;
	int h = 30;
	int w = 80;
	int wait = 1;	
	int waitMS = 75000;	//microsecs (1,000,000 = 1 sec)



	GameOfLife game(h,w);

	initscr();
	
	

	//game.setLiveDeadChars(ACS_DIAMOND,' ');
    	game.setLiveDeadChars('X',' '); //set symbols
    	game.initVectors();
    	game.setInitParams();
	
	//initscr();	//start curses mode
	//int ch;
	//nodelay(stdscr,TRUE);
	//while ((ch = getch())==ERR){
		

	for (int loop=0;loop<cycles;loop++){
		int ch;
		nodelay(stdscr,TRUE);
		if((ch=getch())==ERR){

		}
		else {
			endwin();
			return 0;
		}
	
		std::vector<std::vector<char> > v = game.run();
		move(0,40);
		printw("Game of Life\n");
    		
		for (int i = 0 ; i < w + 2 ; i++){
			addch('*');}
		addch('\n');
		for (int i = 0 ; i < v.size() ; i++){
			addch('*');
			for (int j = 0 ; j < v[i].size() ; j++){
				addch(v[i][j]);
			}
			addch('*');
			addch('\n');
		}
		for (int i = 0 ; i < w + 2 ; i++){
			addch('*');}
	
		refresh();
		//sleep(wait);
		usleep(waitMS);
	}
	
	
	getch();
	endwin();

	return 0;
}
