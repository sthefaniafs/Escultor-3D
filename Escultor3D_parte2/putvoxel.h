#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica {
    int x, y, z;
public:
    PutVoxel (int x0, int y0, int z0, float r, float g, float b, float a);
    ~PutVoxel(){}
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
