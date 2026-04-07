#include<bits/stdc++.h>
using namespace std;

class Robot {
public:
    string direction;
    vector<int> position;
    int width;
    int height;
    Robot(int width, int height) {
        this->width=width;
        this->height=height;
        this->direction="East";
        this->position={0,0};
    }
    
    void step(int num) {
        int num_steps=num;
        int full_rotation=2*(width-1)+2*(height-1);
        if(num_steps>=full_rotation){
            num_steps%=full_rotation;
            if(num_steps%full_rotation==0){
                if(this->position==vector<int>{0,0}) this->direction="South";
                else if(this->position==vector<int>{width-1,0}) this->direction="East";
                else if(this->position==vector<int>{width-1,height-1}) this->direction="North";
                else if(this->position==vector<int>{0,height-1}) this->direction="West";
            }
        }
        while(num_steps!=0){
            if(this->direction=="East"){
                if(width-this->position[0]-1>=num_steps){
                    this->position[0]+=num_steps;
                    break;
                }
                else{
                    num_steps-=(width-this->position[0]-1);
                    this->position[0]=width-1;
                    this->direction="North";
                }
            }
            else if(this->direction=="North"){
                if(height-this->position[1]-1>=num_steps){
                    this->position[1]+=num_steps;
                    break;
                }
                else{
                    num_steps-=(height-this->position[1]-1);
                    this->position[1]=height-1;
                    this->direction="West";
                }
            }
            else if(this->direction=="West"){
                if(this->position[0]>=num_steps){
                    this->position[0]-=num_steps;
                    break;
                }
                else{
                    num_steps-=this->position[0];
                    this->position[0]=0;
                    this->direction="South";
                }
            }
            else{ //"South"
                if(this->position[1]>=num_steps){
                    this->position[1]-=num_steps;
                    break;
                }
                else{
                    num_steps-=this->position[1];
                    this->position[1]=0;
                    this->direction="East";
                }
            }
        }
    }
    
    vector<int> getPos() {
        return this->position;
    }
    
    string getDir() {
        return this->direction;     
    }
};