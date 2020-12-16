#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

class PutEllipsoid: public FiguraGeometrica {
    int x0, y0, z0, raiox, raioy, raioz;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, int r, float g, float b, float a);
    ~PutEllipsoid(){}
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H