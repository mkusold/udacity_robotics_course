# Run 'make help' in the terminal to see a list of script options

.PHONY: help
help: ## Show help message
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

# GENERAL DEVELOPMENT TOOLING

.PHONY: graph
graph: ## Shows the topic graph
	@(rqt_graph)

.PHONY: plot
plot: ## Shows topic output on a graph
	@(rqt_plot)

.PHONY: multiplot
multiplot: ## Shows multiple topic outputs on a graph
	@(rqt_multiplot)

.PHONY: build
build: ## Re-builds the catkin workspace
	@(cd ${CATKIN_WS} && catkin_make)

# RUNNING
.PHONY: run
run: ## Starts the main launch file
	@(cd ${CATKIN_WS} && roslaunch src/bringup.launch)