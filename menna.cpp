#include "Image_Class.h"
# include "menna.h"
using namespace std;
void flipImage(Image& image )
{
    int flip;
    cout << "Enter 1 for horizontal flip or 2 for vertical flip: ";
    cin >> flip;
    while (flip != 1 && flip != 2) {
        cout << "Invalid input. Please enter 1 or 2 : ";
        cin >> flip;
    }


Image copy = image;
if (flip == 1){
cout << "Horizontal flip" << endl;
      for (int i = 0; i < image.width; ++i)

{
      for (int j = 0; j < image.height; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            image(i, j, k) = copy(image.width - 1 - i, j, k);
        }
    }
}
}
else if (flip == 2)   
{
    cout << "Vertical flip" << endl;
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = copy(i, image.height - 1 - j, k);
            }
        }
    }
}
}
