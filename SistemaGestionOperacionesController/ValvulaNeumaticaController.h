#pragma once
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace SistemaGestionOperacionesModel;
using namespace System;

namespace SistemaGestionOperacionesController {
	public ref class ValvulaNeumaticaController {
	public:
		ValvulaNeumaticaController();
		List<ValvulaNeumatica^>^ listarTodos();
		ValvulaNeumatica^ buscarValvulaNeumaticaxId(int id);
		List<ValvulaNeumatica^>^ buscarValvulaNeumaticaxEstado(String^ estado);
		void agregarValvulaNeumatica(int id, String^ estado, float potencia, float presion);
		void escribirArchivo(List<ValvulaNeumatica^>^ listaValvulaNeumaticas);
		void actualizarValvulaNeumatica(int id, String^ estado, float potencia, float presion);
		void eliminarValvulaNeumatica(int id);
	};
}