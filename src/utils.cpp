/*
 * Archivo: utils.cpp
 * Descripción: Este archivo contiene funciones utilitarias generales para el sistema.
 *
 * Autor(es): Mauricio Gonzalez
 */

#include <cstdlib>

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}