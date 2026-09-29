#include <iostream>
#include "Image_Class.h"
#include "menna.h"
#include "menna.cpp"
using namespace std;


int main (){
    
    Image image("flower.jpg");
    grayscale(image);
    image.saveImage("gray.jpg");
    cout<<image.width<<endl;
    cout<<image.height<<endl;

 
    return 0;
}
