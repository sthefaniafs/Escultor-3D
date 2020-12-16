#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP
#include "voxel.h"

using namespace std;

class Sculptor {
protected:
  Voxel ***v;
  int nx,ny,nz;
  float r,g,b,a;
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(char* filename);
  void limpaVoxels();
};
void troca (int &x, int &y);

#endif // SCULPTOR_HPP