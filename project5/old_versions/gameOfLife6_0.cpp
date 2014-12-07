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
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <dirent.h>
#include <algorithm>


class GameOfLife
{
public:
    GameOfLife(int iColumns, int iRows){ columns = iColumns, rows = iRows; };

    void setLiveDeadChars(char cLive, char cDead){ live = cLive, dead = cDead; };
    void initVectors();
    void setInitParams(std::string filename);
    void setInitParamsRandom();
    std::vector<std::string> getSeedFileNames();
    void placeSeedValue(int c, int r);

    std::vector<std::vector<char> > run();
    void createNextIteration(); //builds next iteration, based on this iteration
    int getNeighbors(int c, int r); //returns the number of living neighbors
    void copyVector(){ v = nv; };

private:
    int rows, columns;
    char live, dead;
    std::vector<std::vector<char> > v, nv;   //current, next generation
    std::vector<std::string> seedNames;	//seed files available	
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
 ** Function:       std::vector<std::string> GameOfLife::getSeedFileNames()
 ** Description:    Returns vector of current seed files
 *************************************************************************************************/
std::vector<std::string> GameOfLife::getSeedFileNames(){
	std::string path = "seeds";		//look in the seeds folder
	std::vector<std::string> files;	//list of files
	
	DIR* dir;
	dirent* pdir;
	
	dir = opendir(path.c_str());
	
	while (pdir = readdir(dir)){
		std::string str = pdir->d_name;		
		if (str.at(0) != '.'){	//make sure valid file
			files.push_back(pdir->d_name);}
	}

	std::sort(files.begin(),files.end());	//sort files

	return files;
}

/**************************************************************************************************
 ** Function:       GameOfLife::initVectors()
 ** Description:    Initiates the v and nv vectors to the specified dead cell chars.
 *************************************************************************************************/
void GameOfLife::setInitParams(std::string filename){
	int c, r;

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
void GameOfLife::setInitParamsRandom(){
	srand(time(NULL));
	for (int c = 0 ; c < columns ; c++ ){
		for (int r = 0 ; r < rows ; r++){
			if((rand() % 3 + 1) == 2){ v.at(c).at(r) = live; }
		}	//end for loop r
	}	//end for loop c
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

/**************************************************************************************************
 ** Main and associated functions
 *************************************************************************************************/

void parseEntryArgs(int argc, char* argv[], int &h, int &w, int &waitMS, bool &small);
void printHeader(int col, int row);
void printMenu(int mrow, int mcol);
void printPresetMenu(int mrow, int mcol);
void runGame(GameOfLife game,int scol, int waitMS, int cycles);


int main(int argc, char* argv[]){
	
	bool small = false;
	char ch;
	int h, w, cycles=5000, row, col, waitMS, menuW=20;	//waitMS is in ms (1,000,000 = 1 sec)

	parseEntryArgs(argc, argv, h, w, waitMS, small);
	
	initscr();	//start nCurses
	noecho();	//set no echo
	getmaxyx(stdscr,row,col);	//get size of terminal
	
	int mrow = 3 + h/2 - 3, mcol = (col - menuW)/2;	//row and column for menu
	int scol = (col - w) / 2;						//start column for board
	
	printHeader(col,row);
	
	if(row > 59 && col > 149 || small == true){	//check screen size
		do{
			GameOfLife game(h,w);		//build game of life object
			game.setLiveDeadChars('X',' ');	//set symbols
			game.initVectors();		//initialize vectors

			printMenu(mrow, mcol);
			printHeader(col,row);
			switch(ch = getch()){
			case 'r':{
				game.setInitParamsRandom();				//set seed to random
				runGame(game, scol, waitMS, cycles);	//run seed
				break;}
			case 'p':{
				
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

/**************************************************************************************************
 ** Function:       void parseEntryArgs(int argc, char* argv[], int &h, int &w, int &waitMS)
 ** Description:    Parses the command line args and sets up the defaults
 *************************************************************************************************/
void parseEntryArgs(int argc, char* argv[], int &h, int &w, int &waitMS, bool &small){
    h = 50, w = 130, waitMS = 75000;

    for (int i = 0 ; i < argc ; i++){
        std::string str = argv[i];
        if(str=="-s" ){
            h = 22, w = 80, small = true;
        }   //end if
        else if(str == "-w"){
            int val = atoi(argv[i+1]);
            if(val > 25,000 && val < 10,000,000){
                waitMS = val;
            }   //end if | conditional
        }   //end else if | conditional
    }   //end for loop i
}

/**************************************************************************************************
 ** Function:       void printHeader(int col, int row)
 ** Description:    Print Header (cycles, title, screen size)
 *************************************************************************************************/
void printHeader(int col, int row){
	char title[]="Game of Life";
	mvprintw(0,(col - strlen(title))/2,"%s",title);	//print header menu
	mvprintw(0,(col - 10),"%d,%d",row,col);			//print header menu
	mvprintw(0,2,"0 of 5000    ");						//print header menu
}

/**************************************************************************************************
 ** Function:       void printMenu(int mrow, int mcol)
 ** Description:    Builds the menu
 *************************************************************************************************/
void printMenu(int mrow, int mcol){	//width should be 16
	char menuRand[]=	"[r]andom seed ";
	char menuPreset[]=	"[u]se preset  ";
	char menuSettings[]=    "[s]ettings    ";
	char menuExit[]=	"[e]xit        ";
	
	mvprintw(mrow-2,mcol,"********************");
	mvprintw(mrow-1,mcol,"*                  *");
	mvprintw(mrow,mcol,  "*  %s  *",menuRand);
	mvprintw(mrow+1,mcol,"*                  *");
	mvprintw(mrow+2,mcol,"*  %s  *",menuPreset);
	mvprintw(mrow+3,mcol,"*                  *");
	mvprintw(mrow+4,mcol,"*  %s  *",menuSettings);
	mvprintw(mrow+5,mcol,"*                  *");
	mvprintw(mrow+6,mcol,"*  %s  *",menuExit);
	mvprintw(mrow+7,mcol,"*                  *");
	mvprintw(mrow+8,mcol,"********************");
}

/**************************************************************************************************
 ** Function:       void printPresetsMenu(int mrow, int mcol)
 ** Description:    Builds the menu
 *************************************************************************************************/
void printPresetMenu(int mrow, int mcol){	//width should be 16
		//game.setInitParams("seeds/diehard.txt");	//set paramaters
		//runGame(game, scol, waitMS, cycles);		//run seed
}

/**************************************************************************************************
 ** Function:       void runGame(GameOfLife game, int scol, int waitMS, int cycles)
 ** Description:    Runs the seed to cycles iterations, with waitMS wait time.
 *************************************************************************************************/
void runGame(GameOfLife game, int scol, int waitMS, int cycles){
	int currentCycle = 1;
	
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