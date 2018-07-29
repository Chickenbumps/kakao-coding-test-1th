#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	unsigned int strLength = 0;
	int unitDigit = 0;// 1일때 한번더 숫자를 체크하면 10의자리
	int dartPoint[3] = { 0,0,0 };
	int pointPosition = -1;// 다트 순서

	strLength = dartResult.length();
	int tempPoint = 0;
	for (int i = 0; i < strLength; i++) {
		if (dartResult[i] >= '0 '&& dartResult[i] <= '9') {
			if (unitDigit == 1) {
				tempPoint *= 10;
			}
			else {
				tempPoint = 0;
				tempPoint = dartResult[i] - '0';
				pointPosition += 1;
				unitDigit = 1;
			}
		}
		else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
			if (dartResult[i] == 'S') tempPoint = (int)pow(tempPoint, 1);
			else if (dartResult[i] == 'D') tempPoint = (int)pow(tempPoint, 2);
			else if (dartResult[i] == 'T') tempPoint = (int)pow(tempPoint, 3);
			dartPoint[pointPosition] = tempPoint;
			unitDigit = 0;
		}
		else {
			if (dartResult[i] == '*') {
				if (pointPosition > 0) dartPoint[pointPosition - 1] *= 2;
				dartPoint[pointPosition] = tempPoint * 2;
			}
			else if (dartResult[i] == '#') {
				dartPoint[pointPosition] = tempPoint * -1;
			}
		}

	}
	answer = dartPoint[0] + dartPoint[1] + dartPoint[2];
	return answer;
}