#include <map>
#include <string>
#include <iostream>

using namespace std;

class Module {
public:
    // Получить имя модуля
    virtual string getName() const = 0;

    // Запустить модуль
    virtual void run() = 0;
};
// На этапе тестирования можете использовать следующие модули:

class ModuleA : public Module {
public:
    string getName() const {
        return "moduleA";
    }

    void run() {
        cout << "ModuleA runs" << endl;
    }
};

class ModuleB : public Module {
public:
    string getName() const {
        return "moduleB";
    }

    void run() {
        cout << "ModuleB runs" << endl;
    }
};
// Прототип требуемого диспетчера:

#include <map>
#include <string>

class Dispatcher {
public:
    // Зарегистрировать переданный модуль
    void registerModule(Module* m) {
        modules[m->getName()] = m;
    }


    // Вызвать метод run для модуля с именем moduleName
    // Если такого модуля не зарегистрировано, ничего не делать (но не падать)
    void runModule(const string moduleName) {
        auto found_module_ptr = modules.find(moduleName);
        if (found_module_ptr == modules.end()) {
            return;
        }

        found_module_ptr->second->run();
    }

private:
    std::map<std::string, Module*> modules;
};
// Для тестирования своей реализации можете использовать следующий пример:

int main()
{
    Module* m1 = new ModuleA();
    Module* m2 = new ModuleB();

    Dispatcher d;
    d.registerModule(m1);
    d.registerModule(m2);
    d.runModule("moduleA");
    d.runModule("moduleB");
    d.runModule("moduleC");

    delete m1;
    delete m2;

    return 0;
}
