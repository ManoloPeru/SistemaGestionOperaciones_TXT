#include "EstacionControlController.h"
#include "ExperimentoController.h"

using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase EstacionControlController
EstacionControlController::EstacionControlController() {
}

// Retorna la lista de EstacionControl encontrados
List<EstacionControl^>^ EstacionControlController::listarTodos() {
	List<EstacionControl^>^ listaEstacionesControl = gcnew List<EstacionControl^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("EstacionesControl.txt")) {
		File::WriteAllText("EstacionesControl.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("EstacionesControl.txt");
	String^ separadores = ";";	// Define los separadores de campos
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1];
		List<Dispositivo^>^ listaDispositivo = gcnew List<Dispositivo^>();
		// Aquí se asume que los dispositivos están separados por comas en el campo 2
		array<String^>^ dispositivosCampos = campos[2]->Split(',');
		for each (String ^ dispositivo in dispositivosCampos) {
			int idDispositivo = Convert::ToInt32(dispositivo);
			Dispositivo^ dispositivo = gcnew Dispositivo(idDispositivo, "Activo"); // Crea un nuevo dispositivo con el ID y en estado "Activo"
			listaDispositivo->Add(dispositivo); // Agrega el dispositivo a la lista de dispositivos
		}
		List<Experimento^>^ listaExperimento = gcnew List<Experimento^>();
		// Aquí se asume que los experimentos están separados por comas en el campo 3
		array<String^>^ experimentosCampos = campos[3]->Split(',');
		for each (String ^ experimento in experimentosCampos) {
			int idExperimento = Convert::ToInt32(experimento);
			//Traemos el controlador de Experimento
			ExperimentoController^ controladorExperimento = gcnew ExperimentoController();
			Experimento^ experimento = controladorExperimento->buscarExperimentoxId(idExperimento); // Crea un nuevo experimento con el ID
			if (experimento != nullptr) { // Verifica que el experimento no sea nulo
				listaExperimento->Add(experimento); // Agrega el experimento a la lista de experimentos de la estación de control
			}
		}
		EstacionControl^ estacionControl = gcnew EstacionControl(id, estado, listaDispositivo, listaExperimento);
		listaEstacionesControl->Add(estacionControl); // Agrega la estación de control a la lista de estaciones de control
	}
	return listaEstacionesControl; // Retorna la lista de estaciones de control
}

// Método para buscar una estación de control por su ID
EstacionControl^ EstacionControlController::buscarEstacionControlxId(int id) {
	List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
	// Recorre la lista de estaciones para encontrar la estación con el ID especificado
	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionControl^ estacion = listaEstaciones[i];
		if (estacion->getIdEstacion() == id) {
			return estacion; // Retorna la estación encontrada
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// Método para buscar estaciones de control por estado
List<EstacionControl^>^ EstacionControlController::buscarEstacionControlxEstado(String^ estado) {
	List<EstacionControl^>^ listaEstaciones = gcnew List<EstacionControl^>(); // Aqui creo la lista vacía
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
			listaEstaciones->Add(estacionControl); // Agrega la estación de control a la lista de estaciones de control
		}
	}
	return listaEstaciones; // Retorna la lista de estaciones de control con el estado especificado
}

// Método para agregar una nueva estación de control con los parámetros proporcionados  
void EstacionControlController::agregarEstacionControl(int id, String^ estado, List<Dispositivo^>^ listaDispositivo, List<Experimento^>^ listaExperimento) {  
   // Crea una nueva estación de control con los parámetros proporcionados  
   EstacionControl^ estacionControl = gcnew EstacionControl(id, estado, listaDispositivo, listaExperimento);  
   List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
   listaEstaciones->Add(estacionControl); // Agrega la nueva estación de control a la lista de estaciones de control
   // Escribe la nueva estación de control en el archivo
   escribirArchivo(listaEstaciones);
}

// Método para actualizar una estación de control existente
void EstacionControlController::actualizarEstacionControl(int id, String^ estado, List<Dispositivo^>^ listaDispositivo, List<Experimento^>^ listaExperimento) {
	List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionControl^ estacion = listaEstaciones[i];
		if (estacion->getIdEstacion() == id) {
			estacion->setEstado(estado); // Actualiza el estado de la estación
			estacion->setListaDispositivo(listaDispositivo); // Actualiza la lista de dispositivos
			estacion->setListaExperimento(listaExperimento); // Actualiza la lista de experimentos
			break; // Sale del bucle una vez que se actualiza la estación
		}
	}
	escribirArchivo(listaEstaciones); // Escribe los cambios en el archivo
}

// Método para escribir la lista de estaciones de control en el archivo
void EstacionControlController::escribirArchivo(List<EstacionControl^>^ listaEstacionesControl) {
	StreamWriter^ writer = gcnew StreamWriter("EstacionesControl.txt", false); // Abre el archivo para escribir
	for each (EstacionControl ^ estacion in listaEstacionesControl) {
		// Formando la lista (separados por comas) de dispositivos
		String^ dispositivosIds = "";
		for each (Dispositivo ^ dispositivo in estacion->getListaDispositivo()) {
			dispositivosIds += dispositivo->getIdDispositivo().ToString() + ",";
		}
		if (dispositivosIds->Length > 0) {
			dispositivosIds = dispositivosIds->Substring(0, dispositivosIds->Length - 1); // Elimina la última coma
		}
		// Formando la lista (separados por comas) de experimentos
		String^ experimentosIds = "";
		for each (Experimento ^ experimento in estacion->getListaExperimento()) {
			experimentosIds += experimento->getIdExperimento().ToString() + ",";
		}
		if (experimentosIds->Length > 0) {
			experimentosIds = experimentosIds->Substring(0, experimentosIds->Length - 1); // Elimina la última coma
		}
		// Escribe la línea en el archivo
		writer->WriteLine(String::Format("{0};{1};{2};{3}",
			estacion->getIdEstacion(),
			estacion->getEstado(),
			dispositivosIds,
			experimentosIds));
	}
	writer->Close(); // Cierra el escritor
}

// Método para eliminar una estación de control por su ID
void EstacionControlController::eliminarEstacionControl(int id) {
	List<EstacionControl^>^ listaEstaciones = listarTodos(); // Obtiene la lista de estaciones de control
	for (int i = 0; i < listaEstaciones->Count; i++) {
		EstacionControl^ estacion = listaEstaciones[i];
		if (estacion->getIdEstacion() == id) {
			listaEstaciones->RemoveAt(i); // Elimina la estación de control encontrada
			break; // Sale del bucle una vez que se elimina la estación
		}
	}
	escribirArchivo(listaEstaciones); // Escribe los cambios en el archivo
}