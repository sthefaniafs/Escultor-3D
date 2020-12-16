#include "cutellipsoid.h"
#include <cmath>

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    x0=xcenter;
    y0=ycenter;
    z0=zcenter;
    raiox=rx;
    raioy=ry;
    raioz=rz;
}

void CutEllipsoid::draw(Sculptor &s)
{
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
                            s.cutVoxel(i,j,k);
                    }
            }
        }
    }

}



