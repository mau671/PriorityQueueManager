/*
 * Archivo: KVPair.h
 * Descripción: Este archivo contiene la implementación de la plantilla de clase KVPair,
 *              que representa un par clave-valor. La clase incluye operadores sobrecargados
 *              para comparar pares y asignar valores. Además, permite imprimir el par
 *              clave-valor a un flujo de salida.
 *
 * Autor(es): Profesor Mauricio Aviles Cisneros
 */

#pragma once
#include <iostream>
using std::ostream;

template <typename K, typename V>
class KVPair {
public:
    K key;
    V value;

    KVPair() { }

    KVPair(K key) {
        this->key = key;
    }

    KVPair(K key, V value) {
        this->key = key;
        this->value = value;
    }

    void operator=(const KVPair<K, V>& other) {
        this->key = other.key;
        this->value = other.value;
    }

    bool operator==(const KVPair<K, V>& other) {
        return this->key == other.key;
    }

    bool operator!=(const KVPair<K, V>& other) {
        return this->key != other.key;
    }

    bool operator<(const KVPair<K, V>& other) {
        return this->key < other.key;
    }

    bool operator<=(const KVPair<K, V>& other) {
        return this->key <= other.key;
    }

    bool operator>(const KVPair<K, V>& other) {
        return this->key > other.key;
    }

    bool operator>=(const KVPair<K, V>& other) {
        return this->key >= other.key;
    }
};

template <typename K, typename V>
ostream& operator<<(ostream& os, const KVPair<K, V>& pair) {
    os << "(" << pair.key << ", " << pair.value << ")";
    return os;
}
