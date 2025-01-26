#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Сделать задержку времени чтобы проверить истёк ли срок скипассов
#include <random> // Для генерации инвентаря и тврифов скипасса случанфм образом
#include <ctime> // Для проверки истек ли срок активации скипасса и время урока с инструктором
#include "Human.h" // Класс человека, от него наследуются Adult, Child, Instructor
#include "Adult.h" // Взрослый (клиент гронолыжного курорта)
#include "Child.h" // Ребенок (является полем взрослого), самостоятельно действия не выполняет
#include "SkiPass.h" // Скипасс - это пропуск на подъёмники трасс, его заряжают в кассе(регистратуре) на определённое время, в программе есть проверка истёк ли срок
#include "Rental.h" // Прокат, тут можно получить инвентарь
#include "Registry.h" // Касса(регистратура), тут можно зарядить скипасс
#include "Instructor.h" // Инструктор, можно через инструкторскую заключить договор и получить урок с инструктором, время действия договора также ограничено и может истеч
#include "LeaseDeal.h" // Документ фиксирующий сдачу в аренду инвентаря (между клиентом и прокатом заключается)
#include "InstDeal.h" // Документ фиксирующий оказание услуги урока с инструктором (между клиентом и инструкторской заключается)
#include "SkiResort.h" // Сам горнолыжный курорт, включает в себя кассу(регистратуру), прокат, инструкторскую, клиенты взаимодействуют с курортом через этот класс
#include "InstService.h" // Инструкторская, можно получить урок с инструктором
#include "Inventory.h" // Перечисление, варианты экипировки для детей и взрослых
#include "SkiPassOption.h" // Состояния скипасса, тариф по которому он заряжен или нет
using namespace std;

// g++ main.cpp Adult.cpp Child.cpp Human.cpp InstDeal.cpp Instructor.cpp InstService.cpp LeaseDeal.cpp Registry.cpp Rental.cpp SkiPass.cpp SkiResort.cpp -o main

/*Сами все файлы собираются, ошибки не выдаёт, но при попытках вывести то что ниже ведёт себя
  очень странно, от раза в раз что то выводит, что то нет, иногда дублирует в терминале при 
  выводе какие то строки, причём даже не в том порядке, в котором они написаны */

int main(){
    setlocale(LC_ALL, "En");
    //Инициализзация курорта
    Registry* registry = new Registry();
    Rental* rental = new Rental();
    InstService* instService = new InstService();
    SkiResort* skiResort = new SkiResort("Mountain Sobolinaya", registry, rental, instService);

    //Создание клиентов
    Adult* client1 = new Adult("David");
    Adult* client2 = new Adult("Anna");
    Adult* client3 = new Adult("John");
    Child* child3 = new Child("Tonya", client3);

    //Создание инструкторов
    Instructor* instructor1 = new Instructor("Alexandr");
    Instructor* instructor2 = new Instructor("Sofia");
    Instructor* instructor3 = new Instructor("Sergey");

    //Инициализация скипассов
    SkiPass* skiPass1 = new SkiPass(client1);
    SkiPass* skiPass2 = new SkiPass(client2);
    SkiPass* skiPass3 = new SkiPass(client3);
    SkiPass* skiPass3_1 = new SkiPass(child3);
    SkiPass* skiPass4_1 = new SkiPass((Human*)instructor1);
    SkiPass* skiPass4_2 = new SkiPass((Human*)instructor2); 
    SkiPass* skiPass4_3 = new SkiPass((Human*)instructor3);

    //Добавление инструкторов в инструкторскую
    instService->addInst(instructor1, skiPass4_1);
    instService->addInst(instructor1, skiPass4_2);
    instService->addInst(instructor1, skiPass4_3);

    //Взаимодействие клиентов с курортом
    cout << "--------------------------" <<endl;

    clock_t begin = clock();

    skiResort->registry->getState();
    client1->actSkiPass(skiResort);
    Sleep(1000);
    client3->actSkiPass(skiResort);
    skiResort->registry->getState();
    Sleep(3000);
    clock_t end = clock();
    skiResort->registry->checkSkiPasses(begin, end);
    cout << "Спустя 3 секунд" << endl;
    skiResort->registry->getState();

    cout << "--------------------------" <<endl;

    client1->getInventory(skiResort);
    client2->getInventory(skiResort);
    client3->getInventory(skiResort);
    skiResort->rental->getState();

    cout << "--------------------------" <<endl;

    client1->takeInstructor(skiResort);
    Sleep(1000);
    skiResort->instService->getState();
    client2->takeInstructor(skiResort);
    client3->takeInstructor(skiResort);
    skiResort->instService->getState();
    Sleep(3000);
    skiResort->instService->getState();

    client2->returnInventory(skiResort);

    cout << "--------------------------" <<endl;

    child3->getState();
    cout << endl << "---------" << endl;
    
    return 0;
}