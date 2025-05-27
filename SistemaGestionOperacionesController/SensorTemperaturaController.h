#pragma once

namespace SistemaGestionOperacionesController {
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SistemaGestionOperacionesModel;
	
	public ref class SensorTemperaturaController {
	public:
		SensorTemperaturaController();
		List<SensorTemperatura^>^ listarTodos();
		SensorTemperatura^ buscarSensorxid(int id);
		List<SensorTemperatura^>^ buscarSensorxEstado(String^ estado);
		void agregarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad);
		void escribirArchivo(List<SensorTemperatura^>^ listaSensores);
		void actualizarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad);
		void eliminarSensor(int id);
	};
}