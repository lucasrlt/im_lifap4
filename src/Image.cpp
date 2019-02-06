//
// Created by Lucas on 2019-01-29.
//

#include "Image.h"
#include <iostream>
#include <fstream>

Image::Image() {
    dimx = 0;
    dimy = 0;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY) {
    dimx = dimensionX;
    dimy = dimensionY;

    tab = new Pixel[dimx * dimy];
}

Image::~Image() {
    dimx = 0;
    dimy = 0;
    delete [] tab;
}

Pixel& Image::getPix(unsigned int x, unsigned int y) const {
    assert(x < dimx && y < dimy);
    return tab[y * dimx + x];
}

void Image::setPix(unsigned int x, unsigned int y, const Pixel& couleur) {
    assert(x < dimx && y < dimy);
    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax,
                              const Pixel &couleur) {

    assert(Xmin < Xmax && Xmin < dimx && Xmax <= dimx && Ymin < Ymax && Ymin < dimy && Ymax <= dimy);

    for (unsigned int y = Ymin; y < Ymax; ++y) {
        for (unsigned int x = Xmin; x < Xmax; ++x) {
            setPix(x, y, couleur);
        }
    }
}

void Image::effacer(const Pixel &couleur) {
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::sauver(const string & filename) const {
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());

    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    for (unsigned int y = 0; y < dimy; ++y) {
        for (unsigned int x = 0; x < dimx; ++x) {
            Pixel pix = getPix(x, y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    }

    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());

    unsigned int r,g,b;
    string mot;

    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);

    if (tab != NULL) delete [] tab;

    tab = new Pixel[dimx * dimy];

    for(unsigned int y = 0; y < dimy; ++y) {
        for (unsigned int x = 0; x < dimx; ++x) {
            fichier >> r >> g >> b;
            getPix(x, y).setRouge((unsigned char) r);
            getPix(x, y).setVert((unsigned char) g);
            getPix(x, y).setBleu((unsigned char) b);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole() const {
    cout << dimx << " " << dimy << endl;

    for(unsigned int y = 0; y < dimy; ++y) {
        for(unsigned int x = 0; x < dimx; ++x) {
            Pixel pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

void Image::testRegression() {
    // Test condition normale.
    Image im(10, 10);

    assert(im.dimx == 10 && im.dimy == 10);
    assert(im.getPix(0, 0).getBleu() == 0 && im.getPix(0, 0).getVert() == 0 && im.getPix(0, 0).getRouge() == 0);

    Pixel p(127, 127, 127);
    im.setPix(5, 5, p);

    Pixel modif = im.getPix(5, 5);
    assert(modif.getBleu() == 127 && modif.getVert() == 127 && modif.getRouge() == 127);

    im.dessinerRectangle(0, 0, 5, 5, p);
    for (unsigned int i = 0; i < 5; ++i) {
        for (unsigned int j = 0; j < 5; ++j) {
            assert(im.getPix(j, i).getRouge() == 127);
        }
    }

    // Test image lourde.
    Image imLarge(1000, 1000);
    assert(imLarge.getPix(999, 999).getBleu() == 0);

    Pixel color(100, 100, 100);
    imLarge.dessinerRectangle(0, 0, 999, 999, color);
    assert(imLarge.getPix(500, 500).getBleu() == color.getBleu());

    // Test pointeur
    Image* imgPtr = new Image(5, 5);
    assert(imgPtr->dimx == 5 && imgPtr->dimy == 5);
    assert(imgPtr->getPix(2, 2).getBleu() == 0);

    imgPtr->dessinerRectangle(1, 1, 3, 3, color);
    for (unsigned int i = 1; i < 3; ++i) {
        for (unsigned int j = 1; j < 3; ++j) {
            assert(imgPtr->getPix(j, i).getRouge() == color.getBleu());
        }
    }

    delete imgPtr;
}