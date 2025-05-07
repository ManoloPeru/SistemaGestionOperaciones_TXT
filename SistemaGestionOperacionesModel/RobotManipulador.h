#pragma once
#include "Dispositivo.h"

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase RobotManipulador
    public ref class RobotManipulador : public Dispositivo {
    private:
        float ubicacionX, ubicacionY, ubicacionZ;
        float capacidadCarga;
        float velocidad;

    public:
        // Constructor vacio
        RobotManipulador();

        // Constructor con todos los parámetros
        RobotManipulador(float ubicacionX, float ubicacionY, float ubicacionZ, float capacidadCarga, float velocidad);

        // Metodos GET
        float getUbicacionX();
        float getUbicacionY();
        float getUbicacionZ();
        float getCapacidadCarga();
        float getVelocidad();
        
        // Metodos SET
        void setUbicacionX(float ubicacionX);
        void setUbicacionY(float ubicacionY);
        void setUbicacionZ(float ubicacionZ);
        void setCapacidadCarga(float capacidadCarga);
        void setVelocidad(float velocidad);

        // Métodos
        void MoverBrazo(float x, float y, float z);
        void GirarArticulacion(float grados);
        void ReportarEstado();
    };
}