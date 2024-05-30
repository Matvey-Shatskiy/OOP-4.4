#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    // 1. ����������� ��� ����������
    Vector v1; // ������� ������ ������ 
    cout << "������ v1 (������): ";
    v1.print();

    // 2. ����������� � ��������
    Vector v2(3); // ������� ������ ������� 3
    cout << "������ v2 (������ 3): ";
    v2.print();

    // 3. ���������� � ����������
    cout << "������� �������� ��� ������� v2: " << endl;
    v2.fillFromKeyboard();
    cout << "������ v2 (����� ���������� � ����������): ";
    v2.print();

    // 4. ���������� ���������� �������
    Vector v3(5); // ������� ������ ������� 5
    v3.fillWithRandom();
    cout << "������ v3 (��������� �����): ";
    v3.print();

    // 5. ����������� �����������
    Vector v4(v3); // ������� ����� ������� v3
    cout << "������ v4 (����� v3): ";
    v4.print();

    // 6. ����������� ����������� (move constructor)
    Vector v5 = std::move(v4); // ���������� ������ �� v4 � v5 
    cout << "������ v5 (��������� �� v4): ";
    v5.print();
    cout << "������ v4 (������ ����� �����������): ";
    v4.print();

    // 7. ��������� ������� �������
    if (v5.setSize(7)) { // �������� ������ v5 �� 7
        cout << "������ v5 (����� ������ 7): ";
        v5.print();
    }

    // 8. ��������� �������� �� �������
    cout << "������� v5[2]: " << v5.getElement(2) << endl;

    // 9. ��������� �������� �� �������
    v5.setElement(4, 10.5);
    cout << "������ v5 (������� 4 �������): ";
    v5.print();

    // 10. �������� �� ��������
    v5.addScalar(2.0); // ��������� 2.0 � ������� �������� 
    cout << "������ v5 (��������� 2.0 � ������� ��������): ";
    v5.print();

    v5.multiplyScalar(0.5); // �������� ������ ������� �� 0.5
    cout << "������ v5 (�������� �� 0.5): ";
    v5.print();

    // 11. ����������� �����
    cout << "����� ������� v5: " << v5.length() << endl;

    // 12. ������������ �������� 
    Vector v6(3);
    v6.fillWithRandom();
    cout << "������ v6: ";
    v6.print();

    Vector v7 = v5.add(v6); // �������� ��������
    cout << "������ v7 (����� v5 � v6): ";
    v7.print();

    Vector v8 = v5.subtract(v6); // ��������� ��������
    cout << "������ v8 (�������� v5 � v6): ";
    v8.print();

    // 13. ���������� ��������� ������������
    Vector v9;
    v9 = v8; // ����������� ������� v8 � v9
    cout << "������ v9 (����� v8): ";
    v9.print();

    // 14. �������� � ���������� �������� X � Y (�� ������ ��������� ����)
    Vector X(5);
    X.fillWithRandom();
    cout << "������ X: ";
    X.print();

    Vector Y(7);
    Y.fillWithRandom();
    cout << "������ Y: ";
    Y.print();

    // ����������� ������� � ����������� ������
    double lengthX = X.length();
    double lengthY = Y.length();

    if (lengthX < lengthY) {
        cout << "������ X ����� ������� �����: " << lengthX << endl;
    }
    else {
        cout << "������ Y ����� ������� �����: " << lengthY << endl;
    }

    return 0;
}