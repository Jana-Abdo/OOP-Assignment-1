#include "menna.h"
#include "menna.cpp"
using namespace std;
int main() {
    Image flower("flower.jpg");
    Image bird("bird.jpg");

    mergeImages(flower, bird  ); 
    return 0;
}