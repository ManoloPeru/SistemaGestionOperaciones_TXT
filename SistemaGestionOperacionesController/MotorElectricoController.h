#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class MotorElectricoController {
	public:
		MotorElectricoController();
		List<MotorElectrico^>^ listarTodos();
		MotorElectrico^ buscarMotorElectricoxId(int id);
		List<MotorElectrico^>^ buscarMotorElectricoxEstado(String^ estado);
		void agregarMotorElectrico(int id, String^ estado, float potencia, float velocidadRPM);
		void escribirArchivo(List<MotorElectrico^>^ listaMotores);
		void actualizarMotorElectrico(int id, String^ estado, float potencia, float velocidadRPM);
		void eliminarMotorElectrico(int id);
	};
}