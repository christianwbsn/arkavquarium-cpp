//  File: Position.hpp

#ifndef __POSITION__HPP
#define __POSITION__HPP

class Position{
    protected:
        double x;
        double y;
    public:
        Position();
        Position(double _x, double _y);
        ~Position();
        double getX();
        double getY();
        void setX(double _x);
        void setY(double _y);
};

#endif