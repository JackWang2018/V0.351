# OpenSees -- Open System for Earthquake Engineering Simulation
# Pacific Earthquake Engineering Research Center
# http://opensees.berkeley.edu/
#
# Basic Truss Example
# ----------------------
#  2d 3 Element Elastic Truss
#  Single Nodal Load, Static Analysis
# 
# Example Objectives
# -----------------
#  Simple Introduction to OpenSees
# 
# Units: kips, in, sec
# Written: fmk
# Date: January 2001

# ------------------------------
# Start of model generation
# ------------------------------

# Remove existing model
wipe

# Create ModelBuilder (with two-dimensions and 2 DOF/node)
model BasicBuilder -ndm 2 -ndf 2

# Create nodes
# ------------
    
# Create nodes & add to Domain - command: node nodeId xCrd yCrd
node	1	-7.5	0
node	2	-4.5	0
node	3	-1.5	0
node	4	1.5	0
node	5	4.5	0
node	6	7.5	0
node	7	-6	3
node	8	-3	3
node	9	0	3
node	10	3	3
node	11	6	3


# Set the boundary conditions - command: fix nodeID xResrnt? yRestrnt?
fix 1 1 1 
fix 6 0 1

# Define materials for truss elements
# -----------------------------------

# Create Elastic material prototype - command: uniaxialMaterial Elastic matID E
uniaxialMaterial Elastic 1 30000000

# Define elements
# ---------------

# Create truss elements - command: element truss trussID node1 node2 A matID
element	Truss	1	1	2	0.01	1
element	Truss	2	2	3	0.01	1
element	Truss	3	3	4	0.01	1
element	Truss	4	4	5	0.01	1
element	Truss	5	5	6	0.01	1
element	Truss	6	7	8	0.01	1
element	Truss	7	8	9	0.01	1
element	Truss	8	9	10	0.01	1
element	Truss	9	10	11	0.01	1
element	Truss	10	1	7	0.01	1
element	Truss	11	2	8	0.01	1
element	Truss	12	3	9	0.01	1
element	Truss	13	4	10	0.01	1
element	Truss	14	5	11	0.01	1
element	Truss	15	2	7	0.01	1
element	Truss	16	3	8	0.01	1
element	Truss	17	4	9	0.01	1
element	Truss	18	5	10	0.01	1
element	Truss	19	6	11	0.01	1

    
# Define loads
# ------------

#create a Linear TimeSeries (load factor varies linearly with time): command timeSeries Linear $tag
timeSeries Linear 1

# Create a Plain load pattern with a linear TimeSeries: command pattern Plain $tag $timeSeriesTag { $loads }
pattern Plain 1 1 {
    
    # Create the nodal load - command: load nodeID xForce yForce
	load 9 0 -5
	load 7 5 0

}
    
# ------------------------------
# Start of analysis generation
# ------------------------------

# Create the system of equation, a SPD using a band storage scheme
system BandSPD

# Create the DOF numberer, the reverse Cuthill-McKee algorithm
numberer RCM

# Create the constraint handler, a Plain handler is used as homo constraints
constraints Plain

# Create the integration scheme, the LoadControl scheme using steps of 1.0
integrator LoadControl 1.0

# Create the solution algorithm, a Linear algorithm is created
algorithm Linear

# create the analysis object 
analysis Static

# ------------------------------
# Start of recorder generation
# ------------------------------

# create a Recorder object for the nodal displacements at node 4
recorder Node -file node.txt -time -node	1	-dof 1 2 disp



# Create a recorder for element forces, one in global and the other local system
recorder Element -file eleGlobal.txt -time -ele 1 2 3 forces
recorder Element -file eleLocal.txt -time -ele 1 2 3  basicForces

# ------------------------------
# Finally perform the analysis
# ------------------------------

# Perform the analysis
analyze 1

# ------------------------------
# Print Stuff to Screen
# ------------------------------

# Print the current state at node 4 and at all elements
print node
print ele

