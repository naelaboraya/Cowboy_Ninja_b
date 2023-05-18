#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;


class Point{

private:

double x_coordinate;
double y_coordinate;


public:

//constructor 
Point(double a_coor, double b_coor);


//getters and setter

double getX() const {
    return this->x_coordinate;
}

double getY() const {
    return this->y_coordinate;
}

void setX(double new_x){
    this->x_coordinate = new_x;
}

void setY(double new_y){
    this->y_coordinate = new_y;
}


//functions:
double distance(Point other);
std::string print();
static Point moveTowards(Point source , Point dest , double distance);


};


#endif 