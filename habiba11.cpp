#include "Image_Class.h"
#include <iostream>
using namespace std;

int main()
{
    Image image("apple.jpg");

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, k) = 255 - image(i, j, k);
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
/////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////
#include "Image_Class.h"
#include <iostream>
using namespace std;

void crop(Image& image)
{
    int x, y, cropwidth, cropheight;

    cout << "Current image width: " << image.width << endl;
    cout << "Current image height: " << image.height << endl;

    cout << "Enter the starting X position: ";
    cin >> x;

    cout << "Enter the starting Y position: ";
    cin >> y;

    cout << "Enter crop width: ";
    cin >> cropwidth;

    cout << "Enter crop height: ";
    cin >> cropheight;

    if (x >= 0 && y >= 0 &&
        cropwidth > 0 && cropheight > 0 &&
        x + cropwidth <= image.width &&
        y + cropheight <= image.height)
    {
        Image cropped_image(cropwidth, cropheight);

        for (int i = 0; i < cropwidth; i++)
        {
            for (int j = 0; j < cropheight; j++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int pixelvalue =
                        image.getPixel(x + i, y + j, c);

                    cropped_image.setPixel(i, j, c, pixelvalue);
                }
            }
        }

        image = cropped_image;
    }
    else
    {
        cout << "The entered crop area is not valid." << endl;
    }
}

int main()
{
    Image image("apple.jpg");

    crop(image);

    image.saveImage("cropped_image2.jpg");

    return 0;
}

/////////////////////////////////////////////////////////////
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
