#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

class CutVoxel : public FiguraGeometrica {
    int x, y, z;
public:
    CutVoxel (int x0, int y0, int z0);
    ~CutVoxel(){}
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H