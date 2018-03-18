/*
Description	: Prototype dari modul yang dikerjakan oleh Dev
Author		: Dev - 171511041
*/

#ifndef H_041
#define H_041

// header
#include "..\game.h"

// prototype
// setiap prototype ditulis sebelum #endif
void menu();
// IS : Menu belum ditampilkan
// FS : Menampilkan menu

void instruction();
// IS : Tidak menampilkan instruksi permainan
// FS : Menampilkan instruksi permainan

void initialize();
// IS : Tidak menampilkan input permainan
// FS : Menampilkan input permainan

void clickinitialize();
// IS : Button belum klik dan tidak pindah ke button yang di tuju
// FS : Button sudah di klik dan pindah ke button yang di tuju

void reset();
// IS : Masih berisi hasil penginputan
// FS : Hasil penginputan kembali ke 0


#endif
