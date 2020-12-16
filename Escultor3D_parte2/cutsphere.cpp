#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    x0=xcenter;
    y0=ycenter;
    z0=zcenter;
    raio=radius;
}

void CutSphere::draw(Sculptor &s)
{
    int px,py,pz;
    px=py=pz=0;
    for(int i=0; i<(2*x0); i++)
    {
        for(int j=0; j<(2*y0); j++)
        {
            for(int k=0; k<(2*z0); k++)
            {
                px=i-x0;
                py=j-y0;
                pz=k-z0;
                if(pow(px,2)+pow(py,2)+pow(pz,2)<=pow(raio,2))
                    {
                        if(i<(2*x0) && j<(2*y0)&& k<(2*z0) && i>0 && j>0 && k>0)
                            s.cutVoxel(i,j,k);
                    }
            }
        }
    }

}


