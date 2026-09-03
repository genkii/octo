# Octo Instruction Set Architecture

Octo offers a strong architecture

## Registers

**A**: 16-bit (2 byte) register
**PC**: 16-bit register managing the program counter

## Opcode

Octo uses 8-bit opcode instructions.
Following opcodes are supported:

- **LOAD**: (00000001) loads a number into an register (register can be defined with register address) [opcode][register id u8][high][low]
- **HALT**: (00000100) stops the program [opcode]
- **STORE**: (00000010) store value in memory [opcode][register id u8][memory adress u16 (high / low)]
- **LOADM**: (00000011) load value from memory [opcode][register id u8][memory adress u16 (high / low)]

## Planned (Soon be implemented)

- **ADD**: (00000101) Add a value to a register [opcode][register id][high][low]
- **B**: B register will need changes in ADD and step.cpp