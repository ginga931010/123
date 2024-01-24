#include "ros/ros.h"
#include "practice/sample_message.h"

void loc_data_cb(const practice::sample_message::ConstPtr &msg){
    ROS_INFO_STREAM("-----------------------------");
    ROS_INFO_STREAM("Current time : " << msg->time);
    ROS_INFO_STREAM("Current position : (" << msg->position.linear.x << ", " << msg->position.linear.y << ")");
    ROS_INFO_STREAM("Current omega : (" << msg->position.angular.x << ", " << msg->position.angular.y << ", " << msg->position.angular.z << ")");
    ROS_INFO_STREAM("Current velocity : (" << msg->velocity.linear.x << ", " << msg->velocity.linear.y << ")");
    ROS_INFO_STREAM("-----------------------------");
}

int main(int argc, char** argv){

    ros::init(argc, argv, "loc_sub");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/loc_data", 10, loc_data_cb);

    ros::spin();

}