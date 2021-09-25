# Run 'make help' in the terminal to see a list of script options

.PHONY: help
help: ## Show help message
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

# GENERAL DEVELOPMENT TOOLING
.PHONY: graph
graph:
	@(rqt_graph)

.PHONY: urdf
urdf: ## Validates the my_robot xacro
	@(cd ${CATKIN_WS}/src/${PKG_NAME}/urdf && check_urdf my_robot.xacro)

# RUNNING
.PHONY: run
run: ## Starts the main launch file
	@(cd ${CATKIN_WS} && roslaunch ${PKG_NAME} world.launch)

.PHONY: run-dev
run-dev: ## Starts the launch file with development configurations
	@(cd ${CATKIN_WS} && roslaunch ${PKG_NAME} world.launch use_rviz:=true world_file:=$(find my_robot)/worlds/maze.world)

.PHONY: chase
chase: ## Starts the ball_chaser
	@(cd ${CATKIN_WS} && roslaunch ball_chaser ball_chaser.launch)

.PHONY: play-bag
play-bag: ## Plays the bag file that has ball images in it
	@(cd ${CATKIN_WS}/src/${PKG_NAME}/bagfiles && rosbag play subset.bag)