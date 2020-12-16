#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include "sculptor.h"

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx=_nx, ny=_ny, nz=_nz;
    v= new Voxel **[nx];
    for(int i=0; i<nx; i++)
    {
        v[i]= new Voxel *[ny];
        for(int j=0; j<ny; j++)
            v[i][j]= new Voxel [nz];
    }

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                v[i][j][k].isOn=false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    delete [] v;

    nx=ny=nz=0;
    r=g=b=a=0;
}

void troca (int &x, int &y)
{
    int aux=0;
    aux=x;
    x=y;
    y=aux;
}

void Sculptor::limpaVoxels(void)
{
    queue <int> q;
    int lx, ly, lz;
    for (int i=1; i<nx-1; i++)
    {
        for (int j=1; j<ny-1; j++)
        {
            for (int k=1; k<nz-1; k++)
            {
                if ( (v[i][j][k].isOn==true) && (v[i-1][j][k].isOn==true) && (v[i+1][j][k].isOn==true) && (v[i][j-1][k].isOn==true) && (v[i][j+1][k].isOn==true) && (v[i][j][k-1].isOn==true) && (v[i][j][k+1].isOn==true) )
                {
                    q.push(i);
                    q.push(j);
                    q.push(k);
                }
            }
        }
    }
    while (!q.empty())
    {
        lx=q.front(); q.pop();
        ly=q.front(); q.pop();
        lz=q.front(); q.pop();
        v[lx][ly][lz].isOn=false;
    }
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    if (r>= 0.0 && r<= 1.0 )
    {
        this->r=r;
    }

    if (g>= 0.0 && g <= 1.0 )
    {
        this->g=g;
    }

    if (b>= 0.0 && b<= 1.0 )
    {
        this->b=b;
    }
    if (g>= 0.0 && g <= 1.0 )
    {
        this->g=g;
    }
    if (alpha>= 0.0 && alpha<= 1.0 )
    {
        a=alpha;
    }
}

void Sculptor::putVoxel(int x, int y, int z)
{
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz)
    {
        v[x][y][z].isOn=true;
        v[x][y][z].r=r;
        v[x][y][z].g=g;
        v[x][y][z].b=b;
        v[x][y][z].a=a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz)
    {
        v[x][y][z].isOn=false;
    }
}

void Sculptor::writeOFF(char* filename)
{
    ofstream fout;
    fout.open(filename);

    if (!fout.is_open())
    {
        exit(0);
    }

    int P0,P1,P2,P3,P4,P5,P6,P7,n=0,nv=0;
    P0=0;
    P1=1;
    P2=2;
    P3=3;
    P4=4;
    P5=5;
    P6=6;
    P7=7;

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                if (v[i][j][k].isOn==true)
                    nv++;
            }
        }
    }

    fout << "OFF" << endl;
    fout << 8*nv << " " << 6*nv << " 0" <<endl;

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                if (v[i][j][k].isOn==true)
                {
                    float xmin,xmax,ymin,ymax,zmin,zmax;
                    xmin=i-0.5;
                    xmax=i+0.5;
                    ymin=j-0.5;
                    ymax=j+0.5;
                    zmin=k-0.5;
                    zmax=k+0.5;

                    fout << xmin << " " << ymax << " " << zmin <<endl;
                    fout << xmin << " " << ymin << " " << zmin <<endl;
                    fout << xmax << " " << ymin << " " << zmin <<endl;
                    fout << xmax << " " << ymax << " " << zmin <<endl;
                    fout << xmin << " " << ymax << " " << zmax <<endl;
                    fout << xmin << " " << ymin << " " << zmax <<endl;
                    fout << xmax << " " << ymin << " " << zmax <<endl;
                    fout << xmax << " " << ymax << " " << zmax <<endl;
                }
            }
        }
    }

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                if (v[i][j][k].isOn==true)
                {
                    fout.setf(std::ios::showpoint);
                    fout << 4 << " " << P0+n << " " << P3+n << " " << P2+n << " " << P1+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P4+n << " " << P5+n << " " << P6+n << " " << P7+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P0+n << " " << P1+n << " " << P5+n << " " << P4+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P0+n << " " << P4+n << " " << P7+n << " " << P3+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P7+n << " " << P6+n << " " << P2+n << " " << P3+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P1+n << " " << P2+n << " " << P6+n << " " << P5+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    n+=8;

                }
            }
        }
    }

    fout.close();
}