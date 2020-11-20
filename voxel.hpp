#include <iostream>
#ifndef VOXEL_HPP
#define VOXEL_HPP

/**
 * @brief A struct Voxel desempenha o papel de um pixel 3D
 * - Para isso, a struct conta com a capacidade de armazenar informações como cor e transparência, necessárias para idealizar os elementos de uma escultura. As cores são representadas numa faixa de [0,1], onde 0 denota ausência total da componente e 1 denota a presença total da componente de cor. Na transparência os valores também devem está na faixa [0,1], onde 0 denota transparência total e 1 denota total opacidade. Além disso, a classe possui um booleano usado para ativar ou não o voxel.
 */
struct Voxel {
  /**
   * @brief \b r armazena o valor correspondente a cor vermelha
   * 
   */
  float r;
  /**
   * @brief \b g armazena o valor correspondente a cor verde
   * 
   */
  float g;
  /**
   * @brief \b b armazena o valor correspondente a cor azul
   * 
   */
  float b;
  /**
   * @brief \b a armazena o valor correspondente a transparência do desenho 
   * 
   */
  float a; 
  /**
   * @brief \b isOn define se o voxel correspondente deve ser incluído no arquivo digital 
   * 
   */
  bool isOn;
};
#endif // VOXEL_HPP

