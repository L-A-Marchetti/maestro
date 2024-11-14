#include "../include/maestro.h"

int main()
{
    typedef struct {
        int age;
        const char* name;
    } human;
    human lucas = {14, "Lucas"};
    human mathias = {35, "Mathias"};
    human marie = {18, "Marie"};
    human pascal = {11, "Pascal"};
    maestro* humans = maestro_new(sizeof(human));
    humans->push_back(humans, &lucas);
    humans->push_back(humans, &mathias);
    humans->push_back(humans, &marie);
    humans->pop_back(humans);
    humans->insert(humans, 1, &marie);
    humans->push_back(humans, &pascal);
    humans->erase(humans, 2);
    for (size_t i = 0; i < humans->length; i++) {
    printf("age: %d, name: %s\n", 
           ((human*)humans->data)[i].age,
           ((human*)humans->data)[i].name);
}
    humans->destroy(humans);
    return 0;
}