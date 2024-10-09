/*
 * Archivo: Menu.h
 * Descripción: Declaración de la clase Menu, que proporciona una interfaz para manejar
 *              menús interactivos en consola. Incluye métodos para agregar opciones,
 *              mostrar el menú y obtener la selección del usuario.
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
    void display(const string& message = "Seleccione una opción: ");
    int getSelection();
};
