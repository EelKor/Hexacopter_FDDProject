clear; close all; clc;

tic
disp("Processing...")

%% 불러올 비행데이터 MAT 파일 입력
load("./2025-04-16/log167_m1_30fail_flight_100hz.mat");

%% 
vars = who;
timetables = cell(1,length(vars));
for i = 1:length(vars)
    timetables{i} = eval(vars{i});
end
% 시간 설정
startTime = seconds(0);
dt = seconds(1/100);  % dt를 duration으로 정의
endTime = seconds(height(timetables{1}) * 1/100);
% Time 벡터 생성
Time = (startTime:dt:endTime)';


var1_cells = cell(size(timetables));
for i = 1:length(timetables)
    if(istimetable(timetables{i}))
        var1_cells{i} = timetables{i}.Var1;
    end
end

TT = timetable(Time(1:end-1), var1_cells{1:end});
TT.Properties.VariableNames = vars(1:end);

T = timetable2table(TT);
T.Time = seconds(T.Time);
writetable(T,'result.csv')

% TT = synchronize(timetables{1:end},timetables{1}.Time,'intersection');
% uniqueTT = unique(TT);
% 
% uniqueTT.Properties.VariableNames = vars(1:end);
% 
% writetimetable(uniqueTT,strcat(name,'.csv'))
% 
% processingTime = toc;
% fprintf("Job Finished, Processing time: %f seconds\n",processingTime)
