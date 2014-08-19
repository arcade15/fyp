%% Level-2 M file S-Function for Neural Network Adaptive Control.
%   by Zhao Weihua
%   09Jan2011 , please get permission from Zhao Weihua (zhao0079@gmail.com) before use



%% 

function msfcn_Adaptive_NN_HeightOnly(block)

  setup(block);
  
%endfunction

function setup(block)
  %% read parameters from the Dialogbox
  block.NumDialogPrms  = 16;
  n = block.DialogPrm(1).Data; 
  r = block.DialogPrm(2).Data; 
  n2 = block.DialogPrm(3).Data; 
  NN_ST = block.DialogPrm(4).Data; 
 
%   global n r n2 NN_ST

  
  %% Register number of input and output ports
  block.NumInputPorts  = 4;
  block.NumOutputPorts = 4;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;
 
  %% Input Ports setup

  block.InputPort(1).Dimensions        = 1;
  block.InputPort(1).SamplingMode = 'Sample';
  block.InputPort(1).DirectFeedthrough = true;


  block.InputPort(2).Dimensions        = 1;
  block.InputPort(2).SamplingMode = 'Sample';
  block.InputPort(2).DirectFeedthrough = true;
  


  block.InputPort(3).Dimensions        = 1;
  block.InputPort(3).SamplingMode = 'Sample';
  block.InputPort(3).DirectFeedthrough = true;
  

  block.InputPort(4).Dimensions        = 1;
  block.InputPort(4).SamplingMode = 'Sample';
  block.InputPort(4).DirectFeedthrough = false;

  
  %% Output Ports setup

  block.OutputPort(1).Dimensions       = 1;
  block.OutputPort(1).SamplingMode = 'Sample';


  block.OutputPort(2).Dimensions       = 1;
  block.OutputPort(2).SamplingMode = 'Sample';
  

  block.OutputPort(3).Dimensions       = [2+2*n-r,n2];
  block.OutputPort(3).SamplingMode = 'Sample';
  

  block.OutputPort(4).Dimensions       = n2 + 1;
  block.OutputPort(4).SamplingMode = 'Sample';
  
  %% Set block sample time to inherited
  block.SampleTimes = [NN_ST, 0];
  
  %% Set the block simStateComliance to default (i.e., same as a built-in block)
  block.SimStateCompliance = 'DefaultSimState';

  %% Register methods
  block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
  block.RegBlockMethod('InitializeConditions',    @InitConditions);  
  block.RegBlockMethod('Outputs',                 @Output);  
%   block.RegBlockMethod('Update',                  @Update);  
  
%endfunction

function DoPostPropSetup(block)
 %% Setup Dwork
  n = block.DialogPrm(1).Data;
  r = block.DialogPrm(2).Data;
  n2 = block.DialogPrm(3).Data;
%   NN_ST = block.DialogPrm(4).Data;
%   global n r n2
%%
  block.NumDworks = 3+n2;
  
%  (1) Dwork(1):  
  block.Dwork(1).Name = 'NN_input_eta'; 
  block.Dwork(1).Dimensions      = 2 + 2*n -r;
  block.Dwork(1).DatatypeID      = 0;
  block.Dwork(1).Complexity      = 'Real';
  block.Dwork(1).UsedAsDiscState = true;
  
%  (2) From Dwork(2) 

  for i = 2:(1+n2)
        block.Dwork(i).Name = strcat('V_',int2str(i)); 
        block.Dwork(i).Dimensions      = 2 + 2*n -r;
        block.Dwork(i).DatatypeID      = 0;
        block.Dwork(i).Complexity      = 'Real';
        block.Dwork(i).UsedAsDiscState = true;
  end
  
 
% (3) 
  block.Dwork(2+n2).Name = 'W'; 
  block.Dwork(2+n2).Dimensions      = n2+1;
  block.Dwork(2+n2).DatatypeID      = 0;
  block.Dwork(2+n2).Complexity      = 'Real';
  block.Dwork(2+n2).UsedAsDiscState = true;
  
% (4) 
  block.Dwork(3+n2).Name = 'z_f'; 
  block.Dwork(3+n2).Dimensions      = 1;
  block.Dwork(3+n2).DatatypeID      = 0;
  block.Dwork(3+n2).Complexity      = 'Real';
  block.Dwork(3+n2).UsedAsDiscState = true;

%endfunction

function InitConditions(block)

  %% Initialize Dwork
  n = block.DialogPrm(1).Data;
  r = block.DialogPrm(2).Data;
  n2 = block.DialogPrm(3).Data;


%  (1) 
  block.Dwork(1).Data = [1;zeros(1 + 2*n -r,1)]; % 

  
  

  for i = 2:(1+n2)
      block.Dwork(i).Data = [0;zeros(1+2*n-r,1)];%
  end

%  (3)
  block.Dwork(2+n2).Data = [0;zeros(n2,1)]; %
  %
  
%  (4)
  block.Dwork(3+n2).Data = 0;
%endfunction

function Output(block)
  n = block.DialogPrm(1).Data; 
  r = block.DialogPrm(2).Data; 
  n2 = block.DialogPrm(3).Data; 
  NN_ST = block.DialogPrm(4).Data; 
  GAMA_V = block.DialogPrm(5).Data; 
  gama_V = block.DialogPrm(6).Data; 
  GAMA_W = block.DialogPrm(7).Data; 
  gama_W = block.DialogPrm(8).Data; 
  alpha = block.DialogPrm(9).Data; 
  c_f = block.DialogPrm(10).Data;
  c_y_tilt =  block.DialogPrm(11).Data;
  NN_Deadzone = block.DialogPrm(12).Data; 
  y_min = block.DialogPrm(13).Data; 
  y_max = block.DialogPrm(14).Data;%
  v_min = block.DialogPrm(15).Data; %
  v_max = block.DialogPrm(16).Data;%
%
% 
  

%% construction of input: X_bar (eta)
eta = block.Dwork(1).Data;
temp_y_window = eta(3:1+n);%
temp_v_window = eta(3+n:1+2*n-r);%
eta(2) = block.InputPort(1).Data; %s
eta(3) = block.InputPort(2).Data; %s
eta(3+n) = block.InputPort(3).Data; % 
% s
eta(4:2+n) = temp_y_window;
eta(4+n:2+2*n-r) = temp_v_window;

% 
% delta 
eta(2:2+n) = (eta(2:2+n)-y_min)/(y_max - y_min); %n
eta(3+n:2+2*n-r) = (eta(3+n:2+2*n-r)-v_min)/(v_max - v_min); %

% update Dwork(1)
block.Dwork(1).Data = eta;

%% construction of V, W
% construc old, i.e., V(n) 
V = [];
for i = 2:(1+n2)
    V = [V,block.Dwork(i).Data]; % 
end

% construct W
W = block.Dwork(2+n2).Data;
%% constructioni of neurons:SIGMA, SIGMA_DOT
Z = V'*eta;
% SIGMA
SIGMA = [1;zeros(n2,1)];% the 
% t
SIGMA_DOT_temp = zeros(n2,1);%cons
% 
a = linspace(0.5,1,n2);
for i = 2:(1+n2)
    SIGMA(i) = 1/(1+exp(-a(i-1)*Z(i-1)));
    SIGMA_DOT_temp(i-1) = a(i-1)*exp(-a(i-1)*Z(i-1))/...
        (1+exp(-a(i-1)*Z(i-1)))^2;
end
% 
SIGMA_DOT = diag(SIGMA_DOT_temp);
SIGMA_DOT = [zeros(1,n2);SIGMA_DOT];%

%%  Construct v_ad 
v_ad = W'*SIGMA;

%% construct z_f, v_bar
z_f = block.Dwork(3+n2).Data;
%
y_tilt = block.InputPort(1).Data - block.InputPort(2).Data;

% 
z = c_f*z_f + c_y_tilt*y_tilt + 1*block.InputPort(4).Data;
% 
v_bar = - 0.1*(10+ norm(V,'fro')+norm(W,'fro'))*sign(z)*abs(y_tilt);
% 
%% update z_f and Dwork(3+n2)
%

% u
if abs(y_tilt) > NN_Deadzone;
    z_f = (v_ad - z_f*(0.5-alpha/NN_ST))/(alpha/NN_ST+0.5);
end

% upda
block.Dwork(3+n2).Data = z_f;
%% update V and W
% 
if (abs(y_tilt) > NN_Deadzone) ;%&& (abs(v_ad) < v_max);
    W_temp = W;
    W = (-GAMA_W*(SIGMA-SIGMA_DOT*V'*eta)*z - W*(GAMA_W*gama_W*abs(z)/2-1/NN_ST))/...
        (1/NN_ST + GAMA_W*gama_W*abs(z)/2);
    V_temp = V;%V(n)
    V = (-GAMA_V*eta*z*W'*SIGMA_DOT - V*(GAMA_V*gama_V*abs(z)/2-1/NN_ST))/...
        (1/NN_ST + GAMA_V*gama_V*abs(z)/2);
end

% 
for i = 2:(1+n2)
    block.Dwork(i).Data = V(:,i-1);
end
% u
block.Dwork(2+n2).Data = W;

%% output
%
block.OutputPort(1).Data = v_ad;
% o
block.OutputPort(2).Data = v_bar;
% output(
block.OutputPort(3).Data = V;
% output(
block.OutputPort(4).Data = W;

%endfunction


