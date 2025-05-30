#include "ExperimentoController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase ExperimentoController
ExperimentoController::ExperimentoController() {
}

// Retorna la lista de Experimento encontrados
List<Experimento^>^ ExperimentoController::listarTodos() {
	List<Experimento^>^ listaExperimentos = gcnew List<Experimento^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("Experimentos.txt")) {
		File::WriteAllText("Experimentos.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("Experimentos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ fechaInicio = campos[1];
		int duracion = Convert::ToInt32(campos[2]);
		String^ estado = campos[3];
		Experimento^ experimento = gcnew Experimento(id, fechaInicio, duracion, estado);
		listaExperimentos->Add(experimento); // Agrega el experimento a la lista de experimentos
	}
	return listaExperimentos; // Retorna la lista de experimentos
}

// Método para buscar un experimento por su ID
Experimento^ ExperimentoController::buscarExperimentoxId(int id) {
	List<Experimento^>^ listaExperimentos = listarTodos(); // Obtiene la lista de experimentos
	// Recorre la lista de experimentos para encontrar el experimento con el ID especificado
	for (int i = 0; i < listaExperimentos->Count; i++) {
		Experimento^ experimento = listaExperimentos[i];
		if (experimento->getIdExperimento() == id) {
			return experimento; // Retorna el experimento encontrado
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// Método para buscar experimentos por estado
List<Experimento^>^ ExperimentoController::buscarExperimentoxEstado(String^ estado) {
	List<Experimento^>^ listaExperimentos = gcnew List<Experimento^>(); // Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("Experimentos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estadoActual = campos[3];
		if (estadoActual->Equals(estado)) {
			String^ fechaInicio = campos[1];
			int duracion = Convert::ToInt32(campos[2]);
			Experimento^ experimento = gcnew Experimento(id, fechaInicio, duracion, estadoActual);
			listaExperimentos->Add(experimento); // Agrega el experimento a la lista de experimentos
		}
	}
	return listaExperimentos; // Retorna la lista de experimentos con el estado especificado
}

// Método para buscar experimentos por fecha de inicio
List<Experimento^>^ ExperimentoController::buscarExperimentoxFechaInicio(String^ fechaInicio) {
	List<Experimento^>^ listaExperimentos = gcnew List<Experimento^>(); // Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("Experimentos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ fechaInicioActual = campos[1];
		if (fechaInicioActual->Equals(fechaInicio)) {
			int duracion = Convert::ToInt32(campos[2]);
			String^ estado = campos[3];
			Experimento^ experimento = gcnew Experimento(id, fechaInicioActual, duracion, estado);
			listaExperimentos->Add(experimento); // Agrega el experimento a la lista de experimentos
		}
	}
	return listaExperimentos; // Retorna la lista de experimentos con la fecha de inicio especificada
}

// Método para agregar un nuevo experimento con los parámetros proporcionados
void ExperimentoController::agregarExperimento(int id, String^ fechaInicio, int duracion, String^ estado) {
	// Crea un nuevo experimento con los parámetros proporcionados
	Experimento^ experimentoNuevo = gcnew Experimento(id, fechaInicio, duracion, estado);
	// Obtiene la lista de experimentos existentes, agrega el nuevo experimento y escribe los cambios en el archivo
	List<Experimento^>^ listaExperimentos = listarTodos();
	listaExperimentos->Add(experimentoNuevo);
	escribirArchivo(listaExperimentos);
}

// Método para escribir la lista de experimentos en el archivo
void ExperimentoController::escribirArchivo(List<Experimento^>^ listaExperimentos) {
	StreamWriter^ writer = gcnew StreamWriter("Experimentos.txt", false); // Abre el archivo para escribir
	for each (Experimento ^ experimento in listaExperimentos) {
		String^ linea = String::Format("{0};{1};{2};{3}", experimento->getIdExperimento(), experimento->getFechaInicio(), experimento->getDuracion(), experimento->getEstado());
		writer->WriteLine(linea); // Escribe cada experimento en una línea
	}
	writer->Close(); // Cierra el archivo
}

// Método para actualizar un experimento existente con los nuevos parámetros
void ExperimentoController::actualizarExperimento(int id, String^ fechaInicio, int duracion, String^ estado) {
	List<Experimento^>^ listaExperimentos = listarTodos(); // Obtiene la lista de experimentos
	// Busca el experimento por ID y actualiza sus propiedades
	for (int i = 0; i < listaExperimentos->Count; i++) {
		Experimento^ experimento = listaExperimentos[i];
		if (experimento->getIdExperimento() == id) {
			experimento->setFechaInicio(fechaInicio);
			experimento->setDuracion(duracion);
			experimento->setEstado(estado);
			break; // Sale del bucle una vez que se actualiza el experimento
		}
	}
	escribirArchivo(listaExperimentos); // Escribe los cambios en el archivo
}

// Método para eliminar un experimento por su ID
void ExperimentoController::eliminarExperimento(int id) {
	List<Experimento^>^ listaExperimentos = listarTodos(); // Obtiene la lista de experimentos
	// Busca el experimento por ID y lo elimina de la lista
	for (int i = 0; i < listaExperimentos->Count; i++) {
		Experimento^ experimento = listaExperimentos[i];
		if (experimento->getIdExperimento() == id) {
			listaExperimentos->RemoveAt(i); // Elimina el experimento de la lista
			break; // Sale del bucle una vez que se elimina el experimento
		}
	}
	escribirArchivo(listaExperimentos); // Escribe los cambios en el archivo
}