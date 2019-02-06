//
// Created by Lucas on 2019-01-29.
//

#ifndef LIF7_TD_PIXEL_H
#define LIF7_TD_PIXEL_H


class Pixel {

private:
    unsigned char r, g, b;

public:
    Pixel();
    Pixel(unsigned char r, unsigned char g, unsigned char b);

    unsigned char getRouge() const;
    unsigned char getBleu() const;
    unsigned char getVert() const;

    void setRouge(unsigned char nr);
    void setVert(unsigned char nv);
    void setBleu(unsigned char nb);
};


#endif //LIF7_TD_PIXEL_H
