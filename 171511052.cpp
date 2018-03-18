/*
Description	: Body dari modul yang dikerjakan oleh Jays
Author		: Jays - 171511052
*/

#include "header\171511052.h"
#include "game.h"

// body modul

//Input/Output
void opengraph() {
	initwindow(840, 620, "Avontuur - An 8 Puzzle Game", 100, 50);
}

void escape() {
	char close;
	
	while (close!=KEY_ESCAPE) {
		close=getch();
	}
}


// yg ini gabisa backspace
void nameinput(int x, int y, char *title, int spacing, char name[5], int font, int direction, int charsize) {
	int i, conv = 0;
	char temp;
	
//	for (i=0; i<4; i++) {
//		name[i] = ' ';
//	}

	settextstyle(font, direction, charsize);
	outtextxy(x, y, title);
	
//	fflush(stdin);
	i = 0;
	while (i<4) {
		do {
			temp = getch();
			conv = int(temp);
		} while (!((conv>=97 && conv<=122) || (conv>=65 && conv<=90)));
		
		printf("\n%c %d", temp, conv);
		
		if (conv>=97 && conv<=122) {
//			temp = char(temp - 32);
			conv = conv - 32;
		}
		
//		if ((conv>=65 && conv<=90)) {
			name[i] = char(conv);
			i++;
//		}
		
		outtextxy(x+spacing, y, name);
	}
	
}

// yg ini bisa backspace
//void nameinput(int x, int y, char *title, int spacing, char name[5], int font, int direction, int charsize) {
//	int i;
//	
//	settextstyle(font, direction, charsize);
//	outtextxy(x, y, title);
//	
////	for (i=0; i<6; i++) {
////		name[i] = "\0";
////	}
//	
//	i = 0;
//	while (i<5) {
//		if (i<4) {
//			do {
//				name[i] = getch();
//			} while (!(((name[i]>=97 && name[i]<=122) || (name[i]>=65 && name[i]<=90)) || (name[i]==8)));
//			if (name[i]>=97 && name[i]<=122) {
//				name[i] = name[i] - 32;
//			}
//		} else if (i==4) {
//			do {
//				name[i] = getch();
//			} while (!(name[i]==8 || name[i]==13));
//		}
//		
//		if (name[i]==8) {
//			name[i] = ' ';
//			if (i>0) {
//				name[i-1] = ' ';
//				i--;
//			}
//		}
//		if (name[i]==13) {
//			break;
//		}
//		if ((name[i]>=65 && name[i]<=90)) {
//			i++;
//		}
//		outtextxy(x+spacing, y, name);
//	}	
//}

int puzzinput(puzzElm element[9]){
	char convert, show[1];
	int i, temp, x=0, y=0;
	
	for (i=0; i<9; i++) {
		do {
			convert = getch();
			temp = int(convert);
		} while (!(temp>=32 && temp<=126));
		
		// pengisian struct
		element[i].id = i;
		element[i].real_pos = i;
		element[i].value = temp;
		if(i<3){
			element[i].top = -1;
			element[i].bottom = i+3;
		}
		else if(i>=3 && i<6){
			element[i].top = i-3;
			element[i].bottom = i+3;
		}
		else if(i>=6){
			element[i].top = i-3;
			element[i].bottom = -1;
		}
		
		if(i%3 == 0){
			element[i].left = -1;
			element[i].right = i+1;
			x = 0;
			y = y + 120;
		}
		else if(i%3 == 1){
			element[i].left = i-1;
			element[i].right = i+1;
		}
		else if(i%3 == 2){
			element[i].left = i-1;
			element[i].right = -1;
		}
		
		sprintf(show, "%c", temp);
		outtextxy(290+(x), y+85, show);
		x = x + 120;
	}
	
	for(i=0; i<9; i++){
		printf("%d - %d \n", i, element[i].value);
	}
}

//Layout
void hiScoreLayout() {
	int x, y;
	bool click=false;
	cleardevice();
	readimagefile("img\\BG2.bmp",0,0,840,620);
	rectangle(40, 40, 800, 490);
	readimagefile("img\\p_home\\quitup.jpg",722,501,802,581);
	do {
		readimagefile("img\\p_hscr\\menuup.jpg", 322, 507, 512, 577);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x>322 && x<512) && (y>507 && y<577)) {
				click=true;
				readimagefile("img\\p_hscr\\menudown.jpg", 322, 507, 512, 577);
				delay(300);
				readimagefile("img\\p_hscr\\menuup.jpg", 322, 507, 512, 577);
				delay(100);
				home();
			}
		}
	} while (click==false);
}
