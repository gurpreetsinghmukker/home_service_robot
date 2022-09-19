// include ros, std_msgs, and geometry_msgs/Pose2D
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Pose2D.h>
#include "pick_drop_publisher/pick_drop.h"

int main(int argc, char **argv)
{
    // initialize node
    ros::init(argc, argv, "pick_drop_publisher");
    // create node handle
    ros::NodeHandle n;
    // create publisher
    ros::Publisher pick_drop_pub = n.advertise<pick_drop_publisher::pick_drop>("pick_drop_loc", 1000);
    // set loop rate
    // ros::Rate loop_rate(1);
    // // create message
    // pick_drop_publisher::pick_drop msg;
    // // set message
    // while(ros::ok()){
    //     msg.pickup_loc.x = 1.0;
    //     msg.pickup_loc.y = 2.0;
    //     msg.pickup_loc.theta = 3.0;
    //     msg.dropoff_loc.x = 4.0;
    //     msg.dropoff_loc.y = 5.0;
    //     msg.dropoff_loc.theta = 6.0;
    //     // publish message
    //     pick_drop_pub.publish(msg);
    //     // spin
    //     ros::spinOnce();
    //     // sleep
    //     loop_rate.sleep();
    // }

    ros::spin();
    
    return 0;
}