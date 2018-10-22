#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv) {

  ros::init(argc, argv, "string_out");
  ros::NodeHandle n;
  ros::Publisher pubg = n.advertise<std_msgs::String>("/fedotov_SA_133452/string_out", 1000);
  ros::Rate loop_rate(1);
  loop_rate.sleep();
  
  std_msgs::String msg;
  std::stringstream ss;
  for (int k=0; k<10; k++){
	
	if (k%2 == 0){
		ss.str ("hello Edward");
	} else {
		ss.str ("o, hi Stas");
	}
	msg.data = ss.str();	    
	ROS_INFO("%s", msg.data.c_str());
	
	pubg.publish(msg);
	loop_rate.sleep();
  }
  ros::spinOnce();
  return 0;
}
