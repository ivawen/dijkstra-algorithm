.PHONY: clean All

All:
	@echo "----------Building project:[ dijkstra - Debug ]----------"
	@cd "dijkstra" && "$(MAKE)" -f  "dijkstra.mk"
clean:
	@echo "----------Cleaning project:[ dijkstra - Debug ]----------"
	@cd "dijkstra" && "$(MAKE)" -f  "dijkstra.mk" clean
