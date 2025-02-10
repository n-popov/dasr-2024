class ZooKeeper {
public:
    // Создаём смотрителя зоопарка
    ZooKeeper(): dangerous_count(0) {}

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a) {
        if (a->isDangerous()) dangerous_count++;
    }

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount() {
        return dangerous_count;
    }
private:
    int dangerous_count;
};
