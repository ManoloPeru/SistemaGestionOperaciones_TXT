#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class EstacionControlController {
	public:
		EstacionControlController();
		List<EstacionControl^>^ listarTodos();
		EstacionControl^ buscarEstacionControlxId(int id);
		List<EstacionControl^>^ buscarEstacionControlxEstado(String^ estado);
		void agregarEstacionControl(int id, String^ estado, List<Dispositivo^>^ listaDispositivo, List<Experimento^>^ listaExperimento);
		void escribirArchivo(List<EstacionControl^>^ listaEstacionesControl);
		void actualizarEstacionControl(int id, String^ estado, List<Dispositivo^>^ listaDispositivo, List<Experimento^>^ listaExperimento);
		void eliminarEstacionControl(int id);
	};
}