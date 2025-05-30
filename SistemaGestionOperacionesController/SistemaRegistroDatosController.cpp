#include "SistemaRegistroDatosController.h"

using namespace SistemaGestionOperacionesController;
using namespace System::IO;

// Constructor de la clase SistemaRegistroDatosController
SistemaRegistroDatosController::SistemaRegistroDatosController() {
}

// Retorna la lista de SistemaRegistroDatos encontrados
List<SistemaRegistroDatos^>^ SistemaRegistroDatosController::listarTodos() {
	List<SistemaRegistroDatos^>^ listaRegistroDatos = gcnew List<SistemaRegistroDatos^>(); // Aqui creo la lista vac�a
	// Verifica si el archivo existe, si no, lo crea vac�o
	if (!File::Exists("SistemaRegistroDatos.txt")) {
		File::WriteAllText("SistemaRegistroDatos.txt", "");
	}
	// Leo el archivo y lo separo por l�neas
	array<String^>^ lineas = File::ReadAllLines("SistemaRegistroDatos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ fecha = campos[1];
		String^ hora = campos[2];
		String^ tipoDato = campos[3];
		float valorRegistrado = Convert::ToSingle(campos[4]);
		SistemaRegistroDatos^ registro = gcnew SistemaRegistroDatos(id, fecha, hora, tipoDato, valorRegistrado);
		listaRegistroDatos->Add(registro); // Agrega el registro a la lista de registros
	}
	return listaRegistroDatos; // Retorna la lista de registros del sistema
}

// M�todo para buscar un registro del sistema por su ID
SistemaRegistroDatos^ SistemaRegistroDatosController::buscarSistemaRegistroDatosxId(int id) {
	List<SistemaRegistroDatos^>^ listaRegistroDatos = listarTodos(); // Obtiene la lista de registros del sistema
	// Recorre la lista de registros para encontrar el registro con el ID especificado
	for (int i = 0; i < listaRegistroDatos->Count; i++) {
		SistemaRegistroDatos^ registro = listaRegistroDatos[i];
		if (registro->getIdRegistro() == id) {
			return registro; // Retorna el registro encontrado
		}
	}
	return nullptr; // Si no se encuentra, retorna nullptr
}

// M�todo para buscar registros del sistema por fecha de asignaci�n
List<SistemaRegistroDatos^>^ SistemaRegistroDatosController::buscarSistemaRegistroDatosxFechaAsignacion(String^ fecha) {
	List<SistemaRegistroDatos^>^ listaRegistroDatos = gcnew List<SistemaRegistroDatos^>(); // Aqui creo la lista vac�a
	array<String^>^ lineas = File::ReadAllLines("SistemaRegistroDatos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int id = Convert::ToInt32(campos[0]);
		String^ fechaActual = campos[1];
		if (fechaActual->Equals(fecha)) {
			String^ hora = campos[2];
			String^ tipoDato = campos[3];
			float valorRegistrado = Convert::ToSingle(campos[4]);
			SistemaRegistroDatos^ registro = gcnew SistemaRegistroDatos(id, fechaActual, hora, tipoDato, valorRegistrado);
			listaRegistroDatos->Add(registro); // Agrega el registro a la lista de registros
		}
	}
	return listaRegistroDatos; // Retorna la lista de registros con la fecha de asignaci�n especificada
}

// M�todo para agregar un nuevo registro del sistema con los par�metros proporcionados
void SistemaRegistroDatosController::agregarSistemaRegistroDatos(int id, String^ fecha, String^ hora, String^ tipoDato, float valorRegistrado) {
	// Crea un nuevo registro del sistema con los par�metros proporcionados
	SistemaRegistroDatos^ registroNuevo = gcnew SistemaRegistroDatos(id, fecha, hora, tipoDato, valorRegistrado);
	// Obtiene la lista de registros existentes, agrega el nuevo registro y escribe los cambios en el archivo
	List<SistemaRegistroDatos^>^ listaRegistroDatos = listarTodos();
	listaRegistroDatos->Add(registroNuevo);
	escribirArchivo(listaRegistroDatos);
}

// M�todo para escribir la lista de registros del sistema en el archivo
void SistemaRegistroDatosController::escribirArchivo(List<SistemaRegistroDatos^>^ listaRegistroDatos) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaRegistroDatos->Count);
	// Recorre la lista de registros y los guarda en el array
	for (int i = 0; i < listaRegistroDatos->Count; i++) {
		SistemaRegistroDatos^ registro = listaRegistroDatos[i];
		lineasArchivo[i] = String::Format("{0};{1};{2};{3};{4}",
			registro->getIdRegistro(),
			registro->getFecha(),
			registro->getHora(),
			registro->getTipoDato(),
			registro->getValorRegistrado());
	}
	File::WriteAllLines("SistemaRegistroDatos.txt", lineasArchivo); // Escribe el array en el archivo
}

// M�todo para actualizar un registro del sistema con los par�metros proporcionados
void SistemaRegistroDatosController::actualizarSistemaRegistroDatos(int id, String^ fecha, String^ hora, String^ tipoDato, float valorRegistrado) {
	List<SistemaRegistroDatos^>^ listaRegistroDatos = listarTodos(); // Obtiene la lista de registros del sistema
	// Recorre la lista de registros para encontrar el registro con el ID especificado
	for (int i = 0; i < listaRegistroDatos->Count; i++) {
		SistemaRegistroDatos^ registro = listaRegistroDatos[i];
		if (registro->getIdRegistro() == id) {
			// Actualiza los campos del registro encontrado
			registro->setFecha(fecha);
			registro->setHora(hora);
			registro->setTipoDato(tipoDato);
			registro->setValorRegistrado(valorRegistrado);
			break; // Sale del bucle una vez que se actualiza el registro
		}
	}
	escribirArchivo(listaRegistroDatos); // Escribe los cambios en el archivo
}

// M�todo para eliminar un registro del sistema por su ID
void SistemaRegistroDatosController::eliminarSistemaRegistroDatos(int id) {
	List<SistemaRegistroDatos^>^ listaRegistroDatos = listarTodos(); // Obtiene la lista de registros del sistema
	// Recorre la lista de registros para encontrar el registro con el ID especificado
	for (int i = 0; i < listaRegistroDatos->Count; i++) {
		SistemaRegistroDatos^ registro = listaRegistroDatos[i];
		if (registro->getIdRegistro() == id) {
			listaRegistroDatos->RemoveAt(i); // Elimina el registro encontrado
			break; // Sale del bucle una vez que se elimina el registro
		}
	}
	escribirArchivo(listaRegistroDatos); // Escribe los cambios en el archivo
}