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
		MotorElectrico^ buscarMotorexid(int id);
		List<MotorElectrico^>^ buscarMotorexEstado(String^ estado);
		void agregarMotor(int id, String^ estado, float potencia, float velocidadRPM);
		void escribirArchivo(List<MotorElectrico^>^ listaMotores);
		void actualizarMotor(int id, String^ estado, float potencia, float velocidadRPM);
		void eliminarMotor(int id);
	};
}