/*
Description	: Body dari modul yang dikerjakan oleh Dev
Author		: Dev - 171511041
*/

#include "header\171511041.h"
#include "game.h"

// body modul

void menu(){
	cleardevice();
	readimagefile("img\\BG2.bmp",0,0,840,620);
//	rectangle(80,40,601,413);
	readimagefile("img\\p_home\\Logo.jpg",80,40,603,413); //13032018
	outtextxy(10, 5, "Menu Utama");
//	rectangle(371,450,621,540);
//	rectangle(692,40,762,109);
//	rectangle(692,129,762,199);
//	rectangle(721,501,801,581);
	readimagefile("img\\p_home\\playup.jpg",371,450,623,540);
	readimagefile("img\\p_home\\instup.jpg",692,40,762,109);
	readimagefile("img\\p_home\\usup.jpg",692,129,762,199);
	readimagefile("img\\p_home\\quitup.jpg",722,501,802,581);
//	rectangle(40,500,121,580);
	readimagefile("img\\p_home\\trophup.jpg",41,501,124,580);
}

void instruction(){
	cleardevice();
	readimagefile("img\\BG2.bmp",0,0,840,620);
//	outtextxy(10, 10, "Intruction");
	
//	setcolor(BLACK);
//	rectangle(40,40,602,560);
//	rectangle(617,40,807,110);
	readimagefile("img\\p_inst\\menuup.jpg",617,40,807,110);

	
	textinstruction();
	clickinstruction();
	home();
}

	
void initialize(){
	puzzElm element[9];
	cleardevice();
	char name[5] = "    ";
	int x, y, click = 0;
	bool cek = false;

	readimagefile("img\\BG2.bmp",0,0,840,620);
//	rectangle(231,80,612,120);

//	rectangle(40,459,198,506);
//	rectangle(40,530,211,580);
//	rectangle(630,531,799,580);

	input_form();

	nameinput(241, 90, "YOUR NAME:", 220, name, COMPLEX_FONT, LEFT_TEXT, 3);
	puzzinput(element);
	
	readimagefile("img\\p_init\\resetup.jpg",39,459,198,506);
	readimagefile("img\\p_init\\backup.jpg",40,530,211,580);
	readimagefile("img\\p_init\\startup.jpg",630,531,799,580);
	//clickinitialize();
	while(click==0){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			printf("%d %d - ", x, y);
				if((x >= 40 && x <= 198) && (y >= 459 && y<= 506)){
				readimagefile("img\\p_init\\resetdown.jpg",39,459,198,506);
				delay(300);
				readimagefile("img\\p_init\\resetup.jpg",39,459,198,506);
				delay(100);
				initialize();
				click=1;
			} else if((x >= 40 && x <= 211) && (y >= 530 && y<= 580)){
				readimagefile("img\\p_init\\backdown.jpg",40,530,211,580);
				delay(300);
				readimagefile("img\\p_init\\backup.jpg",40,530,211,580);
				delay(100);
				home();
				click=1;
		
			} else if((x >= 630 && x <= 799) && (y >= 531 && y<= 580)){
				readimagefile("img\\p_init\\startdown.jpg",630,531,799,580);
				delay(300);
				readimagefile("img\\p_init\\startup.jpg",630,531,799,580);
				delay(100);
				
				// pengecekan goals
				// pengecekan spasi
				cek = cekSpasi(element);
				if (cek == false){
					printf("Gaada Spasi\n");
					// outtextxy disini, simpen diatas tombol start, sebagai warning "harus ada sspasi sebagai indikator yang kosong, harap reset"
				}
				else{
					// pengecekan sama
					cek = cekSama(element);
					if (cek == true){
						printf("karakter gaboleh ada yang sama\n");
						// outtextxy disini, simpen diatas tombol start, sebagai warning "gaboleh ada karakter sama, harap reset"
					}
					else{
						playGame(name, element);
						click=1;
					}
				}
			}
		}
	}
}





