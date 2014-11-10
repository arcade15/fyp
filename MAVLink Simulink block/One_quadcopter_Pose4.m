function [ViconPose] = GetViconPose(u)
global MyClient;
global QuadRotationMatix;

while (MyClient.GetFrame().Result.Value) ~= (Result.Success)
	fprintf( '.' );
end 



% *********************************
% Testa
% *********************************


% X, Y, Z Global Coordinates of the Quad
Output_GetSegmentGlobalTranslation = MyClient.GetSegmentGlobalTranslation('ureca 1a', 'ureca 1a');
ViconPose(1) = Output_GetSegmentGlobalTranslation.Translation(1);  % X-coordinate
ViconPose(2) = Output_GetSegmentGlobalTranslation.Translation(2);  % Y-coordinate
ViconPose(3) = Output_GetSegmentGlobalTranslation.Translation(3);  % Z-coordinate
 
% Euler Angles
QuadEulerXYZ = MyClient.GetSegmentGlobalRotationEulerXYZ('ureca 1a', 'ureca 1a');
ViconPose(4) = QuadEulerXYZ.Rotation(1); % Roll
ViconPose(5) = QuadEulerXYZ.Rotation(2); % Pitch
ViconPose(6) = QuadEulerXYZ.Rotation(3); % Yaw

% *********************************
% 1st Marker
% *********************************

% % X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('ureca 1a', 'marker1');
ViconPose(7) = Output_GetMarkerGlobalTranslation.Translation(1);
ViconPose(8) = Output_GetMarkerGlobalTranslation.Translation(2);
ViconPose(9) = Output_GetMarkerGlobalTranslation.Translation(3);

%  *********************************
%  2nd Marker
%  *********************************


% X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('ureca 1a', 'marker2');
ViconPose(10) = Output_GetMarkerGlobalTranslation.Translation(1);
ViconPose(11) = Output_GetMarkerGlobalTranslation.Translation(2);
ViconPose(12) = Output_GetMarkerGlobalTranslation.Translation(3);

% *********************************
% 3nd Marker
% *********************************

% X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('ureca 1a', 'marker3');
ViconPose(13) = Output_GetMarkerGlobalTranslation.Translation(1);
ViconPose(14) = Output_GetMarkerGlobalTranslation.Translation(2);
ViconPose(15) = Output_GetMarkerGlobalTranslation.Translation(3);

% *********************************
% 4nd Marker
% *********************************

% X, Y, Z Global Coordinates of the Marker
Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('ureca 1a', 'marker4');
ViconPose(16) = Output_GetMarkerGlobalTranslation.Translation(1);
ViconPose(17) = Output_GetMarkerGlobalTranslation.Translation(2);
ViconPose(18) = Output_GetMarkerGlobalTranslation.Translation(3);
% 
% % *********************************
% % 5nd Marker
% % *********************************
% 
% % X, Y, Z Global Coordinates of the Marker
% Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation('ureca 1a', 'marker5');
% ViconPose(19) = Output_GetMarkerGlobalTranslation.Translation(1);
% ViconPose(20) = Output_GetMarkerGlobalTranslation.Translation(2);
% ViconPose(21) = Output_GetMarkerGlobalTranslation.Translation(3);


end 



