//  File: Position.hpp

#ifndef __POSITION__HPP
#define __POSITION__HPP

class Position{
    protected:
        double xPos;
        double yPos;
    public:
        Position();
        Position(double _x, double _y);
        ~Position();
        double getXPos() const;
        double getYPos() const;
        void setXPos(double _x);
        void setYPos(double _y);
};

#endif
