/*
Description	: Body dari modul yang dikerjakan oleh Qotrun
Author		: Qotrun - 171511057
*/

#include "header\171511057.h"
#include "game.h"

// body modul

void quit(){
	exit(1);
}

void input_form(){
	
int i, j=0, x=0, y=0;
	
	rectangle (231,80,612,120);
	
	for(i=0; i<9; i++){
		if((i > 0) && (i % 3 == 0)){
			j = j + 1;
			x=0;
			y=0;
		}
//		rectangle(10+(200*(i))-(10*j),10+(200*(j))-(10*j),200+(200*(i)),200+(200*(j)));
		rectangle(240+(120*(x)),160+(120*(j)),240+120+(120*(x)),160+120+(120*(j)));
//		rectangle(240+(120*(x))-(240*1),240+(240*(j))-(240*1),20+(120*(x)),120+(120*(j)));

		x++;
		y++;
}
}

void randPuzz(puzzElm element[9], puzzElm *blankBox){
	int i, j;
	
	// result each time we run this program
    srand ( time(NULL) );
    
    for(i = 9-1; i > 0; i--){
    	j = rand() % (i+1);
    	
    	swapElmnt(&element[i].real_pos, &element[i].value, &element[j].real_pos, &element[j].value);
    }
    
    // find blankbox
    for(i = 0; i < 9; i++){
    	if(element[i].value == 32){
    		*blankBox = element[i];
    		break;
    	}
    }
}

int cekSama(puzzElm element[9]){
	bool cek = false;
	int i = 1, x = 0;
	int active = 0;
	
	// algoritma
	// tampung array pertama ke active
	active = element[x].value;
	
	// looping ke elemen selanjutnya hingga akhir
	while(i<9 and not cek){
		if(element[i].value == active){
			cek = true;
		}
		i++;
		
		if(x < 9 and i == 9 and not cek){
			x = x + 1;
			active = element[x].value;
			i = x + 1;
		}
	}	
	return cek;
}
