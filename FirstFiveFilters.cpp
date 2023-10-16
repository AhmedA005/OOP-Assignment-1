void loadImage() {
    char imageFileName[100];

    cout << "Enter the source image file name:" << endl;
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage() {
    char imageFileName[100];

    cout << "Enter the target image file name:" << endl;
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void blackWhiteFilter() {
    //This filter converts every pixel < 128 to Black and the rest are White
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image[i][j] / 128 * 255;
        }
    }
}

void invertFilter() {
    //This filter converts every pixel to its 256's complement
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = 255 - image[i][j] ;
        }
    }
}

void mergeFilter() {
    //This filter merges every two pixels by calculating the average of every two corresponding pixels in the images
    unsigned char secondImage[SIZE][SIZE];
    char imageFileName[100];

    cout << "Enter the image file name to merge with:" << endl;
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, secondImage);

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = (image[i][j] + secondImage[i][j])/2;
        }
    }
}

void flipImage() {
    unsigned char flippedImage[SIZE][SIZE];
    char flip;

    cout << " Type (h) for a horizontal flip or (v) for a vertical flip:" << endl;
    cin >> flip;
    //Copying the image into a new one
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            flippedImage[i][j] = image[i][j];
        }
    }
    //Flips the image horizontally by flipping the rows
    if(flip == 'h') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = flippedImage[255-i][j];
            }
        }
    }
        //Flips the image vertically by flipping the columns
    else {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = flippedImage[i][255-j];
            }
        }
    }
}

void darkenLightenImage() {
    char light;

    cout << " Type (d) to darken or (l) to lighten:" << endl;
    cin >> light;
    //darkens the image by dividing the  brightness of the pixel by 2
    if(light == 'd') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] /= 2;
            }
        }
    }
        //lightens the image by calculating the average of the pixel and a white pixel
    else if(light == 'l') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = (255+image[i][j])/2;
            }
        }
    }
}