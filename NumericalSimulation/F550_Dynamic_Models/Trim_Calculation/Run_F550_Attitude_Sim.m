clc; clear; close all;

F550_data
%% 
r2d = 180/pi;

%% Define PID Controller Gain
MC_ROLL_P = 7.5;
MC_PITCH_P = 7.5;

MC_ROLLRATE_P = 0.15;
MC_ROLLRATE_I = 0.2;
MC_ROLLRATE_D = 0.003;

MC_PITCHRATE_P = 0.15;
MC_PITCHRATE_I = 0.2;
MC_PITCHRATE_D = 0.003;

MC_YAWRATE_P = 0.2;
MC_YAWRATE_I = 0.1;
MC_YAWRATE_D = 0.0;

%% Define SMC Gains
k_smc_p = 10;
k_smc_i = 3;
k_smc_d = 1.5;

ks = 30;
kp = 30;

epsilon = 0.03;

%% Run Simulation
model = 'F550_Attitude_ctrl_ver2023b';
simout = sim(model, 30);

%% Plot
linewidth = 1;

figure;
plot(simout.SCAS.theta_cmd *r2d, 'r--', 'linewidth',linewidth);
hold on;
plot(simout.State.theta *r2d, 'b', 'linewidth',linewidth);
hold off;
grid on;
title("Pitch" , Interpreter="latex", FontSize=14);
xlabel("t [s]" , Interpreter="latex", FontSize=14);
ylabel("$\theta$ [rad]", Interpreter="latex", FontSize=14)
legend("\theta_{cmd}","\theta")


figure;
plot(simout.SCAS.phi_cmd *r2d, 'r--', 'linewidth',linewidth)
hold on;
plot(simout.State.phi *r2d, 'b', 'linewidth',linewidth);
hold off;
grid on;
title("Roll" , Interpreter="latex", FontSize=14);
xlabel("t [s]" , Interpreter="latex", FontSize=14);
ylabel("$\phi$ [rad]", Interpreter="latex", FontSize=14)
legend("\phi_{cmd}","\phi")

