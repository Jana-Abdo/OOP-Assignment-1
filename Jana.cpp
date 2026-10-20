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
 void rotateImage(Image& m, int angle) {
    Image temp;
    if (angle == 90 || angle == 270) {
        temp = Image(m.height, m.width);
    } 
    else {
        temp = Image(m.width, m.height);
    }
     for (int i = 0; i < temp.width; i++) {
        for (int j = 0; j < temp.height; j++) {
            for (int k = 0; k < m.channels; k++) {
                if (angle == 90) {
                    temp(i, j, k) = m(j, m.height - 1 - i, k);
                }
                else if (angle == 180) {
                    temp(i, j, k) = m(m.width - 1 - i, m.height - 1 - j, k);
                }
                else if (angle == 270) {
                    temp(i, j, k) = m(m.width - 1 - j, i, k);
                }
            }
        }
    }

    m = temp;
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
void TV(Image& m) {
    for (int i = 0; i < m.height; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m.width; j++) {
                m(j, i, 0) *= 0.5;
                m(j, i, 1) *= 0.5;
                m(j, i, 2) *= 0.5;
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
    cout<<"For Rotate Filter--->2\n";
    cout<<"For Detcted Edges Filter--->3\n";
    cout<<"For Tv filter--->4\n";
    cout<<"For load new image --->5\n";
    cout<<"For save image ---> 6\n";
    cout<<"To exit --->7\n";
    cin>>choice;
    if(choice == 1) {
        blackAndwhite(m); 
        changed = true;
    }
    else if (choice == 2) {
        int angle;
        cout<<"Choose rotation angle (90, 180, 270): ";
        cin>>angle;
        rotateImage(m,angle);
        changed = true;
    }
     if(choice == 3) {
        DetectEdge(m); 
        changed = true;
    }
     if(choice == 4) {
        TV(m); 
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
