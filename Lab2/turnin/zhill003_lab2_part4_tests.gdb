# Test file for "Lab2"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x01, PINB: 0x01, PINC: 0x01 => PORTD: 0x00"
# Set inputs
setPINA 0x01
setPINB 0x01
setPINC 0x01
# Continue for several ticks
continue 5000
# Set expect values
expectPORTD 0x00
# Check pass/fail
checkResult

# Add tests below
test "PINA: 0x2F, PINB: 0x32, PINC: 0x2F => PORTD: 0x93"
setPINA 0x2F
setPINB 0x32
setPINC 0x2F
continue 5000
expectPORTC 0x51
checkResult

test "PINA: 0x02F, PINB: 0x32, PINC: 0x32 => PORTC: 096"
setPINA 0x2F
setPINB 0x32
setPINC 0x32
continue 5000
expectPORTC 0x56
checkResult

test "PINA: 0x20, PINB: 0x44, PINC: 0x0D => PORTC: 0x74"
setPINA 0x20
setPINB 0x44
setPINC 0x0D
continue 5000
expectPORTC 0x74
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
