// Project UID af1f95f547e44c8ea88730dfb185559d
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <string>
#include "Matrix.h"
#include "Image.h"
#include "processing.h"

using namespace std;
int main(int argc, char *argv[]) {
    string filename1= argv[1];
    ifstream fin;
    fin.open(filename1);
    if(!fin.is_open()){
        cout << "Error opening file: " << filename1 << endl;
        return 1;
    }
    ofstream fout;
    string filename2= argv[2];
    fout.open(argv[2]);
    if(!fout.is_open()){
        cout << "Error opening file: " << filename2 << endl;
        return 1;
    }
    if(argc==4){
        int width=atoi(argv[3]);
        Image *aux = new Image;
        Image_init(aux,fin);
        int height=Image_height(aux);
        seam_carve(aux,width,height);
        Image_print(aux, fout);
        delete aux;
    }
    else if(argc==5){
        int width=atoi(argv[3]);
        int height=atoi(argv[4]);
        Image *img = new Image;
        Image_init(img,fin);
        seam_carve(img,width,height);
        Image_print(img, fout);
        delete img;
    }
    else{
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
             return 1;
    }
}
    
