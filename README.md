# 📝 CPP Module 05 - Exceptions

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Module](https://img.shields.io/badge/Module-05-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*Mastering Exception Handling and Error Management*

</div>

## 📖 Overview

**CPP Module 05** introduces the critical concept of **exception handling** in C++. Through a bureaucratic nightmare of forms, grades, and administrative procedures, you'll master try-catch blocks, custom exceptions, RAII principles, and robust error handling strategies that are essential for professional C++ development.

### 🎯 Learning Objectives

- Master exception handling with try-catch-throw mechanisms
- Design and implement custom exception classes
- Understand exception safety and RAII principles
- Learn proper error propagation strategies
- Implement exception hierarchies and inheritance
- Practice robust resource management during exceptions
- Explore factory patterns with exception handling

## 💡 Key Concepts Introduced

- **Exception Handling**: try-catch-throw mechanism
- **Custom Exceptions**: User-defined exception classes
- **Exception Safety**: Strong, basic, and no-throw guarantees
- **RAII**: Resource Acquisition Is Initialization
- **Exception Specifications**: throw() and noexcept
- **Exception Hierarchies**: Inheritance in exception classes
- **Factory Pattern**: Object creation with exception handling

## 🏛️ The Bureaucratic Universe

All exercises revolve around a Kafkaesque bureaucratic system:
- **Bureaucrats**: Officials with grades (1-150, 1 being highest)
- **Forms**: Documents requiring specific grades to sign/execute
- **Exceptions**: When procedures go wrong (as they often do)
- **Interns**: Lower-level workers who create forms

## 🚀 Exercises

### 👔 Exercise 00: Mommy, When I Grow Up, I Want to Be a Bureaucrat!
**Files**: `Bureaucrat.cpp`, `Bureaucrat.hpp`, `main.cpp`

Foundation of exception handling through bureaucrat grade management, demonstrating:
- Custom exception class implementation
- Exception throwing and catching
- Input validation with exceptions
- Basic exception safety principles

**Bureaucrat Class**:
```cpp
class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const std::string name, size_t grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& rhs);
    Bureaucrat &operator=(const Bureaucrat& rhs);

    const std::string getName() const;
    size_t getGrade() const;

    void incrementGrade();                    // Can throw GradeTooHighException
    void decrementGrade();                    // Can throw GradeTooLowException

    // Custom Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    const std::string _name;                  // Immutable name
    size_t _grade;                            // Grade: 1 (highest) to 150 (lowest)
};
```

**Grade System**:
- **Range**: 1 (highest) to 150 (lowest)
- **Validation**: Constructor throws exceptions for invalid grades
- **Operations**: Increment/decrement with boundary checking

**Exception Implementation**:
```cpp
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (minimum is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (maximum is 150)";
}
```

**Constructor Validation**:
```cpp
Bureaucrat::Bureaucrat(const std::string name, size_t grade) : _name(name), _grade(grade) {
    if (grade < MIN_GRADE)          // MIN_GRADE = 1
        throw GradeTooHighException();
    if (grade > MAX_GRADE)          // MAX_GRADE = 150
        throw GradeTooLowException();
}
```

**Usage Examples**:
```cpp
try {
    Bureaucrat alice("Alice", 1);      // Highest grade
    Bureaucrat bob("Bob", 150);        // Lowest grade
    Bureaucrat invalid("Invalid", 0);   // Throws GradeTooHighException
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << "Error: " << e.what() << std::endl;
} catch (const Bureaucrat::GradeTooLowException& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

**Key Learning Points**:
- Nested exception classes within host class
- Exception inheritance from `std::exception`
- `throw()` specification for no-throw guarantee
- Input validation through exceptions
- Exception safety in constructors

---

### 📋 Exercise 01: Form Up, Maggots!
**Files**: `Bureaucrat.cpp`, `Bureaucrat.hpp`, `Form.cpp`, `Form.hpp`, `main.cpp`

Introduction to form signing system with complex exception interactions, showcasing:
- Multiple custom exception types
- Exception propagation between objects
- Friend functions and exception handling
- State validation with exceptions

**Form Class**:
```cpp
class Form {
public:
    Form();
    Form(const std::string name, size_t gradeToSign, size_t gradeToExecute);
    ~Form();
    Form(const Form& rhs);
    Form &operator=(const Form& rhs);

    const std::string getName() const;
    bool isSigned() const;
    size_t getGradeToSign() const;
    size_t getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);  // Can throw exceptions

    // Custom Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    const std::string _name;           // Immutable form name
    bool _signed;                      // Signing status
    const size_t _gradeToSign;         // Required grade to sign
    const size_t _gradeToExecute;      // Required grade to execute
};
```

**Enhanced Bureaucrat**:
```cpp
class Bureaucrat {
    // ... previous methods ...

    void signForm(Form& form);         // Attempts to sign form
};
```

**Form Signing Logic**:
```cpp
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
```

**Complex Interaction Example**:
```cpp
try {
    Bureaucrat manager("Manager", 25);
    Bureaucrat intern("Intern", 100);

    Form budget("Budget Report", 50, 25);     // Requires grade 50 to sign
    Form memo("Office Memo", 75, 50);         // Requires grade 75 to sign

    manager.signForm(budget);                 // Success - grade 25 < 50
    intern.signForm(budget);                  // Fails - grade 100 > 50
    intern.signForm(memo);                    // Success - grade 100 > 75

} catch (const std::exception& e) {
    std::cout << "Unexpected error: " << e.what() << std::endl;
}
```

**Key Learning Points**:
- Exception propagation between classes
- State validation before operations
- Graceful error handling with user feedback
- Friend functions and exception safety
- Multiple exception types in class hierarchies

---

### 🏛️ Exercise 02: No, You Need Form 28B, Not 28C...
**Files**: `Bureaucrat.cpp`, `Bureaucrat.hpp`, `AForm.cpp`, `AForm.hpp`, `ShrubberyCreationForm.cpp`, `ShrubberyCreationForm.hpp`, `RobotomyRequestForm.cpp`, `RobotomyRequestForm.hpp`, `PresidentialPardonForm.cpp`, `PresidentialPardonForm.hpp`, `main.cpp`

Abstract form system with concrete implementations and execution logic, demonstrating:
- Abstract base classes with pure virtual functions
- Polymorphic exception handling
- File I/O operations with exception safety
- Complex inheritance hierarchies with exceptions

**Abstract Form Base Class**:
```cpp
class AForm {
public:
    AForm();
    AForm(const std::string name, size_t gradeToSign, size_t gradeToExecute);
    virtual ~AForm();                         // Virtual destructor
    AForm(const AForm& rhs);
    AForm &operator=(const AForm& rhs);

    const std::string getName() const;
    bool isSigned() const;
    size_t getGradeToSign() const;
    size_t getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;  // Template method pattern

    // Custom Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw();
    };

protected:
    virtual void executeAction() const = 0;   // Pure virtual - must implement

private:
    const std::string _name;
    bool _signed;
    const size_t _gradeToSign;
    const size_t _gradeToExecute;
};
```

**Concrete Form Implementations**:

#### `ShrubberyCreationForm`:
```cpp
class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& rhs);

protected:
    void executeAction() const override;      // Creates ASCII tree file

private:
    const std::string _target;
    static const std::string _shrubbery;     // ASCII art tree
};

// Grades: Sign 145, Execute 137
```

#### `RobotomyRequestForm`:
```cpp
class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& rhs);

protected:
    void executeAction() const override;      // 50% success robotomy

private:
    const std::string _target;
};

// Grades: Sign 72, Execute 45
```

#### `PresidentialPardonForm`:
```cpp
class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& rhs);

protected:
    void executeAction() const override;      // Presidential pardon

private:
    const std::string _target;
};

// Grades: Sign 25, Execute 5
```

**Template Method Pattern in Execution**:
```cpp
void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
    executeAction();                          // Call pure virtual method
}
```

**Specialized Execution Implementations**:
```cpp
void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to create shrubbery file");
    }
    file << _shrubbery;
    file.close();
    std::cout << "🌳 Shrubbery created at " << _target << std::endl;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "🔧 *DRILLING NOISES* ";
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully! 🤖" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed! 💥" << std::endl;
    }
}

void PresidentialPardonForm::executeAction() const {
    std::cout << "🏛️ " << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
```

**Enhanced Bureaucrat with Execution**:
```cpp
class Bureaucrat {
    // ... previous methods ...

    void executeForm(const AForm& form) const;
};

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
```

**Complex Usage Example**:
```cpp
try {
    Bureaucrat president("President", 1);
    Bureaucrat manager("Manager", 50);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm tree("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Criminal");

    // Sign forms
    president.signForm(tree);     // Can sign all
    president.signForm(robot);
    president.signForm(pardon);

    // Execute forms
    president.executeForm(tree);   // Can execute all
    manager.executeForm(robot);    // Can execute this one
    intern.executeForm(pardon);    // Cannot execute (grade too low)

} catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

**Key Learning Points**:
- Abstract base classes with pure virtual methods
- Template method pattern for execution framework
- File I/O operations with exception safety
- Polymorphic behavior through base class pointers
- Multiple exception types for different error conditions

---

### 🏢 Exercise 03: At Least This Beats Coffee-Making
**Files**: All previous files + `Intern.cpp`, `Intern.hpp`, `main.cpp`

Factory pattern implementation with comprehensive exception handling, showcasing:
- Factory pattern with exception handling
- String-based object creation
- Form name normalization and validation
- Complete bureaucratic simulation system

**Intern Class** (Factory):
```cpp
class Intern {
public:
    Intern(void);
    Intern(Intern const &src);
    Intern &operator=(Intern const &rhs);
    ~Intern(void);

    AForm *makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    // Factory method pointers
    AForm *makeShrubberyCreationForm(std::string target);
    AForm *makeRobotomyRequestForm(std::string target);
    AForm *makePresidentialPardonForm(std::string target);

    // Form creation lookup table
    static const std::string formNames[3];
    AForm *(Intern::*formCreators[3])(std::string target);

    std::string normalizeFormName(std::string formName);
};
```

**Factory Implementation with Function Pointers**:
```cpp
const std::string Intern::formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

// Constructor initializes function pointer array
Intern::Intern(void) {
    formCreators[0] = &Intern::makeShrubberyCreationForm;
    formCreators[1] = &Intern::makeRobotomyRequestForm;
    formCreators[2] = &Intern::makePresidentialPardonForm;
}
```

**Form Creation Logic**:
```cpp
AForm *Intern::makeForm(std::string formName, std::string target) {
    std::string normalized = normalizeFormName(formName);

    for (int i = 0; i < 3; i++) {
        if (normalized == formNames[i]) {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    throw FormNotFoundException();
}

std::string Intern::normalizeFormName(std::string formName) {
    // Convert to lowercase and handle variations
    std::string result = formName;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
```

**Individual Factory Methods**:
```cpp
AForm *Intern::makeShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}
```

**Complete Bureaucratic Workflow**:
```cpp
void demonstrateBureaucracy() {
    try {
        // Create bureaucratic hierarchy
        Bureaucrat president("President", 1);
        Bureaucrat vicePresident("VP", 10);
        Bureaucrat manager("Manager", 50);
        Bureaucrat supervisor("Supervisor", 100);
        Intern intern;

        // Intern creates forms
        AForm *forms[3];
        forms[0] = intern.makeForm("shrubbery creation", "office");
        forms[1] = intern.makeForm("robotomy request", "annoying_coworker");
        forms[2] = intern.makeForm("presidential pardon", "tax_evader");

        // Sign forms (different bureaucrats for different forms)
        supervisor.signForm(*forms[0]);      // Can sign shrubbery
        manager.signForm(*forms[1]);         // Can sign robotomy
        president.signForm(*forms[2]);       // Can sign pardon

        // Execute forms
        manager.executeForm(*forms[0]);      // Execute shrubbery
        vicePresident.executeForm(*forms[1]); // Execute robotomy
        president.executeForm(*forms[2]);    // Execute pardon

        // Cleanup
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }

    } catch (const std::exception& e) {
        std::cout << "Bureaucratic error: " << e.what() << std::endl;
    }
}
```

**Advanced Error Handling**:
```cpp
void testErrorScenarios() {
    Intern intern;

    try {
        // Test invalid form name
        AForm *invalid = intern.makeForm("coffee making", "kitchen");
    } catch (const Intern::FormNotFoundException& e) {
        std::cout << "Form creation failed: " << e.what() << std::endl;
    }

    try {
        // Test execution without signing
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm tree("garden");
        boss.executeForm(tree);  // Should fail - not signed
    } catch (const std::exception& e) {
        std::cout << "Execution failed: " << e.what() << std::endl;
    }
}
```

**Key Learning Points**:
- Factory pattern with function pointers
- String normalization and comparison
- Complete object creation workflow
- Memory management in factory patterns
- Exception handling in complex systems

## 🛠️ Compilation

Each exercise includes a Makefile with standard targets:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

**Compilation flags**:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🎮 How to Run

### Exercise 00 - Mommy, When I Grow Up, I Want to Be a Bureaucrat!
```bash
cd ex00
make
./bureaucrat
```

### Exercise 01 - Form Up, Maggots!
```bash
cd ex01
make
./form
```

### Exercise 02 - No, You Need Form 28B, Not 28C...
```bash
cd ex02
make
./forms
```

### Exercise 03 - At Least This Beats Coffee-Making
```bash
cd ex03
make
./intern
```

## 🧪 Testing Examples

### Exception Handling Test
```cpp
void testExceptionHandling() {
    try {
        // Test grade boundaries
        Bureaucrat tooHigh("TooHigh", 0);   // Should throw
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("TooLow", 151);   // Should throw
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}
```

### Form Workflow Test
```cpp
void testFormWorkflow() {
    Bureaucrat alice("Alice", 25);
    Bureaucrat bob("Bob", 100);

    PresidentialPardonForm pardon("Criminal");

    // Test signing permissions
    alice.signForm(pardon);  // Should succeed (25 < 25)
    bob.signForm(pardon);    // Should fail (100 > 25)

    // Test execution permissions
    alice.executeForm(pardon); // Should succeed (25 > 5)
    bob.executeForm(pardon);   // Should fail (100 > 5)
}
```

### Factory Test
```cpp
void testFactory() {
    Intern intern;

    std::vector<std::string> formTypes = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "invalid form"
    };

    for (const std::string& formType : formTypes) {
        try {
            AForm* form = intern.makeForm(formType, "target");
            std::cout << "Created: " << form->getName() << std::endl;
            delete form;
        } catch (const std::exception& e) {
            std::cout << "Failed: " << e.what() << std::endl;
        }
    }
}
```

## 🏗️ Project Structure

```
CPP_Module05/
├── README.md
├── ex00/                    # Mommy, When I Grow Up, I Want to Be a Bureaucrat!
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── Bureaucrat.hpp
│   └── src/
│       ├── Bureaucrat.cpp
│       └── main.cpp
├── ex01/                    # Form Up, Maggots!
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── Bureaucrat.hpp
│   │   └── Form.hpp
│   └── src/
│       ├── Bureaucrat.cpp
│       ├── Form.cpp
│       └── main.cpp
├── ex02/                    # No, You Need Form 28B, Not 28C...
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── Bureaucrat.hpp
│   │   ├── AForm.hpp
│   │   ├── ShrubberyCreationForm.hpp
│   │   ├── RobotomyRequestForm.hpp
│   │   └── PresidentialPardonForm.hpp
│   └── src/
│       ├── Bureaucrat.cpp
│       ├── AForm.cpp
│       ├── ShrubberyCreationForm.cpp
│       ├── RobotomyRequestForm.cpp
│       ├── PresidentialPardonForm.cpp
│       └── main.cpp
└── ex03/                    # At Least This Beats Coffee-Making
    ├── Makefile
    ├── inc/
    │   ├── ansi.h
    │   ├── Bureaucrat.hpp
    │   ├── AForm.hpp
    │   ├── ShrubberyCreationForm.hpp
    │   ├── RobotomyRequestForm.hpp
    │   ├── PresidentialPardonForm.hpp
    │   └── Intern.hpp
    └── src/
        ├── Bureaucrat.cpp
        ├── AForm.cpp
        ├── ShrubberyCreationForm.cpp
        ├── RobotomyRequestForm.cpp
        ├── PresidentialPardonForm.cpp
        ├── Intern.cpp
        └── main.cpp
```

## 💡 Key Takeaways

1. **Exception Safety**: Writing code that handles errors gracefully
2. **RAII Principles**: Resource management through object lifetimes
3. **Custom Exceptions**: Creating meaningful error types
4. **Exception Hierarchies**: Organizing exceptions through inheritance
5. **Factory Pattern**: Flexible object creation with error handling
6. **Template Method Pattern**: Defining algorithm frameworks
7. **Robust Design**: Building systems that fail gracefully

## 🎯 Skills Developed

- ✅ Exception handling mechanisms (try-catch-throw)
- ✅ Custom exception class design
- ✅ Exception safety guarantee implementation
- ✅ RAII resource management
- ✅ Polymorphic exception handling
- ✅ Factory pattern with error handling
- ✅ Template method pattern implementation
- ✅ Complex system error management

## ⚠️ Exception Safety Guarantees

### No-Throw Guarantee
- **Promise**: Function will never throw
- **Usage**: Destructors, `what()` methods
- **Specification**: `throw()` or `noexcept`

### Strong Exception Safety
- **Promise**: If exception thrown, program state unchanged
- **Implementation**: Copy-and-swap idiom
- **Usage**: Assignment operators, complex operations

### Basic Exception Safety
- **Promise**: If exception thrown, no resources leak
- **Implementation**: RAII principles
- **Usage**: Most constructors and methods

### No Exception Safety
- **Reality**: Exception leaves program in undefined state
- **Consequence**: Resource leaks, corruption
- **Avoidance**: Proper exception handling design

## 🔗 Design Patterns Used

### Template Method Pattern
- **Purpose**: Define algorithm skeleton, let subclasses override steps
- **Implementation**: `AForm::execute()` calls pure virtual `executeAction()`
- **Benefits**: Consistent execution framework, flexible implementations

### Factory Pattern
- **Purpose**: Create objects without specifying exact class
- **Implementation**: `Intern::makeForm()` with function pointers
- **Benefits**: Flexible object creation, easy extension

### Exception Object Pattern
- **Purpose**: Encapsulate error information in objects
- **Implementation**: Custom exception classes with `what()` method
- **Benefits**: Rich error information, hierarchical error handling

## 🔗 Best Practices Applied

1. **Exception Inheritance**: All custom exceptions inherit from `std::exception`
2. **RAII**: Resources acquired in constructors, released in destructors
3. **Exception Specifications**: Use `throw()` for no-throw guarantee
4. **Error Messages**: Meaningful messages through `what()` method
5. **Resource Cleanup**: Proper cleanup even when exceptions occur
6. **Exception Propagation**: Let exceptions bubble up appropriately
7. **Catch by Reference**: Always catch exceptions by const reference

## 🔗 Next Steps

After mastering Module 05, you'll be ready to tackle:
- **Module 06**: C++ casts and type conversions
- **Module 07**: Templates and generic programming
- **Module 08**: STL containers and iterators

---

<div align="center">

*"Exception handling is not about expecting failure, it's about building resilient systems."*

**Module 05 Complete** ✨ | **Previous**: [← Module 04](../CPP_Module04/README.md) | **Next**: [Module 06 →](../CPP_Module06/README.md)

</div>
