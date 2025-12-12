%% Simulaiton Results: LC62_PIDControl.slx 
% close all;
clc
% ------------------------------------------------------------------------------
line_width = 2.5;
fontsize = 15; %18
t = out.tout;

%% States graph (Altitude and 3-axis Attitude)
% Data Define
X_ref = out.X_ref;
Y_ref = out.Y_ref;
Z_ref = out.Z_ref;
X_pid = out.X_pid;
Y_pid = out.Y_pid;
Z_pid = out.Z_pid;
% ------------------------------------------------------------------------------
U_ref_pid = out.U_ref_pid;
V_ref_pid = out.V_ref_pid;
W_ref_pid = out.W_ref_pid;
U_pid = out.U_pid;
V_pid = out.V_pid;
W_pid = out.W_pid;
% ------------------------------------------------------------------------------
phi_ref    = out.phi_ref;
theta_ref = out.theta_ref;
psi_ref    = out.psi_ref;
% ------------------------------------------------------------------------------
phi_pid   = out.phi_pid;
theta_pid = out.theta_pid;
psi_pid   = out.psi_pid;
% ------------------------------------------------------------------------------
p_ref_pid = out.p_ref_pid;
q_ref_pid = out.q_ref_pid;
r_ref_pid = out.r_ref_pid;
% ------------------------------------------------------------------------------
p_pid = out.p_pid;
q_pid = out.q_pid;
r_pid = out.r_pid;

% ===========================================
figure('windowstyle','docked','name','X-Y-Z')
% X position
subplot(3,1,1)
plot(t,X_ref,'--','linewidth',line_width)
hold on; grid on;
plot(t,X_pid,'linewidth',line_width)
ylim([0 12]);
% xlabel('time [s]'); 
ylabel('X [m]');
legend('Ref','X')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% Y position
subplot(3,1,2)
plot(t,Y_ref,'--','linewidth',line_width)
hold on; grid on;
plot(t,Y_pid,'linewidth',line_width)
ylim([0 12]);
% xlabel('time [s]'); 
ylabel('Y [m]');
legend('Ref','Y')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% Z position
subplot(3,1,3)
plot(t,Z_ref,'--','linewidth',line_width)
hold on; grid on;
plot(t,Z_pid,'linewidth',line_width)
ylim([0 12]);
xlabel('time [s]'); 
ylabel('Z [m]');
legend('Ref','Z')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
figure('windowstyle','docked','name','phi-theta-psi')
% phi
subplot(3,1,1)
plot(t,phi_ref,'--','linewidth',line_width)
hold on; grid on;
plot(t,phi_pid,'linewidth',line_width)
% ylim([-1 1]);
% xlabel('time [s]'); 
ylabel('\phi [deg]'); 
legend('Ref','\phi')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% theta
subplot(3,1,2)
plot(t,theta_ref,'--','linewidth',line_width)
hold on; grid on;
plot(t,theta_pid,'linewidth',line_width)
% ylim([-1 1]);
% xlabel('time [s]'); 
ylabel('\theta [deg]');
legend('Ref','\theta')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% psi
subplot(3,1,3)
plot(t,psi_ref,'--','linewidth',line_width)
hold on; grid on;
plot(t,psi_pid,'linewidth',line_width)
% ylim([-1 1]);
xlabel('time [s]'); ylabel('\psi [deg]');
legend('Ref','\psi')
set(gca,'FontSize',fontsize,'fontWeight','bold')

% ===========================================
figure('windowstyle','docked','name','U-V-W')
% U velocity
subplot(3,1,1)
plot(t,U_ref_pid,'--','linewidth',line_width)
hold on; grid on;
plot(t,U_pid,'linewidth',line_width)
% ylim([-1 1]);
% xlabel('time [s]'); 
ylabel('U [m/s]');
legend('Ref','U')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% V velocity
subplot(3,1,2)
plot(t,V_ref_pid,'--','linewidth',line_width)
hold on; grid on;
plot(t,V_pid,'linewidth',line_width)
% ylim([-1 1]);
% xlabel('time [s]'); 
ylabel('V [m/s]');
legend('Ref','V')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% W velocity
subplot(3,1,3)
plot(t,W_ref_pid,'--','linewidth',line_width)
hold on; grid on;
plot(t,W_pid,'linewidth',line_width)
% ylim([-1 1]);
xlabel('time [s]'); 
ylabel('W [m/s]');
legend('Ref','W')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
figure('windowstyle','docked','name','p-q-r')
% p
subplot(3,1,1)
plot(t,p_ref_pid,'--','linewidth',line_width)
hold on; grid on;
plot(t,p_pid,'linewidth',line_width)
% ylim([-1 1]);
% xlabel('time [s]'); 
ylabel('p [deg/s]');
legend('Ref','p')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% q
subplot(3,1,2)
plot(t,q_ref_pid,'--','linewidth',line_width)
hold on; grid on;
plot(t,q_pid,'linewidth',line_width)
% ylim([-1 1]);
% xlabel('time [s]'); 
ylabel('q [deg/s]');
legend('Ref','q')
set(gca,'FontSize',fontsize,'fontWeight','bold')
% ------------------------------------------------------------------------------
% r
subplot(3,1,3)
plot(t,r_ref_pid,'--','linewidth',line_width)
hold on; grid on;
plot(t,r_pid,'linewidth',line_width)
% ylim([-1 1]);
xlabel('time [s]'); ylabel('r [deg/s]');
legend('Ref','r')
set(gca,'FontSize',fontsize,'fontWeight','bold')
%% Motor Command
PWM1_cmd = out.PWM1_cmd; PWM2_cmd = out.PWM2_cmd; PWM3_cmd = out.PWM3_cmd;
PWM4_cmd = out.PWM4_cmd; PWM5_cmd = out.PWM5_cmd; PWM6_cmd = out.PWM6_cmd;

figure('windowstyle','docked','name','u')
plot(t,PWM1_cmd,t,PWM2_cmd,t,PWM3_cmd,t,PWM4_cmd,t,PWM5_cmd,t,PWM6_cmd,'linewidth',line_width)
grid on; ylim([1000 2000]);
xlabel('time [s]'); ylabel('PWM');
legend('PWM1_{cmd}','PWM2_{cmd}','PWM3_{cmd}','PWM4_{cmd}','PMW5_{cmd}','PWM6_{cmd}')
set(gca,'FontSize',fontsize,'fontWeight','bold')