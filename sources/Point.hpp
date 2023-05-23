#pragma once 
#include <iostream>
#include <cmath>
using namespace std;
namespace ariel
{
    class Point
    {
        double _x;
        double _y;

        public:
            Point(double x, double y);
            double distance(const Point &point)const;
            void print()const;
            static Point moveTowards(const Point &src , const Point &des, double dest);
            friend::ostream &operator <<(ostream &os, const Point &point);
    };

};
