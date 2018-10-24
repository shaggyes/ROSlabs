#include "ros/ros.h"
#include "crystall_ball/Predictions.h"
#include <string>
#define Ncit 10
#include <map>



bool recv(crystall_ball::Predictions::Request &req, 
	crystall_ball::Predictions::Response &res)
{

	int num = req.vopros.length();
	if (req.vopros[num-1] != '?'){
		num = 10;	
	} else {
		num = num%Ncit;
	}
	ROS_INFO("Number of prediction is %d", num);
	
	std::map <int, std::string> predictions_list;
	predictions_list[1] = "Вам будет сопутствовать удача";
	predictions_list[2] = "Как знать, как знать";
	predictions_list[3] = "Попробуйте еще раз";
	predictions_list[4] = "Все будет хорошо";
	predictions_list[5] = "Скорее да, чем нет";	
	predictions_list[6] = "Скорее нет, чем да";
	predictions_list[7] = "Скорее или чем или";
	predictions_list[8] = "Скорее может быть или";
	predictions_list[9] = "Шар сломался";
	predictions_list[0] = "Сервер перегружен вашими запросами";
	predictions_list[10] = "WARNING!!! ACHTUNG!!! Iz it question lol";
	res.otvet = predictions_list[num];


	ROS_INFO("Prediction resposne is: %s", res.otvet.c_str());
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "crystall_ball_server");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("crystall_ball", recv);
	ROS_INFO("Ready for magic");
	ros::spin();
	return 0;
}
