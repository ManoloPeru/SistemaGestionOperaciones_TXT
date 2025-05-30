#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class SistemaRegistroDatosController {
	public:
		SistemaRegistroDatosController();
		List<SistemaRegistroDatos^>^ listarTodos();
		SistemaRegistroDatos^ buscarSistemaRegistroDatosxId(int id);
		List<SistemaRegistroDatos^>^ buscarSistemaRegistroDatosxFechaAsignacion(String^ fechaAsignacion);
		void agregarSistemaRegistroDatos(int id, String^ fecha, String^ hora, String^ tipoDato, float valorRegistrado);
		void escribirArchivo(List<SistemaRegistroDatos^>^ listaRegistroDatos);
		void actualizarSistemaRegistroDatos(int id, String^ fecha, String^ hora, String^ tipoDato, float valorRegistrado);
		void eliminarSistemaRegistroDatos(int id);
	};
}