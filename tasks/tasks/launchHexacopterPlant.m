function launchHexacopterPlant
%

%   Copyright 2021 The MathWorks, Inc.

    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'HexacopterDynamics','UAV_Dynamics_Autopilot_Communication.slx'));
end
