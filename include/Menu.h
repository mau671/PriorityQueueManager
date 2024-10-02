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
