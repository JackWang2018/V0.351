#弹性悬臂梁PushOver分析By伊犁的秋天
 
#基本参数设置
wipe;
model basic -ndm 2 -ndf 3;
file mkdir EQ;
 
#模型定义
node 1 0 0
node 2 0 1000
 
#边界条件
fix 1 1 1 1; 
#定义水平方向质量M=G/g
mass 2 200 1.e-9 0.
#坐标转换 
geomTransf Linear 1;
#定义弹性梁柱单元，命令：element elasticBeamColumn eleTag iNode jNode A E Iz transfTag
element elasticBeamColumn 1 1 2 10000 200000 8333333 1;
 
#定义记录器
recorder Node -file EQ/node2.out -time -node 2 -dof 1 2 3 disp;
recorder Node -file EQ/node1.out -time -node 1 -dof 1 2 3 disp;		
recorder Drift -file EQ/drift.out -time -iNode 1 -jNode 2 -dof 1  -perpDirn 2 ;
 
#定义竖向荷载
pattern Plain 1 Linear {
   load 2 0. -2000. 0.;			
}
constraints Plain;
numberer Plain;
system BandGeneral;
test NormDispIncr 1.0e-8 6;
algorithm Newton;
integrator LoadControl 0.1;
analysis Static;
analyze 10;
loadConst -time 0.0;
 
#定义地震作用
#地面加速度定义（由于地震波文件单位是m/s^2转换成mm/s^2,放大1000倍）
set accelSeries "Series -dt 0.02 -filePath ELCENTRO.DAT -factor 1000";
#施加地震作用
pattern UniformExcitation 2 1 -accel $accelSeries;
#定义瑞雷阻尼（根据第一振型计算）
rayleigh 0. 0. 0. [expr 2*0.02/pow([eigen 1],0.5)];
 
# 建立分析
constraints Plain;
numberer Plain;
system BandGeneral;	
test NormDispIncr 1.0e-8 10;
algorithm Newton;
integrator Newmark 0.5 0.25 ;
analysis Transient;
analyze 1560 0.02;