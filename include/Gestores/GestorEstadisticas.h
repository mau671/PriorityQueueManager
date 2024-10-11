/*
 * Archivo: GestorEstadistica.cpp
 * Descripción: Implementación de funciones para consultar estadísticas del sistema.
 *
 * Autor(es): Josue Meza
 */

#ifndef GESTORESTADISTICAS_H
#define GESTORESTADISTICAS_H

#include "Estructuras/Concretas/ArrayList.h"
#include "Modelos/Area.h"
#include "Modelos/Ventanilla.h"
#include "Modelos/Servicio.h"
#include "Modelos/Tiquete.h"
#include "Modelos/TipoUsuario.h"


void TiempoPromedioEspera(List<Area*>* areas);
void TiquetesPorArea(List<Area*>* areas);
void TiquetesPorVentanilla(List<Ventanilla*>* ventanillas);
void TiquetesPorUsuario(List<TipoUsuario*>* tiposUsuario);
void generarEstadisticas(List<TipoUsuario*>* tiposUsuario, List<Area*>* areas, List<Servicio*>* servicios);

#endif