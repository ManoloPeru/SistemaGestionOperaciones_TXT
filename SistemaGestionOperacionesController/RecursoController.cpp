#include "RecursoController.h"

using namespace SistemaGestionOperacionesController;
using namespace System::IO;

RecursoController::RecursoController() {

}

List<Recurso^>^ RecursoController::listarTodos() {
	List<Recurso^>^ listaRecursos = gcnew List<Recurso^>(); //Aqui creo la lista vacía
	
	// Verifica si el archivo existe, si no, lo crea vacío
	if (!File::Exists("Recursos.txt")) {
		File::WriteAllText("Recursos.txt", "");
	}

	//Leo el archivo y lo separo por lineas
	array<String^>^ lineas = File::ReadAllLines("Recursos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		//Console::WriteLine("Linea: {0}", linea);
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int idRecurso = Convert::ToInt32(campos[0]);
		String^ nombre = campos[1];
		int cantidad = Convert::ToInt32(campos[2]);
		String^ estado = campos[3];
		Recurso^ recurso = gcnew Recurso(idRecurso, nombre, cantidad, estado);
		listaRecursos->Add(recurso);
	}
	//Console::WriteLine("Cantidad de recursos: {0}", listaRecursos->Count);
	return listaRecursos;
}

Recurso^ RecursoController::buscarRecursoxidRecurso(int idRecurso) {
	List<Recurso^>^ listaRecursos = listarTodos();
	for (int i = 0; i < listaRecursos->Count; i++) {
		Recurso^ recurso = listaRecursos[i];
		if (recurso->getIdRecurso() == idRecurso) {
			return recurso;
		}
	}
}

List<Recurso^>^ RecursoController::buscarRecursoxNombre(String^ nombreBuscar) {
	List<Recurso^>^ listaRecursos = gcnew List<Recurso^>(); //Aqui creo la lista vacía
	array<String^>^ lineas = File::ReadAllLines("Recursos.txt");
	String^ separadores = ";";
	for each (String ^ linea in lineas) {
		array<String^>^ campos = linea->Split(separadores->ToCharArray());
		int idRecurso = Convert::ToInt32(campos[0]);
		String^ nombre = campos[1];
		int cantidad = Convert::ToInt32(campos[2]);
		String^ estado = campos[3];
		if (nombre->Contains(nombreBuscar)) {
			Recurso^ recurso = gcnew Recurso(idRecurso, nombre, cantidad, estado);
			listaRecursos->Add(recurso);
		}
	}
	return listaRecursos;
}

void RecursoController::agregarRecurso(int idRecurso, String^ nombre, int cantidad, String^ estado) {
	List<Recurso^>^ listaRecursos = listarTodos();
	Recurso^ recursoNuevo = gcnew Recurso(idRecurso, nombre, cantidad, estado);
	listaRecursos->Add(recursoNuevo);
	escribirArchivo(listaRecursos);
}

void RecursoController::escribirArchivo(List<Recurso^>^ listaRecursos) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaRecursos->Count);
	//Recorro la lista de recursos y los guardo en el array
	for (int i = 0; i < listaRecursos->Count; i++) {
		//Console::WriteLine("ID: {0}", listaRecursos[i]->getIdRecurso());
		Recurso^ recurso = listaRecursos[i];
		lineasArchivo[i] = recurso->getIdRecurso() + ";" + recurso->getNombre() + ";" + recurso->getCantidad() + ";" + recurso->getEstado();
	}
	File::WriteAllLines("Recursos.txt", lineasArchivo);
}

void RecursoController::actualizarRecurso(int idRecurso, String^ nombre, int cantidad, String^ estado) {
	List<Recurso^>^ listaRecursos = listarTodos();
	//Busco el recurso a actualizar
	for (int i = 0; i < listaRecursos->Count; i++) {
		//Console::WriteLine("ID: {0}", listaRecursos[i]->getIdRecurso());
		Recurso^ recurso = listaRecursos[i];
		if (recurso->getIdRecurso() == idRecurso) {
			recurso->setNombre(nombre);
			recurso->setCantidad(cantidad);
			recurso->setEstado(estado);
			listaRecursos[i] = recurso;
			break;
		}
	}
	escribirArchivo(listaRecursos);
}

void RecursoController::eliminarRecurso(int idRecurso) {
	List<Recurso^>^ listaRecursos = listarTodos();
	//Busco el recurso a eliminar
	for (int i = 0; i < listaRecursos->Count; i++) {
		//Console::WriteLine("ID: {0}", listaRecursos[i]->getIdRecurso());
		Recurso^ recurso = listaRecursos[i];
		if (recurso->getIdRecurso() == idRecurso) {
			//Console::WriteLine("ID: {0}", listaRecursos[i]->getIdRecurso());
			//Aqui ya elimine al que queria de la lista
			listaRecursos->RemoveAt(i);
			break;
		}
	}
	//Vuelvo a escribir la lista en el archivo, sin considerar al eliminado
	escribirArchivo(listaRecursos);
}