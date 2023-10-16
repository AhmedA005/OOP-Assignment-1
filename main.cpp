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
    unsigned char quarter[4][SIZE/2][SIZE/2]; // Array to store each quarter of the image
    unsigned char shuffledImage[SIZE][SIZE]; // Array to store the shuffled image
    vector<int> order(4); // Vector to store the order of quarters for shuffling

    // Dividing the image into four quarters and storing them separately
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int quadrant;
            if (i < SIZE/2 && j < SIZE/2)
                quadrant = 0;
            else if (i < SIZE/2 && j >= SIZE/2)
                quadrant = 1;
            else if (i >= SIZE/2 && j < SIZE/2)
                quadrant = 2;
            else
                quadrant = 3;

            quarter[quadrant][i % (SIZE/2)][j % (SIZE/2)] = image[i][j];
        }
    }

    cout << "Enter the order you like to shuffle the picture in:" << endl;
    for (int i = 0; i < 4; ++i) {
        cin >> order[i];
        --order[i]; // Decrementing the value by 1 to be 0-indexded
    }

    // Shuffling the image according to the user's input
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int quadrant;
            if (i < SIZE/2 && j < SIZE/2)
                quadrant = order[0];
            else if (i < SIZE/2 && j >= SIZE/2)
                quadrant = order[1];
            else if (i >= SIZE/2 && j < SIZE/2)
                quadrant = order[2];
            else
                quadrant = order[3];

            shuffledImage[i][j] = quarter[quadrant][i % (SIZE/2)][j % (SIZE/2)];
        }
    }

    // Copying the shuffled image back to the original image array
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            image[i][j] = shuffledImage[i][j];
    }
}


void blurImage() {
    int blurredImage[SIZE][SIZE];

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                int blur = image[i][j];
                int counter = 1; // Counting the nuumber of neigbours to calculate the average

                for (int k = 0; k < 8; ++k) {
                    int newX = i + dx8[k], newY = j + dy8[k]; // Calculating coordinates for neighboring pixels

                    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) { // Making sure the new coordinates is within bounds
                        blur += image[newX][newY];
                        counter++;
                    }
                }

                blur /= counter;
                blurredImage[i][j] = blur; // Assigning the average value to the current pixel and its neighbours
            }
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] =blurredImage[i][j];
            }
        }
}

void cropImage() {
        int pointX,pointY,length,width;
        cout<<"Enter the point x, y, the length and the width:"<< endl;
        cin>>pointX>>pointY>>length>>width;
        //Cropping a rectangle of length and width l,w by converting the pixels outside the rectangle into white pixels
        for(int i=0;i<pointX;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j] = 255;
            }
        }
        for(int i=pointX+length;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j] = 255;
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<pointY;j++){
                image[i][j] = 255;
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=pointY+width;j<SIZE;j++){
                image[i][j] = 255;
            }
        }
}

void skewImageRight() {
    cout << "Please enter degree to skew right" << endl;
    double degree; cin >> degree;
    // Convert the degree to radian and calculate the skew
    degree=90-degree;
    double rad = (degree * 22) / (7 * 180);
    int x=(int)(SIZE / (1 + 1 / tan(rad)));
    double skew = SIZE-x;

    // Initialize the skewed image and a temporary image (Shrunk)
    double step=skew/256;
    int skewedImage[SIZE][SIZE+(int)skew];
    int Shrunk[SIZE][SIZE];

    // Shrink the original image horizontally and store it in Shrunk
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Shrunk[i][(j*x)/256]=image[i][j];
        }
    }

    // Skew the shrunken image to the right and store it in skewedImage
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            skewedImage[i][j+(int)skew]= Shrunk[i][j];
        }
        skew-=step;
    }

    // Copy the skewed image back to the original image
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=skewedImage[i][j];
        }
    }
}

void skewImageUp() {
    // Similar to skewImageRight, but this time we're skewing vertically
    // So we swap the roles of i and j when accessing the image array

        cout << "Please enter degree to skew right" << endl;
        double degree;
        cin >> degree;
        degree = 90 - degree;
        double rad = (degree * 22) / (7 * 180);
        int x = (int) (SIZE / (1 + 1 / tan(rad)));
        double skew = SIZE - x;

        double step = skew / 256;
        int skewedImage[SIZE][SIZE + (int) skew];
        int Shrunk[SIZE][SIZE];


        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                Shrunk[i][(j * x) / 256] = image[j][i];
            }
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                skewedImage[i][j + (int) skew] = Shrunk[i][j];
            }
            skew -= step;
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[j][i] = skewedImage[i][j];
            }
        }
}



