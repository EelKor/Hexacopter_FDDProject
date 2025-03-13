#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/input_rc.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>

typedef struct input_rc_s  px4_Bus_input_rc ;
typedef struct sensor_gyro_s  px4_Bus_sensor_gyro ;
typedef struct vehicle_local_position_s  px4_Bus_vehicle_local_position ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;

#endif
