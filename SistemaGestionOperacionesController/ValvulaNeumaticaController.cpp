#include "ValvulaNeumaticaController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase ValvulaNeumaticaController
ValvulaNeumaticaController::ValvulaNeumaticaController() {
}

// Retorna la lista de ValvulaNeumatica encontrados
List<ValvulaNeumatica^>^ ValvulaNeumaticaController::listarTodos() {
	List<ValvulaNeumatica^>^ listaValvulaNeumaticas = gcnew List<ValvulaNeumatica^>(); // Aqui creo la lista vac�a
	// Verifica si el archivo existe, si no, lo crea vac�o
	if (!File::Exists("ValvulasNeumaticas.txt")) {
		File::WriteAllText("ValvulasNeumaticas.txt", "");
	}
	// Leo el archivo y lo separo por l�neas
	array<String^>^ lineas = File::ReadAllLines("ValvulasNeumaticas.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1];
		float potencia = Convert::ToSingle(campos[2]);
		float presion = Convert::ToSingle(campos[3]);
		ValvulaNeumatica^ valvula = gcnew ValvulaNeumatica(presion);
		valvula->setIdDispositivo(id); // Establece el ID de la v�lvula neum�tica
		valvula->setEstado(estado); // Establece el estado de la v�lvula neum�tica
		valvula->setPotencia(potencia); // Establece la potencia de la v�lvula neum�tica
		listaValvulaNeumaticas->Add(valvula); // Agrega la v�lvula a la lista de v�lvulas neum�ticas
	}
	return listaValvulaNeumaticas; // Retorna la lista de v�lvulas neum�ticas
}

// M�todo para buscar una v�lvula neum�tica por su ID
ValvulaNeumatica^ ValvulaNeumaticaController::buscarValvulaNeumaticaxId(int id) {
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos(); // Obtiene la lista de v�lvulas neum�ticas
	// Recorre la lista de v�lvulas para encontrar la v�lvula con el ID especificado
	for (int i = 0; i < listaValvulas->Count; i++) {
		ValvulaNeumatica^ valvula = listaValvulas[i];
		if (valvula->getIdDispositivo() == id) {
			return valvula; // Retorna la v�lvula encontrada
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// M�todo para buscar v�lvulas neum�ticas por estado
List<ValvulaNeumatica^>^ ValvulaNeumaticaController::buscarValvulaNeumaticaxEstado(String^ estado) {
	List<ValvulaNeumatica^>^ listaValvulas = gcnew List<ValvulaNeumatica^>(); // Aqui creo la lista vac�a
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
			valvula->setIdDispositivo(id); // Establece el ID de la v�lvula neum�tica
			valvula->setEstado(estadoActual); // Establece el estado de la v�lvula neum�tica
			valvula->setPotencia(potencia); // Establece la potencia de la v�lvula neum�tica
			listaValvulas->Add(valvula); // Agrega la v�lvula a la lista de v�lvulas neum�ticas
		}
	}
	return listaValvulas; // Retorna la lista de v�lvulas con el estado especificado
}

// M�todo para agregar una nueva v�lvula neum�tica con los par�metros proporcionados
void ValvulaNeumaticaController::agregarValvulaNeumatica(int id, String^ estado, float potencia, float presion) {
	// Crea una nueva v�lvula neum�tica con los par�metros proporcionados
	ValvulaNeumatica^ valvulaNueva = gcnew ValvulaNeumatica(presion);
	valvulaNueva->setIdDispositivo(id); // Establece el ID de la v�lvula
	valvulaNueva->setEstado(estado); // Establece el estado de la v�lvula
	valvulaNueva->setPotencia(potencia); // Establece la potencia de la v�lvula
	// Obtiene la lista de v�lvulas existentes, agrega la nueva v�lvula y escribe los cambios en el archivo
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos();
	listaValvulas->Add(valvulaNueva);
	escribirArchivo(listaValvulas);
}

// M�todo para escribir la lista de v�lvulas neum�ticas en el archivo
void ValvulaNeumaticaController::escribirArchivo(List<ValvulaNeumatica^>^ listaValvulaNeumaticas) {
	StreamWriter^ escritor = gcnew StreamWriter("ValvulasNeumaticas.txt");
	for each (ValvulaNeumatica ^ valvula in listaValvulaNeumaticas) {
		String^ linea = String::Format("{0};{1};{2};{3}", valvula->getIdDispositivo(), valvula->getEstado(), valvula->getPotencia(), valvula->getPresion());
		escritor->WriteLine(linea); // Escribe cada v�lvula en una nueva l�nea
	}
	escritor->Close(); // Cierra el escritor
}

// M�todo para actualizar una v�lvula neum�tica existente
void ValvulaNeumaticaController::actualizarValvulaNeumatica(int id, String^ estado, float potencia, float presion) {
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos(); // Obtiene la lista de v�lvulas neum�ticas
	for (int i = 0; i < listaValvulas->Count; i++) {
		ValvulaNeumatica^ valvula = listaValvulas[i];
		if (valvula->getIdDispositivo() == id) {
			valvula->setEstado(estado); // Actualiza el estado de la v�lvula
			valvula->setPotencia(potencia); // Actualiza la potencia de la v�lvula
			valvula->setPresion(presion); // Actualiza la presi�n de la v�lvula
			escribirArchivo(listaValvulas); // Escribe los cambios en el archivo
			return; // Sale del m�todo despu�s de actualizar
		}
	}
}

// M�todo para eliminar una v�lvula neum�tica por su ID
void ValvulaNeumaticaController::eliminarValvulaNeumatica(int id) {
	List<ValvulaNeumatica^>^ listaValvulas = listarTodos(); // Obtiene la lista de v�lvulas neum�ticas
	for (int i = 0; i < listaValvulas->Count; i++) {
		ValvulaNeumatica^ valvula = listaValvulas[i];
		if (valvula->getIdDispositivo() == id) {
			listaValvulas->RemoveAt(i); // Elimina la v�lvula de la lista
			escribirArchivo(listaValvulas); // Escribe los cambios en el archivo
			return; // Sale del m�todo despu�s de eliminar
		}
	}
}