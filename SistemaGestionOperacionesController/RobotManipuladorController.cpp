#include "RobotManipuladorController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;

RobotManipuladorController::RobotManipuladorController() {
}

List<RobotManipulador^>^ RobotManipuladorController::listarTodos() {
	List<RobotManipulador^>^ listaRobots = gcnew List<RobotManipulador^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("RobotManipuladores.txt")) {
		// Crea el archivo vacío si no existe
		File::WriteAllText("RobotManipuladores.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("RobotManipuladores.txt");
	// Define los separadores para dividir cada línea en campos
	String^ separadores = ";";
	// Recorre cada línea del archivo
	for each (String ^ linea in lineas) {
		// Divide la línea en campos usando los separadores definidos
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		// Convierte los campos a los tipos adecuados y crea un nuevo RobotManipulador
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1]; // Obtiene el estado del robot
		float ubicacionX = Convert::ToSingle(campos[2]); // Convierte la ubicación X a float
		float ubicacionY = Convert::ToSingle(campos[3]); // Convierte la ubicación Y a float
		float ubicacionZ = Convert::ToSingle(campos[4]); // Convierte la ubicación Z a float
		float capacidadCarga = Convert::ToSingle(campos[5]); // Convierte la capacidad de carga a float
		float velocidad = Convert::ToSingle(campos[6]); // Convierte la velocidad a float
		// Crea un nuevo RobotManipulador con los datos obtenidos
		RobotManipulador^ robot = gcnew RobotManipulador(ubicacionX, ubicacionY, ubicacionZ, capacidadCarga, velocidad);
		// Establece el ID y el estado del robot
		robot->setIdDispositivo(id);
		robot->setEstado(estado);
		// Agrega el robot a la lista de robots
		listaRobots->Add(robot);
	}
	// Retorna la lista de robots manipuladores
	return listaRobots;
}
RobotManipulador^ RobotManipuladorController::buscarRobotxid(int id) {
	// Obtiene la lista de robots existentes
	List<RobotManipulador^>^ listaRobots = listarTodos();
	// Recorre la lista de robots para encontrar el robot con el ID especificado
	for (int i = 0; i < listaRobots->Count; i++) {
		// Obtiene el robot en la posición i
		RobotManipulador^ robot = listaRobots[i];
		// Si el ID del robot coincide con el ID proporcionado, retorna el robot
		if (robot->getIdDispositivo() == id) {
			return robot;
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}
List<RobotManipulador^>^ RobotManipuladorController::buscarRobotxUbicacion(float ubicacionX, float ubicacionY, float ubicacionZ) {
	List<RobotManipulador^>^ listaRobots = gcnew List<RobotManipulador^>(); // Aqui creo la lista vacía
	// Lee el archivo "RobotManipuladores.txt" y separa las líneas
	array<String^>^ lineas = File::ReadAllLines("RobotManipuladores.txt");
	// Define los separadores para dividir cada línea en campos
	String^ separadores = ";";
	// Recorre cada línea del archivo
	for each (String ^ linea in lineas) {
		// Divide la línea en campos usando los separadores definidos
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		// Convierte los campos a los tipos adecuados y crea un nuevo RobotManipulador
		int id = Convert::ToInt32(campos[0]); // Convierte el ID a entero
		String^ estado = campos[1]; // Obtiene el estado del robot
		float x = Convert::ToSingle(campos[2]); // Convierte la ubicación X a float
		float y = Convert::ToSingle(campos[3]); // Convierte la ubicación Y a float
		float z = Convert::ToSingle(campos[4]); // Convierte la ubicación Z a float
		float capacidadCarga = Convert::ToSingle(campos[5]); // Convierte la capacidad de carga a float
		float velocidad = Convert::ToSingle(campos[5]); // Convierte la velocidad a float
		// Verifica si las coordenadas del robot coinciden con las buscadas
		if (x == ubicacionX && y == ubicacionY && z == ubicacionZ) {
			// Si coinciden, crea un nuevo RobotManipulador y lo agrega a la lista
			RobotManipulador^ robot = gcnew RobotManipulador(x, y, z, capacidadCarga, velocidad);
			// Establece el ID y el estado del robot
			listaRobots->Add(robot);
		}
	}
	// Retorna la lista de robots que coinciden con las coordenadas especificadas
	return listaRobots;
}
void RobotManipuladorController::agregarRobot(int id, String^ estado, float ubicacionX, float ubicacionY, float ubicacionZ, float capacidadCarga, float velocidad) {
	// Crea una nueva instancia de RobotManipulador con los parámetros proporcionados
	RobotManipulador^ robot = gcnew RobotManipulador(ubicacionX, ubicacionY, ubicacionZ, capacidadCarga, velocidad);
	// Establece el ID y el estado del robot
	robot->setIdDispositivo(id);
	robot->setEstado(estado);
	// Obtiene la lista de robots existentes, agrega el nuevo robot y escribe los cambios en el archivo
	List<RobotManipulador^>^ listaRobots = listarTodos();
	// Agrega el nuevo robot a la lista de robots
	listaRobots->Add(robot);
	// Llama al método para escribir la lista actualizada de robots en el archivo
	escribirArchivo(listaRobots);
}
void RobotManipuladorController::escribirArchivo(List<RobotManipulador^>^ listaRobots) {
	// Abre el archivo "RobotManipuladores.txt" para escribir los datos de los robots
	StreamWriter^ writer = gcnew StreamWriter("RobotManipuladores.txt");
	// Recorre la lista de robots y escribe cada uno en una línea del archivo
	for each (RobotManipulador ^ robot in listaRobots) {
		// Formatea la línea con los datos del robot y la escribe en el archivo
		String^ linea = String::Format("{0};{1};{2};{3};{4};{5};{6}",
			robot->getIdDispositivo(),
			robot->getEstado(),
			robot->getUbicacionX(),
			robot->getUbicacionY(),
			robot->getUbicacionZ(),
			robot->getCapacidadCarga(),
			robot->getVelocidad());
		// Escribe la línea en el archivo
		writer->WriteLine(linea);
	}
	// Cierra el escritor de archivos para guardar los cambios
	writer->Close();
}
void RobotManipuladorController::actualizarRobot(int id, String^ estado, float ubicacionX, float ubicacionY, float ubicacionZ, float capacidadCarga, float velocidad) {
	List<RobotManipulador^>^ listaRobots = listarTodos(); // Obtiene la lista de robots
	// Recorre la lista de robots para encontrar el robot con el ID especificado
	for (int i = 0; i < listaRobots->Count; i++) {
		// Obtiene el robot en la posición i
		RobotManipulador^ robot = listaRobots[i];
		// Si el ID del robot coincide con el ID proporcionado, actualiza sus propiedades
		if (robot->getIdDispositivo() == id) {
			robot->setEstado(estado); // Actualiza el estado del robot
			robot->setUbicacionX(ubicacionX); // Actualiza la ubicación X del robot
			robot->setUbicacionY(ubicacionY); // Actualiza la ubicación Y del robot
			robot->setUbicacionZ(ubicacionZ); // Actualiza la ubicación Z del robot
			robot->setCapacidadCarga(capacidadCarga); // Actualiza la capacidad de carga del robot
			robot->setVelocidad(velocidad); // Actualiza la velocidad del robot
			escribirArchivo(listaRobots); // Escribe los cambios en el archivo
			return;
		}
	}
}
void RobotManipuladorController::eliminarRobot(int id) {
	List<RobotManipulador^>^ listaRobots = listarTodos(); // Obtiene la lista de robots
	// Recorre la lista de robots para encontrar el robot con el ID especificado
	for (int i = 0; i < listaRobots->Count; i++) {
		RobotManipulador^ robot = listaRobots[i]; // Obtiene el robot en la posición i
		// Si el ID del robot coincide con el ID proporcionado, lo elimina
		if (robot->getIdDispositivo() == id) {
			listaRobots->RemoveAt(i); // Elimina el robot de la lista
			escribirArchivo(listaRobots); // Escribe los cambios en el archivo
			return;
		}
	}
}