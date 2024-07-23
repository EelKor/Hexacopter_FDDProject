function launchQuadcopterPlant()%

%   Copyright 2021 The MathWorks, Inc.
    evalin('base', 'InitQuadcopterPlantVars;');
    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'QuadcopterDynamics','UAV_Dynamics_Autopilot_Communication.slx'));
end
