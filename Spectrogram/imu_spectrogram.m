clear
close all;
clc

load Datasets\소부장_1차년도_25kg_Hexa_0927_정상_로그데이터\소부장_hovering_1.mat

ax = Accel_AccelX.Var1;
ay = Accel_AccelY.Var1;
az = Accel_AccelZ.Var1;
time = Accel_AccelZ.Time;

acc_power = sqrt(ax.^2 + ay.^2 + az.^2);

figure(1) % raw acc_power 그래프
plot(time,acc_power)
grid on;
xlabel("time")
ylabel("m/s^2")


