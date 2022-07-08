#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char byte;

typedef struct {
	char *name;
	int width;
	int length;
	int *raw;
} IMG;

typedef struct {
	byte r;
	byte g;
	byte b;
	byte a;
} COLOR;

int generateBlank(IMG *image, COLOR *col){
	image->raw = malloc(sizeof(int) * image->width * image->length);
	int c = (col->r << 0) + (col->g << 8) + (col->b << 16) + (col->a << 24);
	printf("Image raw : %p\n", image->raw);

	for(int i = 0; i < (image->width * image->length); i++){
		image->raw[i] = c;
	};
	return 0;
}


int imageWrite(IMG *image){
	char buffer[256];
	for(int i = 0; i < 256; i++) buffer[i] = '\0';
	sprintf(buffer, "%s.raw", image->name);
	FILE *fp = fopen(buffer, "wb+");
	if (fp == NULL) return 1;
	fwrite(image->raw, sizeof(int), image->width * image->length, fp);
	fclose(fp);
	return 0;
}


int colorSet(COLOR *col, byte r, byte g, byte b, byte a){
	col->r = r;
	col->g = g;
	col->b = b;
	col->a = a;
	/*
	printf("\033[0;0mCanal \033[0;91mrojo  \033[0;0mcambiado a \033[0;35m%i\n", col->r);
	printf("\033[0;0mCanal \033[0;92mverde \033[0;0mcambiado a \033[0;35m%i\n", col->g);
	printf("\033[0;0mCanal \033[0;94mazul  \033[0;0mcambiado a \033[0;35m%i\n", col->b);
	printf("\033[0;0mCanal \033[0;96malfa  \033[0;0mcambiado a \033[0;35m%i\n", col->a);
	printf("\033[0;0m");
	*/
	return 0;
}

int subSampler(IMG *image, int s){
	fprintf(stdout, "------- <>");
	s = pow(2, s);
	printf("%i\n", s);	
	int *ni = (int *)malloc(sizeof(int)* (image->width/s) * (image->length/s));

	int r,g,b,a,  c;
	
	printf("------- <>");
	for(int y = 0; y < (image->length/s); y++){
		for(int x = 0; x < (image->width/s) ; x++){
			
			r = 0;
			g = 0;
			b = 0;
			a = 0;
			
			for(int n = 0; n < s; n ++){
				for(int m = 0; m < s; m++){
					c = image->raw[
						(x * s + n) + (image->width * (image->length - (y * s - m)))
					];
					r += (c >>  0) & 0xFF;
					g += (c >>  8) & 0xFF;
					b += (c >> 16) & 0xFF;
					a += (c >> 24) & 0xFF;
				};
			};
			r = r/(s * s);
			g = g/(s * s);
			b = b/(s * s);
			a = a/(s * s);

			//printf("%i %i\n", x, y);
			c = (r << 0) + (g << 8) + (b << 16) + (a << 24);
			ni[x + ((image->width/s) * ((image->length/s) - y -1))] = c;
		};
	};
	printf("------- <>");
	//image->raw = realloc(image->raw, sizeof(int) * (image->width/s) * (image->length/s));
	image->width  = image->width/s;
	image->length = image->length/s;
	
	for(int i = 0; i < (image->width * image->length); i++) image->raw[i] = ni[i];
	free(ni);
	return 0;
}
