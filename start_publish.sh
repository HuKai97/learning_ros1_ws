#!/bin/bash
roscore & sleep 5

source devel/setup.bash
# rosrun learning_communication string_publisher
rosrun learning_communication person_publisher