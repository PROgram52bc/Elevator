#ifndef ELEVATORSTATE_H
#define ELEVATORSTATE_H

enum ElevatorDoorState /** the state of the elevator's door */
{
	open, 	/**< when the elevator's door is open */
	closed	/**< when the elevator's door is closed */
}; 
enum ElevatorDirection /** the direction where the elevator is going */
{
	up, 	/**< when the elevator is going upward */
	down, 	/**< when the elevator is going down */
	none	/**< when the elevator is resting */
};

#endif
