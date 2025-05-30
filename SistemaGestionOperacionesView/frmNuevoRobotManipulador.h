#pragma once

namespace SistemaGestionOperacionesView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaGestionOperacionesModel;
	using namespace SistemaGestionOperacionesController;

	/// <summary>
	/// Resumen de frmNuevoRobotManipulador
	/// </summary>
	public ref class frmNuevoRobotManipulador : public System::Windows::Forms::Form
	{
	public:
		frmNuevoRobotManipulador(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoRobotManipulador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnGrabar;
	protected:
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::TextBox^ txtCapacidad;

	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::TextBox^ txtX;

	private: System::Windows::Forms::TextBox^ txtIdDispositivo;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtVelocidad;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtZ;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtY;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->txtVelocidad = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtZ = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCapacidad = (gcnew System::Windows::Forms::TextBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->txtIdDispositivo = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(86, 517);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 56);
			this->btnGrabar->TabIndex = 8;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevoRobotManipulador::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(323, 517);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 9;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevoRobotManipulador::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->txtVelocidad);
			this->grpBoxPrincipal->Controls->Add(this->label7);
			this->grpBoxPrincipal->Controls->Add(this->txtZ);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Controls->Add(this->txtY);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtCapacidad);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->txtX);
			this->grpBoxPrincipal->Controls->Add(this->txtIdDispositivo);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(14, 14);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 468);
			this->grpBoxPrincipal->TabIndex = 14;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general del Robot";
			// 
			// txtVelocidad
			// 
			this->txtVelocidad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtVelocidad->Location = System::Drawing::Point(190, 400);
			this->txtVelocidad->Margin = System::Windows::Forms::Padding(5);
			this->txtVelocidad->Name = L"txtVelocidad";
			this->txtVelocidad->Size = System::Drawing::Size(240, 34);
			this->txtVelocidad->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 405);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(127, 29);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Velocidad:";
			// 
			// txtZ
			// 
			this->txtZ->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtZ->Location = System::Drawing::Point(190, 286);
			this->txtZ->Margin = System::Windows::Forms::Padding(5);
			this->txtZ->Name = L"txtZ";
			this->txtZ->Size = System::Drawing::Size(126, 34);
			this->txtZ->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 286);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 29);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Ubic. Z:";
			// 
			// txtY
			// 
			this->txtY->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtY->Location = System::Drawing::Point(190, 232);
			this->txtY->Margin = System::Windows::Forms::Padding(5);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(126, 34);
			this->txtY->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 235);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 29);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Ubic. Y:";
			// 
			// txtCapacidad
			// 
			this->txtCapacidad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCapacidad->Location = System::Drawing::Point(190, 345);
			this->txtCapacidad->Margin = System::Windows::Forms::Padding(5);
			this->txtCapacidad->Name = L"txtCapacidad";
			this->txtCapacidad->Size = System::Drawing::Size(240, 34);
			this->txtCapacidad->TabIndex = 6;
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->ItemHeight = 29;
			this->cmbEstado->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Activo", L"Inactivo", L"De baja", L"Desechado" });
			this->cmbEstado->Location = System::Drawing::Point(190, 112);
			this->cmbEstado->Margin = System::Windows::Forms::Padding(5);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(240, 37);
			this->cmbEstado->TabIndex = 2;
			// 
			// txtX
			// 
			this->txtX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtX->Location = System::Drawing::Point(190, 175);
			this->txtX->Margin = System::Windows::Forms::Padding(5);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(126, 34);
			this->txtX->TabIndex = 3;
			// 
			// txtIdDispositivo
			// 
			this->txtIdDispositivo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdDispositivo->Location = System::Drawing::Point(190, 57);
			this->txtIdDispositivo->Margin = System::Windows::Forms::Padding(5);
			this->txtIdDispositivo->Name = L"txtIdDispositivo";
			this->txtIdDispositivo->Size = System::Drawing::Size(126, 34);
			this->txtIdDispositivo->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 119);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 345);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Capacidad:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 178);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Ubic. X:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 62);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Identificador:";
			// 
			// frmNuevoRobotManipulador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 607);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Name = L"frmNuevoRobotManipulador";
			this->Text = L"Crear un nuevo Robot Manipulador";
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Cierra el formulario actual
	}
		   
private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Aquí deberías implementar la lógica para grabar el nuevo robot manipulador
			   // Por ejemplo, crear una instancia de RobotManipulador y guardarla en la base de datos
	int idDispositivo = Convert::ToInt32(txtIdDispositivo->Text);
	String^ estado = cmbEstado->SelectedItem->ToString();
	float x = Convert::ToSingle(txtX->Text);
	float y = Convert::ToSingle(txtY->Text);
	float z = Convert::ToSingle(txtZ->Text);
	float capacidad = Convert::ToSingle(txtCapacidad->Text);
	float velocidad = Convert::ToSingle(txtVelocidad->Text);
	// Validar los campos antes de guardar
	if (idDispositivo <= 0 || estado->Equals("") || x < 0 || y < 0 || z < 0 || capacidad <= 0 || velocidad <= 0) {
		MessageBox::Show("Por favor, complete todos los campos correctamente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Sale del método si hay errores
	}
	RobotManipuladorController^ controller = gcnew RobotManipuladorController();
	controller->agregarRobot(idDispositivo, estado, x, y, x, capacidad, velocidad);
	MessageBox::Show("Robot Manipulador grabado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close(); // Cierra el formulario después de grabar
}
};
}
