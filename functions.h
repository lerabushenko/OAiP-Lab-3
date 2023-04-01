#pragma once

#include<iostream>
#include<string>
#include<windows.h>
#include<iomanip>
#include<fstream>

struct Person         //список
{
	char surname[10];
	char name[10];
	char patronimic[10];
	char adres[20];
	char phoneNumber[13];
	int age;
};

struct Node {
	Person onePerson;
	Node* next;
};

void add(Node*& first, Node*& last);         //добавление элемента
int countList(Node* first);
void findMax(Node*first);
void findMin(Node*first);
void deleteDouble(Node*first);
void deleteList(Node*&first);
void printList(Node * first);     //печать листа
int correct();       //проверка на ввод
int menu();     //меню
void readFromFile(Node*&first, Node*&last);
void writeToFile(Node*first);
