#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    // 1. Конструктор без параметров
    Vector v1; // Создает пустой вектор 
    cout << "Вектор v1 (пустой): ";
    v1.print();

    // 2. Конструктор с размером
    Vector v2(3); // Создает вектор размера 3
    cout << "Вектор v2 (размер 3): ";
    v2.print();

    // 3. Заполнение с клавиатуры
    cout << "Введите элементы для вектора v2: " << endl;
    v2.fillFromKeyboard();
    cout << "Вектор v2 (после заполнения с клавиатуры): ";
    v2.print();

    // 4. Заполнение случайными числами
    Vector v3(5); // Создает вектор размера 5
    v3.fillWithRandom();
    cout << "Вектор v3 (случайные числа): ";
    v3.print();

    // 5. Конструктор копирования
    Vector v4(v3); // Создает копию вектора v3
    cout << "Вектор v4 (копия v3): ";
    v4.print();

    // 6. Конструктор перемещения (move constructor)
    Vector v5 = std::move(v4); // Перемещает данные из v4 в v5 
    cout << "Вектор v5 (перемещен из v4): ";
    v5.print();
    cout << "Вектор v4 (пустой после перемещения): ";
    v4.print();

    // 7. Изменение размера вектора
    if (v5.setSize(7)) { // Изменяет размер v5 на 7
        cout << "Вектор v5 (новый размер 7): ";
        v5.print();
    }

    // 8. Получение элемента по индексу
    cout << "Элемент v5[2]: " << v5.getElement(2) << endl;

    // 9. Установка элемента по индексу
    v5.setElement(4, 10.5);
    cout << "Вектор v5 (элемент 4 изменен): ";
    v5.print();

    // 10. Операции со скаляром
    v5.addScalar(2.0); // Добавляет 2.0 к каждому элементу 
    cout << "Вектор v5 (добавлено 2.0 к каждому элементу): ";
    v5.print();

    v5.multiplyScalar(0.5); // Умножает каждый элемент на 0.5
    cout << "Вектор v5 (умножено на 0.5): ";
    v5.print();

    // 11. Определение длины
    cout << "Длина вектора v5: " << v5.length() << endl;

    // 12. Поэлементные операции 
    Vector v6(3);
    v6.fillWithRandom();
    cout << "Вектор v6: ";
    v6.print();

    Vector v7 = v5.add(v6); // Сложение векторов
    cout << "Вектор v7 (сумма v5 и v6): ";
    v7.print();

    Vector v8 = v5.subtract(v6); // Вычитание векторов
    cout << "Вектор v8 (разность v5 и v6): ";
    v8.print();

    // 13. Перегрузка оператора присваивания
    Vector v9;
    v9 = v8; // Копирование вектора v8 в v9
    cout << "Вектор v9 (копия v8): ";
    v9.print();

    // 14. Создание и заполнение векторов X и Y (из вашего исходного кода)
    Vector X(5);
    X.fillWithRandom();
    cout << "Вектор X: ";
    X.print();

    Vector Y(7);
    Y.fillWithRandom();
    cout << "Вектор Y: ";
    Y.print();

    // Определение вектора с минимальной длиной
    double lengthX = X.length();
    double lengthY = Y.length();

    if (lengthX < lengthY) {
        cout << "Вектор X имеет меньшую длину: " << lengthX << endl;
    }
    else {
        cout << "Вектор Y имеет меньшую длину: " << lengthY << endl;
    }

    return 0;
}