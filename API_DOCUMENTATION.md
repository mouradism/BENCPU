# API Documentation

## Class: `my_Bus`

### Description
The `my_Bus` class represents a data bus in the CPU emulator, responsible for transferring data between components.

### Private Members
- `int Data` - Stores the current data value on the bus (default: 0)

### Public Methods

#### `int updateBus(int& Data)`
Updates the bus with new data.

**Parameters:**
- `Data` (int&) - Reference to the data value to be placed on the bus

**Returns:**
- `int` - The updated data value on the bus

**Example:**
```cpp
my_Bus bus;
int newData = 42;
bus.updateBus(newData);
```

#### `int getBusData()`
Retrieves the current data value on the bus.

**Returns:**
- `int` - The current data value stored on the bus

**Example:**
```cpp
my_Bus bus;
int currentData = bus.getBusData();
```

---

## Class: `my_counter`

### Description
The `my_counter` class implements a programmable counter with clock edge detection, enable control, and data loading capabilities.

### Private Members
- `bool Enable` - Enable signal for the counter
- `bool load` - Load signal to load external data
- `bool edg` - Edge detection flag (0 or 1, default: 0)
- `bool clk` - Current clock state (default: 0)
- `int data` - Current counter data value (default: 0)

### Public Methods

#### `void updateState(bool Enable, bool load, int data, bool clk)`
Updates the internal state of the counter including clock edge detection.

**Parameters:**
- `Enable` (bool) - Enable signal for the counter
- `load` (bool) - Load signal for data loading
- `data` (int) - Data value to be loaded
- `clk` (bool) - Current clock signal

**Behavior:**
- Detects rising edge when `clk > this->clk` (sets `edg = 1`)
- Detects falling edge when `clk < this->clk` (sets `edg = 0`)
- Updates internal state variables

**Example:**
```cpp
my_counter counter;
counter.updateState(true, false, 0, true);
```

#### `int loadData(bool& Enable, bool& load, int& data)`
Loads data into the counter when enabled.

**Parameters:**
- `Enable` (bool&) - Reference to enable signal
- `load` (bool&) - Reference to load signal
- `data` (int&) - Reference to data value to load

**Returns:**
- `int` - The current data value in the counter

**Behavior:**
- If `Enable` is false or `load` is false, returns current data without modification
- If both `Enable` and `load` are true, loads the new data and returns it

**Example:**
```cpp
my_counter counter;
bool enable = true, load = true;
int value = 10;
int result = counter.loadData(enable, load, value);
```

#### `int count(bool& clk, bool& Enable, bool& load)`
Performs counting operation based on clock edge and control signals.

**Parameters:**
- `clk` (bool&) - Reference to clock signal
- `Enable` (bool&) - Reference to enable signal
- `load` (bool&) - Reference to load signal

**Returns:**
- `int` - The current counter value

**Behavior:**
- If `Enable` is false, `load` is false, or no edge is detected (`edg` is false), returns current data
- If all conditions are met, loads data and returns it

**Example:**
```cpp
my_counter counter;
bool clk = true, enable = true, load = true;
int count = counter.count(clk, enable, load);
```

---

## Class: `my_Signals`

### Description
The `my_Signals` class manages control signals in the CPU emulator.

### Private Members
- `int Data` - Stores the current signal data (default: 0)

### Public Methods

#### `int updateSignals(int& Data)`
Updates the signal data.

**Parameters:**
- `Data` (int&) - Reference to the new signal data value

**Returns:**
- `int` - The updated signal data value

**Example:**
```cpp
my_Signals signals;
int newSignal = 5;
signals.updateSignals(newSignal);
```

#### `int getSignalsData()`
Retrieves the current signal data.

**Returns:**
- `int` - The current signal data value

**Example:**
```cpp
my_Signals signals;
int currentSignal = signals.getSignalsData();
```

---

## Usage Example

```cpp
#include <iostream>
#include "my_Bus.h"
#include "my_counter.h"
#include "my_Signals.h"

int main() {
    // Initialize components
    my_Bus dataBus;
    my_counter programCounter;
    my_Signals controlSignals;
    
    // Set up bus data
    int busData = 100;
    dataBus.updateBus(busData);
    
    // Configure counter
    bool enable = true;
    bool load = true;
    bool clk = true;
    int counterData = 0;
    
    programCounter.updateState(enable, load, counterData, clk);
    programCounter.loadData(enable, load, counterData);
    
    // Update control signals
    int signalValue = 1;
    controlSignals.updateSignals(signalValue);
    
    // Read values
    std::cout << "Bus Data: " << dataBus.getBusData() << std::endl;
    std::cout << "Signal Data: " << controlSignals.getSignalsData() << std::endl;
    
    return 0;
}
```

## Notes

- All classes use default constructors
- Data types are primarily integers and booleans
- Clock edge detection in `my_counter` uses comparison to detect rising/falling edges
- The counter implementation is work-in-progress and may require refinement
