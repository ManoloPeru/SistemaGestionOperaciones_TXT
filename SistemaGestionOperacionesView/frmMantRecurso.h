#pragma once
#include "frmNuevoRecurso.h"
#include "frmEditarRecurso.h"

namespace SistemaGestionOperacionesView
{

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
	/// Resumen de frmMantRecurso
	/// </summary>
public
	ref class frmMantRecurso : public System::Windows::Forms::Form
	{
	public:
		frmMantRecurso(void)
		{
			InitializeComponent();
			//
			// TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~frmMantRecurso()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Button ^ btnEliminar;

	protected:
	private:
		System::Windows::Forms::Button ^ btnBuscar;

	private:
		System::Windows::Forms::TextBox ^ txtNombre;

	private:
		System::Windows::Forms::Label ^ label1;

	private:
		System::Windows::Forms::Button ^ btnEditar;

	private:
		System::Windows::Forms::Button ^ btnNuevo;

	private:
		System::Windows::Forms::DataGridView ^ dgvLista;

	private:
		System::Windows::Forms::GroupBox ^ groupBox1;

	private:
		System::Windows::Forms::DataGridViewTextBoxColumn ^ colId;

	private:
		System::Windows::Forms::DataGridViewTextBoxColumn ^ colNombre;

	private:
		System::Windows::Forms::DataGridViewTextBoxColumn ^ colCantidad;

	private:
		System::Windows::Forms::DataGridViewTextBoxColumn ^ colEstado;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->dgvLista))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			//
			// btnEliminar
			//
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(831, 590);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(5);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(131, 42);
			this->btnEliminar->TabIndex = 5;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantRecurso::btnEliminar_Click);
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
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantRecurso::btnBuscar_Click);
			//
			// txtNombre
			//
			this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
																		  static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																 static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(164, 57);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(366, 34);
			this->txtNombre->TabIndex = 1;
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
															  static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 60);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre :";
			//
			// btnEditar
			//
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																 static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(571, 590);
			this->btnEditar->Margin = System::Windows::Forms::Padding(5);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(131, 42);
			this->btnEditar->TabIndex = 4;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantRecurso::btnEditar_Click);
			//
			// btnNuevo
			//
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(288, 590);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(5);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(131, 42);
			this->btnNuevo->TabIndex = 3;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantRecurso::btnNuevo_Click);
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
			this->dgvLista->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(4){
				this->colId, this->colNombre,
				this->colCantidad, this->colEstado});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
																		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLista->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvLista->Location = System::Drawing::Point(23, 161);
			this->dgvLista->Margin = System::Windows::Forms::Padding(5);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1231, 402);
			this->dgvLista->TabIndex = 6;
			//
			// colId
			//
			this->colId->HeaderText = L"Id";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			this->colId->Width = 125;
			//
			// colNombre
			//
			this->colNombre->HeaderText = L"Nombre de Recurso";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 400;
			//
			// colCantidad
			//
			this->colCantidad->HeaderText = L"Cantidad";
			this->colCantidad->MinimumWidth = 6;
			this->colCantidad->Name = L"colCantidad";
			this->colCantidad->Width = 120;
			//
			// colEstado
			//
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 120;
			//
			// groupBox1
			//
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																 static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(23, 21);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1231, 116);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de B�squeda";
			//
			// frmMantRecurso
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1268, 673);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantRecurso";
			this->Text = L"Mantenimiento de Recursos";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmMantRecurso::frmMantRecurso_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void frmMantRecurso_Load(System::Object ^ sender, System::EventArgs ^ e)
		{
			// Cargar los recursos en el DataGridView al iniciar el formulario
			// Aqu� deber�as llamar a tu controlador para obtener la lista de recursos y llenarla en el DataGridView
			RecursoController ^ recursoController = gcnew RecursoController();
			List<Recurso ^> ^ listaRecursos = recursoController->listarTodos();
			mostrarGrilla(listaRecursos);
		}

		/*METODOSPERSONALES*/
	public:	void mostrarGrilla(List<Recurso ^> ^ listaRecursos)
		{
			this->dgvLista->Rows->Clear();
			for (int i = 0; i < listaRecursos->Count; i++)
			{
				Recurso ^ recurso = listaRecursos[i];
				array<String ^> ^ filaGrilla = gcnew array<String ^>(7);
				filaGrilla[0] = Convert::ToString(recurso->getIdRecurso());
				filaGrilla[1] = recurso->getNombre();
				filaGrilla[2] = Convert::ToString(recurso->getCantidad());
				filaGrilla[3] = recurso->getEstado();
				this->dgvLista->Rows->Add(filaGrilla);
			}
			this->dgvLista->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
			this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		}

	private:System::Void btnNuevo_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			// Crear una nueva instancia del formulario de nuevo recurso
			// y mostrarlo como un formulario hijo dentro del contenedor MDI
			frmNuevoRecurso ^ nuevoRecursoForm = gcnew frmNuevoRecurso();
			nuevoRecursoForm->ShowDialog(this);
			// Llamar al m�todo para cargar la lista de recursos nuevamente
			RecursoController ^ recursoController = gcnew RecursoController();
			List<Recurso ^> ^ listaRecursos = recursoController->listarTodos();
			mostrarGrilla(listaRecursos);
		}

	private:System::Void btnEditar_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			// Verificar si se ha seleccionado una fila en el DataGridView
			if (this->dgvLista->SelectedRows->Count > 0)
			{
				int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index;
				int idRecurso = Convert::ToInt32(this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value);

				RecursoController ^ recursoController = gcnew RecursoController();
				Recurso ^ recursoSeleccionado = recursoController->buscarRecursoxidRecurso(idRecurso);
				if (recursoSeleccionado == nullptr)
				{
					MessageBox::Show("No se encontr� el recurso seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				// Crear una nueva instancia del formulario de nuevo recurso
				// y mostrarlo como un formulario hijo dentro del contenedor MDI
				frmEditarRecurso ^ editarRecursoForm = gcnew frmEditarRecurso(recursoSeleccionado);
				editarRecursoForm->ShowDialog();
				// Llamar al m�todo para cargar la lista de recursos nuevamente
				List<Recurso ^> ^ listaRecursos = recursoController->listarTodos();
				mostrarGrilla(listaRecursos);
			}
			else
			{
				MessageBox::Show("Por favor, seleccione un recurso para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

	private:System::Void btnEliminar_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			// Verificar si se ha seleccionado una fila en el DataGridView
			if (this->dgvLista->SelectedRows->Count > 0)
			{

				// Preguntar al usuario si est� seguro de eliminar el registro
				System::Windows::Forms::DialogResult resultado = MessageBox::Show("�Est� seguro de que desea eliminar el registro seleccionado?",
																				  "Confirmaci�n de eliminaci�n", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				// Si el usuario selecciona "No", cancelar la operaci�n
				if (resultado == System::Windows::Forms::DialogResult::No)
				{
					return; // Salir del evento si el usuario cancela
				}

				int selectedRowIndex = this->dgvLista->SelectedRows[0]->Index;
				int idRecurso = Convert::ToInt32(this->dgvLista->Rows[selectedRowIndex]->Cells[0]->Value);
				// Crear una instancia del controlador y eliminar el recurso
				RecursoController ^ recursoController = gcnew RecursoController();
				recursoController->eliminarRecurso(idRecurso);
				// Actualizar la lista de recursos en el DataGridView
				List<Recurso ^> ^ listaRecursos = recursoController->listarTodos();
				mostrarGrilla(listaRecursos);
			}
			else
			{
				MessageBox::Show("Por favor, seleccione un recurso para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

	private:System::Void btnBuscar_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			// Obtener el nombre del recurso a buscar
			String ^ nombreRecurso = txtNombre->Text;
			// Crear una instancia del controlador y buscar el recurso por nombre
			RecursoController ^ recursoController = gcnew RecursoController();
			List<Recurso ^> ^ listaRecursos = recursoController->buscarRecursoxNombre(nombreRecurso);
			// Mostrar los resultados en el DataGridView
			mostrarGrilla(listaRecursos);
		}
	};
}
