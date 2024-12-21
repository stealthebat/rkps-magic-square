GCC=gcc
TARGET=magic_square_no_loop

linux:
	@echo "Installing the necessary dependencies..."
	sudo apt-get update && sudo apt-get install -y build-essential
	@echo "Installation finished"
	@echo "Compilation..."
	$(GCC) -o $(TARGET) $(TARGET).c
	@echo "End of compilation..."
	@read -p "Do you want to run the game? (y/n): " answer; \
	if [ "$$answer" = "y" ]; then \
		./$(TARGET); \
	else \
		echo "Compilation complete"; \
	fi

windows:
	@echo "Compilation..."
	$(GCC) $(TARGET).c -o $(TARGET).exe
	@echo "End of compilation..." 
	@echo "Compilation complete"; \

web:
	@echo "Checking if emsdk is already installed..."
	@if [ -d "../emsdk" ]; then \
		echo "emsdk is already installed."; \
	else \
		echo "Installing the necessary dependencies..."; \
		sudo apt-get update; \
		sudo apt-get install -y git build-essential emscripten nodejs npm; \
		sudo npm install -g http-server; \
		@echo "End of installation of necessary dependencies..."; \
		@echo "The beginning of cloning the repository..."; \
		cd .. && git clone https://github.com/emscripten-core/emsdk.git; \
		@echo "End of repository cloning..."; \
		@echo "Start installing the latest version..."; \
		cd ../emsdk && ./emsdk install latest && ./emsdk activate latest && . ./emsdk_env.sh; \
		@echo "End of installation of the latest version..."; \
	fi
	@echo "Compilation..."
	mkdir -p web_build && \
	emcc $(TARGET).c -s NO_EXIT_RUNTIME=0 -o web_build/$(TARGET).html
	@echo "End of compilation..."
	@echo "Starting a local server..."
	http-server
	@echo "Shutting down the local server..."