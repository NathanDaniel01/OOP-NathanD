#include "boat.h"
#include "gtest/gtest.h"
#include <memory>
#include <iostream>

class OarBoat : public water::Boat {
//  ==== Private ====
    private: bool m_OarOn;
    private: std::string m_OarType;
//  ==== Public ====
    public: OarBoat(int line, double length, const std::string &brand, int capacity)
        : Boat(line,length,brand,capacity)
    {
        m_OarOn = true;
        m_OarType = "Day Frame";
        std::cout << "OarBoat@" 
             << (void*) this 
             << " from " << m_constructedOn << " constructed." 
             << std::endl;
    }

    public: ~OarBoat()
    {
        std::cout << "OarBoat@" 
             << (void*) this 
             << " from " << m_constructedOn << " destructed." 
             << std::endl;
    }

    // ...
};

//   a<->b<->c<->d
using namespace water;
using namespace std;

TEST(OarBoat,length) {
    double length = 13.0;
    string brand = "Hyside";
    int capacity = 7;

    
    Boat boat(__LINE__,length, brand, capacity);

    ASSERT_EQ(boat.length(), length);
    OarBoat oarBoat(__LINE__,length, brand, capacity); // automatic
    ASSERT_EQ(oarBoat.length(),length); 

}