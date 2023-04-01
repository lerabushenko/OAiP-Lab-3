//�������� ��������� ������� ��� ������ �� ��������
//countList - ������� �������� ����� ���������
//findMax - ������� ������ ������������� �������� ������
//findMin - ������� ������ ������������ �������� ������
//deleteDouble - ������� �������� ������������� ��������� � ������
//deleteList - ������� �������� ������
//4. ������ "�������": �������, ���, ��������, �������� �����, ����� ��������, �������

//�������� �������� ������������� ���������


#include"functions.h"

int menu();

Node* first=NULL;
Node* last = NULL;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
}

int menu()
{
    int choice;
    std::cout<<std::endl;
    std::cout << "1 - �������� ������� � ������\n";
    std::cout << "2 - ���������� �������� ������\n";
    std::cout << "3 - ����� ������������� �������� � ������\n";
    std::cout << "4 - ����� ������������ �������� � ������\n";
    std::cout << "5 - �������� ������������� ��������� ������\n";
    std::cout << "6 - �������� ������\n";
    std::cout << "7 - ������ ������\n";
    std::cout << "8 - ������ �� �����\n";
    std::cout << "9 - ������ � ����\n";
    std::cout << "0 - ����� �� ���������\n";
    std::cout << "��� �����: ";
    choice = correct();
    switch (choice) {
    case 0:
        std::cout << "������ ���������\n";
        return 0;
        break;
    case 1:
        add(first, last);
        menu();
        break;
    case 2:
        std::cout<<"���������� ���������: "<<countList(first) << std::endl;
        menu();
        break;
    case 3:
        findMax(first);
        menu();
        break;
    case 4:
        findMin(first);
        menu();
        break;
    case 5:
        deleteDouble(first);
        menu();
        break;
    case 6:
        deleteList(first);
        menu();
        break;
    case 7:
        printList(first);
        menu();
        break;
    case 8:
        readFromFile(first, last);
        menu();
        break;
    case 9:
        writeToFile(first);
        menu();
        break;
    default: 
        std::cout << "�������� ��������!\n";
        break;
    }
}

