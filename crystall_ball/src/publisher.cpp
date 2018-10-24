#include "ros/ros.h"
#include "crystall_ball/Predictions.h"
#include <iostream>
#include <string>
#include <sstream>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "crystall_ball_client");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<crystall_ball::Predictions>("crystall_ball");
	crystall_ball::Predictions srv;

	while (ros::ok()) {
		

		std::cout << "  input your question: " << std::endl;
		std::string input;
		std::getline(std::cin, input);
		std::stringstream ss(input);
		srv.request.vopros=ss.str();

		if(client.call(srv)) {
			


			std::cout << "  My prediction is:  " << srv.response.otvet << std::endl << std::endl;
		}
		else {
			
			std::cout << "Failed to nightcall" <<std::endl;
			return 1;
		}
	}
	return 0;
}
