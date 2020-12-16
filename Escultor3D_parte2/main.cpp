#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "figurageometrica.h"
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

int main()
{
    Sculptor *s2;
    Interpretador leitor;

    vector <FiguraGeometrica*> figs;
    figs=leitor.parse("C:/Users/sthef/Documents/Programação Avançada/Escultor3D_parte2/figura.txt");

    s2= new Sculptor(leitor.getDimx(), leitor.getDimy(), leitor.getDimz());

    for (int i=0; i<figs.size(); i++)
    {
        cout << "draw \n";
        figs[i]->draw(*s2);
    }

    s2->limpaVoxels();
    s2->writeOFF((char*)"C:/Users/sthef/Documents/Programação Avançada/Escultor3D_parte2/desenho.off");
    
    for (int i=0; i<figs.size(); i++)
    {
        delete figs[i];
    }

    delete s2;
    return 0;
}
