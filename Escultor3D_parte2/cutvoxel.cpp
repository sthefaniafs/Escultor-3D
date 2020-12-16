#include "cutvoxel.h"

CutVoxel::CutVoxel(int x0, int y0, int z0)
{
    x=x0;
    y=y0;
    z=z0;
}

void CutVoxel::draw(Sculptor &s)
{
    s.cutVoxel(x,y,z);
}