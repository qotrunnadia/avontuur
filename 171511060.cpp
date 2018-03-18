/*
Description	: Body dari modul yang dikerjakan oleh Rizky Agung Hadi Firdaus
Author		: Rizky Agung Hadi Firdaus - 171511060
*/

#include "header\171511060.h"
#include "game.h"

// body modul
void home(){
	int x, y, click = 0;
	
	// algoritma
	menu();
	while(click == 0){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			printf("%d %d - ", x, y);  
			if((x >= 700 && x <= 755) && (y >= 55 && y <= 95)){
				readimagefile("img\\p_home\\instdown.jpg",692,40,762,109);
				delay(300);
				readimagefile("img\\p_home\\instup.jpg",692,40,762,109);
				delay(100);
				instruction();
				click = 1;
			}
			else if((x >= 730 && x <= 795) && (y >= 510 && y <= 570)){
				readimagefile("img\\p_home\\quitdown.jpg",722,501,802,581);
				delay(300);
				readimagefile("img\\p_home\\quitup.jpg",722,501,802,581);
				delay(100);
				quit();
				click = 2;
			}
			else if((x >= 380 && x <= 613) && (y >= 455 && y <= 535)){
				readimagefile("img\\p_home\\playdown.jpg",371,450,623,540);
				delay(300);
				readimagefile("img\\p_home\\playup.jpg",371,450,623,540);
				delay(100);
				initialize();
				click = 3;
			}
			else if((x >= 700 && x <= 755) && (y >= 135 && y <= 190 )){
				readimagefile("img\\p_home\\usdown.jpg", 692,129,762,199);
				delay(300);
				readimagefile("img\\p_home\\usup.jpg", 692,129,762,199);
				delay(100);
				quit();
				click = 4;
			}
			else if((x >= 41 && x <= 501) && (y >= 124 && y <= 580 )){
				readimagefile("img\\p_home\\trophdown.jpg", 41, 501, 124, 580);
				delay(300);
				readimagefile("img\\p_home\\trophup.jpg", 41, 501, 124, 580);
				delay(100);
				hiScoreLayout();
				click=5;
			}
		}
	}
}

void clickinstruction(){
	int x, y, click = 0;
	
	while(click == 0){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			printf("%d %d - ", x, y);  
			if((x >= 625 && x <= 800) && (y >= 50 && y <= 105)){
				readimagefile("img\\p_inst\\menudown.jpg",617,40,807,110);
				delay(300);
				readimagefile("img\\p_inst\\menuup.jpg",617,40,807,110);
				delay(100);
				click = 1;
			}
		}
	}
}

void createButton(koordButton coord, int type){
//	char tup[3] = "UP", tright[6] = "RIGHT", tdown[5] = "DOWN", tleft[5] = "LEFT";
	setcolor(BLACK);
	// kotak luar
	rectangle(coord.x1,   coord.y1,   coord.x2 ,  coord.y2);
	// kotak dalam
	rectangle(coord.x1+JARAK, coord.y1+JARAK, coord.x2-JARAK, coord.y2-JARAK);
	// garis
	line(coord.x1, coord.y1, coord.x1+JARAK, coord.y1+JARAK);
	line(coord.x2, coord.y1, coord.x2-JARAK, coord.y1+JARAK);
	line(coord.x1, coord.y2, coord.x1+JARAK, coord.y2-JARAK);
	line(coord.x2, coord.y2, coord.x2-JARAK, coord.y2-JARAK);
	
	if(type == BUP){
		
	}
	else if(type == BRIGHT){
		
	}
	else if(type == BDOWN){
		
	}
	else if(type == BLEFT){
		
	}
}

void warnaButton(koordButton coord){
	setfillstyle(SOLID_FILL, WHITE);
	// atas
	floodfill(coord.x1    + ((coord.x2    - coord.x1)/2),    coord.y1    + (((coord.y1+JARAK)    - coord.y1)/2), BLACK);
	// kiri
	floodfill(coord.x1    + (((coord.x1+JARAK)    - coord.x1)/2),    coord.y1    + ((coord.y2    - coord.y1)/2), BLACK);
	
	setfillstyle(SOLID_FILL, WHITE);
	// tengah
	floodfill(coord.x1    + ((coord.x2    - coord.x1)/2),    coord.y1    + ((coord.y2    - coord.y1)/2), BLACK);
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	// bawah
	floodfill(coord.x1    + ((coord.x2    - coord.x1)/2),    coord.y2-JARAK    + ((coord.y2    - (coord.y2-JARAK))/2), BLACK);
	// kanan
	floodfill((coord.x2-JARAK)    + ((coord.x2    - (coord.x2-JARAK))/2),    coord.y1    + ((coord.y2    - coord.y1)/2), BLACK);
}

void warnaCButton(koordButton coord){
	setfillstyle(SOLID_FILL, DARKGRAY);
	// atas
	floodfill(coord.x1    + ((coord.x2    - coord.x1)/2),    coord.y1    + (((coord.y1+JARAK)    - coord.y1)/2), BLACK);
	// kiri
	floodfill(coord.x1    + (((coord.x1+JARAK)    - coord.x1)/2),    coord.y1    + ((coord.y2    - coord.y1)/2), BLACK);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	// tengah
	floodfill(coord.x1    + ((coord.x2    - coord.x1)/2),    coord.y1    + ((coord.y2    - coord.y1)/2), BLACK);
	
	setfillstyle(SOLID_FILL, WHITE);
	// bawah
	floodfill(coord.x1    + ((coord.x2    - coord.x1)/2),    coord.y2-JARAK    + ((coord.y2    - (coord.y2-JARAK))/2), BLACK);
	// kanan
	floodfill((coord.x2-JARAK)    + ((coord.x2    - (coord.x2-JARAK))/2),    coord.y1    + ((coord.y2    - coord.y1)/2), BLACK);
}

int cekSpasi(puzzElm element[9]){
	bool cek = false;
	int i = 0;
	
	// algoritma
	// cari spasi
	while(i < 9 and not cek){
		if(element[i].value == 32){
			cek = true;
		}
		i++;
	}
	
	return cek;
}


void playGame(char name[6], puzzElm element[9]){
	// var lokal
	int i, j=0, x=0, y=0, h=0, m=0, s=0, move=0, clickx, clicky;
	char txttime[9], goals[1], txtmove[5];
	int thumb[9];
	puzzElm blankbox;
	koordButton b_up, b_right, b_down, b_left;
	bool selesai = false;
	
	b_up.x1    = 695; b_up.y1    = 470; b_up.x2    = 745; b_up.y2    = 520;
	b_right.x1 = 755; b_right.y1 = 530; b_right.x2 = 805; b_right.y2 = 580;
	b_down.x1  = 695; b_down.y1  = 530; b_down.x2  = 745; b_down.y2  = 580;
	b_left.x1  = 635; b_left.y1  = 530; b_left.x2  = 685; b_left.y2  = 580;
	
	// algoritma
	cleardevice();
	readimagefile("img\\BG2.bmp",0,0,840,620);
	readimagefile("img\\BG.bmp",0,0,200*3,200*3);
	readimagefile("img\\BG.bmp",660,40,660+(40*3),40+(40*3));
	
	// salin thumbnail
	for(i = 0; i < 9; i++){
		thumb[i] = element[i].value;
	}
	
	// pengecekan cheat & pemanggilan random
	if(name[0] == 'H' && name[1] == 'E' && name[2] == 'L' && name[3] == 'P'){
		printf("\nCheat Activated\n");
		cheatRand(element, &blankbox);
	}
	else{
		printf("\nGapake Cheat\n");
		randPuzz(element, &blankbox);
	}
		
	// tampil board game
	printBoard(element);
	
	printf("\n\n%d %d %d %d %d %d %d", blankbox.id, blankbox.real_pos, blankbox.value, blankbox.top, blankbox.right, blankbox.bottom, blankbox.left);
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, LEFT_TEXT, 3);
	for(i=0; i<9; i++){
		if((i > 0) && (i % 3 == 0)){
			j = j + 1;
			x=0;
			y=0;
		}
		// buat main
		rectangle(10+(200*(x))-(10*1),10+(200*(j))-(10*1),200+(200*(x)),200+(200*(j)));
		
		// tampil goals
		// convert ascii to char
		sprintf(goals, "%c", thumb[i]);
		// bikin kotak2 nya
		rectangle(660+(40*(x)),40+(40*(j)),700+(40*(x)),40+(40*(j+1)));
		// tampilin goals nya
		outtextxy(670+(40*x),44+(40*j), goals);
		x++;
		y++;
	}
	
	// kotak data pemain & permainan
	settextstyle(BOLD_FONT, LEFT_TEXT, 2);
	rectangle(620, 180, 820, 280);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(620+(820-620)/2, 180+(280-180)/2, BLACK);
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(630, 190, "Name: ");
	outtextxy(630, 220, "Time: ");
	outtextxy(630, 250, "Move: ");
	
	
	// button
	// up
	createButton(b_up, BUP);
	// right
	createButton(b_right, BRIGHT);
	// down
	createButton(b_down, BDOWN);
	// left
	createButton(b_left, BLEFT);
	
	setcolor(WHITE);
	settextstyle(BOLD_FONT, LEFT_TEXT, 2);
	outtextxy(700, 190, name);
	
	sprintf(txtmove, "%d", move);
	outtextxy(700, 250, txtmove);
	
	while(not selesai){
		warnaButton(b_up);
		warnaButton(b_right);
		warnaButton(b_down);
		warnaButton(b_left);
				
		// timer
		sprintf(txttime, "%d:%02d:%02d", h,m,s);
		outtextxy(700,220, txttime);
		s++;
		delay(1000);
		if(s==60){
			m++;
			s = 0;
		}
		if(m==60){
			h++;
			m = 0;
		}
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, clickx, clicky);
			printf("\n%d %d ", clickx, clicky);
			// button up
			if((clickx > b_up.x1 && clickx < b_up.x2) && (clicky > b_up.y1 && clicky < b_up.y2)){
				warnaCButton(b_up);
				delay(300);
				if(blankbox.top != -1){
					moveUp(element, &blankbox);
					printBoard(element);
					
					move = move + 1;
					sprintf(txtmove, "%d", move);
				}
			}
			// button right
			else if((clickx > b_right.x1 && clickx < b_right.x2) && (clicky > b_right.y1 && clicky < b_right.y2)){
				warnaCButton(b_right);
				delay(300);
				if(blankbox.right != -1){
					moveRight(element, &blankbox);
					printBoard(element);
					
					move = move + 1;
					sprintf(txtmove, "%d", move);
				}
			}
			// button down
			else if((clickx > b_down.x1 && clickx < b_down.x2) && (clicky > b_down.y1 && clicky < b_down.y2)){
				warnaCButton(b_down);
				delay(300);
				if(blankbox.bottom != -1){
					moveBottom(element, &blankbox);
					printBoard(element);
					
					move = move + 1;
					sprintf(txtmove, "%d", move);
				}
			}
			// button left
			else if((clickx > b_left.x1 && clickx < b_left.x2) && (clicky > b_left.y1 && clicky < b_left.y2)){
				warnaCButton(b_left);
				delay(300);
				if(blankbox.left != -1){
					moveLeft(element, &blankbox);
					printBoard(element);
					
					move = move + 1;
					sprintf(txtmove, "%d", move);
				}
			}
			setbkcolor(BLACK);
			setcolor(WHITE);
			settextstyle(BOLD_FONT, LEFT_TEXT, 2);
			outtextxy(700, 250, txtmove);
			
			selesai = cekSelesai(element);
		}
	}
	
	delay(300);
	// disini nanti harusnya proses2 file sebelum nampilin highscore
	hiScoreLayout();
}

void swapElmnt(int *realpos_blank, int *value_blank, int *realpos_1, int *value_1){
	int temp_realpos = *realpos_blank;
	int temp_value   = *value_blank;
	
	*realpos_blank   = *realpos_1;
	*value_blank     = *value_1;
	
	*realpos_1       = temp_realpos;
	*value_1         = temp_value;
}


void cheatRand(puzzElm element[9], puzzElm *blankBox){
	int i, temp_val, temp_realpos;
	
	for(i = 0; i < 9; i++){
		if(element[i].value == 32){
			if(element[i].top != -1){
				temp_val = element[i].value;
				temp_realpos = element[i].real_pos;
				
				element[i].value = element[element[i].top].value;
				element[i].real_pos = element[element[i].top].real_pos;
				
				element[element[i].top].value = temp_val;
				element[element[i].top].real_pos = temp_realpos;
				*blankBox = element[element[i].top];
			}
			else if(element[i].right != -1){
				temp_val = element[i].value;
				temp_realpos = element[i].real_pos;
				
				element[i].value = element[element[i].right].value;
				element[i].real_pos = element[element[i].right].real_pos;
				
				element[element[i].right].value = temp_val;
				element[element[i].right].real_pos = temp_realpos;
				*blankBox = element[element[i].right];
			}
			else if(element[i].bottom != -1){
				temp_val = element[i].value;
				temp_realpos = element[i].real_pos;
				
				element[i].value = element[element[i].bottom].value;
				element[i].real_pos = element[element[i].bottom].real_pos;
				
				element[element[i].bottom].value = temp_val;
				element[element[i].bottom].real_pos = temp_realpos;
				*blankBox = element[element[i].bottom];
			}
			break;
		}
	}
}

void printBoard(puzzElm element[9]){
	int x=0, y=0, i, j=0;
	char print[1], temp;
	
	// algoritma
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, LEFT_TEXT, 9);
	
	for(i=0; i<9; i++){
		if((i>0) && (i % 3 == 0)){
//			j = j + 1;
			x=0;
			y=y+1;
		}
		// buat main
		// convert ascii to char
		temp = (char)element[i].value;
		sprintf(print, "%c", temp);
		printf("%c ", temp);
		// tampil isi nya
		outtextxy(50+(x*200),50+(y*200), print);
		x++;
	}
}

void moveUp(puzzElm element[9], puzzElm *blankBox){
	int up, pos, i;
	pos = blankBox->id;
	up  = blankBox->top;
	
	swapElmnt(&element[pos].real_pos, &element[pos].value, &element[up].real_pos, &element[up].value);
    // find blankbox
    for(i = 0; i < 9; i++){
    	if(element[i].value == 32){
    		*blankBox = element[i];
    		break;
    	}
    }
}

void moveRight(puzzElm element[9], puzzElm *blankBox){
	int right, pos, i;
	pos = blankBox->id;
	right  = blankBox->right;
	
	swapElmnt(&element[pos].real_pos, &element[pos].value, &element[right].real_pos, &element[right].value);
    // find blankbox
    for(i = 0; i < 9; i++){
    	if(element[i].value == 32){
    		*blankBox = element[i];
    		break;
    	}
    }
}

void moveBottom(puzzElm element[9], puzzElm *blankBox){
	int bottom, pos, i;
	pos = blankBox->id;
	bottom  = blankBox->bottom;
	
	swapElmnt(&element[pos].real_pos, &element[pos].value, &element[bottom].real_pos, &element[bottom].value);
    // find blankbox
    for(i = 0; i < 9; i++){
    	if(element[i].value == 32){
    		*blankBox = element[i];
    		break;
    	}
    }
}

void moveLeft(puzzElm element[9], puzzElm *blankBox){
	int left, pos, i;
	pos = blankBox->id;
	left  = blankBox->left;
	
	swapElmnt(&element[pos].real_pos, &element[pos].value, &element[left].real_pos, &element[left].value);
    // find blankbox
    for(i = 0; i < 9; i++){
    	if(element[i].value == 32){
    		*blankBox = element[i];
    		break;
    	}
    }
}

bool cekSelesai(puzzElm element[9]){
	int i;
	bool cek = true;
	
	for(i=0;i<9;i++){
		if(element[i].real_pos != element[i].id){
			cek = false;
			break;
		}
	}
	
	return cek;
}

