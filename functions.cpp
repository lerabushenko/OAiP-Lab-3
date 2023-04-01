#include"functions.h"


void add(Node*& first, Node*& last)
{
    int choice = true;
    do {
        Node* newPerson = new Node;
        system("cls");
        std::cout << "������� �������: ";
        std::cin.getline(newPerson->onePerson.surname, 10);
        std::cout << "������� ���: ";
        std::cin.getline(newPerson->onePerson.name, 10);
        std::cout << "������� ��������: ";
        std::cin.getline(newPerson->onePerson.patronimic, 10);
        std::cout << "������� �����: ";
        std::cin.getline(newPerson->onePerson.adres, 20);
        std::cout << "������� ����� ��������: ";
        std::cin.getline(newPerson->onePerson.phoneNumber, 13);
        std::cout << "������� �������: ";
        newPerson->onePerson.age=correct();
        newPerson->next = NULL;
        if (first == NULL)
        {
            first = last = newPerson;
        }
        else {
            last->next = newPerson;
            last = newPerson;
        }
        system("cls");
        std::cout << "������� ����������?\n0 - ���\n����� ������ ����� - ��\n";
        std::cout << "��� �����:";
        choice = correct();
    } while (choice);
}

void printList(Node * first)
{
    if (countList(first) == 0) {
        std::cout << "������ ����\n";
    }
    else {
        system("cls");
        std::cout <<std::left<< std::setw(10) << "�������" << std::setw(10) << "���" << std::setw(15) << "��������" 
            << std::setw(20) << "�����"<< std::setw(13) << "�������" << std::setw(5) << "�������"<<std::endl;
        Node* current = first;
        while (current != NULL) {
            std::cout << std::left << std::setw(10) << current->onePerson.surname << std::setw(10) << current->onePerson.name 
                << std::setw(15) << current->onePerson.patronimic << std::setw(20) << current->onePerson.adres
                << std::setw(13) << current->onePerson.phoneNumber << std::setw(5) << current->onePerson.age<<std::endl;
            current = current->next;
        }
    }
}

int correct()
{
    bool IsCorrect;
    int number;
    do {
        IsCorrect = true;
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            IsCorrect = false;
            std::cout << "������!\n";
        }
        if (IsCorrect && std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');

            std::cout << "������!\n";
            IsCorrect = false;
        }
    } while (!IsCorrect);
    return number;
}

int countList(Node* first) {
        int ammount = 0;
        Node* current = first;
        while (current != NULL) {
            ammount++;
            current = current->next;
        }
        return ammount;
}

void findMax(Node * first) {
    if (countList(first) == 0) {
        std::cout << "������ ����\n";
    }
    else{
        Node* current = first;
        Node* max = first;
        while (current != NULL) {
            if (current->onePerson.age > max->onePerson.age) {
                max = current;
            }
            current = current->next;
        }
        system("cls");
        std::cout << "������������ ������� � ������:\n";
        std::cout << std::left << std::setw(10) << max->onePerson.surname << std::setw(10) << max->onePerson.name
            << std::setw(15) << max->onePerson.patronimic << std::setw(20) << max->onePerson.adres
            << std::setw(13) << max->onePerson.phoneNumber << std::setw(5) << max->onePerson.age << std::endl;
    }
   }

void findMin(Node*first) {
    if (countList(first) == 0) {
        std::cout << "������ ����\n";
    }
    else {
        Node* current = first;
        Node* min = first;
        while (current != NULL) {
            if (current->onePerson.age < min->onePerson.age) {
                min = current;
            }
            current = current->next;
        }
        system("cls");
        std::cout << "����������� ������� � ������:\n";
        std::cout << std::left << std::setw(10) << min->onePerson.surname << std::setw(10) << min->onePerson.name
            << std::setw(15) << min->onePerson.patronimic << std::setw(20) << min->onePerson.adres
            << std::setw(13) << min->onePerson.phoneNumber << std::setw(5) << min->onePerson.age << std::endl;
    }
}

void deleteDouble(Node* first)
{
    if (countList(first) == 0) {
        std::cout << "������ ����\n";
    }
    else {
        Node* current = first;
        while (current != NULL) {
            Node* temp = current;
            while (temp->next != NULL) {
                if (strcmp(current->onePerson.surname, temp->next->onePerson.surname)==0 &&
                    strcmp(current->onePerson.name, temp->next->onePerson.name)==0 &&
                    strcmp(current->onePerson.patronimic,temp->next->onePerson.patronimic)==0 &&
                    strcmp(current->onePerson.adres, temp->next->onePerson.adres)==0 &&
                    strcmp(current->onePerson.phoneNumber, temp->next->onePerson.phoneNumber)==0 &&
                    current->onePerson.age== temp->next->onePerson.age) {
                    Node* toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                }
                else {
                    temp = temp->next;
                }

            }
            current = current->next;
        }
        std::cout << "�������� ������� ���������\n";
    }
}

void deleteList(Node*&first) {
    Node* temp;
    while (first!=NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
    std::cout << "������ ����\n";
}

void writeToFile(Node* first)
{
    if (countList(first) == 0) {
        std::cout << "������ ����\n";
    }
    else {
        std::ofstream fout("person.dat");
        if (!fout.is_open())
        {
            std::cout << "�� ������� ������� ����\n";
            return;
        }
        Node* current = first;
        while (current != NULL) {
            fout << current->onePerson.surname << "\n" << current->onePerson.name << "\n" << current->onePerson.patronimic
                << "\n" << current->onePerson.adres << "\n" << current->onePerson.phoneNumber << "\n" << current->onePerson.age << "\n";
            current = current->next;
        }
        fout.close();
        std::cout << "������ ������� �������� � ����\n";
    }
}

void readFromFile(Node*&first, Node*&last) {
    std::ifstream fin("person.dat");
    if (!fin.is_open()) {
        std::cout << "���� �� ������!\n";
        return;
    }
    while (!fin.eof())
    {
        Node* temp = new Node;
        fin >> temp->onePerson.surname;
        fin >> temp->onePerson.name;
        fin >> temp->onePerson.patronimic;
        fin >> temp->onePerson.adres;
        fin >> temp->onePerson.phoneNumber;
        fin >> temp->onePerson.age;
        temp->next = NULL;
        if (first == NULL)
        {
            first = last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
    }
    fin.close();
    std::cout << "�������� ������� ���������!\n\n";
}