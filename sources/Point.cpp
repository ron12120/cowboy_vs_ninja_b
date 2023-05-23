#include "Point.hpp"
namespace ariel
{
    Point::Point(double x, double y): _x(x), _y(y){}
    double Point::distance(const Point &point)const {
        double sumx = _x-point._x;
        double sumy = _y-point._y;
        return sqrt(pow(sumx,2)+pow(sumy,2));   
    }
    void Point::print()const{
        cout<<"("<<_x<<","<<_y<<")";
    } 
    Point Point::moveTowards(const Point &src , const Point &des, double dest){
        if(dest<0)
            throw invalid_argument("the speed cnat't be negative");
        double dis=src.distance(des);
        if(dis<=dest)
            return des;
        else
        {
            double ratio = dest/dis;
            double newx= src._x+(des._x-src._x)*ratio;
            double newy= src._y+(des._y-src._y)*ratio;
            Point ans(newx,newy);
            return ans;
        }       
    }

    ostream &operator<<(ostream &os, const Point &point){
        os<<"("<<point._x<<","<<point._y<<")";
        return os;
    }

}