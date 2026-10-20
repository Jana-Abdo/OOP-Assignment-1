#include <iostream>
#include "Image_Class.h"

using namespace std;

 
Image frame (Image image , int F) {
    int w , h  ;
      w = image.width ; h = image.height; 


     int newWidth = w + 2*F;
     int newHeight = h + 2*F;
     Image newImage ( newWidth ,   newHeight );
     
     string typeframe ;
     cout << "Enter the frame type simple or fancy :";
     cin >> typeframe;

     if (typeframe == "simple") {

     cout << "Enter Frame color :" ;
     int R1 , G1 ,B1 ;
     cin >> R1 >> G1 >> B1; 
     int color1 [3] = { R1 , G1 , B1 };

     for (int i = 0 ; i <  newWidth ; i++ ) {
        for (int j = 0 ; j < newHeight ; j++) {
            for ( int k = 0 ; k <3; k++ ) {
            if (i >= F && i < newWidth-F && j >= F && j < newHeight-F) {
            newImage (i , j , k ) = image (i-F , j-F , k) ;
            }
            else
            {
             newImage (i , j , k ) = color1 [k];
            }  
            }
        }
    
      }
    }
      else if (typeframe == "fancy")
    {
         cout << "Enter main Frame color :" ;
          int  R1 ,G1 ,B1 ;
          cin >> R1 >> G1 >> B1; 
          int color1 [3] = { R1 , G1 , B1 };
          cout << "Enter secondry frame color:";
           int  R2 ,G2 ,B2 ;
          cin >> R2 >> G2 >> B2;
          int color2 [3] = { R2 , G2 , B2 };

       for (int i = 0 ; i <  newWidth ; i++ ) {
            for (int j = 0 ; j < newHeight ; j++) {
              for ( int k = 0 ; k <3; k++ ) {
              if (i >= F && i < newWidth-F && j >= F && j < newHeight-F) {
              newImage (i , j , k ) = image (i-F , j-F , k) ;
              }
              else if((i >= 0 && i <= 7 ) || ( i >= newWidth -0.5F-7 && i <= newWidth - 0.5F) || 
               (j >= 0 && j <= 7 ) || (j >= newHeight-0.5F-7 && j <= newHeight-0.5F) ) {
                 newImage (i , j , k ) = color2 [k];
                }
               
              else
               {
               newImage (i , j , k ) = color1 [k];
              }  
              
              }
            }
    
        }
    }
    newImage.saveImage ("scream_framed.png");

    return newImage;
    }
    
  