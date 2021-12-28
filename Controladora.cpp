#include "Controladora.h"
#include "stdlib.h"

Controladora::Controladora()
{
	System::Random^ r = gcnew System::Random();
	objC = new Caballero(250, 400,20, 20);
	objD = new Dragon(80, 10, 1, 1);
}

Controladora::~Controladora()
{
	delete objC;
}

void Controladora::Dibujar_Caballero(Graphics^ g, Bitmap^ bmp)
{
	objC->Dibujar_desImagen(g, bmp);
	objC->Mover(g);
}

void Controladora::Dibujar_Dragon(Graphics^ g, Bitmap^ bmp)
{
	objD->Dibujar_desImagen(g, bmp);
	objD->Mover(g);
}

void Controladora::Desplazar_Caballero(direccion nuevo)
{
	objC->Desplazamiento(nuevo);
	Colision1();
	//Colision2();

}

void Controladora::Disparar()
{
	objC->Disparar();
	objC->cambiar_flechasgastadas(objC->retornar_flechasgastadas()+1);
}

void Controladora::Dibujar_Flecha(Graphics^ g, Bitmap^ bmp)
{
	objC->Mover_Flechas(g, bmp);
}

void Controladora::Dibujar_Bolaf(Graphics^ g, Bitmap^ bmp)
{
	objD->Mover_Bolas_Fuegos(g, bmp);
}

int Controladora::retonar_flechasgastadas()
{
	return objC->retornar_flechasgastadas();
}


bool Controladora::Colision1()
{
	Rectangle rnave = objC->retonar_rectangle();
	bool resultado_colision = false;
	for (int i = 0; !resultado_colision && i < objC->retornar_cant_flechas(); i++)
	{
		Rectangle rbalas = objC->retornar_bala_enindice(i)->retonar_rectangle();
		
		Rectangle rdragon = objD->retonar_rectangle();
		if (rbalas.IntersectsWith(rdragon))
		{
				resultado_colision = true;
				objC->retornar_bala_enindice(i)->cambiar_eliminar(true);
				objD->cambiar_cantvidas(objD->retornar_cantvidas() - 1);
				if (objD->retornar_cantvidas() == 0)
				{
					objD->cambiar_eliminar(resultado_colision);
				}
		}
		
	}
	return resultado_colision;
}

bool Controladora::Colision2()
{
	Rectangle rnave = objC->retonar_rectangle();
	bool resultado_colision2 = false;
	for (int i = 0; !resultado_colision2 && i < objC->retornar_cant_flechas(); i++)
	{
		Rectangle rbalas = objD->retornar_bala_enindice(i)->retonar_rectangle();

		if (rbalas.IntersectsWith(rnave))
		{
			resultado_colision2 = true;
			objD->retornar_bala_enindice(i)->cambiar_eliminar(true);
			objC->cambiar_cantvidas(objD->retornar_cantvidas() - 1);
			if (objC->retornar_cantvidas() == 0)
			{
				objC->cambiar_eliminar(resultado_colision2);
			}
		}

	}
	return resultado_colision2;
}


int Controladora::retornar_vidasD()
{
	return objD->retornar_cantvidas();
}

int Controladora::retornar_vidasC()
{
	return objC->retornar_cantvidas();
}
