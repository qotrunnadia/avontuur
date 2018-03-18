/*
Description	: Prototype dari modul yang dikerjakan oleh Rizky Agung Hadi Firdaus
Author		: Rizky Agung Hadi Firdaus - 171511060
*/

#ifndef H_060
#define H_060

#define BUP 1
#define BRIGHT 2
#define BDOWN 3
#define BLEFT 4
#define JARAK 6

// header
#include "..\game.h"

typedef struct{
	int x1, y1, x2, y2;
} koordButton;

// prototype
// setiap prototype ditulis sebelum #endif
void home();
// tujuan : Untuk menampilkan menu utama, menu() hanya sebagai tampilannya

void clickinstruction();
// tujuan : Untuk kembali ke menu utama di halaman instruction

void createButton(koordButton coord, int type);
// tujuan : Membuat button

void warnaButton(koordButton coord);
// tujuan : Memberi warna pada button

void warnaCButton(koordButton coord);
// tujuan : Memberi warna ketika button di klik

int cekSpasi(puzzElm element[9]);
// IS : Goals belum di cek apa terdapat spasi sebagai indikator blank box atau tidak
// FS : Goals telah di cek dan dapat melanjutkan ke pengecekan selanjutnya

int cekSama(puzzElm element[9]);
// IS : Goals belum di cek apa terdapat karakter yang sama atau tidak
// FS : Goals telah di cek dan dapat melanjutkan ke tahap selanjutnya atau tidak

void playGame(char name[6], puzzElm element[9]);
// IS : Berada di halaman initialize
// FS : Berada di halaman untuk bermain

void swapElmnt(int *realpos_blank, int *value_blank, int *realpos_1, int *value_1);
// IS : value dan realpos dari element puzzle belum ditukar
// FS : value dan realpos dari element puzzle ditukar

void randPuzz(puzzElm element[9], puzzElm *blankBox);
// IS : Element puzzle belum diacak
// FS : Element puzzle telah diacak

void printBoard(puzzElm element[9]);
// IS : Karakter di papan permainan tidak ditampilkan
// FS : Karakter di papan permainan ditampilkan

void moveUp(puzzElm element[9], puzzElm *blankBox);
// tujuan : untuk memindahkan blankbox ke atasnya

void moveRight(puzzElm element[9], puzzElm *blankBox);
// tujuan : untuk memindahkan blankbox ke kanannya

void moveBottom(puzzElm element[9], puzzElm *blankBox);
// tujuan : untuk memindahkan blankbox ke bawahnya

void moveLeft(puzzElm element[9], puzzElm *blankBox);
// tujuan : untuk memindahkan blankbox ke kirinya

bool cekSelesai(puzzElm element[9]);
// tujuan : untuk mengecek puzzle selesai atau belum

#endif
