#include "menna.h"
using namespace std;
void resizeImage(Image image, int newWidth, int newHeight , Image& result){
    for (int i = 0 ; i < newWidth; ++i){
        for (int j = 0 ; j < newHeight; ++j){
            int oldI = i * image.width / newWidth;
            int oldJ = j * image.height / newHeight;
            for (int k = 0; k < image.channels; ++k) {
                result(i, j, k) = image(oldI, oldJ, k);
            }
        }
    }
}
void mergeImages (Image image1, Image image2){
    int newWidth;
    int newHeight;
    if (image1.width == image2.width && image1.height == image2.height){
        newWidth = image1.width;
        newHeight = image1.height;
    }
    else{
        int choice;
        cout << "The images have different dimensions" << endl;
        cout << "1. resize the first image to match the second image" << endl;
        cout << "2. resize the second image to match the first image" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1){
            newWidth = image2.width;
            newHeight = image2.height;}
            else  if (choice == 2){
                newWidth = image1.width;
                newHeight = image1.height;
            }
            else{
                cout << "Invalid choice." << endl;
                return;
            }
        }
                
        
    
        Image resizedImage1(newWidth, newHeight);
        Image resizedImage2(newWidth, newHeight);
        resizeImage(image1, newWidth, newHeight, resizedImage1);
        resizeImage(image2, newWidth, newHeight, resizedImage2); 
        Image result(newWidth, newHeight);
        for (int i = 0 ; i < newWidth; ++i){
            for (int j = 0 ; j < newHeight; ++j){
                for (int k = 0; k < image1.channels; ++k) {
                    int pixel1 = resizedImage1(i, j, k);
                    int pixel2 = resizedImage2(i, j, k);
                    result(i, j, k) = (pixel1 + pixel2) / 2;
                }
            }   
        }
        result.saveImage("merge.jpg");
    }
