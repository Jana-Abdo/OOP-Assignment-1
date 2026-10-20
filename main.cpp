//This file explains Assignment 1(Baby Photoshop project) that allows users to add filters to images.

// ================{ Team Information }=================
// ****[Team members]****
// # Name #                      #  IDs  #             # filters #
// Menna Ahmed                   20250671            1-Gray scale..... 5-Flip
// Jana Abd Elmaqsoud            20251103            2-Black & White...6-Invert
// Habiba Khalaf                 20251116            3-Darken......... 7- Lighten
// Haidy Atef Abdullah           20251468            4-Frame ......... 8-Resize

                            // *** Section Num *** : S30

#include <iostream>
#include "Image_Class.h"
#include "Heidi.cpp"
using namespace std;

void Grayscale(Image& image){
   for (int i = 0; i < image.width; ++i)    {    
    for (int j = 0; j < image.height; ++j)   {           
 int avg = 0;        
   for (int k = 0; k < 3; ++k)      {        
    avg += image(i, j, k);             }       
      avg = avg / 3;         
    for (int k = 0; k < 3; ++k)             {             
   image(i, j, k) = avg;        
     }   
      }  
  }
}
/////*/////*/////*/////*/////*/////*/////*/////*
void blackAndwhite(Image& image){
    for(int i = 0; i < image.width; i++) {
        for(int j = 0; j < image.height; j++) {
             unsigned int avg = 0;
             for (int k = 0; k < image.channels; k++) {
                 avg += image(i, j, k);
                  }
            avg /= image.channels; 
            unsigned char color;
            if (avg > 127) {
                 color = 255;
                 }
             else {
                color = 0;
            }
    for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = color;
            }
        }
    }
}
/////*/////*/////*/////*/////*/////*/////*/////*
void Darken(Image& image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                int pixelValue = image(i, j, k);

                pixelValue = pixelValue * 0.5;

                image(i, j, k) = pixelValue;
            }
        }
    }
}
/////*/////*/////*/////*/////*/////*/////*/////*
Image Frame(Image image) {
    int w = image.width; 
    int h = image.height;
    int F, f;

int main (){
Image img("scream.png");

    frame(img ,  20);
     
         

        image = temp;
    }
/////*/////*/////*/////*/////*/////*/////*/////*
void DetectEdge(Image& image) {
    Image temp = image; 
    for (int i = 0; i < image.width - 1; i++) {
        for (int j = 0; j < image.height - 1; j++) {
            int current = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            int right   = (image(i + 1, j, 0) + image(i + 1, j, 1) + image(i + 1, j, 2)) / 3;
            int bottom  = (image(i, j + 1, 0) + image(i, j + 1, 1) + image(i, j + 1, 2)) / 3;
            int x = abs(current - right);
            int y = abs(current - bottom);
            int color;
            if (x > 40 || y > 40) {
                color = 0;
            }
            else {
                color = 255;
            }
           
            for (int k = 0; k < image.channels; k++) {
                temp(i, j, k) = color;
            }
        }
    }
    image = temp;
}
 
