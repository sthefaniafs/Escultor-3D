#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "escultor.hpp"

using namespace std;

int main()
{
    Sculptor coracao (50,50,50);
    coracao.setColor(0,0,0,1);
    coracao.putVoxel(25,25,25);
    coracao.putVoxel(26,25,24);
    coracao.putVoxel(24,25,24);
    coracao.putVoxel(23,25,23);
    coracao.putVoxel(22,25,23);
    coracao.putVoxel(21,25,23);
    coracao.putVoxel(27,25,23);
    coracao.putVoxel(28,25,23);
    coracao.putVoxel(29,25,23);
    coracao.putVoxel(20,25,24);
    coracao.putVoxel(19,25,25);
    coracao.putVoxel(19,25,26);
    coracao.putVoxel(19,25,27);
    coracao.putVoxel(20,25,28);
    coracao.putVoxel(21,25,29);
    coracao.putVoxel(22,25,30);
    coracao.putVoxel(23,25,31);
    coracao.putVoxel(24,25,32);
    coracao.putVoxel(25,25,33);
    coracao.putVoxel(30,25,24);
    coracao.putVoxel(31,25,25);
    coracao.putVoxel(31,25,26);
    coracao.putVoxel(31,25,27);
    coracao.putVoxel(30,25,28);
    coracao.putVoxel(29,25,29);
    coracao.putVoxel(28,25,30);
    coracao.putVoxel(27,25,31);
    coracao.putVoxel(26,25,32);
    coracao.putVoxel(26,25,24);

    coracao.setColor(1,0,0,1);
    coracao.putVoxel(23,25,24);
    coracao.putVoxel(22,25,24);
    coracao.putVoxel(21,25,24);
    coracao.putVoxel(24,25,25);
    coracao.putVoxel(23,25,25);
    coracao.putVoxel(22,25,25);
    coracao.putVoxel(21,25,25);
    coracao.putVoxel(20,25,25);
    coracao.putVoxel(30,25,26);
    coracao.putVoxel(29,25,26);
    coracao.putVoxel(28,25,26);
    coracao.putVoxel(27,25,26);
    coracao.putVoxel(26,25,26);
    coracao.putVoxel(25,25,26);
    coracao.putVoxel(24,25,26);
    coracao.putVoxel(23,25,26);
    coracao.putVoxel(22,25,26);
    coracao.putVoxel(21,25,26);
    coracao.putVoxel(20,25,26);
    coracao.putVoxel(30,25,27);
    coracao.putVoxel(29,25,27);
    coracao.putVoxel(28,25,27);
    coracao.putVoxel(27,25,27);
    coracao.putVoxel(26,25,27);
    coracao.putVoxel(25,25,27);
    coracao.putVoxel(24,25,27);
    coracao.putVoxel(23,25,27);
    coracao.putVoxel(22,25,27);
    coracao.putVoxel(21,25,27);
    coracao.putVoxel(20,25,27);
    coracao.putVoxel(29,25,28);
    coracao.putVoxel(28,25,28);
    coracao.putVoxel(27,25,28);
    coracao.putVoxel(26,25,28);
    coracao.putVoxel(25,25,28);
    coracao.putVoxel(24,25,28);
    coracao.putVoxel(23,25,28);
    coracao.putVoxel(22,25,28);
    coracao.putVoxel(21,25,28);
    coracao.putVoxel(28,25,29);
    coracao.putVoxel(27,25,29);
    coracao.putVoxel(26,25,29);
    coracao.putVoxel(25,25,29);
    coracao.putVoxel(24,25,29);
    coracao.putVoxel(23,25,29);
    coracao.putVoxel(22,25,29);
    coracao.putVoxel(27,25,30);
    coracao.putVoxel(26,25,30);
    coracao.putVoxel(25,25,30);
    coracao.putVoxel(24,25,30);
    coracao.putVoxel(23,25,30);
    coracao.putVoxel(26,25,31);
    coracao.putVoxel(25,25,31);
    coracao.putVoxel(24,25,31);
    coracao.putVoxel(25,25,32);
    coracao.putVoxel(27,25,24);
    coracao.putVoxel(28,25,24);
    coracao.putVoxel(29,25,24);
    coracao.putVoxel(26,25,25);
    coracao.putVoxel(27,25,25);
    coracao.putVoxel(28,25,25);
    coracao.putVoxel(29,25,25);
    coracao.putVoxel(30,25,25);

    coracao.cutVoxel(21,25,25);
    coracao.cutVoxel(22,25,25);
    coracao.cutVoxel(21,25,26);
    coracao.writeOFF((char*)"coracao.off");

    Sculptor esfera(50,50,50);
    esfera.setColor(1,0,0,1);
    esfera.putSphere(20,20,20,10);
    esfera.setColor(0,1,0,1);
    esfera.putBox(19,22,29,31,19,22);
    esfera.putBox(20,23,31,32,19,22);
    esfera.putBox(21,24,32,33,19,22);
    esfera.putBox(22,25,33,34,19,22);
    esfera.putBox(23,26,34,35,19,22);
    esfera.putBox(24,27,35,36,19,22);
    esfera.putBox(24,27,36,37,19,22);
    esfera.setColor(1,0,0,1);
    esfera.putSphere(35,20,35,10);
    esfera.setColor(0,1,0,1);
    esfera.putBox(34,37,29,31,34,37);
    esfera.putBox(33,36,31,32,34,37);
    esfera.putBox(32,35,32,33,34,37);
    esfera.putBox(31,34,33,34,34,37);
    esfera.putBox(30,33,34,35,34,37);
    esfera.putBox(29,32,35,36,34,37);
    esfera.putBox(29,32,36,37,34,37);
    esfera.writeOFF((char*)"cereja.off");

    Sculptor elipse(31,31,31);
    elipse.setColor(0,1,0,1);
    elipse.putEllipsoid(15,15,15,10,10,15);
    elipse.setColor(1,0,0,1);
    elipse.putEllipsoid(15,15,15,9,9,14);
    elipse.cutEllipsoid(15,15,15,8,8,13);
    elipse.cutBox(0,30,0,30,0,5);
    elipse.writeOFF((char*)"elipse.off");

    return 0;
}
