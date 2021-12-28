#pragma once
#include "Base.h"
#include <vector>
#include "Bolas_Fuego.h"
using namespace std;
class Dragon :
    public Base
{
private:
    int vidas;
    vector<Bolas_Fuego*>bolasf;
public:
    Dragon(int px, int py, int pw, int ph);
    Dragon();
    ~Dragon();
    void Mover(Graphics^ g);
    void cambiar_cantvidas(int nuevo_vidas);
    int retornar_cantvidas();
    void Disparar();
    void Mover_Bolas_Fuegos(Graphics^ g, Bitmap^ bmp);
    vector<Bolas_Fuego*> retornar_Bolas_Fuego();
    Bolas_Fuego* retornar_bala_enindice(int indice);
    int retornar_cant_Bolas_Fuegos();
};

