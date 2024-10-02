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
#include "ArrayList.h"

class Menu {
private:
    ArrayList<std::string> options;
    std::string title;

public:
    Menu(const std::string& title);
    void addOption(const std::string& option);
    void display();
    int getSelection();
};
