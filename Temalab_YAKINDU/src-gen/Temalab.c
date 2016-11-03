
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "Temalab.h"
#include "TemalabRequired.h"
/*! \file Implementation of the state machine 'Temalab'
*/

/* prototypes of all internal functions */
static sc_boolean temalab_check_main_region_LOOP_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_LOOP_tr1_tr1(const Temalab* handle);
static sc_boolean temalab_check_main_region_LeftLightOn_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_RightLightOn_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnLeft_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnLeft_tr1_tr1(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnRight_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnRight_tr1_tr1(const Temalab* handle);
static sc_boolean temalab_check_main_region_LeftLightOff_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_RightLightOff_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnBackFromLeft_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnBackFromLeft_tr1_tr1(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnBackFromRight_tr0_tr0(const Temalab* handle);
static sc_boolean temalab_check_main_region_ServoTurnBackFromRight_tr1_tr1(const Temalab* handle);
static void temalab_effect_main_region_LOOP_tr0(Temalab* handle);
static void temalab_effect_main_region_LOOP_tr1(Temalab* handle);
static void temalab_effect_main_region_LeftLightOn_tr0(Temalab* handle);
static void temalab_effect_main_region_RightLightOn_tr0(Temalab* handle);
static void temalab_effect_main_region_ServoTurnLeft_tr0(Temalab* handle);
static void temalab_effect_main_region_ServoTurnLeft_tr1(Temalab* handle);
static void temalab_effect_main_region_ServoTurnRight_tr0(Temalab* handle);
static void temalab_effect_main_region_ServoTurnRight_tr1(Temalab* handle);
static void temalab_effect_main_region_LeftLightOff_tr0(Temalab* handle);
static void temalab_effect_main_region_RightLightOff_tr0(Temalab* handle);
static void temalab_effect_main_region_ServoTurnBackFromLeft_tr0(Temalab* handle);
static void temalab_effect_main_region_ServoTurnBackFromLeft_tr1(Temalab* handle);
static void temalab_effect_main_region_ServoTurnBackFromRight_tr0(Temalab* handle);
static void temalab_effect_main_region_ServoTurnBackFromRight_tr1(Temalab* handle);
static void temalab_enact_main_region_LeftLightOn(Temalab* handle);
static void temalab_enact_main_region_RightLightOn(Temalab* handle);
static void temalab_enact_main_region_ServoTurnLeft(Temalab* handle);
static void temalab_enact_main_region_ServoTurnRight(Temalab* handle);
static void temalab_enact_main_region_LeftLightOff(Temalab* handle);
static void temalab_enact_main_region_RightLightOff(Temalab* handle);
static void temalab_enact_main_region_ServoTurnBackFromLeft(Temalab* handle);
static void temalab_enact_main_region_ServoTurnBackFromRight(Temalab* handle);
static void temalab_exact_main_region_ServoTurnLeft(Temalab* handle);
static void temalab_exact_main_region_ServoTurnRight(Temalab* handle);
static void temalab_exact_main_region_ServoTurnBackFromLeft(Temalab* handle);
static void temalab_exact_main_region_ServoTurnBackFromRight(Temalab* handle);
static void temalab_enseq_main_region_LOOP_default(Temalab* handle);
static void temalab_enseq_main_region_LeftLightOn_default(Temalab* handle);
static void temalab_enseq_main_region_RightLightOn_default(Temalab* handle);
static void temalab_enseq_main_region_ServoTurnLeft_default(Temalab* handle);
static void temalab_enseq_main_region_ServoTurnRight_default(Temalab* handle);
static void temalab_enseq_main_region_LeftLightOff_default(Temalab* handle);
static void temalab_enseq_main_region_RightLightOff_default(Temalab* handle);
static void temalab_enseq_main_region_ServoTurnBackFromLeft_default(Temalab* handle);
static void temalab_enseq_main_region_ServoTurnBackFromRight_default(Temalab* handle);
static void temalab_enseq_main_region_default(Temalab* handle);
static void temalab_exseq_main_region_LOOP(Temalab* handle);
static void temalab_exseq_main_region_LeftLightOn(Temalab* handle);
static void temalab_exseq_main_region_RightLightOn(Temalab* handle);
static void temalab_exseq_main_region_ServoTurnLeft(Temalab* handle);
static void temalab_exseq_main_region_ServoTurnRight(Temalab* handle);
static void temalab_exseq_main_region_LeftLightOff(Temalab* handle);
static void temalab_exseq_main_region_RightLightOff(Temalab* handle);
static void temalab_exseq_main_region_ServoTurnBackFromLeft(Temalab* handle);
static void temalab_exseq_main_region_ServoTurnBackFromRight(Temalab* handle);
static void temalab_exseq_main_region(Temalab* handle);
static void temalab_react_main_region_LOOP(Temalab* handle);
static void temalab_react_main_region_LeftLightOn(Temalab* handle);
static void temalab_react_main_region_RightLightOn(Temalab* handle);
static void temalab_react_main_region_ServoTurnLeft(Temalab* handle);
static void temalab_react_main_region_ServoTurnRight(Temalab* handle);
static void temalab_react_main_region_LeftLightOff(Temalab* handle);
static void temalab_react_main_region_RightLightOff(Temalab* handle);
static void temalab_react_main_region_ServoTurnBackFromLeft(Temalab* handle);
static void temalab_react_main_region_ServoTurnBackFromRight(Temalab* handle);
static void temalab_react_main_region__entry_Default(Temalab* handle);
static void temalab_clearInEvents(Temalab* handle);
static void temalab_clearOutEvents(Temalab* handle);


void temalab_init(Temalab* handle)
{
	sc_integer i;

	for (i = 0; i < TEMALAB_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Temalab_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	temalab_clearInEvents(handle);
	temalab_clearOutEvents(handle);

	/* Default init sequence for statechart Temalab */
	handle->ifaceLeftLight.state = bool_false;
	handle->ifaceRightLight.state = bool_false;
	handle->ifaceServo.position = 0;

}

void temalab_enter(Temalab* handle)
{
	/* Default enter sequence for statechart Temalab */
	temalab_enseq_main_region_default(handle);
}

void temalab_exit(Temalab* handle)
{
	/* Default exit sequence for statechart Temalab */
	temalab_exseq_main_region(handle);
}

sc_boolean temalab_isActive(const Temalab* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Temalab_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean temalab_isFinal(const Temalab* handle)
{
   return bool_false;
}

static void temalab_clearInEvents(Temalab* handle)
{
	handle->iface.leftButtonPressed_raised = bool_false;
	handle->iface.rightButtonPressed_raised = bool_false;
	handle->timeEvents.temalab_main_region_ServoTurnLeft_tev0_raised = bool_false;
	handle->timeEvents.temalab_main_region_ServoTurnRight_tev0_raised = bool_false;
	handle->timeEvents.temalab_main_region_ServoTurnBackFromLeft_tev0_raised = bool_false;
	handle->timeEvents.temalab_main_region_ServoTurnBackFromRight_tev0_raised = bool_false;
}

static void temalab_clearOutEvents(Temalab* handle)
{
}

void temalab_runCycle(Temalab* handle)
{
	
	temalab_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < TEMALAB_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Temalab_main_region_LOOP :
		{
			temalab_react_main_region_LOOP(handle);
			break;
		}
		case Temalab_main_region_LeftLightOn :
		{
			temalab_react_main_region_LeftLightOn(handle);
			break;
		}
		case Temalab_main_region_RightLightOn :
		{
			temalab_react_main_region_RightLightOn(handle);
			break;
		}
		case Temalab_main_region_ServoTurnLeft :
		{
			temalab_react_main_region_ServoTurnLeft(handle);
			break;
		}
		case Temalab_main_region_ServoTurnRight :
		{
			temalab_react_main_region_ServoTurnRight(handle);
			break;
		}
		case Temalab_main_region_LeftLightOff :
		{
			temalab_react_main_region_LeftLightOff(handle);
			break;
		}
		case Temalab_main_region_RightLightOff :
		{
			temalab_react_main_region_RightLightOff(handle);
			break;
		}
		case Temalab_main_region_ServoTurnBackFromLeft :
		{
			temalab_react_main_region_ServoTurnBackFromLeft(handle);
			break;
		}
		case Temalab_main_region_ServoTurnBackFromRight :
		{
			temalab_react_main_region_ServoTurnBackFromRight(handle);
			break;
		}
		default:
			break;
		}
	}
	
	temalab_clearInEvents(handle);
}

void temalab_raiseTimeEvent(const Temalab* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(TemalabTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean temalab_isStateActive(const Temalab* handle, TemalabStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Temalab_main_region_LOOP :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_LOOP
			);
			break;
		case Temalab_main_region_LeftLightOn :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_LeftLightOn
			);
			break;
		case Temalab_main_region_RightLightOn :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_RightLightOn
			);
			break;
		case Temalab_main_region_ServoTurnLeft :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_ServoTurnLeft
			);
			break;
		case Temalab_main_region_ServoTurnRight :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_ServoTurnRight
			);
			break;
		case Temalab_main_region_LeftLightOff :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_LeftLightOff
			);
			break;
		case Temalab_main_region_RightLightOff :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_RightLightOff
			);
			break;
		case Temalab_main_region_ServoTurnBackFromLeft :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_ServoTurnBackFromLeft
			);
			break;
		case Temalab_main_region_ServoTurnBackFromRight :
			result = (sc_boolean) (handle->stateConfVector[0] == Temalab_main_region_ServoTurnBackFromRight
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void temalabIface_raise_leftButtonPressed(Temalab* handle)
{
	handle->iface.leftButtonPressed_raised = bool_true;
}
void temalabIface_raise_rightButtonPressed(Temalab* handle)
{
	handle->iface.rightButtonPressed_raised = bool_true;
}




sc_boolean temalabIfaceLeftLight_get_state(const Temalab* handle)
{
	return handle->ifaceLeftLight.state;
}
void temalabIfaceLeftLight_set_state(Temalab* handle, sc_boolean value)
{
	handle->ifaceLeftLight.state = value;
}


sc_boolean temalabIfaceRightLight_get_state(const Temalab* handle)
{
	return handle->ifaceRightLight.state;
}
void temalabIfaceRightLight_set_state(Temalab* handle, sc_boolean value)
{
	handle->ifaceRightLight.state = value;
}


sc_integer temalabIfaceServo_get_position(const Temalab* handle)
{
	return handle->ifaceServo.position;
}
void temalabIfaceServo_set_position(Temalab* handle, sc_integer value)
{
	handle->ifaceServo.position = value;
}

/* implementations of all internal functions */

static sc_boolean temalab_check_main_region_LOOP_tr0_tr0(const Temalab* handle)
{
	return handle->iface.leftButtonPressed_raised;
}

static sc_boolean temalab_check_main_region_LOOP_tr1_tr1(const Temalab* handle)
{
	return handle->iface.rightButtonPressed_raised;
}

static sc_boolean temalab_check_main_region_LeftLightOn_tr0_tr0(const Temalab* handle)
{
	return bool_true;
}

static sc_boolean temalab_check_main_region_RightLightOn_tr0_tr0(const Temalab* handle)
{
	return bool_true;
}

static sc_boolean temalab_check_main_region_ServoTurnLeft_tr0_tr0(const Temalab* handle)
{
	return ((handle->timeEvents.temalab_main_region_ServoTurnLeft_tev0_raised) && (handle->ifaceServo.position < 180)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_ServoTurnLeft_tr1_tr1(const Temalab* handle)
{
	return ((bool_true) && (handle->ifaceServo.position == 180)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_ServoTurnRight_tr0_tr0(const Temalab* handle)
{
	return ((bool_true) && (handle->ifaceServo.position == 0)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_ServoTurnRight_tr1_tr1(const Temalab* handle)
{
	return ((handle->timeEvents.temalab_main_region_ServoTurnRight_tev0_raised) && (handle->ifaceServo.position > 0)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_LeftLightOff_tr0_tr0(const Temalab* handle)
{
	return bool_true;
}

static sc_boolean temalab_check_main_region_RightLightOff_tr0_tr0(const Temalab* handle)
{
	return bool_true;
}

static sc_boolean temalab_check_main_region_ServoTurnBackFromLeft_tr0_tr0(const Temalab* handle)
{
	return ((bool_true) && (handle->ifaceServo.position == 90)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_ServoTurnBackFromLeft_tr1_tr1(const Temalab* handle)
{
	return ((handle->timeEvents.temalab_main_region_ServoTurnBackFromLeft_tev0_raised) && (handle->ifaceServo.position > 90)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_ServoTurnBackFromRight_tr0_tr0(const Temalab* handle)
{
	return ((bool_true) && (handle->ifaceServo.position == 90)) ? bool_true : bool_false;
}

static sc_boolean temalab_check_main_region_ServoTurnBackFromRight_tr1_tr1(const Temalab* handle)
{
	return ((handle->timeEvents.temalab_main_region_ServoTurnBackFromRight_tev0_raised) && (handle->ifaceServo.position < 90)) ? bool_true : bool_false;
}

static void temalab_effect_main_region_LOOP_tr0(Temalab* handle)
{
	temalab_exseq_main_region_LOOP(handle);
	temalab_enseq_main_region_LeftLightOn_default(handle);
}

static void temalab_effect_main_region_LOOP_tr1(Temalab* handle)
{
	temalab_exseq_main_region_LOOP(handle);
	temalab_enseq_main_region_RightLightOn_default(handle);
}

static void temalab_effect_main_region_LeftLightOn_tr0(Temalab* handle)
{
	temalab_exseq_main_region_LeftLightOn(handle);
	handle->ifaceServo.position = 90;
	temalab_enseq_main_region_ServoTurnLeft_default(handle);
}

static void temalab_effect_main_region_RightLightOn_tr0(Temalab* handle)
{
	temalab_exseq_main_region_RightLightOn(handle);
	handle->ifaceServo.position = 90;
	temalab_enseq_main_region_ServoTurnRight_default(handle);
}

static void temalab_effect_main_region_ServoTurnLeft_tr0(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnLeft(handle);
	temalab_enseq_main_region_ServoTurnLeft_default(handle);
}

static void temalab_effect_main_region_ServoTurnLeft_tr1(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnLeft(handle);
	temalab_enseq_main_region_ServoTurnBackFromLeft_default(handle);
}

static void temalab_effect_main_region_ServoTurnRight_tr0(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnRight(handle);
	temalab_enseq_main_region_ServoTurnBackFromRight_default(handle);
}

static void temalab_effect_main_region_ServoTurnRight_tr1(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnRight(handle);
	temalab_enseq_main_region_ServoTurnRight_default(handle);
}

static void temalab_effect_main_region_LeftLightOff_tr0(Temalab* handle)
{
	temalab_exseq_main_region_LeftLightOff(handle);
	temalab_enseq_main_region_LOOP_default(handle);
}

static void temalab_effect_main_region_RightLightOff_tr0(Temalab* handle)
{
	temalab_exseq_main_region_RightLightOff(handle);
	temalab_enseq_main_region_LOOP_default(handle);
}

static void temalab_effect_main_region_ServoTurnBackFromLeft_tr0(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnBackFromLeft(handle);
	temalab_enseq_main_region_LeftLightOff_default(handle);
}

static void temalab_effect_main_region_ServoTurnBackFromLeft_tr1(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnBackFromLeft(handle);
	temalab_enseq_main_region_ServoTurnBackFromLeft_default(handle);
}

static void temalab_effect_main_region_ServoTurnBackFromRight_tr0(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnBackFromRight(handle);
	temalab_enseq_main_region_RightLightOff_default(handle);
}

static void temalab_effect_main_region_ServoTurnBackFromRight_tr1(Temalab* handle)
{
	temalab_exseq_main_region_ServoTurnBackFromRight(handle);
	temalab_enseq_main_region_ServoTurnBackFromRight_default(handle);
}

/* Entry action for state 'LeftLightOn'. */
static void temalab_enact_main_region_LeftLightOn(Temalab* handle)
{
	/* Entry action for state 'LeftLightOn'. */
	handle->ifaceLeftLight.state = bool_true;
}

/* Entry action for state 'RightLightOn'. */
static void temalab_enact_main_region_RightLightOn(Temalab* handle)
{
	/* Entry action for state 'RightLightOn'. */
	handle->ifaceRightLight.state = bool_true;
}

/* Entry action for state 'ServoTurnLeft'. */
static void temalab_enact_main_region_ServoTurnLeft(Temalab* handle)
{
	/* Entry action for state 'ServoTurnLeft'. */
	temalab_setTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnLeft_tev0_raised) , 15, bool_true);
	handle->ifaceServo.position += 1;
}

/* Entry action for state 'ServoTurnRight'. */
static void temalab_enact_main_region_ServoTurnRight(Temalab* handle)
{
	/* Entry action for state 'ServoTurnRight'. */
	temalab_setTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnRight_tev0_raised) , 15, bool_true);
	handle->ifaceServo.position -= 1;
}

/* Entry action for state 'LeftLightOff'. */
static void temalab_enact_main_region_LeftLightOff(Temalab* handle)
{
	/* Entry action for state 'LeftLightOff'. */
	handle->ifaceLeftLight.state = bool_false;
}

/* Entry action for state 'RightLightOff'. */
static void temalab_enact_main_region_RightLightOff(Temalab* handle)
{
	/* Entry action for state 'RightLightOff'. */
	handle->ifaceRightLight.state = bool_false;
}

/* Entry action for state 'ServoTurnBackFromLeft'. */
static void temalab_enact_main_region_ServoTurnBackFromLeft(Temalab* handle)
{
	/* Entry action for state 'ServoTurnBackFromLeft'. */
	temalab_setTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnBackFromLeft_tev0_raised) , 15, bool_true);
	handle->ifaceServo.position -= 1;
}

/* Entry action for state 'ServoTurnBackFromRight'. */
static void temalab_enact_main_region_ServoTurnBackFromRight(Temalab* handle)
{
	/* Entry action for state 'ServoTurnBackFromRight'. */
	temalab_setTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnBackFromRight_tev0_raised) , 15, bool_true);
	handle->ifaceServo.position += 1;
}

/* Exit action for state 'ServoTurnLeft'. */
static void temalab_exact_main_region_ServoTurnLeft(Temalab* handle)
{
	/* Exit action for state 'ServoTurnLeft'. */
	temalab_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnLeft_tev0_raised) );		
}

/* Exit action for state 'ServoTurnRight'. */
static void temalab_exact_main_region_ServoTurnRight(Temalab* handle)
{
	/* Exit action for state 'ServoTurnRight'. */
	temalab_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnRight_tev0_raised) );		
}

/* Exit action for state 'ServoTurnBackFromLeft'. */
static void temalab_exact_main_region_ServoTurnBackFromLeft(Temalab* handle)
{
	/* Exit action for state 'ServoTurnBackFromLeft'. */
	temalab_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnBackFromLeft_tev0_raised) );		
}

/* Exit action for state 'ServoTurnBackFromRight'. */
static void temalab_exact_main_region_ServoTurnBackFromRight(Temalab* handle)
{
	/* Exit action for state 'ServoTurnBackFromRight'. */
	temalab_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.temalab_main_region_ServoTurnBackFromRight_tev0_raised) );		
}

/* 'default' enter sequence for state LOOP */
static void temalab_enseq_main_region_LOOP_default(Temalab* handle)
{
	/* 'default' enter sequence for state LOOP */
	handle->stateConfVector[0] = Temalab_main_region_LOOP;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LeftLightOn */
static void temalab_enseq_main_region_LeftLightOn_default(Temalab* handle)
{
	/* 'default' enter sequence for state LeftLightOn */
	temalab_enact_main_region_LeftLightOn(handle);
	handle->stateConfVector[0] = Temalab_main_region_LeftLightOn;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state RightLightOn */
static void temalab_enseq_main_region_RightLightOn_default(Temalab* handle)
{
	/* 'default' enter sequence for state RightLightOn */
	temalab_enact_main_region_RightLightOn(handle);
	handle->stateConfVector[0] = Temalab_main_region_RightLightOn;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ServoTurnLeft */
static void temalab_enseq_main_region_ServoTurnLeft_default(Temalab* handle)
{
	/* 'default' enter sequence for state ServoTurnLeft */
	temalab_enact_main_region_ServoTurnLeft(handle);
	handle->stateConfVector[0] = Temalab_main_region_ServoTurnLeft;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ServoTurnRight */
static void temalab_enseq_main_region_ServoTurnRight_default(Temalab* handle)
{
	/* 'default' enter sequence for state ServoTurnRight */
	temalab_enact_main_region_ServoTurnRight(handle);
	handle->stateConfVector[0] = Temalab_main_region_ServoTurnRight;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LeftLightOff */
static void temalab_enseq_main_region_LeftLightOff_default(Temalab* handle)
{
	/* 'default' enter sequence for state LeftLightOff */
	temalab_enact_main_region_LeftLightOff(handle);
	handle->stateConfVector[0] = Temalab_main_region_LeftLightOff;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state RightLightOff */
static void temalab_enseq_main_region_RightLightOff_default(Temalab* handle)
{
	/* 'default' enter sequence for state RightLightOff */
	temalab_enact_main_region_RightLightOff(handle);
	handle->stateConfVector[0] = Temalab_main_region_RightLightOff;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ServoTurnBackFromLeft */
static void temalab_enseq_main_region_ServoTurnBackFromLeft_default(Temalab* handle)
{
	/* 'default' enter sequence for state ServoTurnBackFromLeft */
	temalab_enact_main_region_ServoTurnBackFromLeft(handle);
	handle->stateConfVector[0] = Temalab_main_region_ServoTurnBackFromLeft;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ServoTurnBackFromRight */
static void temalab_enseq_main_region_ServoTurnBackFromRight_default(Temalab* handle)
{
	/* 'default' enter sequence for state ServoTurnBackFromRight */
	temalab_enact_main_region_ServoTurnBackFromRight(handle);
	handle->stateConfVector[0] = Temalab_main_region_ServoTurnBackFromRight;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void temalab_enseq_main_region_default(Temalab* handle)
{
	/* 'default' enter sequence for region main region */
	temalab_react_main_region__entry_Default(handle);
}

/* Default exit sequence for state LOOP */
static void temalab_exseq_main_region_LOOP(Temalab* handle)
{
	/* Default exit sequence for state LOOP */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state LeftLightOn */
static void temalab_exseq_main_region_LeftLightOn(Temalab* handle)
{
	/* Default exit sequence for state LeftLightOn */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state RightLightOn */
static void temalab_exseq_main_region_RightLightOn(Temalab* handle)
{
	/* Default exit sequence for state RightLightOn */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ServoTurnLeft */
static void temalab_exseq_main_region_ServoTurnLeft(Temalab* handle)
{
	/* Default exit sequence for state ServoTurnLeft */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
	temalab_exact_main_region_ServoTurnLeft(handle);
}

/* Default exit sequence for state ServoTurnRight */
static void temalab_exseq_main_region_ServoTurnRight(Temalab* handle)
{
	/* Default exit sequence for state ServoTurnRight */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
	temalab_exact_main_region_ServoTurnRight(handle);
}

/* Default exit sequence for state LeftLightOff */
static void temalab_exseq_main_region_LeftLightOff(Temalab* handle)
{
	/* Default exit sequence for state LeftLightOff */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state RightLightOff */
static void temalab_exseq_main_region_RightLightOff(Temalab* handle)
{
	/* Default exit sequence for state RightLightOff */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ServoTurnBackFromLeft */
static void temalab_exseq_main_region_ServoTurnBackFromLeft(Temalab* handle)
{
	/* Default exit sequence for state ServoTurnBackFromLeft */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
	temalab_exact_main_region_ServoTurnBackFromLeft(handle);
}

/* Default exit sequence for state ServoTurnBackFromRight */
static void temalab_exseq_main_region_ServoTurnBackFromRight(Temalab* handle)
{
	/* Default exit sequence for state ServoTurnBackFromRight */
	handle->stateConfVector[0] = Temalab_last_state;
	handle->stateConfVectorPosition = 0;
	temalab_exact_main_region_ServoTurnBackFromRight(handle);
}

/* Default exit sequence for region main region */
static void temalab_exseq_main_region(Temalab* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of Temalab.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Temalab_main_region_LOOP :
		{
			temalab_exseq_main_region_LOOP(handle);
			break;
		}
		case Temalab_main_region_LeftLightOn :
		{
			temalab_exseq_main_region_LeftLightOn(handle);
			break;
		}
		case Temalab_main_region_RightLightOn :
		{
			temalab_exseq_main_region_RightLightOn(handle);
			break;
		}
		case Temalab_main_region_ServoTurnLeft :
		{
			temalab_exseq_main_region_ServoTurnLeft(handle);
			break;
		}
		case Temalab_main_region_ServoTurnRight :
		{
			temalab_exseq_main_region_ServoTurnRight(handle);
			break;
		}
		case Temalab_main_region_LeftLightOff :
		{
			temalab_exseq_main_region_LeftLightOff(handle);
			break;
		}
		case Temalab_main_region_RightLightOff :
		{
			temalab_exseq_main_region_RightLightOff(handle);
			break;
		}
		case Temalab_main_region_ServoTurnBackFromLeft :
		{
			temalab_exseq_main_region_ServoTurnBackFromLeft(handle);
			break;
		}
		case Temalab_main_region_ServoTurnBackFromRight :
		{
			temalab_exseq_main_region_ServoTurnBackFromRight(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state LOOP. */
static void temalab_react_main_region_LOOP(Temalab* handle)
{
	/* The reactions of state LOOP. */
	if (temalab_check_main_region_LOOP_tr0_tr0(handle) == bool_true)
	{ 
		temalab_effect_main_region_LOOP_tr0(handle);
	}  else
	{
		if (temalab_check_main_region_LOOP_tr1_tr1(handle) == bool_true)
		{ 
			temalab_effect_main_region_LOOP_tr1(handle);
		} 
	}
}

/* The reactions of state LeftLightOn. */
static void temalab_react_main_region_LeftLightOn(Temalab* handle)
{
	/* The reactions of state LeftLightOn. */
	temalab_effect_main_region_LeftLightOn_tr0(handle);
}

/* The reactions of state RightLightOn. */
static void temalab_react_main_region_RightLightOn(Temalab* handle)
{
	/* The reactions of state RightLightOn. */
	temalab_effect_main_region_RightLightOn_tr0(handle);
}

/* The reactions of state ServoTurnLeft. */
static void temalab_react_main_region_ServoTurnLeft(Temalab* handle)
{
	/* The reactions of state ServoTurnLeft. */
	if (temalab_check_main_region_ServoTurnLeft_tr0_tr0(handle) == bool_true)
	{ 
		temalab_effect_main_region_ServoTurnLeft_tr0(handle);
	}  else
	{
		if (temalab_check_main_region_ServoTurnLeft_tr1_tr1(handle) == bool_true)
		{ 
			temalab_effect_main_region_ServoTurnLeft_tr1(handle);
		} 
	}
}

/* The reactions of state ServoTurnRight. */
static void temalab_react_main_region_ServoTurnRight(Temalab* handle)
{
	/* The reactions of state ServoTurnRight. */
	if (temalab_check_main_region_ServoTurnRight_tr0_tr0(handle) == bool_true)
	{ 
		temalab_effect_main_region_ServoTurnRight_tr0(handle);
	}  else
	{
		if (temalab_check_main_region_ServoTurnRight_tr1_tr1(handle) == bool_true)
		{ 
			temalab_effect_main_region_ServoTurnRight_tr1(handle);
		} 
	}
}

/* The reactions of state LeftLightOff. */
static void temalab_react_main_region_LeftLightOff(Temalab* handle)
{
	/* The reactions of state LeftLightOff. */
	temalab_effect_main_region_LeftLightOff_tr0(handle);
}

/* The reactions of state RightLightOff. */
static void temalab_react_main_region_RightLightOff(Temalab* handle)
{
	/* The reactions of state RightLightOff. */
	temalab_effect_main_region_RightLightOff_tr0(handle);
}

/* The reactions of state ServoTurnBackFromLeft. */
static void temalab_react_main_region_ServoTurnBackFromLeft(Temalab* handle)
{
	/* The reactions of state ServoTurnBackFromLeft. */
	if (temalab_check_main_region_ServoTurnBackFromLeft_tr0_tr0(handle) == bool_true)
	{ 
		temalab_effect_main_region_ServoTurnBackFromLeft_tr0(handle);
	}  else
	{
		if (temalab_check_main_region_ServoTurnBackFromLeft_tr1_tr1(handle) == bool_true)
		{ 
			temalab_effect_main_region_ServoTurnBackFromLeft_tr1(handle);
		} 
	}
}

/* The reactions of state ServoTurnBackFromRight. */
static void temalab_react_main_region_ServoTurnBackFromRight(Temalab* handle)
{
	/* The reactions of state ServoTurnBackFromRight. */
	if (temalab_check_main_region_ServoTurnBackFromRight_tr0_tr0(handle) == bool_true)
	{ 
		temalab_effect_main_region_ServoTurnBackFromRight_tr0(handle);
	}  else
	{
		if (temalab_check_main_region_ServoTurnBackFromRight_tr1_tr1(handle) == bool_true)
		{ 
			temalab_effect_main_region_ServoTurnBackFromRight_tr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void temalab_react_main_region__entry_Default(Temalab* handle)
{
	/* Default react sequence for initial entry  */
	temalab_enseq_main_region_LOOP_default(handle);
}


