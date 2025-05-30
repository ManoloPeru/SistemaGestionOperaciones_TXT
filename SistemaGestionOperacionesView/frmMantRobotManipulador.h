#pragma once
#include "frmNuevoRobotManipulador.h";

namespace SistemaGestionOperacionesView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaGestionOperacionesModel;
	using namespace SistemaGestionOperacionesController;

	/// <summary>
	/// Resumen de frmMantRobotManipulador
	/// </summary>
	public ref class frmMantRobotManipulador : public System::Windows::Forms::Form
	{
	public:
		frmMantRobotManipulador(void)
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
		~frmMantRobotManipulador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEliminar;
	protected:
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;




	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtIdDispositivo;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdDispositivo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colZ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCapacidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colVelocidad;








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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colIdDispositivo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colZ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCapacidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colVelocidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtIdDispositivo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(822, 584);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(5);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(131, 42);
			this->btnEliminar->TabIndex = 9;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(562, 584);
			this->btnEditar->Margin = System::Windows::Forms::Padding(5);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(131, 42);
			this->btnEditar->TabIndex = 8;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(279, 584);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(5);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(131, 42);
			this->btnNuevo->TabIndex = 7;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantRobotManipulador::btnNuevo_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->colIdDispositivo,
					this->colEstado, this->colX, this->colY, this->colZ, this->colCapacidad, this->colVelocidad
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLista->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvLista->Location = System::Drawing::Point(14, 155);
			this->dgvLista->Margin = System::Windows::Forms::Padding(5);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1231, 402);
			this->dgvLista->TabIndex = 11;
			// 
			// colIdDispositivo
			// 
			this->colIdDispositivo->HeaderText = L"Id";
			this->colIdDispositivo->MinimumWidth = 6;
			this->colIdDispositivo->Name = L"colIdDispositivo";
			this->colIdDispositivo->Width = 125;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 120;
			// 
			// colX
			// 
			this->colX->HeaderText = L"Ub. X";
			this->colX->MinimumWidth = 6;
			this->colX->Name = L"colX";
			this->colX->Width = 120;
			// 
			// colY
			// 
			this->colY->HeaderText = L"Ub. Y";
			this->colY->MinimumWidth = 6;
			this->colY->Name = L"colY";
			this->colY->Width = 120;
			// 
			// colZ
			// 
			this->colZ->HeaderText = L"Ub. Z";
			this->colZ->MinimumWidth = 6;
			this->colZ->Name = L"colZ";
			this->colZ->Width = 120;
			// 
			// colCapacidad
			// 
			this->colCapacidad->HeaderText = L"Capacidad de carga";
			this->colCapacidad->MinimumWidth = 6;
			this->colCapacidad->Name = L"colCapacidad";
			this->colCapacidad->Width = 300;
			// 
			// colVelocidad
			// 
			this->colVelocidad->HeaderText = L"Velocidad";
			this->colVelocidad->MinimumWidth = 6;
			this->colVelocidad->Name = L"colVelocidad";
			this->colVelocidad->Width = 150;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtIdDispositivo);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(14, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1231, 116);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnBuscar->Location = System::Drawing::Point(594, 58);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(5);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(131, 42);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			// 
			// txtIdDispositivo
			// 
			this->txtIdDispositivo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdDispositivo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtIdDispositivo->Location = System::Drawing::Point(164, 57);
			this->txtIdDispositivo->Margin = System::Windows::Forms::Padding(5);
			this->txtIdDispositivo->Name = L"txtIdDispositivo";
			this->txtIdDispositivo->Size = System::Drawing::Size(366, 34);
			this->txtIdDispositivo->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 60);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID :";
			// 
			// frmMantRobotManipulador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1383, 786);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantRobotManipulador";
			this->Text = L"Mantenimiento de  los Robot Manipulador";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmMantRobotManipulador::frmMantRobotManipulador_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantRobotManipulador_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargar los registros en el DataGridView al iniciar el formulario
		// Aquí deberías llamar a tu controlador para obtener la lista de RobotManipulado y llenarla en el DataGridView
		RobotManipuladorController^ robotController = gcnew RobotManipuladorController();
		List<RobotManipulador^>^ listaRobotsManipulador = robotController->listarTodos();
		mostrarGrilla(listaRobotsManipulador);
	}

		   /*METODOSPERSONALES*/
	public: void mostrarGrilla(List<RobotManipulador^>^ listaRobotsManipulador) {
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaRobotsManipulador->Count; i++) {
			RobotManipulador^ robot = listaRobotsManipulador[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(robot->getIdDispositivo());
			filaGrilla[1] = robot->getEstado();
			filaGrilla[2] = Convert::ToString(robot->getUbicacionX());
			filaGrilla[3] = Convert::ToString(robot->getUbicacionY());
			filaGrilla[4] = Convert::ToString(robot->getUbicacionZ());
			filaGrilla[5] = Convert::ToString(robot->getCapacidadCarga());
			filaGrilla[6] = Convert::ToString(robot->getVelocidad());
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generación automática de columnas
		this->dgvLista->AllowUserToAddRows = false; // Evitar que el usuario pueda agregar filas manualmente
	}
private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
	// Crear una nueva instancia del formulario de nuevo recurso
			// y mostrarlo como un formulario hijo dentro del contenedor MDI
	frmNuevoRobotManipulador^ nuevoRobotManipuladorForm = gcnew frmNuevoRobotManipulador();
	nuevoRobotManipuladorForm->ShowDialog(this);
	// Llamar al m?todo para cargar la lista de recursos nuevamente
	RobotManipuladorController^ recursoController = gcnew RobotManipuladorController();
	List<RobotManipulador^>^ listaRobotManipuladors = recursoController->listarTodos();
	mostrarGrilla(listaRobotManipuladors);
}
};
}
