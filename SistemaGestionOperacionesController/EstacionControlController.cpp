#include "EstacionControlController.h"
#include "ExperimentoController.h"

using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase EstacionControlController
EstacionControlController::EstacionControlController() {
}

// Retorna la lista de EstacionControl encontrados
List<EstacionControl^>^ EstacionControlController::listarTodos() {
	List<EstacionControl^>^ listaEstacionesControl = gcnew List<EstacionControl^>(); // Aqui creo la lista vac�a
	// Verifica si el archivo existe, si no, lo crea vac�o
	if (!File::Exists("EstacionesControl.txt")) {
		File::WriteAllText("EstacionesControl.txt", "");
	}
	// Leo el archivo y lo separo por l�neas
	array<String^>^ lineas = File::ReadAllLines("EstacionesControl.txt");
	String^ separadores = ";";	// Define los separadores de campos
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1];
		List<Dispositivo^>^ listaDispositivo = gcnew List<Dispositivo^>();
		// Aqu� se asume que los dispositivos est�n separados por comas en el campo 2
		array<String^>^ dispositivosCampos = campos[2]->Split(',');
		for each (String ^ dispositivo in dispositivosCampos) {
			int idDispositivo = Convert::ToInt32(dispositivo);
			Dispositivo^ dispositivo = gcnew Dispositivo(idDispositivo, "Activo"); // Crea un nuevo dispositivo con el ID y en estado "Activo"
			listaDispositivo->Add(dispositivo); // Agrega el dispositivo a la lista de dispositivos
		}
		List<Experimento^>^ listaExperimento = gcnew List<Experimento^>();
		// Aqu� se asume que los experimentos est�n separados por comas en el campo 3
		array<String^>^ experimentosCampos = campos[3]->Split(',');
		for each (String ^ experimento in experimentosCampos) {
			int idExperimento = Convert::ToInt32(experimento);
			//Traemos el controlador de Experimento
			ExperimentoController^ controladorExperimento = gcnew ExperimentoController();
			Experimento^ experimento = controladorExperimento->buscarExperimentoxId(idExperimento); // Crea un nuevo experimento con el ID
			if (experimento != nullptr) { // Verifica que el experimento no sea nulo
				listaExperimento->Add(experimento); // Agrega el experimento a la lista de experimentos de la estaci�n de control
			}
		}
		EstacionControl^ estacionControl = gcnew EstacionControl(id, estado, listaDispositivo, listaExperimento);
		listaEstacionesControl->Add(estacionControl); // Agrega la estaci�n de control a la lista de estaciones de control
	}
	return listaEstacionesControl; // Retorna la lista de estaciones de control
}

// M�todo para buscar una estaci�n de control por su ID
EstacionControl^ EstacionControlController::buscarEstacionControlxId(int id) {
	List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
	// Recorre la lista de estaciones para encontrar la estaci�n con el ID especificado
	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionControl^ estacion = listaEstaciones[i];
		if (estacion->getIdEstacion() == id) {
			return estacion; // Retorna la estaci�n encontrada
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// M�todo para buscar estaciones de control por estado
List<EstacionControl^>^ EstacionControlController::buscarEstacionControlxEstado(String^ estado) {
	List<EstacionControl^>^ listaEstaciones = gcnew List<EstacionControl^>(); // Aqui creo la lista vac�a
	array<String^>^ lineas = File::ReadAllLines("EstacionesControl.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estadoActual = campos[1];
		if (estadoActual->Equals(estado)) {
			List<Dispositivo^>^ listaDispositivo = gcnew List<Dispositivo^>();
			array<String^>^ dispositivosCampos = campos[2]->Split(',');
			for each (String ^ dispositivo in dispositivosCampos) {
				int idDispositivo = Convert::ToInt32(dispositivo);
				Dispositivo^ dispositivo = gcnew Dispositivo(idDispositivo, "Activo");
				listaDispositivo->Add(dispositivo);
			}
			List<Experimento^>^ listaExperimento = gcnew List<Experimento^>();
			array<String^>^ experimentosCampos = campos[3]->Split(',');
			for each (String ^ experimento in experimentosCampos) {
				int idExperimento = Convert::ToInt32(experimento);
				ExperimentoController^ controladorExperimento = gcnew ExperimentoController();
				Experimento^ experimento = controladorExperimento->buscarExperimentoxId(idExperimento);
				if (experimento != nullptr) {
					listaExperimento->Add(experimento);
				}
			}
			EstacionControl^ estacionControl = gcnew EstacionControl(id, estadoActual, listaDispositivo, listaExperimento);
			listaEstaciones->Add(estacionControl); // Agrega la estaci�n de control a la lista de estaciones de control
		}
	}
	return listaEstaciones; // Retorna la lista de estaciones de control con el estado especificado
}

// M�todo para agregar una nueva estaci�n de control con los par�metros proporcionados  
void EstacionControlController::agregarEstacionControl(int id, String^ estado, List<Dispositivo^>^ listaDispositivo, List<Experimento^>^ listaExperimento) {  
   // Crea una nueva estaci�n de control con los par�metros proporcionados  
   EstacionControl^ estacionControl = gcnew EstacionControl(id, estado, listaDispositivo, listaExperimento);  
   List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
   listaEstaciones->Add(estacionControl); // Agrega la nueva estaci�n de control a la lista de estaciones de control
   // Escribe la nueva estaci�n de control en el archivo
   escribirArchivo(listaEstaciones);
}

// M�todo para actualizar una estaci�n de control existente
void EstacionControlController::actualizarEstacionControl(int id, String^ estado, List<Dispositivo^>^ listaDispositivo, List<Experimento^>^ listaExperimento) {
	List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionControl^ estacion = listaEstaciones[i];
		if (estacion->getIdEstacion() == id) {
			estacion->setEstado(estado); // Actualiza el estado de la estaci�n
			estacion->setListaDispositivo(listaDispositivo); // Actualiza la lista de dispositivos
			estacion->setListaExperimento(listaExperimento); // Actualiza la lista de experimentos
			break; // Sale del bucle una vez que se actualiza la estaci�n
		}
	}
	escribirArchivo(listaEstaciones); // Escribe los cambios en el archivo
}

// M�todo para escribir la lista de estaciones de control en el archivo
void EstacionControlController::escribirArchivo(List<EstacionControl^>^ listaEstacionesControl) {
	StreamWriter^ writer = gcnew StreamWriter("EstacionesControl.txt", false); // Abre el archivo para escribir
	for each (EstacionControl ^ estacion in listaEstacionesControl) {
		// Formando la lista (separados por comas) de dispositivos
		String^ dispositivosIds = "";
		for each (Dispositivo ^ dispositivo in estacion->getListaDispositivo()) {
			dispositivosIds += dispositivo->getIdDispositivo().ToString() + ",";
		}
		if (dispositivosIds->Length > 0) {
			dispositivosIds = dispositivosIds->Substring(0, dispositivosIds->Length - 1); // Elimina la �ltima coma
		}
		// Formando la lista (separados por comas) de experimentos
		String^ experimentosIds = "";
		for each (Experimento ^ experimento in estacion->getListaExperimento()) {
			experimentosIds += experimento->getIdExperimento().ToString() + ",";
		}
		if (experimentosIds->Length > 0) {
			experimentosIds = experimentosIds->Substring(0, experimentosIds->Length - 1); // Elimina la �ltima coma
		}
		// Escribe la l�nea en el archivo
		writer->WriteLine(String::Format("{0};{1};{2};{3}",
			estacion->getIdEstacion(),
			estacion->getEstado(),
			dispositivosIds,
			experimentosIds));
	}
	writer->Close(); // Cierra el escritor
}

// M�todo para eliminar una estaci�n de control por su ID
void EstacionControlController::eliminarEstacionControl(int id) {
	List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionControl^ estacion = listaEstaciones[i];
		if (estacion->getIdEstacion() == id) {
			listaEstaciones->RemoveAt(i); // Elimina la estaci�n de control encontrada
			break; // Sale del bucle una vez que se elimina la estaci�n
		}
	}
	escribirArchivo(listaEstaciones); // Escribe los cambios en el archivo
}