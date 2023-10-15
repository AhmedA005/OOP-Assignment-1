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
    degree=90-degree;
    double rad = (degree * 22) / (7 * 180);
    int x=(int)(SIZE / (1 + 1 / tan(rad)));
    double skew = SIZE-x;

    double step=skew/256;
    int skewedImage[SIZE][SIZE+(int)skew];
    int Shrunked[SIZE][SIZE];


    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            skewedImage[i][j]=255;
            Shrunked[i][j]=255;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Shrunked[i][(j*x)/256]=image[i][j];
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            skewedImage[i][j+(int)skew]=Shrunked[i][j];
        }
        skew-=step;
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=skewedImage[i][j];
        }
    }
}






void skewImageUp() {
    // Skew Image Up function


}