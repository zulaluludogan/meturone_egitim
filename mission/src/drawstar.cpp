
#include <ros/ros.h>
#include "move/Handler.hpp"

int main(int argc, char **argv){
    ros::init(argc, argv, "drawstar");
    ros::NodeHandle nh;
    ros::Rate rate(0.2);
    Drone drone = Drone(nh);
    drone.takeoff(3); 

    
    drone.moveGlobal({0,0,3,false});
    ros::Duration(6).sleep();
    drone.moveGlobal({-5,-7,3,false});
    ros::Duration(5).sleep();
    drone.moveGlobal({0,8,3,false});
    ros::Duration(4).sleep();
    drone.moveGlobal({5,-7,3,false});
    ros::Duration(4).sleep();
    drone.moveGlobal({-6,4,3,false});
    ros::Duration(4).sleep();
    drone.moveGlobal({6,4,3,false});
    ros::Duration(4).sleep();
    drone.moveGlobal({-5,-7,3,false});
    ros::Duration(4).sleep(); 
    drone.moveGlobal({0,0,0,false});
    ros::Duration(4).sleep();  

    drone.land();
}

