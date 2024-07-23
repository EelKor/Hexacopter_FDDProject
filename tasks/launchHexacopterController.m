function launchHexacopterController
%

%   Copyright 2021 The MathWorks, Inc.

    project = simulinkproject;
    projectRoot = project.RootFolder;
    %evalin('base', 'InitSimulinkPlantVars;');
    %evalin('base', 'InitQuadcopterControllerVars;');
    evalin('base','InitHexacopterControllerVars');
    %evalin('base', 'InitOnboardAlgorithmVars;');
    %evalin('base', 'Init3DVisualizationVars;');
    open_system(fullfile(projectRoot,'controller','Hexacopter_ControllerWithNavigation.slx'));
end
