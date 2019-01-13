#include <stdio.h>
// for I/O
#include <stdlib.h>
// for malloc(), calloc()

#include "../headers/bmp_header.h"

typedef struct bmp_fileheader bmp_fileheader;
typedef struct bmp_infoheader bmp_infoheader;

bmp_fileheader f_head() // returns the fileheader we use :)
{
    bmp_fileheader fh;
    fh.fileMarker1 = 'B';
    fh.fileMarker2 = 'M';
    fh.bfSize = 40; // file's Size
    fh.unused1 = fh.unused2 = 0;
    fh.imageDataOffset = sizeof(bmp_fileheader) + sizeof(bmp_infoheader); // offset to the image data, i.e. the pixels ----> 14 + 40 = 54
    //
    return fh;
}

bmp_infoheader i_head() // returns the infoheader we use :)
{
    bmp_infoheader ih;
    ih.biSize = 40; // size of hte info header
    // for the next two, we consider that this is a "blank bmp", and we change them when we create the image :)
    ih.width = 0; // width of the image
    ih.height = 0; // height of the image
    ih.planes = 1;
    ih.bitPix = 24; // RGP, here BGR, uses 3 * 8 bits
    ih.biCompression = 0;
    ih.biSizeImage = 0 * 0 + 0 * 0; // the dimension of the pixel matrix, plus the padding of o columns
    ih.biXPelsPerMeter = 0; // used when we print a bmp, pixels per meter
    ih.biYPelsPerMeter = 0; // used when we print a bmp, pixels per meter
    ih.biClrUsed = 0; // number of used colours, only used when bitPix <= 8
    ih.biClrImportant = 0; // number of the important colours ----> it means all of them are important
    //
    return ih;
}

// Task I
// Create the 7 pieces (.bmp images), each one rotated by 0 degrees. The constituting squares
//   are also 10x10 pixels; add a white (255,255,255)  border of 10x10 pixels.
// The .bmp's will be named: piesa_{piece_name}.bmp
void task_1()
{
    // we use auxiliary matrices, one for every piece, and we "expand" them into the image ;)
}

// Task II
// Create three more images for each piece (so 21 all in all),
//   each one will represent the piece being rotated by 90, 180, 270 degrees
// We use the same rules for the creation: border, square size etc.
// The .bmp's will be named: piesa_{nume_piesa}_{rotatie}.bmp
void task_2()
{

}

int main(int argc, char *argv[]) {
    bmp_fileheader fh;
    bmp_infoheader ih;
    fh = f_head();
    ih = i_head();
    //
    task_1();
    task_2();
    //
    return 0;
}


















// un File Header care are urmatoarele campuri:
// signature – 2 octeti - literele 'B' si 'M' in ASCII;
// file size – 4 octeti – dimensiunea intregului fisier;
// reserved – 4 octeti – nefolosit;
// offset – 4 octeti – offsetul de la inceputul fisierului pana la inceputului bitmap-ului, adica al matricii de pixeli.
// un Info Header care poate avea structuri diferite, insa noi vom lucra cu cel care se numeste BITMAPINFOHEADER. Are urmatoarele campuri:
// size – 4 octeti – dimensiunea Info Header-ului, care are o valoare fixa, 40;
// width – 4 octeti – latimea matricii de pixeli (numarul de coloane);
// height – 4 octeti – inaltimea matricii de pixeli (numarul de randuri);
// planes – 2 octeti – setat la valoarea fixa 1;
// bit count – 2 octeti – numarul de biti per pixel. In cazul nostru va avea mereu valoarea 24, adica reprezentam fiecare pixel pe 3 octeti, adica cele 3 canale, RGB;
// compression – 4 octeti – tipul de compresie. Acest camp va fi 0;
// image size – 4 octeti – se refera la dimensiunea matricii de pixeli, inclusiv padding-ul adaugat (vedeti mai jos);
// x pixels per meter – 4 octeti – se refera la rezolutia de printare. Pentru a simplifica putin tema, veti seta acest camp pe 0. Nu o sa printam imaginile :).
// y pixels per meter – la fel ca mai sus;
// colors used – numarul de culori din paleta de culori. Aceasta este o sectiune care va lipsi din imaginile noastre BMP, deoarece ea se afla in general imediat dupa Info Header insa doar pentru imaginile care au campul bit count mai mic sau egal cu 8. Prin urmare, campul va fi setat pe 0;
// colors important – numarul de culori importante. Va fi, de asemenea, setat pe 0, ceea ce inseamna ca toate culorile sunt importante.
