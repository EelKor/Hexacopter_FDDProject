#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/vehicle_rates_setpoint.h>

typedef struct actuator_armed_s  px4_Bus_actuator_armed ;
typedef struct actuator_outputs_s  px4_Bus_actuator_outputs ;
typedef struct input_rc_s  px4_Bus_input_rc ;
typedef struct vehicle_attitude_s  px4_Bus_vehicle_attitude ;
typedef struct vehicle_attitude_setpoint_s  px4_Bus_vehicle_attitude_setpoint ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;
typedef struct vehicle_rates_setpoint_s  px4_Bus_vehicle_rates_setpoint ;

#endif
