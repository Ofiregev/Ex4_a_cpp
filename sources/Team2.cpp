#include "Team2.hpp"

namespace ariel {

    Team2::Team2(Character* leader) : Team(leader) {
        if (leader == nullptr) {
            throw std::invalid_argument("Leader cannot be null");
        }
        getMembers().fill(nullptr);
        add(leader); // Add the team leader as the first member of the team
    }

    void Team2::add(Character* warrior) {
        if (warrior == nullptr) {
            return;
        }
        // Add character to next available slot
        size_t i = 0;
        while (i < MAX_MEMBERS &&  getMembers()[i]) {
            i++;
        }
        if (i < MAX_MEMBERS) {
            getMembers()[i] = warrior;
        }
        print();
    }
    //  void Team2::print()
    // {
    //     cout << "The team leader is " << team_leader->getName() << "." << endl;
    //     cout << "The members of the team are:" << endl;
    //     for (size_t i = 0; i < 10; i++)
    //     {
    //         if (members[i])
    //         {
    //             cout << members[i]->print() << endl;
    //         }
    //     }
    // }
    // const std::array<Character*, MAX_MEMBERS> Team2::getMembers() const 
    // {
    //     return members;
    // }
    // int Team2::stillAlive()
    // {
        
    //     int count = 0;
    //     for (size_t i = 0; i < 10; i++)
    //     {
    //         if (members[i] && members[i]->isAlive())
    //         {
    //             count++;
    //         }
    //     }
    //     return count;
    // }



}
