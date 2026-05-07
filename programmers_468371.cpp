#include <string>
#include <vector>

using namespace std;

struct LightInfo
{
    int G;
    int Y;
    int R;
    int Cycle;

    bool isYellow(int t)
    {
        int color = (t - 1) % (Cycle);

        if(0 <= color && color <= G -1)
            return false; // G
        else if(G - 1 < color && color <= G + Y -1)
            return true; // Y
        else if(G + Y -1 < color)
            return false; // R

        return false;
    }
};

int solution(vector<vector<int>> signals) {
    vector<LightInfo> lightList;
    long long limit = 1;

    for (vector<int> light: signals)
    {
        LightInfo lightinfo;
        lightinfo.G = light[0];
        lightinfo.Y = light[1];
        lightinfo.R = light[2];
        lightinfo.Cycle = light[0] + light[1] + light[2];
        lightList.push_back(lightinfo);

        limit *= lightinfo.Cycle;
    }
    

    int t = 0;
    bool allYellow = false;

    while(++t < limit)
    {
        allYellow = true;

        for(LightInfo info : lightList)
            if(info.isYellow(t) == false)
                allYellow = false;
        
        if(allYellow)
            return t;
    }
    
    return -1;
}


