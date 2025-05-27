close all; clear
r2d = 180/pi;

lineWidth = 2;

%% 데이터 선택
log_filename = 'log_01_smc_2025-5-27-21-11-52';

save_dir = [log_filename, '_fig']; % 저장할 디렉토리 이름
load([log_filename,'.mat'])

%% 결과 저장 디렉토리 생성

if ~exist(save_dir, 'dir')
    mkdir(save_dir);
end

%% SMC 관련 결과 Plotting
smc_time = seconds(vehicle_attitude_smc_setpoint_e.Time);

% tau_roll
smc_tau_roll = vehicle_attitude_smc_setpoint_tau_roll.Var1;
figure;
plot(smc_time,smc_tau_roll, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("SMC \tau_{\phi}")
saveas(gcf, fullfile(save_dir, 'smc_tau_roll.png'));

% S
smc_s = vehicle_attitude_smc_setpoint_s.Var1;
figure;
plot(smc_time,smc_s, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("Sliding Surface (s)")
saveas(gcf, fullfile(save_dir, 'smc_sliding_surface.png'));

% R
smc_r = vehicle_attitude_smc_setpoint_r.Var1;
figure;
plot(smc_time,smc_r, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("Reachability Condition (R)")
saveas(gcf, fullfile(save_dir, 'smc_r.png'));


% H(x)
smc_hx = vehicle_attitude_smc_setpoint_hx.Var1;

figure;
plot(smc_time,smc_hx, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("H(x)")
saveas(gcf, fullfile(save_dir, 'smc_hx.png'));

% e
smc_e = vehicle_attitude_smc_setpoint_e.Var1;
smc_e_dot = vehicle_attitude_smc_setpoint_e_dot.Var1;
smc_integral_e = vehicle_attitude_smc_setpoint_integral_e.Var1;

figure;
subplot(311)
plot(smc_time,smc_e, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("e")

subplot(312)
plot(smc_time,smc_e_dot, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("e dot")

subplot(313)
plot(smc_time,smc_integral_e, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("Integral e")

saveas(gcf, fullfile(save_dir, 'smc_error.png'));

% Phi_cmd, dot, ddot
smc_phi_cmd = vehicle_attitude_smc_setpoint_phi_cmd.Var1;
smc_phi_cmd_dot = vehicle_attitude_smc_setpoint_phi_cmd_dot.Var1;
smc_phi_cmd_ddot = vehicle_attitude_smc_setpoint_phi_cmd_ddot.Var1;

figure;
subplot(311)
plot(smc_time,smc_phi_cmd, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("phi command")

subplot(312)
plot(smc_time,smc_phi_cmd_dot, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("phi command dot")

subplot(313)
plot(smc_time,smc_phi_cmd_ddot, 'LineWidth', lineWidth,'Color','blue');
xlabel("Time (s)"); ylabel("");
grid on;
xlim([smc_time(1), smc_time(end)]);
title("phi command ddot")

saveas(gcf, fullfile(save_dir, 'phi_commands.png'));

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
ylim([-40 40]);
title("\phi  vs  \phi_{cmd}")
% 이미지 저장
saveas(gcf, fullfile(save_dir, 'roll_vs_command.png'));

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
saveas(gcf, fullfile(save_dir, 'pitch_vs_command.png'));

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
saveas(gcf, fullfile(save_dir, 'yaw_vs_command.png'));

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

saveas(gcf, fullfile(save_dir, 'rollrate.png'));

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

saveas(gcf, fullfile(save_dir, 'pitchrate.png'));
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

saveas(gcf, fullfile(save_dir, 'yawrate.png'));

%% Display PWM


pwm_time = seconds(actuator_outputs_output_var9.Time);

pwm_m1 = actuator_outputs_output_var1.Var1;
pwm_m2 = actuator_outputs_output_var2.Var1;
pwm_m3 = actuator_outputs_output_var3.Var1;
pwm_m4 = actuator_outputs_output_var4.Var1;
pwm_m5 = actuator_outputs_output_var5.Var1;
pwm_m6 = actuator_outputs_output_var6.Var1;

figure;
plot(pwm_time, pwm_m1, 'LineWidth', lineWidth);
hold on;
plot(pwm_time, pwm_m2, 'LineWidth', lineWidth);
plot(pwm_time, pwm_m3, 'LineWidth', lineWidth);
plot(pwm_time, pwm_m4, 'LineWidth', lineWidth);
plot(pwm_time, pwm_m5, 'LineWidth', lineWidth);
plot(pwm_time, pwm_m6, 'LineWidth', lineWidth);
grid on;
hold off;
legend("M1", "M2", "M3", "M4", "M5", "M6", 'Location', 'southwest')
xlabel("Time (s)"); ylabel("PWM")
ylim([900 2100]);
xlim([pwm_time(1), pwm_time(end)]);
title("Actuator PWM After Fault")
% 이미지 저장
saveas(gcf, fullfile(save_dir, 'pwm_signals_after_fault.png'));

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
xlim([thr_time(1), thr_time(end)]);
title("Actuator PWM")
saveas(gcf, fullfile(save_dir, 'pwm_signals.png'));

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
saveas(gcf, fullfile(save_dir, 'altitude.png'));

%%
close all;
