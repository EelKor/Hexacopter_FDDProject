close all
clc
dt =0.05;
t=(0:dt:10);
plot(tout,FDI,'r',tout,FDI2,'b','LineWidth',3)
hold on
xline(3,'--','LineWidth',2);
xlim([2.95 3.2])
ylim([0 6.5])
xlabel('Time (s)')
ylabel('Fault actuator number')
legend('Fault condition(Symmetry residual)','Fault condition(RPM residual)','FontSize', 16)
title('Fault detection & isolation','FontSize', 16)
set(gca,'XTick',[2.95:0.01:3.2])
grid on

figure 
plot(tout,R3_measure,'r',t,R3_estimation,'b','LineWidth',3)
legend('RPM3 Measure','RPM3 Estimation','FontSize', 16)
title('RPM compare (Measurement, Estimation)','FontSize', 16)
grid on

figure
subplot(4,1,1)
plot(t,residual(:,1),'r','LineWidth',2)
yline(0.5,'--','LineWidth',2);
yline(-0.5,'--','LineWidth',2);
xlabel('Time (s)')
ylabel('Residual 1')
legend('Residual','Threshold','FontSize', 16)
ylim([-1.5 1.5])
% xlim([2.8 3.2])
title('p','FontSize', 20)
grid on

subplot(4,1,2)
plot(t,residual(:,2),'r','LineWidth',2)
yline(0.03,'--','LineWidth',2);
yline(-0.03,'--','LineWidth',2);
xlabel('Time (s)')
ylabel('Residual 2')
legend('Residual','Threshold','FontSize', 16)
% xlim([2.8 3.2])
ylim([-0.1 0.1])
title('q','FontSize', 20)
grid on

subplot(4,1,3)
plot(t,residual(:,3),'r','LineWidth',2)
yline(0.03,'--','LineWidth',2);
yline(-0.03,'--','LineWidth',2);
xlabel('Time (s)')
ylabel('Residual 3')
legend('Residual','Threshold','FontSize', 16)
% xlim([2.8 3.2])
ylim([-0.1 0.1])
title('r','FontSize', 20)
grid on

subplot(4,1,4)
plot(t,residual(:,4),'r','LineWidth',2)
yline(1,'--','LineWidth',2);
xlabel('Time (s)')
ylabel('Residual 4')
legend('Residual','Threshold','FontSize', 16)
% xlim([2.8 3.2])
ylim([-7 7])
title('a_z','FontSize', 20)
grid on

%%%%%%%%% health %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     

figure
subplot(3,2,1)
plot(t,health(:,1),'r','LineWidth',2)
xlabel('Time (s)')
ylabel('health coefficient')
legend('h_1','FontSize', 16)
ylim([0.7 1.15])
% xlim([2.8 3.2])
title('h_1','FontSize', 20)
grid on

subplot(3,2,3)
plot(t,health(:,2),'r','LineWidth',2)
xlabel('Time (s)')
ylabel('health coefficient')
legend('h_2','FontSize', 16)
ylim([0.7 1.15])
title('h_2','FontSize', 20)
grid on

subplot(3,2,5)
plot(t,health(:,3),'r','LineWidth',2)
xlabel('Time (s)')
ylabel('health coefficient')
legend('h_3','FontSize', 16)
ylim([0.7 1.15])
title('h_3','FontSize', 20)
grid on

subplot(3,2,2)
plot(t,health(:,4),'r','LineWidth',2)
xlabel('Time (s)')
ylabel('health coefficient')
legend('h_4','FontSize', 16)
ylim([0.7 1.15])
title('h_4','FontSize', 20)
grid on

subplot(3,2,4)
plot(t,health(:,5),'r','LineWidth',2)
xlabel('Time (s)')
ylabel('health coefficient')
legend('h_5','FontSize', 16)
ylim([0.7 1.15])
title('h_5','FontSize', 20)
grid on

subplot(3,2,6)
plot(t,health(:,6),'r','LineWidth',2)
xlabel('Time (s)')
ylabel('health coefficient')
legend('h_6','FontSize', 16)
ylim([0.7 1.15])
title('h_6','FontSize', 20)
grid on