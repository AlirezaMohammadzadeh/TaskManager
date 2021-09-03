#include"task.h"
using namespace std;
class employee
{
    friend class Order;
    public:
    employee(string ,string,unsigned int,unsigned int,unsigned int,unsigned int);
    void setStartHour(unsigned int );
    void setFinishHour(unsigned int);
    void setStartMinute(unsigned int);
    void setFinishMinute(unsigned int);
    unsigned int getStartHour()const{return h_s;}
    unsigned int getFinishHour()const{return h_f;}
    unsigned int getStartMinute()const{return m_s;}
    unsigned int getFinishMinute()const{return m_f ;}
    string getSsid()const{return ssid;}
    string getName()const {return name;}
    private:
    string name;
    string  ssid;
    vector<task>employeetasks;
    unsigned int h_s;
    unsigned int h_f;
    unsigned int m_s;
    unsigned int m_f; 
};
employee::employee(string Name,string  id,unsigned int hs,unsigned int ms,unsigned int hf,unsigned int mf)
{
    name=Name;
    ssid=id;
    setStartHour(hs);
    setFinishHour(hf);
    setStartMinute(ms);
    setFinishMinute(mf);
}
void employee::setStartHour(unsigned int h)
{
   if(h>23||h<0)
        throw invalid_argument("Invalid hour");
    h_s=h;
}
void employee:: setFinishHour(unsigned int h)
{
    if(h>23||h<0)
        throw invalid_argument("Invalid hour");
    h_f=h;
}
void employee::setStartMinute(unsigned int m)
{
    if(m>59||m<0)
        throw invalid_argument("Invalid minute");
    m_s=m;
}
void employee::setFinishMinute(unsigned int m)
{
    if(m>59||m<0)
        throw invalid_argument("Invalid minute");
    if(h_s==h_f&&m<m_s)
        throw invalid_argument("Invalid minute");
    m_f=m;

}
