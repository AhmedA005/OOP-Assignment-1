#include <bits/stdc++.h>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];

void blackWhiteFilter();
void saveImage();
void loadImage();
void invertFilter();
void mergeFilter();
void flipImage();
void darkenLightenImage();
void rotateImage();
void detectImageEdges();
void enlargeImage();
void shrinkImage();
void mirrorHalfImage();
void shuffleImage();
void blurImage();
void cropImage();
void skewImageRight();
void skewImageUp();


int main() {
    //The Menu
    string UserName;
    cout << "Please enter your name :" << endl;
    cin >> UserName;
    cout << "Welcome, " << UserName << '!' << endl;
    vector <string> filters = {
            "Black & White Filter",
            "Invert Filter",
            "Merge Filter",
            "Flip Image",
            "Darken and Lighten Image",
            "Rotate Image",
            "Detect Image Edges",
            "Enlarge Image",
            "Shrink Image",
            "Mirror 1/2 Image",
            "Shuffle Image",
            "Blur Image",
            "Crop Image",
            "Skew Image Right",
            "Skew Image Up",
            "s- Save the image to a file",
            "Load New Image",};
    for (int i = 0; i < filters.size(); ++i) {
        cout << i + 1 << " - " << filters[i] << endl;
    }
    loadImage();
    while (true){
        cout << "Please select a filter to apply or 0 to exit: " << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                blackWhiteFilter();
                break;
            case 2:
                invertFilter();
                break;
            case 3:
                mergeFilter();
                break;
            case 4:
                flipImage();
                break;
            case 5:
                darkenLightenImage();
                break;
            case 6:
                rotateImage();
                break;
            case 7:
                detectImageEdges();
                break;
            case 8:
                enlargeImage();
                break;
            case 9:
                shrinkImage();
                break;
            case 10:
                mirrorHalfImage();
                break;
            case 11:
                shuffleImage();
                break;
            case 12:
                blurImage();
                break;
            case 13:
                cropImage();
                break;
            case 14:
                skewImageRight();
                break;
            case 15:
                skewImageUp();
                break;
            case 16:
                saveImage();
                break;
            case 17:
                loadImage();
                break;
            case 0:
                return 0;
        }
    }
}


void blackWhiteFilter() {
    // B&W function
}

void invertFilter() {
    // Invert function
}

void mergeFilter() {
    // Merge Filter function
}

void flipImage() {
    // Flip Image function
}

void darkenLightenImage() {
    // D&L function
}

void rotateImage() {
    // Rotate function
}

void detectImageEdges() {
    // Detect Image Edges function
}

void enlargeImage() {
    // Enlarge Image function
}

void shrinkImage() {
    // Shrink Image function
}

void mirrorHalfImage() {
    // Mirror function
}

void shuffleImage() {
    // Shuffle function
}

void blurImage() {
    // Blur  function
}

void cropImage() {
    // Crop Image function
}

void skewImageRight() {
    // Skew Image Right function
}

void skewImageUp() {
    // Skew Image Up function
}

void saveImageToFile() {
    // Save the image to a file function
}

