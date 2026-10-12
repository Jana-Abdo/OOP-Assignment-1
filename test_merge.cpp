#include "menna.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name1, name2;

    cout << "Enter first image name: ";
    cin >> name1;

    cout << "Enter second image name: ";
    cin >> name2;

    Image image1(name1);
    Image image2(name2);

    mergeImages(image1, image2);

    return 0;
}