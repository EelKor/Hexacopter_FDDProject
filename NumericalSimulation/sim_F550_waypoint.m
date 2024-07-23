% waypoint_control_script.m

clear,warning off
Ts=0.001;  % Sampling Time (Fixed Step Size)
F550_data

% Trim data (u0, x0)
load ../trimLin_data/trim_V0

% Initial Gain values
Kp_theta=5;   Kd_theta=1;
Kp_u =0.2;    Ki_u =0.02;
Kp_vs=0.1;    Ki_vs=0.01;
Kp_h =0.1;    Ki_h =0;
Kp_r=0.15;   
Kp_psi=1.6;   Ki_psi=0;

% Waypoint Reference Command
wp_east  = [0   400 500 500   0];
wp_north = [100 100 300 500 300];
wp_alt   = [100 120 150  80  80];
wp_u     = [  3   5   5   4   3];

t_final=550;
tout=sim('F450_waypoint',t_final);

% plot
x=y_out;

figure(1)
plot(x(:,11),x(:,10), 'Linewidth',1.5), hold on
plot(wp_east,wp_north,'x','Linewidth',1.5), hold off
xlabel('East(m)'), ylabel('North(m)'), grid, shg
axis(axis*1.1), shg

figure(2)
subplot(311), plot(tout,57.3*[psi_cmd x(:,9)],'Linewidth',1.5), grid, xlabel('time'),ylabel('psi(deg)'),shg
legend('psi_{ref}','psi')
subplot(312), plot(tout,[u_cmd x(:,1)],'Linewidth',1.5), grid, xlabel('time'),ylabel('U(m/sec)'),shg
legend('u_{ref}','u')
subplot(313), plot(tout,[alt_cmd -x(:,12)],'Linewidth',1.5), grid, xlabel('time'),ylabel('Altitude(m)'),shg
legend('h_{ref}','h')

