#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

namespace ariel {
    class Character {
        private:
            Point location;
            int score;
            std::string name;
            bool attacked = false;

        public:
            Character();
            Character(Point loc, int score, std::string name);
            Character(const Character &other);
            Character &operator=(const Character &other);
            Character(Character &&other) noexcept;
            Character &operator=(Character &&other) noexcept;
            virtual ~Character();
            virtual Character* createCopy() const = 0;
            void gotAttacked();
            bool getAttackedParam();
            void setAttackedParam(bool attacked);
            bool isAlive();
            double distance(Character *player);
            void hit(int points);
            std::string getName();
            Point getLocation();
            void setLocation(Point loc);
            virtual string print(); 
            int getScore();
            void setScore(int score);
            virtual const std::type_info& getType() const;
    };
}

#endif
