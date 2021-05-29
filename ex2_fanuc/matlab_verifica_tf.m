q=zeros(6,1);

dh_params=[
    0.15 , 0.525 , pi/2 , q(1);
    0.79 , 0     , 0    , q(2)+pi/2;
    0.25 , 0     , pi/2 , q(3);
    0    , 0.86 , pi/2 , q(4);
    0    , 0     ,-pi/2 , q(5);
    0    , 0     , 0    , q(6);
];

T01=trvec2tform([ 0, 0, dh_params(1,2)])*rotm2tform(rotz(rad2deg(dh_params(1,4))))*trvec2tform([ dh_params(1,1), 0, 0])*rotm2tform(rotx(rad2deg(dh_params(1,3))));
T12=trvec2tform([ 0, 0 ,dh_params(2,2)])*rotm2tform(rotz(rad2deg(dh_params(2,4))))*trvec2tform([ dh_params(2,1), 0, 0])*rotm2tform(rotx(rad2deg(dh_params(2,3))));
T23=trvec2tform([ 0, 0, dh_params(3,2)])*rotm2tform(rotz(rad2deg(dh_params(3,4))))*trvec2tform([ dh_params(3,1), 0, 0])*rotm2tform(rotx(rad2deg(dh_params(3,3))));
T34=trvec2tform([ 0, 0, dh_params(4,2)])*rotm2tform(rotz(rad2deg(dh_params(4,4))))*trvec2tform([ dh_params(4,1), 0, 0])*rotm2tform(rotx(rad2deg(dh_params(4,3))));
T45=trvec2tform([ 0, 0, dh_params(5,2)])*rotm2tform(rotz(rad2deg(dh_params(5,4))))*trvec2tform([ dh_params(5,1), 0, 0])*rotm2tform(rotx(rad2deg(dh_params(5,3))));
T56=trvec2tform([ 0, 0, dh_params(6,2)])*rotm2tform(rotz(rad2deg(dh_params(6,4))))*trvec2tform([ dh_params(6,1), 0, 0])*rotm2tform(rotx(rad2deg(dh_params(6,3))));

T46=T45*T56;
T36=T34*T46;
T26=T23*T36;
T16=T12*T26;
T06=T01*T16;

traslazione_56=tform2trvec(T56)
MatriceRotazione_56=tform2rotm(T56)
RPY_56=rotm2eul(MatriceRotazione_56,'ZYX')
asse_angolo56=rotm2axang(MatriceRotazione_56)

traslazione_46=tform2trvec(T46)
MatriceRotazione_46=tform2rotm(T46)
RPY_46=rotm2eul(MatriceRotazione_46,'ZYX')
asse_angolo46=rotm2axang(MatriceRotazione_46)

traslazione_36=tform2trvec(T36)
MatriceRotazione_36=tform2rotm(T36)
RPY_36=rotm2eul(MatriceRotazione_36,'ZYX')
asse_angolo36=rotm2axang(MatriceRotazione_36)

traslazione_26=tform2trvec(T26)
MatriceRotazione_26=tform2rotm(T26)
RPY_26=rotm2eul(MatriceRotazione_26,'ZYX')
asse_angolo26=rotm2axang(MatriceRotazione_26)

traslazione_16=tform2trvec(T16)
MatriceRotazione_16=tform2rotm(T16)
RPY_16=rotm2eul(MatriceRotazione_16,'ZYX')
asse_angolo16=rotm2axang(MatriceRotazione_16)

traslazione_06=tform2trvec(T06)
MatriceRotazione_06=tform2rotm(T06)
RPY_061=rotm2eul(MatriceRotazione_06,'ZYX')
asse_angolo06=rotm2axang(MatriceRotazione_06)
