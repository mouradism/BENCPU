# BENCPU - Binary CPU Emulator

A C++ based CPU emulator project that simulates basic CPU components including buses, counters, and signal management.

## Overview

BENCPU is a binary-inspired CPU emulator designed to simulate fundamental CPU operations and components. The project provides a modular architecture with separate classes for different CPU components.

## Components

### 1. Bus System (`my_Bus`)
The bus system handles data transfer between different CPU components.

**Features:**
- Update bus data
- Retrieve current bus data
- Integer data transmission

**Key Methods:**
- `updateBus(int& Data)` - Updates the bus with new data
- `getBusData()` - Returns the current data on the bus

### 2. Counter (`my_counter`)
A programmable counter with enable, load, and clock functionality.

**Features:**
- Clock edge detection
- Load data capability
- Enable/disable functionality
- State management

**Key Methods:**
- `updateState(bool Enable, bool load, int data, bool clk)` - Updates counter state with control signals
- `loadData(bool& Enable, bool& load, int& data)` - Loads data when enabled
- `count(bool& clk, bool& Enable, bool& load)` - Performs counting operation based on clock edge

### 3. Signals (`my_Signals`)
Manages control signals throughout the CPU emulation.

**Features:**
- Signal data management
- Signal propagation

**Key Methods:**
- `updateSignals(int& Data)` - Updates signal data
- `getSignalsData()` - Retrieves current signal data

## Project Structure

```
binCpuEmulator/
├── binCpuEmulator.cpp      # Main entry point
├── my_Bus.h/.cpp           # Bus component implementation
├── my_counter.h/.cpp       # Counter component implementation
├── my_Signals.h/.cpp       # Signals component implementation
├── binCpuEmulator.sln      # Visual Studio solution file
└── binCpuEmulator.vcxproj  # Visual Studio project file
```

## Building the Project

### Prerequisites
- Visual Studio 2019 or later
- C++ compiler with C++11 support or higher
- Windows OS

### Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/mouradism/BENCPU.git
cd BENCPU
```

2. Open the solution file:
```bash
binCpuEmulator.sln
```

3. Build the project:
   - Press `Ctrl + Shift + B` or
   - Go to `Build > Build Solution`

4. Run the project:
   - Press `Ctrl + F5` (without debugging) or
   - Press `F5` (with debugging)

## Usage

The main program initializes the CPU emulator and displays a welcome message. Future implementations will include:
- Instruction execution
- Memory management
- Register operations
- ALU operations

## Development Status

This project is currently in early development. The basic component architecture is established, with future plans to implement:
- [ ] Complete instruction set
- [ ] Memory subsystem
- [ ] Register file
- [ ] ALU (Arithmetic Logic Unit)
- [ ] Control unit
- [ ] Full CPU cycle simulation

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

## License

This project is open source. Please add an appropriate license file as needed.

## Author

Mourad - [GitHub](https://github.com/mouradism)

## Acknowledgments

Inspired by binary computing principles and CPU architecture design 8-bit compute // Ben Eater

https://www.youtube.com/watch?v=HyznrdDSSGM&list=PLowKtXNTBypGqImE405J2565dvjafglHU
