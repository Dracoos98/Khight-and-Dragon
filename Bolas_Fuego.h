#pragma once
#include "Base.h"
class Bolas_Fuego :
    public Base
{
public:
    Bolas_Fuego();
    ~Bolas_Fuego();
    Bolas_Fuego(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
};

