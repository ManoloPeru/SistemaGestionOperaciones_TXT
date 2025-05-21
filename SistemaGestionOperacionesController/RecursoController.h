#pragma once

namespace SistemaGestionOperacionesController {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SistemaGestionOperacionesModel;

	public ref class RecursoController {

		public:
			RecursoController();
			List<Recurso^>^ listarTodos();
			Recurso^ buscarRecursoxidRecurso(int idRecurso);
			List<Recurso^>^ buscarRecursoxNombre(String^ nombre);
			void agregarRecurso(int idRecurso, String^ nombre, int Cantidad, String^ estado);
			void escribirArchivo(List<Recurso^>^ listaRecursos);
			void actualizarRecurso(int idRecurso, String^ nombre, int Cantidad, String^ estado);
			void eliminarRecurso(int idRecurso);

	};
}


