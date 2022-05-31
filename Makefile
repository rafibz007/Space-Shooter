
all: 
	@echo "use 'make run' to start a project"

run:
	cd CppProject; \
	mkdir cmake-build; \
	cmake -B cmake-build; \
	cd cmake-build; \
	make; \
	./CppProject

clean:
	cd CppProject; \
	rm -rf cmake-build
