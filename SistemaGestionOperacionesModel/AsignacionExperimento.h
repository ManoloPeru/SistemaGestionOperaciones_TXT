#pragma once 
#include "Dispositivo.h"
#include "Experimento.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase AsignacionExperimento
    public ref class AsignacionExperimento {
    private:
        int idAsignacion;
        String^ fechaAsignacion;
        String^ rol;
        Dispositivo^ dispositivo;
        Experimento^ experimento;

    public:
        // Constructor vacio
        AsignacionExperimento();

        // Constructor con todos los parámetros
        AsignacionExperimento(int idAsignacion, String^ fechaAsignacion, String^ rol, Dispositivo^ dispositivo, Experimento^ experimento);

        // Metodos GET
        int getIdAsignacion();
        String^ getFechaAsignacion();
        String^ getRol();
        Dispositivo^ getDispositivo();
        Experimento^ getExperimento();

        // Metodos SET
        void setIdAsignacion(int idAsignacion);
        void setFechaAsignacion(String^ fechaAsignacion);
        void setRol(String^ rol);
        void setDispositivo(Dispositivo^ dispositivo);
        void setExperimento(Experimento^ experimento);

    };
}
