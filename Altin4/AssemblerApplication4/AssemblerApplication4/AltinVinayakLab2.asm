.include "m328def.inc"

.org 0x0000
RJMP begin 

.org 0x0002
RJMP interrupt 

.org 0x0034 

begin:
    LDI R16, low(RAMEND)
    OUT SPL, R16
    LDI R16, high(RAMEND)
    OUT SPH, R16

    LDI R16, (1<<ISC01)|(1<<ISC00)
    STS EICRA, R16

    LDI R16, (1<<INT0)
    OUT EIMSK, R16

    LDI R16, 0xFF
    OUT DDRB, R16

    LDI R16, 0x00
    OUT DDRD, R16

    SEI

Loop:
    LDI R16, 0xFF
    OUT PORTB, R16
    RJMP Loop

interrupt:
    LDI R16, 0x00
    OUT PORTB, R16
    RCALL Delay_1sec
    RETI

Delay_1sec:
    LDI R17, 25

Delay1:
    LDI R18, 125

Delay2:
    LDI R19, 250

Delay3:
    DEC R19
    NOP
    BRNE Delay3

    DEC R18
    BRNE Delay2

    DEC R17
    BRNE Delay1

    RET

