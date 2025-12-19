
/* 
   Program to demonstrate the use of bit fields in structures.
   The program defines a structure representing an on-screen box with various attributes
   such as border presence, visibility, color, and border style. It initializes an instance
   of the structure, displays its settings, modifies them, and displays the updated settings.

   Using : Enum types for color and border style for better readability.
*/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef enum : uint8_t
{
   BLACK    = 0,
   RED      = 1,
   GREEN    = 2,
   YELLOW   = 3,
   BLUE     = 4,
   MAGNETA  = 5,
   CYAN     = 6,
   WHITE    = 7
} Color_en;

typedef enum : uint8_t
{
   SOLID       = 0,
   DOTTED      = 1,
   DASHED      = 2,
   DOUBLE_LINE = 3
} BorderStyle_en;


typedef  struct
{
   bool border                        : 1;
   bool box_visibility                : 1;
   Color_en box_color                 : 3;
   Color_en border_color              : 3;
   BorderStyle_en border_style        : 2;
} OnscreenBox_st;

const char color_Array[8][7] = {"BLACK","RED", "GREEN", "YELLOW", "BLUE", "MAGNETA", "CYAN", "WHITE"};
const char borderStyle_Array[4][12] = {"SOLID", "DOTTED", "DASHED", "DOUBLE_LINE"};

void show_settings(const OnscreenBox_st * box)
{
   BorderStyle_en border_style;
   printf("Box Visibility : %s\n", box->box_visibility ? "Visible" : "Hidden");
   printf("Box Has Border : %s\n", box->border ? "Yes" : "No");
   printf("Box Border : %d\n", box->border);
   printf("Box Color : %s\n", color_Array[box->box_color]);
   printf("Box Border Color : %s\n", color_Array[box->border_color]);
   printf("Box Border Style : %s\n", borderStyle_Array[box->border_style]);  
}


int main(void)                     
{
   OnscreenBox_st box1 = { .border = 1,
                           .box_visibility = 1,
                           .box_color = RED,
                           .border_color = BLUE,
                           .border_style = DOTTED
                        };
  printf("Initial Box Settings : \n");                      
  show_settings(&box1);

 
  box1.border = 0;
  box1.box_visibility = 0;
  box1.box_color = GREEN;
  box1.border_color = YELLOW;
  box1.border_style = DASHED;

  printf("\nModified Box Settings : \n");      
  show_settings(&box1);
  return 0;

}
