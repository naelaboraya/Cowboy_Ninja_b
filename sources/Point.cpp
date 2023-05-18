#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Point::Point(double a_coor , double b_coor) : x_coordinate(a_coor) , y_coordinate(b_coor){

}

double Point::distance(Point other){
    //the distance formula :
    double distance = std::sqrt(std::pow((other.x_coordinate - this->x_coordinate),2)+std::pow((other.y_coordinate - this->y_coordinate),2));
    return distance;
}

std::string Point::print(){
    std:string info = "";
    info += std::to_string (this->x_coordinate);
    info+=" , ";
    info+=std::to_string (this->y_coordinate);
    return info;
}

Point Point::moveTowards(Point source , Point dest , double distance){
    if(distance < 0){
        throw std::invalid_argument("the distance cannot be negative!");
    }
    double dx = dest.getX() - source.getX();
        double dy = dest.getY() - source.getY();
        double currentDistance = std::sqrt(dx * dx + dy * dy);

        if (currentDistance <= distance) {
            // The destination point is already within or at most the given distance from the source point.
            return dest;
        } else {
            double ratio = distance / currentDistance;
            double newX = source.getX() + dx * ratio;
            double newY = source.getY() + dy * ratio;
            return Point(newX, newY);
        }
    }


