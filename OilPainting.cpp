#include <iostream>
#include "Image_Class.h"


using namespace std;

Image oilPainting(Image image) {
    int d = 7;
    int levels = 2;

    Image newImage(image.width, image.height);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            
            int intensityCount[16] = {0};
            int sumR[16] = {0};
            int sumG[16] = {0};
            int sumB[16] = {0};

            for (int Si = i - d; Si <= i + d; Si++) {
                for (int Sj = j - d; Sj <= j + d; Sj++) {
                    if (Si >= 0 && Sj >= 0 && Si < image.width && Sj < image.height) {
                        
                        int r = image(Si, Sj, 0);
                        int g = image(Si, Sj, 1);
                        int b = image(Si, Sj, 2);

                        int intensity = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
                        int level = (intensity * levels) / 256;
                        if (level >= levels) level = levels - 1;

                        intensityCount[level]++;
                        sumR[level] += r;
                        sumG[level] += g;
                        sumB[level] += b;
                    }
                }
            } 

            int bestLevel = 0, maxCount = 0;
            for (int c = 0; c < levels; c++) {
                if (intensityCount[c] > maxCount) {
                    maxCount = intensityCount[c];
                    bestLevel = c;
                }
            }

            if (maxCount > 0) {
                newImage(i, j, 0) = sumR[bestLevel] / maxCount;
                newImage(i, j, 1) = sumG[bestLevel] / maxCount;
                newImage(i, j, 2) = sumB[bestLevel] / maxCount;
            } else {
                newImage(i, j, 0) = image(i, j, 0);
                newImage(i, j, 1) = image(i, j, 1);
                newImage(i, j, 2) = image(i, j, 2);
            }
        }
    }

    newImage.saveImage("mountainPainted.png");
    return newImage;
}