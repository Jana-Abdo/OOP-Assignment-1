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

    if (type != 1 && type != 2)
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    cout << "Enter percentage (0-100): ";
    cin >> percent;

    if (percent < 0)
    {
        percent = 0;
    }

    if (percent > 100)
    {
        percent = 100;
    }

    double p = percent / 100.0;

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < image.channels; ++k)
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

    image.saveImage("output_image.jpg");

    return 0;
}