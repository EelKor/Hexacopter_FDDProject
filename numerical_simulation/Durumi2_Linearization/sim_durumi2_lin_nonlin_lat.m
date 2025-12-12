% sim_durumi2_lin_nonlin_lat.m

clear

durumi2_init
load durumi2_trim_100
load durumi2_linmodel_100

sim_model='durumi2_comp_lin_nonlin_lat.slx';

C_lat=eye(length(A_lat));
D_lat=B_lat*0;

u_da=3;
u_dr=3;

% Simulation
simout=sim(sim_model,15);

% states: x=[u  v  w  p   q  r  phi theta psi  x  y  z]
%            1  2  3  4   5  6   7  8     9    10 11 12

y1   = Lin + x0([2 4 6 7])';
y2   = NonLin;
tout = simout;

figure(1)
n=6; m=1; k=1;

subplot(n,m,k), k=k+1; plot(tout, uin(:,1),   'LineWidth',1.5), ylabel('\delta_a (deg)'), grid
subplot(n,m,k), k=k+1; plot(tout, uin(:,2),   'LineWidth',1.5), ylabel('\delta_r'), grid
subplot(n,m,k), k=k+1; plot(tout, [y1(:,1) y2(:,1)], 'LineWidth',1.5), ylabel('V(kts)'), grid
legend('Linear','NonLinear')
subplot(n,m,k), k=k+1; plot(tout, [57.3*y1(:,2)  57.3*y2(:,2)], 'LineWidth',1.5), ylabel('p(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, [57.3*y1(:,3)  57.3*y2(:,3)], 'LineWidth',1.5), ylabel('r(deg/sec)'), grid
subplot(n,m,k), k=k+1; plot(tout, [57.3*y1(:,4)  57.3*y2(:,4)], 'LineWidth',1.5), ylabel('phi(deg)'), grid

