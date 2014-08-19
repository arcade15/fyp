function [sys,x0,str,ts] = opgui_sf(t,x,u,flag,Ts)

switch flag,
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes(Ts); 
  case 2,
    sys=mdlUpdate(t,x,u,Ts);
  case 3,
    sys = mdlOutputs(t,x,u); 
  case { 1, 4, 9 },
    sys = [0 0 0 0];
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end

function [sys,x0,str,ts]=mdlInitializeSizes(Ts)

sizes = simsizes;

sizes.NumContStates  = 0;
sizes.NumDiscStates  = 1;
sizes.NumOutputs     = 0;
sizes.NumInputs      = 5;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;

sys = simsizes(sizes);
x0  = [0];
str = [];
ts  = [Ts 0];
OpGUI;

function sys=mdlUpdate(t,x,u,Ts)
fig = get_param(gcbh,'UserData');
sys=x;
if ishandle(fig), 
  if strcmp(get(fig,'Visible'),'on'),
      
      chnd = findobj(fig,'Tag','editbox');
      chnc = findobj(fig,'Tag','text1');
      chna = findobj(fig,'Tag','text2');
      chnb = findobj(fig,'Tag','text3');
      if u(3) > 1,
          set(chnd,'backgroundcolor','r');
          set(chnc,'foregroundcolor','r');
          set(chnc,'backgroundcolor','r');
          set(chnb,'foregroundcolor','r');
          set(chnb,'backgroundcolor','r');
          set(chna,'foregroundcolor','r');
          set(chna,'backgroundcolor','r');
        ctd = num2str(u(3) - 1);
        set(chnd,'String',ctd);
      elseif u(3) == 1,
          ctd = num2str(u(3) - 1);
          set(chnc,'foregroundcolor','g');
          set(chnc,'backgroundcolor','g');
          set(chnd,'backgroundcolor','g');
          set(chnb,'foregroundcolor','g');
          set(chnb,'backgroundcolor','g');
          set(chna,'foregroundcolor','g');
          set(chna,'backgroundcolor','g');
          set(chnd,'String','GO!');
      elseif u(3) == 0,
        detik = num2str(u(1));
        menit = num2str(u(2));
        ct1 = num2str(u(4));
        ct2 = num2str(u(5));
        set(chnd,'backgroundcolor','g');
        set(chnc,'backgroundcolor','g');
        set(chnc,'foregroundcolor','black');
        set(chna,'backgroundcolor','g');
        set(chna,'foregroundcolor','black');
        set(chnb,'backgroundcolor','g');
        set(chnb,'foregroundcolor','black');
        if u(1) > 9 && u(2) > 9,
            set(chnd,'String',[menit,' : ',detik]);
        elseif u(1) > 9 && u(2) < 10,
            set(chnd,'String',['0',menit,' : ',detik]);
        elseif u(1) < 10 && u(2) > 9,
            set(chnd,'String',[menit,' : 0',detik]);
        elseif u(1) < 10 && u(2) < 10,
            set(chnd,'String',['0',menit,' : 0',detik]);
        end
        if u(4) > 9 && u(5) > 9,
            set(chnb,'String',[ct2,' : ',ct1]);
        elseif u(4) > 9 && u(5) < 10,
            set(chnb,'String',['0',ct2,' : ',ct1]);
        elseif u(4) < 10 && u(5) > 9,
            set(chnb,'String',[ct2,' : 0',ct1]);
        elseif u(4) < 10 && u(5) < 10,
            set(chnb,'String',['0',ct2,' : 0',ct1]);
        end
      end

      
  end
end

function sys = mdlOutputs(t,x,u)

 sys = [];

