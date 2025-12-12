%==========================================================================================%
%                                       DURUMI II UAV Model                                %
%==========================================================================================%

%-------------------------------------< Aerodynamic Data >---------------------------------%
load durumi2_data

 % === Aerodynamic Data Tuning 
   Ct1 = Ct1 * 1.5;              %++++ 2005.11.14              
   CM = CM + 0.06;               %+++++ 2005.11.11  Adjusted by considering de_trim using flight data
   dCM_de =  dCM_de/1;           %+++++ 2005.11.11  Adjusted using run_sim with dat2.mat
   CN_beta = CN_beta/2;          %+++++ 2005.07.22  Adjusted by comparing with other airplane's data
 
  sc_1 = 1/1.3;    % Scale factor for rolling moment from Flap CD
  sc_2 = 1/1.5;    % Scale factor for rolling moment from Aileron CD
  
%------------------------------------------< Geometry >------------------------------------%
 span = 15.784 ;                     % Wing Span                      (ft)
 cbar =  1.181 ;                     % Wing Mean Aerodynamic Chord    (ft)
 Sw   = 16.318 ;                     % Wing Surface Area              (ft^2)
 Dp   =  2;                          % Propeller Diameter (ft) 
 y_h  = 1.329/2;                     % Y-axis location of HT A/C

 L_Ail_R_In  = -5.02 ;              % Length of Inboard  Aileron_R Center     (ft)
 L_Ail_L_In  =  5.02 ;              % Length of Inboard  Aileron_L Center     (ft)
 L_Ail_R_Out = -6.40 ;              % Length of Outboard Aileron_R Center     (ft)
 L_Ail_L_Out =  6.40 ;              % Length of Outboard Aileron_R Center     (ft)  
 L_Flap_R    = -1.7224;
 L_Flap_L    =  1.7224;
 
%-----------------------------------------< Mass  Data >-----------------------------------%
 g     = 32.2  ;                     % Gravity Constant               (ft/sec^2)
 GTOW  = 72.43 ;                     % Gross Take-Off Weight          (lb)
 Mass  = GTOW/32.2 ;                 % Mass                           (slug) 
 CG    = 0.33;                       % 2005.11.14   
 
 dxcg  = (0.25-CG)*cbar ;
 Zcg   = 0.01 ;
 dzcg  = Zcg*cbar;

%  dxcg=0; dzcg=0;

 I_xx  = 13.37 ;    % Roll Inertia                   (slug ft^2)
 I_yy  =  9.66 ;    % Pitch Inetia                   (slug ft^2)
 I_zz  = 16.44 ;    % Yaw Inertia                    (slug ft^2)
 I_xz  =    0  ;    % Lateral Cross Inertia          (slug ft^2)
 Inertia = [I_xx  0  -I_xz  ;  0  I_yy  0  ;  -I_xz  0  I_zz ] ;
 Inertia_inv=inv(Inertia);

 i_th=0.01;
 z_th=0.01;
