close all; clear
r2d = 180/pi;

lineWidth = 2;

%% 데이터 선택
log_filename = 'log_16_2025-6-5-14-10-52-SMC-M1_30-1';

save_dir = [log_filename, '_fig']; % 저장할 디렉토리 이름
load([log_filename,'.mat'])

%% 결과 저장 디렉토리 생성

if ~exist(save_dir, 'dir')
    mkdir(save_dir);
end

%% Display Attitude vs Attitude Command (Roll)

attitude_Time = seconds(AttitudeEuler_Pitch.Time);
attitudeTarget_Time = seconds(AttitudeTargetEuler_PitchTarget.Time);

roll = AttitudeEuler_Roll.Var1 * r2d;
roll_cmd = AttitudeTargetEuler_RollTarget.Var1 * r2d;

figure;
plot(attitude_Time, roll, 'LineWidth', lineWidth,'Color','blue');
hold on;
plot(attitudeTarget_Time, roll_cmd, 'r--', 'LineWidth', lineWidth);
grid on;
hold off;
legend("Roll", "Roll Command")
xlabel("Time (s)"); ylabel("Angle (deg)")

xlim([attitude_Time(1), attitude_Time(end)]);
ylim([-20 20]);
title("\phi  vs  \phi_{cmd}")
% 이미지 저장
saveas(gcf, fullfile(save_dir, '1_roll_vs_command.png'));

%% Display Attitude vs Attitude Command (Pitch)

pitch = AttitudeEuler_Pitch.Var1 * r2d;
pitch_cmd = AttitudeTargetEuler_PitchTarget.Var1 * r2d;

figure;
plot(attitude_Time, pitch, 'LineWidth', lineWidth,'Color','blue');
hold on;
plot(attitudeTarget_Time, pitch_cmd, 'r--', 'LineWidth', lineWidth);
grid on;
hold off;
legend("Pitch", "Pitch Command")
xlabel("Time (s)"); ylabel("Angle (deg)")
title("\theta  vs  \theta_{cmd}")

xlim([attitude_Time(1), attitude_Time(end)]);
ylim([-20 20])

% 이미지 저장
saveas(gcf, fullfile(save_dir, '2_pitch_vs_command.png'));

%% Display Attitude vs Attitude Command (Yaw)
yaw = AttitudeEuler_Yaw.Var1 * r2d;
yaw_cmd = AttitudeTargetEuler_YawTarget.Var1 * r2d;

figure;
plot(attitude_Time, yaw, 'LineWidth', lineWidth,'Color','blue');
hold on;
%plot(attitudeTarget_Time, yaw_cmd, 'r--', 'LineWidth', 3);
grid on;
hold off;
legend("Yaw", "Yaw Command")
xlabel("Time (s)"); ylabel("Angle (deg)")
xlim([attitude_Time(1), attitude_Time(end)]);
title("\psi")

% 이미지 저장
saveas(gcf, fullfile(save_dir, '3_yaw_vs_command.png'));

%% Rollrate
rollrate = vehicle_angular_velocity_xyz_var1.Var1 * r2d;
rollrate_t = vehicle_angular_velocity_xyz_var1.Time;
rollrate_cmd = vehicle_rates_setpoint_roll.Var1 * r2d;
rollrate_cmd_t = vehicle_rates_setpoint_roll.Time;

figure;
plot(rollrate_t, rollrate,'LineWidth', lineWidth,'Color','blue');
grid on;
title("p vs p_{sp}");
hold on;
plot(rollrate_cmd_t, rollrate_cmd,'r--', 'LineWidth', lineWidth);
legend("p","p_{sp}");
xlabel("Time (s)"); ylabel("Angular Rate (deg/s)")

saveas(gcf, fullfile(save_dir, '4_rollrate.png'));

%% Pitchrate
pitchrate = vehicle_angular_velocity_xyz_var2.Var1 * r2d;
pitchrate_t = vehicle_angular_velocity_xyz_var2.Time;
pitchrate_cmd = vehicle_rates_setpoint_pitch.Var1 * r2d;
pitchrate_cmd_t = vehicle_rates_setpoint_pitch.Time;

figure;
plot(pitchrate_t, pitchrate,'LineWidth', lineWidth,'Color','blue');
grid on;
title("q vs q_{sp}");
hold on;
plot(pitchrate_cmd_t, pitchrate_cmd,'r--', 'LineWidth', lineWidth);
legend("q","q_{sp}");
xlabel("Time (s)"); ylabel("Angular Rate (deg/s)")

saveas(gcf, fullfile(save_dir, '5_pitchrate.png'));
%% Yawrate
yawrate = Gyro_GyroZ.Var1 * r2d;
yawrate_time = Gyro_GyroZ.Time;
yawrate_cmd_t = vehicle_rates_setpoint_yaw.Time;
yawrate_cmd = vehicle_rates_setpoint_yaw.Var1 * r2d;

figure;
plot(yawrate_time, yawrate, 'LineWidth', lineWidth,'Color','blue');
grid on;
hold on;
plot(yawrate_cmd_t, yawrate_cmd,'r--', 'LineWidth', lineWidth);
legend("Yawrate");
title("r vs r_{sp}");
xlabel("Time (s)"); ylabel("Angular Velocity (deg/s)")
xlim([yawrate_time(1), yawrate_time(end)])

saveas(gcf, fullfile(save_dir, '6_yawrate.png'));


%% ActuatorMotors ( Actuator THR before Fault)
minPWM = 1000; maxPWM = 2000;
pwmlineWidth = 1;

thr_time = actuator_motors_control_var1.Time;
thr_m1 = actuator_motors_control_var1.Var1 * (maxPWM-minPWM) + minPWM;
thr_m2 = actuator_motors_control_var2.Var1 * (maxPWM-minPWM) + minPWM;
thr_m3 = actuator_motors_control_var3.Var1 * (maxPWM-minPWM) + minPWM;
thr_m4 = actuator_motors_control_var4.Var1 * (maxPWM-minPWM) + minPWM;
thr_m5 = actuator_motors_control_var5.Var1 * (maxPWM-minPWM) + minPWM;
thr_m6 = actuator_motors_control_var6.Var1 * (maxPWM-minPWM) + minPWM;

figure;
plot(thr_time, thr_m1, 'LineWidth', pwmlineWidth)
hold on;
plot(thr_time, thr_m2, 'LineWidth', pwmlineWidth)
plot(thr_time, thr_m3, 'LineWidth', pwmlineWidth)
plot(thr_time, thr_m4, 'LineWidth', pwmlineWidth)
plot(thr_time, thr_m5, 'LineWidth', pwmlineWidth)
plot(thr_time, thr_m6, 'LineWidth', pwmlineWidth)
grid on;
hold off;
legend("M1", "M2", "M3", "M4", "M5", "M6", 'Location', 'southwest')
xlabel("Time (s)"); ylabel("PWM")
xlim([thr_time(1), thr_time(end)]); ylim([900 2100]);
title("Actuator PWM")
saveas(gcf, fullfile(save_dir, '7_pwm_signals.png'));

%% Display PWM


pwm_time = seconds(actuator_outputs_output_var9.Time);

pwm_m1 = actuator_outputs_output_var1.Var1;
pwm_m2 = actuator_outputs_output_var2.Var1;
pwm_m3 = actuator_outputs_output_var3.Var1;
pwm_m4 = actuator_outputs_output_var4.Var1;
pwm_m5 = actuator_outputs_output_var5.Var1;
pwm_m6 = actuator_outputs_output_var6.Var1;

figure;
plot(pwm_time, pwm_m1, 'LineWidth', pwmlineWidth);
hold on;
plot(pwm_time, pwm_m2, 'LineWidth', pwmlineWidth);
plot(pwm_time, pwm_m3, 'LineWidth', pwmlineWidth);
plot(pwm_time, pwm_m4, 'LineWidth', pwmlineWidth);
plot(pwm_time, pwm_m5, 'LineWidth', pwmlineWidth);
plot(pwm_time, pwm_m6, 'LineWidth', pwmlineWidth);
grid on;
hold off;
legend("M1", "M2", "M3", "M4", "M5", "M6", 'Location', 'southwest')
xlabel("Time (s)"); ylabel("PWM")
xlim([pwm_time(1), pwm_time(end)]); ylim([900 2100]);
title("Actuator PWM After Fault")
% 이미지 저장
saveas(gcf, fullfile(save_dir, '8_pwm_signals_after_fault.png'));

%% Altitude
localNED_Time = seconds(LocalNED_Z.Time);
localNEDTarget_Time = seconds(LocalNEDTarget_ZTarget.Time);

altitude = LocalNED_Z.Var1 * (-1);
altitude_cmd = LocalNEDTarget_ZTarget.Var1*(-1);

figure;
plot(localNED_Time,altitude, 'LineWidth', lineWidth, 'Color','blue');
hold on;
%plot(localNEDTarget_Time,altitude_cmd,'r--', 'LineWidth', 3)
grid on;
hold off;
legend("Altitude")
ylabel("Altitude")
xlabel("Time (s)")
xlim([localNED_Time(1), localNED_Time(end)]);
title("Altitude")
saveas(gcf, fullfile(save_dir, '9_altitude.png'));


%% 
smc_time = vehicle_attitude_smc_setpoint_phi_cmd.Time;
smc_phi_cmd = vehicle_attitude_smc_setpoint_phi_cmd.Var1;

att_cmd_time = AttitudeTargetEuler_RollTarget.Time;
att_cmd_roll = AttitudeTargetEuler_RollTarget.Var1;

figure;
plot(smc_time, smc_phi_cmd*r2d, 'LineWidth', lineWidth,'Color','blue');
grid on;
hold on;
plot(att_cmd_time, att_cmd_roll*r2d, 'LineWidth', lineWidth,'Color','red')
xlabel("Time (s)");
xlim([smc_time(1), smc_time(end)]);
title("\phi_{cmd}");
legend("LPF Filtered", "Raw")
% 이미지 저장
saveas(gcf, fullfile(save_dir, '10_phi_cmd_vs_lpf_cmd.png'));


%% SMC Datas
smc_time = vehicle_attitude_smc_setpoint_s.Time;
smc_s = vehicle_attitude_smc_setpoint_s.Var1;

figure;
plot(smc_time, smc_s, 'LineWidth', lineWidth,'Color','blue');
grid on;
xlabel("Time (s)");
xlim([smc_time(1), smc_time(end)]);
title("Sliding Surface");
% 이미지 저장
saveas(gcf, fullfile(save_dir, '11_sliding_surface.png'));

%% SMC Tau
smc_time = vehicle_attitude_smc_setpoint_tau_roll.Time;
smc_tau = vehicle_attitude_smc_setpoint_tau_roll.Var1;
pid_tau_roll_time = actuator_controls_control_power_var1.Time;
pid_tau_roll = actuator_controls_control_power_var1.Var1;

figure;
plot(smc_time, smc_s, 'LineWidth', lineWidth,'Color','blue');
grid on;
hold on;
plot(pid_tau_roll_time, pid_tau_roll, 'LineWidth', lineWidth,'Color','red')
xlabel("Time (s)");
xlim([smc_time(1), smc_time(end)]);
title("\tau_{PID} vs \tau_{SMC}");
legend("SMC","PID")
% 이미지 저장
saveas(gcf, fullfile(save_dir, '12_tau_roll_smc_pid.png'));

%%
smc_time = vehicle_attitude_smc_setpoint_e.Time;
smc_e = vehicle_attitude_smc_setpoint_e.Var1;

figure;
plot(smc_time, smc_e, 'LineWidth', lineWidth,'Color','blue');
grid on;
xlabel("Time (s)");
xlim([smc_time(1), smc_time(end)]);
title("e");
% 이미지 저장
saveas(gcf, fullfile(save_dir, '13_error.png'));

%%
smc_time = vehicle_attitude_smc_setpoint_e_dot.Time;
smc_e_dot = vehicle_attitude_smc_setpoint_e_dot.Var1;

figure;
plot(smc_time, smc_e_dot, 'LineWidth', lineWidth,'Color','blue');
grid on;
xlabel("Time (s)");
xlim([smc_time(1), smc_time(end)]);
title("\dot{e}");
% 이미지 저장
saveas(gcf, fullfile(save_dir, '14_error_dot.png'));

%% Phi Command의 미분값들

smc_cmd_time = vehicle_attitude_smc_setpoint_phi_cmd.Time;
smc_phi_cmd = vehicle_attitude_smc_setpoint_phi_cmd.Var1;
smc_phi_cmd_dot = vehicle_attitude_smc_setpoint_phi_cmd_dot.Var1;
smc_phi_cmd_ddot = vehicle_attitude_smc_setpoint_phi_cmd_ddot.Var1;

figure;
subplot(311)
plot(smc_cmd_time, smc_phi_cmd * r2d, 'LineWidth', lineWidth,'Color','blue');
grid on;
xlabel("Time (s)");
ylabel("deg");
xlim([smc_cmd_time(1), smc_cmd_time(end)]);
title('$\mathbf{\phi_{cmd}}$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(312)
plot(smc_cmd_time, smc_phi_cmd_dot * r2d, 'LineWidth', lineWidth,'Color','blue');
grid on;
xlabel("Time (s)");
ylabel("deg/s");
xlim([smc_cmd_time(1), smc_cmd_time(end)]);
title('$\mathbf{\dot{\phi}_{cmd}}$', 'Interpreter', 'latex', 'FontSize', 12);

subplot(313)
plot(smc_cmd_time, smc_phi_cmd_ddot * r2d, 'LineWidth', lineWidth,'Color','blue');
grid on;
xlabel("Time (s)");
ylabel("deg/s^2");
xlim([smc_cmd_time(1), smc_cmd_time(end)]);
title('$\mathbf{\ddot{\phi}_{cmd}}$', 'Interpreter', 'latex', 'FontSize', 12);
% 이미지 저장
saveas(gcf, fullfile(save_dir, '15_phi_cmd_derivates.png'));


%% RC Switch
rc_time = input_rc_values_var10.Time;
rc_ctrl_sw = input_rc_values_var10.Var1;
flag_rc_ctrl_sw = input_rc_values_var10.Var1 > 1800;

rc_doublet = input_rc_values_var7.Var1;
flag_rc_doublet = input_rc_values_var7.Var1 > 1800;

figure;
plot(rc_time, flag_rc_ctrl_sw, 'LineWidth', lineWidth,'Color','red');
grid on;
hold on;
plot(rc_time, flag_rc_doublet, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)");
xlim([rc_time(1), rc_time(end)]);
yticks([0 1]);
title("RC Command");
legend("SMC", "Doublet");
% 이미지 저장
saveas(gcf, fullfile(save_dir, '15_flag_ctrl_sw_doublet.png'));

