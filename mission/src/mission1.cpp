#include <ros/ros.h>
#include "move/Handler.hpp"

int main(int argc, char **argv){
    ros::init(argc, argv, "mission1");
    ros::NodeHandle nh;
    ros::Rate rate(0.2);
    Drone drone = Drone(nh);
    drone.takeoff(3); 

    for(double j=1;j<3;j++){
        drone.moveGlobal({30,0,3,false});
        ros::Duration(5).sleep();
        drone.moveGlobal({30,11,3,false});
        ros::Duration(0.002).sleep();

        for(double i=1;i<181;i++){
            float x=0;
            float y=11;
            x+= 30*cos(i*3.141592/180);
            y+= 30*sin(i*3.141592/180);
            drone.moveGlobal({x,y,3,false});
            ros::Duration(0.00000000001).sleep();
        }
        drone.moveGlobal({-28,0,3,false});
        ros::Duration(0.2).sleep();

        for(double i=360;i>-1;i--){
            float x=-30;
            float y=0;
            x+= 2*cos(i*3.141592/180);
            y+= 2*sin(i*3.141592/180);
            drone.moveGlobal({x,y,3,false});
            ros::Duration(0.00000000001).sleep();
        }

        drone.moveGlobal({-30,-11,3,false});
        ros::Duration(0.2).sleep();
        for(double i=180;i<361;i++){
            float x=0;
            float y=-11;
            x+= 30*cos(i*3.141592/180);
            y+= 30*sin(i*3.141592/180);
            drone.moveGlobal({x,y,3,false});
            ros::Duration(0.0000000001).sleep();
        }
        

    }
    drone.moveGlobal({30,0,3,false});
    ros::Duration(0.02).sleep();
    
    drone.moveGlobal({30,0,0,false});
    ros::Duration(0.2).sleep();
    drone.land();

}