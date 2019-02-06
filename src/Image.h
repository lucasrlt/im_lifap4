//
// Created by Lucas on 2019-01-29.
//

#ifndef LIF7_TD_IMAGE_H
#define LIF7_TD_IMAGE_H

#include "Pixel.h"
#include <string>

using namespace std;

class Image {

private:
    Pixel* tab;
    unsigned int dimx, dimy;

public:
    Image();
    Image(unsigned int dimensionX, unsigned int dimensionY);
    ~Image();

    Pixel& getPix(unsigned int x, unsigned int y) const;
    void setPix(unsigned int x, unsigned int y, const Pixel& couleur);

    void dessinerRectangle(unsigned Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel &couleur);
    void effacer(const Pixel &couleur);

    void testRegression();

    void sauver(const string & filename) const;
    void ouvrir(const string & filename);
    void afficherConsole() const;
};


#endif //LIF7_TD_IMAGE_H
