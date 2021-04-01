#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Pose.h>
#include <time.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <turtlesim/Color.h>
#include <stdlib.h>

using namespace std;
ros::Publisher my_pub;
int pencolor_r,pencolor_g,pencolor_b;
void color_cb(const turtlesim::Color::ConstPtr&colorsense)
{
 pencolor_r =  colorsense->r;
 pencolor_g = colorsense->g;
 pencolor_b = colorsense->b;

}

int main(int argc, char** argv)
{   
    ros::init(argc,argv,"game");
    ros::NodeHandle nh;

   ros::Subscriber sub = nh.subscribe("/turtle1/color_sensor",100,&color_cb);

   ros::service::waitForService("/turtle1/teleport_absolute");
   ros::service::waitForService("/turtle1/set_pen");
   ros::ServiceClient pen = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
   ros::ServiceClient teleporter = nh.serviceClient<turtlesim::TeleportAbsolute>("turtle1/teleport_absolute");
   turtlesim::TeleportAbsolute pos;
   turtlesim::SetPen setpen;
   setpen.request.r = 255;
   setpen.request.g = 255;
   setpen.request.b = 0;
   setpen.request.width = 20;
   setpen.request.off = 1;
   pen.call(setpen);
   
   pos.request.theta= 0; 
   pos.request.x = 1;
   pos.request.y = 1;
   teleporter.call(pos);
   setpen.request.off = 0;
   
   pen.call(setpen);
   pos.request.theta= 0; 
   pos.request.x = 8;
   pos.request.y = 1;
   teleporter.call(pos);

   pos.request.theta= 0; 
   pos.request.x = 8;
   pos.request.y = 8;
   teleporter.call(pos);


   pos.request.theta= 0; 
   pos.request.x = 1;
   pos.request.y = 8;
   teleporter.call(pos);


   pos.request.theta= 0; 
   pos.request.x = 1;
   pos.request.y = 1;
   teleporter.call(pos);


   setpen.request.off = 1;
   pen.call(setpen);
  

while(ros::ok())
{
 //if((pencolor_r=0)&&(pencolor_g=0)&&(pencolor_b=0)){
if((pencolor_r!=255)&&(pencolor_r!=255))
cout<<"Ayoo I am out of LINE!!!"<<endl<<endl;
else
system("clear");

 
ros::spinOnce();

}
    return 0;
}
