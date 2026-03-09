# Architecture Documentation

## Overview

BENCPU is a modular CPU emulator designed to simulate basic CPU operations. The architecture consists of three main components that work together to emulate CPU functionality.

## System Architecture

```
┌─────────────────────────────────────────────┐
│            CPU Emulator System              │
│                                             │
│  ┌──────────┐    ┌──────────┐    ┌───────┐│
│  │  Bus     │◄──►│ Counter  │◄──►│Signals││
│  │ System   │    │          │    │       ││
│  └──────────┘    └──────────┘    └───────┘│
│                                             │
└─────────────────────────────────────────────┘
```

## Component Architecture

### 1. Bus System (`my_Bus`)

**Purpose:** Data transfer backbone of the CPU emulator

**Responsibilities:**
- Maintain current data state
- Allow read/write operations
- Facilitate data movement between components

**Design Pattern:** Simple state holder with accessor/mutator methods

**Data Flow:**
```
External Component → updateBus() → Internal Data Storage
Internal Data Storage → getBusData() → External Component
```

### 2. Counter (`my_counter`)

**Purpose:** Implement program counter or general-purpose counter functionality

**Responsibilities:**
- Track count value
- Handle clock edge detection
- Support synchronous load operations
- Enable/disable control

**State Machine:**
```
┌─────────────┐
│   Initial   │
│  (data=0)   │
└──────┬──────┘
       │ updateState()
       ▼
┌─────────────┐
│ State Update│
│ Edge Detect │
└──────┬──────┘
       │
       ├──► loadData() ──► Load new value (if enabled)
       │
       └──► count() ────► Increment/update (on clock edge)
```

**Clock Edge Detection:**
- Rising Edge: `clk > previous_clk` → `edg = 1`
- Falling Edge: `clk < previous_clk` → `edg = 0`

### 3. Signals (`my_Signals`)

**Purpose:** Manage control signals throughout the CPU

**Responsibilities:**
- Store control signal states
- Propagate control information
- Coordinate component operations

**Signal Flow:**
```
Control Logic → updateSignals() → Signal Storage → getSignalsData() → Components
```

## Design Principles

### 1. Modularity
Each component is self-contained with clear interfaces, allowing for:
- Easy testing
- Independent development
- Component replacement
- Scalability

### 2. Encapsulation
Private data members ensure:
- Data integrity
- Controlled access
- State consistency

### 3. Simplicity
Current implementation focuses on:
- Core functionality
- Clear method names
- Straightforward data types

## Data Flow Architecture

### Typical Operation Cycle

```
1. Signal Update
   ┌─────────────┐
   │ my_Signals  │
   │ (Control)   │
   └──────┬──────┘
          │
2. Bus Data Transfer
          ▼
   ┌─────────────┐
   │   my_Bus    │
   │ (Data Path) │
   └──────┬──────┘
          │
3. Counter Operation
          ▼
   ┌─────────────┐
   │ my_counter  │
   │ (Execution) │
   └─────────────┘
```

## Memory Model

### Current Implementation
- Stack-based object allocation
- No dynamic memory management
- Fixed-size data members

### Storage
- **Bus:** Single integer data value
- **Counter:** Integer data + Boolean control flags
- **Signals:** Single integer signal value

## Future Architecture Enhancements

### Planned Components

1. **Instruction Decoder**
   - Decode binary instructions
   - Generate control signals
   - Interface with existing components

2. **Register File**
   - Multiple register storage
   - Read/write ports
   - Integration with bus system

3. **ALU (Arithmetic Logic Unit)**
   - Arithmetic operations
   - Logic operations
   - Flag generation

4. **Memory Unit**
   - RAM simulation
   - Address decoding
   - Read/write operations

5. **Control Unit**
   - Instruction fetch
   - Decode-execute cycle
   - State machine implementation

### Enhanced Architecture Vision

```
┌───────────────────────────────────────────────────────┐
│                  CPU Emulator System                  │
│                                                       │
│  ┌──────────┐    ┌──────────┐    ┌────────────────┐ │
│  │ Control  │───►│ Decoder  │───►│ Register File  │ │
│  │  Unit    │    │          │    │                │ │
│  └────┬─────┘    └──────────┘    └───────┬────────┘ │
│       │                                   │          │
│       │          ┌──────────┐            │          │
│       └─────────►│   Bus    │◄───────────┘          │
│                  │  System  │                        │
│                  └────┬─────┘                        │
│                       │                              │
│       ┌───────────────┼───────────────┐             │
│       │               │               │             │
│  ┌────▼────┐    ┌────▼────┐    ┌────▼────┐        │
│  │   ALU   │    │ Counter │    │ Memory  │        │
│  │         │    │   (PC)  │    │  Unit   │        │
│  └─────────┘    └─────────┘    └─────────┘        │
└───────────────────────────────────────────────────────┘
```

## Scalability Considerations

### Horizontal Scaling
- Add more bus systems for parallel data paths
- Multiple counters for different purposes
- Extended signal sets

### Vertical Scaling
- Enhanced data width (8-bit, 16-bit, 32-bit support)
- More complex control logic
- Multi-cycle operations

## Integration Points

### Current Integration
Components are designed to work together through:
- Shared data types (int, bool)
- Reference-based parameter passing
- Consistent naming conventions

### Future Integration
- Event-driven architecture
- Clock signal distribution
- Interrupt handling
- DMA (Direct Memory Access)

## Performance Considerations

### Current Implementation
- O(1) complexity for all operations
- Minimal memory footprint
- No dynamic allocations

### Optimization Opportunities
- Bit-level operations
- SIMD instructions
- Parallel component updates
- Cache-friendly data structures

## Testing Strategy

### Unit Testing
Each component should be tested independently:
- Bus data integrity
- Counter clock edge detection
- Signal propagation

### Integration Testing
- Component interaction
- Data flow verification
- Clock synchronization

### System Testing
- Full CPU cycle simulation
- Instruction execution
- Performance benchmarks
