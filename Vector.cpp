
#include "Vector.h"

using namespace std;

// ����������� ��� ����������
Vector::Vector() : elements(nullptr), size(0) {}

// ����������� � ���������� (����������� �������)
Vector::Vector(size_t size) : size(size) {
    if (size > MAX_SIZE) {
        cout << "������ ��������� ����������� ����������" << endl;
        this->size = 0;
        elements = nullptr;
    }
    else {
        elements = new double[size]();
    }
}

// ����������� �����������
Vector::Vector(const Vector& other) : size(other.size) {
    elements = new double[size];
    for (size_t i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

// ����������� �����������
Vector::Vector(Vector&& other) noexcept : elements(other.elements), size(other.size) {
    other.elements = nullptr;
    other.size = 0;
}

// ����������
Vector::~Vector() {
    delete[] elements;
}

// ������� ����������� �������
bool Vector::setSize(size_t newSize) {
    if (newSize > MAX_SIZE) {
        cout << "������ ��������� ����������� ����������" << endl;
        return false;
    }
    delete[] elements;
    size = newSize;
    elements = new double[size]();
    return true;
}

// ����������� ���������� ��������� ��������� �������
size_t Vector::getSize() const {
    return size;
}

// ��������� �������� ������� �� ��������� �������
double Vector::getElement(size_t index) const {
    if (index >= size) {
        cout << "������ �� ��������� �������" << endl;
        return 0; // ���������� �������� �� ���������
    }
    return elements[index];
}

// ��������� �������� �������� ������� �� ��������� �������
bool Vector::setElement(size_t index, double value) {
    if (index >= size) {
        cout << "������ �� ��������� �������" << endl;
        return false;
    }
    elements[index] = value;
    return true;
}

// �������� �� ��������
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
        cout << "������� �� ����" << endl;
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        elements[i] /= scalar;
    }
}

// ����������� ����� �������
double Vector::length() const {
    double sum = 0.0;
    for (size_t i = 0; i < size; ++i) {
        sum += elements[i] * elements[i];
    }
    return sqrt(sum);
}

// ������������ ��������
Vector Vector::add(const Vector& other) const {
    if (size != other.size) {
        cout << "������� �������� �� ���������" << endl;
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
        cout << "������� �������� �� ���������" << endl;
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
        cout << "������� �������� �� ���������" << endl;
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
        cout << "������� �������� �� ���������" << endl;
        return Vector();
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        if (other.elements[i] == 0) {
            cout << "������� �� ����" << endl;
            result.elements[i] = 0; // �������� �� 0, ����� �������� ������� �� ����
        }
        else {
            result.elements[i] = elements[i] / other.elements[i];
        }
    }
    return result;
}

// ����� �������� ��������� ������� �� �����
void Vector::print() const {
    for (size_t i = 0; i < size; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

// ���� �������� ��������� ������� � ����������
void Vector::fillFromKeyboard() {
    for (size_t i = 0; i < size; ++i) {
        cout << "������� ������� [" << i << "]: ";
        cin >> elements[i];
    }
}

// ���������� ��������� ������� ���������� �������
void Vector::fillWithRandom() {
    for (size_t i = 0; i < size; ++i) {
        elements[i] = rand() % 10; // ��������� ���������� ����� �� 0 �� 9
    }
}

// ���������� ���������� ������������
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

