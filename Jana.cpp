#include "Jana.h"
#include <iostream>
#include "Image_Class.h"
using namespace std;
int main(){
    Image m("flower.jpg") ;
    for(int i=0;i<m.width;i++){
        for(int j=0;j<m.height;j++){
          for(int k=0;k<3;k++){
            m(i,j,k)=255-m(i,j,k);
          
            }
        }

    }
m.saveImage("flower.jpg");

    return 0;
} 