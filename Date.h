#include<iostream>
#include<string>
#include<stdexcept>
#include<exception>
#include<ctime>
#include <chrono>
using namespace std;
class Date
{
    friend class Order;
    friend class List;
    friend class task;
    //friend class employee;
    friend ostream &operator<<(ostream&,const  Date&);
    public:
    Date(unsigned int=0,  unsigned int=0 ,unsigned int=0, unsigned int=0);
    void setMonth(unsigned int);
    unsigned int getMonth()const{return month;}
    void setDay(unsigned int);
    unsigned int getDay()const{return day;}
    void setHour(unsigned int);
    unsigned int getHour()const{return hour;}
    void setMinute(unsigned int);
    unsigned int getMinute()const{return minute;}
    bool checkDay(unsigned int )const;
    bool operator>=( Date);
    bool operator<=( Date);
    void operator=(const Date&);

    private:
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
};
Date::Date(unsigned int mo,unsigned int d,unsigned int h,unsigned int m)
{
    setMonth(mo);
    setDay(d);
    setHour(h);
    setMinute(m);
}
void Date:: setMonth(unsigned int m)
{
    if(m>12||m<0)
        throw invalid_argument("Invalid month");
    month=m;
}
void Date::setDay(unsigned int d)
{
    if(checkDay(d))
        day=d;
    else
        throw invalid_argument("Invalid day");
}
void Date::setHour(unsigned int h)
{
    if(h>23||h<0)
        throw invalid_argument("Invalid hour");
    hour =h;

}
void Date::setMinute(unsigned int m)
{
    if(m>59||m<0)
        throw invalid_argument("Invalid minute");
    minute=m;
}
bool Date::checkDay(unsigned int testDay)const
{
     unsigned int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(testDay <= daysPerMonth[month])
        return true;
    return false;
}
bool Date::operator>= ( Date temp)
{
    if(getHour()>=temp.getHour())
        return true;
    else if(getHour()==temp.getHour()&&getMinute()>=temp.getMinute())
        return true;
    else
        return false;
}
bool Date::operator<=(  Date temp)
{
     if(getHour()<=temp.getHour())
        return true;
    else if(getHour()==temp.getHour()&&getMinute()<=temp.getMinute())
        return true;
    else
        return false;
  
}
void Date::operator= (const Date&A)
{
    setMonth(A.getMonth());
    setDay(A.getDay());
    setHour(A.getHour());
    setMinute(A.getMinute());
}
ostream &operator<<(ostream &output, const Date& a)
{
    output<<a.getDay()<<"/"<<a.getMonth()<<"-"<<a.getHour()<<":"<<a.getMinute();
    return output;
}