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

    string Cowboy::print() {
        if(!isAlive())
        {
            return "C: (" + getName() + ")" ;
        }else{

        return "C: " + getName() + ", Location: " + getLocation().print()+ ", Score: " + std::to_string(getScore()) + ", Bullets: " + std::to_string(num_of_bullets) ;
        }
    }
    const std::type_info& Cowboy::getType() const {
        return typeid(Cowboy);
    }
    

} // namespace ariel
