#pragma once

namespace SistemaGestionOperacionesController {
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SistemaGestionOperacionesModel;
	public ref class RobotManipuladorController {
	public:
		RobotManipuladorController();
		List<RobotManipulador^>^ listarTodos();
		RobotManipulador^ buscarRobotxid(int id);
		List<RobotManipulador^>^ buscarRobotxUbicacion(float ubicacionX, float ubicacionY, float ubicacionZ);
		void agregarRobot(int id, String^ estado, float ubicacionX, float ubicacionY, float ubicacionZ, float capacidadCarga, float velocidad);
		void escribirArchivo(List<RobotManipulador^>^ listaRobots);
		void actualizarRobot(int id, String^ estado, float ubicacionX, float ubicacionY, float ubicacionZ, float capacidadCarga, float velocidad);
		void eliminarRobot(int id);
	};
}