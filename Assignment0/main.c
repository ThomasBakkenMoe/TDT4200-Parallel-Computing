
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

//#include <windows.h>
//#include <magick_wand.h>

typedef struct{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} pixel;

int main(int argc, char** argv)
{
    stbi_set_flip_vertically_on_load(true);
	stbi_flip_vertically_on_write(true);

	int width;
	int height;
	int channels;
    unsigned char* char_pixels_1 = stbi_load(argv[1], &width, &height, &channels, STBI_rgb_alpha);
    unsigned char* char_pixels_2 = stbi_load(argv[2], &width, &height, &channels, STBI_rgb_alpha);

    printf("height:%d, width: %d\n", height, width);
    if (char_pixels_1 == NULL || char_pixels_2 == NULL)
    {
        printf("Input 1 or 2 is missing or invalid, exiting...");
        exit(1);
    }

    //TODO 2 - typecast pointer
    pixel* pixels_1 = (pixel*) char_pixels_1;
    pixel* pixels_2 = (pixel*) char_pixels_2;

    //TODO 3 - malloc
    pixel* pixels_out = (pixel *) malloc(sizeof(pixel) * (width * height));

    //TODO 4 - loop
    //Write your loop here
    int i;
    for(i = 0; i < (width * height); i++) {

        pixel output_pixel;
        output_pixel.r = (pixels_1[i].r + pixels_2[i].r) / 2;
        output_pixel.g = (pixels_1[i].g + pixels_2[i].g) / 2;
        output_pixel.b = (pixels_1[i].b + pixels_2[i].b) / 2;
        output_pixel.a = (pixels_1[i].a + pixels_2[i].a) / 2;

        pixels_out[i] = output_pixel;
    }

    stbi_write_png("output.png", width, height, STBI_rgb_alpha, pixels_out, sizeof(pixel) * width);

    //TODO 5 - free

    return 0;
}
