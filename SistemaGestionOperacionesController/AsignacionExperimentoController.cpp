#include "AsignacionExperimentoController.h"
#include "ExperimentoController.h"

using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase AsignacionExperimentoController
AsignacionExperimentoController::AsignacionExperimentoController() {
}

// Retorna la lista de AsignacionExperimento encontrados
List<AsignacionExperimento^>^ AsignacionExperimentoController::listarTodos() {
	List<AsignacionExperimento^>^ listaAsignaciones = gcnew List<AsignacionExperimento^>(); // Aqui creo la lista vac�a
	// Verifica si el archivo existe, si no, lo crea vac�o
	if (!File::Exists("AsignacionesExperimentos.txt")) {
		File::WriteAllText("AsignacionesExperimentos.txt", "");
	}
	// Leo el archivo y lo separo por l�neas
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
		listaAsignaciones->Add(asignacion); // Agrega la asignaci�n a la lista de asignaciones
	}
	return listaAsignaciones; // Retorna la lista de asignaciones de experimentos
}

// M�todo para buscar una asignaci�n de experimento por su ID
AsignacionExperimento^ AsignacionExperimentoController::buscarAsignacionExperimentoxId(int id) {
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos(); // Obtiene la lista de asignaciones de experimentos
	// Recorre la lista de asignaciones para encontrar la asignaci�n con el ID especificado
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		AsignacionExperimento^ asignacion = listaAsignaciones[i];
		if (asignacion->getIdAsignacion() == id) {
			return asignacion; // Retorna la asignaci�n encontrada
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// M�todo para buscar asignaciones de experimento por fecha de asignaci�n
List<AsignacionExperimento^>^ AsignacionExperimentoController::buscarAsignacionExperimentoxFechaAsignacion(String^ fechaAsignacion) {
	List<AsignacionExperimento^>^ listaAsignaciones = gcnew List<AsignacionExperimento^>(); // Aqui creo la lista vac�a
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
			listaAsignaciones->Add(asignacion); // Agrega la asignaci�n a la lista de asignaciones
		}
	}
	return listaAsignaciones; // Retorna la lista de asignaciones con la fecha de asignaci�n especificada
}

// M�todo para agregar una nueva asignaci�n de experimento con los par�metros proporcionados
void AsignacionExperimentoController::agregarAsignacionExperimento(int id, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento) {
	// Crea una nueva asignaci�n de experimento con los par�metros proporcionados
	AsignacionExperimento^ asignacionNueva = gcnew AsignacionExperimento(id, fechaAsignacion, rol, dispositivo, experimento);
	// Obtiene la lista de asignaciones existentes, agrega la nueva asignaci�n y escribe los cambios en el archivo
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos();
	listaAsignaciones->Add(asignacionNueva);
	escribirArchivo(listaAsignaciones);
}

// M�todo para escribir la lista de asignaciones de experimentos en el archivo
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
	File::WriteAllLines("AsignacionesExperimentos.txt", lineasArchivo); // Escribe las l�neas en el archivo
}

// M�todo para actualizar una asignaci�n de experimento existente
void AsignacionExperimentoController::actualizarAsignacionExperimento(int id, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento) {
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos(); // Obtiene la lista de asignaciones de experimentos
	// Busca la asignaci�n por ID y actualiza sus propiedades
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		AsignacionExperimento^ asignacion = listaAsignaciones[i];
		if (asignacion->getIdAsignacion() == id) {
			asignacion->setFechaAsignacion(fechaAsignacion);
			asignacion->setRol(rol);
			asignacion->setDispositivo(dispositivo);
			asignacion->setExperimento(experimento);
			break; // Sale del bucle una vez que se actualiza la asignaci�n
		}
	}
	escribirArchivo(listaAsignaciones); // Escribe los cambios en el archivo
}

// M�todo para eliminar una asignaci�n de experimento por su ID
void AsignacionExperimentoController::eliminarAsignacionExperimento(int id) {
	List<AsignacionExperimento^>^ listaAsignaciones = listarTodos(); // Obtiene la lista de asignaciones de experimentos
	// Busca la asignaci�n por ID y la elimina de la lista
	for (int i = 0; i < listaAsignaciones->Count; i++) {
		if (listaAsignaciones[i]->getIdAsignacion() == id) {
			listaAsignaciones->RemoveAt(i); // Elimina la asignaci�n encontrada
			break; // Sale del bucle una vez que se elimina la asignaci�n
		}
	}
	escribirArchivo(listaAsignaciones); // Escribe los cambios en el archivo
}