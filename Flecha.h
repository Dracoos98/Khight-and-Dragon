#pragma once
#include "Base.h"
class Flecha :
    public Base
{
public:
    Flecha();
    ~Flecha();
    Flecha(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
};

