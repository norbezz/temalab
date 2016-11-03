
#ifndef TEMALAB_H_
#define TEMALAB_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'Temalab'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Temalab_main_region_LOOP,
	Temalab_main_region_LeftLightOn,
	Temalab_main_region_RightLightOn,
	Temalab_main_region_ServoTurnLeft,
	Temalab_main_region_ServoTurnRight,
	Temalab_main_region_LeftLightOff,
	Temalab_main_region_RightLightOff,
	Temalab_main_region_ServoTurnBackFromLeft,
	Temalab_main_region_ServoTurnBackFromRight,
	Temalab_last_state
} TemalabStates;

/*! Type definition of the data structure for the TemalabIface interface scope. */
typedef struct
{
	sc_boolean leftButtonPressed_raised;
	sc_boolean rightButtonPressed_raised;
} TemalabIface;

/*! Type definition of the data structure for the TemalabIfaceLeftLight interface scope. */
typedef struct
{
	sc_boolean state;
} TemalabIfaceLeftLight;

/*! Type definition of the data structure for the TemalabIfaceRightLight interface scope. */
typedef struct
{
	sc_boolean state;
} TemalabIfaceRightLight;

/*! Type definition of the data structure for the TemalabIfaceServo interface scope. */
typedef struct
{
	sc_integer position;
} TemalabIfaceServo;

/*! Type definition of the data structure for the TemalabTimeEvents interface scope. */
typedef struct
{
	sc_boolean temalab_main_region_ServoTurnLeft_tev0_raised;
	sc_boolean temalab_main_region_ServoTurnRight_tev0_raised;
	sc_boolean temalab_main_region_ServoTurnBackFromLeft_tev0_raised;
	sc_boolean temalab_main_region_ServoTurnBackFromRight_tev0_raised;
} TemalabTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define TEMALAB_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the Temalab state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	TemalabStates stateConfVector[TEMALAB_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	TemalabIface iface;
	TemalabIfaceLeftLight ifaceLeftLight;
	TemalabIfaceRightLight ifaceRightLight;
	TemalabIfaceServo ifaceServo;
	TemalabTimeEvents timeEvents;
} Temalab;

/*! Initializes the Temalab state machine data structures. Must be called before first usage.*/
extern void temalab_init(Temalab* handle);

/*! Activates the state machine */
extern void temalab_enter(Temalab* handle);

/*! Deactivates the state machine */
extern void temalab_exit(Temalab* handle);

/*! Performs a 'run to completion' step. */
extern void temalab_runCycle(Temalab* handle);

/*! Raises a time event. */
extern void temalab_raiseTimeEvent(const Temalab* handle, sc_eventid evid);

/*! Raises the in event 'leftButtonPressed' that is defined in the default interface scope. */ 
extern void temalabIface_raise_leftButtonPressed(Temalab* handle);

/*! Raises the in event 'rightButtonPressed' that is defined in the default interface scope. */ 
extern void temalabIface_raise_rightButtonPressed(Temalab* handle);

/*! Gets the value of the variable 'state' that is defined in the interface scope 'LeftLight'. */ 
extern sc_boolean temalabIfaceLeftLight_get_state(const Temalab* handle);
/*! Sets the value of the variable 'state' that is defined in the interface scope 'LeftLight'. */ 
extern void temalabIfaceLeftLight_set_state(Temalab* handle, sc_boolean value);
/*! Gets the value of the variable 'state' that is defined in the interface scope 'RightLight'. */ 
extern sc_boolean temalabIfaceRightLight_get_state(const Temalab* handle);
/*! Sets the value of the variable 'state' that is defined in the interface scope 'RightLight'. */ 
extern void temalabIfaceRightLight_set_state(Temalab* handle, sc_boolean value);
/*! Gets the value of the variable 'position' that is defined in the interface scope 'Servo'. */ 
extern sc_integer temalabIfaceServo_get_position(const Temalab* handle);
/*! Sets the value of the variable 'position' that is defined in the interface scope 'Servo'. */ 
extern void temalabIfaceServo_set_position(Temalab* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean temalab_isActive(const Temalab* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean temalab_isFinal(const Temalab* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean temalab_isStateActive(const Temalab* handle, TemalabStates state);

#ifdef __cplusplus
}
#endif 

#endif /* TEMALAB_H_ */
