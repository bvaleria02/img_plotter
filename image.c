#include <stdio.h>
#include <stdlib.h>
#include "image_st.h"
#include "image_fc.h"


int main(int argc, char **argv){
	IMG image;
	COLOR color;

	image.width  =  atoi(argv[1]);
	image.length =  atoi(argv[2]);
	image.name   =  argv[3];
	colorSet(&color, 0, 0, 0, 255);

	printf("argv: %s %s %s\n", argv[1], argv[2], argv[3]);


	generateBlank(&image, &color);
	
	COLOR col1;
	COLOR col2;

	colorSet(&col1, 78, 40, 76, 255);
	colorSet(&col2, 103, 80, 23, 255);
	
	//image_gradientX(&image, &col1, &col2);
	//image_gradientY(&image, &col1, &col2);
	
	
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


	/*
	for(int i = 0; i < 1200; i++){
	
		colorSet(&color, 16+(i/50), 80+(i/15), 32+(i/32), 255);

		image_drawLine(&image, &color, 1300+120*sin((400+i)/(float)720), 1440-(i/10), 2050, 2399);

	};
*/
	
	for(float i = 0; i <0; i += 0.5){
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
	int x1, x2, x3, y1, y2, y3, x4, y4, r;

	for(float i = 0; i < 72; i += 8){
	
		x1 = 1200 + 750*sin(i/4) ;
		y1 = 1200 + 575*sin((i+2.1)/4);

		x2 = 1200 + 625*sin((1.2*i+2.5)/4);
		y2 = 1200 + 800*sin((0.85*i - 1.875)/4);

		x3 = 1200 + 900*sin((0.65*i-4.5)/4);
		y3 = 1200 + 560*sin((1.08*i-0.25)/4); 

		x4 = 120 + (i*10); 
		y4 = 120 + (i*10);
		r  = 30 + (i*-2);

	//printf("------------------\n step: %f\n x1: %i, y1: %i\nx2: %i, y2: %i\nx3: %i, y3: %i\n", i, x1, y1, x2, y2, x3, y3);

		colorSet(&color, 32+3*i, 80+(i*2), abs(232-(i*6)), 255);
		image_drawCircle(&image, &color, x4, y4, r);
		//image_drawPoly(&image, &color, x1, y1, x2, y2, x3, y3);
	};


	// center, radius
	//colorSet(&color, 0, 127, 216, 255);
	//subSampler(&image, 2);

	imageWrite(&image);	
	free(image.raw);
	return 0;
}

