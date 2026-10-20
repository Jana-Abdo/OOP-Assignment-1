#include <iostream>
#include "Image_Class.h"


using namespace std;

Image blur (Image image) {
    int d ;
    cout << "Enter number of level blur : ";
    cin >> d;
    
    Image newImage (image.width,image.height);
      for ( int i=0 ; i < image.width ; i++){
        for (int j=0 ; j < image.height ; j++){
            for (int k=0 ; k < image.channels; k++){
              int color = 0;
              int count = 0;

               for (int Si=i-d ; Si <= i+d ; Si++ ) {
                 for (int Sj=j-d ; Sj <= j+d ; Sj++ ) {
        
                     if (Si >= 0 && Sj >= 0 && Si < image.width && Sj < image.height) {
                     count ++;
                
                       color += image ( Si , Sj , k ) ; 
                     }
                } 
             }
             int avg = color / count ;
             newImage (i , j , k) = avg;
                
         }
        }
    }
     
     newImage.saveImage ("luffyBlured.png");
     return newImage;
    }