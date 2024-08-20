
% RfluData를 1000hz 간격으로 보간한 뒤 FFT 수행

load ./Datasets/RFlyData_imu_hovering.mat
timeDurations = duration(0, 0, log762023615103120sensoraccel0.timestamp*1e-6, 'Format', 'hh:mm:ss.SSSSSS');

log762023615103120sensoraccel0.timestamp = timeDurations;

Fs = 1000; % hz
TT = table2timetable(log762023615103120sensoraccel0);
TT2 = retime(TT,'regular','linear','TimeStep',seconds(1/Fs));
Length = height(TT2);
fft_acc_x = fft(TT2.x);

% 가속도 데이터 플롯 
figure(1)
subplot(3,1,1)
plot(TT2.timestamp,TT2.x);

subplot(3,1,2)
plot(TT2.timestamp, TT2.y);

subplot(3,1,3)
plot(TT2.timestamp, TT2.z);

% FFT 수행
figure(2)
plot(Fs/Length*(1000:Length-1000), abs(fft_acc_x(1000:Length-1000)))
title("Complex MAngitude of fft Spectrum")
xlabel("f (Hz)")
ylabel("|fft(X)|")