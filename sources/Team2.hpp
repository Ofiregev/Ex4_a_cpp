#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {
        private:
        std::array<Character*, MAX_MEMBERS> members;
        Character* team_leader;
    public:
        Team2(Character* leader);
        void add(Character* warrior) override;
        void print() override;
        const std::array<Character*, MAX_MEMBERS> getMembers() const override;
    };
}

#endif // TEAM2_HPP
