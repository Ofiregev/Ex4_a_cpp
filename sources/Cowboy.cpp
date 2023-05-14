#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(string name, Point location) : Character(location, 110, name), num_of_bullets(6) {}

    void Cowboy::setBullets(int bul) {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        num_of_bullets = bul;
    }
    int Cowboy::getNumOfBullets() {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        return num_of_bullets;
    }
    void Character::gotAttacked()
    {
        this->attacked = true;
    }

    void Cowboy::shoot(Character * enemy) {
        if (hasboolets() && isAlive()) {
            double dist = distance(enemy);
            enemy->hit(10);
            num_of_bullets--;
        }
        else {
            throw("cannot shoot!");
            //cout << getName() << " has no bullets left!" << endl;
        }
    }

    bool Cowboy::hasboolets() {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        return num_of_bullets > 0;
    }

    void Cowboy::reload() {
        if(!isAlive())
        {
            throw("the cowboy is dead");
        }
        num_of_bullets = 6;
    }

    void Cowboy::print() {
        if(!isAlive())
        {
            cout << "C: " << "(" << getName() << ")" << endl;
        }else{
        cout << "C: " << getName() << ", Location: ";
        getLocation().print();
        cout << ", Score: " << getScore() << ", Bullets: " << num_of_bullets << endl;
        }
    }
    const std::type_info& Cowboy::getType() const {
        return typeid(Cowboy);
    }
    

} // namespace ariel
