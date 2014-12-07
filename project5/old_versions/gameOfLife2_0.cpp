/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/27/2014
 ** Lab/Project#:   Project 5:  The Game of Life
 ** Filename:       ...
 ** Overview: 	    Builds a program that runs the game of life:
 **
 **                 Rules:
 **                     1.  Any live cell with < 2 live neighbors dies
 **                     2.  Any live cell with 2 or 3 live neighbors lives on
 **                     3.  Any live cell with > 3 live neighbors dies
 **                     4.  Any dead cell with exactly 3 live neighbors becomes a live cell
 **
 ** References:         Technical Details
 **                 http://en.wikipedia.org/wiki/Conway's_Game_of_Life
 **
 **                     Coding
 **                 http://www.dreamincode.net/forums/topic/19998-class-method-print-2d-vector/
 **                 http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/scanw.html
 **
***************************************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <ncurses.h>
#include <unistd.h>
#include <time.h>


class GameOfLife
{
public:
    GameOfLife(int iColumns, int iRows){ columns = iColumns, rows = iRows; };

    void setLiveDeadChars(char cLive, char cDead){ live = cLive, dead = cDead; };
    void initVectors();
    void setInitParams();
    void placeSeedValue(int c, int r);

    std::vector<std::vector<char> > run();
    void createNextIteration(); //builds next iteration, based on this iteration
    int getNeighbors(int c, int r); //returns the number of living neighbors
    void copyVector(){ v = nv; };

private:
    int rows, columns;
    char live, dead;
    std::vector<std::vector<char> > v, nv;   //current, next generation
};

/**************************************************************************************************
 ** Function:       GameOfLife::initVectors()
 ** Description:    Initiates the v and nv vectors to the specified dead cell chars.
 *************************************************************************************************/
void GameOfLife::initVectors(){
    for (int i = 0 ; i < columns ; i++ ){
        v.push_back( std::vector<char>(rows,dead));
        nv.push_back( std::vector<char>(rows,dead));
    }
}

/**************************************************************************************************
 ** Function:       GameOfLife::initVectors()
 ** Description:    Initiates the v and nv vectors to the specified dead cell chars.
 *************************************************************************************************/
void GameOfLife::setInitParams(){
    int c, r;
    std::string filename = "seeds/acorn";

    std::ifstream ifs(filename.c_str());

    while (ifs >> c >> r){
        placeSeedValue(c,r);
    }
}

/**************************************************************************************************
 ** Function:       GameOfLife::placeSeedValue(int c, int r)
 ** Description:    Places values from seed file into v.
 *************************************************************************************************/
void GameOfLife::placeSeedValue(int c, int r){
    v.at(c).at(r) = live;
}

/**************************************************************************************************
 ** Function:       GameOfLife::initVectors()
 ** Description:    Initiates the v and nv vectors to the specified dead cell chars.
 *************************************************************************************************/
std::vector<std::vector<char> > GameOfLife::run(){
    createNextIteration();
    copyVector();
    return v;
}

/**************************************************************************************************
 ** Function:       GameOfLife::createNextIteration()
 ** Description:    Takes the current iteration v and uses it and the 4 rules of the game to
 **                 create the next iteration of the cycle in vector nv.
 *************************************************************************************************/
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

/**************************************************************************************************
 ** Function:       int GameOfLife::getNeighbors(int c, int r)
 ** Description:    Returns the number of living neighbors given an c,r coordinate.  Uses mod to
 **                 'wrap' around the edges of the board.
 *************************************************************************************************/
int GameOfLife::getNeighbors(int c, int r){
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

#include <string.h>
#include <stdlib.h>

void runGame(GameOfLife game,int scol, int waitMS, int cycles);
void printMenu(int mrow, int mcol);

int main(int argc, char* argv[]){

	int waitMS = atoi(argv[1])

	int h = 50,  w = 130, cycles =  200; // waitMS = 125000;	//microsecs (1,000,000 = 1 sec)
	int row, col;
	
	initscr();	//start nCurses
	noecho();
	getmaxyx(stdscr,row,col);	//get size of terminal
	
	int mrow = 3 + h/2 - 3, mcol = (col - 13)/2;	//row and column for menu
	int scol = (col - w) / 2;						//start column for board
	
	char title[]="Game of Life";
	mvprintw(0,(col - strlen(title))/2,"%s",title);	//print header menu
	mvprintw(0,(col - 10),"%d,%d",row,col);			//print header menu
	mvprintw(0,2,"0 of %d",cycles);					//print header menu
	if(row > 59 && col > 149){
		GameOfLife game(h,w);			//Build game of life object
		
		game.setLiveDeadChars('X',' '); //set symbols
		game.initVectors();				//initialize vectors
		
		char ch;
		do{
			printMenu(mrow, mcol);
			switch(ch = getch()){
			case 'r':{
				char r[]="rand seed";
				game.setInitParams();		//set paramaters
				runGame(game, scol, waitMS, cycles);
				//mvprintw(mrow+8,mcol,"%s",r);
				break;}
			case 'p':{
				//char p[]="pick preset";
				//mvprintw(mrow+8,mcol,"%s",p);
				break;}
			case 's':{	
				break;}
			case 'e':{
				break;}
			default:
				break;
			}
		}while(ch != 'e');	
	}
	else{	//exit if screen too small
		char err[]="Please resize the screen to at least 60 rows x 150 columns.";
		mvprintw(row/2,(col - strlen(err))/2,"%s",err);
		getch();
		endwin();
		return 0;
	}
	
	endwin();

	return 0;
}

void printMenu(int mrow, int mcol){
	char menuTitle[]="    menu";
	char menuRand[]="[r]andom seed";
	char menuPreset[]="[p]ick preset";
	char menuSettings[]="[s]ettings";
	char menuExit[]="[e]xit";
	
	mvprintw(mrow,mcol,"%s",menuRand);
	mvprintw(mrow+2,mcol,"%s",menuPreset);
	mvprintw(mrow+4,mcol,"%s",menuSettings);
	mvprintw(mrow+6,mcol,"%s",menuExit);
}

void runGame(GameOfLife game, int scol, int waitMS, int cycles){
	int currentCycle = 0;
	
	for (int loop=0;loop<cycles;loop++){	//run the # of cycles
		char ch;
		mvprintw(0,2,"%d of %d",currentCycle,cycles);
		currentCycle++;
		nodelay(stdscr,TRUE);
		if((ch=getch())==ERR){}
		else {
			break;
		}
	
		std::vector<std::vector<char> > v = game.run();
		
		for (int i = 0 ; i < v.size() ; i++){
			move(4+i,scol);
			for (int j = 0 ; j < v[i].size() ; j++){
				addch(v[i][j]);
			}
			addch('\n');
		}
		refresh();
		usleep(waitMS);
	}
}


	/*
	move(drop,scol);
	for (int i = 0 ; i < (w + 2) / 2 ; i++){
		addch('*');
		addch(' ');
	}
	addch('*');
	for (int i = 1 ; i <= (h + 1) ; i++){
		mvaddch(drop+i,(col - (w+2)) / 2,'*');
		mvaddch(drop+i,(col - ((col -(w+2))/2)),'*');
	}
	move(drop+2+h,(col - (w+2))/2);
	for (int i = 0 ; i < (w + 2) / 2 ; i++){
		addch('*');
		addch(' ');
	}
	addch('*');
	*/
