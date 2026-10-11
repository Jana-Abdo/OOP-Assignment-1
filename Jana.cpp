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
void DetectEdge(Image& m) {
    Image temp = m; 
    for (int i = 0; i < m.width - 1; i++) {
        for (int j = 0; j < m.height - 1; j++) {
            int current = (m(i, j, 0) + m(i, j, 1) + m(i, j, 2)) / 3;
            int right   = (m(i + 1, j, 0) + m(i + 1, j, 1) + m(i + 1, j, 2)) / 3;
            int bottom  = (m(i, j + 1, 0) + m(i, j + 1, 1) + m(i, j + 1, 2)) / 3;
            int x = abs(current - right);
            int y = abs(current - bottom);
            int color;
            if (x > 40 || y > 40) {
                color = 0;
            }
            else {
                color = 255;
            }
           
            for (int k = 0; k < m.channels; k++) {
                temp(i, j, k) = color;
            }
        }
    }
    m = temp;
}
/////*/////*/////*/////*/////*/////*/////*/////*
void SimpleBlur(Image& m) {
    Image temp = m;
    for(int i = 1; i < m.width - 1; i++) {
        for(int j = 1; j < m.height  - 1; j++) {
             for (int k = 0; k < m.channels; k++) {
                int s = 0;
                for(int x = -1; x <= 1; x++){
                    for(int y = -1; y <= 1; y++){
                        s += m(i + x, j + y, k);
                     }
                    }
                    temp(i, j, k) = s / 9;
                }
            }
        }

        m = temp;

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
    cout<<"For Dected Edges Filter--->3\n";
    cout<<"For Simple Blur Filter--->4\n";
    cout<<"For load new image --->5\n";
    cout<<"For save image ---> 6\n";
    cout<<"To exit --->7\n";
    cin>>choice;
    if(choice == 1) {
        blackAndwhite(m); 
        changed = true;
    }
    else if (choice == 2) {
        invert(m); 
        changed = true;
    }
     if(choice == 3) {
        DetectEdge(m); 
        changed = true;
    }
     if(choice == 4) {
        SimpleBlur(m); 
        changed = true;
    }
    else if(choice == 5) {
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
    else if (choice == 6) {
        cout<<"Save as: ";
        cin>>name;
        if(valid(name)) {
            m.saveImage(name);
            changed = false; 
         }
            else cout<<"Invalid extension\n";
         }

         else if(choice == 7) {
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
