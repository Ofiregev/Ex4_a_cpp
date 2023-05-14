#include "Character.hpp"

namespace ariel
{
    Character::Character(Point loc, int score, string name) : location(loc), score(score), name(name) {}
    
    Character& Character::operator=(const Character &other) {
        if (this != &other) {
            location = other.location;
            score = other.score;
            name = other.name;
        }
        return *this;
    }

    Character::Character(const Character& other) : location(other.location), score(other.score), name(other.name) {}

    Character::Character(Character &&other) noexcept : location(std::move(other.location)), score(std::move(other.score)), name(std::move(other.name)) {}

    Character& Character::operator=(Character &&other) noexcept {
        if (this != &other) {
            location = std::move(other.location);
            score = std::move(other.score);
            name = std::move(other.name);
        }
        return *this;
    }
    
    bool Character::isAlive()
    {
        return score > 0;
    }

    double Character::distance(Character *player)
    {
        return location.distance(player->location);
    }

    void Character::hit(int points)
    {
        score = score - points;
    }

    string Character::getName()
    {
        return name;
    }

    Point Character::getLocation()
    {
        return location;
    }
    void Character::setLocation(Point loc)
    {
        location = loc;
    }

    void Character::print()
    {
        if(!isAlive())
        {
            cout << "Name: (" << name << ")";
        }
        cout << "Name: " << name << ", Score: " << score << ", Location: (" << location.getX() << "," << location.getY() << ")" << endl;
    }
    bool Character::getAttackedParam()
    {
        return attacked;
    }
    void Character::setAttackedParam()
    {
        this->attacked = false;
    }
  

    int Character::getScore()
    {
        return score;
    }
    void Character::setScore(int s)
    {
        this->score = s;   
     }
    const std::type_info& Character::getType() const {
        return typeid(Character);
    }
     Character::~Character() = default;

    //Character::Character(const Character&) = default;

    //Character& Character::operator=(const Character&) = default;

    //Character::Character(Character&&) noexcept = default;

    //Character& Character::operator=(Character&&) noexcept = default;


} // namespace ariel

