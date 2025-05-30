#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class ExperimentoController {
	public:
		ExperimentoController();
		List<Experimento^>^ listarTodos();
		Experimento^ buscarExperimentoxId(int id);
		List<Experimento^>^ buscarExperimentoxEstado(String^ estado);
		List<Experimento^>^ buscarExperimentoxFechaInicio(String^ fechaInicio);
		void agregarExperimento(int id, String^ fechaInicio, int duracion, String^ estado);
		void escribirArchivo(List<Experimento^>^ listaExperimentos);
		void actualizarExperimento(int id, String^ fechaInicio, int duracion, String^ estado);
		void eliminarExperimento(int id);
	};
}