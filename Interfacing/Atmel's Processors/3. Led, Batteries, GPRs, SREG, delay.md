# Some Features of ATmega32 Micro-Controller
The operating temperature of the ATmega32 is from -55°C to +125°C, while the storage temperature is -65°C to +150°C.

The storage temperature means it is stored but not operated, while if you are operating it, it withstands a littler range.

The voltage on any pin except $\overline{RESET}$ pin is from -0.5V to 0.5V with respect to Ground. The voltage on $\overline{RESET}$ with respect to Ground is from -0.5V to +13.0V.

The Maximum operating voltage of the ATmega32 Micro-Controller is 6.0V.

The DC Current per I/O Pin is 40.0mA, and the DC Current $V_{CC}$ and $GND$ Pins are 200.0mA and 400.0mA TQFP/MLF.

To be able to understand the DC Current part we need first to go deep in a story.

# Light Emitting Diode:
It is a special kind of diodes that emits photons in the range of visible light.

Any Diode has anode (A) and cathode (K), if you apply on the anode a Voltage that is higher than its $V_{gamma}$ ($Vanode - Vkathode > V_{gamma}$) typically in silicon it's 0.7V, then we can say that we replace it with a battery $Vb = 0.7V$ and a small resistor with a resistance may be $1\Omega$, while if you applied on the anode a voltage that is smaller than its $V_{gamma}$ ($Vanode - Vkathode > V_{gamma}$) then theoretically it is replaced with a resistor with huge resistance ($Rdiode = \infty$) which we interpret as an open circuit.

The $V_{gamma}$ in leds vary according to the color it emits typically between $1.6V$ to $3.6V$.

If you have a circuit of a battery with $Vb = 5V$ and led with $V_{gamma} = 2V$.
Here you have the $Vled (Vanode - Vkathode) > V_{gamma}$ so the led is replaced with a battery in the opposite direction from the same battery with a voltage that equals $V_{gamma} = 2V$.

![A single through hole LED resting on a plain work surface. The primary subject is the LED body with a rounded epoxy lens and two metal leads, and it is not lit. The wider environment is a neutral technical bench with no other objects visible. Tone is technical and neutral. No text appears in the image.](/Interfacing/Attachments/led.jpeg)

The Led is now operating but the problem is that the current is too high that it burns the led, to solve this problem we connect a resistor within the circuit, the resistor is preferred to be around $220 \Omega$ may be greater like $330 \Omega$ or less like $100 \Omega$ which makes the current around $10mA$and this is convenient for lighting a led. 

If we replaced the battery in the circuit with an ATmega32 Pin, it outputs $5V and 40mA$ if you connected the led with the ATmega32 Pin directly it won't burn out the led. As the $40mA$ doesn't burn it. 
Normally when we are prototyping we don't connect a resistor to the led and leave it, no harm in this but in production it is preferred to connect a resistor as operating the pin on its maximum current for too long can harm it. 

A problem appears here is when we want to connect a load to the ATmega32 Pin that is higher than $40mA$ like a motor, there is a lot of ways to solve this like haV_{in}g the current load from another device like a driver or use a transistor. 

> DO NOT CONNECT THE $V_{CC}$ to the $GND$ DIRECTLY WITHOUT ANY LOAD OR RESISTANCE. 

### Led Array
Imagin you are trying to connect a led array containing 5 pins into a single pin. When you set the Pin to **High** the led array lights and when you set it to low, the led array dims.
If we connect the led array haV_{in}g a $250 \Omega$ resistor at each led, we are expecting $20mA$ current at each led.

Since the leds are connected in parallel so we expect the pin to deliver almost $100mA$ which is impossible as the pin maximum current delivered is $40mA$.

![Five LEDs connected in parallel to a single ATmega32 microcontroller pin, each LED shown with a 250 ohm series resistor. The primary subject is the LED array and the excessive combined current draw from one output pin. The wider environment is a black and white technical schematic with component labels. Tone is technical and cautionary. Text in the image includes ATmega32 and 250 ohm.](/Interfacing/Attachments/led-array-false.png)

A solution for this is to use a BJT as a switch, and we only control that switch with our pin.

![A conceptual schematic showing a corrected LED array circuit in which an ATmega32 pin controls a transistor switch that drives multiple LEDs. The primary subject is the transistor switching arrangement and the LED load. The wider environment is a placeholder technical diagram in the notes, with no final artwork visible. Tone is instructive and solution oriented. No text appears in the image.](/Interfacing/Attachments/led-array-true.png)

#### BJT Recap

![A bipolar junction transistor schematic with labeled Collector, Base, and Emitter pins. The primary subject is the transistor symbol and its switching function, with arrows showing current direction. The wider environment is a simple technical diagram on a clean background. Tone is explanatory and neutral. Text in the image includes Collector, Base, and Emitter.](/Interfacing/Attachments/BJT.png)

A bipolar juntion transistor normally consists of three pins, which are Collector, Emitter and Base.
The base is normally connected to the $V_{in}$ the controller that controls the circuit.
The Collector is normally connected to the $V_{CC}$ the Source that gives the power to the circuit.
The Emitter is normally connected to the $GND$ so that the current coming from the source flows into it.

The Collector normally has a $R_{L}$ (load resistor), while the Base normally has a $R_{B}$ (base resistor).

Normally there is a diode between the base and the emitter, the diode's anode is facing the $R_{B}$ while the diode's cathode is facing the $GND$.

So, if the $V_{in}$ is smaller than the $V_{gamma}$ of the diode, then the diode doesn't work *cutoff mode* which is known as open circuit, so there is no current in base, collector or emitter.

When the $V_{in}$ is greater thanthe $V_{gamma}$ of the diode, then the diode now is bypassing current *active mode*, which makes the diode an inverted battery with the voltage of $V_{gamma}$ (typically $0.7V$).

So now the $I_{B}$ is equal to $\frac{V_{in} \space - \space V_{gamma}}{R_{B}}$, In active mode the $I_{C} = \beta \times I_{B}$, - This is magnifying - So the relation between $I_{C}$ and $I_{B}$ is directly proportional till the $V_{CE}$ hits the active threshold that is called the **saturation voltage** typically is 0.2.
The $V_{CE}$ is the voltage at the other end of the $R_{L}$ as the $I_{C} = \frac{V_{CC} \space - \space V_{CE}}{R_{L}}$ (in saturation state) $= \beta \times I_{C}$ (in active state).

Normally as the $I_{C}$ increase the voltage drop accross the $R_{L}$ increases so the $V_{CE}$ decreases. The $V_{CE}$ starts decreasing as the $I_{B}$ starts increasing till it is hits the saturation voltage ($0.2V$).

The saturation voltage is the voltage that when the $V_{CE}$ hits, the $I_{C}$ can not increase further even if the $I_{B}$ increases. So the graph looks like this:

![A graph showing collector current versus base current for a bipolar junction transistor, with the active region and saturation region highlighted by the curve shape. The primary subject is the transistor transfer behavior as base current increases and the curve flattens near saturation. The wider environment is a technical graph on a plain background. Tone is explanatory and instructional. Minimal text appears in the image, if any.](/Interfacing/Attachments/IB-IC-Graph.png)

So, the Maximum voltage for the $I_{C}$ is $\frac{V_{CC} \space - \space 0.2}{R_{L}}A$.

At this point the two states are valid, we are active and we are saturated, so I can get the most minimum $I_{B}$ that gets me saturated using the rule of active law $I_{Bmin} = \frac{I_{C}}{\beta}$.

So, now we can select a good $R_{B}$ that makes our transistor in *cutoff* state if the $V_{in}$ was $0V$ (The pin was Low) so that no current flows into emitter **(Switch Off)**, and in *saturation* state if the $V_{in}$ was $5V$ so that the highest current possible flows into emitter **(Switch On)**.

We select an $R_{B}$ that makes the $I_{B}$ slightly greater than the $I_{Bmin}$.

Let's say that the $I_{Bmin}$ was $0.3mA$, now we need to deliver some current greater than this a little bit, let's say $0.4mA$, so we want the $I_{B}$ to be equal to $0.5mA$ and knowing that the Pin's voltage $V_{in}$ is typically $5V$.

So, we connect $R_{B}$ that equals $ \frac{V_{CC} \space - \space {Vgamma}}{I_{B}} \space = \space \frac{5 \space - \space 0.7}{0.5 \times 10^{-3}} = 860 \Omega$.

We also choose the $R_{L}$ that makes the $I_{Cmax}$ equals $100mA$ -during saturation - to light all the led array safely.

![Primary subject: a conceptual schematic showing an ATmega32 microcontroller pin connected through a base resistor to an NPN transistor used as a switch. The transistor drives a parallel LED array with multiple LEDs and series resistors from the power rail, while the emitter is tied to ground and the collector side powers the LED load. The wider environment is a clean technical circuit diagram on a plain background, illustrating the corrected way to drive several LEDs from a single output pin. Tone is instructional and solution oriented. No text appears in the image.](/Interfacing/Attachments/led-array-true.png)

# Batteries
$Battery Workig Time = \frac{0.8 × Battery Capacity (mAH)}{Total Load Current (mA)}$

#### Battery Capacity:
You can find it's capacity listed as ($500 mAH$) which means it can deliver $500mA$ for a load for an hour, if the load consumes only $50mA$ it can withstand 10 hours, so the capacity of a battery is calculated as how much can the battery deliver a load for an hour. 

 To Calculate the Battery Working Time we simply divide the Battery Capacity by the Total Load Current then multiply this number by a constant factor of $0.8$ this factor varies in each battery as the battery has an internal resistors that consumes some power. 

# General Purpose Registers
GPRs count and names differ across different processors, but they all have the same job. 
In ATmega32 We have 32 Registers $(\$R0-\$R31)$ each is 8-bit width (32×8 Processor). 
They are the internal temporary storage of the processor, They hold the data that will be or has been processed by the ALU.  

In Assembly we have indirect addressing. Rather than normal addressing with load and store instructions, we can take 2 registers as a pointer then we make our operations with that pointer. 

![A register map for the ATmega32 showing 32 general purpose 8 bit registers from R0 through R31 arranged in four rows. The primary subject is the register layout, with the last six registers from R26 through R31 highlighted to show the pointer pairs X, Y, and Z. The wider environment is a clean educational schematic. Tone is educational and technical. Text in the image includes R0 through R31, X R27 R26, Y R29 R28, and Z R31 R30.](/Interfacing/Attachments/GPR.png) 

If you look at the data sheet you'll find that the last six registers are considered as pointers:
- The two registers $(\$R27 \space and \space \$R26)$ are considered as pointer $x$.
- The two registers $(\$R29 \space and \space \$R28)$ are considered as pointer $y$.
- The two registers $(\$R31 \space and \space \$R30)$ are considered as pointer $z$.

![A diagram highlighting the three 16 bit pointer register pairs used for indirect addressing on the ATmega32, named X as R27 R26, Y as R29 R28, and Z as R31 R30. The primary subject is how paired 8 bit registers form a 16 bit memory address for SRAM access. The wider environment is a labeled technical schematic. Tone is instructional and neutral. Text in the image includes X R27 R26, Y R29 R28, and Z R31 R30.](/Interfacing/Attachments/pointers-registers.png)

In the ATmega32 (AVR 8-bit architecture), indirect addressing means accessing SRAM data through a pointer stored in a 16-bit register pair, equivalent in concept to pointer dereferencing (`*ptr` in C) or base-register memory access in MIPS.

The ATmega32 has 32 general-purpose 8-bit registers (R0–R31). Because memory addresses in data space are 16 bits wide, the architecture pairs the top six 8-bit registers into three dedicated 16-bit address pointers:
 * X register: R27:R26 (XH:XL)
 * Y register: R29:R28 (YH:YL)
 * Z register: R31:R30 (ZH:ZL)
 
Any indirect access into data SRAM uses one of these three register pairs as the memory pointer.

So they can functiom normally as general purpose registers or they can function as pointers to a specific location in the SRAM. 

# Status Register (SREG)
It is an 8-bit register where each bit indicates a flag set by the processor or controls a process set by the programmer. 
It is named **SREG** in the datasheet, and it is found in the Special Function Registers (IO Registers).

The bits $C, \space Z, \space N, \space V, \space S, \space and \space H$ are called **conditional flags**.
The bits $T \space and \space I$ are called **control bits**.

This is the data sheet description:
> The Status Register contains information about the result of the most recently executed arithmetic instruction. This
information can be used for altering program flow in order to perform conditional operations. Note that the Status
Register is updated after all ALU operations, as specified in the AVR Instruction Set Manual. This will in many
cases remove the need for using the dedicated compare instructions, resulting in faster and more compact code.
The Status Register is not automatically stored when entering an interrupt routine and restored when returning
from an interrupt. This must be handled by software.

![An 8 bit AVR status register diagram showing eight labeled flag bits from bit 7 to bit 0. The primary subject is the SREG layout and the meaning of each flag. The wider environment is a compact technical diagram inside documentation. Tone is technical and informative. Text in the image includes bit 7 C carry, bit 6 Z zero, bit 5 N negative, bit 4 V overflow, bit 3 S sign, bit 2 T transfer, bit 1 H half carry, and bit 0 I global interrupt enable.](/Interfacing/Attachments/status-register.png)

## Bit 0 - C: Carry Flag
This bit is set to High by the processor if the result of the ALU has a carry and Low otherwise.

## Bit 1 - Z: Zero Flag
This bit is set to High by the processor if the result of the ALU is zero and Low otherwise.

## Bit 2 - N: Negative Flag
This bit is set to High by the processor if the result of the ALU is Negative and Low otherwise.

## Bit 3 - V: Two's Complement Overflow Flag
This bit is set to High by the processor if the result of the ALU overflows, and Low otherwise. 

## Bit 4 - S: Sign Bit, $S = N \oplus V$
This bit is set to High by the processor if the result of the ALU is negative and Low otherwise. 

## Bit 5 - H: Half Carry Flag
This bit is set to High by the processor if the result of the ALU if there is half carry in BCD arithmetic operations.

## Bit 6 - T: Bit Copy Storage
This bit is the copy bit. It is used when you need to copy a bit from a GPR to another bit in another GPR, There is no circuit or assembly instruction can perform this, but this bit is here to save the hustle, it is used to be a mediocre between them. You copy the source bit into it. And copy it into the destination bit. 
This is done using the (Bit STore) and (Bit LoaD) assembly instructions. 
```asm
BST R4, 3
BLD R8, 6
```

## Bit 7 - I: Global Interrupt Enable
This bit is set by the programmer to enable the interrupts, each interrupt is then enabled individualy but if this bit is set to Low, then no interrupt is enabled at all.

## More explanation:

### What is Half Carry?
This bit is used exclusively for *Binary Coded Decimal **BCD** Arithmetic Operations*. It is set to **High** when a carry occures from bit 3 to bit 4 (The halfway point between the lower and upper nibble of an 8-bit byte).

### What is the difference between Carry Flag and Overflow Flag?
The carry flag tracks overflow for unsigned numbers, it is set to **High** when you exceed $255$.

The overflow flag tracks overflow for signed 2's complement numbers, it is set to **High** when you are out of this range ($-128 \space to \space +127$) either you are adding two positive numbers and getting a negative number or you are adding two negative numbers and getting a positive number.

### Why do we have both Negative Flag and Sign Flag?
It seems redundant, but one of them is useful for only logical instructions and the other for the arithmetic instructions:

- Negative Flag:
This flag copies the most significant bit (bit 7) of the ALU's result. If the bit 7 is **High**, the N Flag is set to **High**, the same rule applies to **Low**. It doesn't care if the calculation was valid, it only copies the MSB.

- Sign Flag:
This flag applies exclusive or between the V Flag and N flag,it represents the true mathematically sign of a calculation.

Imagine adding two positive numbers: $100 + 50$ the result should be positive $150$.
In 8-bit signed aithmetic the maximum positive value is $+127$ So, the $150$ overflows and maps into negative number $-106$.
In this case the N Flag reports that the result is negative while the actual answer is positive.
The V Flag is set to **High** and the N flag is also set to **High** yielding **Low** in their xoring, which means that the S flag yields **Low** indicating that the number is positive.

So this is the case where we need the S Flag, what about the case we need the N Flag?
The N flag is mainly used when we need the 7th bit in the result direct without any storing or bitmasking, in case of branch if minus and branch if plus instructions, in case of logical operations and in case of directional shifts and rotates.

You also need it so you can xor the V Flag to get the result of the S FLag.

---

# `_delay_ms() `
This function and its conjugate `_delay_micros()` are defined inside the `<util/delay.h>` header file, it also has the implementations of them. 

It's approach for delay is a bad approach as it uses polling to delay the processor, it loops doing nothing till the delay time ends. 
A better approach is to use a timer with an interrupt, but for now let's stick with this polling approach. 

It's known in AVR processors that a for loop takes two instructions and in pipelining each instruction takes exactly one cycle.
Each cycle is calculated as the period time of a processor which is the reciprocal of the frequency ($Cycle \space Clock \space Time = \frac{1}{Clock Rate}$). 
$Delay \space Time = Time \space per \space Single \space Iteration \times Number \space of \space Iterations (n)$)
Time per single iteration ks calculated as 2 instructions per iteration each having the time of a cycle. 
$Time \space per \space Single \space Iteration = 2 \times \frac{1}{Frequency}$
So, the delay time is simply:
$Delay \space Time = 2 \times \frac{1}{Freq} \times n$

```c
void _delay_ms(double delayTimeInMilliSeconds) {
	for(int i=0; i<n; ++i);
}
```

Now we need to know what is $n$ to set in the loop to hold all the delay time. 
To get $n$ we will tweak the equation:
$n = \frac{Delay \space Time \times Freq}{2}$
The $Freq$ is a hardware configuration, there is no way to know it in the software, so we define a macro called `F_CPU` to hold the frequency od the cpu. 
```c
#define F_CPU 8000000UL // 8 MHz

void _delay_ms(double);

int main(void) {
	_delay_ms(1000);
}

void _delay_ms(double delayTimeInMilliSeconds) {
	double n = delayTimeInMilliSeconds * F_CPU / 1000.0 * 2.0;
	for(int i=0; i<n; ++i);
}
```
So, we need to always define the `F_CPU` macro, if it is not defined the `<util/delay.h>` library defines it by default to `1000000UL` $1MHz$.

---