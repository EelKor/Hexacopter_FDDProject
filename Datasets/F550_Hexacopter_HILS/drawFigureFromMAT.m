close all; clear
r2d = 180/pi;

%% 데이터 선택
log_filename = 'log174_m1_50fail';

save_dir = [log_filename, '_fig']; % 저장할 디렉토리 이름
load([log_filename,'.mat'])

rc_time = seconds(input_rc_values_var8.Time);
rc_inject = input_rc_values_var8.Var1;

ae_time = seconds(failure_detector_status_fd_motor.Time);
ae_detect = failure_detector_status_fd_motor.Var1;

%start_t = seconds(input_rc_values_var8.Time(1));
%end_t = seconds(input_rc_values_var8.Time(end));
%time = start_t:0.001:end_t;

%% 결과 저장 디렉토리 생성

if ~exist(save_dir, 'dir')
    mkdir(save_dir);
end

%% Plot Fault Injection and Detection Flag
inject = rc_inject > 1799;
inject = double(inject);

figure;
plot(rc_time, inject, 'LineWidth', 3)
hold on;
plot(ae_time, ae_detect, 'r--', 'LineWidth', 3)
grid on;
ylim([-0.2 1.2])
xlabel("Time (s)")
ylabel("Flag")
yticks([0 1]);
legend("Fault Injection", "Fault Detection")

injectIdx = find(inject == 1, 1, 'first');
injectTime = rc_time(injectIdx);
detectIdx = find(ae_detect == 1, 1, 'first');
detectTime = ae_time(detectIdx);

anomaly_detect_time_in_s = (detectTime - injectTime);
title(['M1 50% Fail - ', num2str(anomaly_detect_time_in_s), 's'])

%이미지 저장
saveas(gcf, fullfile(save_dir, 'fault_injection_detection.png'));

%% Display Attitude vs Attitude Command (Roll)

attitude_Time = seconds(AttitudeEuler_Pitch.Time);
attitudeTarget_Time = seconds(AttitudeTargetEuler_PitchTarget.Time);

roll = AttitudeEuler_Roll.Var1 * r2d;
roll_cmd = AttitudeTargetEuler_RollTarget.Var1 * r2d;

figure;
plot(attitude_Time, roll, 'LineWidth', 3);
hold on;
plot(attitudeTarget_Time, roll_cmd, 'r--', 'LineWidth', 3);
grid on;
hold off;
legend("Roll", "Roll Command")
xlabel("Time (s)"); ylabel("Angle (deg)")

% 이미지 저장
saveas(gcf, fullfile(save_dir, 'roll_vs_command.png'));

%% Display Attitude vs Attitude Command (Pitch)

pitch = AttitudeEuler_Pitch.Var1 * r2d;
pitch_cmd = AttitudeTargetEuler_PitchTarget.Var1 * r2d;

figure;
plot(attitude_Time, pitch, 'LineWidth', 3);
hold on;
plot(attitudeTarget_Time, pitch_cmd, 'r--', 'LineWidth', 3);
grid on;
hold off;
legend("Pitch", "Pitch Command")
xlabel("Time (s)"); ylabel("Angle (deg)")

% 이미지 저장
saveas(gcf, fullfile(save_dir, 'pitch_vs_command.png'));

%% Display Attitude vs Attitude Command (Yaw)
yaw = AttitudeEuler_Yaw.Var1 * r2d;
yaw_cmd = AttitudeTargetEuler_YawTarget.Var1 * r2d;

figure;
plot(attitude_Time, yaw, 'LineWidth', 3);
hold on;
plot(attitudeTarget_Time, yaw_cmd, 'r--', 'LineWidth', 3);
grid on;
hold off;
legend("Yaw", "Yaw Command")
xlabel("Time (s)"); ylabel("Angle (deg)")

% 이미지 저장
saveas(gcf, fullfile(save_dir, 'yaw_vs_command.png'));

%% Display PWM
pwm_linewidth = 2;


pwm_time = seconds(actuator_outputs_output_var9.Time);

pwm_m1 = actuator_outputs_output_var1.Var1;
pwm_m2 = actuator_outputs_output_var2.Var1;
pwm_m3 = actuator_outputs_output_var3.Var1;
pwm_m4 = actuator_outputs_output_var4.Var1;
pwm_m5 = actuator_outputs_output_var5.Var1;
pwm_m6 = actuator_outputs_output_var6.Var1;

figure;
plot(pwm_time, pwm_m1, 'LineWidth', pwm_linewidth);
hold on;
plot(pwm_time, pwm_m2, 'LineWidth', pwm_linewidth);
plot(pwm_time, pwm_m3, 'LineWidth', pwm_linewidth);
plot(pwm_time, pwm_m4, 'LineWidth', pwm_linewidth);
plot(pwm_time, pwm_m5, 'LineWidth', pwm_linewidth);
plot(pwm_time, pwm_m6, 'LineWidth', pwm_linewidth);
grid on;
hold off;
legend("M1", "M2", "M3", "M4", "M5", "M6", 'Location', 'southeast')
xlabel("Time (s)"); ylabel("PWM")
ylim([900 2100]);

% 이미지 저장
saveas(gcf, fullfile(save_dir, 'pwm_signals.png'));


%% Altitude
localNED_Time = seconds(LocalNED_Z.Time);
localNEDTarget_Time = seconds(LocalNEDTarget_ZTarget.Time);

altitude = LocalNED_Z.Var1 * (-1);
altitude_cmd = LocalNEDTarget_ZTarget.Var1*(-1);

figure;
plot(localNED_Time,altitude, 'LineWidth', 3);
hold on;
%plot(localNEDTarget_Time,altitude_cmd,'r--', 'LineWidth', 3)
grid on;

