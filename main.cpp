
// ================{ Team Information }=================
// ****[Team members]****
// # Name #                       #  IDs  #             # filters #
// Menna Ahmed                   20250671            1-Gray scale..... 5-Flip
// Jana Abd Elmaqsoud            20251103            2-Black & White...6-Invert
// Habiba Khalaf                 20251116            3-Darken......... 7- Lighten
// Haidy Atef Abdullah           20251468            4-Frame ......... 8-Resize

                            // *** Section Num *** : ......

#include <iostream>
#include "Image_Class.h"
#include <fstream>
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

    cout << "Enter frame thickness : ";
    cin >> F;
    int newWidth = w + 2 * F;
    int newHeight = h + 2 * F;
    Image newImage(newWidth, newHeight);
    
    string typeframe;
    cout << "Enter the frame type simple or fancy : ";
    cin >> typeframe;

    if (typeframe == "simple" || typeframe == "Simple") {
        cout << "Enter Frame color (RGB) : ";
        int R1, G1, B1;
        cin >> R1 >> G1 >> B1; 
        int color1[3] = { R1, G1, B1 };

        for (int i = 0 ; i < newWidth ; i++) {
            for (int j = 0 ; j < newHeight ; j++) {
                for (int k = 0 ; k < image.channels; k++) {
                    if (i >= F && i < newWidth - F && j >= F && j < newHeight - F) {
                        newImage(i, j, k) = image(i - F, j - F, k);
                    }
                    else {
                        newImage(i, j, k) = color1[k];
                    }  
                }
            }
        }
    }
    else if (typeframe == "fancy" || typeframe == "Fancy") {
        cout << "Enter Frame color (RGB) : ";
        int R1, G1, B1;
        cin >> R1 >> G1 >> B1; 
        int color1[3] = { R1, G1, B1 };
        
        cout << "Enter outer border thickness : ";
        cin >> f;
        cout << "Enter outer border color (RGB) : ";
        int R2, G2, B2;
        cin >> R2 >> G2 >> B2;
        int color2[3] = { R2, G2, B2 };

        for (int i = 0 ; i < newWidth ; i++) {
            for (int j = 0 ; j < newHeight ; j++) {
                for (int k = 0 ; k < image.channels; k++) {
                    if (i >= F && i < newWidth - F && j >= F && j < newHeight - F) {
                        newImage(i, j, k) = image(i - F, j - F, k);
                    }
                    else if((i >= 0 && i <= f ) || ( i >= newWidth -0.5F-f && i <= newWidth - 0.5F) || 
                   (j >= 0 && j <= f ) || (j >= newHeight-0.5F-f && j <= newHeight-0.5F) ) {
                    }
                    else {
                        newImage(i, j, k) = color1[k];
                    }  
                }
            }
        }
    }
    return newImage;
}
/////*/////*/////*/////*/////*/////*/////*/////*
void FlipImage(Image& image )
{
    int flip;
    cout << "Enter 1 for horizontal flip or 2 for vertical flip: ";
    cin >> flip;
    while (flip != 1 && flip != 2) {
        cout << "Invalid input. Please enter 1 or 2 : ";
        cin >> flip;
    }
Image copy = image;
if (flip == 1){
cout << "Horizontal flip" << endl;
      for (int i = 0; i < image.width; ++i)

{
      for (int j = 0; j < image.height; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            image(i, j, k) = copy(image.width - 1 - i, j, k);
        }
    }
}
}
else if (flip == 2)   
{
    cout << "Vertical flip" << endl;
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = copy(i, image.height - 1 - j, k);
            }
        }
    }
}
}
/////*/////*/////*/////*/////*/////*/////*/////*
void Invert(Image& image) {
    for(int i = 0; i < image.width; i++) {
        for(int j = 0; j < image.height; j++) {
          for(int k = 0; k < image.channels; k++) {
            image(i,j,k) = 255 - image(i,j,k);
          }
        }
    }
}
/////*/////*/////*/////*/////*/////*/////*/////*
void Lighten(Image& image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                int pixelValue = image(i, j, k);

                pixelValue = pixelValue + (255 - pixelValue) * 0.5;

                image(i, j, k) = pixelValue;
            }
        }
    }
}
/////*/////*/////*/////*/////*/////*/////*/////*
Image Resize(Image image) {
    int newWidth;
    int newHeight;
    int w = image.width;
    int h = image.height;
    cout << "Enter New width : ";
    cin >> newWidth;
    cout << "Enter New height : ";
    cin >> newHeight;
    
    Image newImage(newWidth, newHeight);
    for (int i = 0 ; i < newWidth ; i++) {
        for (int j = 0 ; j < newHeight ; j++) {
            for (int k = 0 ; k < image.channels; k++) {
                int Wlim = (i * w) / newWidth;
                int Hlim = (j * h) / newHeight;
                if (Wlim >= w) {
                    Wlim = w - 1;
                }
                if (Hlim >= h) {
                    Hlim = h - 1;
                }
                newImage(i, j, k) = image(Wlim, Hlim, k);
            }
        }
    }
    return newImage;
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
/////*/////*/////*/////*/////*/////*/////*/////*
int main(){
    string name;
    while(true){ 
        cout<<"Enter image name: ";
        cin>>name;
        if(exists(name) && valid(name))
            break;
        cout<<"Invalid file\n";
     }
    Image image(name);
    bool changed = false;
    int choice;
    while(true){
    cout<<"Choose from 1 to 11\n";
    cout<<"Filter1: GrayScale\n";
    cout<<"Filter2: Black And White\n";
    cout<<"Filter3: Darken\n";
    cout<<"Filter4: Frame \n";
    cout<<"Filter5: FlipImage\n";
    cout<<"Filter6: Invert \n";
    cout<<"Filter7: lighten\n";
    cout<<"Filter8: Resize\n";
    cout<<"load new image 9\n";
    cout<<"Save image 10\n";
    cout<<"Exit 11\n";
    cin>>choice;
    if(choice == 1){
        Grayscale(image);
        changed = true;
     }
    else if(choice == 2) {
        blackAndwhite(image); 
        changed = true;
    }
      else if (choice == 3) {
       Darken(image);
       changed = true;
     }
      else if (choice == 4) {
        image = Frame(image);
         changed = true;
    }
       else if (choice == 5) {
        FlipImage(image);
         changed = true;
    }
    else if (choice == 6) {
        Invert(image); 
        changed = true;
    }
  
    else if (choice == 7) {
        Lighten(image);
        changed = true;
      }
    else if (choice == 8) {
       image = Resize(image);
        changed = true;
      }
   
    else if(choice == 9) {
        if(changed){
            char x;
            cout<<"Save current image? (y/n)";
            cin>>x;
            if(x=='y'|| x=='Y') {
                cout<<"Save as: ";
                cin>>name;
                image.saveImage(name);
            }
        }
        cout<<"Enter new image name: ";
        cin>>name;
        if(exists(name) && valid(name)) {
            image.loadNewImage(name);
            changed = false;
         }
        else cout<<"Invalid file\n";
    }
    else if (choice == 10) {
        cout<<"Save as: ";
        cin>>name;
        if(valid(name)) {
            image.saveImage(name);
            changed = false; 
         }
            else cout<<"Invalid extension\n";
         }

         else if(choice == 11) {
            if(changed) {
                char x;
                cout<<"Save before exit? (y/n)";
                cin>>x;
                if(x=='y'|| x=='Y') {
                    cout<<"Save as: ";
                    cin>>name; 
                    image.saveImage(name);
                }
              }
            break;
         }

         else cout<<"Invalid choice\n";
         }
      return 0;
}