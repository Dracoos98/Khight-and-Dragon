#pragma once
#include "Caballero.h"
#include "Dragon.h"
#include<time.h>
class Controladora
{
private:
	Caballero* objC;
	Dragon* objD;
public:
	Controladora();
	~Controladora();
	void Dibujar_Caballero(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Dragon(Graphics^ g, Bitmap^ bmp);
	void Desplazar_Caballero(direccion nuevo);
	void Disparar();
	void Dibujar_Flecha(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Bolaf(Graphics^ g, Bitmap^ bmp);
	int retonar_flechasgastadas();
	bool Colision1();
	bool Colision2();
	int retornar_vidasD();
	int retornar_vidasC();
};

