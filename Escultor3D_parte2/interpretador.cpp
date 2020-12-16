#include <iostream>
#include <fstream>
#include <sstream>
#include "interpretador.h"
#include "interpretador.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"

using namespace std;

vector <FiguraGeometrica*> Interpretador:: parse (string filename)
{
    vector <FiguraGeometrica*> figs;
    ifstream arquivo;
    stringstream ss;
    string s, token;

    arquivo.open(filename.c_str());

    if (!arquivo.is_open())
    {
        cout << "nao abriu " << filename;
        exit(0);
    }

    while(arquivo.good())
    {
        getline(fin,s);
        if(arquivo.good())
        {
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good())
            {
                if(token.compare("dim")==0)
                {
                    ss >> dimx >> dimy >> dimz;
                }
                else if (token.compare("putvoxel")==0)
                {
                    int x0,y0,z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));

                }
                else if (token.compare("cutvoxel")==0)
                {
                    int x0,y0,z0;
                    ss >> x0 >> y0 >> z0;
                    figs.push_back(new CutVoxel(x0,y0,z0));

                }
                else if (token.compare("putbox")==0)
                {
                    int x0,y0,z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));

                }
                else if (token.compare("cutbox")==0)
                {
                    int x0,y0,z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));

                }
                 else if (token.compare("putsphere")==0)
                {
                    int x0, y0, z0, raio;
                    ss >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));

                }
                else if (token.compare("cutsphere")==0)
                {
                    int x0, y0, z0, raio;
                    ss >> x0 >> y0 >> z0 >> raio;
                    figs.push_back(new CutSphere(x0,y0,z0,raio));

                }
                 else if (token.compare("putellipsoid")==0)
                {
                    int x0, y0, z0, raiox, raioy, raioz;
                    ss >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(x0,y0,z0,raiox,raioy,raioz,r,g,b,a));
                }
                else if (token.compare("cutellipsoid")==0)
                {
                    int x0, y0, z0, raiox, raioy, raioz;
                    ss >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz;
                    figs.push_back(new CutEllipsoid(x0,y0,z0,raiox,raioy,raioz));
                }
                else
                {
                    cout << "Comando inexistente no programa\n"; 
                }
                

            }
        }
    }

    return (figs);
}


int Interpretador::getDimx()
{
    return dimx;
}

int Interpretador::getDimy()
{
    return dimy;
}

int Interpretador::getDimz()
{
    return dimz;
}