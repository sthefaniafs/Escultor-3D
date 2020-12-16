#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

class CutEllipsoid: public FiguraGeometrica {
    int x0, y0, z0, raiox, raioy, raioz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid(){}
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
