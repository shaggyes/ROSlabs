#include "ros/ros.h"
#include "crystall_ball/Predictions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "std_msgs/String.h"
#include <map>
#define Ncit 10


//// old version... see next
int main_old(int argc, char **argv)
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

////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	ros::init(argc, argv, "crystall_ball_client");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<crystall_ball::Predictions>("crystall_ball");
	crystall_ball::Predictions srv;

	while (ros::ok()) {
		ros::Rate loop_rate(1);
  		loop_rate.sleep();
		std::srand(unsigned(std::time(0)));
    		int randomnum = std::rand()%Ncit;
   	
		
		std::cout << "  input your question: " << randomnum << std::endl;
		
		std::map <int, std::string> questions_list;
		questions_list[1] = "Получу ли я зачет в этом семестре?";
		questions_list[2] = "Будет ли Эдуард зол, что я поздно сдаю?";
		questions_list[3] = "Такой костыль как std::rand()%10 сгодится?";
		questions_list[4] = "О чем еще спросить?";
		questions_list[5] = "Как дела?";	
		questions_list[6] = "Погода?";
		questions_list[7] = "бла бла ба?";
		questions_list[8] = "Перепужасно?";
		questions_list[9] = "Пироги такие?";
		questions_list[0] = "С++ или Питон?";
	
		std::cout << questions_list[randomnum] << std::endl;
		srv.request.vopros=questions_list[randomnum];

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
