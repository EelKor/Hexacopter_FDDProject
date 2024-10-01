% prepare environment and generate aircraft trajectory
clear all;
close all;
clc;
data = zeros(400,6);
 
% x, y and z coordinates
data(:,1) = 0;
data(:,2) = .5:.5:200;
data(:,3) = 500;
 
% pitch, yaw and roll angle values
data(:,4) = 0;
data(:,5) = 0;
data(21:380,6) = (1:1:360)/57.3;
 
% prepare aircraft simulation model
new_object('aircraft.mat',data,...
'model','f-16.mat','edge',[.1 .1 .1],'face',[.1 .1 .1],...
'path','on','pathcolor',[.89 .0 .27],'pathwidth',1,'scale',1);
 
% generate the scene and save the result as gif file
flypath('aircraft.mat',...
'animate','on','step',3,...
'font','Georgia','fontsize',10,...
'view',[35 45],'window',[700 700],...
'output','aileron_roll.gif',...
'xlim',[-20 20],'ylim',[0 200],'zlim',[480 520]);