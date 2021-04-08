#include <ros/ros.h>
#include "move/Handler.hpp"

int main(int argc, char **argv){
    ros::init(argc, argv, "mission2");
    ros::NodeHandle nh;
    ros::Rate rate(0.2);
    Drone drone = Drone(nh);
    drone.takeoff(3); 


    drone.moveGlobal({20,0,3,false});
    ros::Duration(5).sleep();
    drone.moveGlobal({20,30,3,false});
    ros::Duration(0.2).sleep();

    for(double i=1;i<181;i++){
        float x=0;
        float y=30;
        x+= 20*cos(i*3.141592/180);
        y+= 20*sin(i*3.141592/180);
        drone.moveGlobal({x,y,3,false});
        ros::Duration(0.00000000001).sleep();
    }

    drone.moveGlobal({-20,-30,3,false});
    ros::Duration(0.2).sleep();


    for(double i=180;i<361;i++){
        float x=0;
        float y=-30;
        x+= 20*cos(i*3.141592/180);
        y+= 20*sin(i*3.141592/180);
        drone.moveGlobal({x,y,3,false});
        ros::Duration(0.0000000001).sleep();
    }
    drone.moveGlobal({20,0,3,false});
    ros::Duration(0.2).sleep();
    
    drone.moveGlobal({20,30,3,false});
    ros::Duration(0.2).sleep();

    for(double i=1;i<181;i++){
        float x=0;
        float y=30;
        x+= 20*cos(i*3.141592/180);
        y+= 20*sin(i*3.141592/180);
        drone.moveGlobal({x,y,3,false});
        ros::Duration(0.00000000001).sleep();
    }
    drone.moveGlobal({-20,30,1,false});
    ros::Duration(3).sleep();
    drone.moveGlobal({-20,30,3,false});
    ros::Duration(0.2).sleep();
    drone.moveGlobal({-20,0,3,false});
    ros::Duration(3).sleep();
    drone.moveGlobal({-20,0,1,false});
    ros::Duration(3).sleep();
    drone.moveGlobal({-20,-30,3,false});
    ros::Duration(0.2).sleep();


    for(double i=180;i<361;i++){
        float x=0;
        float y=-30;
        x+= 20*cos(i*3.141592/180);
        y+= 20*sin(i*3.141592/180);
        drone.moveGlobal({x,y,3,false});
        ros::Duration(0.0000000001).sleep();
    }
    drone.moveGlobal({20,0,3,false});
    ros::Duration(0.2).sleep();
    drone.moveGlobal({20,0,0,false});
    ros::Duration(3).sleep();
    
    drone.land();
}