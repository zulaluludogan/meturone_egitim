#include <ros/ros.h>
#include "move/Handler.hpp"

int main(int argc, char **argv){
    ros::init(argc, argv, "drawcircle");
    ros::NodeHandle nh;
    ros::Rate rate(0.2);
    Drone drone = Drone(nh);
    drone.takeoff(3); 
   
    drone.moveGlobal({2,0,3,false});
    ros::Duration(6).sleep();

    for(double i=1;i<361;i++){
        float x=0;
        float y=0;
        x= 2*cos(i*3.141592/180);
        y= 2*sin(i*3.141592/180);
        drone.moveGlobal({x,y,3,false});
        ros::Duration(0.000002).sleep();

        drone.land();
    }
}