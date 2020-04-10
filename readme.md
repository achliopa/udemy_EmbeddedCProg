# Udemy Course: Microcontroller Embedded C Programming: absolute beginners

* [Course Link](https://www.udemy.com/course/microcontroller-embedded-c-programming/)
* [Course Repo](https://github.com/niekiran/Embedded-C)

## Section 1: Introduction

### Lecture 1. Programming languages for Embedded Systems

* C is still the most powerful and popular in Embedded Programming also C++

### Lecture 2. History of 'C' and standardization

* C89 C90 first (1989,1990) , then C99 (1999) then C11 (2011)
* we will use C11 standard with some compiler gCC extensions gnu11

## Section 2: IDE installation

### Lecture 4. Downloading IDE

* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
* we will use Eclipse based STM32CubeIDE developed by ST Microelectronics to write, compile and debug apps on STMew ARM mCUs
* STM32CubeIDE is an Eclipse Based ID customized for STM32

### Lecture 5. Key features of the STM32CubeIDE

* STM32CubeIDE supports all OS
* it integrates STM32CubeMX
	* in older versions we generated a project in MX and then imported it in IDE
	* now its seamless
* comes bundled with compilers and debuggers
* offers advanced debuging with SWV (system analysis and RT tracing)

### Lecture 6. Installing STM32CubeIDE

* extract and install

### Lecture 8. Installing compiler (GCC) for host

* STM32CubeIDE is an IDE to develop, compile and debug embedded apps for STM32 MCUs
* STM32CubeIDE installer also installs the GCC cross compiler for ARM Cortex Mx Procs
* Using the same compiler we write C programs also for the Host Machine
* We need to install gcc for Host. that does not come with installation
* In windows we need to install MinGW (Minimal GNU for Win)

### Lecture 9. Installing compiler (GCC) for host (WINDOWS)

* we get it from [here](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/)
* click next till we get to MinGW Installation Manager
* mark gcc g++ for installation and msys-base-bin
* click installation => apply changes => apply
* after completion we need to set the PATH
* System Properties => Advanced System Properties => Advanced => Environment Variables add the C:\MinGW\bin and C:\MinGW\msys\1.0\bin to Path.
* run `cmd` and in it `gcc` to see it has been installed properly also popular linux commands like `ls` or `rm` are available
* we set `\embedded_c\courseRepo\host` as workspace and launch
* we go to file => import=> General=>existing projects into workspace then select from the Embedded_C repo/all projects/host and import all projects.
* click copy projects into workspace => Finish
* click on restore icon
* we can close info center anr build analzer
* we select the first project => RCLICK => build project. it build ok
* we can clean the project (RCLICK -> clean project)
* we are now done with importing all host projects
* we will now import and buld target projects
* File => Switch Workspace => other and replace host folder with target 'C:\Users\achliopa\workspace\udemy\embedded_c\courseRepo\target\stm32f407_disc' => Launch
* we are now in trget workspace (click restore)
* we again do the same drill importing all project (copy into workspace) in target folder of the downloaded repo
* rclick on a project and build project. it builds
* we confirm the corsscompiler is used
* now we have 2 workspaces with all working projects by the instructor
* we should keep them as reference. not mess with them
* In IDE again we switch workspace passing in `C:\Users\achliopa\workspace\udemy\embedded_c\myCode\host` and launch
* now we have a workspace for host for us to play
* we do the same for target passing myCode\target

### Lecture 13. Creating a project for the HOST

* we select our host workspace by switching workspace
* Create a Project: New => c/c++ project => c managed build => name => toolchain: minGW CC => next => finish
* add a source file: new => source file => main.c
* write some boilerplate code
```
#include<stdio.h>

int main(void) {
	printf("Hello World");
	printf("Press 'Enter' to exit this application");

	getchar();

	return 0;
}
```

* build project
* to find the xecutable: rclick on the binary file => properties => show in system explorer dclick on executable

### Lecture 14. Creating a project for the Target

* switch workspace to our target 
* File => New => STM32 Project => wait to launch CubeMX => select MCU and/or board
* we select our board => name project, Targeted lang: C,  Targ.Bin>File Executable, Target Project Type: Empty
* If we selet STM32Cube we will have to configure the BSP according to out prefs
* we build project as is. we get only one warning (FPU not initialized)

### Lecture 15. FPU warning fix

* The build basically warning you that ,you have enabled using hardware floating point unit of the processor in the build settings but you have not initialized that using your code. So, it is warning you to initialize it before using any floating point related code otherwise it may result in processor fault exception.
* To get rid of this problem you can do this RCLICK on the project -->properties -> expand C/C++ build --> Settings --> Tool settings -->MCU settings ->
	* keep floating point unit: NONE and Floating point abi option: Software 
	* apply - close - clean project - build project
* this is to not use FPU if we want to use it we dont touch these but use the FPU in code (more efficient)

### Lecture 16. Meet the embedded target of this course

* we dont use the discovery board we dont have it.. we will use the Nucleo Board we have... se should have the datasheet close by

## Section 3: Your first 'C' program

* we will use for start the [OnlineGDB](https://www.onlinegdb.com/) a webbased debugger and gcc compiler (actually supports many languages)
* its a good learning tool

### Lecture 18. Printf and Hello World

* we ll write a simple C hello world program
* name project select c lang. the code is there 
* in settings we can set the compiler options if we want
* `printf` comes from `stdio.h`
* standard libs must be included with <> `#include <stdio.h>`
* we know that.... next
* we pass in compiler flag `-save-temps` when we compile we get the assembly code main.s and object file main.o and the preprocessor file main.i
* preprocessor file main.i contains our code and system code we included. prototype of printf is found and used
* from main.i after compilation main.s is produced containing assembly instructions
* main.s will be converted from assembler into machine code main.o. this object file can be executed by the processor and contains opcodes

### Lecture 20. Escape sequences in 'C'

* `\'` single quote
* `\"` double quote
* `\\` backslash
* `\0` null
* `\a` bell
* `\b` backspace
* `\f` formfeed
* `\n` newline
* `\r` carriage return. moves cursor to the beginning of the current line horizontaly
* `\t` horizontal tab
* `\v` vertical tab

## Section 4: Data types and variables

* 2 basic data types in C: integers and floats
* integers (signed): char (8bit), short (16bit), int (32bit), long (64bit), long long (64bit)
* integers (unsigned): unsigned char (8bit), unsigned short (16bit), unsigned int (32bit), unsigned long (64bit), unsigned long long (64bit)
* sizes depend on compiler and target processor architecture. thats why we should use macros
* C standard does not fix sizes. only guidelines
* compile independent are only char,short and long long
* char is usually used to store ASCII chars
* in C we have variable definition `char cityTemp;` and variable initialization `cityTemp=20;` these 2 canbe combined
* Format specifiers for printf
	* `%d` integer format
	* `%f` float format
	* `%c` character format
	* `%s` string format
	* `%u` unsigned int format
	* `%l` long int format
	* `%p` address in hex format
	* `%lld` for long long
	* `%llu` for long long unsigned
	* `%x` for int in hex format , lx, llx
	* `%lf` double format
	* `%#x` print padded formated hex

* in signed data MSB stores the sign (bewareof endianess) usually the leftmost bit (7th)
* signed data is stored in 2s complement form: reverse binary + 1
* unsigned data are stored in plain binary
* char range -128 - 127, unsigned char is 0 - 255
* `sizeof(variable)` in C returns the size in bytes
* variable is a label to a mem location where data is stored
* variable name is not stored in memory. compiler rips them off
* mem location address is called pointer in C
* size of memory word is dependent on architecture
* before using a var we need to define it.
* var definition is telling compiler to do memory reservation for the var
* var initialization is puting some valuable in memory allicated for the variable. otherwise it contains garbage
* definition an initialization in one step `int me = 0;`
* var definition is mem allocation by compiler for the var
* var declaration is telling compiler var exists and has a type. its not mem allocation. definition is also declaration. the reverse does not hold
* if i use `extern int myExamScore;` in global space (outside of a func) we tell the compiler that this variable is coming from a header file we included (external to the current source file)
* variables have scope: their accesibility in a program or function
	* local: defined in a function, available in the function not even in nested ones
	* global: defined out of the function available to the whole program (same sourcefile)
* functions must be definef before called or prototyped (usually in a header file)
* we can use same name for local and global val. local has priority in the function
* we create execution bodies with { } even in the function. these work as namespaces... if a var is defined in it outside of this conetxt loses its priority over the global var with the same name even in its own function
* outside of its execution context or execution body a var loses its existence
* global values have a default val of 0 and live till end of program

## Section 5: Address of variable

* address of variables is represented with `&` &variable
* when we define consequetive vars there is high prob to be in neighbour mem locations
* the &variable is actually a pointer not a usual variable
* we should be aware of the adress space if its 32bit or 64bit
* if we try to define a pointer like this `unsigned long int addressOfa1 = &a1;` we have the following problems
	* `&a1;` is pointer data. pointer data are represented vy pointer data type in C. the type is: char *
	* `unsigned long int addressOfa1` represents a ariable. variables are represented by variable data type: the type is unsigned long int
* there is type mismatch in the assignment. we are trying to assign a pointer data type into a var. there is data type mismatch.
* to solve it we need to convert pointer data type into variable data type using typecasting `unsigned long int addressOfa1 = (unsigned long int)&a1;`. note that now we dont have a pointer but a number
* we still have a problem as for a x64 machine the pointer is a 8byte (64bit) num. if the machine treats long ad 4byte the address will be truncated. we need to use long long

## Section 6: Storage classes

* Storage Class in C lang decides: scope and lifetime of a var, visibility of a var or function.
* scope,visibility and lifetime are feats of a var. they are modified by using storage class specifiers: static and extern
* when defining a global value its available anywhere in the program so it might e modified. this is dangerous
* if we want a global variable that is private to a function. we want a var that does not lose its existence even if te exectuion control goes out of its scope. we use **static**
```
void fun() {
	static int count = 0;
	count +=1;
	printf("%d\n",count);
}
```

* a global variable is available to the whole project not just ita source file. in the other source files we have to declare it with `extern <datatype> <variablename>;`
* if we want to keep a global variable private to the source file it is defined we have to define it as `static`. the same holds for functions. if we want the function private to the file it is implemented we use static e.g
```
static int foo() {
	return 1;
}
```

* extern is not mandatory (is optional) for functions when we declare their prototype in the external file where we want to call them.
* the protottype is needed also when we call them in the same before their implementation
* ASCII supports 127 chars (7bits long) it fits in char
* we can set ASCII as chars  using single quote `char a1 = 'A';`
* be careful to use formatter %c when printing chars 

## Section 7: functions

* outside of function ONLY definitions
* main returns int to the calling process upon exit
* before calling a function we need to declare it with a prototype or define it (implement it)
* implicit declaration is what compiler assumes as prototype. its NOT safe
* prototypes are placed in a header file with declarations
* header file must contain the included guards (they are added automatically) they prevent including them multiple times (they use prerocessor directives)
* when we include our header files we use "" `#include "my.h"`
* typecasting is a way of converting a variable or data from one data type to another data type
* data is truncated when higher data is casted to lower
	* implicit casting is done by compiler (e.g constant are treated by compiler as 4byte int)
	* explicit casting is done by us
* `unsigned chat data = 0xff + 0xffff` has 2 implicit casting. on on RHS (to 4byte) and one on assignment 4b to uchar with potential data loss
* if we type cast the lest part of a mathematical operation theright side is implicitly typecasted to same format

## Section 8: Microcontroller and Hello World

### Lecture 50. Embedded - 'Hello World'

* create an stm32 project in our target workspace on empty targeted project type named 001HelloWorld
* in inc folder we put header files in src folder c files
* when working on MCU projects we need a startup code for the MCU. in our case its assembly code
* in the main.c we include stdio.h and add the printf
* how we put printf in MCU code??
	* in ARM Cortex M3/M4/M7 or higher proc printf works over the SWO pin (serial wire output) of SWD interface
* The SWO pin goes to STlink V2 Debug circuit
* The ITM unit (instrumentation trace macrocell unit) is an optional application driven trace source that supports printf style debugging to trace operating system and application events and generates diagnostic system information
Debug Connector (SWD interface) is a 2wire protocol for accessing the ARM debug interface (2pin debug: SWDIO bidir dataline, SWCLK host driven clock + 1pin trace). SWD is a JTAG alternative
* using SWD interface  we can program MCU internal flash, access mem regions, add breakpoints stop/run CPU
* the extra serial wire viewer of SWD can be used  for printf statements
* JTAG needs more pins 4. SWD supports tracing
* ITM unit has a FIFO outputing to SWO pin captured by the IDE via STlink
* we copy the code snippet needed to use printf from itm_send_data.c in repo
* in syscalls.c after includes we add
```
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//					Implementation of printf like feature using ARM Cortex M3/M4/ ITM functionality
//					This function will not work for ARM Cortex M0/M0+
//					If you are using Cortex M0, then you can use semihosting feature of openOCD
/////////////////////////////////////////////////////////////////////////////////////////////////////////


//Debug Exception and Monitor Control Register base address
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{

	//Enable TRCENA
	DEMCR |= ( 1 << 24);

	//enable stimulus port 0
	ITM_TRACE_EN |= ( 1 << 0);

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 1));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = ch;
}
```

* in the same file syscalls.c in `_write()` function we comment out `__io_putchar(*ptr++);` and add `ITM_SendChar(*ptr++);` that we have added
* in std.lib `printf()` uses `_write()` that we have modded to use ITM unit
* we build the project using the gnu cross compiler for arm 'arm-none-eabi-gcc' that run on host x86 and produces executables for different architecture (ARM) .elf .bin .hex
* .elf is used only for debugging. .bin and .hex are for production (no debug)
* we then have to load the file to target. we connect the target
* RCLICK on project => Debug As => Debug Configuration => DClick on STM32Cortex-M
* we see that it will load the .elf file . we are ok with that we want to debug
* in Debugger tab select ST-LINK GDB, select SWD, enable Serial Wire Viewer
* Apply - Close
* RCLICK to project => Debug As STM32 C/C++ project
* to view printf once we debug Window => Show View => SWV => SWV ITM Data Console
* In the ITM Data Console 
	* select trace button => enable port 0
	* click start trace button
* the printf needs \n to work

### Lecture 52. Testing printf over OpenOCD semihosting

* To use OpenOCD Debugger and Semi-Hosting with STM32CubeIDE for M0 cores tracing
	* set the linker arguments `-specs=rdimon.specs -lc -lrdimon`
	* add semi-hosting run command `monitor arm semihosting enable`
	* add the below function call to main.c
```
extern void initialise_monitor_handles(void);
initialise_monitor_handles(void);
```
* to test this setup we create a new project 001HelloWorld_semihosting with settings like before
	* build the project
	* RCLICK project => DebuAs => Debug Config
	* Select ST3M32 MCU Debugging  and then on top left click New Launch Config
	* we keep it applied on our .elf file
	* in Debugger tab Debug Prob: StLink(OpenOCD)
	* in Startup tab in Run Commands paste `monitor arm semihosting enable` Apply - Close
	* RCLICK on Project => Properties => C/C++ Build => Settings => Tool Settings => MCU GCC Linker => Miscellaneous => Other Flags => Add => paste `-specs=rdimon.specs -lc -lrdimon` => Apply & Close
	* in main.c we cp the HelloWorld code and mod it like this
```
#include <stdio.h>

extern initialise_monitor_handles(void);
int main(void)
{
	initialise_monitor_handles();
	printf("Hello World\n");
	for(;;);
}
```

* RCLICK on syscalls.c => Properties => C/C++ Build => enable Exclude Resource from Build => Apply & Close
* Clean Project and Build Project
* Connect HW and Debug As => STM32...
* print appears in console (\n is required)

### Lecture 53. Run Sizeof on Embedded Target

* print sizeof various datatypes to see the sized in embedded device
* we create sizeof with all settings  configured to use the ITM Unit for trace
```
#include <stdio.h>

int main(void)
{
	printf("Sizeof char datatype: %u\n",sizeof(char));
	printf("Sizeof short datatype: %u\n",sizeof(short));
	printf("Sizeof int datatype: %u\n",sizeof(int));
	printf("Sizeof long datatype: %u\n",sizeof(long));
	printf("Sizeof long long datatype: %u\n",sizeof(long long));
	printf("Sizeof float datatype: %u\n",sizeof(float));
	printf("Sizeof double datatype: %u\n",sizeof(double));
	for(;;);
}
```

* the trace is typical for an ARM 32bit proc
```
Sizeof char datatype: 1
Sizeof short datatype: 2
Sizeof int datatype: 4
Sizeof long datatype: 4
Sizeof long long datatype: 8
Sizeof float datatype: 4
Sizeof double datatype: 8
```

### Lecture 55. Compiler settings on STM32CubeIDE

* to see the compiler settings; RCLICK on project => Properties => C/C++ build => Settings 
	* => Toolchain version tab => toolchain is set to default (crosscompiler, we see version and location)
	* tool settings => mcu settings: (fpu, runtime lib)  project uses the nano runtime lib of C for efficiency
	* tool settings =>MCU Post build outputs: nothing extra only elf
	* tool settings =>MCU GCC Compiler
		* => General: set the C standard used for the build. dont change it
		* => optimizantion: none
	* tool settings => MCU GCC Linker: leave it as is
* we can download a new version or toolchain from [here](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) we want the RM family of procs not the A

## Section 9: Build process

### Lecture 56. Embedded project build process

* Build Process
	* Preprocessing: .c file(s) => .i file(s) all libs included etc
	* Parsing: .i file(s) => [check syntax]
	* Producing object files(s): [code generation] => .s file(s) => [Assembler] => relocatable .o file(s) a.k.a machine code
	* Linking Object file(s): 
	* Producing final executable: .o files + .a files (other libs std and 3rd party) [Linker] => .elf debug file 
	* Post processing of final executable: .elf file => [objcopy tool] => .bin pure binarey executable for prod
* we confirm these stages by building a project
* to see the files: RCLICK on project => Resources => Show in System Explorer
* .i and .s files are not outputed. to see them we need to go to project C/C++ Build => Settings =>
MCU GNU Compiler => Miscellaneous => Other Flags => Add.. `-save-temps` apply ok and rebuild

## Section 10: Analyzing Embedded C code

### Lecture 57. What is a Microcontroller ?

* Analyzing an Embedded C Program
	* Anatomy of the microcontroller
	* Identifying code and data parts of the program
	* Code memory and data memory of the MCU
	* Disassembly feature of the IDE
	* Analyzing the executable (.elf) using GNU tools (like objdump and size)
* MCU is a small computer on single chip SoC. mem,speed, ext interfaces are limited. it targets Embeeded Apps
* MCU includes: proc core, mems (vol and nonvol), I/O pins, peripherals, clock, bus (Data, Address, Control) IFs all on a SoC
* Program Memory is non volatile (Flash)
* Data Memory is Volatile (SRAM)
* CPU communicates with Program Mem with Bus. first Address Bus carries the location of instruction and Data Bus returns the instruction for execution
* Speed of instr execution is set by the clock
* A sample MCU is STM32 CortexM4 based

### Lecture 58. Code memory of the microcontroller

* Code Memory
	* Program mem stores instructions and constant data of our program
	* Types: ROM (EEPROM),OTP,Flash,FRAM(speed)

### Lecture 59. Code and Data of the program using memory browser

* we look at 003Add program which uses 3 global vars
* 1 is for result
```
#include <stdio.h>
/* global variables */
int g_data1 = -4000;
int g_data2 = 200;
int result = 0;
int main(void)
{
	result = g_data1 + g_data2;
	printf("Result = %d\n",result);
	for(;;);
}
```

* we build project and get elf file to download to MCU
* global data is in the elf
* we debug as STM32
* in debugger we will examine FLASH content
* Window => Show View => Memory Browser
* we need to pass in the base address of our program . we will get it from the ref manual of the microcontroller and check the Flash Module Organization
* we see that our MCU has 512KB of Flass in 8 sectors follow by 30KB system memory (non editable). the available rang eis 0x08000000 to 0x080FFFFF
* we put 0x08000000 in browser. 
* the content we see after it is the machine code
* the content is in address value pairs in 32bit words format
* if we want to seebyte-byte we put cell size 1 and column size 1
* for SRAM we find the base memory by the manual
* for our MCU its 0x20000000 we change radix to decimal signed we see our global vals

### Lecture 60. Analyzing ELF file using GNU tools

* when we dowload program in FLASH mem of the microcontroller, data should be in FLASH. how our data arrived in data mem SRAM???
* we will analyze the object file 003Add.elf using GNU tools `arm-none-eabi-objdump.exe` to find our global data
* in MINGw64 we go to project 003Add/Debug and run `arm-none-eabi-objdump.exe -h 003Add.elf` the referneced data is same as 003Add.list file
* -h displayes content of section headers
* the file has 2 columns LMA: Load MEmory Address (Source in FLASH) and VMA: Virtual Memory Address (Destination in SRAM)
* we see that .data go from 0x08001350 (FLASH) to 0x20000000(SRAM) we also see the size of data 
* the copy is done by our program but by the startup code which is 'startup_stm32f446retx.s' and the ResetHandler which runs at startup or after a reset 
* we see that it copies the data segment  initializers from flash to SRAM
* The startup sequence is
	* Reset MCU
	* proc jumps to reset handler
	* copy data from FLASH to SRAM
	* Zero out SRAM locations corresponds to .bss section size
	* Call std.lib init function `__libc.init()`
	* call main() of user prog
	* never return from main() back to reset handler
* we put a breakpoint in CopyDataInit in assembly called by ResetHandler to copy the data
* w want to check content of r2 and ro that contain source and dest addresses
* window => show view -> registers
	* we confirm r2 in hex is the address of data in FLASH
	* we confirm r0 in hex is the address of data in SRAM
	* we confirm r4 in hex is the actual data

### Lecture 61. Disassembly

* dissasembly is the action of passing the machine code into a tool called objdump and get the assembly code
* IDE gives us a disasembly window for instruction level debugging
* while in debug mode Window => Show view => Disassembly
* Proc: ARM Cortex M4
* Proc Arch: ARMv7E-M
* Instruction set archotecture (ISA): Thumb-2 inst. set (16/32 bits instruction encoding)
* a C operation breaks into multiple proc instructions `result = g_data1+g_data2;` is
```
33                   	result = g_data1 + g_data2;
080002b4: 0x0000064b   ldr     r3, [pc, #24]   ; (0x80002d0 <main+32>)
080002b6: 0x00001a68   ldr     r2, [r3, #0]
080002b8: 0x0000064b   ldr     r3, [pc, #24]   ; (0x80002d4 <main+36>)
080002ba: 0x00001b68   ldr     r3, [r3, #0]
080002bc: 0x00001344   add     r3, r2
080002be: 0x0000064a   ldr     r2, [pc, #24]   ; (0x80002d8 <main+40>)
080002c0: 0x00001360   str     r3, [r2, #0]
```

* data is loaded from mem to proc registers using load instructions (ldr)
* the an add operation takes place
* then data is written back to mem location
* we can use `arm-none-eabi-objdump.exe -d 003Add.elf` to do the task from command line
* we can add breakpoints in disassembly window
* to avoid putting breakpoints on each instruction in IDE and Debug Mode there is the i-> button for instruction stepping mode

## Section 11: Data types to manipulate floating point data

* float point is an approximation  of a real number
* IEEE-754 floating point standard => sign + mantissa (significand) +exponent
* mantissa is an approximations
* single precission 32b => significand (23bit: 0-22bit) exponent(8bit: 23-30bit) sign (1bit: 31bit)
* read/write in scientific notation %e %le formater (using e+exponent)
* float precision: 6 decimal places (exponent up to 38)
* double precision: 15 decimal places (exponent up to 308)
* if we assign a value with >6 decimals to a float it is truncated to 6
* if we print >6 decimals in formater %0.9f it prints 3 garbage digits 
* to store using scientific notation `-1.5352352e-19`

## Section 12: Taking input from the user using scanf()

* scanf() is a stdlib function that allows us to read inpput from stdin
* stdin is for us the keyboard
```
int age;
printf("Enter your age: ");
scanf("%d",&age);
```

* scanf reads an integer entered and puts that val at the address of age var
* if we use a char formatter for an int val its ASCII val will be stored
* if we just want to read a single char from the keyboard in ASCII format then we just use getchar(). it takes no arg and returns the ASCII val of the key pressed `int a = getchar();`
* We create 001Average host project to calc average from 3 integers we input
```
#include <stdio.h>

int main(void) {
	float num1, num2, num3;
	printf("Enter num1: ");
	scanf("%f",&num1);
	printf("\nEnter num2: ");
	scanf("%f",&num2);
	printf("\nEnter num3: ");
	scanf("%f",&num3);
	printf("\nAverage is: %f",(num1+num2+num3)/3);
	printf("\nPress key to exit");
	getchar();
	getchar();
	return 0;
}
```

* IDE console is buffering the output. we need to use fflush(stdout) to flush the output buffer
* when we write to keyboard it goes to input buffer and then to program. 
	* when we write 123 and hit enter the buffer has 123\n
	* scanf takes only the num 123 but the \n stays in buffer
	* if we getchar() the \n is pulled from buffer before we even press
* we can read 3nums in one scanf() `scanf("%f %f %f",&num1,&num2,&num3);`
* scan accepts TAB, ENTER or SPACE as delimiter

## Section 13: Pointers

* Pointers are used in C programming to
	* configure the peripheral register address
	* read/write into peripheral data registers
	* read/write into SRAM/FLASH locations and for many other things
* pointers keep a mem adress. on a 32bit machine the pointer size (mem location address size) is 4bytes (32bit)
* having the pointer we can write a value in this address using `*var`
* we can increment the pointer navigating in memory to read/write vals
* pointer data types are <datatype>* `char*`
* to pinter we assing mem address (OUCH)
* literals even hex we must cast to pointer type beore assigning `char* address1 = (char*) 0x0007ffff`
* the pointer datatype has to do with mem allocation.. it allocates enough space depending on the datatype size
* the compiler will always reserve 4 bytes(for ARM) for the pointer variable irrespective of their pointer data type. data type is not for the pointer variable but for mem allocation. it affects the behaviour of the operation carried on th ponter var (read/write incr/decr)
* to read/write data from the pointer `char* address1 = (char*) 0x0007ffff` we use `char data = *address1;` when we use `*pointer` we say we dereference it
* `*var` value of address `&var` address of var
* `&var` has as pointer datatype the datatype of the var variale datatype (implicit)
* its good to name pointers starting with p e.g `pAddress`		
* Exercise
	* create a char type ver and initialize it to 100
	* print the address of the above var
	* create a pointer variable and store the address of the above variable
	* perform read op on the pointer to fetch 1 byte of data
	* print the data obtained from the read op on the pointer
	* perform write op on pointer to store val 65
	* print the val of the variable defined in step 1
```
#include <stdio.h>

int main(void){
	char var1 = 100;
	printf("var1 address: %p",&var1);
	char* adr1 = (char *) &var1;
	char var2 = *adr1;
	printf("Deref val of *adr1 is: %c",var2);
	*adr1 = 65;
	printf("var1 value: %c",var1);
	getchar()
	return 0;
}
```

* DONT mix or mess up pointer data types

## Section 14: Importance of <stdint.h>

* data types may cause compatibility issues across architectures and compilers. Use MACROS aka aliases from the stdint.h lib instead 
	* int8_t, uint8_t, int16_t,....
	* uintmax_t: largest fixed-width unsigned int on the system
	* intmax_t: largest fixed-width signed int on the system
	* uintptr_t: unsigned int type wide enough to store a pointer

## Section 15: Operators

* C operators
	* `++`,`--` : increment and decrement operator (Unary)
	* `+`,`-`,`*`,`/`,`%` : Arithmentic operators (Binary)
	* `<`,`<=`,`>`,`>=`,`==`,`!=` Relational operators (Binary)
	* `&&`,`||`,`!` Logical operators (Binary)
	* `&`,`|`,`<<`,`>>`,`~`,`^` Bitwise operators (Binary)
	* `=`,`+=`,`-=`,`*=`,`/=`,`%=` Asignement operators (Binary)
	* `? :` Conditional Operators (Ternary)
* Operator Precedence rules determine which math operation takes place first. () may be use to force higher precendence
* Asociativity is depending on operators and is used when multiple operators of same precedence exist
* `x=5;y=++x;` preincrementing (y=6,x=6)
* `x=5;y=x++;` postincrementing (y=5,x=6)
* same holds for --
* in pointers the ++ or -- moves the pointer so many places depending on the pointer datatype. `uint32_t *pAddress = (uint32_t*) 0xFFFF0000;` `pAddress++;` new pAddress=0xFFF0004
* relational operators return 1 (true) or 0 (false)
* in C 0 is treated as false, anything !=0 is true

## Section 16: decision making

* 5 different ways in C
	* if statement
	* if-else statement
	* if-else if statement
	* conditional opers
	* switch/case statement
* for single expression in if-else statements we can skip {} (use TAB)
* we cant nest if-else statements
* scanf() returns 1 if successful 0 if not

## Section 17: Bitwise operators

* `&` bitwise AND  for testing bits (&1) and clearing bits(&0)
* `|` bitwise OR   for setting bits
* `<<` bitwise Left Shift
* `>>` bitwise Right Shift
* `~` bitwise NOT (unary) `notA = ~A` for clearing bits (&~mask)
* `^` bitwise XOR for toggling bits
* we do bit testing with a bit mask and AND . if bitwise AND is 0 it fails
* to clear using ~ we negate the mask value first and then perform bitwise AND
* toggle LED at bit0 with XOR `led_state = led_state ^ 0x01`

## Section 18: Embedded C coding exercise for LED

* Write a program to turn on the LED of out target board. we need to know: pointers, bitwise ops, HW connections
* we check the schematic of the board. user LED (LD2) is connected to PA5( GPIO PortA bit5)
* we need to control the state of the pin using the GPIO A peripheral
	* it has registers that control pin's mode/state and functionalities
	* we can acess registers using mem address. 
	* the peripheral registers are memory mapped
* Memory Mapped I/O
	* I/O pins are controlled using peripheral registers which are mapped on to processor addressable memory locations
* What are processor addressable memory locations?
	* AHB System Bus connects the CPU with peripherals (32b addr channel, 32b data channel)
	* the system bus supports a 2^32 4GB memory map 0x00000000 - 0xFFFFFFFF addresses
	* pointers and manual are used
* We consult the Memory Map: GPIOA Register Map (0x40020000 - 0x400203FF)
* All peripheral registers in STM32 MCU are of 32b wide
* Diff peripherals have different number of periph registers
* We should never assume about the address of periph reg. ALWAYS consult te manual
* to control the LED at least we need 
	* GPIOA port mode register: at 0x40020000 we need to set 01 at bit 10-11
	* GPIOA port output data register: at 0x40020014 we neet to set/reset bit 5
* To turn on the LED:
* identify the GPIO port (a peripheral) used to connect to LED (GPIOA)
* identify the GPIO pin where led is connected (pin 5)
* Activate the GPIO peripheral (enable the clock)
	* until we enable the clock to a peripheral it is dead and it nether functions nor it takes values set by us
	* once we activate the clock for a peripheral, the peripehral is ready to take the configuration and control-related commands or arguments (config values)
	* for some MCUs the peripheral may be ON by default, and we need no activation (check the MANUAL)
	* Configure the GPIO pin mode as output. since we are driving a LED it must be set to Output
	* Write to the GPIO pin: 1 (HIGH) for high state, 0(LOW) for low state
* To enable the Peripheral Clock
	* through the peripheral clock regs of the MCU
	* in STM32 MCU all clock control regs are mapped at the below address rangein the MCU mem map 0x40023800 - 0x40023BFF (RCC)
	* we need the RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) at address 0x40023830 and to enambe GPIOA we need to set bit0 to 1
```
#import <stdint.h>

int main(void)
{
	uint32_t *pRCCAhb1EnReg = (uint32_t*) 0x40023830;
	uint32_t *pGPIOAModeReg = (uint32_t*) 0x40020000;
	uint32_t *pGPIOAOutDataReg = (uint32_t*) 0x40020014;
	*pRCCAhb1EnReg |= 0x01;
	uint32_t maskClear = 0xFFFFF3FF;
	uint32_t maskSet = 0x00000400;
	*pGPIOAModeReg &= maskClear;
	*pGPIOAModeReg |= maskSet;
	for(;;){
		*pGPIOAOutDataReg  ^= 0x00000020;
		for(uint32_t i=0; i<500000;i++){
			i++;
		}
		*pGPIOAOutDataReg  ^=  0x00000020;
		for(uint32_t i=0; i<500000;i++){
			i++;
		}
	}
}

```

## Section 19: Bitwise shift operators

* when we are shifting we are 0 padding the positions left 
	* set 4th bit of data `data = data |(1<<4);`
	* clear the 4th bit of data `data = data &~(1<<4);`
* bit extraction: extract bit positions from 9th to 14th in data and store it in another var
	* shift the identified portion to right hand side until it touches the least signisficant bit (0th bit)
	* mask the values to extract only 6bis [5:0] and save it to another var 
	* `output (uint8_t)((data >>9)&003F);`

## Section 20: Looping

* ic C there are 3 types of loops
	* for loop
	* while loop
	* do...while loop
* for single statement in a loop we can omit {}
* While loop
	* expression is evaluated
	* if its true execute statements if its false it breaks
	* go back to condiitonal expression
* in printf use %4d so that nums occupy 4 places (space padded)
* do while loop
	* statements are extecuted first before the expression check (guaranteed 1 execution)
	* it is used to write multiline macros in header files
* if for loop 
	* block2 (condition) is executed before statements
	* after statements are executed block3(index manipulation) is executed and then block2
	* block3 can be omitted (increment index in statements)
* we can nest for loops

## Section 21: Type qualifier 'const'

* 2 qualifiers in C. applying these qualifiers to a variable declaration is called qualiffying the declaration:
* **const:** 
	* is used to enforce read-only  feat on variables. 
	* modifying value throws compile error 
	* `uint8_t const data = 10;` or `const uint8_t data = 10;`
	* we can still modify the val using the address
	* local const variables are still placed in RAM
	* global const variables are stored in FLASH (STM32). if we try to mod it with address we will get an error as FLASH is write protected
* **volatile:**
* **using const in pointers** (modifiable pointer constant data) `uint8_t const *pData = (uint8_t*) 0x40000000;`
	* the pointer is modifiable but the data pointed by the pData cannot be modifiable (read-only)
	* pData is a pointer pointing to read-only data
	* it is used to protect datacontenct during data copy (using pointers) from mistake or tampering
	* Use Case: Secure Data Copy
```
void copy_src_to_dst(uint8_t const *src, uint8_t *dst, uitn32_t len){
	for(uint32_t i=0;i<len;i++){
		*dst = *src;
		dst++;
		src++;
	}
}
```
* **using const in pointers** (modifiable data and constant pointer) `uint8_t *const pData = (uint8_t*) 0x40000000;`
	* here the pointer pData is read only but the data pointed by the pData can be modifiable
	* so we can say that pData is a read only pointer pointing to modifiable data
	* Use Case: Improve readability and guard the pointer vars
```
// update the details of age and salary in to the pointer provider
// by the caller
void update_user_data(uint8_t *const pUserAge, uint32_t *const pUserSalary){
	if(pUserAge != NULL) {
		*pUserAge = getUserAge();
	}
	if(pUserSalary != NULL) {
		*pUserSalary = getUserSalary();
	}
}
```
* **using const in pointers** (const data and const pointer) `uint8_t const *const pData = (uint8_t*) 0x40000000;`
	* here the pointer pData is read-only and the data pointed by the pData is also read-only
	* so, we can say that pData is a read only pointer pointing to read-only data
	* Use case: read data from the status register
```
// read and return the content of status register pointer by pStatusReg
// accidental write to SR may cause unpredictable consequences
uint32_t read_status_register(uint32_t const *const pStatusReg){
	return (*pStatusReg);
}
```
* const value being unmodified has only 1 state. no need to track it
* good practice in function prototypes to protect data
* leads to code optmization

## Section 22: Pin-read

* Exercise:
	* write a program that reads the status of the pin PC13. if the status of PC13 is LOW then turn LOW the on oboard led (PA5)
	* change the status of PC13 manually by pushing the User Button
* We need to set clock in GPIOC and set pin 13 to Input
```
#import <stdint.h>

int main(void)
{
	uint32_t *pRCCAhb1EnReg = (uint32_t*) 0x40023830;
	uint32_t *pGPIOAModeReg = (uint32_t*) 0x40020000;
	uint32_t *pGPIOCModeReg = (uint32_t*) 0x40020800;
	uint32_t *pGPIOAOutDataReg = (uint32_t*) 0x40020014;
	uint32_t *pGPICInDataReg = (uint32_t*) 0x40020810;
	uint32_t pinStatus;

	*pRCCAhb1EnReg |= 0x05;
	uint32_t maskClear = 0xFFFFF3FF;
	uint32_t maskSet = 0x00000400;
	*pGPIOAModeReg &= maskClear;
	*pGPIOAModeReg |= maskSet;
	maskClear = 0xF3FFFFFF;
	*pGPIOCModeReg &= maskClear;
	for(;;){
		pinStatus = *pGPICInDataReg & 0x2000;
		if(pinStatus){
			*pGPIOAOutDataReg  &= ~(1<<5);
		}else {
			*pGPIOAOutDataReg  |= (1<<5);
		}
	}
}
```

## Section 23: Optimization

* GCC Compiler flags to enable optimization
* `-O3`:
	* full optimization of -O2 + some more aggressive optimization steps will be taken by the compiler
	* slowest compilation time
	* may cause bugs in the program
	* not debugging friendly
* `-O2`:
	* full optimization
	* slow compilation time
	* not debugging friendly
* `-O1`:
	* moderate optimization to decrease memory access time and code space
* `-O0`:
	* no optimization
	* not recommended for production if we have limited ram and flash space
	* fast compilation time
	* debugging friendly, used during development
	* a code thaat works at -O0 level might not work at higher optimization levels . code needs to be verified again
* to set optimization level: RCLICK to project => Settings => C/C++ Build => Settings => MCU GCC Compiler => Optimization
* we change it to -O1 and re build and debug: size is reduced
* we see that in -O2 our led app breaks
* we open disassembler to see why this happens (in -O0)
* we debug the logic to see why the if statement fails
* in each loop the proc needs to obtain a fresh value from indatareg mem location and update pinStatus
* we check again at -O2 level. pinstatus update doe not happen at all reg0 is checked but not updated
* we need to tell the compiler to NOT optimize the pinStatus assignment

## Section 24: 'volatile' type qualifier

* **Volatime**
	* is a type of qualifier in C used with variables to instruct the compiler not to invoke any optimization on the variable operation
	* it tells the compiler that the value of the variable may change at any time with or without the program consent. So the compiler turns off optiming the read-write operations on variables which are declared using tvolatile keyword
	* Volatile is very mush helpful in embedded systems code
	* for our led code to safely run in -O3 levels and be safeguarded we add qualifiers
```
#import <stdint.h>

int main(void)
{
	uint32_t *const volatile pRCCAhb1EnReg = (uint32_t*) 0x40023830;
	uint32_t *const volatile pGPIOAModeReg = (uint32_t*) 0x40020000;
	uint32_t *const volatile pGPIOCModeReg = (uint32_t*) 0x40020800;
	uint32_t *const volatile pGPIOAOutDataReg = (uint32_t*) 0x40020014;
	uint32_t const *const pGPICInDataReg = (uint32_t*) 0x40020810;
	uint32_t pinStatus = 0;

	*pRCCAhb1EnReg |= 0x05;
	uint32_t maskClear = 0xFFFFF3FF;
	uint32_t maskSet = 0x00000400;
	*pGPIOAModeReg &= maskClear;
	*pGPIOAModeReg |= maskSet;
	maskClear = 0xF3FFFFFF;
	*pGPIOCModeReg &= maskClear;
	for(;;){
		pinStatus = *pGPICInDataReg & 0x2000;
		if(pinStatus){
			*pGPIOAOutDataReg  &= ~(1<<5);
		}else {
			*pGPIOAOutDataReg  |= (1<<5);
		}
	}
}

```

* use volatile when you code is dealing with below scenarios
	* Memory-mapped peripheral registers of the MCUs
	* multiple tasks accessing global variables(read/write) in an RTOS multithreaded app
	* when a global var is used to share data between the main code and an ISR code
* Case 1: volatile data `uint8_t volatile my_data;` `volatile uint8_t my_data;`
* Case 2: non-volatile pointer to volatile data `uint8_t volatile *pStatusReg;`
	* Use Case: this is a perfect case of accessing memory-mapped registers. use this syntax generously whenever accessing memory mapped registers in the MCU code
* Case 3: volatile pointer to non-volatile data `uint8_t *volatile pStatusReg;`
	* rarely used
* Case 4: volatile pointer to volatile data `uint8_t volatile *volatile pStatusReg;`
	* rarely used
* In courseRepo we see sample code for turning on/off the led by pushing the button using ISR. volatile is used to make sure registry can be updated on both sides
* compiler will remove the cycle burning for loop for button debouncing at higher optimization levels. we need to make the dummy var volatile
* we can combine const and volatile 
* `uint8_t volatile *const pReg = (uint8_t*) 0x40000000` const pointer to volatile data
* `uint8_t const volatile *const pReg = (uint8_t*) 0x40000000` const pointer to volatile const data. its safeguarding towards vompiler and programmer. e.g when we read from a read-only buffer or address prone to unexpected change (shared read-only mem)

## Section 25: Structures and Bit fields

* structure is a data struct used to create user-defined data types in C
* structures alow us to combine data of different types
```
struct carModel {
	uint32_t carNumber;
	uint32_t carPirce;
	uint16_t carMaxSpeed;
	float 	 carWeight;
}
```

* structure definition does not consume any memory its just a description or a record
* memory is consumed when we create (define) structure variables `struct carModel carBMW, carFord;` the data type is `struct carModel` and the total memory allocated is eqyal to the sum of the structure elements
* its good practice to create the struct definition in header file
* one way to assign values to a struct is `struct carModel carBMW = {2021,15000,220,1330}` this is C89 method. Order is Important
* other way to assign vals is `struct carModel carBMW = {.carNumber=2021,.caPrice=15000,.carMaxSped=220,.carWeight=1330}` this is C99 method using designated initializers. order is NOT important
* when a structure var is created use a . operator to access member elements
* with `sizeof(stuctVar)` we can see the size of the struct in bytes
* if we dont define a struct as **packed** structure padding occurs. in our example uint16_t ocuppies 32bit of space and not 16bit so that data s 4byte aligned as our mem is 32bit wide (ARM 32b arch). allined means their start at a 4byte word regardless of their size
* for efficiency the compiler generates instructions to store vars on their natural size boundary addr in mem
* this is tru for structs. member elements of a struct are located on their natural size boundary
* what we deduct is the each mem location is for 1 byte
* aligned data is more CPU friendly for mem operations Registers are 32bit
* remember that in padded (normal) structs las element counts as is in size. as it is alligned...
* to pack a struct use `__attribute__((packed));`
```
struct data {
	char data1;
	int data2;
	char data3;
	short data4;
}__attribute__((packed));
```

* in this example the size is 8bytes
* we run 009packedvsunpacked example on target HW.
* we see that packed struct leads to more instructions
* this is because every 'str' instruction to store a 32b word equals 4 'strb' instructions to store a byte in mem. for 16b short it uses 'strh' (store halfword)
* but 'strh' works on addresses multiplied by 2..... so the proc internally alligns data to process them. str works ONLY with word aligned addresesand strh with halfword aligned data
* typedef struct is used to give an alias name to primitive and user defined data types
* without typedef
```
struct CarModel {
	uint16_t carMaxSpeed;
	uint32_t carPrice;
}
struct CarModel carBMW;
```
* with typedef
```
typedef struct {
	uint16_t carMaxSpeed;
	uint32_t carPrice;
} CarModel_t;
CarModel_t carBMW;
```

* CarModel_t is the alias name
* typedef is used also for primitive data to give aliases (eg uint8_t is an alias)
* in the alias from typedef we use `_t`
* a struct cannot contain elements of its own struct.
* it can contain though pointers to their own type
* such self-referential structs are used for linked lists and binary trees
* we can define nested struct
```
struct Data {
	char data1;
	int data2;
	short data3;
	struct {
		char data4;
		int data 5;
	}moreData;
}
```
* base address of a structure in memory is the address of the first member element
* the struct pointer will point there
* we cannot use pointer to the struct per se. its not in memory. but ony to the variable defined as struct
```
struct DataSet {
	char  data1;
	int   data2;
	char  data3;
	short data4;
}
struct DataSet data;
data.data1 = 0x11;
data.data2 = 0xFFFFEEEE;
data.data3 = 0x22;
data.data4 = 0xABCD;

// to mod the first element of struct using primitive pointer
uint8_t *ptr = (uint8_t*)&data;
*ptr = 0x55;
```
* we can use pointer of type struct and access elements for changing val with ->
```
struct DataSet *pData;
pData = &data;
pData->data1 = 0x55;
```
* we can pass structure pointer to functions `void displayMemberElemenets(struct Dataset *pData)` and pass in any structwithout copying a lot of data
* we always pass struct by reference to save on data copy
* we can extract bit fields from a 32bit reg building a human readable struct as exercise using bit extractions
* the example code is 'structPacket'
* in the example 'structpacketBitField' we can see how to reduce the size of struct using bitfields
* bitfileds are used for these usecase when we want to store bitfieields from a packet var as a struct. without them we waste bits string 2bit mask as 8bit val
* our example 32bit packet is structured as follows
	* CRC (2bits) bits 0-1
	* Status (1bit) bit 2
	* Payload (12bits) bits 3-14
	* Battery (3bits) bits 15-17
	* Sensor (3bits) bits 18-20
	* Long_Addr (8bits) bits 21-28
	* Short_Addr (2bits) bits 29-30
	* Mode (1bit) bit 31
* the struct with bitfields is defined as fllows definging the bitfield size as :size
```
struct Packet
{
	uint32_t crc			:2;
	uint32_t status			:1;
	uint32_t payload		:12;
	uint32_t bat			:3;
	uint32_t sensor			:3;
	uint32_t longAddr		:8;
	uint32_t shortAddr		:2;
	uint32_t addrMode		:1;
};
```
the value assignement is done with bitshifing and masking but using the struct element access rules
```
   uint32_t packetValue ;
   printf("Enter the 32bit packet value:");
   scanf("%X",&packetValue);

   struct Packet packet;

   packet.crc 		=   (uint8_t) (packetValue & 0x3);
   packet.status 	=   (uint8_t) ( (packetValue >> 2) & 0x1 );
   packet.payload   =   (uint16_t) ( (packetValue >> 3) & 0xFFF );
   packet.bat       =   (uint8_t) ( (packetValue >> 15) & 0x7 );
   packet.sensor    =   (uint8_t) ( (packetValue >> 18) & 0x7 );
   packet.longAddr  =   (uint8_t) ( (packetValue >> 21) & 0xFF );
   packet.shortAddr =   (uint8_t) ( (packetValue >> 29) & 0x3 );
   packet.addrMode  =   (uint8_t) ( (packetValue >> 31) & 0x1 );
```

* to reversely use bitfield struct to pack a struct as a packet and send it we need to know the max values (use module to ensure the value is ok) and do the reverse operations

## Section 26: Unions

* a union in C is similar to struct except that all of its members start at the same location in memory
* a union variable can represent the value of only one of its members at a time
* the memory consumed in a union is the size of its largest element
```
union address {
	uint16_t shortAddr;
	uint32_t longAddr;
}
```
* occupies 4 bytes short address the first 2 of them , long address all
* use unions instead of struct to save memory when access to its members is mutually exclusive
* Unions in Embedded System code are used for:
	* Bit extraction
	* Storing mutually exclusive data thus saving memory
* in 'unionBitExtraction'  a technique is aplied
	* struct with bitfields is nested inside a union that has as first element the 32 bit packet..
	* by copying the packet in the first element we have immediate access to the bitfields withou need for masking or bit shifting....
	* at the expence of 0 extra bytes
	* FUCKING BRILLIANT!!!
```
union Packet
{
	uint32_t packetValue;

	struct
	{
		uint32_t crc			:2;
		uint32_t status			:1;
		uint32_t payload		:12;
		uint32_t bat			:3;
		uint32_t sensor			:3;
		uint32_t longAddr		:8;
		uint32_t shortAddr		:2;
		uint32_t addrMode		:1;
	}packetFields;

};
   union Packet packet;
   printf("Enter the 32bit packet value:");
   scanf("%X",&packet.packetValue);
```

## Section 27: Usage of bit-fields in embedded code

* we will mod the led toggling exercise using bitfields and structs..
* when we write drivers for HW we want abstraction. the user should not delve into the register manuals all the time
* we will produce such structs for the led toggling code

## Section 28: Keypad interfacing

* to implement this project we need a 4x4 keypad and wire it to GPIO inputs
* keypads are implemented as matrices
* for a 4x4 keypord we need 8 inputs 4for the rows and 4 for the columns when a key is pressed it jumpers the column and the row its is wired to... 
* so rows and columns are completely isolated connecting only when a button is pressed
	* Rows are programmed as outputs to the processor
	* Columns as imputs.
	* the sequence of pins is R1,R2,R3,R4,C1,C2,C3,C4
	* the 4 inputs lines will be connected with pull-up resistors (22kohm) to +VDD on board (all mukrocontrollers come with integrated pull up resistors for the pins that we can use with register programming)
* Pull up resistors are needed for the following reason
	* if we dont use any resistor and connection to VDD or GND  when the button is not pressed the input is open circuit thus floating so it can flucuate between high and low
	* with pull up when the button is not pressed we read hight
* when we press button we should get 0 in  input.. therefore our R lines should be grounded 
* Code to implement the keypad reading logic
	* when buttons are not pressed we should read hihg
	* we should scan for keys row by row. one at a time
	* scanning a row is bu outputing 0 on that row output while sending high to the other 3. sending low is like grounding. so if a button on that row is pressed we will read 0 in its columns input pin
* We will use the C port on NUCLEO Board
	* R1 output: PC0
	* R2 output: PC1
	* R3 output: PC2
	* R4 output: PC3
	* C1 input:  PC8
	* C2 input:  PC9
	* C3 input:  PC10
	* C4 input:  PC11
* we will make all GPIOs highstate
* in an infinite for loop
	* make R1 low (other high)
	* read C1 is LOW? (yes) =>200ms delay => Keyis1
	* read C2 is LOW? (yes) =>200ms delay => Keyis2
	...
	* make R2 low (other high)
	....
* we need to create pointer to memmaped regs
* initialize regs
* use volatile
* set IOs
* Activate internall pull ups for all columns IOs (use register)
* implement logic
* we test test delay with logic analyzer and tune it
* theoretically: MCU runs with 16Mhz internal RC oscilator
* assume 1 instruction takes 1 clock cycle
	* 1 ins = 0.0625μs
	* 7 ins = 0.5 μs (7 inst is one iteration of empty for loop => check dissasembler)
	* 1000μs ==> 2000 iterations => 150ms => 300000 iterations

## Section 29: Arrays

* 
