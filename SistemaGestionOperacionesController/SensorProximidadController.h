#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class SensorProximidadController {
	public:
		SensorProximidadController();
		List<SensorProximidad^>^ listarTodos();
		SensorProximidad^ buscarSensorxid(int id);
		List<SensorProximidad^>^ buscarSensorxEstado(String^ estado);
		void agregarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad);
		void escribirArchivo(List<SensorProximidad^>^ listaSensores);
		void actualizarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad);
		void eliminarSensor(int id);
	};
}