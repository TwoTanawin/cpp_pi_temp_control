# Use an official GCC compiler image
FROM gcc:11

# Set the working directory
WORKDIR /app

# Copy the CMakeLists.txt and source files into the container
COPY CMakeLists.txt .
COPY src/ ./src/
COPY test/ ./test/

# Install CMake and other required packages
RUN apt-get update && \
    apt-get install -y cmake lcov && \
    apt-get clean

# Run CMake and build the project
RUN mkdir -p build && \
    cd build && \
    cmake .. -DENABLE_COVERAGE=ON && \
    cmake --build . && \
    ctest && \
    cmake --build . --target coverage

# Set the default command to run the application
CMD ["./build/pi_temp_control"]
