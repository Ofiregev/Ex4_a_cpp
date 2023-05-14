#include "Ninja.hpp"

namespace ariel {
    Ninja::Ninja(Point loc, int score, string name) : Character(loc, score, name), speed(0) {}

    void Ninja::setSpeed(int s) {
        speed = s;
    }
    const std::type_info& Ninja::getType() const {
        return typeid(Ninja);
    }

    void Ninja::move(Character* enemy) {
        Point enemy_loc = enemy->getLocation();
        double dist = distance(enemy);
        double dx = (enemy_loc.getX() - getLocation().getX()) / dist;
        double dy = (enemy_loc.getY() - getLocation().getY()) / dist;
        Point new_loc(getLocation().getX() + speed * dx, getLocation().getY() + speed * dy);
        setLocation(new_loc);
    }

    void Ninja::slash(Character* enemy) {
        if(isAlive() && distance(enemy) <= 1){
            enemy->hit(40);
        }
    }
    int Ninja::getSpeed()
    {
        return speed;
    }

    void Ninja::print() {
         if(!isAlive())
        {
            cout << "N: " << "(" << getName() << ")" << endl;
        }else{
        cout << "N: " << getName() << " at location ";
        getLocation().print();
        cout << ", with speed " << speed << " and score " << getScore() << endl;
    }
    }
}
