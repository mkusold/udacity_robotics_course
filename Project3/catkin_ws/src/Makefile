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

.PHONY: build
build: ## Re-builds the catkin workspace
	@(cd ${CATKIN_WS} && catkin_make)

# RUNNING
.PHONY: run
run: ## Starts the main bringup file that launches all nodes
	@(cd ${CATKIN_WS} && roslaunch ${PKG_NAME} bringup.launch)

.PHONY: world
world: ## Starts the main world launch file
	@(cd ${CATKIN_WS} && roslaunch ${PKG_NAME} world.launch)

.PHONY: world-dev
world-dev: ## Starts the world launch file with development configurations
	@(cd ${CATKIN_WS} && roslaunch ${PKG_NAME} world.launch use_rviz:=false world:=empty)

.PHONY: amcl
amcl: ## Starts the amcl launch file
	@(cd ${CATKIN_WS} && roslaunch ${PKG_NAME} amcl.launch)

.PHONY: teleop
teleop: ## Teleoperational controls
	@(cd ${CATKIN_WS} && rosrun teleop_twist_keyboard teleop_twist_keyboard.py)
