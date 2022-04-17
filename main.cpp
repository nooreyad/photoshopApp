#include <cstring>
#include <iostream>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE], SecondImage[SIZE][SIZE];


void loadImage();
void BlackAndWhiteFilter();
void InvertFilter();
void MergeFilter();
void FlipImage();
void DarkenAndLightenImage();
void RotateImage();
void DetectImageEdges();
//void EnlargeImage();
//void ShrinkImage();
//void MirrorHalfImage();
//void ShuffleImage();
//void BlurImage();
//void saveImage();

int main() {
    char choice;

    cout << "Hello and welcome to our photoshop program\n";
    cout << "Please choose one of the options below\n";
    cout << "1. Black & White Filter\n";
    cout << "2. Invert Filter\n";
    cout << "3. Merge Filter\n";
    cout << "4. Flip Image\n";
    cout << "5. Darken and Lighten Image\n";
    cout << "6. Rotate Image\n";
    cout << "7. Detect Image Edges\n";
//    cout << "8. Enlarge Image\n";
//    cout << "9. Shrink Image\n";
//    cout << "a. Mirror 1/2 Image\n";
//    cout << "b. Shuffle Image\n";
//    cout << "c. Blur Image\n";
//    cout << "s. Save the image to a file\n";
//    cout << "0. Exit\n";
//    cout << "Your choice: ";
    cin >> choice;
    while (choice != 0) {
        while (choice == '1') {
            BlackAndWhiteFilter();
            break;
        }
        while (choice == '2') {
            InvertFilter();
            break;
        }
        while (choice == '3') {
            MergeFilter();
            break;
        }
        while (choice == '4') {
            FlipImage();
            break;
        }
        while (choice == '5') {
            DarkenAndLightenImage();
            break;
        }
        while (choice == '6') {
            RotateImage();
            break;
        }
        while (choice == '7') {
            DetectImageEdges();
            break;
        }
        while (choice == '8') {
            EnlargeImage();
            break;
        }
        while (choice == '9') {
            ShrinkImage();
            break;
        }
        while (choice == 'a') {
            MirrorHalfImage();
            break;
        }
        while (choice == 'b') {
            ShuffleImage();
            break;
        }
        while (choice == 'c') {
            BlurImage();
            break;
        }
        while (choice == 's') {
            saveImage();
            break;
        }
    }
    if (choice == 0){
        cout << "Thank you for using our program\nGoodbye!";
    }
    else{
        while (choice != 0){
            cout << "Invalid input, Please re-enter the chosen filter: ";
            cin >> choice;
            break;
        }
    }
}

void loadImage () {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void loadSecondImage () {
    char imageFileName[100];
    cout << "Enter the source of the second image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, SecondImage);
}

void saveImage() {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void BlackAndWhiteFilter(){
    loadImage();
    long avg = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    saveImage();
}

void InvertFilter(){
    loadImage();
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i][j] = 255 - image[i][j];
        }
    }
    saveImage();

}

void MergeFilter(){
    loadImage();
    loadSecondImage();
    for (int i = 0; i < SIZE; i++){
        for (int j = i % 2; j < SIZE; j+=2){
            image[i][j] = SecondImage[i][j];
        }
    }
    saveImage();
}

void FlipImage(){
    loadImage();
    char choice;
    cout << "Please choose either\n1. for horizontal flipping\n2. for vertical flipping\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice){
        case '1':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    SecondImage[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][j] = SecondImage[255-i][j];
                }
            }
            break;

        case '2':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    SecondImage[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][j] = SecondImage[i][255-j];
                }
            }
            break;
        default:
            break;
    }
    saveImage();
}

void DarkenAndLightenImage(){
    loadImage();
    char choice;
    cout << "Please choose either\n1. for darkening\n2. for lightening\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice){
        case '1':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    if(image[i][j] - 64 > 0){
                        image[i][j] -= 64;
                    }
                    else{
                        image[i][j] = 0;
                    }
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    if(image[i][j] + 64 < 255){
                        image[i][j] += 64;
                    }
                    else{
                        image[i][j] = 255;
                    }
                }
            }
            break;
        default:
            break;
    }
    saveImage();
}

void RotateImage(){
    loadImage();
    char choice;
    cout << "Please choose either\n1. Rotate 90\n2. Rotate 180\n3. Rotate 270\n";
    cout << "Choice: ";
    cin >> choice;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            SecondImage[i][j] = image[i][j];
        }
    }
    switch (choice){
        case '1':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][j] = SecondImage[255-j][i];
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][j] = SecondImage[255-i][255-j];
                }
            }
            break;
        case '3':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][j] = SecondImage[j][255-i];
                }
            }
            break;

        default:
            break;
    }
    saveImage();
}

void DetectImageEdges(){
    loadImage();
    long avg = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j+1] == 255 || image[i+1][j] == 255 || image[i+1][j+1] == 0 || image[i-1][j-1] == 255
            || image[i-1][j] == 255 || image[i][j-1] == 255 || image[i+1][j - 1] == 255 || image[i-1][j+1] == 255) {
                image[i][j] = 0;
            } else {
                if (image[i][j + 1] == 0 || image[i + 1][j] == 0 || image[i + 1][j + 1] == 0|| image[i - 1][j - 1] == 0
                || image[i - 1][j] == 0 || image[i][j-1] == 0 || image[i+1][j-1] == 0 || image[i-1][j+1] == 0) {
                    image[i][j] = 255;
                }
            }
        }
    }
    saveImage();
}

//void EnlargeImage(){
//    cout << "Which quarter to enlarge? 1, 2, 3 or 4: ";
//    // cin >> IntegerChoice;
//}

//void ShrinkImage(){
//    cout << "Shrink to\n1. (1/2)\n2. (1/3)\n3. (1/4)\n";
//    cout << "Choice: ";
//    // cin >> IntegerChoice;
//}
//
//void MirrorHalfImage(){
//    cout << "Mirror\n1. Left\n2. Right\n3. Upper\n4. Down\n";
//    cout << "Choice: ";
//    // cin >> IntegerChoice;
//}
//
//void ShuffleImage(){
//    int order[4];
//    cout << "Please enter new order of the 4 quarters: ";
//    cin >> order[4];
//}
//
//void BlurImage(){
//
//}