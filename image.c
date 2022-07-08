#include <stdio.h>
#include <stdlib.h>
#include "image_st.h"
#include "image_fc.h"


int main(){
	IMG image;
	COLOR color;

	image.width  =  2400;
	image.length =  2400;
	image.name   = "img";
	colorSet(&color, 255, 255, 255, 255);

	generateBlank(&image, &color);
	
	// Some examples. Uncomment to see
	
	/*	
	for(int i = 0; i < 2390; i++){
		colorSet(&color, (i/10), 255-(i/10), (i/10), 255);
		image_drawRect(&image, &color, 0, i, 2390, 2390);
	};	
	for(int i = -160; i < 1760; i++){
		colorSet(&color, abs(-128 + i/5), abs(255 - i/5), i/5, 255);
		image_drawRect(&image, &color, 2100-i, 600+i, 200+i, 200+i);
	};
	colorSet(&color, 0, 0, 255, 255);
	image_drawLine(&image, &color, 100, 400, 200, 2000);
	*/	
	for(int i = 0; i < 1920; i++){
		colorSet(
				&color,
				/* R */ 5*(i/80),
				/* G */ abs(-255+10*(i/200)),
				/* B */ 255 - 5*(i/140),
				/* A */ 255
				);
		
		
		image_drawLine(
				&image,
				&color,
				/* X1 */ 80+(i/4),
				/* Y1 */ 1200+(800*(sin(i/(float)160)))+(360*sin(i/(float)220)),
				/* X2 */ 2200-(i/32),
				/* Y2 */ 1200+(i/5)
				);
	};	

	subSampler(&image, 1);

	imageWrite(&image);	
	free(image.raw);
	return 0;
}

