#include "SignalCore_Normal.h"
#include <iostream>
using namespace std;
/* test case 1 
Floor:      [8] (7) 8  2   
Direction:  [0]     0  1   
 */
/* test case 2
Floor:		[8]  (7) 8  9
Direction:	[-1]     0  0
*/
/* test case 3
Floor:         [9]    8   7   
Direction:     [-1]   0   -1  
*/

int main() {
	SignalCore_Normal sgn;
	//sgn.addSignal(2, 4, SignalCore_B::down);
	//sgn.addSignal(2, 8, SignalCore_B::both);
	sgn.addSignal(6, 8, SignalCore_B::both);
	sgn.addSignal(6, 7, SignalCore_B::down);
	sgn.addSignal(7, 9, SignalCore_B::down);
	sgn.printList();

	return 0;
}
