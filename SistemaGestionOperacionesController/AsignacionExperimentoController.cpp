#include "AsignacionExperimentoController.h"
#include "ExperimentoController.h"

using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase AsignacionExperimentoController
AsignacionExperimentoController::AsignacionExperimentoController() {
}

// Retorna la lista de AsignacionExperimento encontrados
List<AsignacionExperimento^>^ AsignacionExperimentoController::listarTodos() {
	List<AsignacionExperimento^>^ listaAsignaciones = gcnew List<AsignacionExperimento^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("AsignacionesExperimentos.txt")) {
		File::WriteAllText("AsignacionesExperimentos.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("AsignacionesExperimentos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ fechaAsignacion = campos[1];
		String^ rol = campos[2];
		int idDispositivo = Convert::ToInt32(campos[3]);
		int idExperimento = Convert::ToInt32(campos[4]);
		// Accedemos a la clase Dispsitivo y creamos su instancia
		Dispositivo^ dispositivo = gcnew Dispositivo(idDispositivo, "Activo"); // Crea un nuevo dispositivo con el ID y en estado "Activo"
		// Accedemos al controlador Experimento para crear la instancia
		ExperimentoController^ controladorExperimento = gcnew ExperimentoController(); 
		Experimento^ experimento = controladorExperimento->buscarExperimentoxId(idExperimento); // Crea un nuevo experimento con el ID
		AsignacionExperimento^ asignacion = gcnew AsignacionExperimento(id, fechaAsignacion, rol, dispositivo, experimento);
		listaAsignaciones->Add(asignacion); // Agrega la asignación a la lista de asignaciones
	}
	return listaAsignaciones; // Retorna la lista de asignaciones de experimentos
}

// Método para buscar una asignación de experimento por su ID
AsignacionExperimento^ AsignacionExperimentoController::buscarAsignacionExperimentoxId(int id) {
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos(); // Obtiene la lista de asignaciones de experimentos
	// Recorre la lista de asignaciones para encontrar la asignación con el ID especificado
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		AsignacionExperimento^ asignacion = listaAsignaciones[i];
		if (asignacion->getIdAsignacion() == id) {
			return asignacion; // Retorna la asignación encontrada
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// Método para buscar asignaciones de experimento por fecha de asignación
List<AsignacionExperimento^>^ AsignacionExperimentoController::buscarAsignacionExperimentoxFechaAsignacion(String^ fechaAsignacion) {
	List<AsignacionExperimento^>^ listaAsignaciones = gcnew List<AsignacionExperimento^>(); // Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("AsignacionesExperimentos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ fechaActual = campos[1];
		if (fechaActual->Equals(fechaAsignacion)) {
			String^ rol = campos[2];
			int idDispositivo = Convert::ToInt32(campos[3]);
			int idExperimento = Convert::ToInt32(campos[4]);
			Dispositivo^ dispositivo = gcnew Dispositivo(idDispositivo, "Activo"); // Crea un nuevo dispositivo con el ID y en estado "Activo"
			ExperimentoController^ controladorExperimento = gcnew ExperimentoController();
			Experimento^ experimento = controladorExperimento->buscarExperimentoxId(idExperimento); // Crea un nuevo experimento con el ID
			AsignacionExperimento^ asignacion = gcnew AsignacionExperimento(id, fechaActual, rol, dispositivo, experimento);
			listaAsignaciones->Add(asignacion); // Agrega la asignación a la lista de asignaciones
		}
	}
	return listaAsignaciones; // Retorna la lista de asignaciones con la fecha de asignación especificada
}

// Método para agregar una nueva asignación de experimento con los parámetros proporcionados
void AsignacionExperimentoController::agregarAsignacionExperimento(int id, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento) {
	// Crea una nueva asignación de experimento con los parámetros proporcionados
	AsignacionExperimento^ asignacionNueva = gcnew AsignacionExperimento(id, fechaAsignacion, rol, dispositivo, experimento);
	// Obtiene la lista de asignaciones existentes, agrega la nueva asignación y escribe los cambios en el archivo
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos();
	listaAsignaciones->Add(asignacionNueva);
	escribirArchivo(listaAsignaciones);
}

// Método para escribir la lista de asignaciones de experimentos en el archivo
void AsignacionExperimentoController::escribirArchivo(List<AsignacionExperimento^>^ listaAsignaciones) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaAsignaciones->Count);
	// Recorre la lista de asignaciones y las guarda en el array
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		AsignacionExperimento^ asignacion = listaAsignaciones[i];
		lineasArchivo[i] = String::Format("{0};{1};{2};{3};{4}",
			asignacion->getIdAsignacion(),
			asignacion->getFechaAsignacion(),
			asignacion->getRol(),
			asignacion->getDispositivo()->getIdDispositivo(),
			asignacion->getExperimento()->getIdExperimento());
	}
	File::WriteAllLines("AsignacionesExperimentos.txt", lineasArchivo); // Escribe las líneas en el archivo
}

// Método para actualizar una asignación de experimento existente
void AsignacionExperimentoController::actualizarAsignacionExperimento(int id, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento) {
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos(); // Obtiene la lista de asignaciones de experimentos
	// Busca la asignación por ID y actualiza sus propiedades
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		AsignacionExperimento^ asignacion = listaAsignaciones[i];
		if (asignacion->getIdAsignacion() == id) {
			asignacion->setFechaAsignacion(fechaAsignacion);
			asignacion->setRol(rol);
			asignacion->setDispositivo(dispositivo);
			asignacion->setExperimento(experimento);
			break; // Sale del bucle una vez que se actualiza la asignación
		}
	}
	escribirArchivo(listaAsignaciones); // Escribe los cambios en el archivo
}

// Método para eliminar una asignación de experimento por su ID
void AsignacionExperimentoController::eliminarAsignacionExperimento(int id) {
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos(); // Obtiene la lista de asignaciones de experimentos
	// Busca la asignación por ID y la elimina de la lista
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		if (listaAsignaciones[i]->getIdAsignacion() == id) {
			listaAsignaciones->RemoveAt(i); // Elimina la asignación encontrada
			break; // Sale del bucle una vez que se elimina la asignación
		}
	}
	escribirArchivo(listaAsignaciones); // Escribe los cambios en el archivo
}