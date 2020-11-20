#include <iostream>
#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP
#include "voxel.hpp"

/**
 * @brief A classe Sculptor serve para realizar esculturas em blocos tridimensionais representados por matrizes digitais
 *
 */

using namespace std;

class Sculptor {
protected:
/**
 * @brief  Matriz de tridimensional do tipo voxel
 * 
 */
  Voxel ***v;
/**
 * @brief Determina a dimensão da matriz
 * 
 */
  int nx,ny,nz; 
  /**
   * @brief Determina a cor da matriz
   * 
   */
  float r,g,b,a; 
public:
/**
 * @brief Construct a new Sculptor object
 * 
 * @param _nx 
 * @param _ny 
 * @param _nz 
 */

  Sculptor(int _nx, int _ny, int _nz); // construtor
  ~Sculptor(); //destrutor
  //funções membro
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(char* filename);
};

#endif // SCULPTOR_HPP
