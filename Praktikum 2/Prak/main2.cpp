#include "Hero.cpp"
#include "Axe.cpp"
#include "Invoker.cpp"

int main() {
    Invoker i(10,1000);
    i.useSkill();
    Invoker *i2 = new Invoker(i);
    i.Hero::heal(1);
    Invoker *i3 = new Invoker(50,200);
    (*i3).Invoker::move(10,25);
    *i3 = i;
    Axe *A = new Axe(200,10);
    (*A).Axe::move(2,20);
    (*A).Axe::heal(10);
    Axe *A2 = new Axe(*A);
    Axe A3((*A2).Axe::operator+(*A));
    (*A).Axe::useSkill();
    A3.Axe::useSkill();
    delete A;
    return 0;
}