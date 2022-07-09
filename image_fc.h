#include <math.h>
#include <stdio.h>

int image_drawLine(IMG *image, COLOR *col, int x1, int y1, int x2, int y2){
	
	if(x2 < x1){
		x1 = x1 ^ x2;
		x2 = x2 ^ x1;
		x1 = x1 ^ x2;
	};
	if(y2 < y1){
		y1 = y1 ^ y2;
		y2 = y2 ^ y1;
		y1 = y1 ^ y2;
	};

	if (x1 < 0)		   x1 = 0;
	if (x2 < 0)		   x2 = 0;
	if (x1 > image->width -2)  x1 = image->width - 4;
	if (x2 > image->width -2)  x2 = image->width - 4;
	if (y1 < 0) 		   y1 = 0;
	if (y2 < 0) 		   y2 = 0;
	if (y1 > image->length -2) y1 = image->length - 4;
	if (y2 > image->length -2) y2 = image->length - 4;
	
	
	int x = x1;
	int y = y1;
	int c = (col->r << 0) + (col->g << 8) + (col->b << 16) + (col->a << 24);
	int yn = y1;
	int dfy = 0;
	
	for(int i = 0; i < abs(x2 - x1); i++){
		x = x1 + i;
		y = y1 + i * ( (y2 - y1)/(float)(x2 - x1) );
	
		dfy = abs(yn - y);
		for(int j = 0; j < dfy; j++){
			image->raw[ x + (image->width * (image->length - y - (int)(abs(yn - y) * (j/(float)(yn - y)) ) - 1))] = c;
		};
		yn = y;
	};

	return 0;
}



int image_drawRect(IMG *image, COLOR *col, int x1, int y1, int x2, int y2){
	//int x = 0;
	//int y = 0;
	int c = (col->r << 0) + (col->g << 8) + (col->b << 16) + (col->a << 24);
	
	if(x2 < x1){
		x1 = x1 ^ x2;
		x2 = x2 ^ x1;
		x1 = x1 ^ x2;
	};
	if(y2 < y1){
		y1 = y1 ^ y2;
		y2 = y2 ^ y1;
		y1 = y1 ^ y2;
	};
/*
	if (x1 < 0)		   x1 = 0;
	if (x2 < 0)		   x2 = 0;
	if (x1 > image->width -2)  x1 = image->width - 4;
	if (x2 > image->width -2)  x2 = image->width - 4;
	if (y1 < 0) 		   y1 = 0;
	if (y2 < 0) 		   y2 = 0;
	if (y1 > image->length -2) y1 = image->length - 4;
	if (y2 > image->length -2) y2 = image->length - 4;
*/	
	for(int x = x1; x < x2; x++){

		//x = i + x1;
		for(int y = y1; y < y2; y++){
			
			image->raw[x + (image->width * y)] = c;
		};
	};
	return 0;
}


int image_gradientX(IMG *image, COLOR *col1, COLOR *col2){

	int r1 = col1->r;
       	int g1 = col1->g;	
       	int b1 = col1->b;	
       	int a1 = col1->a;	

	int r2 = col2->r;
       	int g2 = col2->g;	
       	int b2 = col2->b;	
       	int a2 = col2->a;	

	int c = 0;	

	for(int x = 0; x < image->width; x++){
			c =    ((r1 + x*(r2-r1)/image->width) << 0)  	
			    +  ((g1 + x*(g2-g1)/image->width) << 8) 	
			    +  ((b1 + x*(b2-b1)/image->width) << 16)  	
			    +  ((a1 + x*(a2-a1)/image->width) << 24); 	
				
		for(int y = 0; y < image->length; y++){
			image->raw[x+ (image->width * y) ] = c;
		};
	};

	return 0;
}


int image_gradientY(IMG *image, COLOR *col1, COLOR *col2){

	int r1 = col1->r;
       	int g1 = col1->g;	
       	int b1 = col1->b;	
       	int a1 = col1->a;	

	int r2 = col2->r;
       	int g2 = col2->g;	
       	int b2 = col2->b;	
       	int a2 = col2->a;	

	int c = 0;	

	for(int y = 0; y < image->length; y++){
			c =    ((r1 + y*(r2-r1)/image->length) << 0)  	
			    +  ((g1 + y*(g2-g1)/image->length) << 8) 	
			    +  ((b1 + y*(b2-b1)/image->length) << 16)  	
			    +  ((a1 + y*(a2-a1)/image->length) << 24); 	
				
		for(int x = 0; x < image->width; x++){
			image->raw[x + (image->width * y) ] = c;
		};
	};

	return 0;
}


