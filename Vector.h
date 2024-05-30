#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

const size_t MAX_SIZE = 100;

class Vector {
private:
    double* elements;
    size_t size;

public:
    // Конструктор без параметров
    Vector();

    // Конструктор с параметром (размерность вектора)
    Vector(size_t size);

    // Конструктор копирования
    Vector(const Vector& other);

    // Конструктор перемещения
    Vector(Vector&& other) noexcept;

    // Деструктор
    ~Vector();

    // Задание размерности вектора
    bool setSize(size_t newSize);

    // Определение количества элементов заданного вектора
    size_t getSize() const;

    // Получение элемента вектора по заданному индексу
    double getElement(size_t index) const;

    // Занесение значения элемента вектора по заданному индексу
    bool setElement(size_t index, double value);

    // Операции со скаляром
    void addScalar(double scalar);
    void subtractScalar(double scalar);
    void multiplyScalar(double scalar);
    void divideScalar(double scalar);

    // Определение длины вектора
    double length() const;

    // Поэлементные операции
    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    Vector multiply(const Vector& other) const;
    Vector divide(const Vector& other) const;

    // Вывод значений элементов вектора на экран
    void print() const;

    // Ввод значений элементов вектора с клавиатуры
    void fillFromKeyboard();

    // Заполнение элементов вектора случайными числами
    void fillWithRandom();

    // Перегрузка операторов присваивания
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
};

#endif // VECTOR_H
