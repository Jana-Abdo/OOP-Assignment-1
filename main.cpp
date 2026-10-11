#include "menna.cpp"

using namespace std;
int main() {
    
    Image bird("mena.jpg");
    sunlight_brightness(bird); 
    bird.saveImage("mena_sunlight.jpg");
    return 0;
}