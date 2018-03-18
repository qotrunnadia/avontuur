/*
Description	: Prototype dari modul yang dikerjakan oleh Jays
Author		: Jays - 171511052
*/

#ifndef H_052
#define H_052

// header
#include "..\game.h"
#define KEY_ESCAPE	27
#define maxwidth	840
#define maxheight	620

// prototype
// setiap prototype ditulis sebelum #endif

//Input/Output
void opengraph();
void escape();
void nameinput(int x, int y, char *title, int spacing, char name[5], int font, int direction, int charsize);
int puzzinput(puzzElm element[9]);
//Layout
void hiScoreLayout();

#endif
