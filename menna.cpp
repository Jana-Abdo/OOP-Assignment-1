
# include "Image_Class.h"
# include <iostream>
using namespace std ;


void image_Resize (Image &image , int new_w, int new_h){

    Image new_image (new_w, new_h);

    for (int new_i=0; new_i < new_image.width ; ++new_i){

      for (int new_j=0; new_j < new_image.height ; ++new_j){
        
        int old_i= new_i * image.width/new_image.width;

        int old_j= new_j * image.height/new_image.height;


        for(int k=0 ; k<3; ++k){
          
            new_image(new_i,new_j,k)=image(old_i,old_j, k);

        }

      }
           
    }

      image=new_image;
}



void merge_images(Image &image1, Image &image2){

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

            image_Resize(image1,width,height);
            image_Resize(image2,width,height);



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
     for (int new_i =0 ; new_i < width;++new_i){

        for (int new_j=0; new_j< height; ++new_j){

            for(int k=0; k <3; ++k){

                merged_photo(new_i,new_j,k)=(image1(new_i,new_j,k)+image2(new_i,new_j,k))/2;

            
            }
        }
     }

     merged_photo.saveImage("merged photo.jpg");
    }
}


int main(){


    string name1, name2;
    
     cout<<"Enter first image name:";

     cin>> name1;

     cout<< "enter seconde image name:";

     cin>> name2;

     Image image1(name1);
     Image image2(name2);

     merge_images(image1, image2);

     cout<<" the two images are merged !";
        
     return 0 ;

}