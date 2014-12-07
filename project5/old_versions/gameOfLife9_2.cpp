/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/27/2014
 ** Lab/Project#:   Project 5:  The Game of Life
 ** Filename:       ...
 ** Overview: 	    Builds a program that runs the game of life:
 **
 **                 Rules:
 **                     1.  Any live cell with < 2 live neighbours dies
 **                     2.  Any live cell with 2 or 3 live neighbours lives on
 **                     3.  Any live cell with > 3 live neighbours dies
 **                     4.  Any dead cell with exactly 3 live neighbours becomes a live cell
 **
 ** References:         Technical Details
 **                 http://en.wikipedia.org/wiki/Conway's_Game_of_Life
 **
 **                     Coding
 **                 http://www.dreamincode.net/forums/topic/19998-class-method-print-2d-vector/
 **                 http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/scanw.html
 **			http://hughm.cs.ukzn.ac.za/~murrellh/os/notes/ncurses.html#attribute
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
void printMenu(int mrow, int col);
bool runPresetMenu(GameOfLife game, std::string &fileName, int mrow, int col);
void printSettings(int waitTime, int mrow, int col);
void runGame(GameOfLife game, int scol, int waitMS, int cycles);


int main(int argc, char* argv[]){
	
	bool small = false;	//if true, program run with the -s mod
	int h, w;			//height and width of the board
	int cycles=5000;	//number of cycles to run the current seed
	int row, col;		//size of the terminal
	int waitMS;			//time to wait in micro seconds (1,000,000 = 1 sec) between cycles
	
	parseEntryArgs(argc, argv, h, w, waitMS, small);	//parse cmd args
	
	initscr();		//start nCurses	
	noecho();		//set no echo
	curs_set(0);	//hide cursor	
	
	getmaxyx(stdscr,row,col);	//get size of terminal	
	int menuStartRow = 3 + (h/2);			//start row for menus (half way down board)		
	int boardStartColumn = (col - w) / 2;	//start column for board
	
	bool bpass = false;	//set to false until terminal is correct size
	
	if (small == true && row > 25 && col > 81){		//going to run with -s
		bpass = true;
	}
	else if(small == false && row > 53 && col > 151){	//going to run without -s
		bpass = true;
	}
	
	if(bpass == true){	//terminal is correct size
		char mch;
		do{
			clear();
			printHeader(col,row);
			printMenu(menuStartRow, col);
			refresh();
			
			GameOfLife game(h, w);				//initialize gameOfLife object
			game.setLiveDeadChars('X',' ');		//set symbols
			game.initVectors();					//setup vectors

			switch(mch = getch()){
			case 'r':{	//generate random seed
				game.setInitParamsRandom();				//set seed to random
				runGame(game, boardStartColumn, waitMS, cycles);	//run seed
				break;}
			case 'u':{	//use presets
				std::string fileName = "seeds/";
				clear();
				printHeader(col,row);
				if (runPresetMenu(game, fileName, menuStartRow, col)==true){
					game.setInitParams(fileName);
					runGame(game, boardStartColumn, waitMS, cycles);
				}
				break;}
			case 's':{
				clear();
				printHeader(col,row);
				printSettings(waitMS, menuStartRow, col);
				break;}
			case 'e':{
				break;}
			default:
				break;
			}
		}while(mch != 'e');	
	}
	else{	//terminal is too small
		curs_set(1);	//show cursor
		endwin();
		
		std::cout << "\nPlease resize the terminal to at least 54 rows x 152 columns."
			  << "\nYour current terminal size is:"
			  << "\n\tRows: " << row << "\n\tColumns: " << col
			  << "\nAlternatively, run the program with cmd -s"
			  << " (minimum terminal size: 26 rows X 82 columns)"				
			  << "\n\t./GameOfLife -s" << std::endl;
				  
		return 1;
	}

	curs_set(1);	//show cursor
	endwin();
	
	return 0;
}

/**************************************************************************************************
 ** Function:       void parseEntryArgs(int argc, char* argv[], int &h, int &w, int &waitMS)
 ** Description:    Parses the command line args and sets up the defaults
 *************************************************************************************************/
void parseEntryArgs(int argc, char* argv[], int &h, int &w, int &waitMS, bool &small){
    h = 50, w = 130, waitMS = 250000;

    for (int i = 0 ; i < argc ; i++){
        std::string str = argv[i];
        if(str=="-s" ){
            h = 22, w = 80, small = true;
        }   //end if
        else if(str == "-w"){
            int val = atoi(argv[i+1]);
            if(val > 25000 && val < 10000000){
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
 ** Function:       void printMenu(int mrow, int col)
 ** Description:    Builds the menu
 *************************************************************************************************/
void printMenu(int mrow, int col){
	int menuWidth = 20;
	int menuStartColumn = (col - menuWidth)/2;
	
	char menuRand[]=	"[r]andom seed ";
	char menuPreset[]=	"[u]se preset  ";
	char menuSettings[]="[s]ettings    ";
	char menuExit[]=	"[e]xit        ";
	
	mvprintw(mrow-1,menuStartColumn,"********************");
	mvprintw(mrow,menuStartColumn,  "*  %s  *",menuRand);
	mvprintw(mrow+1,menuStartColumn,"*  %s  *",menuPreset);
	mvprintw(mrow+2,menuStartColumn,"*  %s  *",menuSettings);
	mvprintw(mrow+3,menuStartColumn,"*  %s  *",menuExit);
	mvprintw(mrow+4,menuStartColumn,"********************");
}

/**************************************************************************************************
 ** Function:       void printPresetsMenu(int mrow, int mcol)
 ** Description:    Builds the menu
 *************************************************************************************************/
bool runPresetMenu(GameOfLife game, std::string &fileName, int mrow, int col){
		int menuWidth = 0;
		int menuStartColumn = (col - menuWidth)/2;
		
		std::vector<std::string> files = game.getSeedFileNames();
		int height = files.size() + 4;		//set height of menu
		
		for(int i= 0 ; i < files.size() ; i++){	//set width of menu
			std::string str = files[i];
			if(str.length() > menuWidth){ menuWidth = str.length(); }
		}
		
		menuWidth += 4;
		
		std::string edge = "";
		for(int i = 0 ; i < menuWidth+5 ; i++){ edge += "*"; }
		
		mvprintw(mrow-1,menuStartColumn,"%s",edge.c_str());	//print top edge
		int i = 0;		
		for(i=0;i < files.size();i++) {			//print each item
			std::string str = files[i];
			mvprintw(mrow+i,menuStartColumn,"* [%c] %s",char(i+97),str.c_str());
			for (int j = 0 ; j < (menuWidth - 2 - str.length()) ; j++){
				addch(' ');
			}
			addch('*');
		}
		mvprintw(mrow+i,menuStartColumn,"* [z] back");
		for (int j = 0 ; j < (menuWidth - 6) ; j++){
			addch(' ');
		}		
		addch('*');
		mvprintw(mrow+i+1,menuStartColumn,"%s",edge.c_str());	//print top edge		
		
		char mch;
		do{
			mch = getch();
			int imch = int(mch) - 97;
			if(mch == 'z'){ return false; }
			else if (imch < i && imch > -1){
 				fileName += files[imch];
				return true;
		 	}
		}while(mch != 'z');
}

/**************************************************************************************************
 ** Function:       void runGame(GameOfLife game, int scol, int waitMS, int cycles)
 ** Description:    Runs the seed to cycles iterations, with waitMS wait time.
 *************************************************************************************************/
void printSettings(int waitTime, int mrow, int col){
	int menuWidth = 40;
	int menuStartColumn = (col - menuWidth)/2;
	
	std::string line1 = "1                                   ";
	std::string line2 = "2                                   ";
	std::string line3 = "3                                   ";
	std::string line4 = "Hit any key to return to main menu. ";
	
	mvprintw(mrow-1,menuStartColumn,"****************************************");
	mvprintw(mrow,menuStartColumn,  "*  %s  *",line1.c_str());
	mvprintw(mrow+1,menuStartColumn,"*  %s  *",line2.c_str());
	mvprintw(mrow+2,menuStartColumn,"*  %s  *",line3.c_str());
	mvprintw(mrow+3,menuStartColumn,"*  %s  *",line4.c_str());
	mvprintw(mrow+4,menuStartColumn,"********************");
	
	getch;
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
			nodelay(stdscr,FALSE);
			return;
		}
	
		std::vector<std::vector<char> > v = game.run();
		
		for (int i = 0 ; i < v.size() ; i++){
			move(4+i,scol);
			addch('*');
			for (int j = 0 ; j < v[i].size() ; j++){
				addch(v[i][j]);
			}
			addstr("*\n");
			//addch('\n');
		}
		refresh();
		usleep(waitMS);
	}
	nodelay(stdscr,FALSE);
}
