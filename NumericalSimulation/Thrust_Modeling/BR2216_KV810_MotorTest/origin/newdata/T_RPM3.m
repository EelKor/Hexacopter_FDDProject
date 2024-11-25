%% Thrust - PWM
data = csvread('stp_case_3.csv',2,0);

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

%% Thrust - RPM

figure()
plot(rpm1, T1, 'r-');
grid on;

