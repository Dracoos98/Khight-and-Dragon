#pragma once
#include "Controladora.h"
namespace CaballeroyDragon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objcontroladora = new Controladora();
			bmpcaballero = gcnew Bitmap("Caballero.png");
			bmpflecha = gcnew Bitmap("Flecha.jpg");
			bmpdragon = gcnew Bitmap("Dragones.png");
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete bmpcaballero,objcontroladora,bmpflecha,bmpdragon;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Controladora* objcontroladora;
		Bitmap^ bmpcaballero;
		Bitmap^ bmpflecha;
		Bitmap^ bmpdragon;
		//Bitmap^ bmpbolaf;
		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(763, 646);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arian", 10);
		System::Drawing::Font^ k = gcnew System::Drawing::Font("Arian", 20);
		System::Drawing::SolidBrush^ sb = gcnew System::Drawing::SolidBrush(Color::Black);
		System::Drawing::SolidBrush^ sbh = gcnew System::Drawing::SolidBrush(Color::DarkRed);
		System::Drawing::SolidBrush^ sbg = gcnew System::Drawing::SolidBrush(Color::Green);
		String^ s = "Cantidad de flechas restantes: ";
		int flechas_restantes = 25-objcontroladora->retonar_flechasgastadas();
		if (flechas_restantes <= 0) {
			timer1->Enabled = false;
			bf->Graphics->Clear(Color::White);
			
			bf->Graphics->DrawString("Perdio", k, sbh, 40, 40);
		}
		
		bf->Graphics->DrawString(s + flechas_restantes.ToString(), f, sb, 10, 10);
		objcontroladora->Dibujar_Caballero(bf->Graphics, bmpcaballero);
		objcontroladora->Dibujar_Dragon(bf->Graphics, bmpdragon);
		//objcontroladora->Dibujar_Bolaf(bf->Graphics, bmpbolaf);
		objcontroladora->Dibujar_Flecha(bf->Graphics, bmpflecha);
		if (objcontroladora->retornar_vidasD() == 0)
		{
			timer1->Enabled = false;
			bf->Graphics->Clear(Color::White);
			
			bf->Graphics->DrawString("Gano", k, sbg, 40, 40);
		}
		//if (objcontroladora->retornar_vidasC() == 0)
		//{
			//timer1->Enabled = false;
			//bf->Graphics->Clear(Color::White);
			
			//bf->Graphics->DrawString("Perdio", k, sbg, 40, 40);
		//}
		bf->Render(g);
		delete bf, espacio, g;

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objcontroladora->Desplazar_Caballero(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objcontroladora->Desplazar_Caballero(direccion::derecha);
		if (e->KeyCode == Keys::Up) objcontroladora->Desplazar_Caballero(direccion::arriba);
		if (e->KeyCode == Keys::Down)objcontroladora->Desplazar_Caballero(direccion::abajo);
		if (e->KeyCode == Keys::Space)objcontroladora->Disparar();
	}
	};
}
