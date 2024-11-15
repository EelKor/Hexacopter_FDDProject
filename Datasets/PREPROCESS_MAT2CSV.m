clear; close all; clc;

fileName = "F550HILS_M1_10Fail_ULOG_100HZ"

load(fileName+'.mat');
TT = synchronize(Accel_AccelZ,Gyro_GyroX,Gyro_GyroY,Gyro_GyroZ, ...
    AttitudeEuler_Pitch,AttitudeEuler_Roll,AttitudeEuler_Yaw, ...
    Attitude_cmd_pitch_body,Attitude_cmd_roll_body,Attitude_cmd_yaw_body,Attitude_cmd_thrust_body, ...
    input_rc_values_var8, 'union','nearest')
uniqueTT = unique(TT);

writetimetable(uniqueTT,fileName+'.csv')
