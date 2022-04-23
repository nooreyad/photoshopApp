#include<iostream>
#include<cstring>
#include "bmplib.h"
#include "bmplib.cpp"
#include<algorithm>

using namespace std;

unsigned char image[SIZE][SIZE][RGB], SecondImage[SIZE][SIZE][RGB];
char IntegerChoice;

//Declare filters' functions
void BlackAndWhiteFilter();
void InvertFilter();
void MergeFilter();
void FlipImage();
void DarkenAndLightenImage();
void RotateImage();
void EnlargeImage();
//void ShrinkImage();
void MirrorHalfImage();
void ShuffleImage();
void BlurImage();



void loadImage() {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
    if (readRGBBMP(imageFileName, image) == 1) {
        loadImage();
    }
}

void loadSecondImage() {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, SecondImage);
    if (readRGBBMP(imageFileName, image) == 1) {
        loadImage();
    }
}

void saveImage() {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}


int main() {
    char choice = ' ';
    cout << "Hello and welcome to our photoshop program\n";

    while (choice != '0') {
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
        cout << "a. Mirror Half Image\n"; cout << "b. Shuffle Image\n";
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
        /*
        while (choice == '7') {
            DetectImageEdges();
            break;
        }
         */
        while (choice == '8') {
            EnlargeImage();
            break;
        }
        /*
        while (choice == '9') {
            ShrinkImage();
            break;
        }
         */
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
    if (choice == '0') {
        cout << "Thank you for using our program\nGoodbye!";
    }
    else {
        while (choice != '0') {
            cout << "Invalid input, Please re-enter the chosen filter: ";
            cin >> choice;
            break;
        }
    }
}

void BlackAndWhiteFilter() {
    loadImage();
    long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
            avg += image[i][j][k];
        }
    }
}
avg /= (RGB * SIZE * SIZE);
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        for (int k = 0; k < RGB; k++) {
            if (image[i][j][0] + image[i][j][1] + image[i][j][2] > avg) {
                image[i][j][k] = 255;
            }
             else {
                image[i][j][k] = 0;
            }
        }
    }
}
saveImage();
}

void InvertFilter() {
    loadImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
    saveImage();

}

void MergeFilter() {
    loadImage();
    loadSecondImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = i % 2; j < SIZE; j += 2) {
            for (int k = 0; k < RGB; k++) {
                image[i][j][k] = SecondImage[i][j][k];
            }
        }
    }
    saveImage();
}

void FlipImage() {
    loadImage();
    char choice;
    cout << "Please choose either\n1. for horizontal flipping\n2. for vertical flipping\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        SecondImage[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = SecondImage[255 - i][j][k];
                    }
                }
            }
            break;

        case '2':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        SecondImage[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = SecondImage[i][255 - j][k];
                    }
                }
            }
            break;
    }
    saveImage();
}

void DarkenAndLightenImage() {
    loadImage();
    char choice;
    cout << "Please choose either\n1. for darkening\n2. for lightening\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        if (image[i][j][k] - 64 > 0) {
                            image[i][j][k] -= 64;
                        }
                        else {
                            image[i][j][k] = 0;
                        }
                    }
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        if (image[i][j][k] + 64 < 255) {
                            image[i][j][k] += 64;
                        }
                        else {
                            image[i][j][k] = 255;
                        }
                    }
                }
            }
            break;
    }
    saveImage();
}

void RotateImage() {
    loadImage();
    char choice;
    cout << "Please choose either\n1. Rotate 90\n2. Rotate 180\n3. Rotate 270\n";
    cout << "Choice: ";
    cin >> choice;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                SecondImage[i][j][k] = image[i][j][k];
            }
        }
    }
    switch (choice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = SecondImage[255 - j][i][k];
                    }
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = SecondImage[255 - i][255 - j][k];
                    }
                }
            }
            break;
        case '3':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = SecondImage[j][255 - i][k];
                    }
                }
            }
            break;
    }
    saveImage();
}

void DetectImageEdges() {
    loadImage();
    long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                avg += image[i][j][k];
            }
        }
    }
    avg /= (RGB * SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                if (image[i][j][0] + image[i][j][1] + image[i][j][2] > avg) {
                    image[i][j][k] = 255;
                } else {
                    image[i][j][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                SecondImage[i][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                if (SecondImage[i][j][k] == 0) {
                    if (SecondImage[i][j + 1][k] == 255 || SecondImage[i + 1][j][k] == 255 || SecondImage[i + 1][j + 1][k] == 255 || SecondImage[i - 1][j - 1][k] == 255
                        || SecondImage[i - 1][j][k] == 255 || SecondImage[i][j - 1][k] == 255 || SecondImage[i + 1][j - 1][k] == 255 || SecondImage[i - 1][j + 1][k] == 255) {
                        image[i][j][k] = 0;
                    }
                    else {
                        image[i][j][k] = 255;
                    }
                }
            }
        }
    }
    saveImage();
}

void EnlargeImage() {
    int quarterImage[SIZE / 2][SIZE / 2][RGB];
    loadImage();
    cout << "Which quarter to enlarge? 1, 2, 3 or 4: ";
    cin >> IntegerChoice;
    switch (IntegerChoice)
        case '1': {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < RGB; k++) {
                        quarterImage[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE; i++) {
                int m = 0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 2 == 0) {
                        for (int k = (j - 1); k <= j; k++) {
                            for (int n = 0; n < RGB; n++) {
                                image[i][k][n] = quarterImage[i / 2][m][n];
                                image[i + 1][k][n] = quarterImage[i / 2][m][n];
                            }
                        }
                        m += 1;
                    }
                }
            }
            break;
            case '2':
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                        for (int n = 0; n < RGB; n++) {
                            quarterImage[i][k][n] = image[i][j][n];
                        }
                    }
                }
            for (int i = 0; i < SIZE; i++) {
                int m = 0;
                for (int j = 0; j < SIZE; j++) {

                    if ((j + 1) % 4 == 0) {
                        for (int k = (j - 3); k <= j; k++) {
                            for (int n = 0; n < RGB; n++) {
                                image[i][k][n] = quarterImage[i / 2][m][n];
                                image[i + 1][k][n] = quarterImage[i / 2][m][n];
                            }
                        }
                        m += 1;
                    }

                }
            }
            break;
            case '3':
                for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        for (int n = 0; n < RGB; n++) {
                            quarterImage[k][j][n] = image[i][j][n];
                        }
                    }
                }
            for (int i = 0; i < SIZE; i++) {
                int m = 0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 4 == 0) {
                        for (int k = (j - 3); k <= j; k++) {
                            for (int n = 0; n < RGB; n++) {
                                image[i][k][n] = quarterImage[i / 2][m][n];
                                image[i + 1][k][n] = quarterImage[i / 2][m][n];
                            }
                        }
                        m += 1;
                    }
                }
            }
            break;
            case '4':
                for (int i = SIZE / 2, c = 0; i < SIZE; i++, c++) {
                    for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                        for (int n = 0; n < RGB; n++) {
                            quarterImage[c][k][n] = image[i][j][n];
                        }
                    }
                }
            for (int i = 0; i < SIZE; i++) {
                int m = 0;
                for (int j = 0; j < SIZE; j++) {
                    if ((j + 1) % 4 == 0) {
                        for (int k = (j - 3); k <= j; k++) {
                            for (int n = 0; n < RGB; n++) {
                                image[i][k][n] = quarterImage[i / 2][m][n];
                                image[i + 1][k][n] = quarterImage[i / 2][m][n];
                            }
                        }
                        m += 1;
                    }
                }
            }
            break;
        }
    saveImage();
}
/*
void ShrinkImage() {
    loadImage();
    cout << "Shrink to\n1. (1/2)\n2. (1/3)\n3. (1/4)\n";
    cout << "Choice: ";
    cin >> IntegerChoice;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; K++) {
                SecondImage[i][j][K] = image[i][j][K];
            }
        }
    }
    switch (IntegerChoice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; K++) {
                        image[i][j][K] = 255;
                        image[i / 2][j / 2][K] = SecondImage[i][j][K];
                    }
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; K++) {
                        image[i][j][K] = 255;
                        image[i / 3][j / 3][K] = SecondImage[i][j][K];

                    }
                }
            }
            break;
        case '3':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; K++) {
                        image[i][j][K] = 255;
                        image[i / 4][j / 4][K] = SecondImage[i][j][K];
                    }
                }
            }
            break;
    }
    saveImage();
}
 */
void MirrorHalfImage() {
    loadImage();
    char choice;
    cout << "Mirror\n1. Left half\n2. Right half\n3. Upper half \n4. Down half\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
        case '1':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int n = 0; n < RGB; n++) {
                        image[i][j][n] = image[i][SIZE - 1 - j][n];
                        image[i][SIZE - 1 - j][n] = image[i][j][n];
                    }
                }
            }
            break;
        case '2':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int n = 0; n < RGB; n++) {
                        image[i][SIZE - 1 - j][n] = image[i][j][n];
                        image[i][j][n] = image[i][SIZE - 1 - j][n];
                    }
                }
            }
            break;
        case '3':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int n = 0; n < RGB; n++) {
                        image[i][j][n] = image[SIZE - 1 - i][j][n];
                        image[SIZE - 1 - i][j][n] = image[i][j][n];
                    }
                }
            }
            break;
        case '4':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int n = 0; n < RGB; n++) {
                        image[SIZE - 1 - i][j][n] = image[i][j][n];
                        image[i][j][n] = image[SIZE - 1 - i][j][n];
                    }
                }
            }
            break;
    }
    saveImage();
}

//Function to shuffle an image
void ShuffleImage(){
    loadImage();
    int order[4], checkOrder[4];
    cout << "Please enter new order of the 4 quarters: ";
    cin >> order[4];
    order[4] = checkOrder[4];
    int arraySize = sizeof(checkOrder) / sizeof(checkOrder[0]);
    sort(checkOrder, checkOrder + arraySize);
    while (checkOrder[4] != {0,1,2,3}){
        cout << "The order must contain numbers from 0 to 3 only, Please re-enter the order: ";
        cin >> checkOrder[4];
        int arraySize = sizeof(checkOrder) / sizeof(checkOrder[0]);
        sort(checkOrder, checkOrder + arraySize);
    }
    unsigned char quarters[4][SIZE/2][SIZE/2];
    for (int i = 0; i <= 127; i++){
        for (int j = 0; j <= 127; j++){
            quarters[0][i][j] = image[i][j];
        }
    }
    for (int i = 0; i <= 127; i++){
        for (int j = 128, k = 0; j <= 255; j++, k++){
            quarters[1][i][k] = image[i][j];
        }
    }
    for (int i = 128, k = 0; i <= 255; i++, k++){
        for (int j = 0; j <= 127; j++){
            quarters[2][k][j] = image[i][j];
        }
    }
    for (int i = SIZE/2, c = 0; i < SIZE; i++, c++){
        for (int j = SIZE/2, k = 0; j < SIZE; j++, k++){
            quarters[3][c][k] = image[i][j];
        }
    }
    for (int b = 0; b < 4; b++){
        for (int i = 0; i <= 127; i++){
            for (int j = 0; j <= 127; j++){
                image[i][j] = quarters[b][i][j];
            }
        }
        for (int i = 0; i <= 127; i++){
            for (int j = 128, k = 0; j <= 255; j++, k++){
                image[i][j] = quarters[b][i][k];
            }
        }
        for (int i = 128, k = 0; i <= 255; i++, k++){
            for (int j = 0; j <= 127; j++){
                image[i][j] = quarters[b][k][j];
            }
        }
        for (int i = 128, c = 0; i <= 255; i++, c++){
            for (int j = 128, k = 0; j <= 255; j++, k++){
                image[i][j] = quarters[b][c][k];
            }
        }
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

void BlurImage() {
    loadImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                for (int k = 0; k < RGB; k++) {
                    long double average;
                    average = (image[i][j][k] + image[i - 1][j - 1][k] + image[i - 1][j][k] + image[i - 1][j + 1][k] + image[i][j - 1][k] + image[i][j + 1][k] + image[i + 1][j - 1][k] + image[i + 1][j][k] + image[i + 1][j + 1][k]) / 9;
                    image[i][j][k] = average;
                }
            }
        }
    }
    saveImage();
}

