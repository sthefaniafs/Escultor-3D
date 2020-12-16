#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"

class PutSphere: public FiguraGeometrica {
    int x0, y0, z0, raio;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, int r, float g, float b, float a);
    ~PutSphere(){}
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H