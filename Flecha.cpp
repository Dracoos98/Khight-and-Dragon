#include "Flecha.h"

Flecha::Flecha()
{
}

Flecha::~Flecha()
{
}

Flecha::Flecha(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 1, 4, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	dy = -(r->Next(10, 16));
	delete r;
}

void Flecha::Mover(Graphics^ g)
{
	if (y + dy < 1)
	{
		dy = 0;
		eliminar = true;
	}
	y += dy;
}
