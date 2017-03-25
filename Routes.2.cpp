// Programmer: Minjoo Kim
// Programmer's ID: 1581736

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <cstring>

class Leg{
    friend class Route;
    
    const char* const startCity;
    const char* const endCity;
    double const dist;
    
public:
    Leg(const char* const s, const char* const e, double d) : startCity(s), endCity(e), dist(d){}
    double getDist() const {return dist;}
    Leg& operator=(const Leg&);
};


class Route{
    vector<const Leg*> legs;
    double const dist;
    
public:
    Route(const Leg&);
    Route(const Route&, const Leg&);
    double getDistance() const {return dist;}
    void niceOutput(ostream&) const;
    Route& operator=(const Route&);
};

int main(){
    
    cout << "Programmer: Minjoo Kim\n";
    cout << "Programmer's ID: 1581736\n";
    cout << "File: " << __FILE__ << endl;
    
    Leg ary[] = {
        Leg("San Francisco","Sacramento",87.9),
        Leg("San Francisco","San Jose",48.3),
        Leg("San Francisco","Los Angeles",342),
        Leg("Los Angeles","Las Vegas",270),
        Leg("Los Angeles","Albuquerque",789),
        Leg("Albuquerque","Santa Fe",64.3),
        Leg("Albuquerque","Denver",447),
        Leg("Santa Fe","Amarillo",280),
        Leg("Amarillo","Oklahoma City",260),
        Leg("Oklahoma City","Memphis",466),
        Leg("Memphis","Nashville",212),
        Leg("Nashville","Knoxville",180),
        Leg("Knoxville","Winston-Salem",258),
        Leg("Winston-Salem","Richmond",229),
        Leg("Richmond","Washington",109),
        Leg("Las Vegas","Denver",748),
        Leg("Denver","Kansas City",605),
        Leg("Kansas City","St. Louis",248),
        Leg("Kansas City","Des Moines",383),
        Leg("St. Louis","Louisville",261),
        Leg("St. Louis","Indianapolis",242),
        Leg("Louisville","Cincinnati",114),
        Leg("Louisville","Indianapolis",100),
        Leg("Louisville","Washington",608),
        Leg("Washington","Philadelphia",136),
        Leg("Philadelphia","New York",96.5),
        Leg("Cincinnati","Columbus",107),
        Leg("Sacramento","Reno",132),
        Leg("Reno","Salt Lake City",518),
        Leg("Salt Lake City","Ogden",38.2),
        Leg("Ogden","Lincoln",877),
        Leg("Lincoln","Omaha",53.5),
        Leg("Omaha","Des Moines",140),
        Leg("Omaha","Kansas City",189),
        Leg("Des Moines","Iowa City",114),
        Leg("Iowa City","Peoria",151),
        Leg("Iowa City","Chicago",221),
        Leg("Chicago","Cleveland",346),
        Leg("Cleveland","Buffalo",189),
        Leg("Buffalo","New York",373),
        Leg("Peoria","Indianapolis",213),
        Leg("Indianapolis","Columbus",175),
        Leg("Columbus","Pittsburgh",185),
        Leg("Pittsburgh","New York",371),
    };
    
    Route rary[] = {
        Route(ary[0]),
        Route(rary[0],ary[1]),
        Route(rary[1],ary[2]),
        Route(rary[2],ary[3]),
        Route(rary[3],ary[4]),
        Route(rary[4],ary[5]),
        Route(rary[5],ary[6]),
        Route(rary[6],ary[7]),
        Route(rary[7],ary[8]),
        Route(rary[8],ary[9]),
        Route(rary[9],ary[10]),
        Route(rary[10],ary[11]),
        Route(rary[11],ary[12]),
        Route(rary[12],ary[13]),
        Route(rary[13],ary[14]),
        Route(rary[14],ary[15]),
        Route(rary[15],ary[16]),
        Route(rary[16],ary[17]),
        Route(rary[17],ary[18]),
        Route(rary[18],ary[19]),
        Route(rary[19],ary[20]),
        Route(rary[20],ary[21]),
        Route(rary[21],ary[22])
        
    };
    
    
    for (int i = 0; i < (sizeof(rary)/sizeof(*rary)); i++){
        for (int j = i + 1; j < (sizeof(rary)/sizeof(*rary)); j++){
            if (rary[j].getDistance() > rary[i].getDistance()){
                swap(rary[i], rary[j]);
            }
        }
    }
    
    for(auto& i : rary){
        i.niceOutput(cout);
    }
}

Leg& Leg::operator=(const Leg& copyThis){
    Leg& host = *this;
    if(this != &copyThis){
        const_cast<const char*&>(host.startCity) = copyThis.startCity;
        const_cast<const char*&>(host.endCity) = copyThis.endCity;
        const_cast<double&>(host.dist) = copyThis.dist;
    }
    return host;
}

Route::Route(const Leg& leg) : dist(leg.getDist()){
    legs.push_back(&leg);
}

Route::Route(const Route& route, const Leg& leg)
: legs(route.legs), dist((strcmp(route.legs.back()->endCity, leg.startCity) == 0) ? route.dist+leg.dist : route.dist){
    try{
        if (strcmp(route.legs.back()->endCity, leg.startCity) != 0)
            throw "Mismatch";
        legs.push_back(&leg);
    }
    catch (const char* er)
    {
        cout << er << endl;
    }
    
}

void Route::niceOutput(ostream& os) const{
    
    cout << "Route: ";
    for(int i = 0; i < legs.size(); i++){
        cout << legs[i]->startCity;
        
        if(i != legs.size()-1) {
            cout << " to ";
        }
        else{
            cout << " to " << legs[i]->endCity;
        }
    }
    cout << " " << getDistance() << " miles" << endl;
}

Route& Route::operator=(const Route& copyThis){
    Route& host = *this;
    if(this != &copyThis){
        const_cast<double&>(host.dist) = copyThis.getDistance();
        host.legs = copyThis.legs;
    }
    return host;
}
