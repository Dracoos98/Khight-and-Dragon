#include "Caballero.h"

Caballero::Caballero()
{
}

Caballero::~Caballero()
{
}

Caballero::Caballero(int px, int py, int pw, int ph) : Base(px, py, pw, ph, 4, 7, 0, 0)
{
	vidas = 2;
	fraccion_movimientoX = 2;
	fraccion_movimientoY = 2;
	orientacion = direccion::derecha;
	flechasgastadas = 0;
}

void Caballero::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)dx = 0;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dy = 0;
	x += dx;
	y += dy;
}

void Caballero::Disparar()
{
	flechas.push_back(new Flecha(x + w / 2, y, 1, 1));
}

void Caballero::Mover_Flechas(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < flechas.size(); i++)
	{
		flechas.at(i)->Dibujar_desImagen(g, bmp);
		flechas.at(i)->Mover(g);
	}
	for (int i = 0; i < flechas.size(); i++)
	{
		if (flechas.at(i)->retornar_eliminar() == true)
			flechas.erase(flechas.begin() + i);
	}
}

vector<Flecha*> Caballero::retornar_flecha()
{
	return flechas;
}

int Caballero::retornar_cant_flechas()
{
	return flechas.size();
}

void Caballero::cambiar_cantvidas(int nuevo_vidas)
{
	vidas = nuevo_vidas;
}

int Caballero::retornar_cantvidas()
{
	return vidas;
}

Flecha* Caballero::retornar_bala_enindice(int indice)
{
	return flechas.at(indice);
}

int Caballero::retornar_flechasgastadas()
{
	return flechasgastadas;
}

void Caballero::cambiar_flechasgastadas(int nuevo)
{
 flechasgastadas=nuevo;
}
