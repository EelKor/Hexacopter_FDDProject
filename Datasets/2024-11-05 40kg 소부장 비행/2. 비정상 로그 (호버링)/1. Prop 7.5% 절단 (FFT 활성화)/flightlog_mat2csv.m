%% flightlog_mat2csv.m 
% 작성: 석사과정 이승신
% 최초작성: 2024. 07. 22
% 최종수정: 2024. 10. 08
% 
% 버전 표기법 
% VX.Y.Z X: Major Change Y: Minor Change Z: Bug-fix

% 수정내용: 
% 2024.07.22(이승신) V1.0 :
% 파이썬 환경으로 넘어갈때 MAT형식을 CSV 형식으로 변환 하는 스크립트
%
% 2024.10.08(이승신) V1.1: 
% 일반적인 상황에서 사용가능하게, 작업공간에 선언된 변수명을 읽어 와서 파일 변환하도록 수정
%
% 2024.10.15(이승신) V1.1.1:
% 파일 이름에 확장자가 포함되어 저장되는 버그 수정

%% 

clear; close all; clc;

name = input('Enter the MAT Filename w/o file extension(e.g. data.mat(X) data(O)): ','s');


tic
disp("Processing...")
load(string(name)+".mat");
vars = who;
timetables = cell(1,length(vars));
for i = 1:length(vars)
    timetables{i} = eval(vars{i});
end

TT = synchronize(timetables{1:end-1},'first','previous');

TT.Properties.VariableNames = vars(1:end-1);
writetimetable(TT,strcat(name,'.csv'))

processingTime = toc;
fprintf("Job Finished, Processing time: %f seconds\n",processingTime)
