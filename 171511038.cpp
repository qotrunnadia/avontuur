/*
Description	: Body dari modul yang dikerjakan oleh Azka
Author		: Azka - 171511038
*/

#include "header\171511038.h"
#include "game.h"

// body modul

void textinstruction()
{
	{
	//border kotak instruction
	setcolor(BLACK);
	rectangle(40,40,602,560);
	rectangle(20,20,582,540);
	setfillstyle(XHATCH_FILL,GREEN);
	floodfill(600,100,BLACK);
	setfillstyle(XHATCH_FILL,GREEN);
	floodfill(30,30,BLACK);
	}

	{
	setbkcolor(RED);
	setcolor(YELLOW);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(60, 50, "SEORANG ANAK KECIL KABUR DARI RUMAH");
	outtextxy(150, 80, "KARENA TAK MAU MENURUTI");
	outtextxy(178, 110, "KATA ORANG TUANYA!!");
	outtextxy(110,480, "CEPAT!! LANGIT MULAI GELAP,");
	outtextxy(150,510, "WAKTUMU TIDAK BANYAK!!");
	}
	
	{
	setbkcolor(BROWN);
	setcolor(WHITE);
	settextstyle(BOLD_FONT,0,2);
	outtextxy(42,150, "Tanpa sadar ia telah melarikan diri ke hutan,");
	outtextxy(50,170, "ia tersesat dan matahari hendak tenggelam!");
	outtextxy(70,190, "Ia menangis dan berjanji untuk menuruti");
	outtextxy(160,210, "perkataan orang tuanya");
	outtextxy(90,240, "Namun, untuk keluar dari hutan tersebut,");
	outtextxy(80,260, "dia harus menyelesaikan sebuah puzzle,");
	outtextxy(90,280, "mari bantu anak itu pulang!!");
	outtextxy(42,310, "Caranya:");
	outtextxy(42,330, "1. Klik tombol 'PLAY'' diawal menu");
	outtextxy(42,350, "2. Ketik namamu");
	outtextxy(42,370, "3. Masukkan goals untuk puzzle milikmu!");
	outtextxy(42,390, "4. Klik tombol 'START'");
	outtextxy(42,410, "5. Selesaikan puzzle yang telah diacak secara");
	outtextxy(42,430, "random dengan klik pada panah di ujung kanan!");
	}
}
