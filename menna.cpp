#include "menna.h"
void sunlight_brightness(Image& image)
{
    for (int i = 0; i < image.width ;++i)
{ 
     for (int j = 0; j < image.height ;++j)
    {
        int red = image(i , j , 0);
        int green = image(i , j , 1);
        
        red = red + 60;
        green = green + 40;   

        if (red > 255) {
            red = 255;
        }
        if (green > 255) {
            green = 255;
        }
    
        
        image(i , j , 0) = red;
        image(i , j , 1) = green;
    }
    
    }







} 

