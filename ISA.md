# Octo Instruction Set Architecture

Octo offers a strong architecture

## Registers

**A**: 16-bit (2 byte) register
**PC**: 16-bit register managing the program count

## Opcode

Octo uses 8-bit opcode instructions.
Following opcodes are supported:

- **LOAD**: (00000001) loads a number into an register (register can be defined with register address)
- **HALT**: (00000100) stops the program