#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <string>
#include <array>
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YountNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;

namespace ariel {
constexpr int MAX_MEMBERS = 10;
    class Team {
        
        private:
            std::array<Character*, MAX_MEMBERS> members;
            Character* team_leader;

        public:
            Team(Character* leader);
            Team(const Team& other);
            Team& operator=(const Team& other);
            Team(Team&& other) noexcept;
            Team& operator=(Team&& other) noexcept;
            virtual ~Team();

            virtual void add(Character* warrior);
            std::array<Character*, MAX_MEMBERS> getMembers() const;
            void sortByType();
            void attack(Team* enemies);
            size_t findClosestLivingMemberIndex() ;
            Character* getTeamLeader();
            // void findClosestTeamLeader();
            Character* findClosestLivingMember();
            int didNotAttacked();
            void setAttackedParam();
            Character* findClosestVictim(Team* enemies);
            void killVictim(Team* enemies);
            bool isCowboy(Character* warrior);
            bool isNinja(Character* warrior);
            int stillAlive();
            virtual void print();
    };

}

#endif