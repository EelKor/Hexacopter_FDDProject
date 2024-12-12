% sim_durumi2_lin_nonlin_lon.m

clear
warning off

durumi2_init

load durumi2_trim_100
load durumi2_linmodel_100

sim_model='durumi2_comp_lin_nonlin_lon.slx';

C_lon=eye(length(A_lon));
D_lon=B_lon*0;

u_de=2;
u_th=0.1;

% Simulation
simout=sim(sim_model,40);

% states: x=[u  v  w  p   q  r  phi theta psi  x  y  z]
%            1  2  3  4   5  6   7  8     9    10 11 12
y1   = Lin + x0([1 3 5 8])';
y2   = NonLin;
tout=simout;

figure(1)
n=6; m=1; k=1;

subplot(n,m,k), k=k+1; plot(tout, uin(:,1),   'LineWidth',1.5), ylabel('\delta_e (deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, uin(:,2),   'LineWidth',1.5), ylabel('throttle'), grid
subplot(n,m,k), k=k+1; plot(tout, [y1(:,1) y2(:,1)],   'LineWidth',1.5), ylabel('U(kts)'), grid
legend('Linear','NonLinear')
subplot(n,m,k), k=k+1; plot(tout, [y1(:,2) y2(:,2)],   'LineWidth',1.5), ylabel('W(kts)'), grid
subplot(n,m,k), k=k+1; plot(tout, [57.3*y1(:,3) 57.3*y2(:,3)], 'LineWidth',1.5), ylabel('q(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, [57.3*y1(:,4) 57.3*y2(:,4)], 'LineWidth',1.5), ylabel('theta(deg)'), grid

