#include <iostream>
#include "Image_Class.h"


using namespace std;

Image IV (Image image) {

    Image newImage (image.width,image.height);
      for ( int i=0 ; i < image.width ; i++){
        for (int j=0 ; j < image.height ; j++){
                 newImage (i , j , 0) = 255;
                 newImage (i , j , 1) = 255 -image (i , j , 1);
                 newImage (i , j , 2) = 255 - image (i , j , 2) ;
        
        }
    }
 newImage.saveImage ("luffyIV.png");
 return newImage;

}