#include "ValvulaNeumaticaController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase ValvulaNeumaticaController
ValvulaNeumaticaController::ValvulaNeumaticaController() {
}

// Retorna la lista de ValvulaNeumatica encontrados
List<ValvulaNeumatica^>^ ValvulaNeumaticaController::listarTodos() {
	List<ValvulaNeumatica^>^ listaValvulaNeumaticas = gcnew List<ValvulaNeumatica^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("ValvulasNeumaticas.txt")) {
		File::WriteAllText("ValvulasNeumaticas.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("ValvulasNeumaticas.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1];
		float potencia = Convert::ToSingle(campos[2]);
		float presion = Convert::ToSingle(campos[3]);
		ValvulaNeumatica^ valvula = gcnew ValvulaNeumatica(presion);
		valvula->setIdDispositivo(id); // Establece el ID de la válvula neumática
		valvula->setEstado(estado); // Establece el estado de la válvula neumática
		valvula->setPotencia(potencia); // Establece la potencia de la válvula neumática
		listaValvulaNeumaticas->Add(valvula); // Agrega la válvula a la lista de válvulas neumáticas
	}
	return listaValvulaNeumaticas; // Retorna la lista de válvulas neumáticas
}

// Método para buscar una válvula neumática por su ID
ValvulaNeumatica^ ValvulaNeumaticaController::buscarValvulaNeumaticaxId(int id) {
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos(); // Obtiene la lista de válvulas neumáticas
	// Recorre la lista de válvulas para encontrar la válvula con el ID especificado
	for (int i = 0; i < listaValvulas->Count; i++) {
		ValvulaNeumatica^ valvula = listaValvulas[i];
		if (valvula->getIdDispositivo() == id) {
			return valvula; // Retorna la válvula encontrada
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// Método para buscar válvulas neumáticas por estado
List<ValvulaNeumatica^>^ ValvulaNeumaticaController::buscarValvulaNeumaticaxEstado(String^ estado) {
	List<ValvulaNeumatica^>^ listaValvulas = gcnew List<ValvulaNeumatica^>(); // Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("ValvulasNeumaticas.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estadoActual = campos[1];
		float potencia = Convert::ToSingle(campos[2]);
		float presion = Convert::ToSingle(campos[3]);
		if (estadoActual->Equals(estado)) {
			ValvulaNeumatica^ valvula = gcnew ValvulaNeumatica(presion);
			valvula->setIdDispositivo(id); // Establece el ID de la válvula neumática
			valvula->setEstado(estadoActual); // Establece el estado de la válvula neumática
			valvula->setPotencia(potencia); // Establece la potencia de la válvula neumática
			listaValvulas->Add(valvula); // Agrega la válvula a la lista de válvulas neumáticas
		}
	}
	return listaValvulas; // Retorna la lista de válvulas con el estado especificado
}

// Método para agregar una nueva válvula neumática con los parámetros proporcionados
void ValvulaNeumaticaController::agregarValvulaNeumatica(int id, String^ estado, float potencia, float presion) {
	// Crea una nueva válvula neumática con los parámetros proporcionados
	ValvulaNeumatica^ valvulaNueva = gcnew ValvulaNeumatica(presion);
	valvulaNueva->setIdDispositivo(id); // Establece el ID de la válvula
	valvulaNueva->setEstado(estado); // Establece el estado de la válvula
	valvulaNueva->setPotencia(potencia); // Establece la potencia de la válvula
	// Obtiene la lista de válvulas existentes, agrega la nueva válvula y escribe los cambios en el archivo
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos();
	listaValvulas->Add(valvulaNueva);
	escribirArchivo(listaValvulas);
}

// Método para escribir la lista de válvulas neumáticas en el archivo
void ValvulaNeumaticaController::escribirArchivo(List<ValvulaNeumatica^>^ listaValvulaNeumaticas) {
	StreamWriter^ escritor = gcnew StreamWriter("ValvulasNeumaticas.txt");
	for each (ValvulaNeumatica ^ valvula in listaValvulaNeumaticas) {
		String^ linea = String::Format("{0};{1};{2};{3}", valvula->getIdDispositivo(), valvula->getEstado(), valvula->getPotencia(), valvula->getPresion());
		escritor->WriteLine(linea); // Escribe cada válvula en una nueva línea
	}
	escritor->Close(); // Cierra el escritor
}

// Método para actualizar una válvula neumática existente
void ValvulaNeumaticaController::actualizarValvulaNeumatica(int id, String^ estado, float potencia, float presion) {
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos(); // Obtiene la lista de válvulas neumáticas
	for (int i = 0; i < listaValvulas->Count; i++) {
		ValvulaNeumatica^ valvula = listaValvulas[i];
		if (valvula->getIdDispositivo() == id) {
			valvula->setEstado(estado); // Actualiza el estado de la válvula
			valvula->setPotencia(potencia); // Actualiza la potencia de la válvula
			valvula->setPresion(presion); // Actualiza la presión de la válvula
			escribirArchivo(listaValvulas); // Escribe los cambios en el archivo
			return; // Sale del método después de actualizar
		}
	}
}

// Método para eliminar una válvula neumática por su ID
void ValvulaNeumaticaController::eliminarValvulaNeumatica(int id) {
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos(); // Obtiene la lista de válvulas neumáticas
	for (int i = 0; i < listaValvulas->Count; i++) {
		ValvulaNeumatica^ valvula = listaValvulas[i];
		if (valvula->getIdDispositivo() == id) {
			listaValvulas->RemoveAt(i); // Elimina la válvula de la lista
			escribirArchivo(listaValvulas); // Escribe los cambios en el archivo
			return; // Sale del método después de eliminar
		}
	}
}