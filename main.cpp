//Include libraries
#include <cstring>
#include <iostream>
#include <algorithm>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;

// Declare images and variables
unsigned char image[SIZE][SIZE], SecondImage[SIZE][SIZE];
char IntegerChoice;

//Declare filters' functions
void loadImage();
void loadSecondImage();
void saveImage();
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

//Main function
int main() {
    char choice = ' ';
    cout << "Hello and welcome to our photoshop program\n";
    
    while (choice != '0') {
        //Menu of filters
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
        cout << "a. Mirror Half Image\n";cout << "b. Shuffle Image\n";
        cout << "c. Blur Image\n";
        cout << "s. Save the image to a file\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
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
    if (choice == '0'){
        cout << "Thank you for using our program\nGoodbye!";
    }
    else{
        while (choice != '0'){
            cout << "Invalid input, Please re-enter the chosen filter: ";
            cin >> choice;
            break;
        }
    }
}

// Function to load image
void loadImage () {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, SecondImage);
    if(readGSBMP(imageFileName, image) == 1){
        loadImage();
    }
}

// Function to load second image
void loadSecondImage () {
    char imageFileName[100];
    cout << "Enter the source of the second image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, SecondImage);
    if(readGSBMP(imageFileName, SecondImage) == 1){
        loadSecondImage();
    }
}

// Function to save image
void saveImage() {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

// Function of black and white filter
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

// Function of invert filter
void InvertFilter(){
    loadImage();
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i][j] = 255 - image[i][j];
        }
    }
    saveImage();

}

// Function of merge filter
void MergeFilter(){
    loadImage();
    loadSecondImage();
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i][j] = (SecondImage[i][j] + image[i][j])/2;
        }
    }
    saveImage();
}

// Function to flip image horizontally or vertically
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

//Function to darken or lighten an image
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

// Function to rotate an image
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

//Function to detect the edges of an image
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
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            SecondImage[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(SecondImage[i][j] == 0){
                if (SecondImage[i][j+1] == 255 || SecondImage[i+1][j] == 255 || SecondImage[i+1][j+1] == 255 || SecondImage[i-1][j-1] == 255
                || SecondImage[i-1][j] == 255 || SecondImage[i][j-1] == 255 || SecondImage[i+1][j - 1] == 255 || SecondImage[i-1][j+1] == 255) {
                    image[i][j] = 0;
                }
                else{
                    image[i][j] = 255;
                }
            }
        }
    }
    saveImage();
}

//Function to enlarge a quarter of an image
void EnlargeImage(){
    int quarterImage[SIZE/2][SIZE/2];
    loadImage();
    cout << "Which quarter to enlarge? 1, 2, 3 or 4: ";
    cin >> IntegerChoice;
    switch (IntegerChoice)
        case '1': {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    quarterImage[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                int m =0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 2 == 0) {
                        for (int k = (j - 1); k <= j; k++) {
                            image[i][k] = quarterImage[i/2][m];
                            image[i+1][k] = quarterImage[i/2][m];
                        }
                        m+=1;
                    }

                }

            }
            break;
            case '2':
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                        quarterImage[i][k] = image[i][j];
                    }
                }
            for (int i = 0; i < SIZE; i++) {
                int m =0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 4 == 0) {
                        for (int k = (j - 3); k <= j; k++) {
                            image[i][k] = quarterImage[i/2][m];
                            image[i+1][k] = quarterImage[i/2][m];
                        }
                        m += 1;
                    }

                }
            }
            break;
            case '3':
                for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        quarterImage[k][j] = image[i][j];
                    }
                }
            for (int i = 0; i < SIZE; i++) {
                int m =0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 4 == 0) {
                        for (int k = (j - 3); k <= j; k++) {
                            image[i][k] = quarterImage[i/2][m];
                            image[i+1][k] = quarterImage[i/2][m];
                        }
                        m += 1;
                    }
                }
            }
            break;
            case '4':
                for (int i = SIZE / 2, c = 0; i < SIZE; i++, c++) {
                    for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                        quarterImage[c][k] = image[i][j];
                    }
                }
            for (int i = 0; i < SIZE; i++) {
                int m =0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 4 == 0) {
                        for (int k = (j - 3); k <= j; k++) {
                            image[i][k] = quarterImage[i/2][m];
                            image[i+1][k] = quarterImage[i/2][m];
                        }
                        m += 1;
                    }
                }
            }
            break;
        }
    saveImage();
}

//Function to shrink an image to half or third or quarter of it
void ShrinkImage() {
    loadImage();
    cout << "Shrink to\n1. (1/2)\n2. (1/3)\n3. (1/4)\n";
    cout << "Choice: ";
    cin >> IntegerChoice;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            SecondImage[i][j] = image[i][j];
        }
    }
    switch(IntegerChoice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j]= 255;
                    image[i/2][j/2] = SecondImage[i][j];
                        }
                    }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j]= 255;
                    image[i/3][j/3] = SecondImage[i][j];
                        }
                    }
            break;
        case '3':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j]= 255;
                    image[i/4][j/4] = SecondImage[i][j];
                        }
                    }
            break;
    }
    saveImage();
}

// Function to mirror half an image
void MirrorHalfImage(){
    loadImage();
    char choice;
    cout << "Mirror\n1. Left half\n2. Right half\n3. Upper half \n4. Down half\n";
    cout << "Choice: ";
    cin >> choice;
    switch(choice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = image[i][SIZE-1-j];
                    image[i][SIZE-1-j] = image[i][j];
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][SIZE-1-j] = image[i][j];
                    image[i][j] = image[i][SIZE-1-j];
                }
            }
            break;
        case '3':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[i][j] = image[SIZE-1-i][j];
                    image[SIZE-1-i][j] = image[i][j];
                }
            }
            break;
        case '4':
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    image[SIZE-1-i][j] = image[i][j];
                    image[i][j] = image[SIZE-1-i][j];
                }
            }
            break;
        default:
            break;
    }
    saveImage();
}

// Function to shuffle an image to a new order

void ShuffleImage(){
    loadImage();
    int quarterImage1[SIZE/2][SIZE/2],quarterImage2[SIZE/2][SIZE/2],quarterImage3[SIZE/2][SIZE/2],quarterImage4[SIZE/2][SIZE/2];
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            quarterImage1[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
            quarterImage2[i][k] = image[i][j];
        }
    }
    for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
        for (int j = 0; j < SIZE / 2; j++) {
            quarterImage3[k][j] = image[i][j];
        }
    }
    for (int i = SIZE / 2, c = 0; i < SIZE; i++, c++) {
        for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
            quarterImage4[c][k] = image[i][j];
        }
    }
    cout<< "Please choose one of the following orders: " << endl << "1. (2431)      2. (4312)" << endl;
    cin>> IntegerChoice;
    switch(IntegerChoice) {
        case '1':
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    image[i][j] = quarterImage2[i][j];
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                    image[i][j] = quarterImage4[i][k];
                }
            }
            for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    image[i][j] = quarterImage3[k][j];
                }
            }
            for (int i = SIZE / 2, c = 0; i < SIZE; i++, c++) {
                for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                    image[i][j] =  quarterImage1[c][k];
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    image[i][j] = quarterImage4[i][j];
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                    image[i][j] = quarterImage3[i][k];
                }
            }
            for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    image[i][j] = quarterImage1[k][j];
                }
            }
            for (int i = SIZE / 2, c = 0; i < SIZE; i++, c++) {
                for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                    image[i][j] =  quarterImage2[c][k];
                }
            }
            break;
    }
    saveImage();
}

//Function to blur an image
void BlurImage(){
    loadImage();
    for (int i = 0 ; i < SIZE ; i++){
        for (int j =0 ; j< SIZE ; j++){
            long double average ;
            average = (image[i][j] + image[i-1][j-1] + image[i-1][j] + image [i-1][j+1] + image [i][j-1]+
                    image[i][j+1]+ image [i+1][j-1] + image[i+1][j]+ image[i+1][j+1])/9;
            image [i][j] = average;
        }
    }
    saveImage();
}