#include "Recurso.h"

namespace SistemaGestionOperacionesModel {
	// Constructor vacío
	Recurso::Recurso() {
		this->idRescurso = 0;
		this->nombre = "";
		this->Cantidad = 0;
		this->estado = "Inactivo";
	}

	// Constructor con parámetros
	Recurso::Recurso(int idRes, String^ nombre, int Cantidad, String^ estado) {
		this->idRescurso = idRes;
		this->nombre = nombre;
		this->Cantidad = Cantidad;
		this->estado = estado;
	}

	// Métodos GET
	int Recurso::getIdRecurso() {
		return this->idRescurso;
	}
	String^ Recurso::getNombre() {
		return this->nombre;
	}
	int Recurso::getCantidad() {
		return this->Cantidad;
	}
	String^ Recurso::getEstado() {
		return this->estado;
	}
	// Métodos SET
	void Recurso::setIdRecurso(int id) {
		this->idRescurso = id;
	}
	void Recurso::setNombre(String^ nombre) {
		this->nombre = nombre;
	}
	void Recurso::setCantidad(int Cantidad) {
		this->Cantidad = Cantidad;
	}
	void Recurso::setEstado(String^ estado) {
		this->estado = estado;
	}
	void Recurso::Activar() {
		estado = "Activo";
		Console::WriteLine("Recurso {0} activado.", idRescurso);
	}
	void Recurso::Desactivar() {
		estado = "Inactivo";
		Console::WriteLine("Recurso {0} desactivado.", idRescurso);
	}
}
