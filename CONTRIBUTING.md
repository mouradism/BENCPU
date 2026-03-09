# Contributing to BENCPU

Thank you for your interest in contributing to BENCPU! This document provides guidelines and instructions for contributing to the project.

## Table of Contents
- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Setup](#development-setup)
- [How to Contribute](#how-to-contribute)
- [Coding Standards](#coding-standards)
- [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)

## Code of Conduct

Please be respectful and constructive in all interactions. We aim to maintain a welcoming and inclusive environment for all contributors.

## Getting Started

### Prerequisites
- Visual Studio 2019 or later
- Git
- C++ compiler with C++11 support or higher
- Basic understanding of CPU architecture

### Fork and Clone

1. Fork the repository on GitHub
2. Clone your fork locally:
```bash
git clone https://github.com/YOUR_USERNAME/BENCPU.git
cd BENCPU
```

3. Add the upstream repository:
```bash
git remote add upstream https://github.com/mouradism/BENCPU.git
```

## Development Setup

1. Open `binCpuEmulator.sln` in Visual Studio
2. Build the solution (Ctrl + Shift + B)
3. Run tests to ensure everything works (if tests exist)

## How to Contribute

### Reporting Bugs

If you find a bug, please create an issue with:
- Clear description of the bug
- Steps to reproduce
- Expected behavior
- Actual behavior
- Environment details (OS, Visual Studio version, etc.)

### Suggesting Enhancements

For feature requests or enhancements:
- Check if the feature has already been requested
- Provide a clear description of the enhancement
- Explain why it would be useful
- Include examples if applicable

### Code Contributions

1. **Create a branch** for your feature or bugfix:
```bash
git checkout -b feature/your-feature-name
# or
git checkout -b bugfix/issue-description
```

2. **Make your changes** following the coding standards

3. **Test your changes** thoroughly

4. **Commit your changes** with clear messages

5. **Push to your fork**:
```bash
git push origin feature/your-feature-name
```

6. **Create a Pull Request** from your fork to the main repository

## Coding Standards

### C++ Style Guidelines

#### Naming Conventions
- **Classes:** PascalCase with `my_` prefix (e.g., `my_Bus`, `my_counter`)
- **Methods:** camelCase (e.g., `updateBus`, `getBusData`)
- **Variables:** camelCase for local variables
- **Private members:** camelCase (e.g., `Data`, `Enable`)
- **Constants:** UPPER_SNAKE_CASE

#### Code Formatting
```cpp
// Use proper indentation (4 spaces or 1 tab)
class my_Example
{
private:
    int privateData;
    
public:
    void exampleMethod()
    {
        if (condition) {
            // Code here
        }
    }
};
```

#### Header Files
- Always use `#pragma once` for header guards
- Include only necessary headers
- Organize includes: standard library, then project headers

```cpp
#pragma once
#include <iostream>
#include "my_Bus.h"
```

#### Comments
- Use clear, concise comments
- Document complex logic
- Add header comments for classes and methods

```cpp
/**
 * @brief Updates the bus with new data
 * @param Data Reference to the data value
 * @return The updated data value
 */
int updateBus(int& Data);
```

### Best Practices

1. **Keep methods small and focused** - Each method should do one thing well
2. **Use meaningful names** - Variable and method names should be self-documenting
3. **Avoid magic numbers** - Use named constants instead
4. **Handle edge cases** - Consider null pointers, boundary conditions, etc.
5. **Write testable code** - Design with testing in mind

## Commit Guidelines

### Commit Message Format
```
<type>: <subject>

<body>

<footer>
```

### Types
- **feat:** New feature
- **fix:** Bug fix
- **docs:** Documentation changes
- **style:** Code style changes (formatting, missing semicolons, etc.)
- **refactor:** Code refactoring
- **test:** Adding or updating tests
- **chore:** Maintenance tasks

### Examples
```
feat: Add ALU component for arithmetic operations

Implemented basic ALU with support for:
- Addition
- Subtraction
- Bitwise AND/OR

Closes #15
```

```
fix: Correct clock edge detection in counter

The counter was not properly detecting falling edges.
Updated the logic to handle both rising and falling edges correctly.

Fixes #23
```

## Pull Request Process

### Before Submitting
1. ✅ Code builds without errors
2. ✅ All tests pass
3. ✅ Code follows style guidelines
4. ✅ Comments are added where necessary
5. ✅ Documentation is updated if needed

### PR Description Template
```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Code refactoring

## Testing
Describe how you tested your changes

## Checklist
- [ ] Code builds successfully
- [ ] Follows coding standards
- [ ] Documentation updated
- [ ] Tests added/updated
```

### Review Process
1. Maintainers will review your PR
2. Address any feedback or requested changes
3. Once approved, your PR will be merged

### After Merge
1. Delete your feature branch (optional)
2. Pull the latest changes from upstream:
```bash
git checkout master
git pull upstream master
```

## Areas for Contribution

### High Priority
- [ ] Implement ALU component
- [ ] Add memory unit
- [ ] Create register file
- [ ] Develop control unit
- [ ] Write unit tests

### Medium Priority
- [ ] Add instruction decoder
- [ ] Implement interrupt handling
- [ ] Create debugging tools
- [ ] Performance optimization

### Documentation
- [ ] Add code examples
- [ ] Create tutorial documentation
- [ ] Improve API documentation
- [ ] Add architecture diagrams

## Questions?

If you have questions about contributing:
- Open an issue with the "question" label
- Check existing documentation
- Review closed issues for similar questions

## License

By contributing to BENCPU, you agree that your contributions will be licensed under the same license as the project.

## Thank You!

Your contributions help make BENCPU better for everyone. We appreciate your time and effort!
