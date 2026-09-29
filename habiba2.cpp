#include "Image_Class.h"
#include <iostream>
using namespace std;

int main()
{
    Image image("apple.jpg");

    int type;
    double percent;

    cout << "1 - Darken" << endl;
    cout << "2 - Lighten" << endl;
    cin >> type;

    cout << "Enter percentage (0-100): ";
    cin >> percent;

    double p = percent / 100.0;

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                if (type == 1)
                {
                    image(i, j, k) =
                        image(i, j, k) * (1 - p);
                }

                else if (type == 2)
                {
                    image(i, j, k) =
                        image(i, j, k) +
                        (255 - image(i, j, k)) * p;
                }
            }
        }
    }

    if (image.saveImage("output_image.png"))
    {
        cout << "Image saved successfully!" << endl;
    }
    else
    {
        cout << "Failed to save image!" << endl;
    }

    return 0;
}