#include"Date.h"
#include<vector>
#include<algorithm>
using namespace std;
class task
{
    friend class Order;
    friend class employee;
    public:
    task(string,const Date&,const Date&);
    void setTaskName(string);
    void setTaskStartDate( const Date&);
    void setTaskFinishDate( const Date&);
    Date getStartTask()const{return start;}
    Date getFinishTask()const{return finish;}
    string getNameTask()const{return Name;}
    bool operator<(const task&);
    bool operator<=(const task&);
    private:
    string Name;
    Date start;
    Date finish;
};
task::task(string name,const Date& s ,const Date& f)
{
    if(s.getMonth()!=f.getMonth()||s.getDay()!=f.getDay())
        throw invalid_argument("start and finish a cast must be in same day and month");
    Name=name;
    start=s;
    finish=f;
}
bool task::operator<(const task&A)
{
    if(start.getHour()<A.start.getHour())
        return true;
    if(start.getHour()==A.start.getHour()&&start.getMinute()<A.start.getMinute())
        return true;
    return false;
}
bool task::operator<=(const task&A)
{
    if(start.getHour()<=A.start.getHour())
        return true;
    if(start.getHour()==A.start.getHour()&&start.getMinute()<=A.start.getMinute())
        return true;
    return false;
}
void task::setTaskName(string n)
{
    Name=n;
}
void task::setTaskStartDate(const Date &A)
{
    start=A;
}
void task::setTaskFinishDate(const Date &A)
{
    finish=A;
}



