clc; clear; close all;

load log_165_pitch_doublet.mat

ax_time = Accel_AccelX.Time;
ax = Accel_AccelX.Var1;

figure;
plot(ax_time,ax,'b','LineWidth',1)
hold on;
ax_lpf = lowpass(ax,0.8);
plot(ax_time,ax_lpf,'r','LineWidth',1)


