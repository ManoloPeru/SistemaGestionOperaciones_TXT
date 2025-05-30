#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class AsignacionExperimentoController {
	public:
		AsignacionExperimentoController();
		List<AsignacionExperimento^>^ listarTodos();
		AsignacionExperimento^ buscarAsignacionExperimentoxId(int id);
		List<AsignacionExperimento^>^ buscarAsignacionExperimentoxFechaAsignacion(String^ fechaAsignacion);
		void agregarAsignacionExperimento(int id, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento);
		void escribirArchivo(List<AsignacionExperimento^>^ listaAsignaciones);
		void actualizarAsignacionExperimento(int id, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento);
		void eliminarAsignacionExperimento(int id);
	};
}