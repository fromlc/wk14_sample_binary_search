//------------------------------------------------------------------------------
// Circle class declaration and definition
//------------------------------------------------------------------------------
#ifndef CIRCLE_H
#define CIRCLE_H

#include <ostream>

//------------------------------------------------------------------------------
// Circle
//------------------------------------------------------------------------------
class Circle
{
private:
    int radius;

    friend std::ostream& operator<<(std::ostream& os, const Circle& c);

public:
    // constructor
    Circle(int r) : radius(r) { }

    // getter
    int getRadius() const { return radius; }

    // overload operator ==
    //--------------------------------------------------------------------------
    bool operator==(const Circle& rhs) const
    {
        return this->radius == rhs.radius;
    }

    // overload operator >
    //--------------------------------------------------------------------------
    bool operator>(const Circle& rhs)
    {
        return this->radius > rhs.radius;
    }
};

// overload operator <<
//------------------------------------------------------------------------------
static std::ostream& operator<<(std::ostream& os, const Circle& c)
{
    os << "Radius " << c.radius;
    return os;
}
#endif	// CIRCLE_H
