#include <iostream>
#include <string>
#include <map>
#include <functional>
#include "bmplib.cpp"
using namespace std;
void blackWhiteFilter();
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
void saveImageToFile();
void exit();
int main() {
    string UserName;
    cout << "Please enter your name : ";
    cin >> UserName;
    cout << "Welcome, " << UserName << '!' << endl;
    while (true) {
        cout << "Please enter file name of the image to process: " << endl;
        string ImageName;
        getline(cin, ImageName);
        map<string, function<void()>> filters = {
                {"Black & White Filter", blackWhiteFilter},
                {"Invert Filter", invertFilter},
                {"Merge Filter", mergeFilter},
                {"Flip Image", flipImage},
                {"Darken and Lighten Image", darkenLightenImage},
                {"Rotate Image", rotateImage},
                {"Detect Image Edges", detectImageEdges},
                {"Enlarge Image", enlargeImage},
                {"Shrink Image", shrinkImage},
                {"Mirror 1/2 Image", mirrorHalfImage},
                {"Shuffle Image", shuffleImage},
                {"Blur Image", blurImage},
                {"Crop Image", cropImage},
                {"Skew Image Right", skewImageRight},
                {"Skew Image Up", skewImageUp},
                {"s- Save the image to a file", saveImageToFile}};
        cout << "please select a filter to apply or 0 to exit: " << endl;
        for (auto it: filters) cout << "- " << it.first << endl;
        string SelectedFilter;
        getline(cin, SelectedFilter);
        if (filters.count(SelectedFilter)) {
            filters[SelectedFilter];
        } else if (SelectedFilter == "0")
            break;
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

