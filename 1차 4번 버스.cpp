#include <iostream>
#include <string>
using namespace std;

int StringToMintime(string time) {
	int minTime = 0;
	int hour = ((time[0] - '0') * 10 + (time[1] - '0')) * 60;
	int min = (time[3] - '0') * 10 + (time[4] - '0');
	minTime = hour + min;
	return minTime;
}
