#include "section.h"
#include <string>
#include <iostream>

int main() {
	using namespace std;
	Section testSec1(1,1,50,10);
	Section testSec2(51,1,50,10);
	Section testSec3(1,11,50,10);
	Section testSec4(51,11,50,10);

/* 	sec1...sec2
 *  .
 *  .
 *  sec3...sec4
 */

	testSec1.drawStrAt("SEC1Start");
	testSec2.drawStrAt("SEC2Start");
	testSec3.drawStrAt("SEC3Start");
	testSec4.drawStrAt("SEC4Start"); 

	testSec1.drawStrAt("SEC1End", testSec1.height);
	testSec2.drawStrAt("SEC2End", testSec2.height);
	testSec3.drawStrAt("SEC3End", testSec3.height);
	testSec4.drawStrAt("SEC4End", testSec4.height);

	testSec1.drawStrAt("}", 1,  testSec1.width);
	testSec1.drawStrAt("}", testSec1.height, testSec1.width);
	testSec2.drawStrAt("}", 1,  testSec2.width);
	testSec2.drawStrAt("}", testSec2.height,  testSec2.width);
	testSec3.drawStrAt("}", 1,  testSec3.width);
	testSec3.drawStrAt("}", testSec3.height,  testSec3.width);
	testSec4.drawStrAt("}", 1,  testSec4.width);
	testSec4.drawStrAt("}", testSec4.height,  testSec4.width);

	testSec3.clrSection();

}
