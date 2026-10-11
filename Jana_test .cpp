#include "Jana.h"
#include <iostream>
#include "Image_Class.h"
#include <fstream>
using namespace std;
void blackAndwhite(Image& m){
    for(int i = 0; i < m.width; i++) {
      for(int j = 0; j < m.height; j++) {
         unsigned int avg = 0;
          for (int k = 0; k < m.channels; k++) {
                avg += m(i, j, k);
            }
            avg /= m.channels; 
            unsigned char color;
            if (avg > 127) {
                color = 255;
            }
            else {
                color = 0;
            }
            for (int k = 0; k < m.channels; k++) {
                m(i, j, k) = color;
            }
        }
    }
}
/////*/////*/////*/////*/////*/////*/////*/////*

void invert(Image& m) {
    for(int i = 0; i < m.width; i++) {
        for(int j = 0; j < m.height; j++) {
          for(int k = 0; k < m.channels; k++) {
            m(i,j,k) = 255 - m(i,j,k);
          }
        }
    }
}
/////*/////*/////*/////*/////*/////*/////*/////*
bool exists(string name) {
    ifstream file(name) ;
    return file.good();
}
bool valid(string name) {
    int p = name.find_last_of('.');
    if(p == -1){
        return false;
    }
        string ext = name.substr(p+1);
        return ext=="jpg"||ext=="jpeg"||ext=="png"||ext=="bmp"||ext=="tga";
}   

int main(){
    string name;
    while(true){ 
        cout<<"Enter image name: ";
        cin>>name;
        if(exists(name) && valid(name))
            break;
        cout<<"Invalid file\n";
     }
    Image m(name);
    bool changed = false;
    int choice;
    while(true){
    cout<<"For Black And White Filter---> 1\n";
    cout<<"For Black Invert color Filter--->2\n";
    cout<<"For load new image --->3\n";
    cout<<"For save image ---> 4\n";
    cout<<"To exit --->5\n";
    cin>>choice;
    if(choice == 1) {
        blackAndwhite(m); 
        changed = true;
    }
    else if (choice == 2) {
        invert(m); 
        changed = true;
    }
    else if(choice == 3) {
        if(changed){
            char x;
            cout<<"Save current image? (y/n)";
            cin>>x;
            if(x=='y'|| x=='Y') {
                cout<<"Save as: ";
                cin>>name;
                m.saveImage(name);
            }
        }
        cout<<"Enter new image name: ";
        cin>>name;
        if(exists(name) && valid(name)) {
            m.loadNewImage(name);
            changed = false;
         }
        else cout<<"Invalid file\n";
    }
    else if (choice == 4) {
        cout<<"Save as: ";
        cin>>name;
        if(valid(name)) {
            m.saveImage(name);
            changed = false; 
         }
            else cout<<"Invalid extension\n";
         }

         else if(choice == 5) {
            if(changed) {
                char x;
                cout<<"Save befofe exit? (y/n)";
                cin>>x;
                if(x=='y'|| x=='Y') {
                    cout<<"Save as: ";
                    cin>>name; 
                    m.saveImage(name);
                }
              }
            break;
         }

         else cout<<"Invalid choice\n";
         }
      return 0;
} 
