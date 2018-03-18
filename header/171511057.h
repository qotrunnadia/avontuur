/*
Description	: Prototype dari modul yang dikerjakan oleh Qotrun
Author		: Qotrun - 171511057
*/

#ifndef H_057
#define H_057

// header
#include "..\game.h"

// prototype
// setiap prototype ditulis sebelum #endif

void quit();
// IS : Masih berada dalam program
// FS : Keluar dari program

void input_form();
// Menampilkan Grid ketika input

void cheatRand(puzzElm element[9], puzzElm *blankBox);
// IS : Element puzzle belum diacak
// FS : Element Puzzle diacak 

#endif
