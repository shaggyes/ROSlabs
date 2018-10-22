#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <algorithm>

void recieve(const std_msgs::String::ConstPtr& msg) {
	
	std::string str = msg->data;
	std::transform(str.begin(), str.end(),str.begin(), ::toupper);

	ROS_INFO("UPPERCASE: %s", str.c_str());
	return;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "string_in");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/fedotov_SA_133452/string_out", 1000,recieve);
	ros::spin();

	return 0;
}
