
#include "menna.h"
#include <iostream>
using namespace std;

void mergeImages(Image image1, Image image2, Image& result)
{
int newWidth;
int newHeight;

if (image1.width == image2.width &&  
    image1.height == image2.height)  
{  
    newWidth = image1.width;  
    newHeight = image1.height;  
}  
else  
{  
    int choice;  

    cout << "The images have different dimensions.\n";  
    cout << "1. Resize the first image to match the second.\n";  
    cout << "2. Resize the second image to match the first.\n";  
    cout << "Enter your choice: ";  
    cin >> choice;  

    if (choice == 1)  
    {  
        newWidth = image2.width;  
        newHeight = image2.height;  
    }  
    else if (choice == 2)  
    {  
        newWidth = image1.width;  
        newHeight = image1.height;  
    }  
    else  
    {  
        cout << "Invalid choice.\n";  
        return ;
    }  
}  

Image resizedImage1(newWidth, newHeight);  
Image resizedImage2(newWidth, newHeight);  

resizeImage(image1, newWidth, newHeight, resizedImage1);  
resizeImage(image2, newWidth, newHeight, resizedImage2);  

Image result(newWidth, newHeight);  

for (int i = 0; i < newWidth; ++i)  
{  
    for (int j = 0; j < newHeight; ++j)  
    {  
        for (int k = 0; k < result.channels; ++k)  
        {  
            int pixel1 = resizedImage1(i, j, k);  
            int pixel2 = resizedImage2(i, j, k);  

            result(i, j, k) = (pixel1 + pixel2) / 2;  
        }  
    }  
}  

cout << "Merge completed!\n";  

return ;

} 