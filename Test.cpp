#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;


TEST_CASE("Distance method") {
    Point p1(0, 0);
    Point p2(5, 5);
    Point n1(-3, 2);
    Point n2(1, -8);
    Point n3(-2, -2);

    CHECK_EQ(p1.distance(p2), doctest::Approx(7.07107).epsilon(0.0001));
    CHECK_EQ(p2.distance(p1), doctest::Approx(7.07107).epsilon(0.0001));
    CHECK_EQ(n1.distance(n2), doctest::Approx(10.7703).epsilon(0.0001));
    CHECK_EQ(n2.distance(n1), doctest::Approx(10.7703).epsilon(0.0001));
    CHECK_EQ(n3.distance(p1), doctest::Approx(2.82843).epsilon(0.0001));
    CHECK_EQ(p1.distance(n3), doctest::Approx(2.82843).epsilon(0.0001));
    CHECK_EQ(n2.distance(p1), doctest::Approx(8.06226).epsilon(0.0001));
}

TEST_CASE("Testing young ninja") {
    YoungNinja ninja{"YN", Point{4, 5}};

    CHECK_EQ(ninja.getName(), "YN");
    CHECK_EQ(ninja.getLocation().distance(Point{4, 5}), 0);
    CHECK_NE(ninja.getLocation().distance(Point{3, 2}), 0);

    CHECK(ninja.isAlive());
}

TEST_CASE("Testing Trained ninja") {
    TrainedNinja ninja{"TN", Point{4, 5}};

    CHECK_EQ(ninja.getName(), "TN");
    CHECK_EQ(ninja.getLocation().distance(Point{4, 5}), 0);
    CHECK(ninja.getLocation().print()=="4.000000 , 5.000000");
    CHECK_NE(ninja.getLocation().distance(Point{3, 2}), 0);

    CHECK(ninja.isAlive());
}


TEST_CASE("Testing Old ninja") {
    OldNinja ninja{"ON", Point{4, 5}};

    CHECK_EQ(ninja.getName(), "ON");
    CHECK_EQ(ninja.getLocation().distance(Point{4, 5}), 0);
    CHECK(ninja.getLocation().print()=="4.000000 , 5.000000");
    CHECK_NE(ninja.getLocation().distance(Point{3, 2}), 0);

    CHECK(ninja.isAlive());
}

TEST_CASE("Testing Cowboy") {
    Cowboy cowboy{"CB", Point{10, 5}};
    CHECK(cowboy.hasboolets());
    CHECK_EQ(cowboy.getName(), "CB");
    CHECK_EQ(cowboy.getLocation().distance(Point{10, 5}), 0);
    CHECK_NE(cowboy.getLocation().distance(Point{3, 2}), 0);

    CHECK(cowboy.isAlive());
 }

TEST_CASE("Testing eam"){
    Cowboy* cowboy = new Cowboy( "CB" ,Point(2, 3));
    Team team{cowboy};
    CHECK_EQ(team.stillAlive(), 1);

}