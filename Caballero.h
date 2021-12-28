#pragma once
#include "Base.h"
#include <vector>
#include "Flecha.h"
using namespace std;
class Caballero :
    public Base
{
private:
    int vidas;
    vector<Flecha*>flechas;
    int flechasgastadas;
public:
    Caballero();
    ~Caballero();
    Caballero(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
    void Disparar();
    void Mover_Flechas(Graphics^ g, Bitmap^ bmp);
    vector<Flecha*> retornar_flecha();
    Flecha* retornar_bala_enindice(int indice);
    int retornar_flechasgastadas();
    void cambiar_flechasgastadas(int nuevo);
    int retornar_cant_flechas();
    void cambiar_cantvidas(int nuevo_vidas);
    int retornar_cantvidas();

};

