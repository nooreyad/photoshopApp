#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include "bmplib.h"
#include "unistd.h"

using namespace std;
unsigned char image[SIZE][SIZE];

int IntegerChoice, choice;

void loadImage();
void BlackAndWhiteFilter();
void InvertFilter();
void MergeFilter();
void FlipImage();
void DarkenAndLightenImage();
void RotateImage();
void DetectImageEdges();
void EnlargeImage();
void ShrinkImage();
void MirrorHalfImage();
void ShuffleImage();
void BlurImage();
void saveImage();

int main() {
    cout << "Hello and welcome to our photoshop program\n";
    loadImage();
    cout << "Please choose one of the options below\n";
    cout << "1. Black & White Filter\n";
    cout << "2. Invert Filter\n";
    cout << "3. Merge Filter\n";
    cout << "4. Flip Image\n";
    cout << "5. Darken and Lighten Image\n";
    cout << "6. Rotate Image\n";
    cout << "7. Detect Image Edges\n";
    cout << "8. Enlarge Image\n";
    cout << "9. Shrink Image\n";
    cout << "a. Mirror 1/2 Image\n";
    cout << "b. Shuffle Image\n";
    cout << "c. Blur Image\n";
    cout << "s. Save the image to a file\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:{
            BlackAndWhiteFilter();
        }
        case 2:{
            InvertFilter();
        }
        case 3:{
            MergeFilter();
        }
        case 4:{
            FlipImage();
        }
        case 5:{
            DarkenAndLightenImage();
        }
        case 6:{
            RotateImage();
        }
        case 7:{
            DetectImageEdges();
        }
        case 8:{
            EnlargeImage();
        }
        case 9:{
            ShrinkImage();
        }
        case 'a':{
            MirrorHalfImage();
        }
        case 'b':{
            ShuffleImage();
        }
        case 'c':{
            BlurImage();
        }
        case 's':{
            saveImage();
        }
    }
}

void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void BlackAndWhiteFilter(){

}

void InvertFilter(){

}

void MergeFilter(){
    loadImage();
}

void FlipImage(){
    cout << "Please choose either\n1. for horizontal flipping\n2. for vertical flipping: ";
    cin >> IntegerChoice;
}

void DarkenAndLightenImage(){
    cout << "Please choose either\n1. for darkening\n2. for lightening: ";
    cin >> IntegerChoice;
}

void RotateImage(){
    cout << "Please choose either\n1. Rotate 90\n2. Rotate 180\n3. Rotate 360\n";
    cout << "Choice: ";
    cin >> IntegerChoice;
}

void DetectImageEdges(){

}

void EnlargeImage(){
    cout << "Which quarter to enlarge? 1, 2, 3 or 4: ";
    cin >> IntegerChoice;
}

void ShrinkImage(){
    cout << "Shrink to\n1. (1/2)\n2. (1/3)\n3. (1/4)\n";
    cout << "Choice: ";
    cin >> IntegerChoice;
}

void MirrorHalfImage(){
    cout << "Mirror\n1. Left\n2. Right\n3. Upper\n4. Down\n";
    cout << "Choice: ";
    cin >> IntegerChoice;
}

void ShuffleImage(){
    int order[4];
    cout << "Please enter new order of the 4 quarters: ";
    cin >> order[4];
}

void BlurImage(){

}
