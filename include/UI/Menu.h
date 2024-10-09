/*
 * Archivo: Menu.h
 * Descripci�n: Declaraci�n de la clase Menu, que proporciona una interfaz para manejar
 *              men�s interactivos en consola. Incluye m�todos para agregar opciones,
 *              mostrar el men� y obtener la selecci�n del usuario.
 *
 * Autor(es): Mauricio Gonzalez
 */

#pragma once

#include <iostream>
#include "Estructuras/Concretas/ArrayList.h"

using std::string;

class Menu {
private:
    ArrayList<string> options;
    std::string title;

public:
    Menu(const string& title);
    void addOption(const string& option);
    void display(const string& message = "Seleccione una opci�n: ");
    int getSelection();
};
