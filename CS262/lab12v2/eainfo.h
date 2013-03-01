#pragma once
#include <string>
#include <stdio.h>

using namespace std;

namespace macs262_labs
{

typedef pair<int, std::string> IntStrPair_T;

class QueueComparator : public binary_function<IntStrPair_T,IntStrPair_T,bool>
{
public:
    
    inline QueueComparator(void) {};
    inline virtual ~QueueComparator(void) {};
    
    inline bool operator()(const IntStrPair_T& aPair,
                           const IntStrPair_T& bPair) const
        {
            return (aPair.first > bPair.first);
        }
};

}