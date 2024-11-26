#include <iostream>
using namespace std;
struct Unit
{
    char letter;
    Unit* next;
    Unit* prev;
};
void Distort(Unit* u)
{
    int s, t;
    cin >> s >> t;
    for (int i = 0; i < abs(s); i++) u = (s > 0) ? u->next : u->prev;
    Unit* y = u;
    for (int i = 0; i < abs(t); i++) y = (t > 0) ? y->next : y->prev;
    if ((s + t) % 2 == 0)
        u->next = y;
    else
        u->prev = y;
}

void Fix(Unit* u) {
    auto curr = u->next;
    auto curr_2x = u->next->next;
    auto i = 1;
    for (;curr != curr_2x; i++) {
        curr = curr->next;
        curr_2x = curr_2x->next->next;
    }

    auto size_next = -1;
    if (curr == u) {
        size_next = i;
    }

    curr = u->prev;
    curr_2x = u->prev->prev;
    i = 1;
    for (;curr != curr_2x; i++) {
        curr = curr->prev;
        curr_2x = curr_2x->prev->prev;
    }

    auto size_prev = -1;
    if (curr == u) {
        size_prev = i;
    }

    curr = u;
    if (size_next > size_prev) {
        for (i = 0; i < size_next; i++) {
            curr->next->prev = curr;
            curr = curr->next;
        }
    } else {
        for (i = 0; i < size_prev; i++) {
            curr->prev->next = curr;
            curr = curr->prev;
        }
    }
}
// ваш код будет здесь
void Clean (Unit* u)
{
    if (!u) return;
    u->prev->next = NULL;
    Unit *c = u, *t = u;
    while (c)
    {
        c = c->next;
        delete t;
        t = c;
    }
}
int main()
{
    Unit* unit0 = NULL;
    Unit* unit = NULL;
    int count = 0;
    while (true)
    {
        char c = cin.get();
        if ((c == ' ') || (c== '\n')) break;
        Unit* new_unit = new Unit;
        new_unit->letter = c;
        if (unit != NULL)
        {
            new_unit->prev = unit;
            unit->next = new_unit;
        }
        else
            unit0 = new_unit;
        unit = new_unit;
        count++;
    }
    unit0->prev = unit;
    unit->next = unit0;

    Distort(unit);
    Fix(unit);
    for (int i = 0; i < count + 1; i++)
    {
        unit = unit->next;
        cout << unit->letter;
    }
    cout << endl;
    for (int i = 0; i < count + 1; i++)
    {
        cout << unit->letter;
        unit = unit->prev;
    }
    Clean(unit);
    return 0;
}
