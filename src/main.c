#include "../include/maestro.h"

int main()
{
    typedef struct {
        int age;
        const char* name;
    } human;
    human lucas = {14, "Lucas"};
    human mathias = {35, "Mathias"};
    maestro* humans = maestro_new(sizeof(human));
    humans->append(humans, &lucas);
    humans->append(humans, &mathias);
    for (size_t i = 0; i < humans->length; i++) {
    printf("age: %d, name: %s\n", 
           ((human*)humans->data)[i].age,
           ((human*)humans->data)[i].name);
}
    humans->erase(humans);
    return 0;
}