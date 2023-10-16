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
