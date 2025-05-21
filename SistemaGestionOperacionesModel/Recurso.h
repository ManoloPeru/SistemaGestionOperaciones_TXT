#pragma once

namespace SistemaGestionOperacionesModel {
	using namespace System; // Para tipos como String

	public ref class Recurso {
	private:
		int idRescurso;
		String^ nombre;
		int Cantidad;
		String^ estado;
	public:
		// Constructor vacio
		Recurso();
		// Constructor con todos los parámetros
		Recurso(int idRes, String^ nombre, int Cantidad, String^ estado);
		
		// Metodos GET
		int getIdRecurso();
		String^ getNombre();
		int getCantidad();
		String^ getEstado();
		
		// Metodos SET
		void setIdRecurso(int id);
		void setNombre(String^ nombre);
		void setCantidad(int Cantidad);
		void setEstado(String^ estado);
		void Activar();
		void Desactivar();
	};
}