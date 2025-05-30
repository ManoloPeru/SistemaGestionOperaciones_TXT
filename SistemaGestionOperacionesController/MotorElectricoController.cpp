#include "MotorElectricoController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase MotorElectricoController
MotorElectricoController::MotorElectricoController() {
}

// Retorna la lista de recursos encontrados
List<MotorElectrico^>^ MotorElectricoController::listarTodos() {
	List<MotorElectrico^>^ listaMotores = gcnew List<MotorElectrico^>(); // Aqui creo la lista vac�a
	// Verifica si el archivo existe, si no, lo crea vac�o
	if (!File::Exists("MotoresElectricos.txt")) {
		File::WriteAllText("MotoresElectricos.txt", "");
	}
	// Leo el archivo y lo separo por l�neas
	array<String^>^ lineas = File::ReadAllLines("MotoresElectricos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1];
		float potencia = Convert::ToSingle(campos[2]);
		float velocidadRPM = Convert::ToSingle(campos[3]);
		MotorElectrico^ motor = gcnew MotorElectrico(velocidadRPM);
		motor->setIdDispositivo(id); // Establece el ID del motor el�ctrico
		motor->setEstado(estado); // Establece el estado del motor el�ctrico
		motor->setPotencia(potencia); // Establece la potencia del motor
		listaMotores->Add(motor); // Agrega el motor a la lista de motores el�ctricos
	}
	return listaMotores; // Retorna la lista de motores el�ctricos
}

// M�todo para agregar un nuevo motor el�ctrico con los par�metros proporcionados
MotorElectrico^ MotorElectricoController::buscarMotorElectricoxId(int id) {
	List<MotorElectrico^>^ listaMotores = listarTodos(); // Obtiene la lista de motores el�ctricos
	// Recorre la lista de motores para encontrar el motor con el ID especificado
	for (int i = 0; i < listaMotores->Count; i++) {
		MotorElectrico^ motor = listaMotores[i];
		if (motor->getIdDispositivo() == id) {
			return motor; // Retorna el motor encontrado
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// M�todo para buscar motores el�ctricos por estado
List<MotorElectrico^>^ MotorElectricoController::buscarMotorElectricoxEstado(String^ estado) {
	List<MotorElectrico^>^ listaMotores = gcnew List<MotorElectrico^>(); // Aqui creo la lista vac�a
	array<String^>^ lineas = File::ReadAllLines("MotoresElectricos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estadoActual = campos[1];
		float potencia = Convert::ToSingle(campos[2]);
		float velocidadRPM = Convert::ToSingle(campos[3]);
		if (estadoActual->Equals(estado)) {
			MotorElectrico^ motor = gcnew MotorElectrico(velocidadRPM);
			motor->setIdDispositivo(id);
			motor->setEstado(estadoActual);
			motor->setPotencia(potencia);
			listaMotores->Add(motor);
		}
	}
	return listaMotores; // Retorna la lista de motores con el estado especificado
}

// M�todo para agregar un nuevo motor el�ctrico con los par�metros proporcionados
void MotorElectricoController::agregarMotorElectrico(int id, String^ estado, float potencia, float velocidadRPM) {
	// Crea un nuevo motor el�ctrico con los par�metros proporcionados
	MotorElectrico^ motorNuevo = gcnew MotorElectrico(velocidadRPM);
	motorNuevo->setIdDispositivo(id); // Establece el ID del motor
	motorNuevo->setEstado(estado); // Establece el estado del motor
	motorNuevo->setPotencia(potencia); // Establece la potencia del motor
	// Obtiene la lista de motores existentes, agrega el nuevo motor y escribe los cambios en el archivo
	List<MotorElectrico^>^ listaMotores = listarTodos();
	listaMotores->Add(motorNuevo);
	escribirArchivo(listaMotores);
}

// M�todo para escribir la lista de motores el�ctricos en el archivo
void MotorElectricoController::escribirArchivo(List<MotorElectrico^>^ listaMotores) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaMotores->Count);
	// Recorre la lista de motores y los guarda en el array
	for (int i = 0; i < listaMotores->Count; i++) {
		MotorElectrico^ motor = listaMotores[i];
		lineasArchivo[i] = String::Format("{0};{1};{2};{3};{4}",
			motor->getIdDispositivo(),
			motor->getEstado(),
			motor->getPotencia(),
			motor->getVelocidadRPM());
	}
	// Escribe el array en el archivo
	File::WriteAllLines("MotoresElectricos.txt", lineasArchivo);
}

// M�todo para actualizar un motor el�ctrico existente con los nuevos par�metros
void MotorElectricoController::actualizarMotorElectrico(int id, String^ estado, float potencia, float velocidadRPM) {
	List<MotorElectrico^>^ listaMotores = listarTodos(); // Obtiene la lista de motores el�ctricos
	// Busca el motor a actualizar
	for (int i = 0; i < listaMotores->Count; i++) {
		MotorElectrico^ motor = listaMotores[i];
		if (motor->getIdDispositivo() == id) {
			motor->setEstado(estado); // Actualiza el estado del motor
			motor->setPotencia(potencia); // Actualiza la potencia del motor
			motor->setVelocidadRPM(velocidadRPM); // Actualiza la velocidad del motor
			break; // Sale del bucle una vez encontrado y actualizado
		}
	}
	escribirArchivo(listaMotores); // Escribe los cambios en el archivo
}

// M�todo para eliminar un motor el�ctrico por su ID
void MotorElectricoController::eliminarMotorElectrico(int id) {
	List<MotorElectrico^>^ listaMotores = listarTodos(); // Obtiene la lista de motores el�ctricos
	// Busca el motor a eliminar
	for (int i = 0; i < listaMotores->Count; i++) {
		MotorElectrico^ motor = listaMotores[i];
		if (motor->getIdDispositivo() == id) {
			listaMotores->RemoveAt(i); // Elimina el motor de la lista
			break; // Sale del bucle una vez encontrado y eliminado
		}
	}
	escribirArchivo(listaMotores); // Escribe los cambios en el archivo
}