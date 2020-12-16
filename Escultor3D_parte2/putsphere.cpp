#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, int r, float g, float b, float a)
{
    x0=xcenter;
    y0=ycenter;
    z0=zcenter;
    raio=radius;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

void PutSphere::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);
    int px,py,pz;
    px=py=pz=0;
    for(int i=x0-raio; i<(x0+raio); i++)
    {
        for(int j=y0-raio; j<(y0+raio); j++)
        {
            for(int k=z0-raio; k<(z0+raio); k++)
            {
                px=i-x0;
                py=j-y0;
                pz=k-z0;
                if(pow(px,2)+pow(py,2)+pow(pz,2)<=pow(raio,2))
                    {
                        if(i<(x0+raio) && j<(y0+raio)&& k<(z0+raio) && i>0 && j>0 && k>0)
                            s.putVoxel(i,j,k);
                    }
            }
        }
    }

}