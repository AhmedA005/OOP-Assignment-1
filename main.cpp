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
    int rotate;
    int rotatedImage[SIZE][SIZE];
    //This filters rotates images by changing the pixel's coordinates
    cout << "rotate (90), (180), (270) degrees?" << endl;
    cin >> rotate;
    // Transposes and reverses rows
    if (rotate == 90) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                rotatedImage[j][i] = image[255-i][j];
            }
        }
    }
        //Rotates by flipping the rows and the columns
    else if (rotate == 180) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                rotatedImage[i][j] = image[255 - i][255 - j];
            }
        }
    }
        //Rotates by switching the coordinates of the pixel
    else if (rotate == 270) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                rotatedImage[j][i] = image[i][j];
            }
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = rotatedImage[i][j];
        }
    }
}

int dx8[]={1,0,-1,0,-1,1,-1,1}; // Array to represent x-coordinates of 8 neighboring pixels
int dy8[]={0,-1,0,1,1,1,-1,-1}; // Array to represent y-coordinates of 8 neighboring pixels
bool isVisited[SIZE][SIZE]; // Boolean array to keep track of visited pixels
int detect[SIZE][SIZE];

void BFS() {
    deque<pair<int, int>> q;
    q.push_front({0, 0}); // Pushing the starting point (top-left corner) into the queue

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop_front();

        for (int i = 0; i < 8; ++i) {
            int newX = x + dx8[i], newY = y + dy8[i]; // Calculating coordinates for neighboring pixels

            // Checking if the new coordinates are within bounds and if the pixel has not been visited yet
            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && !isVisited[newX][newY]){

                if (abs(image[newX][newY] - image[x][y]) <= 30) { // If the difference in grayscale values between the current pixel and its neighbour <=30 then it is an edge
                    isVisited[newX][newY] = 1; // Marking the pixel as visited
                    detect[newX][newY] = 255; // Marking the pixel as an edge in the detection result
                    q.push_front({newX, newY}); // Adding the pixel to the front of the queue for further processing
                }

                else if (abs(image[newX][newY] - image[x][y]) > 30) { // The difference is > 30 then it is not an edge
                    isVisited[newX][newY] = 1;
                    detect[newX][newY] = 0; // Marking the pixel as non-edge in the detection result
                    if (detect[newX][newY] > 255) {
                        detect[newX][newY] = 255; // Ensuring that the detection result does not exceed the maximum grayscale value
                    }
                    q.push_back({newX, newY}); // Adding the pixel to the back of the queue for further processing
                }
            }
        }
    }
}


void detectImageEdges() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            isVisited[i][j]=0; // Marking all the pixels as not visited
        }
    }

    BFS();

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = detect[i][j];
        }
    }
}

void enlargeImage() {
    int quarter;
    unsigned char enlarge[SIZE][SIZE];
    //enlarge a quarter by copying the pixel into a square consists of 4 pixels in the new image
    cout << " which Quarter to enlarge 1,2,3 or 4?" << endl;
    cin>>quarter;

    if (quarter == 1) {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                enlarge[2*i][2*j] = enlarge[2*i][(2*j)+1] = enlarge[(2*i)+1][2*j] = enlarge[(2*i)+1][(2*j)+1] =image[i][j] ;
            }
        }
    }

    else if(quarter == 2) {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                enlarge[2*i][2*j] = enlarge[2*i][2*j+1] = enlarge[(2*i)+1][2*j] = enlarge[(2*i)+1][2*j+1] =image[i][j+128] ;
            }
        }
    }

    else if(quarter == 3) {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                enlarge[2*i][2*j] = enlarge[2*i][2*j+1] = enlarge[(2*i)+1][2*j] = enlarge[(2*i)+1][2*j+1] =image[i+128][j] ;
            }
        }
    }

    else if(quarter == 4) {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                enlarge[2*i][2*j] = enlarge[2*i][2*j+1] = enlarge[(2*i)+1][2*j] = enlarge[(2*i)+1][2*j+1] =image[i+128][j+128] ;
            }
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]  =enlarge[i][j] ;

        }
    }
}

void shrinkImage() {
    int newImage[256][256];
    int shrink;
    int newSize;
    //This filter shrinks the image by discarding pixels (like lossy compression)
    cout<<"Shrink to 1. (1/2), 2. (1/3), 3. (1/4)?" << endl;
    cin>>shrink;

    if (shrink==1) {
        newSize = 128;
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                newImage[i][j] = image[i * 2][j * 2];
            }
        }
    }

    else if(shrink==2) {
        newSize = 256/3;
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                newImage[i][j] = image[i * 3][j * 3];
            }
        }
    }

    else if(shrink==3) {
        newSize = 64;
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                newImage[i][j] = image[i * 4][j * 4];
            }
        }
    }
    //Filling the rest of the image with white pixels
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i >= newSize || j >= newSize) {
                newImage[i][j] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = newImage[i][j];
        }
    }
}

void mirrorHalfImage() {
    char mirror;

    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?" << endl;
    cin >> mirror;

    // Mirroring right half of the image
    if (mirror == 'r') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image[i][j] = image[i][255 - j];
            }
        }
    }

    // Mirroring left half of the image
    else if (mirror == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                image[i][j] = image[i][255 - j];
            }
        }
    }

    // Mirroring lower half of the image
    else if (mirror == 'd') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[255 - i][j];
            }
        }
    }

    // Mirroring upper half of the image
    else if (mirror == 'u') {
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[255 - i][j];
            }
        }
    }
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



