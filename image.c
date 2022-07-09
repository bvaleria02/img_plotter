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
	colorSet(&color, 0, 0, 0, 255);

	generateBlank(&image, &color);
	
	COLOR col1;
	COLOR col2;

	colorSet(&col1, 78, 40, 76, 255);
	colorSet(&col2, 103, 80, 23, 255);
	
	//image_gradientX(&image, &col1, &col2);
	image_gradientY(&image, &col1, &col2);
	
	
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



	for(int i = 0; i < 1200; i++){
	
		colorSet(&color, 16+(i/50), 80+(i/15), 32+(i/32), 255);

		image_drawLine(&image, &color, 1300+120*sin((400+i)/(float)720), 1440-(i/10), 2050, 2399);

	};

	
	for(float i = 0; i < 2400; i += 0.5){
		colorSet(
				&color,
				/* R */ 127 + (i/20),
				/* G */ (i/10),
				/* B */ 255-(i/10),
				/* A */ 255
				);
		
		
		image_drawLine(
				&image,
				&color,
				/* X1 */ 900 + ((2400-i)/3)*sin(i/(float)96),
				/* Y1 */ 900 + ((i)/3)*cos((i+120)/(float)96),
				/* X2 */ 1440,
				/* Y2 */ 1440 
				);
	};	



	subSampler(&image, 2);

	imageWrite(&image);	
	free(image.raw);
	return 0;
}

