/* 
 * rosserial Subscriber Example
 * turns on an LED on sending char 'a' and offs on typing any other char
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::String& toggle_msg){
 if(toggle_msg.data[0]=='a')  //check 1st letter of the string
 digitalWrite(13, HIGH);   // turn on the led
else
digitalWrite(13,LOW);

}

ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

