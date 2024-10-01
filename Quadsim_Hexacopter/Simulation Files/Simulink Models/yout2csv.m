%% Save Flight Logs as csv
% Index 33
% time, 
% P, Q, R, 
% Phi, Theta, Psi, 
% U, V, W, 
% X, Y, Z, 
% THR1, THR2, THR3, THR4, THR5, THR6,
% RPM1, RPM2, RPM3, RPM4, RPM5, RPM6,
% Phi_cmd, The_cmd, Psi_cmd, Alt_cmd,
% X_cmd, Y_cmd,
% ax, ay, az


time = datetime('now','Format','uuuuMMdd''T''HHmmss');
time_str = char(time);
fileName = "FlightLog_"+time_str+".csv";

idx = ["time","P","Q","R","Phi","Theta","Psi","U","V","W","X","Y","Z",...
    "RPM1","RPM2","RPM3","RPM4","RPM5","RPM6","THR1","THR2","THR3","TJR4","THR5","THR6",...
    "Phi_cmd","Theta_cmd","Psi_cmd","Alt_cmd","X_cmd","Y_cmd","Ax","Ay","Az","Fault_M1","Fault_M2","Fault_M3","Fault_M4","Fault_M5","Fault_M6"];
length(idx)
data = horzcat(tout, yout);
data = vertcat(idx, data);
writematrix(data,fileName,'Delimiter',',');


