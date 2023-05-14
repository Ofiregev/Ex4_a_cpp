#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization - Point")
{
    Point p1(1, 2), p2(2,2), p3(3,2);
    CHECK(p1.getX() == 1);
    CHECK(p1.getY() == 2);
    CHECK(p1.distance(p2) == 1);
    CHECK(p2.distance(p1) == 1);
    Point res = p1.moveTowards(p3,1);
    CHECK(res == p2);
    res = p2.moveTowards(p3,0);
    CHECK(res == p2); 
}
TEST_CASE("Test 2 - Initialization - Characters")
{
    Point p1(1, 2), p2(2,2), p3(15,20);
    Cowboy c("c", p1);
    c.setScore(0); // make him dead
    CHECK_THROWS(c.hasboolets());
    Cowboy c1("martin", p1);
    OldNinja n1("sushi", p2);
    YountNinja n2("sushika", p3);
    CHECK(n1.getScore() == 150);
    CHECK(c1.getLocation() == p1);
    CHECK(c1.getScore() == 110);
    CHECK(c1.getNumOfBullets() == 6);
    c1.hit(10);
    CHECK(c1.getScore() == 100);
    c1.shoot(&n1);
    CHECK(c1.getNumOfBullets() == 5);
    c1.reload();
    CHECK(n1.getScore() == 140);
    n1.slash(&c1); 
    n1.slash(&c1);
    n1.slash(&c1);// killed c1
    CHECK_FALSE(c1.isAlive());
    CHECK_THROWS(c1.getNumOfBullets());
    CHECK_THROWS(c1.shoot(&n2));
    n1.slash(&n2);
    CHECK(n2.getScore() == 100); // the ninja is too far
}
TEST_CASE("Test  - create and add members to a new team")
{
    Point p1(1, 2), p2(2,2), p3(15,20), p4(32,5);
    Cowboy *tom = new Cowboy("Tom", p1);
    OldNinja *sushi = new OldNinja("sushi", p2);
    YountNinja *sashimi = new YountNinja("sashimi", p3);
    Cowboy *sam = new Cowboy("sam", p4);
    Team team_test(tom);
    CHECK(team_test.stillAlive() == 1);
    team_test.add(sushi);
    team_test.add(sashimi);
    team_test.add(sam);
    CHECK(team_test.stillAlive() == 4);
    CHECK(team_test.getTeamLeader()->getName() == tom->getName());
    CHECK((team_test.getMembers()[3])->getType().name() == typeid(Ninja).name()); // ninja are after cowboys
}
TEST_CASE("Test  - attack")
{
    Point p1(1, 2), p2(2,2), p3(15,20), p4(32,5);
    Cowboy *tom = new Cowboy("Tom", p1);
    Cowboy *sam = new Cowboy("sam", p4);
    OldNinja *sushi = new OldNinja("sushi", p2);
    YountNinja *sashimi = new YountNinja("sashimi", p3);
    Cowboy *ben = new Cowboy("ben", p1);
    TrainedNinja *chai = new TrainedNinja("cahi", p2);
    YountNinja *fol = new YountNinja("fol", p3);
    Cowboy *erv = new Cowboy("erv", p1);

    Team team_a(tom);
    team_a.add(sushi);
    team_a.add(sashimi);
    team_a.add(ben);

    Team team_b(sam);
    team_b.add(fol);
    team_b.add(erv);
    team_b.add(chai);

    Character *victim = team_a.findClosestVictim(&team_b);
    CHECK(victim->getName() == "erv");

    CHECK(team_b.stillAlive() == 4);
    //team_a.print();
    team_a.attack(&team_b);
    // cout << "team_a after an attack :" << endl;
    // team_a.print();
    // cout << "team_b after an attack :" << endl;
    // team_b.print();

    team_b.attack(&team_a);

    Cowboy *asd = new Cowboy("asd", p1);
    Cowboy *dfg = new Cowboy("dfg", p4);
    OldNinja *rty = new OldNinja("rty", p2);
    Team team_c(asd);
    team_c.add(dfg);
    team_c.add(rty);
    team_a.attack(&team_c);
    CHECK(tom->getNumOfBullets() == 6); // fill after shot all bullets
    tom->setScore(0);
    ben->setLocation(Point(2,16));
    sushi->setLocation(Point(1,3));
    team_a.attack(&team_c);
    team_a.getTeamLeader()->print();    
    team_a.attack(&team_c);
    CHECK(team_a.getTeamLeader()->getName() == "sushi");



}
