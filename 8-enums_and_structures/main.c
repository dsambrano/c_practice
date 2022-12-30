#include <stdio.h>

// Global Variable (be careful because this consume memory until program ends)
// but the benefit is that it can be used across the whole program
int result;

// Create your own types with informative names (ranges from 0 - 255)
typedef unsigned char BYTE;

// Enums, pretty much just the same as python, e.g., creates BOOLEAN enum
// These are automatically assigned, but can be manually assigne with = INT
// after the name (e.g., false = 0).
typedef enum { false, true } BOOLEAN;
typedef struct {
  BYTE red_pixel;
  BYTE green_pixel;
  BYTE blue_pixel;
} PIXEL;

void add_to_pixel(PIXEL *data, int value) {
  data->red_pixel = data->red_pixel + value;
  data->blue_pixel = data->blue_pixel + value;
  data->green_pixel = data->green_pixel + value;
}

void create_pixel(PIXEL *data, BYTE red, BYTE green, BYTE blue) {
  data->red_pixel = red;
  data->blue_pixel = blue;
  data->green_pixel = green;
}

int main(void) {
  // boolean test
  BOOLEAN b_type;
  b_type = true;

  if (b_type) {
    printf("BOOLEAN worked\n");
  } else {
    printf("BOOLEAN did not worked\n");
  }
  PIXEL pix;
  create_pixel(&pix, 149, 44, 255);
  printf("RGB of purple is rgb(%d, %d, %d).\n", pix.red_pixel, pix.green_pixel,
         pix.blue_pixel);
  printf("Hex of purple is #%x%x%x).\n", pix.red_pixel, pix.green_pixel,
         pix.blue_pixel);

  pix.red_pixel = 79;
  pix.blue_pixel = 13;
  pix.green_pixel = 182;
  printf("RGB of manual purple is rgb(%d, %d, %d).\n", pix.red_pixel,
         pix.green_pixel, pix.blue_pixel);

  return 0;
}
