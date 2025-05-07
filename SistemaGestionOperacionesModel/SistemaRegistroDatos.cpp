#include "SistemaRegistroDatos.h"

namespace SistemaGestionOperacionesModel {
    // Constructor vacío
    SistemaRegistroDatos::SistemaRegistroDatos()
    {
        this->idRegistro = 0;
        this->fecha = "";
        this->hora = "";
        this->tipoDato = "Inactivo";
        this->valorRegistrado = 0.0f;
    }

    // Constructor con parámetros
    SistemaRegistroDatos::SistemaRegistroDatos(int idRegistro, String^ fecha, String^ hora, String^ tipoDato, float valorRegistrado)
    {
        this->idRegistro = idRegistro;
        this->fecha = fecha;
        this->hora = hora;
        this->tipoDato = tipoDato;
        this->valorRegistrado = valorRegistrado;
    }

    // Métodos GET
    int SistemaRegistroDatos::getIdRegistro()
    {
        return this->idRegistro;
    }

    String^ SistemaRegistroDatos::getFecha()
    {
        return this->fecha;
    }

    String^ SistemaRegistroDatos::getHora()
    {
        return this->hora;
    }

    String^ SistemaRegistroDatos::getTipoDato()
    {
        return this->tipoDato;
    }

    float SistemaRegistroDatos::getValorRegistrado()
    {
        return this->valorRegistrado;
    }

    // Métodos SET
    void SistemaRegistroDatos::setIdRegistro(int idRegistro)
    {
        this->idRegistro = idRegistro;
    }

    void SistemaRegistroDatos::setFecha(String^ fecha)
    {
        this->fecha = fecha;
    }

    void SistemaRegistroDatos::setHora(String^ hora)
    {
        this->hora = hora;
    }

    void SistemaRegistroDatos::setTipoDato(String^ tipoDato)
    {
        this->tipoDato = tipoDato;
    }

    void SistemaRegistroDatos::setValorRegistrado(float valorRegistrado)
    {
        this->valorRegistrado = valorRegistrado;
    }

    //Metodos generales
    void SistemaRegistroDatos::GuardarDato()
    {
        Console::WriteLine("GuardarDato.");
    }

    void SistemaRegistroDatos::ConsultarRegistroXFecha()
    {
        Console::WriteLine("ConsultarRegistroXFecha.");
    }

    void SistemaRegistroDatos::GenerarReporte() {
        Console::WriteLine("GenerarReporte...");
    }
}

