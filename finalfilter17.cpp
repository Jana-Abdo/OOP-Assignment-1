#include "Image_Class.h"
#include <iostream>
#include <cmath>
using namespace std;

void skewImage(Image& image)
{
    double angle;

    cout << "Enter skew angle in degrees: ";
    cin >> angle;

    if (angle <= -89 || angle >= 89)
    {
        cout << "Invalid angle!" << endl;
        return;
    }

    double radians = angle * 3.141592653589793 / 180.0;
    double skew = tan(radians);

    int extraWidth = ceil((image.height - 1) * abs(skew));
    int newWidth = image.width + extraWidth;

    Image result(newWidth, image.height);

    for (int j = 0; j < image.height; j++)
    {
        for (int i = 0; i < newWidth; i++)
        {
            result(i, j, 0) = 255;
            result(i, j, 1) = 255;
            result(i, j, 2) = 255;
        }
    }

    for (int j = 0; j < image.height; j++)
    {
        int shift = round((image.height - 1 - j) * skew);

        if (angle < 0)
        {
            shift += extraWidth;
        }

        for (int i = 0; i < image.width; i++)
        {
            int newX = i + shift;

            if (newX >= 0 && newX < newWidth)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    result(newX, j, k) = image(i, j, k);
                }
            }
        }
    }

    image = result;
}