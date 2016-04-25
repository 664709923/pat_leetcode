#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int rate[24];
int n;

class record{
public:
    string name;
    string datetime;
    string type;

    int month;
    int day;
    int hour;
    int minute;

    void setTime()
    {
        sscanf(datetime.c_str(), "%d:%d:%d:%d", &month, &day, &hour, &minute);
    }

};

bool cmp(record a, record b)
{
    if(a.name != b.name)
    {
        return a.name < b.name;
    }else{
        return a.datetime < b.datetime;
    }
}

double calc(string datetime)
{
    int month;
    int day;
    int hour;
    int minute;
    sscanf(datetime.c_str(), "%d:%d:%d:%d", &month, &day, &hour, &minute);



    return result;
}

int main()
{
    for(int i = 0; i < 24; i++)
    {
        cin >> rate[i];
    }
    cin >> n;
    record records[n];
    for(int i = 0; i < n; i++)
    {
        cin >> records[i].name >> records[i].datetime >> records[i].type;
    }
    sort(records, records+n, cmp);

    int i=0;
    int cnt=0;
    vector<record> res;
    while(i < n - 1)
    {
        if(records[i].name != records[i+1].name)
        {
            i++;
            break;
        }else{
            if(records[i].type == "on-line" && records[i+1].type == "off-line")
            {
                records[i].setTime();
                records[i+1].setTime();

                res.push_back(records[i]);
                res.push_back(records[i+1]);
                i += 2;
            }else{
                i++;
            }
        }
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i].name<<"\t"<<res[i].datetime<<"\t"<<res[i].type<<"\n";
    }




    return 0;
}
