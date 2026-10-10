
#include "Image_Class.h"
#include <iostream>
using namespace std;

void PurpleApple(Image& image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            int old_red = image.getPixel(x, y, 0);
            int old_green = image.getPixel(x, y, 1);
            int old_blue = image.getPixel(x, y, 2);

            int new_red = (0.8 * old_red) + (0.2 * 180);
            int new_green = (0.8 * old_green) + (0.0001 * 70);
            int new_blue = (0.8 * old_blue) + (0.2 * 200);

            image.setPixel(x, y, 0, new_red);
            image.setPixel(x, y, 1, new_green);
            image.setPixel(x, y, 2, new_blue);
        }
    }
}

int main()
{
    Image image("apple.jpg");

    PurpleApple(image);

    image.saveImage("purple_apple.jpg");

    return 0;
}

