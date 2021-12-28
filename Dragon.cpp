#include "Dragon.h"

Dragon::Dragon()
{
}

Dragon::Dragon(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 4, 3, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	dx = r->Next(10, 15);
	dy = r->Next(5, 20);
	delete r;
	vidas = 3;
}

Dragon::~Dragon()
{
}

void Dragon::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx>(g->VisibleClipBounds.Width-200))
	{
		dx = dx * -1;
	}
	x = x + dx;
	System::Random^ r = gcnew System::Random();
	if (dx > 0)
	{
		dx = r->Next(5, 20);
		fil = 1;
	}
	else if (dx < 0)
	{
		dx = -1 * (r->Next(5, 20));
		fil = 3;
	}

}

void Dragon::cambiar_cantvidas(int nuevo_vidas)
{
	vidas = nuevo_vidas;
}

int Dragon::retornar_cantvidas()
{
	return vidas;
}

void Dragon::Disparar()
{
	if (bolasf.size() < 3)
	{
		bolasf.push_back(new Bolas_Fuego(x + w / 2, y, 1, 1));
	}
}

void Dragon::Mover_Bolas_Fuegos(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < bolasf.size(); i++)
	{
		bolasf.at(i)->Dibujar_desImagen(g, bmp);
		bolasf.at(i)->Mover(g);
	}
	for (int i = 0; i < bolasf.size(); i++)
	{
		if (bolasf.at(i)->retornar_eliminar() == true)
			bolasf.erase(bolasf.begin() + i);
	}
}

vector<Bolas_Fuego*> Dragon::retornar_Bolas_Fuego()
{
	return bolasf;
}

Bolas_Fuego* Dragon::retornar_bala_enindice(int indice)
{
	return bolasf.at(indice);
}

int Dragon::retornar_cant_Bolas_Fuegos()
{
	return bolasf.size();
}
