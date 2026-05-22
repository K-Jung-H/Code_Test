#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {    
    int max_health = health;
    
    int band_charge = bandage[0];
    int band_heal = bandage[1];
    int band_heal_extra = bandage[2];  
    int band_combo = 0;
    
    int attack_damage = 0;
    
    int time = 0, attack_count = 0;
    
    for(int time = 0; time <= attacks.back()[0]; ++time)
    {
        if(time == attacks[attack_count][0]) // 공격 
        {
            attack_damage = attacks[attack_count][1];
            health -= attack_damage;
            
            band_combo = 0;
            attack_count += 1;
            
            if(health <= 0)
                return -1;
            
        }
        else // 붕대 감기
        {
            health += band_heal;
            
            band_combo += 1;
            
            if(band_combo == band_charge)
            {
                health += band_heal_extra; 
                band_combo = 0;
            }
            
            health = clamp(health, 0, max_health);
        }
        
    }
    
    return health;
}

//============================================================


int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int max_health = health;
    int band_charge = bandage[0];
    int band_heal = bandage[1];
    int band_heal_extra = bandage[2];
    
    int current_time = 0;
    
    for (const auto& attack : attacks) {
        int attack_time = attack[0];
        int attack_damage = attack[1];
        
        int time_diff = attack_time - current_time - 1;
        
        if (time_diff > 0) {
            int total_heal = (time_diff * band_heal) + ((time_diff / band_charge) * band_heal_extra);
            health = min(max_health, health + total_heal);
        }
        
        health -= attack_damage;
        
        if (health <= 0) {
            return -1;
        }
        
        current_time = attack_time;
    }
    
    return health;
}