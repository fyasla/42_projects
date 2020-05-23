/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:41:42 by faysal            #+#    #+#             */
/*   Updated: 2020/05/23 15:40:42 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

const int bytesPerPixel = 3; /// red, green, blue
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;

void generateBitmapImage(unsigned char *image, int height, int width, char* imageFileName);
unsigned char* createBitmapFileHeader(int height, int width, int paddingSize);
unsigned char* createBitmapInfoHeader(int height, int width);


int gen(t_scene *scene){
    int height = scene->resy;
    int width = scene->resx;
    unsigned char image[height][width][bytesPerPixel];
    char* imageFileName = "bitmapImage.bmp";

    t_pix	p;

    p.x = 0;
    while(p.x < width){
        p.y = 0;
        while(p.y < height){
            image[height - 1 - p.y][p.x][2] = (unsigned char)pix_col(p, scene, scene->cam).r; ///red
            image[height - 1 - p.y][p.x][1] = (unsigned char)pix_col(p, scene, scene->cam).g; ///green
            image[height - 1 - p.y][p.x][0] = (unsigned char)pix_col(p, scene, scene->cam).b; ///blue
            p.y++;
        }
        p.x++;
    }


    generateBitmapImage((unsigned char *)image, height, width, imageFileName);
    return(0);
}


void generateBitmapImage(unsigned char *image, int height, int width, char* imageFileName){

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (width*bytesPerPixel) % 4) % 4;

    unsigned char* fileHeader = createBitmapFileHeader(height, width, paddingSize);
    unsigned char* infoHeader = createBitmapInfoHeader(height, width);

    // FILE* imageFile = fopen(imageFileName, "wb");
    int imageFile;
    imageFile = open(imageFileName, O_WRONLY);    

    /* fwrite(fileHeader, 1, fileHeaderSize, imageFile);
    fwrite(infoHeader, 1, infoHeaderSize, imageFile); */

    write(imageFile, fileHeader, fileHeaderSize);
    write(imageFile, infoHeader, infoHeaderSize);
    int i;
    i = 0;
    while(i < height){
       /*  fwrite(image+(i*width*bytesPerPixel), bytesPerPixel, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile); */
        write(imageFile, image+(i*width*bytesPerPixel), bytesPerPixel * width);
        write(imageFile, padding, paddingSize);
        i++;
    }

    close(imageFile);
}

unsigned char* createBitmapFileHeader(int height, int width, int paddingSize){
    int fileSize = fileHeaderSize + infoHeaderSize + (bytesPerPixel*width+paddingSize) * height;

    static unsigned char fileHeader[] = {
        0,0, /// signature
        0,0,0,0, /// image file size in bytes
        0,0,0,0, /// reserved
        0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize    );
    fileHeader[ 3] = (unsigned char)(fileSize>> 8);
    fileHeader[ 4] = (unsigned char)(fileSize>>16);
    fileHeader[ 5] = (unsigned char)(fileSize>>24);
    fileHeader[10] = (unsigned char)(fileHeaderSize + infoHeaderSize);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader(int height, int width){
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size
        0,0,0,0, /// image width
        0,0,0,0, /// image height
        0,0, /// number of color planes
        0,0, /// bits per pixel
        0,0,0,0, /// compression
        0,0,0,0, /// image size
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(infoHeaderSize);
    infoHeader[ 4] = (unsigned char)(width    );
    infoHeader[ 5] = (unsigned char)(width>> 8);
    infoHeader[ 6] = (unsigned char)(width>>16);
    infoHeader[ 7] = (unsigned char)(width>>24);
    infoHeader[ 8] = (unsigned char)(height    );
    infoHeader[ 9] = (unsigned char)(height>> 8);
    infoHeader[10] = (unsigned char)(height>>16);
    infoHeader[11] = (unsigned char)(height>>24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(bytesPerPixel*8);

    return infoHeader;
}