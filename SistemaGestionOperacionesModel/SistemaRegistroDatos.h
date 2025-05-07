#pragma once 

namespace SistemaGestionOperacionesModel {
    using namespace System; // Para tipos como String

    // Declaracion de la clase SistemaRegistroDatos
    public ref class SistemaRegistroDatos {
    private:
        int idRegistro;
        String^ fecha;
        String^ hora;
        String^ tipoDato;
        float valorRegistrado;

    public:
        // Constructor vacio
        SistemaRegistroDatos();

        // Constructor con todos los parámetros
        SistemaRegistroDatos(int idRegistro, String^ fecha, String^ hora, String^ tipoDato, float valorRegistrado);

        // Metodos GET
        int getIdRegistro();
        String^ getFecha();
        String^ getHora();
        String^ getTipoDato();
        float getValorRegistrado();

        // Metodos SET
        void setIdRegistro(int idRegistro);
        void setFecha(String^ fecha);
        void setHora(String^ hora);
        void setTipoDato(String^ tipoDato);
        void setValorRegistrado(float valorRegistrado);

        // Métodos
        void GuardarDato();
        void ConsultarRegistroXFecha();
        void GenerarReporte();
    };
}