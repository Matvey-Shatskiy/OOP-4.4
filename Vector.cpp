
#include "Vector.h"

using namespace std;

// Конструктор без параметров
Vector::Vector() : elements(nullptr), size(0) {}

// Конструктор с параметром (размерность вектора)
Vector::Vector(size_t size) : size(size) {
    if (size > MAX_SIZE) {
        cout << "Размер превышает максимально допустимый" << endl;
        this->size = 0;
        elements = nullptr;
    }
    else {
        elements = new double[size]();
    }
}

// Конструктор копирования
Vector::Vector(const Vector& other) : size(other.size) {
    elements = new double[size];
    for (size_t i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

// Конструктор перемещения
Vector::Vector(Vector&& other) noexcept : elements(other.elements), size(other.size) {
    other.elements = nullptr;
    other.size = 0;
}

// Деструктор
Vector::~Vector() {
    delete[] elements;
}

// Задание размерности вектора
bool Vector::setSize(size_t newSize) {
    if (newSize > MAX_SIZE) {
        cout << "Размер превышает максимально допустимый" << endl;
        return false;
    }
    delete[] elements;
    size = newSize;
    elements = new double[size]();
    return true;
}

// Определение количества элементов заданного вектора
size_t Vector::getSize() const {
    return size;
}

// Получение элемента вектора по заданному индексу
double Vector::getElement(size_t index) const {
    if (index >= size) {
        cout << "Индекс за пределами вектора" << endl;
        return 0; // Возвращаем значение по умолчанию
    }
    return elements[index];
}

// Занесение значения элемента вектора по заданному индексу
bool Vector::setElement(size_t index, double value) {
    if (index >= size) {
        cout << "Индекс за пределами вектора" << endl;
        return false;
    }
    elements[index] = value;
    return true;
}

// Операции со скаляром
void Vector::addScalar(double scalar) {
    for (size_t i = 0; i < size; ++i) {
        elements[i] += scalar;
    }
}

void Vector::subtractScalar(double scalar) {
    for (size_t i = 0; i < size; ++i) {
        elements[i] -= scalar;
    }
}

void Vector::multiplyScalar(double scalar) {
    for (size_t i = 0; i < size; ++i) {
        elements[i] *= scalar;
    }
}

void Vector::divideScalar(double scalar) {
    if (scalar == 0) {
        cout << "Деление на ноль" << endl;
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        elements[i] /= scalar;
    }
}

// Определение длины вектора
double Vector::length() const {
    double sum = 0.0;
    for (size_t i = 0; i < size; ++i) {
        sum += elements[i] * elements[i];
    }
    return sqrt(sum);
}

// Поэлементные операции
Vector Vector::add(const Vector& other) const {
    if (size != other.size) {
        cout << "Размеры векторов не совпадают" << endl;
        return Vector();
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

Vector Vector::subtract(const Vector& other) const {
    if (size != other.size) {
        cout << "Размеры векторов не совпадают" << endl;
        return Vector();
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

Vector Vector::multiply(const Vector& other) const {
    if (size != other.size) {
        cout << "Размеры векторов не совпадают" << endl;
        return Vector();
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result.elements[i] = elements[i] * other.elements[i];
    }
    return result;
}

Vector Vector::divide(const Vector& other) const {
    if (size != other.size) {
        cout << "Размеры векторов не совпадают" << endl;
        return Vector();
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        if (other.elements[i] == 0) {
            cout << "Деление на ноль" << endl;
            result.elements[i] = 0; // Заменяем на 0, чтобы избежать деления на ноль
        }
        else {
            result.elements[i] = elements[i] / other.elements[i];
        }
    }
    return result;
}

// Вывод значений элементов вектора на экран
void Vector::print() const {
    for (size_t i = 0; i < size; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

// Ввод значений элементов вектора с клавиатуры
void Vector::fillFromKeyboard() {
    for (size_t i = 0; i < size; ++i) {
        cout << "Введите элемент [" << i << "]: ";
        cin >> elements[i];
    }
}

// Заполнение элементов вектора случайными числами
void Vector::fillWithRandom() {
    for (size_t i = 0; i < size; ++i) {
        elements[i] = rand() % 10; // Генерация случайного числа от 0 до 9
    }
}

// Перегрузка операторов присваивания
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new double[size];
        for (size_t i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] elements;
        elements = other.elements;
        size = other.size;
        other.elements = nullptr;
        other.size = 0;
    }
    return *this;
}

