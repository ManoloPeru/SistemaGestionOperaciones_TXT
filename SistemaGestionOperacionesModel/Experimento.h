#pragma once 

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase Experimento
    public ref class Experimento {
    private:
        int idExperimento;
        String^ fechaInicio;
        int duracion;
        String^ estado;

    public:
        // Constructor vacio
        Experimento();

        // Constructor con todos los parámetros
        Experimento(int idExperimento, String^ fechaInicio, int duracion, String^ estado);

        // Metodos GET
        int getIdExperimento();
        String^ getFechaInicio();
        int getDuracion();
        String^ getEstado();

        // Metodos SET
        void setIdExperimento(int idExperimento);
        void setFechaInicio(String^ fechaInicio);
        void setDuracion(int duracion);
        void setEstado(String^ estado);

        // Métodos
        void Iniciar();
        void Finalizar();
        void GenerarInforme();
    };
}