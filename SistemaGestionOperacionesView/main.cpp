using namespace System;
using namespace SistemaGestionOperacionesModel;

int main() {
    // Crear dispositivos
    Dispositivo^ dispositivo1 = gcnew Dispositivo(1,"Activo");
    RobotManipulador^ robot = gcnew RobotManipulador();
    robot->setIdDispositivo(dispositivo1->getIdDispositivo());
    robot->setEstado(dispositivo1->getEstado());
    robot->setUbicacionX(0.5f);
    robot->setUbicacionY(1.5f);
    robot->setUbicacionZ(2.5f);
    robot->setCapacidadCarga(12.0f);
    robot->setVelocidad(5.0f);

    robot->Activar();

    // Crear experimento y asignar dispositivo
    Experimento^ exp = gcnew Experimento(1, "05/05/2025", 20, "Inicializado");
    AsignacionExperimento^ asignacion = gcnew AsignacionExperimento(10, "07/05/2025", "Principal", dispositivo1, exp);

    // Reportar estado
    robot->ReportarEstado();

    return 0;
}