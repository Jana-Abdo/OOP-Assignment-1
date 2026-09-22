#include "Jana.h"
#include <iostream>
#include "Image_Class.h"
using namespace std;
int main(){
   Image m("flower.jpg");
    for(int i=0; i<m.width; ++i) {
      for(int j=0; j<m.height; ++j) {
         unsigned int avg=0;
          for (int k=0; k<m.channels; ++k) {
                avg += m(i, j, k);
            }
            avg /= m.channels; 
            unsigned char color;
            if (avg>127){color=255;}
            else {color=0;}
            for (int k=0; k<m.channels; ++k) {
                m(i, j, k)=color;
            }
        }
    }
    m.saveImage("flower.jpg");
    return 0;
} 