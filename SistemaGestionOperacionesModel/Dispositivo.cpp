#pragma once
#include "Dispositivo.h"

namespace SistemaGestionOperacionesModel {

    // Constructor vac�o
    Dispositivo::Dispositivo() {
        this->idDispositivo = 0;
        this->estado = "Inactivo";
    }

    // Constructor con par�metros
    Dispositivo::Dispositivo(int idDispositivo, String^ estado) {
        this->idDispositivo = idDispositivo;
        this->estado = estado;
    }

    // Metodos GET
    int Dispositivo::getIdDispositivo() {
        return this->idDispositivo;
    }

    String^ Dispositivo::getEstado() {
        return this->estado;
    }

    // Metodos SET
    void Dispositivo::setIdDispositivo(int id) {
        this->idDispositivo = id;
    }

    void Dispositivo::setEstado(String^ estado) {
        this->estado = estado;
    }

    // M�todos
    void Dispositivo::Activar() {
        estado = "Activo";
        Console::WriteLine("Dispositivo {0} activado.", idDispositivo);
    }

    void Dispositivo::Desactivar() {
        estado = "Inactivo";
        Console::WriteLine("Dispositivo {0} desactivado.", idDispositivo);
    }
}
