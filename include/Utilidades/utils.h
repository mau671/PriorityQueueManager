/*
 * Archivo: utils.h
 * Descripción: Proporciona una declaración de la función clearConsole, que limpia la consola
 *              de manera compatible tanto en sistemas Windows como en sistemas basados en Unix.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef UTILS_H
#define UTILS_H

void clearConsole();
bool readConfirmation(const std::string& message);
void pause();
int readInt(const std::string& message, const int& max = 0);
string obtenerHoraActual();
string readString(const std::string& message);

#endif
