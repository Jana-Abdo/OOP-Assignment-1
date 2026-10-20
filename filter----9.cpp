#include "Image_Class.h"
#include <iostream>
using namespace std;

void Image_Resize (Image &image , int new_w, int new_h){

    Image new_image (new_w, new_h);

    for (int new_i=0; new_i < new_image.width ; ++new_i){

      for (int new_j=0; new_j < new_image.height ; ++new_j){
        
        int old_x= new_i * image.width/new_image.width;

        int old_y= new_j * image.height/new_image.height;


        for(int color=0 ; color<3; ++color){
          
            new_image(new_i,new_j,color)=image(old_x,old_y, color);

        }

      }
           
    }

      image=new_image;
}



void Merge(Image &image1, Image &image2, Image &image){

    int width, height;
    if (image1.width==image2.width && image1.height==image2.height){

        width=image1.width; height=image1.height;
    }

    else{

        int choice;

        cout<<" the two_images have different sizes \n";
        cout << "choose one of two options\n";
        cout<< " choose 1  resize to the beggist size\n";
        cout<<" choose 2  merge common_area\n";

        cin>> choice;

        if(choice==1){
         
            if(image1.width>image2.width){

                width=image1.width;
    
            }

            else{ width =image2.width;}

            if(image1.height>image2.height){

                height=image1.height;
    
            }

            else{height=image2.height;}

            Image_Resize(image1,width,height);
            Image_Resize(image2,width,height);



        }

         else if  (choice==2){
         
            if(image1.width<image2.width){

                width=image1.width;
    
            }

            else{ width =image2.width;}

            if(image1.height<image2.height){

                height=image1.height;
    
            }
             else{height=image2.height;}
            

    }

    else{

        cout<<"invalid choice";
    }

      

    Image merged_photo(width,height);
     for (int x =0 ; x < width;++x){

        for (int y=0; y< height; ++y){

            for(int color=0; color <3; ++color){

                merged_photo(x,y,color)=(image1(x,y,color)+image2(x,y,color))/2;

            
            }
        }
     }
     image =  merged_photo;

    }
}