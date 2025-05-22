clc; clear; close all

%% === Parameters ===
Ix = 0.005;
Iy = 0.005;
Iz = 0.009;

k1 = 5; k2 = 3; k3 = 1;   % PID-like sliding surface gains
K = 0.1;                 % SMC gain

T_end = 10;             % Simulation time [sec]
dt = 0.001;             % Time step [sec]
N = T_end / dt;

%% === Initialization ===
phi    = 0.3;           % Initial roll angle [rad]
p      = 0;             % Initial roll rate [rad/s]
q      = 0.0;           % Assume q, r are small but nonzero
r      = 0.0;
int_e  = 0;

% Desired values (constant)
phi_d   = 0;
dphi_d  = 0;
ddphi_d = 0;

% Logging
phi_log = zeros(1,N);
p_log   = zeros(1,N);
tau_log = zeros(1,N);
time    = (0:N-1) * dt;

%% === Simulation Loop ===
for i = 1:N
    % === Compute phi_dot ===
    dphi = p + sin(phi)*tan(1e-6)*q + cos(phi)*tan(1e-6)*r; % theta ≈ 0
    
    % === Errors ===
    e  = phi_d - phi;
    de = dphi_d - dphi;
    int_e = int_e + e * dt;
    
    % === Sliding Surface ===
    s = k1 * e + k2 * de + k3 * int_e;
    
    % === Nonlinear coupling term ===
    nonlinear_term = (Iy - Iz) * q * r;  % ≈ 0 in this case
    
    % === Equivalent Control ===
    p_dot_eq = ddphi_d + (k1/k2)*de + (k3/k2)*e;
    tau_eq = Ix * p_dot_eq + nonlinear_term;
    
    % === Final Control Law ===
    tau_phi = tau_eq - K * tanh(s);   % Robust control term
    
    % === Dynamics Update ===
    p_dot = (1/Ix) * (tau_phi - nonlinear_term);
    p = p + p_dot * dt;
    phi = phi + dphi * dt;
    
    % === Logging ===
    phi_log(i) = phi;
    p_log(i)   = p;
    tau_log(i) = tau_phi;
end

%% === Plot Results ===
figure;
subplot(3,1,1)
plot(time, phi_log, 'b', 'LineWidth', 1.5)
ylabel('\phi [rad]')
grid on
title('Roll Angle Response')

subplot(3,1,2)
plot(time, p_log, 'r', 'LineWidth', 1.5)
ylabel('p [rad/s]')
grid on
title('Roll Rate')

subplot(3,1,3)
plot(time, tau_log, 'k', 'LineWidth', 1.5)
ylabel('\tau_\phi [Nm]')
xlabel('Time [s]')
grid on
title('Control Input')
