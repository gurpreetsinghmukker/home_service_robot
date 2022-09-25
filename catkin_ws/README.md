
# Home Service Robot

## Localization 

This project employs a ROS package called **AMCL** that implements Monte Carlo Localization technique that uses particle filter to localize the robot in the environment. A Map is given to the robot and the algorithm distributes a bunch of particles (or the pose estimates) across the map uniformly at the start.  These partticles also contain an extra value called the “weight”. The weight of a particle indicates how close the particle actually is to the actual pose of the robot. Higher weighted particles are also more likely to survive during the resampling process. 

 As the robot is moving in the environment, the algorithms keeps on updating the weights of the particles according to the new sensory measurements. The measurements come from the sensors such as lidar and odometry which is constantly compared to the map given to the algorithm. If the estimated pose of particle is found to be in agreement with sensor readings using bayesian pose estimation technique, the weight of the particle is increased making it more likely to survive during the resampling process. Over time, as the robot is moving throught the configuration space, the particles converge to a very small area on the map thereby estimating the pose of the robot relatively accurately. 
## Mapping

This project uses **gmapping** ROS packge to creat Occupancy grid maps is the environment. The evironment is abstracted out as grid of numbers. The number in the grid tells if the corresponding location of the environment is occupied by an obstacle or not. The major hurdle in mapping is the very huge solution space of the possible maps for a given set of data. This hurdle is over come what is called as Binary Bayes filter where we assume that the probability of occupance of each grid is independent of occupancy of the neighbouring grids cells. 

Mapping when the robot is known, requires us to compute the grid map by the use of only measuurement data. The posterior of each grid is calculated using the Binary Bayes filter.  

One of the other methods we use to reduce the complexity involved in calculating posterior over the map, is by using inverse measurement method according to which we calculate the “cause” of something( the map in our case) from its effects( the lidar measurement data). 

## Navigation

For navigation, this project uses ROS’s **Navigation stack**. The given map is made up of grid cells. Each cell is either white indicating free of obstacles, black indicating obstacles or grey indicating unknown state. Each of these grid cells can be considered as nodes in a graph connected to its neighbouring cells. The black cells have high cost, so any planned path that involves going through that cell will incurr a high cost making it less favourable path for robot to follow. 

We use the Djikstra’s Algorithm which is a variant for Uniform Cost Search Algorithm. This algorithm finds the lowest cost path from the start to goal location which is then followed by the robot. The robot is given commands of translational and angular velocity by by the **move_base** package to make it stay over the planned path. 

**move_base** package also handles generation of both local, global cost maps, inflation of obstacles etc which are all required for navigation. 

