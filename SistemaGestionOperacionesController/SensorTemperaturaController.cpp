#include "SensorTemperaturaController.h"
using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase SensorTemperaturaController
SensorTemperaturaController::SensorTemperaturaController() {
}

// Método para listar todos los sensores de temperatura
List<SensorTemperatura^>^ SensorTemperaturaController::listarTodos() {
	List<SensorTemperatura^>^ listaSensores = gcnew List<SensorTemperatura^>(); // Aqui creo la lista vacía
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("SensoresTemperatura.txt")) {
		File::WriteAllText("SensoresTemperatura.txt", "");
	}
	// Leo el archivo y lo separo por líneas
	array<String^>^ lineas = File::ReadAllLines("SensoresTemperatura.txt");
	// Define los separadores para dividir cada línea en campos
	String^ separadores = ";";
	// Recorre cada línea del archivo
	for each (String ^ linea in lineas) {
		// Divide la línea en campos usando los separadores definidos
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		// Convierte los campos a los tipos adecuados y crea un nuevo SensorTemperatura
		int id = Convert::ToInt32(campos[0]);
		String^ estado = campos[1]; // Obtiene el estado del sensor
		float precision = Convert::ToSingle(campos[2]); // Convierte la precisión a float
		float rangoMin = Convert::ToSingle(campos[3]); // Convierte el rango mínimo a float
		float rangoMax = Convert::ToSingle(campos[4]); // Convierte el rango máximo a float
		float valorActual = Convert::ToSingle(campos[5]); // Convierte el valor actual a float
		String^ unidad = campos[6]; // Convierte la unidad a float
		// Crea un nuevo SensorTemperatura con los datos obtenidos
		SensorTemperatura^ sensor = gcnew SensorTemperatura(unidad);
		// Establece el ID y el estado del sensor
		sensor->setIdDispositivo(id); // Establece el ID del sensor
		sensor->setEstado(estado); // Establece el estado del sensor
		sensor->setPrecision(precision); // Establece la precisión del sensor
		sensor->setRangoMin(rangoMin); // Establece el rango mínimo del sensor
		sensor->setRangoMax(rangoMax); // Establece el rango máximo del sensor
		sensor->setValorActual(valorActual); // Establece el valor actual del sensor
		// Agrega el sensor a la lista de sensores
		listaSensores->Add(sensor);
	}
	return listaSensores; // Retorna la lista de sensores de temperatura
}

// Agrega un nuevo sensor de temperatura con los parámetros proporcionados
SensorTemperatura^ SensorTemperaturaController::buscarSensorxid(int id) {
	List<SensorTemperatura^>^ listaSensores = listarTodos(); // Obtiene la lista de sensores
	// Recorre la lista de sensores para encontrar el sensor con el ID especificado
	for (int i = 0; i < listaSensores->Count; i++) {
		SensorTemperatura^ sensor = listaSensores[i];
		if (sensor->getIdDispositivo() == id) {
			return sensor; // Retorna el sensor encontrado
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// Método para buscar sensores de temperatura por estado
List<SensorTemperatura^>^ SensorTemperaturaController::buscarSensorxEstado(String^ estado) {
	List<SensorTemperatura^>^ listaSensores = gcnew List<SensorTemperatura^>(); // Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("SensoresTemperatura.txt");
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
			SensorTemperatura^ sensor = gcnew SensorTemperatura(unidad);
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

// Método para agregar un nuevo sensor de temperatura
void SensorTemperaturaController::agregarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad) {
	// Crea un nuevo sensor de temperatura con los parámetros proporcionados
	SensorTemperatura^ sensorNuevo = gcnew SensorTemperatura(unidad);
	sensorNuevo->setIdDispositivo(id); // Establece el ID del sensor
	sensorNuevo->setEstado(estado); // Establece el estado del sensor
	sensorNuevo->setPrecision(precision); // Establece la precisión del sensor
	sensorNuevo->setRangoMin(rangoMin); // Establece el rango mínimo del sensor
	sensorNuevo->setRangoMax(rangoMax); // Establece el rango máximo del sensor
	sensorNuevo->setValorActual(valorActual); // Establece el valor actual del sensor
	// Obtiene la lista de sensores existentes, agrega el nuevo sensor y escribe los cambios en el archivo
	List<SensorTemperatura^>^ listaSensores = listarTodos();
	// Agrega el nuevo sensor a la lista de sensores
	listaSensores->Add(sensorNuevo);
	// Llama al método para escribir la lista actualizada de sensores en el archivo
	escribirArchivo(listaSensores); 
}

// Método para escribir la lista de sensores en el archivo
void SensorTemperaturaController::escribirArchivo(List<SensorTemperatura^>^ listaSensores) {
	// Abre el archivo "SensoresTemperatura.txt" para escribir los datos de los sensores
	StreamWriter^ writer = gcnew StreamWriter("SensoresTemperatura.txt");
	// Recorre la lista de sensores y escribe cada uno en una línea del archivo
	for each (SensorTemperatura ^ sensor in listaSensores) {
		// Formatea la línea con los datos del sensor y la escribe en el archivo
		String^ linea = String::Format("{0};{1};{2};{3};{4};{5};{6}",
			sensor->getIdDispositivo(), sensor->getEstado(), sensor->getPrecision(),
			sensor->getRangoMin(), sensor->getRangoMax(), sensor->getValorActual(),
			sensor->getUnidad());
		writer->WriteLine(linea);
	}
	writer->Close(); // Cierra el escritor para guardar los cambios
}

// Método para actualizar un sensor de temperatura existente
void SensorTemperaturaController::actualizarSensor(int id, String^ estado, float precision, float rangoMin, float rangoMax, float valorActual, String^ unidad) {
	List<SensorTemperatura^>^ listaSensores = listarTodos(); // Obtiene la lista de sensores
	// Recorre la lista de sensores para encontrar el sensor con el ID especificado
	for (int i = 0; i < listaSensores->Count; i++) {
		SensorTemperatura^ sensor = listaSensores[i];
		// Verifica si el ID del sensor coincide con el ID proporcionado
		if (sensor->getIdDispositivo() == id) {
			// Actualiza los datos del sensor encontrado
			sensor->setEstado(estado);
			sensor->setPrecision(precision);
			sensor->setRangoMin(rangoMin);
			sensor->setRangoMax(rangoMax);
			sensor->setValorActual(valorActual);
			sensor->setUnidad(unidad);
			listaSensores[i] = sensor; // Actualiza el sensor en la lista
			break; // Sale del bucle una vez que se actualiza el sensor
		}
	}
	escribirArchivo(listaSensores); // Llama al método para escribir la lista actualizada de sensores en el archivo
}

// Método para eliminar un sensor de temperatura por ID
void SensorTemperaturaController::eliminarSensor(int id) {
	List<SensorTemperatura^>^ listaSensores = listarTodos(); // Obtiene la lista de sensores
	// Recorre la lista de sensores para encontrar el sensor con el ID especificado
	for (int i = 0; i < listaSensores->Count; i++) {
		SensorTemperatura^ sensor = listaSensores[i];
		// Verifica si el ID del sensor coincide con el ID proporcionado
		if (sensor->getIdDispositivo() == id) {
			listaSensores->RemoveAt(i); // Elimina el sensor de la lista
			break; // Sale del bucle una vez que se elimina el sensor
		}
	}
	escribirArchivo(listaSensores); // Llama al método para escribir la lista actualizada de sensores en el archivo
}