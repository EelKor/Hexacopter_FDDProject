% data = csvread('stp_case_1_conti.csv',2,0);
% 
% cons = (120*pi)^2/(1.225*0.2413^4);
% RPM1 = data(:,7);
% T1 = cons.*data(:,5);
% 
% Ct = T1./(RPM1.^2)
% 
% 
% plot(RPM1, Ct);
% xlabel('RPM 값');
% ylabel('추력');
% 
% legend('회귀된 다항식');
% title('RPM 값에 따른 추력 곡선');

%% Thrust - PWM
data = csvread('stp_case_1.csv',2,0);

d_pwm1 = data(:,2);
d_T1 = 9.8.*data(:,5);

pwm1 = min(d_pwm1):1:max(d_pwm1); % 선형 보간할 x 값 범위

T1 = interp1(d_pwm1, d_T1, pwm1, 'linear');
plot(pwm1, T1, 'r-');
grid on;

%% RPM - PWM

d_rpm1 = data(:,7);

rpm1 = interp1(d_pwm1, d_rpm1, pwm1, 'linear');
figure()
plot(pwm1, rpm1, 'r-');
grid on;
title("PWM vs RPM")
xlabel("PWM")
ylable("RPM")
%% Thrust - RPM

figure()
plot(rpm1, T1, 'r-');
grid on;

%% Ct - rpm

cons = (120*pi)^2/(1.225*0.2413^4);
Ct = (cons.*T1)./(rpm1.^2);

figure()
plot(rpm1, Ct);
ylim([0 1])

ct = Ct(1,101:end);              % from pwm 1100~2000, under 1100, 쓸모없는 데이터
Ctm = sum(ct(1:end))/(numel(ct))
% cq_v = Torque./(RPM.*RPM)
% Cqm_V = sum(cq_v(1:end))/(numel(cq_v)) 