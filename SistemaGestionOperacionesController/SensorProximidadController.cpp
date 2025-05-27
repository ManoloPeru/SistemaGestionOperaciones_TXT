#include "SensorProximidadController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;
// Constructor de la clase SensorProximidadController
SensorProximidadController::SensorProximidadController() {
}

// Método para listar todos los sensores de proximidad
List<SensorProximidad^>^ SensorProximidadController::listarTodos() {
	List<SensorProximidad^>^ listaSensores = gcnew List<SensorProximidad^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("SensoresProximidad.txt")) {
		File::WriteAllText("SensoresProximidad.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("SensoresProximidad.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1];
		float precision = Convert::ToSingle(campos[2]);
		float rangoMin = Convert::ToSingle(campos[3]);
		float rangoMax = Convert::ToSingle(campos[4]);
		float valorActual = Convert::ToSingle(campos[5]);
		String^ unidad = campos[6];
		SensorProximidad^ sensor = gcnew SensorProximidad(unidad);
		sensor->setIdDispositivo(id);
		sensor->setEstado(estado);
		sensor->setPrecision(precision);
		sensor->setRangoMin(rangoMin);
		sensor->setRangoMax(rangoMax);
		sensor->setValorActual(valorActual);
		listaSensores->Add(sensor);
	}
	return listaSensores; // Retorna la lista de sensores de proximidad
}

// Método para buscar un sensor de proximidad por ID
SensorProximidad^ SensorProximidadController::buscarSensorxid(int id) {
	List<SensorProximidad^>^ listaSensores = listarTodos(); // Obtiene la lista de sensores
	// Recorre la lista de sensores para encontrar el sensor con el ID especificado
	for (int i = 0; i < listaSensores->Count; i++) {
		SensorProximidad^ sensor = listaSensores[i];
		if (sensor->getIdDispositivo() == id) {
			return sensor; // Retorna el sensor encontrado
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// Método para buscar sensores de proximidad por estado
List<SensorProximidad^>^ SensorProximidadController::buscarSensorxEstado(String^ estado) {
	List<SensorProximidad^>^ listaSensores = gcnew List<SensorProximidad^>(); // Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("SensoresProximidad.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ estadoActual = campos[1];
		float precision = Convert::ToSingle(campos[2]);
		float rangoMin = Convert::ToSingle(campos[3]);
		float rangoMax = Convert::ToSingle(campos[4]);
		float valorActual = Convert::ToSingle(campos[5]);
		String^ unidad = campos[6];
		if (estadoActual->Equals(estado)) {
			SensorProximidad^ sensor = gcnew SensorProximidad(unidad);
			sensor->setIdDispositivo(id);
			sensor->setEstado(estadoActual);
			sensor->setPrecision(precision);
			sensor->setRangoMin(rangoMin);
			sensor->setRangoMax(rangoMax);
			sensor->setValorActual(valorActual);
			listaSensores->Add(sensor);
		}
	}
	return listaSensores; // Retorna la lista de sensores con el estado especificado
}

// Método para agregar un nuevo sensor de proximidad
void SensorProximidadController::agregarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad) {
	// Crea un nuevo sensor de proximidad con los parámetros proporcionados
	SensorProximidad^ sensorNuevo = gcnew SensorProximidad(unidad);
	sensorNuevo->setIdDispositivo(id); // Establece el ID del sensor
	sensorNuevo->setEstado(estado); // Establece el estado del sensor
	sensorNuevo->setPrecision(precision); // Establece la precisión del sensor
	sensorNuevo->setRangoMin(rangoMin); // Establece el rango mínimo del sensor
	sensorNuevo->setRangoMax(rangoMax); // Establece el rango máximo del sensor
	sensorNuevo->setValorActual(valorActual); // Establece el valor actual del sensor
	// Obtiene la lista de sensores existentes, agrega el nuevo sensor y escribe los cambios en el archivo
	List<SensorProximidad^>^ listaSensores = listarTodos();
	listaSensores->Add(sensorNuevo);
	escribirArchivo(listaSensores);
}

// Método para escribir la lista de sensores en el archivo
void SensorProximidadController::escribirArchivo(List<SensorProximidad^>^ listaSensores) {
	// Abre el archivo "SensoresProximidad.txt" para escribir los datos de los sensores
	StreamWriter^ writer = gcnew StreamWriter("SensoresProximidad.txt");
	// Recorre la lista de sensores y escribe cada uno en una línea del archivo
	for each (SensorProximidad ^ sensor in listaSensores) {
		String^ linea = String::Format("{0};{1};{2};{3};{4};{5};{6}",
			sensor->getIdDispositivo(),
			sensor->getEstado(),
			sensor->getPrecision(),
			sensor->getRangoMin(),
			sensor->getRangoMax(),
			sensor->getValorActual(),
			sensor->getUnidad());
		writer->WriteLine(linea); // Escribe la línea en el archivo
	}
	writer->Close(); // Cierra el escritor de archivos
}

// Método para actualizar un sensor de proximidad existente
void SensorProximidadController::actualizarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad) {
	List<SensorProximidad^>^ listaSensores = listarTodos(); // Obtiene la lista de sensores
	// Recorre la lista de sensores para encontrar el sensor con el ID especificado
	for (int i = 0; i < listaSensores->Count; i++) {
		SensorProximidad^ sensor = listaSensores[i];
		if (sensor->getIdDispositivo() == id) {
			sensor->setEstado(estado);
			sensor->setPrecision(precision);
			sensor->setRangoMin(rangoMin);
			sensor->setRangoMax(rangoMax);
			sensor->setValorActual(valorActual);
			sensor->setUnidad(unidad);
			escribirArchivo(listaSensores); // Escribe los cambios en el archivo
			return; // Sale del método una vez actualizado
		}
	}
}

// Método para eliminar un sensor de proximidad por ID
void SensorProximidadController::eliminarSensor(int id) {
	List<SensorProximidad^>^ listaSensores = listarTodos(); // Obtiene la lista de sensores
	// Recorre la lista de sensores para encontrar el sensor con el ID especificado
	for (int i = 0; i < listaSensores->Count; i++) {
		SensorProximidad^ sensor = listaSensores[i];
		if (sensor->getIdDispositivo() == id) {
			listaSensores->RemoveAt(i); // Elimina el sensor de la lista
			escribirArchivo(listaSensores); // Escribe la lista actualizada en el archivo
			return; // Sale del método una vez eliminado
		}
	}
}