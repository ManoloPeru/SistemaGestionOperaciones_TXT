#include "RobotManipulador.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    RobotManipulador::RobotManipulador() : Dispositivo()
    {
        this->ubicacionX = 0.0f;
        this->ubicacionY = 0.0f;
        this->ubicacionZ = 0.0f;
        this->capacidadCarga = 0.0f;
        this->velocidad = 0.0f;
    }

    // Constructor con parámetros
    RobotManipulador::RobotManipulador(float ubicacionX, float ubicacionY, float ubicacionZ, float capacidadCarga, float velocidad) : Dispositivo (idDispositivo, estado)
    {
        this->ubicacionX = ubicacionX;
        this->ubicacionY = ubicacionY;
        this->ubicacionZ = ubicacionZ;
        this->capacidadCarga = capacidadCarga;
        this->velocidad = velocidad;
    }

    // Métodos GET
    float RobotManipulador::getUbicacionX()
    {
        return this->ubicacionX;
    }

    float RobotManipulador::getUbicacionY()
    {
        return this->ubicacionY;
    }

    float RobotManipulador::getUbicacionZ()
    {
        return this->ubicacionZ;
    }

    float RobotManipulador::getCapacidadCarga()
    {
        return this->capacidadCarga;
    }

    float RobotManipulador::getVelocidad()
    {
        return this->velocidad;
    }

    // Métodos SET
    void RobotManipulador::setUbicacionX(float ubicacionX)
    {
        this->ubicacionX = ubicacionX;
    }

    void RobotManipulador::setUbicacionY(float ubicacionY)
    {
        this->ubicacionY = ubicacionY;
    }

    void RobotManipulador::setUbicacionZ(float ubicacionZ)
    {
        this->ubicacionZ = ubicacionZ;
    }

    void RobotManipulador::setCapacidadCarga(float capacidadCarga)
    {
        this->capacidadCarga = capacidadCarga;
    }

    void RobotManipulador::setVelocidad(float velocidad)
    {
        this->velocidad = velocidad;
    }

    void RobotManipulador::MoverBrazo(float x, float y, float z)
    {
        this->setUbicacionX(x);
        this->setUbicacionY(y);
        this->setUbicacionZ(z);
        Console::WriteLine("Robot {0} movido a ({1}, {2}, {3}).", this->getIdDispositivo(), x, y, z);
    }

    void RobotManipulador::GirarArticulacion(float grados)
    {
        Console::WriteLine("El Robot {0}: ha girado {1} grados", this->getIdDispositivo(), grados);
    }

    void RobotManipulador::ReportarEstado() {
        Console::WriteLine("Robot {0}: Estado={1}, Posición=({2}, {3}, {4})",
            this->getIdDispositivo(), this->getEstado() ? "Activo" : "Inactivo", ubicacionX, ubicacionY, ubicacionZ);
    }
}

