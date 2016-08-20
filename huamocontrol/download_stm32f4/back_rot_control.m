% BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY
% FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN
% OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES
% PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
% OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
% MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS
% TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE
% PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING,
% REPAIR OR CORRECTION.
% 
%   12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
% WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR
% REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,
% INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING
% OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED
% TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY
% YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER
% PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGES.

% Rotations control function
% INPUT: state, (phi,theta,psi)(ref)
% OUTPUT: desired prop speeds

function out=back1_rot_control(in)

% global file for parameters
glob;

global Om_old;  % 
global x1_1;
global x2_1;
global x3_1;

% ********* Operational Conditions *********
roll=in(1);     % [rad]
dotroll=in(2);  % [rad/s]
pitch=in(3);
dotpitch=in(4);
yaw=in(5);
dotyaw=in(6);
z=in(7);        % [m]
dotz=in(8);     % [m/s]
x=in(9);
dotx=in(10);
y=in(11);
doty=in(12);

rolld=in(13);   % desired ROLL angle [rad]

pitchd=in(14);   % desired PITCH angle [rad]


Td=in(15);   % desired thrust [N]

yawd=in(16);    % desired yaw angle [rad]

r2=0;
r3=0;
r4=0;
% ******************************************************** CONTROL ******************************************************** 

dotrolld = 0;     

dotpitchd = 0;

dotyawd = 0;

% ********* +滑模参数roll**************
lamdaroll=20;
kproll=10;
kpsroll=3;
deltaroll=0.05;
% ********* + 滑模参数pitch **************
lamdapitch=20;
kppitch=10;
kpspitch=3;
deltapitch=0.05;
% ********* + 滑模参数yaw **************
lamdayaw=8;
kpyaw=2;
kpsyaw=1;
deltayaw=0.02;
% ********* + FILTER + NOISE **************
lam1=3;  % lam > 0   integral term parameter   
lam2=3;
lam3=3;

% Controls
c1= 5;       % c1,2,3,4> 0  parameter for convergence speed of the ROLL tracking loop
c2= 8;      % parameter for convergence speed of the DOTROLL tracking loop
c3= 5;
c4= 8;
c5= 2;
c6= 1;

k1=0.5;
k2=0.5;
k3=0.5;



e1=2*kproll*(rolld-roll);  % roll error
e3=2*kppitch*(pitchd-pitch);  % pitch error
% e5=k3*(yawd-yaw);  % pitch error
e5=2*kpyaw*(yawd-yaw);

x1=x1_1+e1*sp;  % integrator
x2=x2_1+e3*sp;  % integrator
x3=x3_1+e5*sp;  % integrator


e2=c1*e1+dotrolld+lam1*x1-dotroll;  % dotroll error

e4=c3*e3+dotpitchd+lam2*x2-dotpitch;  % dotpitch error
e6=c5*e5+dotyawd+lam3*x3-dotyaw;  % dotyaw error

% ********* sliding surface **************
sroll=-1*dotroll+lamdaroll*(rolld-roll) +kproll*x1;
spitch=-1*dotpitch+lamdapitch*(pitchd-pitch) +kppitch*x2;
syaw=-1*dotyaw+lamdayaw*(yawd-yaw) +kpyaw*x3;

% ********* r2  **************
if(sroll<=-1*deltaroll)
    r2=-1*deltaroll;
elseif(sroll>=deltaroll)
    r2=deltaroll;
else
    r2=sroll;
end
% ********* r3  **************
if(spitch<=-1*deltapitch)
    r3=-1*deltapitch;
elseif(spitch>=deltapitch)
    r3=deltapitch;
else
    r3=spitch;
end
% ********* r4  **************
if(syaw<=-1*deltayaw)
    r4=-1*deltayaw;
elseif(syaw>=deltayaw)
    r4=deltayaw;
else
    r4=syaw;
end
% Coconut controller
U(1)=Td; % [N]

% U(2)=(Ixx/L)*((1-c1^2+lam1)*e1 + (c1+c2)*e2 - c1*lam1*x1);
U(2)=(Ixx/L)*(e1-lamdaroll*dotroll-((Iyy-Izz)/Ixx)*dotpitch*dotyaw) + kpsroll*Ixx*r2;
U(3)=(Iyy/L)*(e3-lamdapitch*dotpitch-((Izz-Ixx)/Iyy)*dotroll*dotyaw) + kpspitch*Iyy*r3;
% U(3)=(Iyy/L)*((1-c3^2+lam2)*e3 + (c3+c4)*e4 - c3*lam2*x2);
 
% U(4)=(Izz)* ((1-c5^2+lam3)*e5 + (c5+c6)*e6 - c5*lam3*x3);
U(4)=(Izz)* (e5-lamdayaw*dotyaw-((Ixx-Iyy)/Izz)*dotpitch*dotroll) + d*kpsyaw*Izz*r4/b;

% update integrator
x1_1=x1;
x2_1=x2;
x3_1=x3;

% Outputs
out(1)=U(1);
out(2)=U(2);
out(3)=U(3);
out(4)=U(4);

out(5)=e1;
out(6)=e3;