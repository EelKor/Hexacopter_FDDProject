clear; clc; close all;

run ../F550_data.m
x0 = [0 0 0 0 0 0 0 0 0 0 0 -100]; % initial Condition

%% Run Simulation
out = sim("F550_CompareCA.slx");

%% Plot 
% pinvCA_states =
% [ u,v,w,p,q,r,phi,theta,psi,x,y,z] 1x12 vector

% pinvCA_cmd = 
% [p_sp, q_sp, r_sp, phi_sp, theta_sp, w_sp, z_sp] 1x7 vector

label_states = {'u [m/s]','v [m/s]','w [m/s]','p [deg/s]','q [deg/s]','r [deg/s]','phi [deg]','theta [deg]','psi [deg]','x [m]','y [m]','z [m]'};
label_cmds = {'p_sp','q_sp','r_sp','phi_sp','theta_sp','w_sp','z_sp'};
label_cmds_index = {0,0,6,1,2,3,4,5,0,0,0,7};

%% Plot psuedo-inverse CA
% Fig size - 왼쪽 하단 모서리 (100,100), 너비 1200px, 높이 900px
fig_size = [100 100 1200 900];
linewidth = 1.0;


figure('Position', fig_size); 
for i = 1:12
    subplot(4,3,i);
    
    % 셀 배열의 내용을 중괄호 {}로 접근
    current_state = label_states{i};
    current_cmd_index = label_cmds_index{i};
    
    % 상태 데이터 플롯
    plot(out.tout, out.pinvCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
    hold on;
    grid on;
    
    % 명령 데이터가 0이 아닌 경우 플롯
    if ~(current_cmd_index == 0)
        plot(out.tout, out.pinvCA_cmd(:,label_cmds_index{i}), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
    end
    
    % 제목 설정
    title(current_state);
    
    % 범례 추가
    %legend('show');
    
    hold off;
end
sgtitle("Psuedo-Inverse CA")
print(gcf, 'Psuedo-Inverse CA','-dpng','-r300'); 
%% Plot quadratic programming CA
figure('Position', fig_size); 
for i = 1:12
    subplot(4,3,i);
    
    % 셀 배열의 내용을 중괄호 {}로 접근
    current_state = label_states{i};
    current_cmd_index = label_cmds_index{i};
    
    % 상태 데이터 플롯
    plot(out.tout, out.qpCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
    hold on;
    grid on;
    
    % 명령 데이터가 0이 아닌 경우 플롯
    if ~(current_cmd_index == 0)
        plot(out.tout, out.qpCA_cmd(:,label_cmds_index{i}), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
    end
    
    % 제목 설정
    title(current_state);
    
    % 범례 추가
    %legend('show');
    
    hold off;
end
sgtitle("Quadratic Programming CA")
print(gcf, 'Quadratic Programming CA','-dpng','-r300'); 

%% Plot quadratic programming CA - Throttle Commands
figure('Position', fig_size); 
plot(out.tout, out.qpCA_throttle,'linewidth',1);
title("Quadratic Programming CA - Throttle [0-1]")
ylim([-0.2 1]);
grid on;
legend('M1','M2','M3','M4','M5','M6');
print(gcf, 'Quadratic Programming CA-Throttle','-dpng','-r300'); 


%% Plot Static Mixer CA
figure('Position', fig_size); 
for i = 1:12
    subplot(4,3,i);
    
    % 셀 배열의 내용을 중괄호 {}로 접근
    current_state = label_states{i};
    current_cmd_index = label_cmds_index{i};
    
    % 상태 데이터 플롯
    plot(out.tout, out.staticCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
    hold on;
    grid on;
    
    % 명령 데이터가 0이 아닌 경우 플롯
    if ~(current_cmd_index == 0)
        plot(out.tout, out.staticCA_cmd(:,label_cmds_index{i}), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
    end
    
    % 제목 설정
    title(current_state);
    
    % 범례 추가
    %legend('show');
    
    hold off;
end
sgtitle("Static Mixer CA")
print(gcf, 'Static Mixer CA','-dpng','-r300'); 

close all;


%% 각 CA별 비교
% Pitch Angle
i = 8;

figure('Position', [100 100 900 900]); 
i = 8;

subplot(3,1,1);
plot(out.tout, out.staticCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.staticCA_cmd(:,5), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Static CA")

subplot(3,1,2);
plot(out.tout, out.pinvCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.pinvCA_cmd(:,5), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Psuedo-Inverse CA")

subplot(3,1,3);
plot(out.tout,out.qpCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.qpCA_cmd(:,5), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Quadratic Programming CA")

sgtitle("Pitch Angle [deg]")
print(gcf, 'Pitch Angle [deg]','-dpng','-r300'); 

% Roll Angle
figure('Position', [100 100 900 900]); 
i = 7;

subplot(3,1,1);
plot(out.tout, out.staticCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.staticCA_cmd(:,4), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Static CA")

subplot(3,1,2);
plot(out.tout, out.pinvCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.pinvCA_cmd(:,4), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Psuedo-Inverse CA")

subplot(3,1,3);
plot(out.tout,out.qpCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.qpCA_cmd(:,4), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Quadratic Programming CA")

sgtitle("Roll Angle [deg]")
print(gcf, 'Roll Angle [deg]','-dpng','-r300'); 

%% Yaw Angle
figure('Position', [100 100 900 900]); 
i = 9;

subplot(3,1,1);
plot(out.tout, out.staticCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.staticCA_cmd(:,6), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Static CA")

subplot(3,1,2);
plot(out.tout, out.pinvCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.pinvCA_cmd(:,6), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Psuedo-Inverse CA")

subplot(3,1,3);
plot(out.tout,out.qpCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.qpCA_cmd(:,6), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Quadratic Programming CA")

sgtitle("Yaw Angle [deg]")
print(gcf, 'Yaw Angle [deg]','-dpng','-r300'); 

%%  Z Position
figure('Position', [100 100 900 900]); 
i = 12;

subplot(3,1,1);
plot(out.tout, out.staticCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.staticCA_cmd(:,7), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Static CA")

subplot(3,1,2);
plot(out.tout, out.pinvCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.pinvCA_cmd(:,7), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Psuedo-Inverse CA")

subplot(3,1,3);
plot(out.tout,out.qpCA_states(:,i), 'b', 'DisplayName', 'State','LineWidth',linewidth);
hold on; grid on;
plot(out.tout, out.qpCA_cmd(:,7), 'r--', 'DisplayName', 'Command','LineWidth',linewidth);
title("Quadratic Programming CA")

sgtitle("Z Position [m]")
print(gcf, 'Z Position [m]','-dpng','-r300'); 