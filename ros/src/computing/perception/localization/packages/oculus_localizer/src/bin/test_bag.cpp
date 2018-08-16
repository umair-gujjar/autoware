/*
 * test_bag.cpp
 *
 *  Created on: Aug 10, 2018
 *      Author: sujiwo
 */


#include <iostream>
#include <vector>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <rosbag/message_instance.h>
#include <rosbag/structures.h>

#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>

#include <nmea_msgs/Sentence.h>
#include <gnss/geo_pos_conv.hpp>

#include <opencv2/highgui.hpp>

#include "datasets/RandomAccessBag.h"
#include "utilities.h"

using namespace std;


void createTrackFromGnssBag (RandomAccessBag &bagsrc, vector<Pose> &track)
{
	if (bagsrc.getTopic() != "/nmea_sentence")
		throw runtime_error("Not GNSS bag");

	geo_pos_conv geoconv;

	for (uint32_t ix=0; ix<bagsrc.size(); ix++) {

	}
}


int main (int argc, char *argv[])
{
	rosbag::Bag bagstore;
	bagstore.open("/home/sujiwo/Data/log_2016-12-26-13-21-10-filtered.bag");

	RandomAccessBag ramBag (bagstore, "/camera1/image_raw");
	auto img0 = ramBag.at<sensor_msgs::Image>(0);

	cv_bridge::CvImageConstPtr cvPtr = cv_bridge::toCvShare(img0, sensor_msgs::image_encodings::RGB8);
	cv::imwrite("/tmp/t0.png", cvPtr->image);

	return 0;
}