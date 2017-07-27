wipe
puts "System"
model basic -ndm 3 -ndf 3
puts "restraint"
node 1 0.000E+000 0.000E+000 0.000E+000
node 2 0.000E+000 3.000E+003 0.000E+000
node 3 6.000E+003 0.000E+000 0.000E+000
node 4 6.000E+003 3.000E+003 0.000E+000
node 5 1.200E+004 0.000E+000 0.000E+000
node 6 1.200E+004 3.000E+003 0.000E+000
node 7 1.800E+004 0.000E+000 0.000E+000
node 8 1.800E+004 3.000E+003 0.000E+000
node 9 2.400E+004 0.000E+000 0.000E+000
node 10 2.400E+004 3.000E+003 0.000E+000
node 11 3.000E+003 0.000E+000 4.500E+003
node 12 3.000E+003 3.000E+003 4.500E+003
node 13 9.000E+003 0.000E+000 4.500E+003
node 14 9.000E+003 3.000E+003 4.500E+003
node 15 1.500E+004 0.000E+000 4.500E+003
node 16 1.500E+004 3.000E+003 4.500E+003
node 17 2.100E+004 0.000E+000 4.500E+003
node 18 2.100E+004 3.000E+003 4.500E+003
puts "node"
fix 1 1 1 1 0 0 0;
fix 2 1 1 1 0 0 0;
fix 9 1 1 1 0 0 0;
fix 10 1 1 1 0 0 0;
puts "material"
uniaxialMaterial Elastic 1 1.999E+005
uniaxialMaterial Elastic 2 2.482E+004
uniaxialMaterial Elastic 3 1.999E+005
puts "transformation"
puts "element"
element truss 1 11 12 1.305E+004 1
element truss 2 13 14 1.305E+004 1
element truss 3 15 16 1.305E+004 1
element truss 4 17 18 1.305E+004 1
element truss 5 11 13 2.120E+004 1
element truss 6 13 15 2.120E+004 1
element truss 7 15 17 2.120E+004 1
element truss 8 12 14 2.120E+004 1
element truss 9 14 16 2.120E+004 1
element truss 10 16 18 2.120E+004 1
element truss 11 1 11 1.305E+004 1
element truss 12 3 11 1.305E+004 1
element truss 13 3 13 1.305E+004 1
element truss 14 5 13 1.305E+004 1
element truss 15 5 15 1.305E+004 1
element truss 16 7 15 1.305E+004 1
element truss 17 7 17 1.305E+004 1
element truss 18 9 17 1.305E+004 1
element truss 19 2 12 1.305E+004 1
element truss 20 4 12 1.305E+004 1
element truss 21 4 14 1.305E+004 1
element truss 22 6 14 1.305E+004 1
element truss 23 6 16 1.305E+004 1
element truss 24 8 16 1.305E+004 1
element truss 25 8 18 1.305E+004 1
element truss 26 10 18 1.305E+004 1
element truss 27 12 13 1.305E+004 1
element truss 28 13 16 1.305E+004 1
element truss 29 16 17 1.305E+004 1
element truss 30 1 2 1.305E+004 1
element truss 31 3 4 1.305E+004 1
element truss 32 5 6 1.305E+004 1
element truss 33 7 8 1.305E+004 1
element truss 34 9 10 1.305E+004 1
element truss 35 1 3 2.120E+004 1
element truss 36 3 5 2.120E+004 1
element truss 37 5 7 2.120E+004 1
element truss 38 7 9 2.120E+004 1
element truss 39 2 4 2.120E+004 1
element truss 40 4 6 2.120E+004 1
element truss 41 6 8 2.120E+004 1
element truss 42 8 10 2.120E+004 1
element truss 43 2 3 1.305E+004 1
element truss 44 3 6 1.305E+004 1
element truss 45 6 7 1.305E+004 1
element truss 46 7 10 1.305E+004 1
puts "recorder"
recorder Node -file node0.out -time -nodeRange 1 18 -dof 1 2 3 disp
recorder Node -file node5.out -time -node 5 -dof 1 2 3 disp
recorder Element -file ele0.out -time -eleRange 1 46 localForce
puts "loading"
## Load Case = DEAD
pattern Plain 1 Linear {
load 13 0.000E+000 0.000E+000 -1.000E+005 0.000E+000 0.000E+000 0.000E+000
load 14 0.000E+000 0.000E+000 -1.000E+005 0.000E+000 0.000E+000 0.000E+000
load 15 0.000E+000 0.000E+000 -1.000E+005 0.000E+000 0.000E+000 0.000E+000
load 16 0.000E+000 0.000E+000 -1.000E+005 0.000E+000 0.000E+000 0.000E+000
}
puts "analysis"
constraints Plain
numberer Plain
system BandGeneral
test EnergyIncr 1.0e-6 200
algorithm Newton
integrator LoadControl 1.000E-002
analysis Static
analyze 100
