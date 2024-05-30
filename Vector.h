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
    // ����������� ��� ����������
    Vector();

    // ����������� � ���������� (����������� �������)
    Vector(size_t size);

    // ����������� �����������
    Vector(const Vector& other);

    // ����������� �����������
    Vector(Vector&& other) noexcept;

    // ����������
    ~Vector();

    // ������� ����������� �������
    bool setSize(size_t newSize);

    // ����������� ���������� ��������� ��������� �������
    size_t getSize() const;

    // ��������� �������� ������� �� ��������� �������
    double getElement(size_t index) const;

    // ��������� �������� �������� ������� �� ��������� �������
    bool setElement(size_t index, double value);

    // �������� �� ��������
    void addScalar(double scalar);
    void subtractScalar(double scalar);
    void multiplyScalar(double scalar);
    void divideScalar(double scalar);

    // ����������� ����� �������
    double length() const;

    // ������������ ��������
    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    Vector multiply(const Vector& other) const;
    Vector divide(const Vector& other) const;

    // ����� �������� ��������� ������� �� �����
    void print() const;

    // ���� �������� ��������� ������� � ����������
    void fillFromKeyboard();

    // ���������� ��������� ������� ���������� �������
    void fillWithRandom();

    // ���������� ���������� ������������
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
};

#endif // VECTOR_H
