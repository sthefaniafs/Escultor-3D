#include "putellipsoid.h"
#include <cmath>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, int r, float g, float b, float a)
{   x0=xcenter;
    y0=ycenter;
    z0=zcenter;
    raiox=rx;
    raioy=ry;
    raioz=rz;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

void PutEllipsoid::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);
    int px,py,pz;
    px=py=pz=0;
    for(int i=x0-raiox; i<(x0+raiox); i++)
    {
        for(int j=y0-raioy; j<(y0+raioy); j++)
        {
            for(int k=z0-raioz; k<(z0+raioz); k++)
            {
                px=i-x0;
                py=j-y0;
                pz=k-z0;
                if((pow(px,2)/pow(raiox,2))+(pow(py,2)/pow(raioy,2))+(pow(pz,2)/pow(raioz,2))<=1)
                    {
                        if(i<(x0+raiox) && j<(y0+raioy) && k<(z0+raioz) && i>0 && j>0 && k>0)
                            s.putVoxel(i,j,k);
                    }
            }
        }
    }

}