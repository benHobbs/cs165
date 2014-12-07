#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

int main(){
	int w = 100;
	int h = 50;
	int wait = 1;	
	int waitMS = 125000;	//microsecs (1,000,000 = 1 sec)
	char arr[h][w];

	initscr();	//start curses mode
	for (int loop=0;loop<w;loop++){
		for (int i=0;i<h;i++){
			for (int j=0;j<w;j++){
				arr[i][j]='-';
			}
			if(i%2==0){arr[i][loop]='0';}
			else{arr[i][(w-1)-loop] = '0';}
		}
		
		move(0,40);
		printw("Sup");

		for (int i=0;i<h;i++){
			move(i+1,10);	
			for (int j=0;j<w;j++){
				addch(arr[i][j]);
			}	
			addch('\n');
		}

	//printw("Hello World@");
		refresh();
		//sleep(wait);
		usleep(waitMS);
		
	}

	getch();
	
	endwin();

	//std::cout << "Hello World@" << std::endl;

	return 0;
}
