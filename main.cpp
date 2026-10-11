#include "grayscale.cpp"

using namespace std;
int main() {
    
    Image image("mena.jpg");
    grayscale(image);
    image.saveImage("mena_grayscale.jpg");
    return 0;
}