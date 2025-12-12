%{
 This demonstration script generates a timeseries in the workspace
 After saving the workspace, you can load it later to a position controler 
 as a timeseries of position commands.

Additional quadcopter modeling and simulation materials available at:
github.com/dch33/Quad-Sim

Copyright (C) 2014 D. Hartman, K. Landis, S. Moreno, J. Kim, M. Mehrer

License:
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU LESSER GENERAL PUBLIC LICENSE as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU LESSER GENERAL PUBLIC LICENSE
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
%}

%% This demonstration script generates a timeseries in the workspace
% 

%% WP - Front Flight
X = [ 0, 0, 20,20,20]; % meters
Y = [ 0, 0, 0, 0,0]; % meters
Z = [ 3, 3, 3, 3,3]; % meters
t = [ 0, 5, 10, 15, 20]; % seconds
Psi = [ 0, 0, 0, 0, 0]*pi/180; % radians
%X = 1.5*X;
%Y = 1.5*Y;
path.x = timeseries(X,t);
path.y = timeseries(Y,t);
path.z = timeseries(Z,t);
path.psi = timeseries(Psi,t);
clear X Y Z t Psi
uisave('path', 'front')

%% WP - right Flight
X = [ 0, 0, 0,0,0]; % meters
Y = [ 0, 0, 20, 20, 20]; % meters
Z = [ 3, 3, 3, 3,3]; % meters
t = [ 0, 5, 10, 15, 20]; % seconds
Psi = [ 0, 0, 0, 0, 0]*pi/180; % radians
%X = 1.5*X;
%Y = 1.5*Y;
path.x = timeseries(X,t);
path.y = timeseries(Y,t);
path.z = timeseries(Z,t);
path.psi = timeseries(Psi,t);
clear X Y Z t Psi
uisave('path', 'front')

%% Diamond
% X = [ 0, 10, 0, -10, 0, 10, 0, -10, 0, 10, 0, -10, 0, 10, 0, -10, 0, 10, 0, -10, 0]; % meters
% Y = [ 0, 0, 10, 0, -10, 0, 10, 0, -10, 0, 10, 0, -10, 0, 10, 0, -10, 0, 10, 0, -10]; % meters
% Z = [ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3]; % meters
% t = [ 0, 5, 10,15,20,25,30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]; % seconds
% Psi = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; % radians
% X = 1.5*X;
% Y = 1.5*Y;
% path.x = timeseries(X,t);
% path.y = timeseries(Y,t);
% path.z = timeseries(Z,t);
% path.psi = timeseries(Psi,t);
% clear X Y Z t Psi
% uisave('path', 'Diamond')

%% Rectangle
% X = 10+(10*rand(1,21));
% Y = 10+(10*rand(1,21));
% X = [ 0, 20, 20, 0, -20, -20, -20, 0, 20, 20, 20, 0, -20, -20, -20, 0, 20, 20, 20, 20, 0]; % meters
% Y = [ 0, 0, 20, 20, 20, 0, -20, -20, -20, 0, 20, 20, 20, 0, -20, -20, -20, 0, 0, 20, 0]; % meters
% Z = [ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3]; % meters
% t = [ 0, 5, 10,15,20,25,30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]; % seconds
% Psi = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; % radians
% path.x = timeseries(X,t);
% path.y = timeseries(Y,t);
% path.z = timeseries(Z,t);
% path.psi = timeseries(Psi,t);
% clear X Y Z t Psi
% uisave('path', 'rec20')

%% Hovering
rng('shuffle');
X = zeros(1, 21); % meters
Y = zeros(1, 21); % meters
Z = [ 3, 3, 6, 6, 3, 3, 6, 6, 3, 3, 6, 6, 3, 3, 6, 6, 3, 3, 3, 3, 3]; % meters
t = [ 0, 5, 10,15,20,25,30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]; % seconds
Psi = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; % radians
path.x = timeseries(X,t);
path.y = timeseries(Y,t);
path.z = timeseries(Z,t);
path.psi = timeseries(Psi,t);
clear X Y Z t Psi
uisave('path', 'Hover')

%% Rectangle
% X = [ 0, 20, 20, 0, -20, -20, -20, 0, 20, 20, 20, 0, -20, -20, -20, 0, 20, 20, 20, 20, 0]; % meters
% Y = [ 0, 0, 20, 20, 20, 0, -20, -20, -20, 0, 20, 20, 20, 0, -20, -20, -20, 0, 0, 20, 0]; % meters
% Z = [ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3]; % meters
% t = [ 0, 5, 10,15,20,25,30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]; % seconds
% Psi = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; % radians
% path.x = timeseries(X,t);
% path.y = timeseries(Y,t);
% path.z = timeseries(Z,t);
% path.psi = timeseries(Psi,t);
% clear X Y Z t Psi
% uisave('path', 'rec20')
% + 20
% X = [ 0, 20, 0, -20, 0, 20, 0, -20, 0, 20, 0, -20, 0, 20, 0, -20, 0, 20, -20, 0, 0]; % meters
% Y = [ 0, 0, 20, 0, -20, 0, 20, 0, -20, 0, 20, 0, -20, 0, 20, 0, -20, 0, 0, -20, 0]; % meters
% Z = [ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3]; % meters
% t = [ 0, 5, 10,15,20,25,30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]; % seconds
% Psi = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; % radians
% path.x = timeseries(X,t);
% path.y = timeseries(Y,t);
% path.z = timeseries(Z,t);
% path.psi = timeseries(Psi,t);
% clear X Y Z t Psi
% uisave('path', '+20')
%clear path
% 
%% This demonstration script generates a timeseries in the workspace
% Survay Pattern
wp_long = 10; %[m] Survay 패턴에서 긴쪽 거리
wp_short = 10; %[m] Survay 패턴의 짧은쪽 거리
wp_z = 5; %[m] survay 패턴의 고도 변화

X = [ 0, wp_long, wp_long, 0, wp_long, wp_long, 0, wp_long, wp_long, 0, wp_long,wp_long, 0, wp_long, wp_long, 0]; % meters
Y = [ 0, 0, wp_short, wp_short, wp_short*2, wp_short*2, wp_short*3, wp_short*3, wp_short*4, wp_short*4, wp_short*5, wp_short*5,wp_short*6, wp_short*6, wp_short*7, wp_short*7]; % meters
Z = [ 0, wp_z, wp_z*2, wp_z*3, wp_z*2, wp_z, wp_z*2, wp_z*3, wp_z*4, wp_z*3, wp_z*2, wp_z, wp_z*2, wp_z*3, wp_z*2, wp_z]; % meters
t = [ 0, 20,40,60,80,100,120, 140, 160, 180,200,220,240,260,280,300]; % seconds
% Psi = [90,180,90,0,90,180,90,0,90,180,90,0,90,180,90,0] * pi/180; % radians
Psi = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0] * pi/180; % radians
path.x = timeseries(X,t);
path.y = timeseries(Y,t);
path.z = timeseries(Z,t);
path.psi = timeseries(Psi,t);
clear X Y Z t Psi
uisave('path', 'Path_Survay_10x10')
%clear path
%% This demonstration script generates a much more absurd path.
% % Note that it takes a long time to run and each step is five seconds
% % Team 37 Plot
% X = [0,0,-1,1,4,   1,  4,   1,4,5.5,6.25,4.75,6.25,7,7.25,8.5,9.25,10,10,12,  14, 12,  14,12,15,17, 16,15,0];% meters 28pts
% X = X*0.3048;
% Y = [0,3, 3,3,3,2.25,1.5,0.75,0,  3, 1.5, 1.5, 1.5,0,   3,   0,  3, 0, 0, 0,0.75,1.5,2.25, 3, 3, 3,1.5, 0,0];
% Y = Y*0.3048;
% Z = [3];
% 
% tXY = 1:10:10*length(X); % seconds
% 
% Psi = [0]; % radians
% path.x = timeseries(X,tXY);
% path.y = timeseries(Y,tXY);
% path.z = timeseries(Z,tXY);
% path.psi = timeseries(Psi,tXY);
% clear X Y Z tXY Psi 
% uisave('path', 'Path_Team')
% %clear path