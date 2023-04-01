//Написать следующие функции для работы со списками
//countList - функция подсчета числа элементов
//findMax - Функция поиска максимального элемента списка
//findMin - функция поиска минимального элемента списка
//deleteDouble - функция удаления повторяющихся элементов в списке
//deleteList - функция удаления списка
//4. Список "Человек": фамилия, имя, отчество, домашний адрес, номер телефона, возраст

//дописать удаление повторяющихся элементов


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
    std::cout << "1 - добавить элемент в список\n";
    std::cout << "2 - подсчитать элементы списка\n";
    std::cout << "3 - поиск максимального возраста в списке\n";
    std::cout << "4 - поиск минимального возраста в списке\n";
    std::cout << "5 - удаление повторяющихся элементов списка\n";
    std::cout << "6 - удаление списка\n";
    std::cout << "7 - печать списка\n";
    std::cout << "8 - чтение из файла\n";
    std::cout << "9 - запись в файл\n";
    std::cout << "0 - выход из программы\n";
    std::cout << "Ваш выбор: ";
    choice = correct();
    switch (choice) {
    case 0:
        std::cout << "Работа завершена\n";
        return 0;
        break;
    case 1:
        add(first, last);
        menu();
        break;
    case 2:
        std::cout<<"Количество элементов: "<<countList(first) << std::endl;
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
        std::cout << "Неверное значение!\n";
        break;
    }
}

