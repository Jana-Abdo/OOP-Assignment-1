#include <iostream>
#include "Image_Class.h"


using namespace std;

Image Resize(Image image) {
    int newWidth;
    int newHeight;
    int w = image.width;
    int h = image.height;
    cout << "Enter New width : ";
    cin >> newWidth;
    cout << "Enter New height : ";
    cin >> newHeight;
    
    Image newImage(newWidth, newHeight);
    for (int i = 0 ; i < newWidth ; i++) {
        for (int j = 0 ; j < newHeight ; j++) {
            for (int k = 0 ; k < image.channels; k++) {
                int Wlim = (i * w) / newWidth;
                int Hlim = (j * h) / newHeight;
                if (Wlim >= w) {
                    Wlim = w - 1;
                }
                if (Hlim >= h) {
                    Hlim = h - 1;
                }
                newImage(i, j, k) = image(Wlim, Hlim, k);
            }
        }
    }
    return newImage;
}